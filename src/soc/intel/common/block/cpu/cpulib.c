/* SPDX-License-Identifier: GPL-2.0-only */

#include <acpi/acpigen.h>
#include <assert.h>
#include <console/console.h>
#include <cpu/cpu.h>
#include <cpu/intel/common/common.h>
#include <cpu/intel/turbo.h>
#include <cpu/x86/msr.h>
#include <cpu/x86/mtrr.h>
#include <intelblocks/cpulib.h>
#include <intelblocks/fast_spi.h>
#include <intelblocks/msr.h>
#include <smp/node.h>
#include <soc/soc_chip.h>
#include <types.h>

#define CPUID_EXTENDED_CPU_TOPOLOGY 0x0b
#define LEVEL_TYPE_CORE 2
#define LEVEL_TYPE_SMT 1

#define CPUID_CPU_TOPOLOGY(x, val) \
	(((val) >> CPUID_CPU_TOPOLOGY_##x##_SHIFT) & CPUID_CPU_TOPOLOGY_##x##_MASK)

#define CPUID_CPU_TOPOLOGY_LEVEL_TYPE_SHIFT 0x8
#define CPUID_CPU_TOPOLOGY_LEVEL_TYPE_MASK 0xff
#define CPUID_CPU_TOPOLOGY_LEVEL(res) CPUID_CPU_TOPOLOGY(LEVEL_TYPE, (res).ecx)

#define CPUID_CPU_TOPOLOGY_LEVEL_BITS_SHIFT 0x0
#define CPUID_CPU_TOPOLOGY_LEVEL_BITS_MASK 0x1f
#define CPUID_CPU_TOPOLOGY_THREAD_BITS(res) CPUID_CPU_TOPOLOGY(LEVEL_BITS, (res).eax)
#define CPUID_CPU_TOPOLOGY_CORE_BITS(res, threadbits) \
	((CPUID_CPU_TOPOLOGY(LEVEL_BITS, (res).eax)) - threadbits)

#define CPUID_PROCESSOR_FREQUENCY		0X16
#define CPUID_HYBRID_INFORMATION		0x1a

/* Structured Extended Feature Flags */
#define CPUID_STRUCT_EXTENDED_FEATURE_FLAGS	0x7
#define HYBRID_FEATURE				BIT(15)

/*
 * Set PERF_CTL MSR (0x199) P_Req with
 * Turbo Ratio which is the Maximum Ratio.
 */
void cpu_set_max_ratio(void)
{
	/* Check for configurable TDP option */
	if (get_turbo_state() == TURBO_ENABLED)
		cpu_set_p_state_to_turbo_ratio();
}

/*
 * Get the TDP Nominal Ratio from MSR 0x648 Bits 7:0.
 */
u8 cpu_get_tdp_nominal_ratio(void)
{
	u8 nominal_ratio;
	msr_t msr;

	msr = rdmsr(MSR_CONFIG_TDP_NOMINAL);
	nominal_ratio = msr.lo & 0xff;
	return nominal_ratio;
}

/*
 * Read PLATFORM_INFO MSR (0xCE).
 * Return Value of Bit 34:33 (CONFIG_TDP_LEVELS).
 *
 * Possible values of Bit 34:33 are -
 * 00 : Config TDP not supported
 * 01 : One Additional TDP level supported
 * 10 : Two Additional TDP level supported
 * 11 : Reserved
 */
int cpu_config_tdp_levels(void)
{
	msr_t platform_info;

	/* Bits 34:33 indicate how many levels supported */
	platform_info = rdmsr(MSR_PLATFORM_INFO);
	return (platform_info.hi >> 1) & 3;
}

static void set_perf_control_msr(msr_t msr)
{
	wrmsr(IA32_PERF_CTL, msr);
	printk(BIOS_DEBUG, "CPU: frequency set to %d MHz\n",
	       ((msr.lo >> 8) & 0xff) * CONFIG_CPU_BCLK_MHZ);
}

/*
 * TURBO_RATIO_LIMIT MSR (0x1AD) Bits 31:0 indicates the
 * factory configured values for of 1-core, 2-core, 3-core
 * and 4-core turbo ratio limits for all processors.
 *
 * 7:0 -	MAX_TURBO_1_CORE
 * 15:8 -	MAX_TURBO_2_CORES
 * 23:16 -	MAX_TURBO_3_CORES
 * 31:24 -	MAX_TURBO_4_CORES
 *
 * Set PERF_CTL MSR (0x199) P_Req with that value.
 */
void cpu_set_p_state_to_turbo_ratio(void)
{
	msr_t msr, perf_ctl;

	msr = rdmsr(MSR_TURBO_RATIO_LIMIT);
	perf_ctl.lo = (msr.lo & 0xff) << 8;
	perf_ctl.hi = 0;

	set_perf_control_msr(perf_ctl);
}

/*
 * CONFIG_TDP_NOMINAL MSR (0x648) Bits 7:0 tells Nominal
 * TDP level ratio to be used for specific processor (in units
 * of 100MHz).
 *
 * Set PERF_CTL MSR (0x199) P_Req with that value.
 */
void cpu_set_p_state_to_nominal_tdp_ratio(void)
{
	msr_t msr, perf_ctl;

	msr = rdmsr(MSR_CONFIG_TDP_NOMINAL);
	perf_ctl.lo = (msr.lo & 0xff) << 8;
	perf_ctl.hi = 0;

	set_perf_control_msr(perf_ctl);
}

/*
 * PLATFORM_INFO MSR (0xCE) Bits 15:8 tells
 * MAX_NON_TURBO_LIM_RATIO.
 *
 * Set PERF_CTL MSR (0x199) P_Req with that value.
 */
void cpu_set_p_state_to_max_non_turbo_ratio(void)
{
	msr_t perf_ctl;

	/* Platform Info bits 15:8 give max ratio */
	perf_ctl.lo = (cpu_get_max_non_turbo_ratio() << 8) & 0xff00;
	perf_ctl.hi = 0;

	set_perf_control_msr(perf_ctl);
}

/*
 * Set PERF_CTL MSR (0x199) P_Req with the value
 * for maximum efficiency. This value is reported in PLATFORM_INFO MSR (0xCE)
 * in Bits 47:40 and is extracted with cpu_get_min_ratio().
 */
void cpu_set_p_state_to_min_clock_ratio(void)
{
	uint32_t min_ratio;
	msr_t perf_ctl;

	/* Read the minimum ratio for the best efficiency. */
	min_ratio = cpu_get_min_ratio();
	perf_ctl.lo = (min_ratio << 8) & 0xff00;
	perf_ctl.hi = 0;

	set_perf_control_msr(perf_ctl);
}

/*
 * Get the Burst/Turbo Mode State from MSR IA32_MISC_ENABLE 0x1A0
 * Bit 38 - TURBO_MODE_DISABLE Bit to get state ENABLED / DISABLED.
 * Also check for the cpuid 0x6 to check whether Burst mode unsupported.
 */
int cpu_get_burst_mode_state(void)
{

	msr_t msr;
	unsigned int eax;
	int burst_en, burst_cap, burst_state = BURST_MODE_UNKNOWN;

	eax = cpuid_eax(0x6);
	burst_cap = eax & 0x2;
	msr = rdmsr(IA32_MISC_ENABLE);
	burst_en = !(msr.hi & BURST_MODE_DISABLE);

	if (!burst_cap && burst_en) {
		burst_state = BURST_MODE_UNAVAILABLE;
	} else if (burst_cap && !burst_en) {
		burst_state = BURST_MODE_DISABLED;
	} else if (burst_cap && burst_en) {
		burst_state = BURST_MODE_ENABLED;
	}
	return burst_state;
}

bool cpu_is_hybrid_supported(void)
{
	struct cpuid_result cpuid_regs;

	/* CPUID.(EAX=07H, ECX=00H):EDX[15] indicates CPU is hybrid CPU or not*/
	cpuid_regs = cpuid_ext(CPUID_STRUCT_EXTENDED_FEATURE_FLAGS, 0);
	return !!(cpuid_regs.edx & HYBRID_FEATURE);
}

/*
 * The function must be called if CPU is hybrid. If CPU is hybrid, the CPU type
 * information is available in the Hybrid Information Enumeration Leaf(EAX=0x1A, ECX=0).
 */
uint8_t cpu_get_cpu_type(void)
{
	union cpuid_nat_model_id_and_core_type {
		struct {
			u32 native_mode_id:24;
			u32 core_type:8;
		} bits;
		u32 hybrid_info;
	};
	union cpuid_nat_model_id_and_core_type eax;

	eax.hybrid_info = cpuid_eax(CPUID_HYBRID_INFORMATION);
	return (u8)eax.bits.core_type;
}

/* It gets CPU bus frequency in MHz */
uint32_t cpu_get_bus_frequency(void)
{
	return cpuid_ecx(CPUID_PROCESSOR_FREQUENCY);
}

/*
 * Program CPU Burst mode
 * true = Enable Burst mode.
 * false = Disable Burst mode.
 */
void cpu_burst_mode(bool burst_mode_status)
{
	msr_t msr;

	msr = rdmsr(IA32_MISC_ENABLE);
	if (burst_mode_status)
		msr.hi &= ~BURST_MODE_DISABLE;
	else
		msr.hi |= BURST_MODE_DISABLE;
	wrmsr(IA32_MISC_ENABLE, msr);
}

/*
 * Program Enhanced Intel Speed Step Technology
 * true = Enable EIST.
 * false = Disable EIST.
 */
void cpu_set_eist(bool eist_status)
{
	msr_t msr;

	msr = rdmsr(IA32_MISC_ENABLE);
	if (eist_status)
		msr.lo |= (1 << 16);
	else
		msr.lo &= ~(1 << 16);
	wrmsr(IA32_MISC_ENABLE, msr);
}

/*
 * This function fills in the number of Cores(physical) and Threads(virtual)
 * of the CPU in the function arguments. It also returns if the number of cores
 * and number of threads are equal.
 */
int cpu_read_topology(unsigned int *num_phys, unsigned int *num_virt)
{
	msr_t msr;
	msr = rdmsr(MSR_CORE_THREAD_COUNT);
	*num_virt = (msr.lo >> 0) & 0xffff;
	*num_phys = (msr.lo >> 16) & 0xffff;
	return (*num_virt == *num_phys);
}

int cpu_get_coord_type(void)
{
	return HW_ALL;
}

uint32_t cpu_get_min_ratio(void)
{
	msr_t msr;
	/* Get bus ratio limits and calculate clock speeds */
	msr = rdmsr(MSR_PLATFORM_INFO);
	return ((msr.hi >> 8) & 0xff);	/* Max Efficiency Ratio */
}

uint32_t cpu_get_max_ratio(void)
{
	msr_t msr;
	uint32_t ratio_max;
	if (cpu_config_tdp_levels()) {
		/* Set max ratio to nominal TDP ratio */
		msr = rdmsr(MSR_CONFIG_TDP_NOMINAL);
		ratio_max = msr.lo & 0xff;
	} else {
		msr = rdmsr(MSR_PLATFORM_INFO);
		/* Max Non-Turbo Ratio */
		ratio_max = (msr.lo >> 8) & 0xff;
	}
	return ratio_max;
}

uint8_t cpu_get_max_non_turbo_ratio(void)
{
	msr_t msr;

	/*
	 * PLATFORM_INFO(0xCE) MSR Bits[15:8] tells
	 * MAX_NON_TURBO_LIM_RATIO
	 */
	msr = rdmsr(MSR_PLATFORM_INFO);
	return ((msr.lo >> 8) & 0xff);
}

void configure_tcc_thermal_target(void)
{
	const config_t *conf = config_of_soc();
	msr_t msr;

	if (!conf->tcc_offset)
		return;

	/* Set TCC activation offset */
	msr = rdmsr(MSR_PLATFORM_INFO);
	if ((msr.lo & BIT(30))) {
		msr = rdmsr(MSR_TEMPERATURE_TARGET);
		msr.lo &= ~(0xf << 24);
		msr.lo |= (conf->tcc_offset & 0xf) << 24;
		wrmsr(MSR_TEMPERATURE_TARGET, msr);
	}

	/*
	 * SoCs prior to Comet Lake/Cannon Lake do not support the time window
	 * bits, so return early.
	 */
	if (CONFIG(SOC_INTEL_APOLLOLAKE) || CONFIG(SOC_INTEL_SKYLAKE) ||
	    CONFIG(SOC_INTEL_KABYLAKE) || CONFIG(SOC_INTEL_BRASWELL) ||
	    CONFIG(SOC_INTEL_BROADWELL))
		return;

	/* Time Window Tau Bits [6:0] */
	msr = rdmsr(MSR_TEMPERATURE_TARGET);
	msr.lo &= ~0x7f;
	msr.lo |= 0xe6; /* setting 100ms thermal time window */
	wrmsr(MSR_TEMPERATURE_TARGET, msr);
}

uint32_t cpu_get_bus_clock(void)
{
	/* CPU bus clock is set by default here to 100MHz.
	 * This function returns the bus clock in KHz.
	 */
	return CONFIG_CPU_BCLK_MHZ * KHz;
}

uint32_t cpu_get_power_max(void)
{
	msr_t msr;
	int power_unit;

	msr = rdmsr(MSR_PKG_POWER_SKU_UNIT);
	power_unit = 2 << ((msr.lo & 0xf) - 1);
	msr = rdmsr(MSR_PKG_POWER_SKU);
	return (msr.lo & 0x7fff) * 1000 / power_unit;
}

uint32_t cpu_get_max_turbo_ratio(void)
{
	msr_t msr;
	msr = rdmsr(MSR_TURBO_RATIO_LIMIT);
	return msr.lo & 0xff;
}

void mca_configure(void)
{
	int i;
	const unsigned int num_banks = mca_get_bank_count();

	printk(BIOS_DEBUG, "Clearing out pending MCEs\n");

	mca_clear_status();

	for (i = 0; i < num_banks; i++) {
		/* Initialize machine checks */
		wrmsr(IA32_MC_CTL(i),
			(msr_t) {.lo = 0xffffffff, .hi = 0xffffffff});
	}
}

void cpu_lt_lock_memory(void)
{
	msr_set(MSR_LT_CONTROL, LT_CONTROL_LOCK);
}

bool is_sgx_supported(void)
{
	struct cpuid_result cpuid_regs;
	msr_t msr;

	/* EBX[2] is feature capability */
	cpuid_regs = cpuid_ext(CPUID_STRUCT_EXTENDED_FEATURE_FLAGS, 0x0);
	msr = rdmsr(MTRR_CAP_MSR); /* Bit 12 is PRMRR enablement */
	return ((cpuid_regs.ebx & SGX_SUPPORTED) && (msr.lo & MTRR_CAP_PRMRR));
}

static bool is_sgx_configured_and_supported(void)
{
	return CONFIG(SOC_INTEL_COMMON_BLOCK_SGX_ENABLE) && is_sgx_supported();
}

bool is_keylocker_supported(void)
{
	struct cpuid_result cpuid_regs;
	msr_t msr;

	/* ECX[23] is feature capability */
	cpuid_regs = cpuid_ext(CPUID_STRUCT_EXTENDED_FEATURE_FLAGS, 0x0);
	msr = rdmsr(MTRR_CAP_MSR); /* Bit 12 is PRMRR enablement */
	return ((cpuid_regs.ecx & KEYLOCKER_SUPPORTED) && (msr.lo & MTRR_CAP_PRMRR));
}

static bool is_keylocker_configured_and_supported(void)
{
	return CONFIG(INTEL_KEYLOCKER) && is_keylocker_supported();
}

static bool check_prm_features_enabled(void)
{
	/*
	 * Key Locker and SGX are the features that need PRM.
	 * If either of them are enabled return true, otherwise false
	 * */
	return is_sgx_configured_and_supported() ||
		is_keylocker_configured_and_supported();
}

int get_valid_prmrr_size(void)
{
	msr_t msr;
	int i;
	int valid_size;

	/* If none of the features that need PRM are enabled then return 0 */
	if (!check_prm_features_enabled())
		return 0;

	if (!CONFIG_SOC_INTEL_COMMON_BLOCK_PRMRR_SIZE)
		return 0;

	msr = rdmsr(MSR_PRMRR_VALID_CONFIG);
	if (!msr.lo) {
		printk(BIOS_WARNING, "PRMRR not supported.\n");
		return 0;
	}

	printk(BIOS_DEBUG, "MSR_PRMRR_VALID_CONFIG = 0x%08x\n", msr.lo);

	/* find the first (greatest) value that is lower than or equal to the selected size */
	for (i = 8; i >= 0; i--) {
		valid_size = msr.lo & (1 << i);

		if (valid_size && valid_size <= CONFIG_SOC_INTEL_COMMON_BLOCK_PRMRR_SIZE)
			break;
		else if (i == 0)
			valid_size = 0;
	}

	if (!valid_size) {
		printk(BIOS_WARNING, "Unsupported PRMRR size of %i MiB, check your config!\n",
			CONFIG_SOC_INTEL_COMMON_BLOCK_PRMRR_SIZE);
		return 0;
	}

	printk(BIOS_DEBUG, "PRMRR size set to %i MiB\n", valid_size);

	valid_size *= MiB;

	return valid_size;
}

/* Get number of bits for core ID and SMT ID */
static void get_cpu_core_thread_bits(uint32_t *core_bits, uint32_t *thread_bits)
{
	struct cpuid_result cpuid_regs;
	int level_num, cpu_id_op = 0;
	const uint32_t cpuid_max_func = cpuid_get_max_func();

	/* Assert if extended CPU topology not supported */
	assert(cpuid_max_func >= CPUID_EXTENDED_CPU_TOPOLOGY);

	cpu_id_op = CPUID_EXTENDED_CPU_TOPOLOGY;

	*core_bits = level_num = 0;
	cpuid_regs = cpuid_ext(cpu_id_op, level_num);

	/* Sub-leaf index 0 enumerates SMT level, if not assert */
	assert(CPUID_CPU_TOPOLOGY_LEVEL(cpuid_regs) == LEVEL_TYPE_SMT);

	*thread_bits = CPUID_CPU_TOPOLOGY_THREAD_BITS(cpuid_regs);
	do {
		level_num++;
		cpuid_regs = cpuid_ext(cpu_id_op, level_num);
		if (CPUID_CPU_TOPOLOGY_LEVEL(cpuid_regs) == LEVEL_TYPE_CORE) {
			*core_bits = CPUID_CPU_TOPOLOGY_CORE_BITS(cpuid_regs, *thread_bits);
			break;
		}
	/* Stop when level type is invalid i.e 0 */
	} while (CPUID_CPU_TOPOLOGY_LEVEL(cpuid_regs));
}

void get_cpu_topology_from_apicid(uint32_t apicid, uint8_t *package,
		uint8_t *core, uint8_t *thread)
{

	uint32_t core_bits, thread_bits;

	get_cpu_core_thread_bits(&core_bits, &thread_bits);

	if (package)
		*package = apicid >> (thread_bits + core_bits);
	if (core)
		*core = (apicid  >> thread_bits) & ((1 << core_bits) - 1);
	if (thread)
		*thread = apicid  & ((1 << thread_bits) - 1);
}

static void sync_core_prmrr(void)
{
	static msr_t msr_base, msr_mask;

	if (boot_cpu()) {
		msr_base = rdmsr(MSR_PRMRR_BASE_0);
		msr_mask = rdmsr(MSR_PRMRR_PHYS_MASK);
	} else if (!intel_ht_sibling()) {
		wrmsr(MSR_PRMRR_BASE_0, msr_base);
		wrmsr(MSR_PRMRR_PHYS_MASK, msr_mask);
	}
}

void init_core_prmrr(void)
{
	msr_t msr = rdmsr(MTRR_CAP_MSR);

	if (msr.lo & MTRR_CAP_PRMRR)
		sync_core_prmrr();
}

bool is_tme_supported(void)
{
	struct cpuid_result cpuid_regs;

	/* ECX[13] is feature capability */
	cpuid_regs = cpuid_ext(CPUID_STRUCT_EXTENDED_FEATURE_FLAGS, 0x0);
	return (cpuid_regs.ecx & TME_SUPPORTED);
}

void set_tme_core_activate(void)
{
	msr_t msr = { .lo = 0, .hi = 0 };

	wrmsr(MSR_CORE_MKTME_ACTIVATION, msr);
}

/* Provide the max turbo frequency of the CPU */
unsigned int smbios_cpu_get_max_speed_mhz(void)
{
	return cpu_get_max_turbo_ratio() * CONFIG_CPU_BCLK_MHZ;
}

void disable_three_strike_error(void)
{
	msr_t msr;

	msr = rdmsr(MSR_PREFETCH_CTL);
	msr.lo = msr.lo | DISABLE_CPU_ERROR;
	wrmsr(MSR_PREFETCH_CTL, msr);
}

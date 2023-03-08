cmake_minimum_required(VERSION 3.7.2)

declare_platform(stm32mp1 KernelPlatformSTM32MP1 PLAT_STM32MP1 KernelSel4ArchAarch32)

if(KernelPlatformSTM32MP1)
    declare_seL4_arch(aarch32)
    set(KernelArmCortexA7 ON)
    set(KernelArchArmV7a ON)
    config_set(KernelARMPlatform ARM_PLAT stm32mp1)
    config_set(KernelArmMach MACH "stm32mp1")
    list(APPEND KernelDTSList "tools/dts/stm32mp1.dts")
    list(APPEND KernelDTSList "src/plat/stm32mp1/overlay-stm32mp1.dts")
	declare_default_headers(
        TIMER_FREQUENCY 8000000
        MAX_IRQ 159
        NUM_PPI 32
        TIMER drivers/timer/arm_generic.h
        INTERRUPT_CONTROLLER arch/machine/gic_v2.h
        CLK_MAGIC 1llu
        CLK_SHIFT 8u
        KERNEL_WCET 10u
    )
endif()

add_sources(
    DEP "KernelPlatformSTM32MP1"
    CFILES src/arch/arm/machine/gic_v2.c src/arch/arm/machine/l2c_nop.c
)

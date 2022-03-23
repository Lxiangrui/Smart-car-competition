################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/User/subdir.mk
-include src/Driver/subdir.mk
-include src/APP/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/_PinMap/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/_Lib/DataHandling/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/_Impl/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Vadc/Std/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Vadc/Adc/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Stm/Std/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Src/Std/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Scu/Std/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Qspi/Std/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Qspi/SpiMaster/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Port/Std/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Gtm/Tom/Pwm/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Gtm/Tim/In/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Gtm/Std/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Gtm/Atom/Pwm/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Gpt12/Std/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Flash/Std/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Fft/Std/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Fft/Fft/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Emem/Std/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Dma/Std/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Dma/Dma/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Cpu/Trap/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Cpu/Std/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Cpu/Irq/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Cpu/CStart/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Ccu6/Timer/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Ccu6/Std/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Asclin/Std/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Asclin/Spi/subdir.mk
-include Libraries/iLLD/TC26B/Tricore/Asclin/Asc/subdir.mk
-include Libraries/Service/CpuGeneric/SysSe/Math/subdir.mk
-include Libraries/Service/CpuGeneric/SysSe/Bsp/subdir.mk
-include Libraries/Service/CpuGeneric/StdIf/subdir.mk
-include Libraries/Service/CpuGeneric/If/subdir.mk
-include Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
-include Configurations/Debug/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
LQ_TC264DA_LIB.siz \


# All Target
all: LQ_TC264DA_LIB.elf secondary-outputs

# Tool invocations
LQ_TC264DA_LIB.elf: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: TASKING Linker'
	cctc -lrt -lfp_fpu -lcs_fpu  -Wl-Oc -Wl-OL -Wl-Ot -Wl-Ox -Wl-Oy "G:\2022ÄêÖÇÄÜ³µ\WORKSPACE\LQ_TC264DA_LIB\src\APP\LQ_MPU6050_DMP.o" -Wl--map-file="LQ_TC264DA_LIB.map" -Wl-mc -Wl-mf -Wl-mi -Wl-mk -Wl-ml -Wl-mm -Wl-md -Wl-mr -Wl-mu --no-warnings= -Wl--error-limit=42 --strict --anachronisms --force-c++ -Ctc26xb   -o"LQ_TC264DA_LIB.elf" -Wl-o"LQ_TC264DA_LIB.hex:IHEX" --lsl-core=vtc  --lsl-file=../Lcf_Tasking_Tricore_Tc.lsl $(OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

LQ_TC264DA_LIB.siz: LQ_TC264DA_LIB.elf
	@echo 'Invoking: Print Size'
	elfsize  "LQ_TC264DA_LIB.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	find . ! -name "*.mk" ! -name "makefile" ! -name "." -type f -delete 
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets

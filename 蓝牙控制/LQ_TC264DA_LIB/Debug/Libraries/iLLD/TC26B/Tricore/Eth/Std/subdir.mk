################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/iLLD/TC26B/Tricore/Eth/Std/IfxEth.c 

OBJS += \
./Libraries/iLLD/TC26B/Tricore/Eth/Std/IfxEth.o 

COMPILED_SRCS += \
./Libraries/iLLD/TC26B/Tricore/Eth/Std/IfxEth.src 

C_DEPS += \
./Libraries/iLLD/TC26B/Tricore/Eth/Std/IfxEth.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/iLLD/TC26B/Tricore/Eth/Std/%.src: ../Libraries/iLLD/TC26B/Tricore/Eth/Std/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D__CPU__=tc26xb -I"G:\2022\111\LQ_TC264\LQ_TC264DA_DDC_Xunji211228\src" -I"G:\2022\111\LQ_TC264\LQ_TC264DA_DDC_Xunji211228\src\APP" -I"G:\2022\111\LQ_TC264\LQ_TC264DA_DDC_Xunji211228\src\Driver" -I"G:\2022\111\LQ_TC264\LQ_TC264DA_DDC_Xunji211228\src\Main" -I"G:\2022\111\LQ_TC264\LQ_TC264DA_DDC_Xunji211228\src\User" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Gpt12" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/Infra/Platform/Tricore/Compilers" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Multican/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/Infra/Platform" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Cif/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Hssl/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Cpu/Trap" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/Service/CpuGeneric/If/Ccu6If" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Dsadc/Dsadc" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Port" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Stm/Timer" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Dts/Dts" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Eth" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Flash" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Vadc" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Msc" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Qspi/SpiMaster" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Scu/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/Service/CpuGeneric/SysSe/Comm" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/Service/CpuGeneric/SysSe/Math" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/Infra/Platform/Tricore" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Gtm/Trig" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Gtm/Tim" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Ccu6/TimerWithTrigger" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Emem" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Mtu" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/Infra" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Fft" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/I2c/I2c" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Asclin/Asc" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/Service/CpuGeneric/SysSe" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Flash/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/Service/CpuGeneric/If" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Psi5" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Cpu" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Fce/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Stm/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Msc/Msc" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Vadc/Adc" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Asclin" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Gtm/Tom/Pwm" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Gtm/Atom" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Port/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Psi5/Psi5" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Eray" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Qspi/SpiSlave" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Ccu6/Icu" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Cpu/CStart" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Hssl" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Cif" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Eth/Phy_Pef7071" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Hssl/Hssl" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Iom/Driver" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Multican/Can" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Psi5s/Psi5s" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Fft/Fft" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Ccu6/PwmHl" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Iom/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/_Lib" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Gtm/Tom/Timer" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Sent" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Eray/Eray" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Gpt12/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Dma" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Fce/Crc" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Qspi" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/Infra/Sfr" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/Infra/Sfr/TC26B" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/Service/CpuGeneric/SysSe/Bsp" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/Service/CpuGeneric/SysSe/General" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Cpu/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Dts" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Src" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Dma/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Cif/Cam" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Src/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Asclin/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/I2c/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Configurations" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/_Lib/DataHandling" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Sent/Sent" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Ccu6/Timer" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Psi5/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Psi5s" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Emem/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Ccu6/PwmBc" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Iom" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Ccu6/TPwm" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/Service/CpuGeneric" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Multican" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Mtu/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/Infra/Sfr/TC26B/_Reg" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Gtm/Tom/PwmHl" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Dma/Dma" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Gtm/Atom/Timer" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Ccu6/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/Service/CpuGeneric/SysSe/Time" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Dsadc/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Cpu/Irq" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Gtm" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Ccu6" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Gpt12/IncrEnc" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Psi5s/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Scu" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/_Lib/InternalMux" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Stm" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Dsadc/Rdc" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Vadc/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Dts/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/Service" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Eth/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Smu" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/_PinMap" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Asclin/Lin" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/Service/CpuGeneric/StdIf" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Dsadc" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Fce" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Gtm/Atom/PwmHl" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Qspi/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Gtm/Tom" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Gtm/Tim/In" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Msc/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Configurations/Debug" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Fft/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Gtm/Atom/Pwm" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/Service/CpuGeneric/_Utilities" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Gtm/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Smu/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/I2c" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Asclin/Spi" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Eray/Std" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Port/Io" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/_Impl" -I"G:/2022/111/LQ_TC264/LQ_TC264DA_DDC_Xunji211228/Libraries/iLLD/TC26B/Tricore/Sent/Std" --iso=99 --c++14 --language=+volatile --anachronisms --fp-model=3 --fp-model=c --fp-model=f --fp-model=l --fp-model=n --fp-model=r --fp-model=z -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -o "$@"  "$<"  -cs --dep-file=$(@:.src=.d) --misrac-version=2012 -N0 -Z0 -Y0 2>&1; sed -i -e '/ctc\\include/d' -e '/Libraries\\iLLD/d' -e '/Libraries\\Infra/d' -e 's/\(.*\)".*\\LQ_TC264DA_LIB\(\\.*\)"/\1\.\.\2/g' -e 's/\\/\//g' $(@:.src=.d) && \
	echo $(@:.src=.d) generated
	@echo 'Finished building: $<'
	@echo ' '

Libraries/iLLD/TC26B/Tricore/Eth/Std/%.o: ./Libraries/iLLD/TC26B/Tricore/Eth/Std/%.src
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '



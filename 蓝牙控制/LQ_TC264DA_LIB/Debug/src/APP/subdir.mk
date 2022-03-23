################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/APP/LQ_ADC_test.c \
../src/APP/LQ_Atom_Motor.c \
../src/APP/LQ_CAMERA.c \
../src/APP/LQ_CCU6_Timer.c \
../src/APP/LQ_EEPROM_TEST.c \
../src/APP/LQ_FFT_TEST.c \
../src/APP/LQ_GPIO_ExInt.c \
../src/APP/LQ_GPIO_KEY.c \
../src/APP/LQ_GPIO_LED.c \
../src/APP/LQ_GPT_mini512.c \
../src/APP/LQ_I2C_9AX.c \
../src/APP/LQ_I2C_VL53.c \
../src/APP/LQ_ICM20602.c \
../src/APP/LQ_IIC_Gyro.c \
../src/APP/LQ_MT9V034.c \
../src/APP/LQ_OLED096.c \
../src/APP/LQ_STM_Timer.c \
../src/APP/LQ_TFT18.c \
../src/APP/LQ_TFT2.c \
../src/APP/LQ_TFTPicFont.c \
../src/APP/LQ_Tim_InputCature.c \
../src/APP/LQ_Tom_Servo.c \
../src/APP/LQ_UART_Bluetooth.c 

O_SRCS += \
../src/APP/LQ_MPU6050_DMP.o 

OBJS += \
./src/APP/LQ_ADC_test.o \
./src/APP/LQ_Atom_Motor.o \
./src/APP/LQ_CAMERA.o \
./src/APP/LQ_CCU6_Timer.o \
./src/APP/LQ_EEPROM_TEST.o \
./src/APP/LQ_FFT_TEST.o \
./src/APP/LQ_GPIO_ExInt.o \
./src/APP/LQ_GPIO_KEY.o \
./src/APP/LQ_GPIO_LED.o \
./src/APP/LQ_GPT_mini512.o \
./src/APP/LQ_I2C_9AX.o \
./src/APP/LQ_I2C_VL53.o \
./src/APP/LQ_ICM20602.o \
./src/APP/LQ_IIC_Gyro.o \
./src/APP/LQ_MT9V034.o \
./src/APP/LQ_OLED096.o \
./src/APP/LQ_STM_Timer.o \
./src/APP/LQ_TFT18.o \
./src/APP/LQ_TFT2.o \
./src/APP/LQ_TFTPicFont.o \
./src/APP/LQ_Tim_InputCature.o \
./src/APP/LQ_Tom_Servo.o \
./src/APP/LQ_UART_Bluetooth.o 

COMPILED_SRCS += \
./src/APP/LQ_ADC_test.src \
./src/APP/LQ_Atom_Motor.src \
./src/APP/LQ_CAMERA.src \
./src/APP/LQ_CCU6_Timer.src \
./src/APP/LQ_EEPROM_TEST.src \
./src/APP/LQ_FFT_TEST.src \
./src/APP/LQ_GPIO_ExInt.src \
./src/APP/LQ_GPIO_KEY.src \
./src/APP/LQ_GPIO_LED.src \
./src/APP/LQ_GPT_mini512.src \
./src/APP/LQ_I2C_9AX.src \
./src/APP/LQ_I2C_VL53.src \
./src/APP/LQ_ICM20602.src \
./src/APP/LQ_IIC_Gyro.src \
./src/APP/LQ_MT9V034.src \
./src/APP/LQ_OLED096.src \
./src/APP/LQ_STM_Timer.src \
./src/APP/LQ_TFT18.src \
./src/APP/LQ_TFT2.src \
./src/APP/LQ_TFTPicFont.src \
./src/APP/LQ_Tim_InputCature.src \
./src/APP/LQ_Tom_Servo.src \
./src/APP/LQ_UART_Bluetooth.src 

C_DEPS += \
./src/APP/LQ_ADC_test.d \
./src/APP/LQ_Atom_Motor.d \
./src/APP/LQ_CAMERA.d \
./src/APP/LQ_CCU6_Timer.d \
./src/APP/LQ_EEPROM_TEST.d \
./src/APP/LQ_FFT_TEST.d \
./src/APP/LQ_GPIO_ExInt.d \
./src/APP/LQ_GPIO_KEY.d \
./src/APP/LQ_GPIO_LED.d \
./src/APP/LQ_GPT_mini512.d \
./src/APP/LQ_I2C_9AX.d \
./src/APP/LQ_I2C_VL53.d \
./src/APP/LQ_ICM20602.d \
./src/APP/LQ_IIC_Gyro.d \
./src/APP/LQ_MT9V034.d \
./src/APP/LQ_OLED096.d \
./src/APP/LQ_STM_Timer.d \
./src/APP/LQ_TFT18.d \
./src/APP/LQ_TFT2.d \
./src/APP/LQ_TFTPicFont.d \
./src/APP/LQ_Tim_InputCature.d \
./src/APP/LQ_Tom_Servo.d \
./src/APP/LQ_UART_Bluetooth.d 


# Each subdirectory must supply rules for building sources it contributes
src/APP/%.src: ../src/APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D__CPU__=tc26xb -I"G:\2022年智能车\WORKSPACE\LQ_TC264DA_LIB\src" -I"G:\2022年智能车\WORKSPACE\LQ_TC264DA_LIB\src\APP" -I"G:\2022年智能车\WORKSPACE\LQ_TC264DA_LIB\src\Driver" -I"G:\2022年智能车\WORKSPACE\LQ_TC264DA_LIB\src\Main" -I"G:\2022年智能车\WORKSPACE\LQ_TC264DA_LIB\src\User" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Gpt12" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/Infra/Platform/Tricore/Compilers" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Multican/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/Infra/Platform" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Cif/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Hssl/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Cpu/Trap" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/Service/CpuGeneric/If/Ccu6If" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Dsadc/Dsadc" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Port" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Stm/Timer" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Dts/Dts" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Eth" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Flash" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Vadc" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Msc" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Qspi/SpiMaster" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Scu/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/Service/CpuGeneric/SysSe/Comm" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/Service/CpuGeneric/SysSe/Math" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/Infra/Platform/Tricore" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Gtm/Trig" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Gtm/Tim" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Ccu6/TimerWithTrigger" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Emem" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Mtu" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/Infra" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Fft" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/I2c/I2c" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Asclin/Asc" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/Service/CpuGeneric/SysSe" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Flash/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/Service/CpuGeneric/If" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Psi5" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Cpu" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Fce/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Stm/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Msc/Msc" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Vadc/Adc" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Asclin" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Gtm/Tom/Pwm" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Gtm/Atom" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Port/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Psi5/Psi5" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Eray" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Qspi/SpiSlave" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Ccu6/Icu" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Cpu/CStart" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Hssl" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Cif" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Eth/Phy_Pef7071" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Hssl/Hssl" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Iom/Driver" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Multican/Can" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Psi5s/Psi5s" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Fft/Fft" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Ccu6/PwmHl" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Iom/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/_Lib" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Gtm/Tom/Timer" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Sent" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Eray/Eray" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Gpt12/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Dma" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Fce/Crc" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Qspi" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/Infra/Sfr" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/Infra/Sfr/TC26B" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/Service/CpuGeneric/SysSe/Bsp" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/Service/CpuGeneric/SysSe/General" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Cpu/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Dts" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Src" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Dma/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Cif/Cam" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Src/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Asclin/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/I2c/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Configurations" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/_Lib/DataHandling" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Sent/Sent" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Ccu6/Timer" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Psi5/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Psi5s" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Emem/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Ccu6/PwmBc" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Iom" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Ccu6/TPwm" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/Service/CpuGeneric" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Multican" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Mtu/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/Infra/Sfr/TC26B/_Reg" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Gtm/Tom/PwmHl" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Dma/Dma" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Gtm/Atom/Timer" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Ccu6/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/Service/CpuGeneric/SysSe/Time" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Dsadc/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Cpu/Irq" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Gtm" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Ccu6" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Gpt12/IncrEnc" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Psi5s/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Scu" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/_Lib/InternalMux" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Stm" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Dsadc/Rdc" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Vadc/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Dts/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/Service" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Eth/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Smu" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/_PinMap" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Asclin/Lin" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/Service/CpuGeneric/StdIf" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Dsadc" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Fce" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Gtm/Atom/PwmHl" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Qspi/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Gtm/Tom" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Gtm/Tim/In" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Msc/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Configurations/Debug" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Fft/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Gtm/Atom/Pwm" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/Service/CpuGeneric/_Utilities" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Gtm/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Smu/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/I2c" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Asclin/Spi" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Eray/Std" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Port/Io" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/_Impl" -I"G:/2022年智能车/WORKSPACE/LQ_TC264DA_LIB/Libraries/iLLD/TC26B/Tricore/Sent/Std" --iso=99 --c++14 --language=+volatile --anachronisms --fp-model=3 --fp-model=c --fp-model=f --fp-model=l --fp-model=n --fp-model=r --fp-model=z -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -o "$@"  "$<"  -cs --dep-file=$(@:.src=.d) --misrac-version=2012 -N0 -Z0 -Y0 2>&1; sed -i -e '/ctc\\include/d' -e '/Libraries\\iLLD/d' -e '/Libraries\\Infra/d' -e 's/\(.*\)".*\\LQ_TC264DA_LIB\(\\.*\)"/\1\.\.\2/g' -e 's/\\/\//g' $(@:.src=.d) && \
	echo $(@:.src=.d) generated
	@echo 'Finished building: $<'
	@echo ' '

src/APP/%.o: ./src/APP/%.src
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '



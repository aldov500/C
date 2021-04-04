################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/PIN_Tester.c \
../source/kl25z_pin.c \
../source/mtb.c 

OBJS += \
./source/PIN_Tester.o \
./source/kl25z_pin.o \
./source/mtb.o 

C_DEPS += \
./source/PIN_Tester.d \
./source/kl25z_pin.d \
./source/mtb.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_OS_BAREMETAL -DFSL_RTOS_BM -DCPU_MKL25Z128VFM4 -DCPU_MKL25Z128VFM4_cm0plus -D__REDLIB__ -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\PIN_Tester\source" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\PIN_Tester" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\PIN_Tester\drivers" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\PIN_Tester\utilities" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\PIN_Tester\frdmkl25z" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\PIN_Tester\startup" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\PIN_Tester\CMSIS" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/P3_Lights.c \
../source/kl25z_pin.c \
../source/kl25z_pwm.c \
../source/main.c \
../source/mtb.c 

OBJS += \
./source/P3_Lights.o \
./source/kl25z_pin.o \
./source/kl25z_pwm.o \
./source/main.o \
./source/mtb.o 

C_DEPS += \
./source/P3_Lights.d \
./source/kl25z_pin.d \
./source/kl25z_pwm.d \
./source/main.d \
./source/mtb.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_OS_BAREMETAL -DFSL_RTOS_BM -DCPU_MKL25Z128VFM4 -DCPU_MKL25Z128VFM4_cm0plus -D__REDLIB__ -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\Light_Module\source" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\Light_Module" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\Light_Module\drivers" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\Light_Module\startup" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\Light_Module\utilities" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\Light_Module\frdmkl25z" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\Light_Module\CMSIS" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



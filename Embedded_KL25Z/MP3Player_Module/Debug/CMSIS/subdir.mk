################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/system_MKL25Z4.c 

OBJS += \
./CMSIS/system_MKL25Z4.o 

C_DEPS += \
./CMSIS/system_MKL25Z4.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/%.o: ../CMSIS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_OS_BAREMETAL -DFSL_RTOS_BM -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -D__REDLIB__ -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\MP3Player_Module\source" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\MP3Player_Module" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\MP3Player_Module\drivers" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\MP3Player_Module\startup" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\MP3Player_Module\frdmkl25z" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\MP3Player_Module\utilities" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\MP3Player_Module\CMSIS" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



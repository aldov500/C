################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_flash.c \
../drivers/fsl_gpio.c \
../drivers/fsl_lpsci.c \
../drivers/fsl_smc.c \
../drivers/fsl_uart.c 

OBJS += \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_flash.o \
./drivers/fsl_gpio.o \
./drivers/fsl_lpsci.o \
./drivers/fsl_smc.o \
./drivers/fsl_uart.o 

C_DEPS += \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_flash.d \
./drivers/fsl_gpio.d \
./drivers/fsl_lpsci.d \
./drivers/fsl_smc.d \
./drivers/fsl_uart.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DNDEBUG -DSDK_OS_BAREMETAL -DFSL_RTOS_BM -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -D__REDLIB__ -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\MP3Player_Module\source" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\MP3Player_Module" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\MP3Player_Module\drivers" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\MP3Player_Module\startup" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\MP3Player_Module\frdmkl25z" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\MP3Player_Module\utilities" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\MP3Player_Module\CMSIS" -Os -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



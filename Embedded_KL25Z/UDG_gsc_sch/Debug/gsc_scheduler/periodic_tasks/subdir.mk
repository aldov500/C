################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../gsc_scheduler/periodic_tasks/periodic_tasks_exec.c \
../gsc_scheduler/periodic_tasks/periodic_tasks_init.c 

OBJS += \
./gsc_scheduler/periodic_tasks/periodic_tasks_exec.o \
./gsc_scheduler/periodic_tasks/periodic_tasks_init.o 

C_DEPS += \
./gsc_scheduler/periodic_tasks/periodic_tasks_exec.d \
./gsc_scheduler/periodic_tasks/periodic_tasks_init.d 


# Each subdirectory must supply rules for building sources it contributes
gsc_scheduler/periodic_tasks/%.o: ../gsc_scheduler/periodic_tasks/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCR_INTEGER_PRINTF -DDEBUG -DFRDM_KL25Z -DFREEDOM -DSDK_DEBUGCONSOLE=0 -DSDK_DEBUGCONSOLE_UART -D__MCUXPRESSO -D__USE_CMSIS -DCPU_MKL25Z128VLK4_cm0plus -DCPU_MKL25Z128VLK4 -D__REDLIB__ -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\UDG_gsc_sch\source" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\UDG_gsc_sch" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\UDG_gsc_sch\drivers" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\UDG_gsc_sch\board" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\UDG_gsc_sch\utilities" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\UDG_gsc_sch\CMSIS" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\UDG_gsc_sch\startup" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\UDG_gsc_sch\gsc_scheduler" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\UDG_gsc_sch\gsc_scheduler\gsc_sch_core" -I"C:\Users\Aldo Vargas\Google Drive\QCI\2017B\Topicos Selectos de Digitales\Worskpace Kinetis\UDG_gsc_sch\gsc_scheduler\periodic_tasks" -O0 -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



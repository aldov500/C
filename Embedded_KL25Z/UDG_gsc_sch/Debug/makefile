################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include utilities/subdir.mk
-include startup/subdir.mk
-include source/subdir.mk
-include gsc_scheduler/periodic_tasks/subdir.mk
-include gsc_scheduler/gsc_sch_core/subdir.mk
-include drivers/subdir.mk
-include board/subdir.mk
-include app/subdir.mk
-include MAL/subdir.mk
-include HAL/subdir.mk
-include CMSIS/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: UDG_gsc_sch.axf

# Tool invocations
UDG_gsc_sch.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="UDG_gsc_sch.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m0plus -mthumb -T UDG_gsc_schdriver_examples_pit_Debug.ld -o "UDG_gsc_sch.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) UDG_gsc_sch.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "UDG_gsc_sch.axf"; # arm-none-eabi-objcopy -v -O binary "UDG_gsc_sch.axf" "UDG_gsc_sch.bin" ; # checksum -p MKL25Z128xxx4 -d "UDG_gsc_sch.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets

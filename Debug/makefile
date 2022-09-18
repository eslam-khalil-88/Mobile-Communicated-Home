################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Mob.Comm.Home.lss \

FLASH_IMAGE += \
Mob.Comm.Home.hex \

EEPROM_IMAGE += \
Mob.Comm.Home.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Mob.Comm.Home.elf secondary-outputs

# Tool invocations
Mob.Comm.Home.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Mob.Comm.Home.map -mmcu=atmega32 -o "Mob.Comm.Home.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Mob.Comm.Home.lss: Mob.Comm.Home.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Mob.Comm.Home.elf  >"Mob.Comm.Home.lss"
	@echo 'Finished building: $@'
	@echo ' '

Mob.Comm.Home.hex: Mob.Comm.Home.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Mob.Comm.Home.elf  "Mob.Comm.Home.hex"
	@echo 'Finished building: $@'
	@echo ' '

Mob.Comm.Home.eep: Mob.Comm.Home.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Mob.Comm.Home.elf  "Mob.Comm.Home.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Mob.Comm.Home.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Mob.Comm.Home.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Mob.Comm.Home.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:Mob.Comm.Home.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Mob.Comm.Home.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

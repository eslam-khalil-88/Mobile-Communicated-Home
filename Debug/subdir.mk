################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Driv.c \
../Bluetooth.c \
../DIO.c \
../LCDFunc.c \
../SW_TIMER0.c \
../Servo_Driv.c \
../String_OPR.c \
../USART.c \
../main.c 

OBJS += \
./ADC_Driv.o \
./Bluetooth.o \
./DIO.o \
./LCDFunc.o \
./SW_TIMER0.o \
./Servo_Driv.o \
./String_OPR.o \
./USART.o \
./main.o 

C_DEPS += \
./ADC_Driv.d \
./Bluetooth.d \
./DIO.d \
./LCDFunc.d \
./SW_TIMER0.d \
./Servo_Driv.d \
./String_OPR.d \
./USART.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Solom\Desktop\Latest Projects\Mob.Comm.Home" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Praktikum\ 1.cpp 

CPP_DEPS += \
./src/Praktikum\ 1.d 

OBJS += \
./src/Praktikum\ 1.o 


# Each subdirectory must supply rules for building sources it contributes
src/Praktikum\ 1.o: ../src/Praktikum\ 1.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Praktikum 1.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Praktikum\ 1.d ./src/Praktikum\ 1.o

.PHONY: clean-src


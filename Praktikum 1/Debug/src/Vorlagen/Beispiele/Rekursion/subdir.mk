################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Vorlagen/Beispiele/Rekursion/rekursion.cpp 

CPP_DEPS += \
./src/Vorlagen/Beispiele/Rekursion/rekursion.d 

OBJS += \
./src/Vorlagen/Beispiele/Rekursion/rekursion.o 


# Each subdirectory must supply rules for building sources it contributes
src/Vorlagen/Beispiele/Rekursion/%.o: ../src/Vorlagen/Beispiele/Rekursion/%.cpp src/Vorlagen/Beispiele/Rekursion/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-Vorlagen-2f-Beispiele-2f-Rekursion

clean-src-2f-Vorlagen-2f-Beispiele-2f-Rekursion:
	-$(RM) ./src/Vorlagen/Beispiele/Rekursion/rekursion.d ./src/Vorlagen/Beispiele/Rekursion/rekursion.o

.PHONY: clean-src-2f-Vorlagen-2f-Beispiele-2f-Rekursion


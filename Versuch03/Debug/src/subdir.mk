################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/reversi.cpp \
../src/reversiKI.cpp \
../src/test.cpp 

CPP_DEPS += \
./src/reversi.d \
./src/reversiKI.d \
./src/test.d 

OBJS += \
./src/reversi.o \
./src/reversiKI.o \
./src/test.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/reversi.d ./src/reversi.o ./src/reversiKI.d ./src/reversiKI.o ./src/test.d ./src/test.o

.PHONY: clean-src


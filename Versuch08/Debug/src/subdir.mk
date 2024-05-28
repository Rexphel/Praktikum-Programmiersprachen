################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Buch.cpp \
../src/Buecherei.cpp \
../src/DVD.cpp \
../src/Datum.cpp \
../src/Magazin.cpp \
../src/Medium.cpp \
../src/Person.cpp 

CPP_DEPS += \
./src/Buch.d \
./src/Buecherei.d \
./src/DVD.d \
./src/Datum.d \
./src/Magazin.d \
./src/Medium.d \
./src/Person.d 

OBJS += \
./src/Buch.o \
./src/Buecherei.o \
./src/DVD.o \
./src/Datum.o \
./src/Magazin.o \
./src/Medium.o \
./src/Person.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Buch.d ./src/Buch.o ./src/Buecherei.d ./src/Buecherei.o ./src/DVD.d ./src/DVD.o ./src/Datum.d ./src/Datum.o ./src/Magazin.d ./src/Magazin.o ./src/Medium.d ./src/Medium.o ./src/Person.d ./src/Person.o

.PHONY: clean-src


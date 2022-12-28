################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/NumberMatchBase.cpp \
../src/entorno.cpp \
../src/pr_tadCelda.cpp \
../src/pr_tadTablero.cpp \
../src/tadCelda.cpp \
../src/tadTablero.cpp 

OBJS += \
./src/NumberMatchBase.o \
./src/entorno.o \
./src/pr_tadCelda.o \
./src/pr_tadTablero.o \
./src/tadCelda.o \
./src/tadTablero.o 

CPP_DEPS += \
./src/NumberMatchBase.d \
./src/entorno.d \
./src/pr_tadCelda.d \
./src/pr_tadTablero.d \
./src/tadCelda.d \
./src/tadTablero.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



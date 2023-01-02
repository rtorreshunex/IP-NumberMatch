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
../src/tadJuego.cpp \
../src/tadTablero.cpp 

CPP_DEPS += \
./src/NumberMatchBase.d \
./src/entorno.d \
./src/pr_tadCelda.d \
./src/pr_tadTablero.d \
./src/tadCelda.d \
./src/tadJuego.d \
./src/tadTablero.d 

OBJS += \
./src/NumberMatchBase.o \
./src/entorno.o \
./src/pr_tadCelda.o \
./src/pr_tadTablero.o \
./src/tadCelda.o \
./src/tadJuego.o \
./src/tadTablero.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/NumberMatchBase.d ./src/NumberMatchBase.o ./src/entorno.d ./src/entorno.o ./src/pr_tadCelda.d ./src/pr_tadCelda.o ./src/pr_tadTablero.d ./src/pr_tadTablero.o ./src/tadCelda.d ./src/tadCelda.o ./src/tadJuego.d ./src/tadJuego.o ./src/tadTablero.d ./src/tadTablero.o

.PHONY: clean-src


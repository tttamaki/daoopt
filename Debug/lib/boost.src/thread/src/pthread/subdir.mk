################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/boost.src/thread/src/pthread/exceptions.cpp \
../lib/boost.src/thread/src/pthread/once.cpp \
../lib/boost.src/thread/src/pthread/thread.cpp 

OBJS += \
./lib/boost.src/thread/src/pthread/exceptions.o \
./lib/boost.src/thread/src/pthread/once.o \
./lib/boost.src/thread/src/pthread/thread.o 

CPP_DEPS += \
./lib/boost.src/thread/src/pthread/exceptions.d \
./lib/boost.src/thread/src/pthread/once.d \
./lib/boost.src/thread/src/pthread/thread.d 


# Each subdirectory must supply rules for building sources it contributes
lib/boost.src/thread/src/pthread/%.o: ../lib/boost.src/thread/src/pthread/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	ccache g++ -DDEBUG -DLINUX -I../include -I../lib -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


cmake_minimum_required(VERSION 3.20)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/cmake/avr-toolchain.cmake")

project(my_freertos_app C ASM)

set(MCU   atmega32u4)
set(F_CPU 16000000UL)

add_library(avr_common INTERFACE)
target_compile_options(avr_common INTERFACE
    -mmcu=${MCU} -DF_CPU=${F_CPU}
    -Os -Wall -ffunction-sections -fdata-sections
)
target_link_options(avr_common INTERFACE
    -mmcu=${MCU} -Wl,--gc-sections
)

# FreeRTOSConfig.h
add_library(freertos_config INTERFACE)
target_include_directories(freertos_config SYSTEM INTERFACE
    "${CMAKE_SOURCE_DIR}/app"
)
target_compile_definitions(freertos_config INTERFACE
    projCOVERAGE_TEST=0
)
target_link_libraries(freertos_config INTERFACE avr_common)

# Port AVR 
set(FREERTOS_PORT GCC_ATMEGA CACHE STRING "" FORCE)

# Heap
set(FREERTOS_HEAP
    "${CMAKE_SOURCE_DIR}/FreeRTOS/portable/MemMang/heap_1.c"
    CACHE STRING "" FORCE
)

add_subdirectory(FreeRTOS)

# Flags AVR propagés au kernel et au port
target_link_libraries(freertos_kernel        PUBLIC avr_common)
target_link_libraries(freertos_kernel_port   PUBLIC avr_common)

# Application séparée de FreeRTOS
add_subdirectory(app)

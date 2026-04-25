add_executable(firmware.elf main.c usart_atmega.c)

target_include_directories(firmware.elf PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}  # FreeRTOSConfig.h
)

target_link_libraries(firmware.elf PRIVATE
    freertos_kernel
    avr_common
)

add_custom_command(TARGET firmware.elf POST_BUILD
    COMMAND avr-objcopy -O ihex -R .eeprom
            $<TARGET_FILE:firmware.elf> firmware.hex
    COMMENT "Génération firmware.hex"
)

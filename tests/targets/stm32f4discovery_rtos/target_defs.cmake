include(${MCUS_DIR}/stm32f407/mcu_defs.cmake)

# External oscillator has a 8 MHz out clock
set(CONFIG_PLATFORM_HSE_VAL 8000000)

# Enable console, only bypass. Streams are not used for this target.
set(CONFIG_USE_BYPASS_CONSOLE 1)
# UART #3 used for console output
set(CONFIG_CONSOLE_DEVICE_NUM 3)
# Baud rate of the console
set(CONFIG_CONSOLE_BAUD 115200)

# Enable FreRTOS
set(CONFIG_OS freertos)
set(CONFIG_FREERTOS_HEADERS_PATH ${CMAKE_CURRENT_LIST_DIR})

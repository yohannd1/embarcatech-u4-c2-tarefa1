# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(u4_c2_tarefa1 C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

add_executable(u4_c2_tarefa1
    src/main.c
    src/buzzer.c
)

pico_set_program_name(u4_c2_tarefa1 "U4, C2, Tarefa 1")
pico_set_program_version(u4_c2_tarefa1 "0.1")

pico_enable_stdio_uart(u4_c2_tarefa1 0)
pico_enable_stdio_usb(u4_c2_tarefa1 1)

# Add the standard library to the build
target_link_libraries(u4_c2_tarefa1
    pico_stdlib
    hardware_pwm
)

# Add the standard include files to the build
target_include_directories(u4_c2_tarefa1 PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
)

# Add any user requested libraries
target_link_libraries(u4_c2_tarefa1
)

pico_add_extra_outputs(u4_c2_tarefa1)

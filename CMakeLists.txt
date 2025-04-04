cmake_minimum_required(VERSION 3.15)
project(secure-delete)

# Set the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Set compiler flags
add_compile_options(-Wall -Werror)

# Include directory
include_directories(include)

# Add the executable
add_executable(secure-delete
    src/functions.c
    src/main.c
)

# Custom clean target (CMake already has a clean target, this is just for reference)
add_custom_target(extra_clean
    COMMAND ${CMAKE_COMMAND} -E remove secure-delete
)

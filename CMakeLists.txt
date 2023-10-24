cmake_minimum_required(VERSION 3.20)

project(math_interpreter C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

# target_link_libraries(math-interpreter your_library_name)

add_executable(math-interpreter ./src/main.c ./src/mpc.c)
set_target_properties(math-interpreter PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build
)


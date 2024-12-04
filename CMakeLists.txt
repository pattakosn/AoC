cmake_minimum_required(VERSION 3.25 FATAL_ERROR)
project(advent2024 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#set(BUILD_SHARED_LIBS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Debug)

if (MSVC)
    add_compile_options(/W4)
else()
    #-fsanitize=memory
    #add_compile_options(-fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment -Wall -Wextra -Wpedantic)
    add_compile_options(-Wall -Wextra -Wpedantic)
    #add_link_options(-fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment)
endif()

add_executable(01a 01/a.cpp)
add_executable(01b 01/b.cpp)
add_executable(02a 02/a.cpp)
add_executable(02b 02/b.cpp)

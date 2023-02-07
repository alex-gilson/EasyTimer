cmake_minimum_required(VERSION 3.15)

project(EasyTimer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_library(EasyTimer "")

set(EASY_TIMER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/)

if(MSVC)
  target_compile_options(EasyTimer PRIVATE /W4 /WX)
else()
  target_compile_options(EasyTimer PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

add_subdirectory(src)
add_subdirectory(test)

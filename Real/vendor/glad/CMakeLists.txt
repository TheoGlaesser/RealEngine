cmake_minimum_required(VERSION 3.13)

include_directories(${CMAKE_SOURCE_DIR}/vendor/glad/include)

add_library(glad STATIC ${CMAKE_SOURCE_DIR}/vendor/glad/src/glad.c)

target_compile_definitions(glad PUBLIC GLFW_INCLUDE_NONE)
set_property(TARGET glad PROPERTY POSITION_INDEPENDENT_CODE ON)



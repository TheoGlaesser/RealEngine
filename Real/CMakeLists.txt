cmake_minimum_required(VERSION 3.13)

project(real)

add_library(real SHARED ${CMAKE_SOURCE_DIR}/src/Real/Application.cpp) 

target_include_directories(real PUBLIC ${CMAKE_SOURCE_DIR}/src/Real.h)




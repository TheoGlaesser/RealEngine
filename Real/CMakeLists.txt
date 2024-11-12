cmake_minimum_required(VERSION 3.13)

project(real)

set(PROJECT_SOURCES
  src/Real/Application.cpp
  src/Real/Log.cpp
  src/Real/Log.h
)

add_library(real SHARED ${CMAKE_SOURCE_DIR}/${PROJECT_SOURCES}) 

add_subdirectory(vendor/glfw)
target_link_libraries(real PRIVATE glfw)

target_include_directories(real PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_include_directories(real PUBLIC ${CMAKE_SOURCE_DIR}/vendor/spdlog/include)

target_precompile_headers(real PRIVATE  src/realpch.h)



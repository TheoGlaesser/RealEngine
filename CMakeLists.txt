project(main)

set(current ${CMAKE_SOURCE_DIR})

cmake_minimum_required(VERSION 3.13)

add_executable(main ${CMAKE_SOURCE_DIR}/Sandbox/src/Application.cpp)

target_include_directories(main PUBLIC current/Real/src/Real.h)
target_include_directories(main PUBLIC ${CMAKE_SOURCE_DIR}/Real/vendor/spdlog/include)

target_link_libraries(main ${CMAKE_SOURCE_DIR}/bin/libreal.so)

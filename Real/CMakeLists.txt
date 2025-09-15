cmake_minimum_required(VERSION 3.13)

project(real)

set(PROJECT_SOURCES
  src/Real/Application.cpp
  src/Real/Log.cpp
  src/Real/Layerstack.cpp
  src/Real/Layer.cpp
  src/Platform/Ubuntu/UbuntuWindow.cpp
)

add_library(real SHARED ${CMAKE_SOURCE_DIR}/${PROJECT_SOURCES}) 

target_compile_definitions(real PRIVATE REAL_ENABLE_ASSERTS)
target_compile_definitions(real PUBLIC GLFW_INCLUDE_NONE)
target_link_options(real PUBLIC -fPIC)

#-----------------------------------
# ADD SUBDIRECTORIES
#-----------------------------------
add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)

#----------------------------------
#LINK LIBRARIES OF TARGET Real
#----------------------------------
target_link_libraries(real PUBLIC glfw)
target_link_libraries(real PUBLIC glad)

#-----------------------------------
#INCLUDE DIRECTORIES OF TARGET REAL
#-----------------------------------
target_include_directories(real PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_include_directories(real PUBLIC ${CMAKE_SOURCE_DIR}/src/Platform/Ubuntu)

target_include_directories(real PUBLIC ${CMAKE_SOURCE_DIR}/vendor/spdlog/include)
target_include_directories(real PUBLIC ${CMAKE_SOURCE_DIR}/vendor/glad/include)


target_precompile_headers(real PUBLIC  src/realpch.h)



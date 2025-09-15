project(main)

cmake_minimum_required(VERSION 3.13)

add_executable(main ${CMAKE_SOURCE_DIR}/Sandbox/src/Application.cpp)




# Find OpenGL
find_package(OpenGL REQUIRED)

# Include GLFW (optional, for window management)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)



target_include_directories(main PUBLIC current/Real/src/Real.h)
target_include_directories(main PUBLIC ${CMAKE_SOURCE_DIR}/Real/vendor/spdlog/include)
target_include_directories(main PUBLIC ${CMAKE_SOURCE_DIR}/Real/vendor/glad/include)
target_include_directories(main PUBLIC ${GLFW_INCLUDE_DIRS})


#--------------------------------------------
#LINK AGAINST SHARED MODULES WHICH ARE NOT STATIC
#--------------------------------------------
target_link_libraries(main PRIVATE ${CMAKE_SOURCE_DIR}/bin/libreal.so)
target_link_libraries(main PRIVATE OpenGL::GL ${GLFW_LIBRARIES})

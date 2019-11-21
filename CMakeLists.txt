cmake_minimum_required(VERSION 3.15)
project(glAssigment)
set(PROJECT_EXECUTABLE glAssigment)
set(CMAKE_CXX_STANDARD 17)

# src and include dir
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_SOURCE_DIR}/include)

# set sources
set(PROJECT_SOURCES
        ${SRC_DIR}/main.cpp
        ${SRC_DIR}/glad.c
        )

# glfw
set(glfw3_DIR ${CMAKE_SOURCE_DIR}/../../Dependencies/GLFW/lib/cmake/glfw3)

# glm
set(GLM_INC_DIR ${CMAKE_SOURCE_DIR}/../../Dependencies)

include_directories(
        ${INC_DIR}
        ${GLM_INC_DIR}
)

find_package(glfw3 3.2 REQUIRED)

add_executable(${PROJECT_EXECUTABLE} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} glfw)

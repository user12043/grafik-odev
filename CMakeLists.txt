cmake_minimum_required(VERSION 3.15)
project(GL_assigment)
set(PROJECT_EXECUTABLE GL_assigment)
set(CMAKE_CXX_STANDARD 17)

# src and include dir
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_SOURCE_DIR}/include)

# set sources
set(PROJECT_SOURCES
        ${SRC_DIR}/glad.c
        ${SRC_DIR}/main.cpp
        ${SRC_DIR}/shader_program.cpp
        ${SRC_DIR}/drawing.cpp
        ${SRC_DIR}/SnakeCell.cpp
        ${SRC_DIR}/Snake.cpp
        ${SRC_DIR}/Texture.cpp
        )

# set headers
set(PROJECT_HEADERS
        ${INC_DIR}/drawing.h
        ${INC_DIR}/Direction.h
        ${INC_DIR}/SnakeCell.h
        ${INC_DIR}/Snake.h
        ${INC_DIR}/Texture.h
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

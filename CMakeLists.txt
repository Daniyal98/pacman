cmake_minimum_required(VERSION 3.9.1)
project(Pacman)

find_package(GLEW 2.0 REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

include_directories("include")

file(GLOB SOURCES "src/*.cpp")

add_executable(game ${SOURCES})
include_directories(${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR})
target_link_libraries(game GLEW::GLEW ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
cmake_minimum_required(VERSION 3.0)

project(vtk_test2)

add_executable(vtk_test2 main.cpp)

install(TARGETS vtk_test2 RUNTIME DESTINATION bin)

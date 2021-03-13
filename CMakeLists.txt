cmake_minimum_required(VERSION 3.0)

project(vtk_test2)

add_executable(vtk_test2 main.cpp)

find_package(VTK COMPONENTS 
vtkCommonColor
vtkCommonCore
vtkFiltersSources
vtkInteractionStyle
vtkRenderingContextOpenGL2
vtkRenderingCore
vtkRenderingFreeType
vtkRenderingGL2PSOpenGL2
vtkRenderingOpenGL2
QUIET)

target_link_libraries(vtk_test2 PRIVATE ${VTK_LIBRARIES})

install(TARGETS vtk_test2 RUNTIME DESTINATION bin)

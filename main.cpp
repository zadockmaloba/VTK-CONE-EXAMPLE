
#include <vtk-7.1/vtkAutoInit.h> 
VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL2
VTK_MODULE_INIT(vtkInteractionStyle);

#include <iostream>
#include <vtk-7.1/vtkActor.h>
#include <vtk-7.1/vtkCamera.h>
#include <vtk-7.1/vtkCylinderSource.h>
#include <vtk-7.1/vtkConeSource.h>
#include <vtk-7.1/vtkNamedColors.h>
#include <vtk-7.1/vtkNew.h>
#include <vtk-7.1/vtkPolyDataMapper.h>
#include <vtk-7.1/vtkProperty.h>
#include <vtk-7.1/vtkRenderWindow.h>
#include <vtk-7.1/vtkRenderWindowInteractor.h>
#include <vtk-7.1/vtkRenderer.h>
#include <array>

int main(int argc, char **argv) 
{
  vtkConeSource* cone = vtkConeSource::New();
  cone->Update();

  vtkPolyDataMapper* mapper = vtkPolyDataMapper::New();
  mapper->SetInputConnection(cone->GetOutputPort());

  vtkActor* conActor = vtkActor::New();
  conActor->SetMapper(mapper);

  vtkRenderer* ren = vtkRenderer::New();
  ren->AddActor(conActor);

  vtkRenderWindow* win = vtkRenderWindow::New();
  win->AddRenderer(ren);

  vtkRenderWindowInteractor* winIntr = vtkRenderWindowInteractor::New();
  winIntr->SetRenderWindow(win);

  win->Render();
  winIntr->Start();

  return EXIT_SUCCESS;
}

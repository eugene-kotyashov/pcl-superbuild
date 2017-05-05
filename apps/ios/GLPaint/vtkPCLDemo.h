/*========================================================================
  VES --- VTK OpenGL ES Rendering Toolkit

      http://www.kitware.com/ves

  Copyright 2011 Kitware, Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
 ========================================================================*/
/// \class vtkPCLDemo
/// \ingroup KiwiPlatform
#ifndef __vtkPCLDemo_h
#define __vtkPCLDemo_h

// #include <vtkWidgetRepresentation.h>
#include "vtkShaderProgram.h"
#include "vtkNew.h"
#include "vtkActor.h"
#include "vtkCamera.h"
#include "vtkConeSource.h"
#include "vtkDebugLeaks.h"
#include "vtkGlyph3D.h"
#include "vtkPolyData.h"
#include "vtkPolyDataMapper.h"
#include "vtkIOSRenderWindow.h"
#include "vtkIOSRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkSphereSource.h"
#include "vtkCommand.h"
// #include "vtkInteractorStyleMultiTouchCamera.h"
#include "vtkMapper.h"
//#include "vtkGeometryData.h"

//use?
#include <vtkTimerLog.h>
#include <vtkPoints.h>
#include <vtkPointData.h>
#include <vtkUnsignedCharArray.h>
#include <vtkLookupTable.h>

#include <vector>
#include <cassert>
#include <sstream>

// class vtkPCLDemo : public vtkWidgetRepresentation
class vtkPCLDemo
{
public:
  vtkPCLDemo();
  ~vtkPCLDemo();

  void initialize(const std::string& filename);

  void setLeafSize(double value);

  void setPlaneDistanceThreshold(double value);
  vtkSmartPointer<vtkPolyData> GetPolyData();
    
  virtual int numberOfFacets();
  virtual int numberOfVertices();
  virtual int numberOfLines();

  class vtkInternal;

protected:

  // vtkSharedPtr<vtkGeometryData> updateGeometryData();
  // void updateGeometryData();

private:

  vtkPCLDemo(const vtkPCLDemo&); // Not implemented
  void operator=(const vtkPCLDemo&); // Not implemented


  vtkInternal* Internal;
};

#endif

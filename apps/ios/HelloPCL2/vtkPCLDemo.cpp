/*========================================================================
  VES --- VTK OpenGL ES Rendering Toolkit

      http://www.kitware.com/vtk

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

#include "vtkKiwiPCLDemo.h"


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
#include "vtkGeometryData.h"

// pcl
#include "vtkPCLConversions.h"
#include "vtkPCLSACSegmentationPlane.h"
#include "vtkPCLVoxelGrid.h"

//use?
#include <vtkTimerLog.h>
#include <vtkPoints.h>
#include <vtkPointData.h>
#include <vtkUnsignedCharArray.h>
#include <vtkLookupTable.h>

#include <vector>
#include <cassert>
#include <sstream>

//----------------------------------------------------------------------------
class vtkKiwiPCLDemo::vtkInternal
{
public:

  vtkInternal()
  {
    this->LeafSize = 0.05;
    this->PlaneDistanceThreshold = 0.0;
  }

  ~vtkInternal()
  {
  }

  double LeafSize;
  double PlaneDistanceThreshold;
  vtkSmartPointer<vtkPolyData> PolyData;
  vtkShaderProgram::Ptr GeometryShader;
};

//----------------------------------------------------------------------------
vtkKiwiPCLDemo::vtkKiwiPCLDemo()
{
  this->Internal = new vtkInternal();
}

//----------------------------------------------------------------------------
vtkKiwiPCLDemo::~vtkKiwiPCLDemo()
{
  delete this->Internal;
}

//----------------------------------------------------------------------------
void vtkKiwiPCLDemo::setLeafSize(double value)
{
  if (this->Internal->LeafSize != value) {
    this->Internal->LeafSize = value;
  }
}

//----------------------------------------------------------------------------
void vtkKiwiPCLDemo::setPlaneDistanceThreshold(double value)
{
  if (this->Internal->PlaneDistanceThreshold != value) {
    this->Internal->PlaneDistanceThreshold = value;
  }
}

//----------------------------------------------------------------------------
void vtkKiwiPCLDemo::initialize(const std::string& filename, vtkSharedPtr<vtkShaderProgram> shader)
{
  this->Internal->PolyData = vtkPCLConversions::PolyDataFromPCDFile(filename);

  this->Internal->GeometryShader = shader;
}

namespace {

void ConvertVertexArrays(vtkDataSet* dataSet, vtkSharedPtr<vtkGeometryData> geometryData, vtkScalarsToColors* scalarsToColors=NULL)
{
  vtkUnsignedCharArray* colors = vtkKiwiDataConversionTools::FindRGBColorsArray(dataSet);
  vtkDataArray* scalars = vtkKiwiDataConversionTools::FindScalarsArray(dataSet);
  vtkDataArray* tcoords = vtkKiwiDataConversionTools::FindTextureCoordinatesArray(dataSet);
  if (colors)
    {
    vtkKiwiDataConversionTools::SetVertexColors(colors, geometryData);
    }
  else if (scalars)
    {
    vtkSmartPointer<vtkScalarsToColors> colorMap = scalarsToColors;
    if (!colorMap)
      {
      colorMap = vtkKiwiDataConversionTools::GetRedToBlueLookupTable(scalars->GetRange());
      }
    vtkKiwiDataConversionTools::SetVertexColors(scalars, colorMap, geometryData);
    }
  else if (tcoords)
    {
    vtkKiwiDataConversionTools::SetTextureCoordinates(tcoords, geometryData);
    }
}

}


//----------------------------------------------------------------------------
vtkGeometryData::Ptr vtkKiwiPCLDemo::updateGeometryData()
{
  if (!this->Internal->PolyData) {
    return vtkGeometryData::Ptr(new vtkGeometryData);
  }

  vtkSmartPointer<vtkPolyData> polyData = this->Internal->PolyData;

  if (this->Internal->LeafSize != 0.0) {
    vtkSmartPointer<vtkPCLVoxelGrid> voxelGrid = vtkSmartPointer<vtkPCLVoxelGrid>::New();
    voxelGrid->SetInputData(this->Internal->PolyData);
    voxelGrid->SetLeafSize(this->Internal->LeafSize, this->Internal->LeafSize, this->Internal->LeafSize);
    voxelGrid->Update();
    polyData = voxelGrid->GetOutput();
  }

  if (this->Internal->PlaneDistanceThreshold != 0.0) {
    vtkSmartPointer<vtkPCLSACSegmentationPlane> fitPlane = vtkSmartPointer<vtkPCLSACSegmentationPlane>::New();
    fitPlane->SetInputData(polyData);
    fitPlane->SetMaxIterations(200);
    fitPlane->SetDistanceThreshold(this->Internal->PlaneDistanceThreshold);
    fitPlane->Update();
    polyData = fitPlane->GetOutput();
    polyData->GetPointData()->RemoveArray("rgb_colors");
  }

  vtkGeometryData::Ptr geometryData = vtkKiwiDataConversionTools::ConvertPoints(polyData);

  ConvertVertexArrays(polyData, geometryData);

  return geometryData;

}

//----------------------------------------------------------------------------
bool vtkKiwiPCLDemo::handleSingleTouchDown(int displayX, int displayY)
{
  vtkNotUsed(displayX);
  vtkNotUsed(displayY);
  return false;
}

//----------------------------------------------------------------------------
bool vtkKiwiPCLDemo::handleSingleTouchUp()
{
  return false;
}

//----------------------------------------------------------------------------
bool vtkKiwiPCLDemo::handleSingleTouchTap(int displayX, int displayY)
{
  vtkNotUsed(displayX);
  vtkNotUsed(displayY);

  return false;
}

//----------------------------------------------------------------------------
bool vtkKiwiPCLDemo::handleSingleTouchPanGesture(double deltaX, double deltaY)
{
  vtkNotUsed(deltaX);
  vtkNotUsed(deltaY);
  return false;
}

//----------------------------------------------------------------------------
void vtkKiwiPCLDemo::willRender(vtkSharedPtr<vtkRenderer> renderer)
{
  vtkNotUsed(renderer);
}

//----------------------------------------------------------------------------
void vtkKiwiPCLDemo::addSelfToRenderer(vtkSharedPtr<vtkRenderer> renderer)
{
  this->Superclass::addSelfToRenderer(renderer);
}

//----------------------------------------------------------------------------
void vtkKiwiPCLDemo::removeSelfFromRenderer(vtkSharedPtr<vtkRenderer> renderer)
{
  this->Superclass::removeSelfFromRenderer(renderer);
}

//----------------------------------------------------------------------------
int vtkKiwiPCLDemo::numberOfFacets()
{
  return 0;
}

//----------------------------------------------------------------------------
int vtkKiwiPCLDemo::numberOfVertices()
{
  return 0;
}

//----------------------------------------------------------------------------
int vtkKiwiPCLDemo::numberOfLines()
{
  return 0;
}

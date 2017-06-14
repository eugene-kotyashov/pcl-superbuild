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

#include "vtkPCLDemo.h"

// pcl
#include "vtkPCLConversions.h"
#include "vtkPCLSACSegmentationPlane.h"
#include "vtkPCLVoxelGrid.h"

//----------------------------------------------------------------------------
class vtkPCLDemo::vtkInternal
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
};

//----------------------------------------------------------------------------
vtkPCLDemo::vtkPCLDemo()
{
  this->Internal = new vtkInternal();
}

//----------------------------------------------------------------------------
vtkPCLDemo::~vtkPCLDemo()
{
  delete this->Internal;
}

//----------------------------------------------------------------------------
vtkSmartPointer<vtkPolyData> vtkPCLDemo::GetPolyData()
{
    return this->Internal->PolyData;
}

//----------------------------------------------------------------------------
void vtkPCLDemo::setLeafSize(double value)
{
  if (this->Internal->LeafSize != value) {
    this->Internal->LeafSize = value;
  }
}

//----------------------------------------------------------------------------
void vtkPCLDemo::setPlaneDistanceThreshold(double value)
{
  if (this->Internal->PlaneDistanceThreshold != value) {
    this->Internal->PlaneDistanceThreshold = value;
  }
}

//----------------------------------------------------------------------------
void vtkPCLDemo::initialize(const std::string& filename)
{
  this->Internal->PolyData = vtkPCLConversions::PolyDataFromPCDFile(filename);
}

// vtkPolyData::Ptr vtkPCLDemo::()
// {
//      return this->Internal->PolyData;
// }

// namespace {
//
// void ConvertVertexArrays(vtkDataSet* dataSet, vtkSharedPtr<vtkGeometryData> geometryData, vtkScalarsToColors* scalarsToColors=NULL)
// {
//   vtkUnsignedCharArray* colors = vtkKiwiDataConversionTools::FindRGBColorsArray(dataSet);
//   vtkDataArray* scalars = vtkKiwiDataConversionTools::FindScalarsArray(dataSet);
//   vtkDataArray* tcoords = vtkKiwiDataConversionTools::FindTextureCoordinatesArray(dataSet);
//   if (colors)
//     {
//     vtkKiwiDataConversionTools::SetVertexColors(colors, geometryData);
//     }
//   else if (scalars)
//     {
//     vtkSmartPointer<vtkScalarsToColors> colorMap = scalarsToColors;
//     if (!colorMap)
//       {
//       colorMap = vtkKiwiDataConversionTools::GetRedToBlueLookupTable(scalars->GetRange());
//       }
//     vtkKiwiDataConversionTools::SetVertexColors(scalars, colorMap, geometryData);
//     }
//   else if (tcoords)
//     {
//     vtkKiwiDataConversionTools::SetTextureCoordinates(tcoords, geometryData);
//     }
// }
//
// }


//----------------------------------------------------------------------------
// vtkGeometryData::Ptr vtkPCLDemo::updateGeometryData()
// {
//   if (!this->Internal->PolyData) {
//     return vtkGeometryData::Ptr(new vtkGeometryData);
//   }
//
//   vtkNew<vtkPolyData> polyData = this->Internal->PolyData;
//
//   if (this->Internal->LeafSize != 0.0) {
//     vtkNew<vtkPCLVoxelGrid> voxelGrid = vtkNew<vtkPCLVoxelGrid>::New();
//    voxelGrid->SetInputData(this->Internal->PolyData);
//    voxelGrid->SetLeafSize(this->Internal->LeafSize, this->Internal->LeafSize, this->Internal->LeafSize);
//    voxelGrid->Update();
//    polyData = voxelGrid->GetOutput();
//  }
//
//  if (this->Internal->PlaneDistanceThreshold != 0.0) {
//    vtkNew<vtkPCLSACSegmentationPlane> fitPlane = vtkNew<vtkPCLSACSegmentationPlane>::New();
//    fitPlane->SetInputData(polyData);
//    fitPlane->SetMaxIterations(200);
//    fitPlane->SetDistanceThreshold(this->Internal->PlaneDistanceThreshold);
//    fitPlane->Update();
//    polyData = fitPlane->GetOutput();
//    polyData->GetPointData()->RemoveArray("rgb_colors");
//  }
//
//  vtkGeometryData::Ptr geometryData = vtkKiwiDataConversionTools::ConvertPoints(polyData);
//
//  // ConvertVertexArrays(polyData, geometryData);
//
//  return geometryData;
//
//}

//----------------------------------------------------------------------------
int vtkPCLDemo::numberOfFacets()
{
  return 0;
}

//----------------------------------------------------------------------------
int vtkPCLDemo::numberOfVertices()
{
  return 0;
}

//----------------------------------------------------------------------------
int vtkPCLDemo::numberOfLines()
{
  return 0;
}

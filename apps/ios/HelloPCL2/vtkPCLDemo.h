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

#include <vtkWidgetRepresentation.h>

class vtkPCLDemo : public vtkWidgetRepresentation
{
public:
  vtkPCLDemo();
  ~vtkPCLDemo();

  void initialize(const std::string& filename, vtkSharedPtr<vtkShaderProgram> shader);

  void setLeafSize(double value);

  void setPlaneDistanceThreshold(double value);

  virtual void addSelfToRenderer(vtkSharedPtr<vtkRenderer> renderer);
  virtual void removeSelfFromRenderer(vtkSharedPtr<vtkRenderer> renderer);
  virtual void willRender(vtkSharedPtr<vtkRenderer> renderer);

  virtual int numberOfFacets();
  virtual int numberOfVertices();
  virtual int numberOfLines();

  virtual bool handleSingleTouchTap(int displayX, int displayY);
  virtual bool handleSingleTouchDown(int displayX, int displayY);
  virtual bool handleSingleTouchPanGesture(double deltaX, double deltaY);
  virtual bool handleSingleTouchUp();

  class vtkInternal;

protected:

  vtkSharedPtr<vtkGeometryData> updateGeometryData();

private:

  vtkPCLDemo(const vtkPCLDemo&); // Not implemented
  void operator=(const vtkPCLDemo&); // Not implemented


  vtkInternal* Internal;
};

#endif

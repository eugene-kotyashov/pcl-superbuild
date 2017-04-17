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
/// \class vtkPCLApp
/// \ingroup KiwiPlatform
#ifndef __vtkPCLApp_h
#define __vtkPCLApp_h

#include "vtkKiwiViewerApp.h"
#include "vtkPCLDemo.h"

#include <vtksys/SystemTools.hxx>

class vtkShaderProgram;
class vtkKiwiPolyDataRepresentation;
class vtkGeometryData;

class vtkPCLApp : public vtkKiwiViewerApp
{
public:

  vtkTypeMacro(vtkPCLApp);

  vtkPCLApp()
  {
    this->addBuiltinDataset("Kinect point cloud", "pointcloud.pcd");
  }

  ~vtkPCLApp()
  {
  }

  virtual  bool loadDatasetWithCustomBehavior(const std::string& filename)
  {
    if (this->mRep) {
      this->mRep->removeSelfFromRenderer(this->renderer());
      this->mRep.reset();
    }

    if (vtksys::SystemTools::GetFilenameLastExtension(filename) == ".pcd") {
      return this->loadPCLDemo(filename);
    }
    return vtkKiwiViewerApp::loadDatasetWithCustomBehavior(filename);
  }

  bool loadPCLDemo(const std::string& filename)
  {
    this->mRep = vtkPCLDemo::Ptr(new vtkPCLDemo);
    this->mRep->initialize(filename, this->shaderProgram());
    this->mRep->addSelfToRenderer(this->renderer());
    this->setBackgroundColor(0., 0., 0.);
    return true;
  }

  vtkPCLDemo::Ptr getPCLDemo()
  {
    return this->mRep;
  }


protected:


  vtkPCLDemo::Ptr mRep;


private:

  vtkPCLApp(const vtkPCLApp&); // Not implemented
  void operator=(const vtkPCLApp&); // Not implemented

};

#endif

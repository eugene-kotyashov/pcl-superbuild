/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkPCLSACSegmentationPlane.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkPCLSACSegmentationPlane -
// .SECTION Description
//

#ifndef __vtkPCLSACSegmentationPlane_h
#define __vtkPCLSACSegmentationPlane_h

class vtkPCLSACSegmentationPlane
{
public:
  static vtkPCLSACSegmentationPlane *New();

protected:
  double DistanceThreshold;
  int MaxIterations;

  bool PerpendicularConstraintEnabled;
  double PerpendicularAxis[3];
  double AngleEpsilon;

  double PlaneCoefficients[4];
  double PlaneOrigin[3];
  double PlaneNormal[3];

  virtual int RequestData();

  vtkPCLSACSegmentationPlane();
  virtual ~vtkPCLSACSegmentationPlane();

private:
  vtkPCLSACSegmentationPlane(const vtkPCLSACSegmentationPlane&);  // Not implemented.
  void operator=(const vtkPCLSACSegmentationPlane&);  // Not implemented.
};

#endif



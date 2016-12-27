/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkPCLVoxelGrid.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkPCLVoxelGrid -
// .SECTION Description
//

#ifndef __vtkPCLVoxelGrid_h
#define __vtkPCLVoxelGrid_h

#include <vtkPolyDataAlgorithm.h>


class vtkPCLVoxelGrid
{
public:
  static vtkPCLVoxelGrid *New();

protected:
  double LeafSize[3];

  virtual int RequestData();

  vtkPCLVoxelGrid();
  virtual ~vtkPCLVoxelGrid();
private:
  vtkPCLVoxelGrid(const vtkPCLVoxelGrid&);  // Not implemented.
  void operator=(const vtkPCLVoxelGrid&);  // Not implemented.
};

#endif



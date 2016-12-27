/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkAnnotateOBBs.cxx

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
//
// .NAME vtkPCLConversions - collection of pointcloud library routines
//
// .SECTION Description
//

#ifndef __vtkPCLConversions_h
#define __vtkPCLConversions_h

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/PointIndices.h>
#include <pcl/ModelCoefficients.h>

class vtkPCLConversions
{
public:
        
  static vtkPCLConversions* New();
     
  static void PolyDataFromPCDFile(const std::string& filename);
  static void PolyDataFromPointCloud(pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud);
  static void PolyDataFromPointCloud(pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr cloud);
  static void PolyDataFromPointCloud(pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr cloud);
  static void PointCloudFromPolyData(vtkPolyData* polyData);
  static void NewVertexCells(vtkIdType numberOfVerts);

  static void NewLabelsArray(pcl::IndicesConstPtr indices, vtkIdType length);
  static void NewLabelsArray(pcl::PointIndices::ConstPtr indices, vtkIdType length);
  static void NewLabelsArray(const std::vector<pcl::PointIndices>& indices, vtkIdType length);

  static void PerformPointCloudConversionBenchmark(vtkPolyData* polyData);

protected:

  vtkPCLConversions();
  ~vtkPCLConversions();

private:

  vtkPCLConversions(const vtkPCLConversions&); // Not implemented
  void operator=(const vtkPCLConversions&); // Not implemented
};

#endif

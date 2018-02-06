//
// .NAME PointCloudLibraryConversions - collection of pointcloud library routines
//
// .SECTION Description
//

#ifndef __PointCloudLibraryConversions_h
#define __PointCloudLibraryConversions_h

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/PointIndices.h>
#include <pcl/ModelCoefficients.h>

class PointCloudLibraryConversions
{
public:
  static PointCloudLibraryConversions* New();

  static float* PointCloudDataFromPCDFile(const char* filename);
  static float* PointCloudDataFromPointCloud(pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud);
  static float* PointCloudDataFromPointCloud(pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr cloud);
  static float* PointCloudDataFromPointCloud(pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr cloud);

protected:
  PointCloudLibraryConversions();
  ~PointCloudLibraryConversions();

private:

  PointCloudLibraryConversions(const PointCloudLibraryConversions&); // Not implemented
  void operator=(const PointCloudLibraryConversions&); // Not implemented
};

#endif

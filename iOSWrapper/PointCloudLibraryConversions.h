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

#include "vertex.h"

class PointCloudLibraryConversions
{
public:
    static float* PointCloudDataFromPCDFile(const char* filename);
    static float* PointCloudDataFromPointCloud(pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud);
    static float* PointCloudDataFromPointCloud(pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr cloud);
    static float* PointCloudDataFromPointCloud(pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr cloud);

    static SwiftPointXYZRGBA* PointCloudDataFromPCDFile2(const char* filename);
    static SwiftPointXYZRGBA* PointCloudDataFromPointCloud2(pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud);
    static SwiftPointXYZRGBA* PointCloudDataFromPointCloud2(pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr cloud);
    static SwiftPointXYZRGBA* PointCloudDataFromPointCloud2(pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr cloud);

    // Convert to PointCloud Array
    static pcl::PointCloud<pcl::PointXYZ>::ConstPtr PointCloudDataFromFloatArray1(float* farray);
    static pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr PointCloudDataFromFloatArray2(float* farray);
    static pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr PointCloudDataFromFloatArray3(float* farray);

// use VTK
public:
    // static PointCloudLibraryConversions* New();

protected:
    PointCloudLibraryConversions();
    virtual ~PointCloudLibraryConversions();

private:
    PointCloudLibraryConversions(const PointCloudLibraryConversions&); // Not implemented
    void operator=(const PointCloudLibraryConversions&); // Not implemented
};

#endif // __PointCloudLibraryConversions_h

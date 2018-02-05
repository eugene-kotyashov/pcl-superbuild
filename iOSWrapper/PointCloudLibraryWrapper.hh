#include <string>
#include <iostream>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/PointIndices.h>
#include <pcl/ModelCoefficients.h>

#include <pcl/io/pcd_io.h>
#include <pcl/kdtree/kdtree.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/radius_outlier_removal.h>
#include <pcl/filters/conditional_removal.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/statistical_outlier_removal.h>

class PointCloudLibraryWrapper
{
public:
    PointCloudLibraryWrapper() {std::cout << "PointCloudLibraryWrapper Created." << std::endl;}
    ~PointCloudLibraryWrapper() {std::cout << "PointCloudLibraryWrapper Destroyed." << std::endl;}

    int PrintFoo();
    std::string foo;

    // double[] GetPointData();
    // double[] GetPointData2();

    // io
    void Load(std::string filename);

    // Feature
    // Filter

private:
    // 加工前データ
    pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud;
    // 加工後データ
    pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud_filtered;
};



#include <string>
#include <iostream>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/PointIndices.h>
#include <pcl/ModelCoefficients.h>

// #include <pcl/sample_consensus/method_types.h>
// #include <pcl/sample_consensus/model_types.h>
// #include <pcl/segmentation/sac_segmentation.h>

#include <pcl/filters/voxel_grid.h>

class PointCloudLibraryWrapper
{
public:
    PointCloudLibraryWrapper() {std::cout << "PointCloudLibraryWrapper Created." << std::endl;}
    ~PointCloudLibraryWrapper() {std::cout << "PointCloudLibraryWrapper Destroyed." << std::endl;}

	int PrintFoo();
    std::string foo;
private:
};



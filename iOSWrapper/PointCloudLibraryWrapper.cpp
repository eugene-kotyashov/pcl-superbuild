#include "PointCloudLibraryWrapper.hh"
#include <string>
#include <iostream>

#define EXPORT __attribute__((visibility("default")))

EXPORT
int PointCloudLibraryWrapper::PrintFoo()
{
#if __cplusplus
    std::cout << "C++ environment detected." << std::endl;
#endif
    std::cout << "PointCloudLibraryWrapper::PrintFoo() called." << std::endl;
    return 1;
} 


// io
EXPORT
void PointCloudLibraryWrapper::Load(std::string filename)
{
}

//----------------------------------------------------------------------------
/*
EXPORT
pcl::PointCloud<pcl::PointXYZ>::Ptr ApplyVoxelGrid(pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud, double leafSize[3])
{
    pcl::VoxelGrid<pcl::PointXYZ> voxelGrid;
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloudFiltered(new pcl::PointCloud<pcl::PointXYZ>);
    voxelGrid.setInputCloud(cloud);
    voxelGrid.setLeafSize(leafSize[0], leafSize[1], leafSize[2]);
    voxelGrid.filter(*cloudFiltered);
    return cloudFiltered;
}

//----------------------------------------------------------------------------
EXPORT
int PointCloudLibraryVoxelGrid::RequestData()
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud = PointCloudLibraryConversions::PointCloudFromPolyData(input);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloudFiltered = ApplyVoxelGrid(cloud, this->LeafSize);
    
    output->ShallowCopy(PointCloudLibraryConversions::PolyDataFromPointCloud(cloudFiltered));
    return 1;
}
*/
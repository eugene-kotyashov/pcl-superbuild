// namespace ‚ÌŽg—p‚ÍNG
// #include "PointCloudLibraryWrapper.h"
#include "PointCloudLibraryWrapper.hh"
#include "PointCloudLibraryConversions.h"

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
void PointCloudLibraryWrapper::Load(const char* filename)
{
    // not using namespace to object-c
    // if (pcl::io::loadPCDFile<pcl::PointXYZ> (filename, *cloud) == -1) //* load the file
    // if (loadPCDFile<pcl::PointXYZ> (filename, *cloud) == -1) //* load the file
    // use C++?
    this->pointdata = PointCloudLibraryConversions::PointCloudDataFromPCDFile(filename);
    // not static?
    // PointCloudLibraryConversions* conversion = new PointCloudLibraryConversions();
    // conversion->PointCloudDataFromPCDFile(filename);
}

//----------------------------------------------------------------------------

EXPORT
void PointCloudLibraryWrapper::FilterAxis(const char* axis, double min, double max)
{
    // Create the filtering object
    // pcl::PassThrough<pcl::PointXYZ> pass;
    // pass.setInputCloud (cloud);

    // NSLog(@"arr1 %d : %d", i, intArr[i]);

    // pass.setFilterFieldName ("z");
    // pass.setFilterFieldName ("y");
    // pass.setFilterLimits (min, max);
    // pass.setFilterLimitsNegative (true);
    // pass.filter (*cloud_filtered);
}

/*
EXPORT
PointCloudLibraryWrapper::ApplyVoxelGrid(pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud, double leafSize[3])
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

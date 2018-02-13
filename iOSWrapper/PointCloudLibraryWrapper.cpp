// namespace ‚ÌŽg—p‚ÍNG
// #include "PointCloudLibraryWrapper.h"
#include "PointCloudLibraryWrapper.hh"
#include "PointCloudLibraryConversions.h"
// #include "PointCloudLibraryVoxelGrid.h"
// #include "PointCloudLibrarySACSegmentationPlane.h"

#define EXPORT __attribute__((visibility("default")))

PointCloudLibraryWrapper::PointCloudLibraryWrapper()
{ 
    std::cout << "PointCloudLibraryWrapper Created." << std::endl; 
    PointCloudLibraryConversions::New();
    // PointCloudLibraryVoxelGrid::New();
    // PointCloudLibrarySACSegmentationPlane::New();
}

PointCloudLibraryWrapper::~PointCloudLibraryWrapper()
{
    std::cout << "PointCloudLibraryWrapper Destroyed." << std::endl; 
}

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
    // this->pointdata = PointCloudLibraryConversions::PointCloudDataFromPCDFile(filename);
	this->pointdata = PointCloudLibraryConversions::PointCloudDataFromPCDFile2(filename);
    // not static?
    // PointCloudLibraryConversions* conversion = new PointCloudLibraryConversions();
    // conversion->PointCloudDataFromPCDFile(filename);
}

//----------------------------------------------------------------------------

EXPORT
void PointCloudLibraryWrapper::FilterAxis(const char* axis, double min, double max)
{
    // this->pointdata = PointCloudLibraryVoxelGrid::PointCloudLibraryVoxelGridFromFloatArray(this->pointdata);
}

/*
EXPORT
void PointCloudLibraryWrapper::SegmentationPlane(double leafSize[3])
{
    this->pointdata = PointCloudLibraryVoxelGrid::PointCloudLibrarySACSegmentationPlaneFromFloatArray(this->pointdata);
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

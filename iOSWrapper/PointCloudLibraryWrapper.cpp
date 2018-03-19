// namespace use NG
// #include "PointCloudLibraryWrapper.h"
// #include "PointCloudLibraryWrapper.hh"
#include "PointCloudLibraryWrapper.hpp"
#include "PointCloudLibraryConversions.h"
// #include "PointCloudLibraryVoxelGrid.h"
// #include "PointCloudLibrarySACSegmentationPlane.h"

#define EXPORT __attribute__((visibility("default")))

struct SwiftPointXYZ fcpp(const float ** triangle) {
    SwiftPointXYZ curl;
    curl.z = (triangle[1][0] - triangle[0][0]) * (triangle[2][1]-triangle[0][1]) - (triangle[1][1] - triangle[0][1])*(triangle[2][0]-triangle[0][0]);
    curl.y = (triangle[1][2] - triangle[0][2]) * (triangle[2][1]-triangle[0][1]) - (triangle[1][0] - triangle[0][0])*(triangle[2][2]-triangle[0][0]);
    curl.x = (triangle[1][1] - triangle[0][1]) * (triangle[2][2]-triangle[0][2]) - (triangle[1][2] - triangle[0][2])*(triangle[2][1]-triangle[0][1]);

    return curl;
}

extern "C" struct SwiftPointXYZ fc(const float ** p) 
{
    return fcpp(p);
};

struct SwiftPointXYZ fcpp2(float triangle[3][3]) {

    SwiftPointXYZ curl;

    curl.z = (triangle[1][0] - triangle[0][0])*(triangle[2][1]-triangle[0][1]) - (triangle[1][1] - triangle[0][1])*(triangle[2][0]-triangle[0][0]);
    curl.y = (triangle[1][2] - triangle[0][2])*(triangle[2][1]-triangle[0][1]) - (triangle[1][0] - triangle[0][0])*(triangle[2][2]-triangle[0][0]);
    curl.x = (triangle[1][1] - triangle[0][1])*(triangle[2][2]-triangle[0][2]) - (triangle[1][2] - triangle[0][2])*(triangle[2][1]-triangle[0][1]);

    return curl;
};

extern "C" struct SwiftPointXYZ fc2(float t[3][3]) {
    return fcpp2(t);
};

PointCloudLibraryWrapper::PointCloudLibraryWrapper()
{ 
    std::cout << "PointCloudLibraryWrapper Created." << std::endl; 
    // PointCloudLibraryConversions::New();
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

EXPORT
struct SwiftPointXYZRGBA* PointCloudLibraryWrapper::GetPointCloudData()
{
    return this->pointdata;
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

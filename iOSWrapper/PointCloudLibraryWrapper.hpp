#ifndef __PointCloudWrapper_hpp
#define __PointCloudWrapper_hpp

#include <string>
#include <iostream>

#include "vertex.h"

// gcc5?
// https://stackoverflow.com/questions/33394934/converting-std-cxx11string-to-stdstring
// #define _GLIBCXX_USE_CXX11_ABI 0

struct SwiftPointXYZ fcpp(const float **);
// #ifdef __cplusplus
// extern "C" {
// #endif
//     struct SwiftPointXYZ fc(const float ** p);
// #ifdef __cplusplus
// }
// #endif

struct SwiftPointXYZ fcpp2(float t[3][3]);
// extern "C" 
// #ifdef __cplusplus
// extern "C" {
// #endif
//     struct SwiftPointXYZ fc2(float t[3][3]);
// #ifdef __cplusplus
// }
// #endif

// parameter is pointer to array of array 3 of const float
// NG : 
// cannot convert argument of incomplete type 'const float [][3]' to 'float (*)[3]' for 1st argument
// struct SwiftPointXYZ fcpp3(const float (* const t)[][3]) {
//     return fcpp2(*t);
// }

// Swift direct namespace source code NG.
class PointCloudLibraryWrapper
{
public:
    PointCloudLibraryWrapper();
    ~PointCloudLibraryWrapper();

    int PrintFoo();
    std::string foo;

    // io
    void Load(const char* filename);

    // Feature
    // Filter
    void FilterAxis(const char* axis, double min, double max);

    // Segmentation
    // float* GetPointCloudData() 
    // { 
    //     return this->pointdata;
    // }
    struct SwiftPointXYZRGBA* GetPointCloudData();

    int GetPointCloudCount();
    int GetPointCloudType() { return this->pointtype; }

    void SetPointCloudData(struct SwiftPointXYZRGBA* data);
    void SetPointCloudCount(int count);
    // void SetPointCloudType(int pointtype);

private:
    // pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud;
    // pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud_filtered;
    // PointCloudLibraryConversions* conversion;

    // float** pointdata;
    SwiftPointXYZRGBA* pointdata;
    int pointcount;
    int pointtype;
};

#endif // __PointCloudWrapper_hpp


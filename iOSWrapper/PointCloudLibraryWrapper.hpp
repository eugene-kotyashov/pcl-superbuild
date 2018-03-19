#ifndef __PointCloudWrapper_hh
#define __PointCloudWrapper_hh

#include <string>
#include <iostream>

#include "vertex.h"

// gcc5?
// https://stackoverflow.com/questions/33394934/converting-std-cxx11string-to-stdstring
#define _GLIBCXX_USE_CXX11_ABI 0

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

// ���̃t�@�C����(cpp�܂�)�ł� namespace �̎g�p��NG
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
    // struct SwiftPointXYZRGBA* GetPointCloudData() 
    // {
    //     // float** ����� Convert �őΉ�����H
    //     return this->pointdata;
    // }

    // struct SwiftPointXYZ* GetPointCloudData()
    // {
    //     // float** ����� Convert �őΉ�����H
    //     return this->pointdata;
    // }

    int GetPointCloudCount() { return this->pointcount; }
    int GetPointCloudType() { return this->pointtype; }
private:
    // ���H�O�f�[�^
    // pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud;
    // ���H��f�[�^
    // pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud_filtered;
    // PointCloudLibraryConversions* conversion;
    // float** pointdata;
    SwiftPointXYZRGBA* pointdata;
    int pointcount;
    int pointtype;
};

#endif // __PointCloudWrapper_hh


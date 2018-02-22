#ifndef __PointCloudWrapper_hh
#define __PointCloudWrapper_hh

#include <string>
#include <iostream>

// #include "vertex.h"

// Swift/Object-C と点群データをやり取りする際の構造体を定義する
struct SwiftPointXYZRGBA{
    float x;
    float y;
    float z;
    float r;
    float g;
    float b;
    float a;
};
typedef struct SwiftPointXYZRGBA SwiftPointXYZRGBA;

struct SwiftPointXYZ {
    float x;
    float y;
    float z;
};

struct SwiftPointXYZ fcpp(const float **);

extern "C" struct SwiftPointXYZ fc(const float ** p) {
    return fcpp(p);
};

struct SwiftPointXYZ fcpp2(float t[3][3]);
extern "C" struct SwiftPointXYZ fc2(float t[3][3]) {
    return fcpp2(t);
};

// このファイル内(cpp含む)での namespace の使用はNG
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
    struct SwiftPointXYZRGBA* GetPointCloudData() 
    {
        // float** からの Convert で対応する？
        return this->pointdata;
    }

    // struct SwiftPointXYZ* GetPointCloudData()
    // {
    //     // float** からの Convert で対応する？
    //     return this->pointdata;
    // }

    int GetPointCloudCount() { return this->pointcount; }
    int GetPointCloudType() { return this->pointtype; }
private:
    // 加工前データ
    // pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud;
    // 加工後データ
    // pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud_filtered;
    // PointCloudLibraryConversions* conversion;
    // float** pointdata;
    SwiftPointXYZRGBA* pointdata;
    int pointcount;
    int pointtype;
};

#endif // __PointCloudWrapper_hh


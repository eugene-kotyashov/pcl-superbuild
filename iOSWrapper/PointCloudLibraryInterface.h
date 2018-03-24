// Objective-C++ objective-c class to interface with C++ Library
#import <Foundation/Foundation.h>

// set Bridge Header?
struct float3 {
    float x;
    float y;
    float z;
};

struct float3 fc(const float **);
struct float3 fc2(float [][3]);

struct float7 {
    float x;
    float y;
    float z;
    float r;
    float g;
    float b;
    float a;
};

// 
// These one headers god to mm file
// #include <pcl/PointCloudLibraryWrapper.hpp>

@interface PointCloudLibraryInterface : NSObject

@property (nonatomic, copy) NSArray *pointArray;

- (void)callLoad:(NSString *)argString;
- (void)callLoadResourceFile;
- (void)callFiltering;
// - (void)setPointCloudData:(NSArray<NSValue *>)pointArray;
// - (NSArray<NSValue *>)GetPointCloudData;
// ARKit? <- PointCloud?
// + (ARPointCloud *) applyPointCloudLibraryTo: (ARPointCloud*) uiPoints;
// + (vector_float3 *) applyPointCloudLibraryTo: (vector_float3*) uiPoints;
// these methods have to be in mm file, hence private
// + (pcl::PointCloud*)pclPointCloudFromARPointCloud:(ARPointCloud *)uiPoints;
- (struct float7*)GetPointCloudData;
- (int)GetPointCloudDataCount;

@end

#import "PointCloudLibraryInterface.h"
#import <UIKit/UIKit.h>

// Framework headers
#include <pcl/PointCloudLibraryWrapper.hpp>

// namespace use ng
// use wrapper class private
/*
// XYZ
@interface NSValue (PointXYZ)
+ (NSValue*)valueWithCGPoint:(PointXYZ)point;
- (PointXYZ)cgpointValue;
@end

@implementation NSValue (PointXYZ)
+ (NSValue*)valueWithCGPoint:(PointXYZ)point
{
  return [NSValue value:&point withObjCType:@encode(PointXYZ)];
}
// XYZRGB
@interface NSValue (PointXYZRGB)
+ (NSValue*)valueWithCGPoint:(PointXYZRGB)point;
- (PointXYZRGB)cgpointValue;
@end
@implementation NSValue (PointXYZRGB)
+ (NSValue*)valueWithCGPoint:(PointXYZRGB)point
{
  return [NSValue value:&point withObjCType:@encode(PointXYZRGB)];
}
// XYZRGBA
@interface NSValue (PointXYZRGBA)
+ (NSValue*)valueWithCGPoint:(PointXYZRGBA)point;
- (PointXYZRGBA)cgpointValue;
@end
@implementation NSValue (PointXYZRGBA)
+ (NSValue*)valueWithCGPoint:(PointXYZRGBA)point
{
  return [NSValue value:&point withObjCType:@encode(PointXYZRGBA)];
}
@end
// PointXYZ point = { 0.0f, 1.0f, 0.0f };
// // NSValue ��
// NSValue val = [NSValue valueWithCGPoint:point];
// // PointXYZ ��
// point = [val cgpointValue];
// // NSArray �ɒǉ�
// NSArrray *array = [NSArray arrayWithObects:[NSValue valueWithCGPoint:point], nil];
*/


// @interface PointCloudLibraryInterface ()
//     PointCloudLibraryWrapper* myPointCloudLibraryWrapper;
// @end
// + (std::vector<dlib::rectangle>)convertCGRectValueArray:(NSArray<NSValue *> *)rects;
@interface PointCloudLibraryInterface ()

@property (assign) BOOL isLoad;

@end

@implementation PointCloudLibraryInterface {
    PointCloudLibraryWrapper* myPointCloudLibraryWrapper;
}

-(id)init {
    self = [super init];

    if (self != nil) 
    {
        myPointCloudLibraryWrapper = new PointCloudLibraryWrapper();
        myPointCloudLibraryWrapper->PrintFoo();
        self.isLoad = NO;
    }

    return self;
}
- (void) dealloc {
    if(myPointCloudLibraryWrapper != NULL) delete myPointCloudLibraryWrapper;
    [super dealloc];
}

// custom
- (void) callLoad : (NSString *)argString {
    std::string strDst = [argString UTF8String];
    myPointCloudLibraryWrapper->Load(strDst);

    // TestCode
    // Load Resource Files
    // NSString *modelFileName = [[NSBundle mainBundle] pathForResource:@"pointcloud" ofType:@"pcd"]; 
    // std::string modelFileNameCString = [modelFileName UTF8String]; 
    // myPointCloudLibraryWrapper->Load(strDst);

    self.isLoad = YES; 
}

- (void) callLoadResourceFile {
    NSString *modelFileName = [[NSBundle mainBundle] pathForResource:@"pointcloud" ofType:@"pcd"]; 
    std::string modelFileNameCString = [modelFileName UTF8String]; 
    myPointCloudLibraryWrapper->Load(strDst);

    self.isLoad = YES; 
}

- (void) callFiltering {
    if (!self.isLoad)
    {
        // NSLog()
        return;
    }

    // myPointCloudLibraryWrapper.min = 1.0;
    // myPointCloudLibraryWrapper.max = 5.0;
    myPointCloudLibraryWrapper->FilterAxis("x", 1.0, 5.0);
}

- (struct float7*)GetPointCloudData {
    if (!self.isLoad)
    {
        // NSLog()
        return;
    }

    SwiftPointXYZRGBA* data = myPointCloudLibraryWrapper->GetPointCloudData();
    return data;
}

// - (NSArray<NSValue *>)GetPointCloudData {
//     if (!self.isLoad)
//     {
//         // NSLog()
//         return;
//     }
// 
//     // Get Float*
//     SwiftPointXYZRGBA* data = myPointCloudLibraryWrapper->GetPointCloudData();
//     int count = myPointCloudLibraryWrapper->GetPointCloudCount();
//     int type = myPointCloudLibraryWrapper->GetPointCloudType();
// 
//     for(int i = 0;i < count;i++)
//     {
//         // point to use cpp_code
//         // 3DPoint point = {0.0f, 1.0f, 1.0f};
//         // NSValue *val = [NSValue value:&point withObjCType:@encode(Vertex)];
//         // [val getValue:&point];
//         // 3DPoint point = {0.0f, 1.0f, 1.0f};
//         // NSValue *val = [NSValue value:&point withObjCType:@encode(Vertex)];
//         // [val getValue:&point];
//     }
// 
//     return data;
// }

// use Array Sample
// -(NSArray*)getList {
//    NSMutableArray *tmpArray = [NSMutableArray arrayWithCapacity:(obj.vct).size()];
//    for (int i=0;i<(obj.vct).size();i++) {
//        [tmpArray addObject:[NSNumber numberSithInt:obj.vct[i]]];
//    }
//    return [NSArray arrayWithArray:tmpArray];
// }

// ARKit Code?
// https://stackoverflow.com/questions/46292620/opencv-error-core-hpp-header-must-be-compiled-as-c/46294263#46294263
// implementation of public methods:
// + (ARPointCloud *) applyPointCloudLibraryTo: (ARPointCloud*) uiPoints{
//     pcl::PointCloud<pcl::PointXYZ>::Ptr pclFrame = [PointCloudLibraryInterface pclPointCloudFromARPointCloud: uiPoints];
//     // do something with cvFrame using OpenCV
//     pcl::PointCloud<pcl::PointXYZ>::Ptr ret = pclFrame.clone();
// 
//     return [PointCloudLibraryInterface ARPointCloudFromPointCloudXYZ: ret];
// }
// 
// // Implementations of the conversion functions:
// + (ARPointCloud *)ARPointCloudFromPointCloudXYZ:(pcl::PointCloud<pcl::PointXYZ>::Ptr) pclPointCloud {
//     // do something here
//     return uiPoints;
// }
// 
// + (pcl::PointCloud<pcl::PointXYZ>::Ptr)pclPointCloudFromARPointCloud:(ARPointCloud *)uiPoints;

@end

#import "PointCloudLibraryInterface.h"
#import <UIKit/UIKit.h>

// Framework headers
#include <pcl/PointCloudLibraryWrapper.hh>

// namespace 定義があるため直接は×
// 代わりの定義ヘッダを用意する?
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
// // NSValue 化
// NSValue val = [NSValue valueWithCGPoint:point];
// // PointXYZ 化
// point = [val cgpointValue];
// // NSArray に追加
// NSArrray *array = [NSArray arrayWithObects:[NSValue valueWithCGPoint:point], nil];
*/


// @interface PointCloudLibraryInterface ()
//     PointCloudLibraryWrapper* myPointCloudLibraryWrapper;
// @end
// + (std::vector<dlib::rectangle>)convertCGRectValueArray:(NSArray<NSValue *> *)rects;
@interface PointCloudLibraryInterface ()

@property (assign) BOOL isLoad;

@end

@implementation PointCloudLibraryInterface{
    PointCloudLibraryWrapper* myPointCloudLibraryWrapper;
}

-(id)init {
    self = [super init];
    if (self != nil) 
    {
        myPointCloudLibraryWrapper = new PointCloudLibraryWrapper();
        myPointCloudLibraryWrapper->PrintFoo();
        self.isLoad = NO
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

- (NSArray<NSValue *>)GetPointCloudData {
    if (!self.isLoad)
    {
        // NSLog()
        return;
    }

    // Get Float*
    float* data = myPointCloudLibraryWrapper->GetPointCloudData();
    int count = myPointCloudLibraryWrapper->GetPointCloudCount();
    int type = myPointCloudLibraryWrapper->GetPointCloudType();

    for(int i = 0;i < count;i++)
    {
        // データを加工する
        // 3DPoint point = {0.0f, 1.0f, 1.0f};
        // NSValue *val = [NSValue value:&point withObjCType:@encode(3DPoint)];
        // [val getValue:&point];
    }

    return nullptr;
}
@end

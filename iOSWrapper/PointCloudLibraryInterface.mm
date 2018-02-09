#import "PointCloudLibraryInterface.h"
#import <UIKit/UIKit.h>

// Framework headers
#include <pcl/PointCloudLibraryWrapper.hh>

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
@end

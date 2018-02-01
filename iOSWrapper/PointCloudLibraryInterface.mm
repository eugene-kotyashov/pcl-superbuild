#import "CppInterface.h"
#include <pcl/PointCloudLibraryWrapper.hh>

@interface PointCloudLibraryInterface () 
{
    PointCloudLibraryWrapper* myPointCloudLibraryWrapper;
}
@end

@implementation CppInterface

-(instancetype)init
{
    self = [super init];
    if (self) {
        myPointCloudLibraryWrapper = new PointCloudLibraryWrapper();
        myPointCloudLibraryWrapper->PrintFoo();
        delete myPointCloudLibraryWrapper;
        myPointCloudLibraryWrapper = nullptr;
    }
    return self;
}

@end

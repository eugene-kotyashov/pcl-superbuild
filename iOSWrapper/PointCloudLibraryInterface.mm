#include "PointCloudLibraryInterface.h"
#include <pcl/PointCloudLibraryWrapper.hh>

@interface PointCloudLibraryInterface () 
{
    PointCloudLibraryWrapper* myPointCloudLibraryWrapper;
}
@end

@implementation PointCloudLibraryInterface

-(id)init {
    self = [super init];
    if (self != nil) 
    {
        myPointCloudLibraryWrapper = new PointCloudLibraryWrapper();
        myPointCloudLibraryWrapper->PrintFoo();
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
}
- (void) callFiltering {
    // myPointCloudLibraryWrapper.min = 1.0;
    // myPointCloudLibraryWrapper.max = 5.0;
    myPointCloudLibraryWrapper->FilterAxis("x", 1.0, 5.0);
}
@end

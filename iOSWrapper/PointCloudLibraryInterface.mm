#import "PointCloudLibraryInterface.h"
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
- (void) callLoad : (NSString *)argString {
    std::string strDst = [argString UTF8String];
    myPointCloudLibraryWrapper->Load(strDst);
}
- (void) callFiltering {
    // myPointCloudLibraryWrapper.min = 5;
    // myPointCloudLibraryWrapper.max = 5;
    myPointCloudLibraryWrapper->FilterAxis();
}
@end

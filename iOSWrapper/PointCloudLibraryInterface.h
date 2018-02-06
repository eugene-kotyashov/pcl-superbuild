// Objective-C++ objective-c class to interface with C++ Library
#import <Foundation/Foundation.h>

@interface PointCloudLibraryInterface : NSObject

@property (nonatomic, copy) NSArray *pointArray;

- (void)callLoad:(NSString *)argString;
- (void)callFiltering;
// - (void)setPointCloudData:(NSArray *)pointArray;
@end

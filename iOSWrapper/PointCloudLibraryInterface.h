// Objective-C++ objective-c class to interface with C++ Library
#import <Foundation/Foundation.h>

typedef struct {
    float x;
    float y;
    float z;
    float r;
    float g;
    float b;
    float a;
} Vertex;

@interface PointCloudLibraryInterface : NSObject

@property (nonatomic, copy) NSArray *pointArray;

- (void)callLoad:(NSString *)argString;
- (void)callFiltering;
// - (void)setPointCloudData:(NSArray<NSValue *>)pointArray;
- (NSArray<NSValue *>)GetPointCloudData;
@end

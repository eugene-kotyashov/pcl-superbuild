#import <XCTest/XCTest.h>

#import "../PointCloudLibraryInterface.h"

@interface Tests : XCTestCase
@end

@implementation Tests

- (void)setUp {
    [super setUp];
}

- (void)tearDown {
    [super tearDown];
}

- (void)testExample {
    PointCloudLibraryInterface* i = [[PointCloudLibraryInterface alloc] init];
    XCTAssert(i);
}

- (void)testLoadFile {
    PointCloudLibraryInterface* i = [[PointCloudLibraryInterface alloc] init];
    XCTAssert(i);

    // i.callLoadResourceFile;
    [i callLoadResourceFile];
}

- (void)testFilterAxis {
    PointCloudLibraryInterface* i = [[PointCloudLibraryInterface alloc] init];
    XCTAssert(i);

    // i.callFiltering;
    [i callFiltering];
}

- (void)GetPointCloudData {
    PointCloudLibraryInterface* i = [[PointCloudLibraryInterface alloc] init];
    XCTAssert(i);

    struct float7* param;
    param = i.GetPointCloudData;

}
@end

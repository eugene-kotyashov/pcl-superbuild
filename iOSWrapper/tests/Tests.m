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

@end

import XCTest

@testable import libPointCloudLibrary

class Tests: XCTestCase {

    var callApiExpectation: XCTestExpectation? = nil

    override func setUp() {
        super.setUp()
        // Put setup code here. This method is called before the invocation of each test method in the class.
    }

    override func tearDown() {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
        super.tearDown()
    }

    func testExample() {
        // This is an example of a functional test case.
        // Use XCTAssert and related functions to verify your tests produce the correct results.
        libPointCloudLibrary.Load("pointcloud.pcd");
        let i = libPointCloudLibrary.GetPointCloudData();
        XCTAssert(i);
    }

    func testPerformanceExample() {
        // This is an example of a performance test case.
        self.measure {
            // Put the code you want to measure the time of here.
        }
    }

    // MARK: - Reurn value

    /*!
     * 結果を戻り値で返す。
     */
    func testReturnVelue() {
        let manager = libPointCloudLibrary()
        let pointData = manager.GetPointCloudData()

        // 戻り値を確認する場合は、素直に比較する。
        XCTAssertNotNil(pointData)

        XCTAssertEqual(pointData.x, "TEST1234")
        XCTAssertEqual(pointData.y, "CAD34831-E763-45A9-8BA2-31991DCB682B")
        XCTAssertEqual(pointData.z, 1)

        XCTAssertNotNil(pointData.latestAccessDate)
    }
}


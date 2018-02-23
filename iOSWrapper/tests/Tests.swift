import XCTest

@testable import sample

class sampleTests: XCTestCase, NetworkManagerDelegate {

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
        let manager = NetworkManager()
        let userData = manager.userData()

        // 戻り値を確認する場合は、素直に比較する。
        XCTAssertNotNil(userData)

        XCTAssertEqual(userData.username, "TEST1234")
        XCTAssertEqual(userData.uuid, "CAD34831-E763-45A9-8BA2-31991DCB682B")
        XCTAssertEqual(userData.rank, 1)

        XCTAssertNotNil(userData.latestAccessDate)
    }

    // MARK: - Asynchronous(Delegate)

    /*!
     * 結果を Delegate で返す。
     */
    func testCallApiDelegate() {
        // 非同期処理の完了を監視するオブジェクトを作成
        // 別メソッドになるためメンバ変数を用意
        self.callApiExpectation = self.expectation(description: "CallApiDelegate")

        let manager = NetworkManager()
        manager.delegate = self
        manager.callApi(command: .Update, parameters: nil, completionHandler: nil)

        // 指定秒数待つ
        self.waitForExpectations(timeout: 10, handler: nil)
    }

    func callBackApi(result: [NetworkManager.ApiResutKeys : Any]) {
        // 非同期処理の監視を終了
        self.callApiExpectation?.fulfill()
        // 結果を確認
        XCTAssertNotNil(result)
    }

    // MARK: - Asynchronous(Blocks)

    /*!
     * 非同期処理で結果を Blocks で返す。
     */
    func testImageDownlaodBlocks() {
        // 非同期処理の完了を監視するオブジェクトを作成
        let expectation = self.expectation(description: "CallApiBlocks")

        let manager = NetworkManager()
        manager.delegate = self
        manager.callApi(command: .Update, parameters: nil) { (result, apiResult, error) in
            // 非同期処理の監視を終了
            expectation.fulfill()
            // 結果を確認
            XCTAssertTrue(result)
        }

        // 指定秒数待つ
        self.waitForExpectations(timeout: 10, handler: nil)
    }

    // MARK: - Asynchronous(Notification)

    /*!
     * 結果を Notification で返す。
     */
    func testCallApiNotification() {
        // 通知を監視する
        self.expectation(forNotification: NetworkManager.ApiCallbackNotification.rawValue, object: nil) { (notification) -> Bool in
            // 結果を確認
            XCTAssertNotNil(notification.object)
            let apiResult = notification.object as! [NetworkManager.ApiResutKeys: AnyObject]
            XCTAssertTrue(apiResult[.Status] as! Bool)
            XCTAssertNil(apiResult[.Error])

            // 通知の監視を終了
            return true
        }

        let manager = NetworkManager()
        manager.callApi(command: .Update, parameters: nil, completionHandler: nil)

        // 指定秒数待つ
        self.waitForExpectations(timeout: 10, handler: nil)
    }
}


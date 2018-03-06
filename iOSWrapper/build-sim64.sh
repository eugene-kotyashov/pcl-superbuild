cmake -DCMAKE_TOOLCHAIN_FILE=../toolchains/Toolchain-iPhoneSimulator_Xcode.cmake -DIOS_PLATFORM=SIMULATOR64 -H. -Bbuild.sim64 -GXcode
cmake --build build.sim64/ --config Release

cmake -DCMAKE_TOOLCHAIN_FILE=../toolchains/Toolchain-iPhoneSimulator_Xcode.cmake -DIOS_PLATFORM=SIMULATOR -H. -Bbuild.sim -GXcode
cmake --build build.sim/ --config Release

cmake -DCMAKE_TOOLCHAIN_FILE=../toolchains/iOS_xcode.cmake -DIOS_PLATFORM=SIMULATOR64 -DIOS_TESTS=1 -H. -Bbuild.test -GXcode
cmake --build build.test/ --config Release

cmake -DCMAKE_TOOLCHAIN_FILE=../toolchains/iOS_xcode.cmake -DIOS_PLATFORM=SIMULATOR64 -H. -Bbuild.test -GXcode
cmake --build build.test/ --config Release

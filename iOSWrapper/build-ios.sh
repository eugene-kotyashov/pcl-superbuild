cmake -DCMAKE_TOOLCHAIN_FILE=../toolchains/iOS_xcode.cmake -DIOS_PLATFORM=OS -H. -Bbuild.ios -GXcode
cmake --build build.ios/ --config Release

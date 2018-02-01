cmake -DCMAKE_TOOLCHAIN_FILE=../toolchains/ios.cmake -DIOS_PLATFORM=OS -H. -Bbuild.ios -GXcode
cmake --build build.ios/ --config Release

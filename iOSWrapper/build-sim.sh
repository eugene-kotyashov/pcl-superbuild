cmake -DCMAKE_TOOLCHAIN_FILE=../toolchains/ios.cmake -DIOS_PLATFORM=SIMULATOR -H. -Bbuild.sim -GXcode
cmake --build build.sim/ --config Release

#!/bin/bash

set -x

appDir=$(pwd)
superbuildDir=$(cd $(pwd)/../../../ && echo $(pwd))
buildDir=${appDir}/build
target=device

mkdir -p ${buildDir}
cd ${buildDir}

cmake \
-G Xcode \
-DSUPERBUILD_DIR=${superbuildDir}/build \
-DPCL_DIR=${superbuildDir}/CMakeExternals/Install/pcl-ios-device \
-DBOOST_DIR=${superbuildDir}/CMakeExternals/Install/boost-ios-device \
-DEIGEN_INCLUDE_DIRS:PATH=${superbuildDir}/CMakeExternals/Install/eigen \
-DBOOST_INCLUDE_DIRS:PATH=${superbuildDir}/CMakeExternals/boost-ios-device/include \
-DPCL_INCLUDE_DIRS:PATH=${superbuildDir}/CMakeExternals/pcl-ios-device/include \
-DVTK_DIR:PATH=${superbuildDir}/VTK/build/CMakeExternals/vtk-ios-device-armv7 \
# -DVTK_INCLUDE_DIRS:PATH=${superbuildDir}/VTK/build/CMakeExternals/Build/vtk-ios-device-armv7/include/vtk-7.0' \
# -DVTK_LIBRARY:PATH=${superbuildDir}/VTK/build/CMakeExternals/Build/vtk-ios-device-armv7/lib \
${appDir}


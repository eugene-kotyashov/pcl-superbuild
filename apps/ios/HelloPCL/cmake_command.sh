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
-DSUPERBUILD_DIR=${superbuildDir} \
-DVES_DIR=${superbuildDir}/build/CMakeExternals/Install/ves-ios-device \
-DVTK_DIR=${superbuildDir}/build/CMakeExternals/Install/vtk-ios-device \
-DPCL_DIR=${superbuildDir}/build/CMakeExternals/Install/pcl-ios-device/pcl-1.7 \
-DEIGEN_INCLUDE_DIRS:PATH=${superbuildDir}/build/CMakeExternals/Install/eigen  \
${appDir}


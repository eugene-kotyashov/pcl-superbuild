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
-DVES_DIR=${superbuildDir}/VES/build/CMakeExternals/ves-ios-device \
-DVTK_DIR=${superbuildDir}/build/CMakeExternals/Install/vtk-ios-device \
-DPCL_DIR=${superbuildDir}/build/CMakeExternals/Install/pcl-ios-device \
-DEIGEN_INCLUDE_DIRS:PATH=${superbuildDir}/build/CMakeExternals/Install/eigen  \
${appDir}


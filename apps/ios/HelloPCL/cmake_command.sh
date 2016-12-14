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
-DVES_DIR=${superbuildDir}/CMakeExternals/Install/ves-ios-device \
-DVTK_DIR=${superbuildDir}/CMakeExternals/Install/vtk-ios-device \
-DPCL_DIR=${superbuildDir}/CMakeExternals/Install/pcl-ios-device \
-DBOOST_DIR=${superbuildDir}/CMakeExternals/Install/boost-ios-device \
-DEIGEN_INCLUDE_DIRS:PATH=${superbuildDir}/CMakeExternals/Install/eigen \
${appDir}


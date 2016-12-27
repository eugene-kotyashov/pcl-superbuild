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
${appDir}


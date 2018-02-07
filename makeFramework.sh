#!/bin/bash

#------------------------------------------------------------------------------
install=./CMakeExternals/Install
if [ ! -d $install ]; then
  echo "Install directory not found.  This script should be run from the top level build directory that contains CMakeExternals/Install."
  exit 1
fi

#------------------------------------------------------------------------------
make_pcl_framework ()
{
  # device_folder = "ios-device"
  # simulator_folder = "ios-simulator"

  # pcl_device_libs=`find $install/pcl-${device_folder} $install/flann-${device_folder} $install/boost-${device_folder} -name *.a`
  pcl_device_libs=`find $install/pcl-ios-device -name *.a`
  boost_device_libs=`find $install/boost-ios-device -name *.a`
  flann_device_libs=`find $install/flann-ios-device -name *.a`
  # pcl_sim_libs=`find $install/pcl-${simulator_folder} $install/flann-${simulator_folder} $install/boost-${simulator_folder} -name *.a`
  pcl_sim_libs=`find $install/pcl-ios-simulator -name *.a`
  boost_sim_libs=`find $install/boost-ios-simulator -name *.a`
  flann_sim_libs=`find $install/flann-ios-simulator -name *.a`

  # args -> version
  # version 1.7
  # pcl_header_dir=$install/pcl-${device_folder}/include/pcl-1.7
  # version 1.8
  pcl_header_dir=$install/pcl-ios-device/include/pcl-1.8
  boost_header_dir=$install/boost-ios-device/include
  eigen_header_dir=$install/eigen
  flann_header_dir=$install/flann-ios-device/include
  qhull_header_dir=$install/qhull-ios-device/include

  pcl_framework=$install/frameworks/pcl.framework
  mkdir -p $pcl_framework
  rm -rf $pcl_framework/*

  # Public Header
  mkdir $pcl_framework/Headers
  cp -R $pcl_header_dir/* $pcl_framework/Headers/
  cp -R $boost_header_dir/* $pcl_framework/Headers/
  cp -R $eigen_header_dir/* $pcl_framework/Headers/
  cp -R $flann_header_dir/* $pcl_framework/Headers/

  # mkdir $pcl_framework/Modules
  # cp module.modulemap $pcl_framework/Modules/

  libtool -static -o $pcl_framework/pcl_device $pcl_device_libs $boost_device_libs $flann_device_libs
  libtool -static -o $pcl_framework/pcl_sim $pcl_sim_libs $boost_sim_libs $flann_sim_libs

  # 
  # lipo -create $pcl_framework/pcl_device -output $pcl_framework/pcl
  # lipo -create $pcl_framework/pcl_sim -output $pcl_framework/pcl
  lipo -create $pcl_framework/pcl_device $pcl_framework/pcl_sim -output $pcl_framework/pcl

  rm $pcl_framework/pcl_*
}


#------------------------------------------------------------------------------
make_pcl_framework_device ()
{
  # すでに存在する device 用の pcl.Framework に対して外部ライブラリを取り込む
  current_pcl_ios_device_framework=../iOSWrapper/build.ios/Release-iphoneos/pcl.framework

  # Step 1. Build Device and Simulator versions complete
  pcl_device_libs=`find $install/pcl-ios-device -name *.a`
  boost_device_libs=`find $install/boost-ios-device -name *.a`
  flann_device_libs=`find $install/flann-ios-device -name *.a`
  qhull_device_libs=`find $install/qhull-ios-device -name *.a`
  # Object-C/Swift で使用するためのラッパー関数を持つライブラリ
  # wrapper_device_libs=`find $install/ios_device_wrapper -name *.a`

  # args -> version
  # version 1.8
  pcl_header_dir=$install/pcl-ios-device/include/pcl-1.8
  boost_header_dir=$install/boost-ios-device/include
  eigen_header_dir=$install/eigen
  flann_header_dir=$install/flann-ios-device/include
  qhull_header_dir=$install/qhull-ios-device/include
  # ioswrapper_header_dir=$install/ios_device_wrapper/include

  # Step 2. Copy the framework structure (from iphoneos build) to the device folder
  pcl_framework=$install/frameworks-device/pcl.framework
  mkdir -p ${pcl_framework}
  rm -rf $pcl_framework/*

  cp -R "${current_pcl_ios_device_framework}" "${pcl_framework}/.."

  # mkdir $pcl_framework/Headers
  cp -R $pcl_header_dir/* $pcl_framework/Headers/ 2>&1
  cp -R $boost_header_dir/* $pcl_framework/Headers/ 2>&1
  cp -R $eigen_header_dir/* $pcl_framework/Headers/ 2>&1
  cp -R $flann_header_dir/* $pcl_framework/Headers/ 2>&1
  cp -R $qhull_header_dir/* $pcl_framework/Headers/ 2>&1
  # cp -R $ioswrapper_header_dir/* $pcl_framework/Headers/

  # mkdir $pcl_framework/Modules
  # cp module.modulemap $pcl_framework/Modules/

  # ライブラリの結合
  libtool -static -o $pcl_framework/pcl_device $pcl_device_libs $boost_device_libs $flann_device_libs $qhull_device_libs $current_pcl_ios_device_framework/pcl

  # Xcode で生成した framework と 個別にビルドした外部ライブラリを合わせる
  lipo -create -output $pcl_framework/pcl $pcl_framework/pcl_device

  rm -rf $pcl_framework/pcl_*
}

make_pcl_framework_simulator ()
{
  # すでに存在する simulation 用の pcl.Framework に対して外部ライブラリを取り込む
  current_pcl_ios_sim_framework=../iOSWrapper/build/Release-iphonesimulator/pcl.framework

  pcl_sim_libs=`find $install/pcl-ios-simulator -name *.a`
  boost_sim_libs=`find $install/boost-ios-simulator -name *.a`
  flann_sim_libs=`find $install/flann-ios-simulator -name *.a`
  qhull_sim_libs=`find $install/qhull-ios-simulator -name *.a`
  # ioswrapper_sim_libs=$install/ioswrapper-ios-simulator -name *.a`
  # Object-C/Swift で使用するためのラッパー関数を持つライブラリ
  # wrapper_sim_libs=`find $install/ios_simulator_wrapper -name *.a`

  # args -> version
  # version 1.8
  pcl_header_dir=$install/pcl-ios-simulator/include/pcl-1.8
  boost_header_dir=$install/boost-ios-simulator/include
  eigen_header_dir=$install/eigen
  flann_header_dir=$install/flann-ios-simulator/include
  qhull_header_dir=$install/qhull-ios-simulator/include
  # ioswrapper_header_dir=$install/ioswrapper-ios-simulator/include

  # Step 3. Copy the framework structure (from iphoneos-simulator build) to the device folder
  pcl_framework=$install/frameworks-simulator/pcl.framework
  mkdir -p ${pcl_framework}
  rm -rf $pcl_framework/*

  cp -R "${current_pcl_ios_sim_framework}" "${pcl_framework}/.."

  # Public Header
  # mkdir $pcl_framework/Headers
  cp -R $pcl_header_dir/* $pcl_framework/Headers/
  cp -R $boost_header_dir/* $pcl_framework/Headers/
  cp -R $eigen_header_dir/* $pcl_framework/Headers/
  cp -R $flann_header_dir/* $pcl_framework/Headers/
  cp -R $qhull_header_dir/* $pcl_framework/Headers/
  cp -R $ioswrapper_header_dir/* $pcl_framework/Headers/

  # mkdir $pcl_framework/Modules
  # cp module.modulemap $pcl_framework/Modules/

  # ライブラリの結合
  libtool -static -o $pcl_framework/pcl_sim $pcl_sim_libs $boost_sim_libs $flann_sim_libs $qhull_sim_libs $current_pcl_ios_sim_framework/pcl 

  # Xcode で生成した framework と 個別にビルドした外部ライブラリを合わせる
  lipo -create -output $pcl_framework/pcl $pcl_framework/pcl_sim

  rm -rf $pcl_framework/pcl_*
}

make_pcl_framework_universal ()
{
  # すでに存在する device/sim 用の pcl.Framework に対して外部ライブラリを取り込む
  current_pcl_ios_device_framework=../iOSWrapper/build/Release-iphoneos/pcl.framework
  current_pcl_ios_sim_framework=../iOSWrapper/build/Release-iphonesimulator/pcl.framework

  # device_folder = "ios-device"
  # simulator_folder = "ios-simulator"

  # pcl_device_libs=`find $install/pcl-${device_folder} $install/flann-${device_folder} $install/boost-${device_folder} -name *.a`
  pcl_device_libs=`find $install/pcl-ios-device -name *.a`
  boost_device_libs=`find $install/boost-ios-device -name *.a`
  flann_device_libs=`find $install/flann-ios-device -name *.a`
  qhull_device_libs=`find $install/qhull-ios-device -name *.a`
  # Object-C/Swift で使用するためのラッパー関数を持つライブラリ
  # wrapper_device_libs=`find $install/ios_device_wrapper -name *.a`

  # pcl_sim_libs=`find $install/pcl-${simulator_folder} $install/flann-${simulator_folder} $install/boost-${simulator_folder} -name *.a`
  pcl_sim_libs=`find $install/pcl-ios-simulator -name *.a`
  boost_sim_libs=`find $install/boost-ios-simulator -name *.a`
  flann_sim_libs=`find $install/flann-ios-simulator -name *.a`
  qhull_sim_libs=`find $install/qhull-ios-simulator -name *.a`
  # Object-C/Swift で使用するためのラッパー関数を持つライブラリ
  # wrapper_sim_libs=`find $install/ios_simulator_wrapper -name *.a`

  # args -> version
  # version 1.7
  # pcl_header_dir=$install/pcl-${device_folder}/include/pcl-1.7
  # version 1.8
  pcl_header_dir=$install/pcl-ios-device/include/pcl-1.8
  boost_header_dir=$install/boost-ios-device/include
  eigen_header_dir=$install/eigen
  flann_header_dir=$install/flann-ios-device/include
  qhull_header_dir=$install/qhull-ios-device/include

  pcl_framework=$install/frameworks-universal/pcl.framework
  mkdir -p ${pcl_framework}
  rm -rf $pcl_framework/*

  cp -R "${current_pcl_ios_device_framework}" "${pcl_framework}/.."
  cp -R "${current_pcl_ios_sim_framework}" "${pcl_framework}/.."

  # Public Header
  mkdir $pcl_framework/Headers
  cp -R $pcl_header_dir/* $pcl_framework/Headers/
  cp -R $boost_header_dir/* $pcl_framework/Headers/
  cp -R $eigen_header_dir/* $pcl_framework/Headers/
  cp -R $flann_header_dir/* $pcl_framework/Headers/
  cp -R $qhull_header_dir/* $pcl_framework/Headers/

  # mkdir $pcl_framework/Modules
  # cp module.modulemap $pcl_framework/Modules/

  # ライブラリの結合
  libtool -static -o $pcl_framework/pcl_device $pcl_device_libs $boost_device_libs $flann_device_libs $qhull_device_libs $current_pcl_ios_device_framework/pcl
  libtool -static -o $pcl_framework/pcl_sim $pcl_sim_libs $boost_sim_libs $flann_sim_libs $qhull_sim_libs $current_pcl_ios_sim_framework/pcl

  # Xcode で生成した framework と 個別にビルドした外部ライブラリを合わせる
  lipo -create -output $pcl_framework/pcl $pcl_framework/pcl_device $pcl_framework/pcl_sim

  rm -rf $pcl_framework/pcl_*
}

#------------------------------------------------------------------------------
if [ "$1" == "pcl" ]; then
  make_pcl_framework
elif [ "$1" == "universal" ]; then
  make_pcl_framework_universal
elif [ "$1" == "device" ]; then
  make_pcl_framework_device
elif [ "$1" == "simulator" ]; then
  make_pcl_framework_simulator
else
  echo "Usage: $0 pcl"
  exit 1
fi

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
  device_folder = "ios-device"
  simulator_folder = "ios-simulator"

  # pcl_device_libs=`find $install/pcl-${device_folder} $install/flann-${device_folder} $install/boost-${device_folder} -name *.a`
  pcl_device_libs=`find $install/pcl-${device_folder} -name *.a`
  boost_device_libs=`find $install/boost-${device_folder} -name *.a`
  flann_device_libs=`find $install/flann-${device_folder} -name *.a`
  # pcl_sim_libs=`find $install/pcl-${simulator_folder} $install/flann-${simulator_folder} $install/boost-${simulator_folder} -name *.a`
  pcl_sim_libs=`find $install/pcl-${simulator_folder} -name *.a`
  boost_sim_libs=`find $install/boost-${simulator_folder} -name *.a`
  flann_sim_libs=`find $install/flann-${simulator_folder} -name *.a`

  # args -> version
  # version 1.7
  # pcl_header_dir=$install/pcl-${device_folder}/include/pcl-1.7
  # version 1.8
  pcl_header_dir=$install/pcl-${device_folder}/include/pcl-1.8
  boost_header_dir=$install/boost-${device_folder}/include
  eigen_header_dir=$install/eigen
  flann_header_dir=$install/flann-${device_folder}/include

  pcl_framework=$install/frameworks/pcl.framework

  mkdir -p $pcl_framework
  rm -rf $pcl_framework/*
  mkdir $pcl_framework/Headers
  cp -r $pcl_header_dir/* $pcl_framework/Headers/
  cp -r $boost_header_dir/* $pcl_framework/Headers/
  cp -r $eigen_header_dir/* $pcl_framework/Headers/
  cp -r $flann_header_dir/* $pcl_framework/Headers/

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
if [ "$1" == "pcl" ]; then
  make_pcl_framework
else
  echo "Usage: $0 pcl"
  exit 1
fi

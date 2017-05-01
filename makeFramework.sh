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
  pcl_device_libs=`find $install/pcl-ios-device $install/flann-ios-device $install/boost-ios-device -name *.a`
  # pcl_sim_libs=`find $install/pcl-ios-simulator $install/flann-ios-simulator $install/boost-iso-simulator -name *.a`

  # args -> version
  # version 1.7
  pcl_header_dir=$install/pcl-ios-device/include/pcl-1.7
  boost_header_dir=$install/boost-ios-device/include/
  eigen_header_dir=$install/eigen
  flann_header_dir=$install/flann-ios-device/include/
  # version 1.8
  # pcl_header_dir=$install/pcl-ios-device/include/pcl-1.8

  pcl_framework=$install/frameworks/pcl.framework
  mkdir -p $pcl_framework
  rm -rf $pcl_framework/*
  mkdir $pcl_framework/Headers
  cp -r $pcl_header_dir/* $pcl_framework/Headers/
  cp -r $boost_header_dir/* $pcl_framework/Headers/
  cp -r $eigen_header_dir/* $pcl_framework/Headers/
  cp -r $flann_header_dir/* $pcl_framework/Headers/

  libtool -static -o $pcl_framework/pcl_device $pcl_device_libs
  lipo -create $pcl_framework/pcl_device -output $pcl_framework/pcl
  # libtool -static -o $pcl_framework/pcl_sim $pcl_sim_libs
  # lipo -create $pcl_framework/pcl_device $pcl_framework/pcl_sim -output $pcl_framework/pcl
  rm $pcl_framework/pcl_*
}


#------------------------------------------------------------------------------
if [ "$1" == "pcl" ]; then
  make_pcl_framework
else
  echo "Usage: $0 pcl"
  exit 1
fi

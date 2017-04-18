cmake_minimum_required(VERSION 2.8.5)
project(HelloPCL2)

set(CMAKE_OSX_SYSROOT iPhoneOS9.3)
set(CMAKE_OSX_ARCHITECTURES "arm64")
# set(CMAKE_XCODE_EFFECTIVE_PLATFORMS "-iphoneos;-iphonesimulator")
set(CMAKE_XCODE_EFFECTIVE_PLATFORMS "-iphoneos")

set(CMAKE_FIND_ROOT_PATH ${CMAKE_OSX_SYSROOT})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)


if(NOT DEFINED SUPERBUILD_DIR)
  message(FATAL_ERROR "Please set the cmake variable SUPERBUILD_DIR")
endif()

set(cmakeexternals ${SUPERBUILD_DIR}/CMakeExternals)
if(NOT IS_DIRECTORY ${cmakeexternals})
  message(FATAL_ERROR "The directory ${cmakeexternals} does not exist.  Check the value of SUPERBUILD_DIR.")
endif()

list(APPEND CMAKE_FIND_ROOT_PATH
  ${cmakeexternals}/Install/boost-ios-device
  ${cmakeexternals}/Install/flann-ios-device
  ${cmakeexternals}/Install/pcl-ios-device)

# ${cmakeexternals}/Install/vtk-ios-device

# http://tomokop.hatenablog.com/entry/2014/04/24/045553
# http://www.vtk.org/Wiki/VTK/Tutorials/CMakeListsFile
# VTK_DIR
# find_package(VTK REQUIRED)
# include(${VTK_USE_FILE})

# pcl use(check ng)
# find_package(BOOST REQUIRED)
include_directories(${BOOST_INCLUDE_DIRS})

# NG
# find_package(PCL REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# AppDelegate.mm or kiwiAppDelegate.mm
set(M_SRCS
  MyGLKViewController.mm 
  GLViewController.m
  InfoView.m
  LoadDataController.m
  TitleBarViewContainer.m
  kiwiAppDelegate.mm
  main.m
  )

set(cpp_sources
  vtkPCLConversions.cxx
  vtkPCLConversions.h
  vtkPCLSACSegmentationPlane.cxx
  vtkPCLSACSegmentationPlane.h
  vtkPCLVoxelGrid.cxx
  vtkPCLVoxelGrid.h
  )

# AppDelegate.h or kiwiAppDelegate.h
set(HEADERS
  MyGLKViewController.h 
  GLViewController.h
  InfoView.h
  pcl-proxy-Prefix.pch
  LoadDataController.h
  TitleBarViewContainer.h
  kiwiAppDelegate.h
  )

# change story board?
set(XIB_FILES
  InfoView.xib
  MainWindow.xib
  TitleBarViewContainer.xib
)

set(RESOURCES
  ${XIB_FILES}

  images/Kiwi_K.png
  images/fullscreen_32.png
  images/opendata_32.png
  images/Default-Landscape~ipad.png
  images/Default-Portrait~ipad.png
  images/kiwi_icon_57.png
  images/kiwi_icon_72.png
  images/kiwi_icon_114.png

  data/pointcloud.pcd
  )

add_executable(HelloPCL2 MACOSX_BUNDLE ${M_SRCS} ${cpp_sources} ${HEADERS} ${RESOURCES})

# pcl.framework
# ${PCL_SEGMENTATION_LIBRARY}
# ${PCL_SAMPLE_CONSENSUS_LIBRARY}
# ${PCL_FILTERS_LIBRARY}
# ${PCL_KDTREE_LIBRARY}
# ${PCL_IO_LIBRARY}
# ${PCL_COMMON_LIBRARY}
# ${BOOST_LIBRARIES}

target_link_libraries(HelloPCL2
  "-framework pcl.framework"
  "-framework CoreGraphics"
  "-framework Foundation"
  "-framework UIKit"
  "-framework OpenGLES"
  "-framework QuartzCore"
  )

set_target_properties(HelloPCL2 PROPERTIES
  MACOSX_BUNDLE_GUI_IDENTIFIER "com.kitware.HelloPCL2"
  MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/pcl-proxy-Info.plist
  RESOURCE "${RESOURCES}"
  XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "iPhone Developer"
  XCODE_ATTRIBUTE_DEBUG_INFORMATION_FORMAT "dwarf-with-dsym"
  XCODE_ATTRIBUTE_GCC_PRECOMPILE_PREFIX_HEADER YES
  XCODE_ATTRIBUTE_GCC_PREFIX_HEADER ${CMAKE_CURRENT_LIST_DIR}/pcl-proxy-Prefix.pch
  XCODE_ATTRIBUTE_INFOPLIST_PREPROCESS YES
  XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET 9.3
  )

# sysroot
# if (NOT CMAKE_OSX_SYSROOT)
#   set(possible_sdk_roots
#     "${XCODE_DEVELOPER_DIR}/Platforms/iPhoneOS.platform/Developer/SDKs"
#     /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs
#     /Developer/Platforms/iPhoneOS.platform/Developer/SDKs
#     )
#   foreach(sdk_root ${possible_sdk_roots})
#     foreach(sdk iPhoneOS4.3.sdk iPhoneOS5.0.sdk iPhoneOS5.1.sdk iPhoneOS6.0.sdk
#                 iPhoneOS6.1.sdk iPhoneOS7.0.sdk iPhoneOS7.1.sdk iPhoneOS8.0.sdk iPhoneOS9.3.sdk)
#       if (EXISTS ${sdk_root}/${sdk} AND IS_DIRECTORY ${sdk_root}/${sdk})
#         set(CMAKE_OSX_SYSROOT ${sdk_root}/${sdk})
#       endif()
#     endforeach()
#   endforeach()
#   if (NOT CMAKE_OSX_SYSROOT)
#     message(FATAL_ERROR "Could not find a usable iOS SDK in ${sdk_root}")
#   endif()
# endif()

# Debug
# message(STATUS "-- gcc found at: ${CMAKE_C_COMPILER}")
# message(STATUS "-- g++ found at: ${CMAKE_CXX_COMPILER}")
message(STATUS "-- Using iOS SDK: ${CMAKE_OSX_SYSROOT}")


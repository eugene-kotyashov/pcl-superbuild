cmake_minimum_required (VERSION 3.7)

# Wrapper
set(LIBRARY_SOURCE
    ${CMAKE_CURRENT_LIST_DIR}/PointCloudLibraryWrapper.hh
    ${CMAKE_CURRENT_LIST_DIR}/PointCloudLibraryWrapper.cpp
)

add_library(
    pcl SHARED
    ${LIBRARY_SOURCE}
)


# FolderPath Check
# message(${CMAKE_BINARY_DIR})
message(STATUS ${CMAKE_BINARY_DIR})
# parent root.
# -> ./CMakeExternals/Build
# ./CMakeExternals/Install

# a/dylib
# boost?
file(GLOB boost_includefiles RELATIVE ${CMAKE_BINARY_DIR}/../Install/boost-ios-device/include *.*)
file(GLOB boost_device_libraryfiles RELATIVE ${CMAKE_BINARY_DIR}/../Install/boost-ios-device/lib *.a)
file(GLOB boost_simulation_libraryfiles RELATIVE ${CMAKE_BINARY_DIR}/../Install/boost-ios-simulator/lib *.a)

message(STATUS ${boost_includefiles})
message(STATUS ${boost_device_libraryfiles})
message(STATUS ${boost_simulation_libraryfiles})

# add_library(
#     pcl SHARED
#     ${boost_device_libraryfiles}
# )
# 
# add_library(
#     pcl SHARED
#     ${boost_simulation_libraryfiles}
# )
# 
###

# eigen
file(GLOB eigen_includefiles RELATIVE ${CMAKE_BINARY_DIR}/../Install/eigen/Eigen *.*)
file(GLOB eigen_unsupported_includefiles RELATIVE ${CMAKE_BINARY_DIR}/../Install/eigen/unsupported *.*)

message(STATUS ${eigen_includefiles})
message(STATUS ${eigen_unsupported_includefiles})

###

# flann
file(GLOB flann_includefiles RELATIVE ${CMAKE_BINARY_DIR}/../Install/flann-ios-device/include *.*)
file(GLOB flann_device_libraryfiles RELATIVE ${CMAKE_BINARY_DIR}/../Install/flann-ios-device/lib *.a)
file(GLOB flann_simulation_libraryfiles RELATIVE ${CMAKE_BINARY_DIR}/../Install/flann-ios-simulator/lib *.a)

message(STATUS ${flann_includefiles})
message(STATUS ${flann_device_libraryfiles})
message(STATUS ${flann_simulation_libraryfiles})

# add_library(
#     pcl SHARED
#     ${flann_device_libraryfiles}
# )
# 
# add_library(
#     pcl SHARED
#     ${flann_simulation_libraryfiles}
# )
# 
###

# qhull
file(GLOB qhull_includefiles RELATIVE ${CMAKE_BINARY_DIR}/../Install/qhull-ios-device/include *.*)
file(GLOB qhull_device_libraryfiles RELATIVE ${CMAKE_BINARY_DIR}/../Install/qhull-ios-device/lib *.a)
file(GLOB qhull_simulation_libraryfiles RELATIVE ${CMAKE_BINARY_DIR}/../Install/qhull-ios-simulator/lib *.a)

message(STATUS ${qhull_includefiles})
message(STATUS ${qhull_device_libraryfiles})
message(STATUS ${qhull_simulation_libraryfiles})

# add_library(
#     pcl SHARED
#     ${qhull_device_libraryfiles}
# )
# 
# add_library(
#     pcl SHARED
#     ${qhull_simulation_libraryfiles}
# )
# 
###

# pcl
file(GLOB pcl_includefiles RELATIVE ${CMAKE_BINARY_DIR}/../Install/pcl-ios-device/include/pcl-1.8 *.*)
file(GLOB pcl_device_libraryfiles RELATIVE ${CMAKE_BINARY_DIR}/../Install/pcl-ios-device/lib *.a)
file(GLOB pcl_simulation_libraryfiles RELATIVE ${CMAKE_BINARY_DIR}/../Install/pcl-ios-simulator/lib *.a)

message(STATUS ${pcl_includefiles})
message(STATUS ${pcl_device_libraryfiles})
message(STATUS ${pcl_simulation_libraryfiles})

# add_library(
#     pcl SHARED
#     ${pcl_device_libraryfiles}
# )
# 
# add_library(
#     pcl SHARED
#     ${pcl_simulation_libraryfiles}
# )
# 
###
# file(GLOB boost_libraryfiles RELATIVE ${CMAKE_BINARY_DIR} *.a)
###

set(CMAKE_SHARED_LINKER_FLAGS "-Wall")

include_directories(${CMAKE_BINARY_DIR}/../Install/boost-ios-device/include)
include_directories(${CMAKE_BINARY_DIR}/../Install/eigen-ios-device/include)
include_directories(${CMAKE_BINARY_DIR}/../Install/flann-ios-device/include)
include_directories(${CMAKE_BINARY_DIR}/../Install/pcl-ios-device/include/pcl-1.8)

include_directories(${CMAKE_BINARY_DIR}/../Install/boost-ios-simulator/include)
include_directories(${CMAKE_BINARY_DIR}/../Install/eigen-ios-simulator/include)
include_directories(${CMAKE_BINARY_DIR}/../Install/flann-ios-simulator/include)
include_directories(${CMAKE_BINARY_DIR}/../Install/pcl-ios-simulator/include/pcl-1.8)


# link_directories(${CMAKE_BINARY_DIR}/../Install/boost-ios-device)
# link_directories(${CMAKE_BINARY_DIR}/../Install/boost-ios-simulator)
# link_directories(${CMAKE_BINARY_DIR}/../Install/flann-ios-device)
# link_directories(${CMAKE_BINARY_DIR}/../Install/flann-ios-simulator)
# link_directories(${CMAKE_BINARY_DIR}/../Install/pcl-ios-device)
# link_directories(${CMAKE_BINARY_DIR}/../Install/pcl-ios-simulator)
# target_link_libraries(${boost_device_libraryfiles})
# target_link_libraries(${boost_simulation_libraryfiles})
# target_link_libraries(${flann_device_libraryfiles})
# target_link_libraries(${flann_simulation_libraryfiles})
# target_link_libraries(${pcl_device_libraryfiles})
# target_link_libraries(${pcl_simulation_libraryfiles})

# https://cmake.org/cmake/help/v3.10/prop_tgt/FRAMEWORK.html
set_target_properties(pcl PROPERTIES
    FRAMEWORK TRUE
    FRAMEWORK_VERSION A
    MACOSX_FRAMEWORK_IDENTIFIER ${FRAMEWORK_BUNDLE_IDENTIFIER}
    MACOSX_FRAMEWORK_INFO_PLIST ${CMAKE_CURRENT_LIST_DIR}/framework.plist.in
    # "current version" in semantic format in Mach-O binary file
    VERSION 1.0.0
    # "compatibility version" in semantic format in Mach-O binary file
    SOVERSION 1.0.0
    PUBLIC_HEADER "${CMAKE_CURRENT_LIST_DIR}/PointCloudLibraryWrapper.hh"
    XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET ${DEPLOYMENT_TARGET}
    XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY ${CODE_SIGN_IDENTITY}
    # XCODE_ATTRIBUTE_DEVELOPMENT_TEAM ${DEVELOPMENT_TEAM_ID}
    XCODE_ATTRIBUTE_TARGETED_DEVICE_FAMILY ${DEVICE_FAMILY}
    XCODE_ATTRIBUTE_SKIP_INSTALL "YES"
)


# Symbol visibility setup, COMPILE_FLAGS only affect C++ so for Objective C we
# have to use XCODE_ATTRIBUTE_OTHER_CFLAGS.
set_target_properties(pcl PROPERTIES
    COMPILE_FLAGS "-fvisibility=hidden -fvisibility-inlines-hidden"
    XCODE_ATTRIBUTE_OTHER_CFLAGS "-fvisibility=hidden -fvisibility-inlines-hidden")

# set_target_properties(pcl PROPERTIES COMPILE_FLAGS "-x c++")


cmake_minimum_required (VERSION 3.7)

set(FRAMEWORK_NAME pcl)
set(CODE_SIGN_IDENTITY "iPhone Developer")                  # <== Set to your preferred code sign identity, to see list:
                                                            # /usr/bin/env xcrun security find-identity -v -p codesigning
set(FRAMEWORK_BUNDLE_IDENTIFIER "com.company.framework")    # <== Set to your framework's bundle identifier (cannot be the same as app bundle identifier)
set(DEPLOYMENT_TARGET 8.0)                                  # <== Set your deployment target version of iOS
set(DEVICE_FAMILY "1,2")                                    # <== Set to "1" to target iPhone, set to "2" to target iPad, set to "1,2" to target both
set(DEVELOPMENT_TEAM_ID "AAAAAAAA")                         # <== Set to your team ID from Apple

# Wrapper
set(LIBRARY_SOURCE
    ${CMAKE_CURRENT_LIST_DIR}/PointCloudLibraryWrapper.hh
    ${CMAKE_CURRENT_LIST_DIR}/PointCloudLibraryWrapper.cpp
)

add_library(
    ${FRAMEWORK_NAME} SHARED
    ${LIBRARY_SOURCE}
)

# FolderPath Check
# message(${CMAKE_BINARY_DIR})
# ./CMakeExternals/Install

# a/dylib
# boost?
file(GLOB boost_includefiles RELATIVE ${CMAKE_BINARY_DIR}/CMakeExternals/Install/boost-ios-device/include *.*)
file(GLOB boost_device_libraryfiles RELATIVE ${CMAKE_BINARY_DIR}/CMakeExternals/Install/boost-ios-device/lib *.a)
file(GLOB boost_simulation_libraryfiles RELATIVE ${CMAKE_BINARY_DIR}/CMakeExternals/Install/boost-ios-simulator/lib *.a)

# add_library(
#     ${FRAMEWORK_NAME} SHARED
#     ${boost_device_libraryfiles}
# )
# 
# add_library(
#     ${FRAMEWORK_NAME} SHARED
#     ${boost_simulation_libraryfiles}
# )
# 
###

# eigen
file(GLOB eigen_includefiles RELATIVE ${CMAKE_BINARY_DIR}/CMakeExternals/Install/eigen/Eigen *.*)
file(GLOB eigen_includefiles RELATIVE ${CMAKE_BINARY_DIR}/CMakeExternals/Install/eigen/unsupported *.*)

###

# flann
file(GLOB flann_includefiles RELATIVE ${CMAKE_BINARY_DIR}/CMakeExternals/Install/flann-ios-device/include *.*)
file(GLOB flann_device_libraryfiles RELATIVE ${CMAKE_BINARY_DIR}/CMakeExternals/Install/flann-ios-device/lib *.a)
file(GLOB flann_simulation_libraryfiles RELATIVE ${CMAKE_BINARY_DIR}/CMakeExternals/Install/flann-ios-simulator/lib *.a)
# add_library(
#     ${FRAMEWORK_NAME} SHARED
#     ${flann_device_libraryfiles}
# )
# 
# add_library(
#     ${FRAMEWORK_NAME} SHARED
#     ${flann_simulation_libraryfiles}
# )
# 
###

# pcl
file(GLOB pcl_includefiles RELATIVE ${CMAKE_BINARY_DIR}/pcl-ios-device/include *.*)
file(GLOB pcl_device_libraryfiles RELATIVE ${CMAKE_BINARY_DIR}/pcl-ios-device/lib *.a)
file(GLOB pcl_simulation_libraryfiles RELATIVE ${CMAKE_BINARY_DIR}/pcl-ios-simulator/lib *.a)

# add_library(
#     ${FRAMEWORK_NAME} SHARED
#     ${pcl_device_libraryfiles}
# )
# 
# add_library(
#     ${FRAMEWORK_NAME} SHARED
#     ${pcl_simulation_libraryfiles}
# )
# 
###
# file(GLOB boost_libraryfiles RELATIVE ${CMAKE_BINARY_DIR} *.a)
###

set(CMAKE_SHARED_LINKER_FLAGS "-Wall")

include_directories(${CMAKE_BINARY_DIR}/boost-ios-device/include)
include_directories(${CMAKE_BINARY_DIR}/eigen-ios-device/include)
include_directories(${CMAKE_BINARY_DIR}/flann-ios-device/include)
include_directories(${CMAKE_BINARY_DIR}/pcl-ios-device/include)

# link_directories(${CMAKE_BINARY_DIR}/CMakeExternals/Install/boost-ios-device)
# link_directories(${CMAKE_BINARY_DIR}/CMakeExternals/Install/boost-ios-simulator)
# link_directories(${CMAKE_BINARY_DIR}/CMakeExternals/Install/flann-ios-device)
# link_directories(${CMAKE_BINARY_DIR}/CMakeExternals/Install/flann-ios-simulator)
# link_directories(${CMAKE_BINARY_DIR}/CMakeExternals/Install/pcl-ios-device)
# link_directories(${CMAKE_BINARY_DIR}/CMakeExternals/Install/pcl-ios-simulator)
# target_link_libraries(${boost_device_libraryfiles})
# target_link_libraries(${boost_simulation_libraryfiles})
# target_link_libraries(${flann_device_libraryfiles})
# target_link_libraries(${flann_simulation_libraryfiles})
# target_link_libraries(${pcl_device_libraryfiles})
# target_link_libraries(${pcl_simulation_libraryfiles})

# https://cmake.org/cmake/help/v3.10/prop_tgt/FRAMEWORK.html
set_target_properties(${FRAMEWORK_NAME} PROPERTIES
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
set_target_properties(${FRAMEWORK_NAME} PROPERTIES
    COMPILE_FLAGS "-fvisibility=hidden -fvisibility-inlines-hidden"
    XCODE_ATTRIBUTE_OTHER_CFLAGS "-fvisibility=hidden -fvisibility-inlines-hidden")

# set_target_properties(${FRAMEWORK_NAME} PROPERTIES COMPILE_FLAGS "-x c++")


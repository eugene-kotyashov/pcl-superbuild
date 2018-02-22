cmake_minimum_required (VERSION 3.7)

# set(MACOSX_BUNDLE_COPYRIGHT "Copyright YOU") 

# framework.plist setting
set(FRAMEWORK_NAME pcl)                                       # <== Set to your framework's name
set(FRAMEWORK_ICON_FILE "")
set(FRAMEWORK_BUNDLE_IDENTIFIER com.sirokujira.framework)     # <== Set to your framework's bundle identifier (cannot be the same as app bundle identifier)
set(CODE_SIGN_IDENTITY "iPhone Developer")                    # <== Set to your preferred code sign identity, to see list:
                                                              # /usr/bin/env xcrun security find-identity -v -p codesigning
set(DEPLOYMENT_TARGET 10.3)                                    # <== Set your deployment target version of iOS
set(DEVICE_FAMILY "1,2")                                      # <== Set to "1" to target iPhone, set to "2" to target iPad, set to "1,2" to target both
set(DEVELOPMENT_TEAM_ID "AAAAAAAA")                           # <== Set to your team ID from Apple


# Wrapper
set(LIBRARY_SOURCE
    ${CMAKE_CURRENT_LIST_DIR}/PointCloudLibraryWrapper.hpp
    ${CMAKE_CURRENT_LIST_DIR}/PointCloudLibraryWrapper.cpp
    ${CMAKE_CURRENT_LIST_DIR}/PointCloudLibraryConversions.h
    ${CMAKE_CURRENT_LIST_DIR}/PointCloudLibraryConversions.cxx
#     ${CMAKE_CURRENT_LIST_DIR}/PointCloudLibraryVoxelGrid.h
#     ${CMAKE_CURRENT_LIST_DIR}/PointCloudLibraryVoxelGrid.cxx
)

add_library(
    ${FRAMEWORK_NAME} STATIC
    ${LIBRARY_SOURCE}
)


# FolderPath Check
# CMAKE_INSTALL_PREFIX
message(STATUS "CMAKE_INSTALL_PREFIX : ${CMAKE_INSTALL_PREFIX}")
# -> ???
# message(${CMAKE_BINARY_DIR})
message(STATUS "CMAKE_BINARY_DIR : ${CMAKE_BINARY_DIR}")
# parent root.
# -> ./CMakeExternals/Build
# ./CMakeExternals/Install

# a/dylib
# boost?
# file(GLOB_RECURSE boost_includefiles "../build/CMakeExternals/Install/boost-ios-device/include/*.h*")
# file(GLOB_RECURSE boost_device_libraryfiles "../build/CMakeExternals/Install/boost-ios-device/lib/*.a")
file(GLOB_RECURSE boost_includefiles "../build/CMakeExternals/Install/boost-ios-device-arm64/include/*.h*")
file(GLOB_RECURSE boost_device_libraryfiles "../build/CMakeExternals/Install/boost-ios-device-arm64/lib/*.a")
file(GLOB_RECURSE boost_simulation_libraryfiles "../build/CMakeExternals/Install/boost-ios-simulator/lib/*.a")

# message(STATUS "boost(include)         : ${boost_includefiles}")
# message(STATUS "boost(device - lib)    : ${boost_device_libraryfiles}")
# message(STATUS "boost(simulator - lib) : ${boost_simulation_libraryfiles}")

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
file(GLOB_RECURSE eigen_includefiles "../build/CMakeExternals/Install/eigen/Eigen/*.")
file(GLOB_RECURSE eigen_unsupported_includefiles "../build/CMakeExternals/Install/eigen/unsupported/*.")

# message(STATUS ${eigen_includefiles})
# message(STATUS ${eigen_unsupported_includefiles})

###

# flann
# file(GLOB_RECURSE flann_includefiles "../build/CMakeExternals/Install/flann-ios-device/include/flann/*.h*")
# file(GLOB_RECURSE flann_device_libraryfiles "../build/CMakeExternals/Install/flann-ios-device/lib/*.a")
file(GLOB_RECURSE flann_includefiles "../build/CMakeExternals/Install/flann-ios-device-arm64/include/flann/*.h*")
file(GLOB_RECURSE flann_device_libraryfiles "../build/CMakeExternals/Install/flann-ios-device-arm64/lib/*.a")
file(GLOB_RECURSE flann_simulation_libraryfiles "../build/CMakeExternals/Install/flann-ios-simulator/lib/*.a")

# message(STATUS "flann(include)         : ${flann_includefiles}")
# message(STATUS "flann(device - lib)    : ${flann_device_libraryfiles}")
# message(STATUS "flann(simulator - lib) : ${flann_simulation_libraryfiles}")

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

# qhull
# file(GLOB_RECURSE qhull_includefiles "../build/CMakeExternals/Install/qhull-ios-device/*.h*")
# file(GLOB_RECURSE qhull_device_libraryfiles "../build/CMakeExternals/Install/qhull-ios-device/*.a")
file(GLOB_RECURSE qhull_includefiles "../build/CMakeExternals/Install/qhull-ios-device-arm64/*.h*")
file(GLOB_RECURSE qhull_device_libraryfiles "../build/CMakeExternals/Install/qhull-ios-device-arm64/*.a")
file(GLOB_RECURSE qhull_simulation_libraryfiles "../build/CMakeExternals/Install/qhull-ios-simulator/*.a")

# message(STATUS "qhull(include)         : ${qhull_includefiles}")
# message(STATUS "qhull(device - lib)    : ${qhull_device_libraryfiles}")
# message(STATUS "qhull(simulator - lib) : ${qhull_simulation_libraryfiles}")

# add_library(
#     ${FRAMEWORK_NAME} SHARED
#     ${qhull_device_libraryfiles}
# )
# 
# add_library(
#     ${FRAMEWORK_NAME} SHARED
#     ${qhull_simulation_libraryfiles}
# )
# 
###

# pcl
# file(GLOB_RECURSE pcl_includefiles "../build/CMakeExternals/Install/pcl-ios-device/include/pcl-1.8/*.h*")
# file(GLOB_RECURSE pcl_device_libraryfiles "../build/CMakeExternals/Install/pcl-ios-device/lib/*.a")
file(GLOB_RECURSE pcl_includefiles "../build/CMakeExternals/Install/pcl-ios-device-arm64/include/pcl-1.8/*.h*")
file(GLOB_RECURSE pcl_device_libraryfiles "../build/CMakeExternals/Install/pcl-ios-device-arm64/lib/*.a")
file(GLOB_RECURSE pcl_simulation_libraryfiles "../build/CMakeExternals/Install/pcl-ios-simulator/lib/*.a")

# message(STATUS "pcl(include)         : ${pcl_includefiles}")
# message(STATUS "pcl(device - lib)    : ${pcl_device_libraryfiles}")
# message(STATUS "pcl(simulator - lib) : ${pcl_simulation_libraryfiles}")

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

include_directories(../build/CMakeExternals/Install/eigen)

# if (BUILD_IOS_DEVICE)
# set(INCLUDE_DIR
#     ../build/CMakeExternals/Install/boost-ios-device/include
#     ../build/CMakeExternals/Install/flann-ios-device/include
#     ../build/CMakeExternals/Install/qhull-ios-device/include/libqhull
#     ../build/CMakeExternals/Install/qhull-ios-device/include/libqhull_r
#     ../build/CMakeExternals/Install/qhull-ios-device/include/libqhullcpp
#     ../build/CMakeExternals/Install/pcl-ios-device/include/pcl-1.8
# )
if (IOS_PLATFORM STREQUAL "OS")
    set(INCLUDE_DIR
        ../build/CMakeExternals/Install/boost-ios-device-arm64/include
        ../build/CMakeExternals/Install/flann-ios-device-arm64/include
        ../build/CMakeExternals/Install/qhull-ios-device-arm64/include/libqhull
        ../build/CMakeExternals/Install/qhull-ios-device-arm64/include/libqhull_r
        ../build/CMakeExternals/Install/qhull-ios-device-arm64/include/libqhullcpp
        ../build/CMakeExternals/Install/pcl-ios-device-arm64/include/pcl-1.8
    )
# elseif (IOS_PLATFORM STREQUAL "SIMULATOR")
elseif (IOS_PLATFORM STREQUAL "SIMULATOR64")
    set(INCLUDE_DIR
        ../build/CMakeExternals/Install/boost-ios-simulator/include
        ../build/CMakeExternals/Install/flann-ios-simulator/include
        ../build/CMakeExternals/Install/qhull-ios-simulator/include
        ../build/CMakeExternals/Install/qhull-ios-simulator/include/libqhull
        ../build/CMakeExternals/Install/qhull-ios-simulator/include/libqhull_r
        ../build/CMakeExternals/Install/qhull-ios-simulator/include/libqhullcpp
        ../build/CMakeExternals/Install/pcl-ios-simulator/include/pcl-1.8
    )
endif ()


# link_directories(../build/CMakeExternals/Install/boost-ios-device)
# link_directories(../build/CMakeExternals/Install/flann-ios-device)
# link_directories(../build/CMakeExternals/Install/qhull-ios-device)
# link_directories(../build/CMakeExternals/Install/pcl-ios-device)
# link_directories(../build/CMakeExternals/Install/boost-ios-simulator)
# link_directories(../build/CMakeExternals/Install/flann-ios-simulator)
# link_directories(../build/CMakeExternals/Install/qhull-ios-simulator)
# link_directories(../build/CMakeExternals/Install/pcl-ios-simulator)

target_include_directories(pcl PRIVATE
    ${INCLUDE_DIR}
)

if (IOS_PLATFORM STREQUAL "OS")
    target_link_libraries(${FRAMEWORK_NAME} 
        ${boost_device_libraryfiles}
        ${flann_device_libraryfiles}
        ${qhull_device_libraryfiles}
        ${pcl_device_libraryfiles}
    )
# elseif (IOS_PLATFORM STREQUAL "SIMULATOR")
elseif (IOS_PLATFORM STREQUAL "SIMULATOR64")
    target_link_libraries(${FRAMEWORK_NAME} 
        ${boost_device_libraryfiles}
        ${flann_device_libraryfiles}
        ${qhull_device_libraryfiles}
        ${pcl_device_libraryfiles}
    )
endif ()

# target_link_libraries(${FRAMEWORK_NAME} ${boost_simulation_libraryfiles})
# target_link_libraries(${FRAMEWORK_NAME} ${flann_simulation_libraryfiles})
# target_link_libraries(${FRAMEWORK_NAME} ${qhull_simulation_libraryfiles})
# target_link_libraries(${FRAMEWORK_NAME} ${pcl_simulation_libraryfiles})

# https://cmake.org/cmake/help/v3.10/prop_tgt/FRAMEWORK.html
# set_target_properties(${FRAMEWORK_NAME} PROPERTIES
#     FRAMEWORK TRUE
#     FRAMEWORK_VERSION A
#     MACOSX_FRAMEWORK_IDENTIFIER ${FRAMEWORK_BUNDLE_IDENTIFIER}
#     MACOSX_FRAMEWORK_INFO_PLIST ${CMAKE_CURRENT_LIST_DIR}/framework.plist.in
#     # info_plist properties
#     # MACOSX_FRAMEWORK_BUNDLE_VERSION
#     # MACOSX_FRAMEWORK_ICON_FILE ${FRAMEWORK_ICON_FILE}
#     # MACOSX_FRAMEWORK_SHORT_VERSION_STRING 1.0.0
#     # "current version" in semantic format in Mach-O binary file
#     VERSION 1.0.0
#     # "compatibility version" in semantic format in Mach-O binary file
#     SOVERSION 1.0.0
#     PUBLIC_HEADER "${CMAKE_CURRENT_LIST_DIR}/PointCloudLibraryWrapper.hpp"
#     # XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET ${DEPLOYMENT_TARGET}
#     XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY ${CODE_SIGN_IDENTITY}
#     # XCODE_ATTRIBUTE_DEVELOPMENT_TEAM ${DEVELOPMENT_TEAM_ID}
#     # XCODE_ATTRIBUTE_TARGETED_DEVICE_FAMILY ${DEVICE_FAMILY}
#     # XCODE_ATTRIBUTE_SKIP_INSTALL "YES"
# )

if (IOS_PLATFORM STREQUAL "OS")
set_target_properties(${FRAMEWORK_NAME} PROPERTIES
    FRAMEWORK TRUE
    FRAMEWORK_VERSION A
    MACOSX_FRAMEWORK_IDENTIFIER com.sirokujira.framework
    MACOSX_FRAMEWORK_INFO_PLIST ${CMAKE_CURRENT_LIST_DIR}/framework.plist
    # "current version" in semantic format in Mach-O binary file
    VERSION 1.0.0
    # "compatibility version" in semantic format in Mach-O binary file
    SOVERSION 1.0.0
    PUBLIC_HEADER "${CMAKE_CURRENT_LIST_DIR}/PointCloudLibraryWrapper.hpp" ${INCLUDE_DIR}
    XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET ${DEPLOYMENT_TARGET}
    XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "iPhone Developer"
    XCODE_ATTRIBUTE_TARGETED_DEVICE_FAMILY ${DEVICE_FAMILY}
    XCODE_ATTRIBUTE_SKIP_INSTALL "YES"
)
elseif (IOS_PLATFORM STREQUAL "SIMULATOR64")
set_target_properties(${FRAMEWORK_NAME} PROPERTIES
    FRAMEWORK TRUE
    FRAMEWORK_VERSION A
    MACOSX_FRAMEWORK_IDENTIFIER com.sirokujira.framework
    MACOSX_FRAMEWORK_INFO_PLIST ${CMAKE_CURRENT_LIST_DIR}/framework.plist
    # "current version" in semantic format in Mach-O binary file
    # VERSION 1.0.0
    # "compatibility version" in semantic format in Mach-O binary file
    # SOVERSION 1.0.0
    PUBLIC_HEADER "${CMAKE_CURRENT_LIST_DIR}/PointCloudLibraryWrapper.hpp" ${INCLUDE_DIR}
    # XCODE_ATTRIBUTE_TARGETED_DEVICE_FAMILY ${DEVICE_FAMILY}
    # XCODE_ATTRIBUTE_SKIP_INSTALL "YES"
)
endif ()

# https://cmake.org/cmake/help/v3.1/prop_tgt/XCODE_ATTRIBUTE_an-attribute.html
# To disable bitcode:
set_target_properties(${FRAMEWORK_NAME} PROPERTIES XCODE_ATTRIBUTE_ENABLE_BITCODE "NO")
# if (IOS_PLATFORM)
#     if (IOS_PLATFORM eq SIMULATOR64)
#         set_target_properties(${FRAMEWORK_NAME} PROPERTIES XCODE_ATTRIBUTE_VALID_ARCHS "x86_64")
#     endif()
# endif()

# -ObjC++
# Symbol visibility setup, COMPILE_FLAGS only affect C++ so for Objective C we
# have to use XCODE_ATTRIBUTE_OTHER_CFLAGS.
set_target_properties(${FRAMEWORK_NAME} PROPERTIES
    COMPILE_FLAGS "-fvisibility=hidden -fvisibility-inlines-hidden"
    XCODE_ATTRIBUTE_OTHER_CFLAGS "-fvisibility=hidden -fvisibility-inlines-hidden")

# set_target_properties(pcl PROPERTIES COMPILE_FLAGS "-x c++")


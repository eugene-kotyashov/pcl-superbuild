cmake_minimum_required(VERSION 2.8.6)

# reference pcl cmakelists.txt cmake policy
# start
if(POLICY CMP0017)
  # Do not include files in CMAKE_MODULE_PATH from files
  # in CMake module directory. Fix MXE build
  cmake_policy(SET CMP0017 NEW)
endif()

if(POLICY CMP0020 AND (WIN32 AND NOT MINGW))
  cmake_policy(SET CMP0020 NEW) # Automatically link Qt executables to qtmain target on Windows
endif()

if(POLICY CMP0048)
  cmake_policy(SET CMP0048 OLD) # do not use VERSION option in project() command
endif()

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 OLD) # Silent warnings about quoted variables
endif()
# end

project(superbuild NONE)

include(setup-superbuild.cmake)

include(setup-project-variables.cmake)

include(external-project-macros.cmake)


install_eigen()
# Build overTime
# fetch_vtk()
fetch_pcl()
fetch_boost()
fetch_flann()
fetch_qhull()

# Build overTime
# compile_vtk()

set(tags)

# Add
if (BUILD_ANDROID)
 list(APPEND tags android)
endif()
if (BUILD_IOS_DEVICE)
 list(APPEND tags ios-device)
endif()
if(BUILD_IOS_SIMULATOR)
 list(APPEND tags ios-simulator)
endif()
# 
if (BUILD_IOS_DEVICE_ARM64)
 list(APPEND tags ios-device-arm64)
endif()
if (BUILD_IOS_DEVICE_ARMV7)
 list(APPEND tags ios-device-armv7)
endif()
if (BUILD_IOS_DEVICE_ARMV7S)
 list(APPEND tags ios-device-armv7s)
endif()

if (BUILD_IOS_SIMULATOR_X86_64)
 list(APPEND tags ios-simulator-x86-64)
endif()

if (BUILD_IOS_SIMULATOR_I386)
 list(APPEND tags ios-simulator-i386)
endif()

foreach(tag ${tags})
  # Build overTime
  # crosscompile_vtk(${tag})
  crosscompile_boost(${tag})
  # crosscompile_boost_on_b2(${tag})
  crosscompile_flann(${tag})
  crosscompile_qhull(${tag})

  # use pcl
  crosscompile_pcl(${tag})
endforeach()

# if (BUILD_IOS_DEVICE)
#   ios_device_wrapper_compile()
# endif()

# if (BUILD_IOS_SIMULATOR)
#   ios_simulator_wrapper_compile()
# endif()
# 
# if (BUILD_IOS_DEVICE)
#   create_pcl_framework()
#   # create_pcl_framework2()
# endif()

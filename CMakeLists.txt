cmake_minimum_required(VERSION 2.8.6)
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

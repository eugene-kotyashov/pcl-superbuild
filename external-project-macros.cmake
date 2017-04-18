
#
# force build macro
#
macro(force_build proj)
  ExternalProject_Add_Step(${proj} forcebuild
    COMMAND ${CMAKE_COMMAND} -E remove ${base}/Stamp/${proj}/${proj}-build
    DEPENDEES configure
    DEPENDERS build
    ALWAYS 1
  )
endmacro()

macro(get_toolchain_file tag)
  string(REPLACE "-" "_" tag_with_underscore ${tag})
  set(toolchain_file ${toolchain_${tag_with_underscore}})
endmacro()

macro(get_try_run_results_file tag)
  string(REPLACE "-" "_" tag_with_underscore ${tag})
  set(try_run_results_file ${try_run_results_${tag_with_underscore}})
endmacro()

#
# Eigen fetch and install
#
macro(install_eigen)
  set(eigen_url http://bitbucket.org/eigen/eigen/get/3.2.8.tar.bz2)
  ExternalProject_Add(
    eigen
    SOURCE_DIR ${source_prefix}/eigen
    URL ${eigen_url}
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ${CMAKE_COMMAND} -E copy_directory "${source_prefix}/eigen/Eigen" "${install_prefix}/eigen/Eigen" && ${CMAKE_COMMAND} -E copy_directory "${source_prefix}/eigen/unsupported" "${install_prefix}/eigen/unsupported"
  )
endmacro()

#
# VTK fetch
#
macro(fetch_vtk)
  ExternalProject_Add(
    vtk-fetch
    SOURCE_DIR ${source_prefix}/vtk
    GIT_REPOSITORY git://github.com/Kitware/VTK.git
    # Version 1.8.0
    # GIT_TAG origin/master
    # Version 1.7.2
    GIT_TAG v6.3.0
    # GIT_REPOSITORY git://github.com/patmarion/VTK.git
    # GIT_TAG ce4a267
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
  )
endmacro()

#
# VTK compile
#
macro(compile_vtk)
  set(proj vtk-host)
  ExternalProject_Add(
    ${proj}
    SOURCE_DIR ${source_prefix}/vtk
    DOWNLOAD_COMMAND ""
    INSTALL_COMMAND ""
    DEPENDS vtk-fetch
    CMAKE_ARGS
      -DCMAKE_INSTALL_PREFIX:PATH=${install_prefix}/${proj}
      -DCMAKE_BUILD_TYPE:STRING=${build_type}
      -DBUILD_SHARED_LIBS:BOOL=ON
      -DBUILD_TESTING:BOOL=OFF
      -DVTK_ANDROID_BUILD:BOOL=ON
      -DANDROID_ARCH_NAME:STRING=armeabi-v7a
      -DANDROID_NATIVE_API_LEVEL:STRING=21
      -DOPENGL_ES_VERSION:STRING=2.0
      -DVTK_EXTRA_COMPILER_WARNINGS:BOOL=OFF
      -DVTK_Group_Imaging:BOOL=OFF
      -DVTK_Group_MPI:BOOL=OFF
      -DVTK_Group_Qt:BOOL=OFF
      -DVTK_Group_Rendering:BOOL=OFF
      -DVTK_Group_StandAlone:BOOL=ON
      -DVTK_Group_Tk:BOOL=OFF
      -DVTK_Group_Views:BOOL=OFF
      -DVTK_Group_Web:BOOL=OFF
      -DVTK_IOS_BUILD:BOOL=ON
      -DVTK_PYTHON_VERSION:STRING=2
      -DVTK_RENDERING_BACKEND:STRING=OpenGL
      -DVTK_SMP_IMPLEMENTATION_TYPE:STRING=Sequential
      -DVTK_USE_LARGE_DATA:BOOL=OFF
      -DVTK_WRAP_JAVA:BOOL=OFF
      -DVTK_WRAP_PYTHON:BOOL=OFF
      -DVTK_WRAP_TCL:BOOL=OFF
      ${vtk_module_defaults}
  )
endmacro()

#
# VTK crosscompile
#
macro(crosscompile_vtk tag)
  set(proj vtk-${tag})
  get_toolchain_file(${tag})
  get_try_run_results_file(${proj})
  if(${tag} STREQUAL "android")
    set(is_Android ON)
    set(is_iOSDevice OFF)
    set(is_iOSSimulator ON)
  elseif(${tag} STREQUAL  "ios_device")
    set(is_Android OFF)
    set(is_iOSDevice ON)
    set(is_iOSSimulator ON)
  elseif(${tag} STREQUAL  "ios_simulator")
    set(is_Android OFF)
    set(is_iOSDevice ON)
    set(is_iOSSimulator ON)
  endif ()

  ExternalProject_Add(
    ${proj}
    SOURCE_DIR ${source_prefix}/vtk
    DOWNLOAD_COMMAND ""
    DEPENDS vtk-host
    CMAKE_ARGS
      -DCMAKE_INSTALL_PREFIX:PATH=${install_prefix}/${proj}
      -DCMAKE_BUILD_TYPE:STRING=${build_type}
      -DBUILD_SHARED_LIBS:BOOL=OFF
      -DBUILD_TESTING:BOOL=OFF
      -DCMAKE_TOOLCHAIN_FILE:FILEPATH=${toolchain_file}
      -DVTKCompileTools_DIR:PATH=${build_prefix}/vtk-host
      -DVTK_ANDROID_BUILD:BOOL=${is_Android}
      -DVTK_IOS_BUILD:BOOL=${is_iOSDevice}
      -DANDROID_ARCH_NAME:STRING=armeabi-v7a
      -DANDROID_NATIVE_API_LEVEL:STRING=21
      -DOPENGL_ES_VERSION:STRING=2.0
      -DVTK_EXTRA_COMPILER_WARNINGS:BOOL=OFF
      -DVTK_Group_Imaging:BOOL=OFF
      -DVTK_Group_MPI:BOOL=OFF
      -DVTK_Group_Qt:BOOL=OFF
      -DVTK_Group_Rendering:BOOL=OFF
      -DVTK_Group_StandAlone:BOOL=ON
      -DVTK_Group_Tk:BOOL=OFF
      -DVTK_Group_Views:BOOL=OFF
      -DVTK_Group_Web:BOOL=OFF
      -DVTK_PYTHON_VERSION:STRING=2
      -DVTK_RENDERING_BACKEND:STRING=OpenGL
      -DVTK_SMP_IMPLEMENTATION_TYPE:STRING=Sequential
      -DVTK_USE_LARGE_DATA:BOOL=OFF
      -DVTK_WRAP_JAVA:BOOL=OFF
      -DVTK_WRAP_PYTHON:BOOL=OFF
      -DVTK_WRAP_TCL:BOOL=OFF
      ${vtk_module_defaults}
      -C ${try_run_results_file}
  )
endmacro()

# 
# VES fetch
# 
macro(fetch_ves)
  ExternalProject_Add(
    ves-fetch
    SOURCE_DIR ${source_prefix}/ves
    GIT_REPOSITORY git://vtk.org/stage/VES.git
    # GIT_TAG pcl-ios-app
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
  )
endmacro()

#
# VTK compile
#
macro(compile_ves)
  set(proj ves-host)
  ExternalProject_Add(
    ${proj}
    SOURCE_DIR ${source_prefix}/ves
    DOWNLOAD_COMMAND ""
    INSTALL_COMMAND ""
    DEPENDS ves-fetch
    CMAKE_ARGS
      -DCMAKE_INSTALL_PREFIX:PATH=${install_prefix}/${proj}
      -DCMAKE_BUILD_TYPE:STRING=${build_type}
      -DBUILD_SHARED_LIBS:BOOL=ON
      -DBUILD_TESTING:BOOL=OFF
      -DVTK_ANDROID_BUILD:BOOL=ON
      -DANDROID_ARCH_NAME:STRING=armeabi-v7a
      -DANDROID_NATIVE_API_LEVEL:STRING=21
      -DOPENGL_ES_VERSION:STRING=2.0
      -DVTK_EXTRA_COMPILER_WARNINGS:BOOL=OFF
      -DVTK_Group_Imaging:BOOL=OFF
      -DVTK_Group_MPI:BOOL=OFF
      -DVTK_Group_Qt:BOOL=OFF
      -DVTK_Group_Rendering:BOOL=OFF
      -DVTK_Group_StandAlone:BOOL=ON
      -DVTK_Group_Tk:BOOL=OFF
      -DVTK_Group_Views:BOOL=OFF
      -DVTK_Group_Web:BOOL=OFF
      -DVTK_IOS_BUILD:BOOL=ON
      -DVTK_PYTHON_VERSION:STRING=2
      -DVTK_RENDERING_BACKEND:STRING=OpenGL
      -DVTK_SMP_IMPLEMENTATION_TYPE:STRING=Sequential
      -DVTK_USE_LARGE_DATA:BOOL=OFF
      -DVTK_WRAP_JAVA:BOOL=OFF
      -DVTK_WRAP_PYTHON:BOOL=OFF
      -DVTK_WRAP_TCL:BOOL=OFF
      ${vtk_module_defaults}
  )
endmacro()


#
# FLANN fetch
#
macro(fetch_flann)
  ExternalProject_Add(
    flann-fetch
    SOURCE_DIR ${source_prefix}/flann
    GIT_REPOSITORY git://github.com/mariusmuja/flann
    # old
    # GIT_TAG cee08ec38a8df7bc70397f10a4d30b9b33518bb4
    # SampleBuild NG
    # GIT_TAG 1.8.4
    GIT_TAG 1.8.5
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
  )
endmacro()

#
# FLANN crosscompile
#
macro(crosscompile_flann tag)
  set(proj flann-${tag})
  get_toolchain_file(${tag})
  
#   if(${tag} STREQUAL "android")
#   elseif(${tag} STREQUAL  "ios-device")
#     set(ios_platform "OS")
#     ExternalProject_Add(
#       ${proj}
#       SOURCE_DIR ${source_prefix}/flann
#       DOWNLOAD_COMMAND ""
#       DEPENDS flann-fetch
#       CMAKE_ARGS
#         -DCMAKE_INSTALL_PREFIX:PATH=${install_prefix}/${proj}
#         -DCMAKE_BUILD_TYPE:STRING=${build_type}
#         -DCMAKE_TOOLCHAIN_FILE:FILEPATH=${toolchain_file}
#        # -DCMAKE_IOS_DEVELOPER_ROOT:${ios_root}
#        # -DIOS_PLATFORM_LOCATION:${ios_platform}
#        # -DBUILD_SHARED_LIBS:BOOL=OFF
#         -DBUILD_EXAMPLES:BOOL=OFF
#         -DBUILD_PYTHON_BINDINGS:BOOL=OFF
#         -DBUILD_MATLAB_BINDINGS:BOOL=OFF
#     )
#   elseif(${tag} STREQUAL  "ios-simulator")
#     set(ios_platform "SIMULATOR64")
#     ExternalProject_Add(
#       ${proj}
#       SOURCE_DIR ${source_prefix}/flann
#       DOWNLOAD_COMMAND ""
#       DEPENDS flann-fetch
#       CMAKE_ARGS
#         -DCMAKE_INSTALL_PREFIX:PATH=${install_prefix}/${proj}
#         -DCMAKE_BUILD_TYPE:STRING=${build_type}
#         -DCMAKE_TOOLCHAIN_FILE:FILEPATH=${toolchain_file}
#        # -DCMAKE_IOS_DEVELOPER_ROOT:${ios_root}
#        # -DIOS_PLATFORM_LOCATION:${ios_platform}
#        # -DBUILD_SHARED_LIBS:BOOL=OFF
#         -DBUILD_EXAMPLES:BOOL=OFF
#         -DBUILD_PYTHON_BINDINGS:BOOL=OFF
#         -DBUILD_MATLAB_BINDINGS:BOOL=OFF
#     )
#   endif ()

  ExternalProject_Add(
    ${proj}
    SOURCE_DIR ${source_prefix}/flann
    DOWNLOAD_COMMAND ""
    DEPENDS flann-fetch
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${install_prefix}/${proj}
               -DCMAKE_BUILD_TYPE:STRING=${build_type}
               -DCMAKE_TOOLCHAIN_FILE:FILEPATH=${toolchain_file}
               -DBUILD_EXAMPLES:BOOL=OFF
               -DBUILD_PYTHON_BINDINGS:BOOL=OFF
               -DBUILD_MATLAB_BINDINGS:BOOL=OFF
  )

  force_build(${proj})
endmacro()


#
# Boost fetch
#
macro(fetch_boost)
  ExternalProject_Add(
    boost-fetch
    SOURCE_DIR ${source_prefix}/boost
    GIT_REPOSITORY git://github.com/Sirokujira/boost-build.git
    GIT_TAG origin/master
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
  )
endmacro()

#
# Boost crosscompile
#
macro(crosscompile_boost tag)


  set(proj boost-${tag})
  get_toolchain_file(${tag})
  ExternalProject_Add(
    ${proj}
    SOURCE_DIR ${source_prefix}/boost
    DOWNLOAD_COMMAND ""
    DEPENDS boost-fetch
    CMAKE_ARGS
      -DCMAKE_INSTALL_PREFIX:PATH=${install_prefix}/${proj}
      -DCMAKE_BUILD_TYPE:STRING=${build_type}
      -DCMAKE_TOOLCHAIN_FILE:FILEPATH=${toolchain_file}
      -DBUILD_SHARED_LIBS:BOOL=OFF
  )

  force_build(${proj})
endmacro()

#
# Boost crosscompile(use b2.exe)
#
macro(crosscompile_boost_on_b2 tag)

  set(proj boost-${tag})
  
  # ./b2 toolset=clang cflags="-arch arm64 -fvisibility=default -miphoneos-version-min=5.0" architecture=arm target-os=iphone link=static threading=multi define=_LITTLE_ENDIAN include=/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS9.3.sdk/usr/include/
  # --prefix=(インストールしたいディレクトリ)
  execute_process(
    COMMAND ./b2 toolset=clang cflags="-arch arm64 -fvisibility=default -miphoneos-version-min=7.0" architecture=arm target-os=iphone link=static threading=multi define=_LITTLE_ENDIAN include=/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS9.3.sdk/usr/include/
    WORKING_DIRECTORY ${source_prefix}/boost
  )
endmacro()


#
# PCL fetch
#
macro(fetch_pcl)
  ExternalProject_Add(
    pcl-fetch
    SOURCE_DIR ${source_prefix}/pcl
    # GIT_REPOSITORY git://github.com/patmarion/PCL.git
    # GIT_REPOSITORY git://github.com/PointCloudLibrary/pcl.git
    GIT_REPOSITORY git://github.com/Sirokujira/pcl.git
    # GIT_TAG origin/android-tag
    # GIT_TAG origin/master
    # GIT_TAG pcl-1.8.0
    GIT_TAG Branch_pcl-1.7.2
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
  )
endmacro()

#
# PCL crosscompile
macro(crosscompile_pcl tag)
  set(proj pcl-${tag})
  get_toolchain_file(${tag})
  get_try_run_results_file(${proj})

  # copy the toolchain file and append the boost install dir to CMAKE_FIND_ROOT_PATH
  set(original_toolchain_file ${toolchain_file})
  get_filename_component(toolchain_file ${original_toolchain_file} NAME)
  set(toolchain_file ${build_prefix}/${proj}/${toolchain_file})
  configure_file(${original_toolchain_file} ${toolchain_file} COPYONLY)
  file(APPEND ${toolchain_file}
    "\nlist(APPEND CMAKE_FIND_ROOT_PATH ${install_prefix}/boost-${tag})\n")

  ExternalProject_Add(
    ${proj}
    SOURCE_DIR ${source_prefix}/pcl
    DOWNLOAD_COMMAND ""
    DEPENDS pcl-fetch boost-${tag} flann-${tag} eigen
    CMAKE_ARGS
      -DCMAKE_INSTALL_PREFIX:PATH=${install_prefix}/${proj}
      -DCMAKE_BUILD_TYPE:STRING=${build_type}
      -DCMAKE_TOOLCHAIN_FILE:FILEPATH=${toolchain_file}
      -DBUILD_SHARED_LIBS:BOOL=OFF
      -DPCL_SHARED_LIBS:BOOL=OFF
      # Clang Build NG
      -DPCL_ENABLE_SSE:BOOL=OFF
      -DWITH_OPENGL:BOOL=OFF
      -DWITH_FZAPI:BOOL=OFF
      -DWITH_LIBUSB:BOOL=OFF
      -DWITH_OPENNI:BOOL=OFF
      -DWITH_OPENNI2:BOOL=OFF
      -DWITH_PCAP:BOOL=OFF
      -DWITH_PNG:BOOL=OFF
      -DWITH_PXCAPI:BOOL=OFF
      # -DWITH_QHULL:BOOL=ON
      -DWITH_QHULL:BOOL=OFF
      -DWITH_QT:BOOL=OFF
      # -DWITH_VTK:BOOL=ON
      -DWITH_VTK:BOOL=OFF
      -DBUILD_OPENNI:BOOL=OFF
      -DBUILD_OPENNI2:BOOL=OFF
      -DBUILD_all_in_one_installer:BOOL=OFF
      -DBUILD_apps:BOOL=OFF
      -DBUILD_common:BOOL=ON
      -DBUILD_example:BOOL=OFF
      -DBUILD_features:BOOL=ON
      -DBUILD_filters:BOOL=ON
      -DBUILD_geometry:BOOL=ON
      -DBUILD_global_tests:BOOL=OFF
      -DBUILD_io:BOOL=ON
      -DBUILD_kdtree:BOOL=ON
      -DBUILD_keypoints:BOOL=ON
      -DBUILD_outofcore:BOOL=ON
      -DBUILD_people:BOOL=ON
      -DBUILD_recognition:BOOL=ON
      -DBUILD_registration:BOOL=ON
      -DBUILD_sample_consensus:BOOL=ON
      -DBUILD_search:BOOL=ON
      -DBUILD_segmentation:BOOL=ON
      -DBUILD_surface:BOOL=ON
      -DBUILD_surface_on_nurbs:BOOL=ON
      -DBUILD_tools:BOOL=ON
      -DBUILD_tracking:BOOL=ON
      # -DBUILD_visualization:BOOL=ON
      -DBUILD_visualization:BOOL=OFF
      -DBUILD_examples:BOOL=OFF
      -DEIGEN_INCLUDE_DIR=${install_prefix}/eigen
      -DFLANN_INCLUDE_DIR=${install_prefix}/flann-${tag}/include
      -DFLANN_LIBRARY=${install_prefix}/flann-${tag}/lib/libflann_cpp_s.a
      -DFLANN_LIBRARY_DEBUG=${install_prefix}/flann-${tag}/lib/libflann_cpp_s-gd.lib
      -DBOOST_ROOT=${install_prefix}/boost-${tag}
      -C ${try_run_results_file}
  )

  force_build(${proj})
endmacro()


# macro(create_pcl_framework tags)
macro(create_pcl_framework)
    # message (STATUS ${tags})
    add_custom_target(pclFramework ALL
      COMMAND ${CMAKE_SOURCE_DIR}/makeFramework.sh pcl
      WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
      # DEPENDS pcl-ios-device pcl-ios-simulator
      DEPENDS pcl-ios-device
      # DEPENDS ${tags}
      COMMENT "Creating pcl.framework")
endmacro()

cmake_minimum_required(VERSION 3.4.1)

project(HelloPCLWorld)

set (Boost_INCLUDE_DIRS ../../../../build/CMakeExternals/Install/boost-android/include/)
set (BOOST_LIBRARIES_DIRS ../../../../build/CMakeExternals/Install/boost-android/lib/)
# find_package(Boost 1.54.0 REQUIRED COMPONENTS date_time system filesystem thread iostreams)
include_directories(${Boost_INCLUDE_DIRS})

set (PCL_INCLUDE_DIRS ../../../../build/CMakeExternals/Install/pcl-android/include/)
set (PCL_LIBRARIES_DIRS ../../../../build/CMakeExternals/Install/pcl-android/lib/)
# find_package(PCL 1.7 REQUIRED COMPONENTS common io octree kdtree)
include_directories(${PCL_INCLUDE_DIRS})  

# flann
set (Flann_INCLUDE_DIRS ../../../../build/CMakeExternals/Install/flann-android/include/)
set (Flann_LIBRARIES_DIRS ../../../../build/CMakeExternals/Install/flann-android/lib/)
include_directories(${Flann_INCLUDE_DIRS})

# Eigen
set (EIGEN_INCLUDE_DIRS ../../../../build/CMakeExternals/Install/eigen/)
include_directories(${EIGEN_INCLUDE_DIRS})  

# library folder path
link_directories (${BOOST_LIBRARIES_DIRS} ${Flann_LIBRARIES_DIRS} ${PCL_LIBRARIES_DIRS})

# libflann_cpp_s.a
# libflann_s.a

# external
target_link_libraries(${BOOST_LIBRARIES_DIRS}libboost_filesystem.a)
target_link_libraries(${BOOST_LIBRARIES_DIRS}libboost_system.a)
target_link_libraries(${BOOST_LIBRARIES_DIRS}libboost_program_options.a)
target_link_libraries(${BOOST_LIBRARIES_DIRS}libboost_iostreams.a)
target_link_libraries(${BOOST_LIBRARIES_DIRS}libboost_date_time.a)
target_link_libraries(${BOOST_LIBRARIES_DIRS}libboost_chrono.a)
target_link_libraries(${Flann_LIBRARIES_DIRS}libflann_cpp_s.a)
target_link_libraries(${PCL_LIBRARIES_DIRS}libpcl_common.a)
target_link_libraries(${PCL_LIBRARIES_DIRS}libpcl_keypoints.a)
target_link_libraries(${PCL_LIBRARIES_DIRS}libpcl_segmentation.a)
target_link_libraries(${PCL_LIBRARIES_DIRS}libpcl_features.a)
target_link_libraries(${PCL_LIBRARIES_DIRS}libpcl_octree.a)
target_link_libraries(${PCL_LIBRARIES_DIRS}libpcl_surface.a)
target_link_libraries(${PCL_LIBRARIES_DIRS}libpcl_filters.a)
target_link_libraries(${PCL_LIBRARIES_DIRS}libpcl_recognition.a)
target_link_libraries(${PCL_LIBRARIES_DIRS}libpcl_tracking.a)
target_link_libraries(${PCL_LIBRARIES_DIRS}libpcl_io.a)
target_link_libraries(${PCL_LIBRARIES_DIRS}libpcl_registration.a)
target_link_libraries(${PCL_LIBRARIES_DIRS}libpcl_io_ply.a)
target_link_libraries(${PCL_LIBRARIES_DIRS}libpcl_sample_consensus.a)
target_link_libraries(${PCL_LIBRARIES_DIRS}libpcl_kdtree.a)
target_link_libraries(${PCL_LIBRARIES_DIRS}libpcl_search.a)

# Include libraries needed for hello-jni lib
target_link_libraries( hello-pcl log android)

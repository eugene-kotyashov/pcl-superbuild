cmake_minimum_required(VERSION 2.8)

project(HelloPCLWorld)

#notice the "recycling" of CMAKE_C_FLAGS
#this is necessary to pick up android flags
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pedantic" )

set (Boost_INCLUDE_DIRS /home/sirokujira/work2/pcl-superbuild/build/CMakeExternals/Install/boost-android/include/)
set (BOOST_LIBRARIES /home/sirokujira/work2/pcl-superbuild/build/CMakeExternals/Install/boost-android/lib/)
# find_package(Boost 1.54.0 REQUIRED COMPONENTS date_time system filesystem thread iostreams)
include_directories(${Boost_INCLUDE_DIRS})

set (PCL_INCLUDE_DIRS /home/sirokujira/work2/pcl-superbuild/build/CMakeExternals/Install/pcl-android/include/)
set (PCL_LIBRARIES /home/sirokujira/work2/pcl-superbuild/build/CMakeExternals/Install/pcl-android/lib/)
# find_package(PCL 1.7 REQUIRED COMPONENTS common io octree kdtree)
include_directories(${PCL_INCLUDE_DIRS})  

# flann
set (Flann_INCLUDE_DIRS /home/sirokujira/work2/pcl-superbuild/build/CMakeExternals/Install/flann-android/include/)
set (Flann_LIBRARIES /home/sirokujira/work2/pcl-superbuild/build/CMakeExternals/Install/flann-android/lib/)
include_directories(${Flann_INCLUDE_DIRS})

# Eigen
set (EIGEN_INCLUDE_DIRS /home/sirokujira/work2/pcl-superbuild/build/CMakeExternals/Install/eigen/)
include_directories(${EIGEN_INCLUDE_DIRS})  


# IMPORTANT
# android-ndk-hogehoge -> 
# arm-linux-androideabi -> 
link_directories (${Boost_INCLUDE_DIRS} ${Flann_LIBRARIES} ${PCL_LIBRARIES})

#test for ANDROID and look for stuff not relevant to android.
if(NOT ANDROID)
#jni is available by default on android
find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})
endif()


#this will be overridden by the android toolchain
set( LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib/pc CACHE PATH
        "Single Directory for all Libraries")



#make sure to used shared in in the jni library, as this will be loaded by
#java

# libflann_cpp_s.a  
# libflann_s.a

add_library(helloPCLWorld SHARED jni/hello-pcl.cpp)
target_link_libraries(helloPCLWorld ${BOOST_LIBRARIES}libboost_filesystem.a)
target_link_libraries(helloPCLWorld ${BOOST_LIBRARIES}libboost_system.a)
target_link_libraries(helloPCLWorld ${BOOST_LIBRARIES}libboost_program_options.a)
target_link_libraries(helloPCLWorld ${BOOST_LIBRARIES}libboost_iostreams.a)
target_link_libraries(helloPCLWorld ${BOOST_LIBRARIES}libboost_date_time.a)
target_link_libraries(helloPCLWorld ${BOOST_LIBRARIES}libboost_chrono.a)
target_link_libraries(helloPCLWorld ${Flann_LIBRARIES}libflann_cpp_s.a)
target_link_libraries(helloPCLWorld ${PCL_LIBRARIES}libpcl_common.a)
target_link_libraries(helloPCLWorld ${PCL_LIBRARIES}libpcl_keypoints.a)
target_link_libraries(helloPCLWorld ${PCL_LIBRARIES}libpcl_segmentation.a)
target_link_libraries(helloPCLWorld ${PCL_LIBRARIES}libpcl_features.a)
target_link_libraries(helloPCLWorld ${PCL_LIBRARIES}libpcl_octree.a)
target_link_libraries(helloPCLWorld ${PCL_LIBRARIES}libpcl_surface.a)
target_link_libraries(helloPCLWorld ${PCL_LIBRARIES}libpcl_filters.a)
target_link_libraries(helloPCLWorld ${PCL_LIBRARIES}libpcl_recognition.a)
target_link_libraries(helloPCLWorld ${PCL_LIBRARIES}libpcl_tracking.a)
target_link_libraries(helloPCLWorld ${PCL_LIBRARIES}libpcl_io.a)
target_link_libraries(helloPCLWorld ${PCL_LIBRARIES}libpcl_registration.a)
target_link_libraries(helloPCLWorld ${PCL_LIBRARIES}libpcl_io_ply.a)
target_link_libraries(helloPCLWorld ${PCL_LIBRARIES}libpcl_sample_consensus.a)
target_link_libraries(helloPCLWorld ${PCL_LIBRARIES}libpcl_kdtree.a)
target_link_libraries(helloPCLWorld ${PCL_LIBRARIES}libpcl_search.a)


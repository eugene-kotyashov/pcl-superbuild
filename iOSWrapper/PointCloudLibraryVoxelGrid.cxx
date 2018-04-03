#include "PointCloudLibraryVoxelGrid.h"
#include "PointCloudLibraryConversions.h"

//----------------------------------------------------------------------------
namespace 
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr ApplyVoxelGrid(
                      pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud,
                      double leafSize[3])
    {
        pcl::VoxelGrid<pcl::PointXYZ> voxelGrid;
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloudFiltered(new pcl::PointCloud<pcl::PointXYZ>);
        voxelGrid.setInputCloud(cloud);
        voxelGrid.setLeafSize(leafSize[0], leafSize[1], leafSize[2]);
        voxelGrid.filter(*cloudFiltered);

        return cloudFiltered;
    }

}

PointCloudLibraryVoxelGrid::PointCloudLibraryVoxelGrid() 
{
    this->LeafSize[0] = 0.01;
    this->LeafSize[1] = 0.01;
    this->LeafSize[2] = 0.01;
}

float* PointCloudLibraryVoxelGrid::PointCloudLibraryVoxelGridFromFloatArray(float* farray)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud = PointCloudDataFromFloatArray(farray);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloudFiltered = ApplyVoxelGrid(cloud, this->LeafSize);

    size_t nr_points = cloudFiltered->points.size();
    float* tmpFloatArray = new float[nr_points * 3];
    if (cloudFiltered->is_dense)
    {
        for (int i = 0; i < nr_points; ++i)
        {
            float point[3] = {cloud->points[i].x, cloud->points[i].y, cloud->points[i].z};
            // unsigned char color[3] = {cloud->points[i].r, cloud->points[i].g, cloud->points[i].b};
            tmpFloatArray[i * 3 + 0] = point[0];
            tmpFloatArray[i * 3 + 1] = point[1];
            tmpFloatArray[i * 3 + 2] = point[2];
            // rgbArray->SetTupleValue(i, color);
        }
    }
    else
    {
        int j = 0;    // true point index
        for (int i = 0; i < nr_points; ++i)
        {
            // Check if the point is invalid
            if (!pcl_isfinite (cloud->points[i].x) || 
                !pcl_isfinite (cloud->points[i].y) || 
                !pcl_isfinite (cloud->points[i].z))
            continue;

            float point[3] = { cloud->points[i].x, cloud->points[i].y, cloud->points[i].z };
            // unsigned char color[3] = {cloud->points[i].r, cloud->points[i].g, cloud->points[i].b};
            tmpFloatArray[j * 3 + 0] = point[0];
            tmpFloatArray[j * 3 + 1] = point[1];
            tmpFloatArray[j * 3 + 2] = point[2];
            //rgbArray->SetTupleValue(j, color);
            j++;
        }

        nr_points = j;
        //points->SetNumberOfPoints(nr_points);
        //rgbArray->SetNumberOfTuples(nr_points);
    }

    // ì_åQâ¡çH
    return tmpFloatArray;
}



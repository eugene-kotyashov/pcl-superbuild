
#include "PointCloudLibraryConversions.h"

#include <pcl/io/pcd_io.h>
#include <cassert>

//----------------------------------------------------------------------------
PointCloudLibraryConversions::PointCloudLibraryConversions()
{
}

//----------------------------------------------------------------------------
PointCloudLibraryConversions::~PointCloudLibraryConversions()
{
}

namespace {
    template <typename T>
    float* TemplatedPointCloudDataFromPCDFile(const std::string& filename)
    {
        typename pcl::PointCloud<T>::Ptr cloud(new pcl::PointCloud<T>);
        if (pcl::io::loadPCDFile(filename, *cloud) == -1)
        {
            std::cout << "Error reading pcd file: " << filename;
            return NULL;
        }

        return PointCloudLibraryConversions::PointCloudDataFromPointCloud(cloud);
    }
}


//----------------------------------------------------------------------------
// float* PointCloudLibraryConversions::PointCloudDataFromPCDFile(const std::string& filename)
float* PointCloudLibraryConversions::PointCloudDataFromPCDFile(const char* filename)
{
    int version;
    int type;
    unsigned int idx;

    pcl::PCLPointCloud2 cloud;
    Eigen::Vector4f origin;
    Eigen::Quaternionf orientation;
    pcl::PCDReader reader;
    reader.readHeader(filename, cloud, origin, orientation, version, type, idx);

    if (pcl::getFieldIndex(cloud, "rgba") != -1) 
    {
        return TemplatedPointCloudDataFromPCDFile<pcl::PointXYZRGBA>(filename);
    }
    else if (pcl::getFieldIndex(cloud, "rgb") != -1) 
    {
        return TemplatedPointCloudDataFromPCDFile<pcl::PointXYZRGB>(filename);
    }
    else 
    {
        return TemplatedPointCloudDataFromPCDFile<pcl::PointXYZ>(filename);
    }
}

//----------------------------------------------------------------------------
float* PointCloudLibraryConversions::PointCloudDataFromPointCloud(pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
{
    size_t nr_points = cloud->points.size();

    float* tmpFloatArray = new float[nr_points * 3];

    if (cloud->is_dense)
    {
        for (int i = 0; i < nr_points; ++i)
        {
            float point[3] = {cloud->points[i].x, cloud->points[i].y, cloud->points[i].z}; 
            // points->SetPoint(i, point);
            tmpFloatArray[i * 3 + 0] = point[0];
            tmpFloatArray[i * 3 + 1] = point[1];
            tmpFloatArray[i * 3 + 2] = point[2];
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

            float point[3] = {cloud->points[i].x, cloud->points[i].y, cloud->points[i].z}; 
            tmpFloatArray[j * 3 + 0] = point[0];
            tmpFloatArray[j * 3 + 1] = point[1];
            tmpFloatArray[j * 3 + 2] = point[2];
            j++;
        }

        nr_points = j;
        //points->SetNumberOfPoints(nr_points);
    }

    // ì_åQâ¡çH
    return tmpFloatArray;
}

//----------------------------------------------------------------------------
float* PointCloudLibraryConversions::PointCloudDataFromPointCloud(pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr cloud)
{
    size_t nr_points = cloud->points.size();

    float* tmpFloatArray = new float[nr_points * 3];

    if (cloud->is_dense)
    {
        for (int i = 0; i < nr_points; ++i)
        {
            float point[3] = {cloud->points[i].x, cloud->points[i].y, cloud->points[i].z};
            // unsigned char color[3] = {cloud->points[i].r, cloud->points[i].g, cloud->points[i].b};
            tmpFloatArray[i * 3 + 0] = point[0];
            tmpFloatArray[i * 3 + 1] = point[1];
            tmpFloatArray[i * 3 + 2] = point[2];

            //rgbArray->SetTupleValue(i, color);
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

            float point[3] = {cloud->points[i].x, cloud->points[i].y, cloud->points[i].z};
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

//----------------------------------------------------------------------------
float* PointCloudLibraryConversions::PointCloudDataFromPointCloud(pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr cloud)
{
    size_t nr_points = cloud->points.size();

    float* tmpFloatArray = new float[nr_points * 3];

    if (cloud->is_dense)
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

pcl::PointCloud<pcl::PointXYZ>::ConstPtr PointCloudDataFromPCDFile(float* farray)
{
    pcl::PointCloud<pcl::PointXYZ> tmpPointCloudPtr;

    int arraySize = 0;
    for(int i = 0; i < arraySize; i++)
    {
        cloud->points[i].x
        cloud->points[i].y
        cloud->points[i].z
    }

    return tmpPointCloudPtr;
}

pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr PointCloudLibraryConversions::PointCloudDataFromPCDFile(float* farray)
{
    pcl::PointCloud<pcl::PointXYZRGB> tmpPointCloudPtr;

    int arraySize = 0;
    for(int i = 0; i < arraySize; i++)
    {
        cloud->points[i].x = 0;
        cloud->points[i].y = 0;
        cloud->points[i].z = 0;
        cloud->points[i].rgb = 0;
    }

    return tmpPointCloudPtr;
}

pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr PointCloudLibraryConversions::PointCloudDataFromPCDFile(float* farray)
{
    pcl::PointCloud<pcl::PointXYZRGBA> tmpPointCloudPtr;

    int arraySize = 0;
    for(int i = 0; i < arraySize; i++)
    {
        cloud->points[i].x = 0;
        cloud->points[i].y = 0;
        cloud->points[i].z = 0;
        cloud->points[i].rgba = 0;
    }

    return tmpPointCloudPtr;
}


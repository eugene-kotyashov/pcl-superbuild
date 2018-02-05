/*=========================================================================
=========================================================================*/

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
    void TemplatedPolyDataFromPCDFile(const std::string& filename)
    {
        typename pcl::PointCloud<T>::Ptr cloud(new pcl::PointCloud<T>);
        if (pcl::io::loadPCDFile(filename, *cloud) == -1)
        {
            std::cout << "Error reading pcd file: " << filename;
            return;
        }

        // return PointCloudLibraryConversions::PolyDataFromPointCloud(cloud);
    }
}


//----------------------------------------------------------------------------
void PointCloudLibraryConversions::PolyDataFromPCDFile(const std::string& filename)
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
        return TemplatedPolyDataFromPCDFile<pcl::PointXYZRGBA>(filename);
    }
    else if (pcl::getFieldIndex(cloud, "rgb") != -1) 
    {
        return TemplatedPolyDataFromPCDFile<pcl::PointXYZRGB>(filename);
    }
    else 
    {
        return TemplatedPolyDataFromPCDFile<pcl::PointXYZ>(filename);
    }
}

//----------------------------------------------------------------------------
void PointCloudLibraryConversions::PolyDataFromPointCloud(pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
{
    int nr_points = cloud->points.size();

    //vtkNew<vtkPoints> points;
    //points->SetDataTypeToFloat();
    //points->SetNumberOfPoints(nr_points);

    if (cloud->is_dense)
    {
        for (int i = 0; i < nr_points; ++i)
        {
            float point[3] = {cloud->points[i].x, cloud->points[i].y, cloud->points[i].z}; 
            // points->SetPoint(i, point);
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
            //points->SetPoint(j, point);
            j++;
        }
        
        nr_points = j;
        //points->SetNumberOfPoints(nr_points);
    }

    //vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();
    //polyData->SetPoints(points.GetPointer());
    //polyData->SetVerts(NewVertexCells(nr_points));
    //return polyData;
}

//----------------------------------------------------------------------------
void PointCloudLibraryConversions::PolyDataFromPointCloud(pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr cloud)
{
    int nr_points = cloud->points.size();

    //vtkNew<vtkPoints> points;
    //points->SetDataTypeToFloat();
    //points->SetNumberOfPoints(nr_points);

    //vtkNew<vtkUnsignedCharArray> rgbArray;
    //rgbArray->SetName("rgb_colors");
    //rgbArray->SetNumberOfComponents(3);
    //rgbArray->SetNumberOfTuples(nr_points);

    if (cloud->is_dense)
    {
        for (int i = 0; i < nr_points; ++i)
        {
            float point[3] = {cloud->points[i].x, cloud->points[i].y, cloud->points[i].z};
            unsigned char color[3] = {cloud->points[i].r, cloud->points[i].g, cloud->points[i].b}; 
            //points->SetPoint(i, point);
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
            unsigned char color[3] = {cloud->points[i].r, cloud->points[i].g, cloud->points[i].b};
            //points->SetPoint(j, point);
            //rgbArray->SetTupleValue(j, color);
            j++;
        }
        
        nr_points = j;
        //points->SetNumberOfPoints(nr_points);
        //rgbArray->SetNumberOfTuples(nr_points);
    }

    //vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();
    //polyData->SetPoints(points.GetPointer());
    //polyData->GetPointData()->AddArray(rgbArray.GetPointer());
    //polyData->SetVerts(NewVertexCells(nr_points));
    //return polyData;
}

//----------------------------------------------------------------------------
void PointCloudLibraryConversions::PolyDataFromPointCloud(pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr cloud)
{
    int nr_points = cloud->points.size();

    //vtkNew<vtkPoints> points;
    //points->SetDataTypeToFloat();
    //points->SetNumberOfPoints(nr_points);

    //vtkNew<vtkUnsignedCharArray> rgbArray;
    //rgbArray->SetName("rgb_colors");
    //rgbArray->SetNumberOfComponents(3);
    //rgbArray->SetNumberOfTuples(nr_points);

    if (cloud->is_dense)
    {
        for (int i = 0; i < nr_points; ++i)
        {
            float point[3] = {cloud->points[i].x, cloud->points[i].y, cloud->points[i].z};
            unsigned char color[3] = {cloud->points[i].r, cloud->points[i].g, cloud->points[i].b}; 
            //points->SetPoint(i, point);
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
            unsigned char color[3] = {cloud->points[i].r, cloud->points[i].g, cloud->points[i].b};
            //points->SetPoint(j, point);
            //rgbArray->SetTupleValue(j, color);
            j++;
        }
        
        nr_points = j;
        //points->SetNumberOfPoints(nr_points);
        //rgbArray->SetNumberOfTuples(nr_points);
    }
    
    //vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();
    //polyData->SetPoints(points.GetPointer());
    //polyData->GetPointData()->AddArray(rgbArray.GetPointer());
    //polyData->SetVerts(NewVertexCells(nr_points));
    //return polyData;
}


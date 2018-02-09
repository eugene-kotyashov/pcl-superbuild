#include "PointCloudLibraryConversions.h"
#include "PointCloudLibrarySACSegmentationPlane.h"

#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>

//----------------------------------------------------------------------------
namespace {
    void ComputeSACSegmentationLine(pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud,
                                    double distanceThreshold,
                                    int maxIterations,
                                    pcl::ModelCoefficients::Ptr &modelCoefficients,
                                    pcl::PointIndices::Ptr &inliers)
    {
        pcl::SACSegmentation<pcl::PointXYZ> seg;
        inliers = pcl::PointIndices::Ptr(new pcl::PointIndices);
        modelCoefficients = pcl::ModelCoefficients::Ptr(new pcl::ModelCoefficients);

        seg.setOptimizeCoefficients (true);
        seg.setModelType(pcl::SACMODEL_LINE);
        seg.setMethodType(pcl::SAC_RANSAC);
        seg.setMaxIterations(maxIterations);
        seg.setDistanceThreshold(distanceThreshold);

        seg.setInputCloud(cloud);
        seg.segment(*inliers, *modelCoefficients);
    }

    void ComputeSACSegmentationPlane(pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud,
                                     double distanceThreshold,
                                     int maxIterations,
                                     pcl::ModelCoefficients::Ptr &modelCoefficients,
                                     pcl::PointIndices::Ptr &inliers)
    {
        pcl::SACSegmentation<pcl::PointXYZ> seg;
        inliers = pcl::PointIndices::Ptr(new pcl::PointIndices);
        modelCoefficients = pcl::ModelCoefficients::Ptr(new pcl::ModelCoefficients);

        seg.setOptimizeCoefficients (true);
        seg.setModelType(pcl::SACMODEL_PLANE);
        seg.setMethodType(pcl::SAC_RANSAC);
        seg.setMaxIterations(maxIterations);
        seg.setDistanceThreshold(distanceThreshold);

        seg.setInputCloud(cloud);
        seg.segment(*inliers, *modelCoefficients);
    }

    void ComputeSACSegmentationPerpendicularPlane(pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud,
                                                  double distanceThreshold,
                                                  const Eigen::Vector3f& perpendicularAxis,
                                                  double angleEpsilon,
                                                  int maxIterations,
                                                  pcl::ModelCoefficients::Ptr &modelCoefficients,
                                                  pcl::PointIndices::Ptr &inliers)
    {
        pcl::SACSegmentation<pcl::PointXYZ> seg;
        inliers = pcl::PointIndices::Ptr(new pcl::PointIndices);
        modelCoefficients = pcl::ModelCoefficients::Ptr(new pcl::ModelCoefficients);

        seg.setOptimizeCoefficients (true);
        seg.setModelType(pcl::SACMODEL_PERPENDICULAR_PLANE);
        seg.setMethodType(pcl::SAC_RANSAC);
        seg.setMaxIterations(maxIterations);
        seg.setDistanceThreshold(distanceThreshold);
        seg.setAxis(perpendicularAxis);
        seg.setEpsAngle(angleEpsilon);

        seg.setInputCloud(cloud);
        seg.segment(*inliers, *modelCoefficients);
    }
}


//----------------------------------------------------------------------------
// int PointCloudLibrarySACSegmentationPlane::RequestData()
// {
//   // perform plane model fit
//   pcl::PointIndices::Ptr inlierIndices;
//   pcl::ModelCoefficients::Ptr modelCoefficients;
//   pcl::PointCloud<pcl::PointXYZ>::Ptr cloud = PointCloudLibraryConversions::PointCloudFromPolyData(input);
//
//   if (this->PerpendicularConstraintEnabled)
//     {
//     ComputeSACSegmentationPerpendicularPlane(
//                                 cloud,
//                                 this->DistanceThreshold,
//                                 Eigen::Vector3f(this->PerpendicularAxis[0],
//                                                 this->PerpendicularAxis[1],
//                                                 this->PerpendicularAxis[2]),
//                                 this->AngleEpsilon,
//                                 this->MaxIterations,
//                                 modelCoefficients,
//                                 inlierIndices);
//     }
//   else
//     {
//     ComputeSACSegmentationPlane(cloud,
//                                 this->DistanceThreshold,
//                                 this->MaxIterations,
//                                 modelCoefficients,
//                                 inlierIndices);
//     }
//
//   // store plane coefficients
//   for (size_t i = 0; i < modelCoefficients->values.size(); ++i)
//     {
//     this->PlaneCoefficients[i] = modelCoefficients->values[i];
//     }
//
//   // compute origin and normal
//   Eigen::Vector4d coeffs(this->PlaneCoefficients);
//   if (coeffs[2] < 0)
//     {
//     coeffs *= -1.0;
//     }
//   Eigen::Vector3d normal(coeffs.data());
//
//  return 1;
//}


#ifndef __PointCloudLibrarySACSegmentationPlane_h
#define __PointCloudLibrarySACSegmentationPlane_h

class PointCloudLibrarySACSegmentationPlane
{
    // virtual int RequestData();
    static void PointCloudLibrarySACSegmentationPlaneFromFloatArray(float* farray);

public:
    static PointCloudLibrarySACSegmentationPlane *New();

protected:
    double DistanceThreshold;
    int MaxIterations;

    bool PerpendicularConstraintEnabled;
    double PerpendicularAxis[3];
    double AngleEpsilon;

    double PlaneCoefficients[4];
    double PlaneOrigin[3];
    double PlaneNormal[3];

    PointCloudLibrarySACSegmentationPlane();
    virtual ~PointCloudLibrarySACSegmentationPlane();

private:
    PointCloudLibrarySACSegmentationPlane(const PointCloudLibrarySACSegmentationPlane&);  // Not implemented.
    void operator=(const PointCloudLibrarySACSegmentationPlane&);  // Not implemented.
};

#endif



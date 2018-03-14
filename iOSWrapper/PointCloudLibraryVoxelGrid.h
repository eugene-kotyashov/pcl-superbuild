// .NAME PointCloudLibraryVoxelGrid
// .SECTION Description
// 

#ifndef __PointCloudLibraryVoxelGrid_h
#define __PointCloudLibraryVoxelGrid_h

#include <pcl/filters/voxel_grid.h>

class PointCloudLibraryVoxelGrid
{
public:
    static PointCloudLibraryVoxelGrid *New();
    static float* PointCloudLibraryVoxelGridFromFloatArray(float* farray);

protected:
    double LeafSize[3];

    // virtual int RequestData();
    PointCloudLibraryVoxelGrid();
    virtual ~PointCloudLibraryVoxelGrid();
private:
    PointCloudLibraryVoxelGrid(const PointCloudLibraryVoxelGrid&);  // Not implemented.
    void operator=(const PointCloudLibraryVoxelGrid&);  // Not implemented.
};

#endif  // __PointCloudLibraryVoxelGrid_h



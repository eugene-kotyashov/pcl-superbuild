// .NAME PointCloudLibraryVoxelGrid
// .SECTION Description
// 

#ifndef __PointCloudLibraryVoxelGrid_h
#define __PointCloudLibraryVoxelGrid_h

class PointCloudLibraryVoxelGrid
{
public:
  static PointCloudLibraryVoxelGrid *New();

protected:
  double LeafSize[3];

  // virtual int RequestData();

  PointCloudLibraryVoxelGrid();
  virtual ~PointCloudLibraryVoxelGrid();
private:
  PointCloudLibraryVoxelGrid(const PointCloudLibraryVoxelGrid&);  // Not implemented.
  void operator=(const PointCloudLibraryVoxelGrid&);  // Not implemented.
};

#endif



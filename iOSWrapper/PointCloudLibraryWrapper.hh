
#ifndef __PointCloudWrapper_hh
#define __PointCloudWrapper_hh

#include <string>
#include <iostream>


// このファイル内(cpp含む)での namespace の使用はNG
class PointCloudLibraryWrapper
{
public:
    PointCloudLibraryWrapper() 
	{ 
		std::cout << "PointCloudLibraryWrapper Created." << std::endl; 
		// conversion = new PointCloudLibraryConversions();
	}
    ~PointCloudLibraryWrapper()
	{ 
		std::cout << "PointCloudLibraryWrapper Destroyed." << std::endl; 
		// if (conversion != NULL)
		// {
		// 	delete conversion;
		// }
	}

    int PrintFoo();
    std::string foo;

    // io
    void Load(const char* filename);

    // Feature
    // Filter
    void FilterAxis(const char* axis, double min, double max);

    // Segmentation

private:
    // 加工前データ
    // pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud;
    // 加工後データ
    // pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud_filtered;
	// PointCloudLibraryConversions* conversion;

	// 
    float* pointdata;
};

#endif // __PointCloudWrapper_hh



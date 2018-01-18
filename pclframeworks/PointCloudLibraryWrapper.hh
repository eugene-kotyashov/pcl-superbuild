#include <string>
#include <iostream>

class PointCloudLibraryWrapper
{
public:
    int PrintFoo();
    std::string foo;
    PointCloudLibraryWrapper() {std::cout << "PointCloudLibraryWrapper Created." << std::endl;}
    ~PointCloudLibraryWrapper() {std::cout << "PointCloudLibraryWrapper Destroyed." << std::endl;}
private:
};



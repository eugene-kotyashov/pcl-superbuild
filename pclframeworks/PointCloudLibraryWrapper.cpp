#include "PointCloudLibraryWrapper.hh"
#include <string>
#include <iostream>

#define EXPORT __attribute__((visibility("default")))

EXPORT
int PointCloudLibraryWrapper::PrintFoo()
{
#if __cplusplus
    std::cout << "C++ environment detected." << std::endl;
#endif
    std::cout << "PointCloudLibraryWrapper::PrintFoo() called." << std::endl;
    return 1;
} 


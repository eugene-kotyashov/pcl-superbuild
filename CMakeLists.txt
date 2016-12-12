cmake_minimum_required(VERSION 2.8.6)
project(superbuild NONE)

include(setup-superbuild.cmake)

include(setup-project-variables.cmake)

include(external-project-macros.cmake)


fetch_vtk()

# Build overTime(Travis)
compile_vtk()

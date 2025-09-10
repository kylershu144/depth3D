cmake_minimum_required(VERSION 3.14)
project(depth3D LANGUAGES CXX)

# You can adjust this to your Python
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 CONFIG REQUIRED)      # if installed via pip or vcpkg
# find_package(Eigen3 REQUIRED)               # make sure Eigen3 is findable

pybind11_add_module(matching_bind cpp/matching_bind.cpp)

set(EIGEN3_INCLUDE_DIR "C:/Users/Kyler/libs/eigen-3.4.0")
target_include_directories(matching_bind PRIVATE ${EIGEN3_INCLUDE_DIR})

# target_link_libraries(matching_bind PRIVATE Eigen3::Eigen)
# set_target_properties(matching_bind PROPERTIES
#     CXX_STANDARD 17
#     CXX_STANDARD_REQUIRED YES
# )

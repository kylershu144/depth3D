#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <Eigen/Dense>

namespace py = pybind11;

Eigen::Matrix4d compute_umeyama(const Eigen::MatrixXd &src,
                                const Eigen::MatrixXd &dst,
                                bool with_scaling = true)
{
    // Eigen::umeyama expects data in (dim x num_points)
    Eigen::Matrix4d transform = Eigen::umeyama(src.transpose(), dst.transpose(), with_scaling);
    return transform;
}

PYBIND11_MODULE(matching_bind, m)
{
    m.doc() = "Python binding for Eigen's umeyama() using pybind11";
    m.def("compute_umeyama", &compute_umeyama,
          py::arg("src"), py::arg("dst"),
          py::arg("with_scaling") = true);
}

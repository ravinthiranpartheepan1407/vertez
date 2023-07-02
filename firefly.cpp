#include "Infernix/mean.cpp"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

PYBIND11_MODULE(vertez, m)
{
    m.def("mean", &mean, "Mean of a list of numbers");
}
#include "functions.h"
#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
#include <pygen/converters.h>

namespace py = boost::python;
namespace np = boost::python::numpy;

BOOST_PYTHON_MODULE(pyTestFunctions)
{
    Py_Initialize();
    np::initialize();

    // Create convertors for type T
    convertEigen<double>(Converters::All, true);
    // TODO: Check other type
    // TODO: Check particular case of fixed-size vectorizable Eigen types

    // Matrix relative
    py::class_<RandomDynamicSizeMatrix>("RandomDynamicSizeMatrix", py::init<Eigen::Index, Eigen::Index>())
        .def("get", &RandomDynamicSizeMatrix::get)
        .def("check", &RandomDynamicSizeMatrix::check);
    py::class_<RandomFixedSizeMatrix>("RandomFixedSizeMatrix", py::init<>())
        .def("get", &RandomFixedSizeMatrix::get)
        .def("check", &RandomFixedSizeMatrix::check);
    py::class_<RandomHalfDynamicSizeMatrix>("RandomHalfDynamicSizeMatrix", py::init<Eigen::Index>())
        .def("get", &RandomHalfDynamicSizeMatrix::get)
        .def("check", &RandomHalfDynamicSizeMatrix::check);

    // Vector relative
    py::class_<RandomDynamicSizeVector>("RandomDynamicSizeVector", py::init<Eigen::Index>())
        .def("get", &RandomDynamicSizeVector::get)
        .def("check", &RandomDynamicSizeVector::check);
    py::class_<RandomDynamicSizeRowVector>("RandomDynamicSizeRowVector", py::init<Eigen::Index>())
        .def("get", &RandomDynamicSizeRowVector::get)
        .def("check", &RandomDynamicSizeRowVector::check);
    py::class_<RandomFixedSizeVector>("RandomFixedSizeVector", py::init<>())
        .def("get", &RandomFixedSizeVector::get)
        .def("check", &RandomFixedSizeVector::check);
    py::class_<RandomFixedSizeRowVector>("RandomFixedSizeRowVector", py::init<>())
        .def("get", &RandomFixedSizeRowVector::get)
        .def("check", &RandomFixedSizeRowVector::check);
}
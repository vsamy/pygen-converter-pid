#include "functions.h"
#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
#include <pygen/converters.h>

namespace py = boost::python;
namespace np = boost::python::numpy;

BOOST_PYTHON_MODULE(TestFunctions)
{
    Py_Initialize();
    np::initialize();

    // Create convertors for type T
    convertEigen<double>(Converters::All, true);
    // TODO: Check other type

    // Matrix relative
    py::class_<RandomDynamicSizeMatrix>("RandomDynamicSizeMatrix", py::init<Eigen::Index, Eigen::Index>())
        .def("get", &RandomDynamicSizeMatrix::get)
        .def("check", &RandomDynamicSizeMatrix::check);
    py::class_<RandomFixedSizeMatrix>("RandomFixedSizeMatrix", py::init<Eigen::Index, Eigen::Index>())
        .def("get", &RandomFixedSizeMatrix::get)
        .def("check", &RandomFixedSizeMatrix::check);
    py::class_<RandomhalfDynamicSizeMatrix>("RandomhalfDynamicSizeMatrix", py::init<Eigen::Index, Eigen::Index>())
        .def("get", &RandomhalfDynamicSizeMatrix::get)
        .def("check", &RandomhalfDynamicSizeMatrix::check);

    // Vector relative
    py::class_<RandomDynamicSizeVector>("RandomDynamicSizeVector", py::init<Eigen::Index, Eigen::Index>())
        .def("get", &RandomDynamicSizeVector::get)
        .def("check", &RandomDynamicSizeVector::check);
    py::class_<RandomDynamicSizeRowVector>("RandomDynamicSizeRowVector", py::init<Eigen::Index, Eigen::Index>())
        .def("get", &RandomDynamicSizeRowVector::get)
        .def("check", &RandomDynamicSizeRowVector::check);
    py::class_<RandomFixedSizeVector>("RandomFixedSizeVector", py::init<Eigen::Index, Eigen::Index>())
        .def("get", &RandomFixedSizeVector::get)
        .def("check", &RandomFixedSizeVector::check);
    py::class_<RandomFixedSizeRowVector>("RandomFixedSizeRowVector", py::init<Eigen::Index, Eigen::Index>())
        .def("get", &RandomFixedSizeRowVector::get)
        .def("check", &RandomFixedSizeRowVector::check);
}
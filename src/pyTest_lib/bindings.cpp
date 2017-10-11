#include "functions.h"
#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
#include <complex>
#include <pygen/converters.h>
#include <string>

namespace py = boost::python;
namespace np = boost::python::numpy;

template <typename T>
struct TypeName {
    static constexpr const char* name = typeid(T).name();
};

template <>
struct TypeName<int> {
    static constexpr const char* name = "Int";
};

template <>
struct TypeName<float> {
    static constexpr const char* name = "Float";
};

template <>
struct TypeName<double> {
    static constexpr const char* name = "Double";
};

template <>
struct TypeName<std::complex<float> > {
    static constexpr const char* name = "CFloat";
};

template <>
struct TypeName<std::complex<double> > {
    static constexpr const char* name = "CDouble";
};

template <typename T>
void bindEigen()
{
    // Create convertors for type T
    convertEigen<T>(Converters::All, true);

    // Matrix relative
    auto name = std::string("RandomDynamicSizeMatrix") + TypeName<T>::name;
    py::class_<RandomDynamicSizeMatrix<T> >(name.c_str(), py::init<Eigen::Index, Eigen::Index>())
        .def("get", &RandomDynamicSizeMatrix<T>::get)
        .def("check", &RandomDynamicSizeMatrix<T>::check);
    name = std::string("RandomFixedSizeMatrix") + TypeName<T>::name;
    py::class_<RandomFixedSizeMatrix<T> >(name.c_str(), py::init<>())
        .def("get", &RandomFixedSizeMatrix<T>::get)
        .def("check", &RandomFixedSizeMatrix<T>::check);
    name = std::string("RandomHalfDynamicSizeMatrix") + TypeName<T>::name;
    py::class_<RandomHalfDynamicSizeMatrix<T> >(name.c_str(), py::init<Eigen::Index>())
        .def("get", &RandomHalfDynamicSizeMatrix<T>::get)
        .def("check", &RandomHalfDynamicSizeMatrix<T>::check);

    // Vector relative
    name = std::string("RandomDynamicSizeVector") + TypeName<T>::name;
    py::class_<RandomDynamicSizeVector<T> >(name.c_str(), py::init<Eigen::Index>())
        .def("get", &RandomDynamicSizeVector<T>::get)
        .def("check", &RandomDynamicSizeVector<T>::check);
    name = std::string("RandomDynamicSizeRowVector") + TypeName<T>::name;
    py::class_<RandomDynamicSizeRowVector<T> >(name.c_str(), py::init<Eigen::Index>())
        .def("get", &RandomDynamicSizeRowVector<T>::get)
        .def("check", &RandomDynamicSizeRowVector<T>::check);
    name = std::string("RandomFixedSizeVector") + TypeName<T>::name;
    py::class_<RandomFixedSizeVector<T> >(name.c_str(), py::init<>())
        .def("get", &RandomFixedSizeVector<T>::get)
        .def("check", &RandomFixedSizeVector<T>::check);
    name = std::string("RandomFixedSizeRowVector") + TypeName<T>::name;
    py::class_<RandomFixedSizeRowVector<T> >(name.c_str(), py::init<>())
        .def("get", &RandomFixedSizeRowVector<T>::get)
        .def("check", &RandomFixedSizeRowVector<T>::check);
}

BOOST_PYTHON_MODULE(pyTestFunctions)
{
    Py_Initialize();
    np::initialize();

    // Eigen default global matrix types are: int, float, double, std::complex<float> and std::complex<double>
    bindEigen<int>();
    bindEigen<float>();
    bindEigen<double>();
    bindEigen<std::complex<float> >();
    bindEigen<std::complex<double> >();
}
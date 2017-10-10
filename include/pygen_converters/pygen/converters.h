
#pragma once

#include <Eigen/Core>
#include <boost/python.hpp>
#include <boost/python/implicit.hpp>
#include <boost/python/module.hpp>
#include <boost/python/numpy.hpp>

namespace py = boost::python;
namespace np = boost::python::numpy;

/*
 *                  List -> Eigen converters
 */

template <class VectorType>
struct python_list_to_eigen_vector {
    python_list_to_eigen_vector()
    {
        py::converter::registry::push_back(&convertible, &construct, py::type_id<VectorType>());
    }

    static void* convertible(PyObject* obj_ptr)
    {
        static_assert(VectorType::ColsAtCompileTime == 1 || VectorType::RowsAtCompileTime == 1); // Only for vectors conversion

        if (!PySequence_Check(obj_ptr)
            || (VectorType::ColsAtCompileTime == 1 && VectorType::RowsAtCompileTime != Eigen::Dynamic
                   && (PySequence_Size(obj_ptr) != VectorType::RowsAtCompileTime)) // Check Fixed-size vector
            || (VectorType::RowsAtCompileTime == 1 && VectorType::ColsAtCompileTime != Eigen::Dynamic
                   && (PySequence_Size(obj_ptr) != VectorType::ColsAtCompileTime))) // Check Fixed-size row vector
            return 0;

        if (VectorType::ColsAtCompileTime == 1 && VectorType::RowsAtCompileTime != Eigen::Dynamic && (PySequence_Size(obj_ptr) != VectorType::RowsAtCompileTime))
            return 0;

        py::list arr = py::extract<py::list>(obj_ptr);
        for (long i = 0; i < py::len(arr); i++)
            if (!py::extract<typename VectorType::Scalar>(arr[i]).check())
                return 0;

        return obj_ptr;
    }

    static void construct(PyObject* obj_ptr, py::converter::rvalue_from_python_stage1_data* data)
    {
        py::list arr = py::extract<py::list>(obj_ptr);
        long len = py::len(arr);

        using storage_type = py::converter::rvalue_from_python_storage<VectorType>;
        void* storage = reinterpret_cast<storage_type*>(data)->storage.bytes;

        new (storage) VectorType;
        VectorType& vec = *static_cast<VectorType*>(storage);

        if (VectorType::RowsAtCompileTime == Eigen::Dynamic || VectorType::ColsAtCompileTime == Eigen::Dynamic)
            vec.resize(len);

        for (long i = 0; i < len; ++i)
            vec(i) = py::extract<typename VectorType::Scalar>(arr[i]);

        data->convertible = storage;
    }
};

template <class MatrixType>
struct python_list_to_eigen_matrix {
    python_list_to_eigen_matrix()
    {
        py::converter::registry::push_back(&convertible, &construct, py::type_id<MatrixType>());
    }

    static void* convertible(PyObject* obj_ptr)
    {
        auto checkNestedList = [](const py::list& list) {
            py::extract<py::list> nested_list(list[0]);
            if (!nested_list.check())
                return false;

            long cols = py::len(nested_list());
            for (long i = 1; i < py::len(list); ++i) {
                py::extract<py::list> nested_list(list[i]);
                if (!nested_list.check() || py::len(nested_list) != cols) // Check nested list size
                    return false;
                for (long j = 0; j < cols; ++j)
                    if (!py::extract<typename MatrixType::Scalar>(nested_list()[j]).check()) // Check list type
                        return false;
            }

            return true;
        };

        py::extract<py::list> extract_list(obj_ptr);
        py::extract<py::list> extract_nested_list(extract_list());
        if (!extract_list.check() // Check list
            || !checkNestedList(extract_list()) // Check nested lists
            || (MatrixType::RowsAtCompileTime != Eigen::Dynamic && MatrixType::RowsAtCompileTime != py::len(extract_list())) // Check rows are the same
            || (MatrixType::ColsAtCompileTime != Eigen::Dynamic && MatrixType::ColsAtCompileTime != py::len(extract_nested_list()))) // Check cols are the same
            return 0;

        return obj_ptr;
    }

    static void construct(PyObject* obj_ptr, py::converter::rvalue_from_python_stage1_data* data)
    {
        py::list arr = py::extract<py::list>(obj_ptr);
        long rows = py::len(arr);
        long cols = py::len(py::extract<py::list>(arr[0])());

        using storage_type = py::converter::rvalue_from_python_storage<MatrixType>;
        void* storage = reinterpret_cast<storage_type*>(data)->storage.bytes;

        new (storage) MatrixType;
        MatrixType& mat = *static_cast<MatrixType*>(storage);

        // Resize matrix if (half-)dynamic-sized matrix
        if (MatrixType::RowsAtCompileTime == Eigen::Dynamic || MatrixType::ColsAtCompileTime == Eigen::Dynamic)
            mat.resize(rows, cols);

        for (long i = 0; i < rows; ++i)
            for (long j = 0; j < cols; ++j)
                mat(i, j) = py::extract<typename MatrixType::Scalar>(arr[i][j]);

        data->convertible = storage;
    }
};

/*
 *              Numpy -> Eigen converters
 */

template <typename VectorType>
struct numpy_array_to_eigen_vector {
    numpy_array_to_eigen_vector()
    {
        py::converter::registry::push_back(&convertible, &construct, py::type_id<VectorType>());
    }

    static void* convertible(PyObject* obj_ptr)
    {
        static_assert(VectorType::RowsAtCompileTime == 1 || VectorType::ColsAtCompileTime == 1); // Check that in c++ side, it is an Eigen vector
        py::extract<np::ndarray> arr(obj_ptr);
        if (!arr.check() // Check it is a numpy array
            || arr().get_nd() != 1 // Check array dimension (does not allow numpy array of type (1, 3), needs to ravel it first)
            || arr().get_dtype() != np::dtype::get_builtin<typename VectorType::Scalar>() // Check type
            || (VectorType::RowsAtCompileTime == 1
                   && VectorType::ColsAtCompileTime != Eigen::Dynamic
                   && VectorType::ColsAtCompileTime != arr().shape(0)) // Check vector size in case of fixed-size array (for a row-vector)
            || (VectorType::ColsAtCompileTime == 1
                   && VectorType::RowsAtCompileTime != Eigen::Dynamic
                   && VectorType::RowsAtCompileTime != arr().shape(0))) // Check vector size in case of fixed-size array (for a column-vector)
            return 0;

        return obj_ptr;
    }

    static void construct(PyObject* obj_ptr, py::converter::rvalue_from_python_stage1_data* data)
    {
        np::ndarray arr = py::extract<np::ndarray>(obj_ptr);

        using storage_type = py::converter::rvalue_from_python_storage<VectorType>;
        void* storage = reinterpret_cast<storage_type*>(data)->storage.bytes;

        new (storage) VectorType;
        VectorType& vec = *static_cast<VectorType*>(storage);
        // Resize for dynamic-sized matrices
        if (VectorType::RowsAtCompileTime == Eigen::Dynamic || VectorType::ColsAtCompileTime == Eigen::Dynamic)
            vec.resize(arr.shape(0));

        // Extract values. The type has been check in the convertible function
        for (int i = 0; i < arr.shape(0); ++i)
            vec(i) = py::extract<typename VectorType::Scalar>(arr[i]);

        data->convertible = storage;
    }
};

template <typename MatrixType>
struct numpy_array_to_eigen_matrix {
    numpy_array_to_eigen_matrix()
    {
        py::converter::registry::push_back(&convertible, &construct, py::type_id<MatrixType>());
    }

    static void* convertible(PyObject* obj_ptr)
    {
        py::extract<np::ndarray> arr(obj_ptr);
        if (!arr.check() // Check it is a numpy array
            || arr().get_nd() != 2 // Check array dimension
            || arr().get_dtype() != np::dtype::get_builtin<typename MatrixType::Scalar>() // Check type
            || (MatrixType::RowsAtCompileTime != Eigen::Dynamic && MatrixType::RowsAtCompileTime != arr().shape(0)) // Check rows are the same
            || (MatrixType::ColsAtCompileTime != Eigen::Dynamic && MatrixType::ColsAtCompileTime != arr().shape(1))) // Check cols are the same
            return 0;

        return obj_ptr;
    }

    static void construct(PyObject* obj_ptr, py::converter::rvalue_from_python_stage1_data* data)
    {
        np::ndarray arr = py::extract<np::ndarray>(obj_ptr);

        using storage_type = py::converter::rvalue_from_python_storage<MatrixType>;
        void* storage = reinterpret_cast<storage_type*>(data)->storage.bytes;

        new (storage) MatrixType;
        MatrixType& mat = *static_cast<MatrixType*>(storage);
        // Resize for dynamic-sized matrices
        // For half dynamic-sized matrices, the fixed-size part has been check in the convertible function
        if (MatrixType::RowsAtCompileTime == Eigen::Dynamic || MatrixType::ColsAtCompileTime == Eigen::Dynamic)
            mat.resize(arr.shape(0), arr.shape(1));

        // Extract values. The type has been check in the convertible function
        for (int i = 0; i < arr.shape(0); ++i)
            for (int j = 0; j < arr.shape(1); ++j)
                mat(i, j) = py::extract<typename MatrixType::Scalar>(arr[i][j]);

        data->convertible = storage;
    }
};

/*
 *              Eigen -> Numpy converters
 */

template <typename VectorType>
struct eigen_vector_to_numpy_array {
    static PyObject* convert(const VectorType& mat)
    {
        static_assert(VectorType::ColsAtCompileTime == 1 || VectorType::RowsAtCompileTime == 1); // Ensure that it is a vector

        np::dtype dt = np::dtype::get_builtin<typename VectorType::Scalar>();
        auto shape = py::make_tuple(mat.size());
        np::ndarray mOut = np::empty(shape, dt);

        for (Eigen::Index i = 0; i < mat.size(); ++i)
            mOut[i] = mat(i);

        return py::incref(mOut.ptr());
    }
};

template <typename MatrixType>
struct eigen_matrix_to_numpy_array {
    static PyObject* convert(const MatrixType& mat)
    {
        static_assert(MatrixType::ColsAtCompileTime != 1 && MatrixType::RowsAtCompileTime != 1); // Ensure that it is not a vector

        np::dtype dt = np::dtype::get_builtin<typename MatrixType::Scalar>();
        auto shape = py::make_tuple(mat.rows(), mat.cols());
        np::ndarray mOut = np::empty(shape, dt);

        for (Eigen::Index i = 0; i < mat.rows(); ++i)
            for (Eigen::Index j = 0; j < mat.cols(); ++j)
                mOut[i][j] = mat(i, j);

        return py::incref(mOut.ptr());
    }
};

/**
 * Main converters
 */

enum struct Converters : short {
    None = 0,
    Matrix = 1,
    Vector = 1 << 1,
    RowVector = 1 << 2,
    NoRowConversion = Matrix | Vector,
    All = Matrix | Vector | RowVector
};

inline short
operator&(Converters lhs, Converters rhs)
{
    return static_cast<short>(lhs) & static_cast<short>(rhs);
}

template <typename T>
void convertMatrix(bool isListConvertible = true)
{
    // python -> eigen
    numpy_array_to_eigen_matrix<Eigen::Matrix<T, 2, 2> >(); // Matrix2<T>
    numpy_array_to_eigen_matrix<Eigen::Matrix<T, Eigen::Dynamic, 2> >(); // MatrixX2<T>
    numpy_array_to_eigen_matrix<Eigen::Matrix<T, 2, Eigen::Dynamic> >(); // Matrix2X<T>
    numpy_array_to_eigen_matrix<Eigen::Matrix<T, 3, 3> >(); // Matrix3<T>
    numpy_array_to_eigen_matrix<Eigen::Matrix<T, Eigen::Dynamic, 3> >(); // MatrixX3<T>
    numpy_array_to_eigen_matrix<Eigen::Matrix<T, 3, Eigen::Dynamic> >(); // Matrix3X<T>
    numpy_array_to_eigen_matrix<Eigen::Matrix<T, 4, 4> >(); // Matrix4<T>
    numpy_array_to_eigen_matrix<Eigen::Matrix<T, Eigen::Dynamic, 4> >(); // MatrixX4<T>
    numpy_array_to_eigen_matrix<Eigen::Matrix<T, 4, Eigen::Dynamic> >(); // Matrix4X<T>
    numpy_array_to_eigen_matrix<Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> >(); // MatrixX<T>

    if (isListConvertible) {
        python_list_to_eigen_matrix<Eigen::Matrix<T, 2, 2> >(); // Matrix2<T>
        python_list_to_eigen_matrix<Eigen::Matrix<T, Eigen::Dynamic, 2> >(); // MatrixX2<T>
        python_list_to_eigen_matrix<Eigen::Matrix<T, 2, Eigen::Dynamic> >(); // Matrix2X<T>
        python_list_to_eigen_matrix<Eigen::Matrix<T, 3, 3> >(); // Matrix3<T>
        python_list_to_eigen_matrix<Eigen::Matrix<T, Eigen::Dynamic, 3> >(); // MatrixX3<T>
        python_list_to_eigen_matrix<Eigen::Matrix<T, 3, Eigen::Dynamic> >(); // Matrix3X<T>
        python_list_to_eigen_matrix<Eigen::Matrix<T, 4, 4> >(); // Matrix4<T>
        python_list_to_eigen_matrix<Eigen::Matrix<T, Eigen::Dynamic, 4> >(); // MatrixX4<T>
        python_list_to_eigen_matrix<Eigen::Matrix<T, 4, Eigen::Dynamic> >(); // Matrix4X<T>
        python_list_to_eigen_matrix<Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> >(); // MatrixX<T>
    }

    // eigen -> python
    py::to_python_converter<Eigen::Matrix<T, 2, 2>, eigen_matrix_to_numpy_array<Eigen::Matrix<T, 2, 2> > >(); // Matrix2<T>
    py::to_python_converter<Eigen::Matrix<T, Eigen::Dynamic, 2>, eigen_matrix_to_numpy_array<Eigen::Matrix<T, Eigen::Dynamic, 2> > >(); // MatrixX2<T>
    py::to_python_converter<Eigen::Matrix<T, 2, Eigen::Dynamic>, eigen_matrix_to_numpy_array<Eigen::Matrix<T, 2, Eigen::Dynamic> > >(); // Matrix2X<T>
    py::to_python_converter<Eigen::Matrix<T, 3, 3>, eigen_matrix_to_numpy_array<Eigen::Matrix<T, 3, 3> > >(); // Matrix3<T>
    py::to_python_converter<Eigen::Matrix<T, Eigen::Dynamic, 3>, eigen_matrix_to_numpy_array<Eigen::Matrix<T, Eigen::Dynamic, 3> > >(); // MatrixX3<T>
    py::to_python_converter<Eigen::Matrix<T, 3, Eigen::Dynamic>, eigen_matrix_to_numpy_array<Eigen::Matrix<T, 3, Eigen::Dynamic> > >(); // Matrix3X<T>
    py::to_python_converter<Eigen::Matrix<T, 4, 4>, eigen_matrix_to_numpy_array<Eigen::Matrix<T, 4, 4> > >(); // Matrix4<T>
    py::to_python_converter<Eigen::Matrix<T, Eigen::Dynamic, 4>, eigen_matrix_to_numpy_array<Eigen::Matrix<T, Eigen::Dynamic, 4> > >(); // MatrixX4<T>
    py::to_python_converter<Eigen::Matrix<T, 4, Eigen::Dynamic>, eigen_matrix_to_numpy_array<Eigen::Matrix<T, 4, Eigen::Dynamic> > >(); // Matrix4X<T>
    py::to_python_converter<Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>,
        eigen_matrix_to_numpy_array<Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> > >(); // MatrixX<T>
}

template <typename T>
void convertVector(bool isListConvertible = true)
{
    // python -> eigen
    numpy_array_to_eigen_vector<Eigen::Matrix<T, 2, 1> >(); // Vector2<T>
    numpy_array_to_eigen_vector<Eigen::Matrix<T, 3, 1> >(); // Vector3<T>
    numpy_array_to_eigen_vector<Eigen::Matrix<T, 4, 1> >(); // Vector4<T>
    numpy_array_to_eigen_vector<Eigen::Matrix<T, Eigen::Dynamic, 1> >(); // VectorX<T>

    if (isListConvertible) {
        python_list_to_eigen_vector<Eigen::Matrix<T, 2, 1> >(); // Vector2<T>
        python_list_to_eigen_vector<Eigen::Matrix<T, 3, 1> >(); // Vector3<T>
        python_list_to_eigen_vector<Eigen::Matrix<T, 4, 1> >(); // Vector4<T>
        python_list_to_eigen_vector<Eigen::Matrix<T, Eigen::Dynamic, 1> >(); // VectorX<T>
    }

    // eigen -> python
    py::to_python_converter<Eigen::Matrix<T, 2, 1>, eigen_vector_to_numpy_array<Eigen::Matrix<T, 2, 1> > >(); // Vector2<T>
    py::to_python_converter<Eigen::Matrix<T, 3, 1>, eigen_vector_to_numpy_array<Eigen::Matrix<T, 3, 1> > >(); // Vector3<T>
    py::to_python_converter<Eigen::Matrix<T, 4, 1>, eigen_vector_to_numpy_array<Eigen::Matrix<T, 4, 1> > >(); // Vector4<T>
    py::to_python_converter<Eigen::Matrix<T, Eigen::Dynamic, 1>, eigen_vector_to_numpy_array<Eigen::Matrix<T, Eigen::Dynamic, 1> > >(); // VectorX<T>
}

template <typename T>
void convertRowVector(bool isListConvertible = true)
{
    // python -> eigen
    numpy_array_to_eigen_vector<Eigen::Matrix<T, 1, 2> >(); // RowVector2<T>
    numpy_array_to_eigen_vector<Eigen::Matrix<T, 1, 3> >(); // RowVector3<T>
    numpy_array_to_eigen_vector<Eigen::Matrix<T, 1, 4> >(); // RowVector4<T>
    numpy_array_to_eigen_vector<Eigen::Matrix<T, 1, Eigen::Dynamic> >(); // RowVectorX<T>

    if (isListConvertible) {
        python_list_to_eigen_vector<Eigen::Matrix<T, 1, 2> >(); // RowVector2<T>
        python_list_to_eigen_vector<Eigen::Matrix<T, 1, 3> >(); // RowVector3<T>
        python_list_to_eigen_vector<Eigen::Matrix<T, 1, 4> >(); // RowVector4<T>
        python_list_to_eigen_vector<Eigen::Matrix<T, 1, Eigen::Dynamic> >(); // RowVectorX<T>
    }

    // eigen -> python
    py::to_python_converter<Eigen::Matrix<T, 1, 2>, eigen_vector_to_numpy_array<Eigen::Matrix<T, 1, 2> > >(); // RowVector2<T>
    py::to_python_converter<Eigen::Matrix<T, 1, 3>, eigen_vector_to_numpy_array<Eigen::Matrix<T, 1, 3> > >(); // RowVector3<T>
    py::to_python_converter<Eigen::Matrix<T, 1, 4>, eigen_vector_to_numpy_array<Eigen::Matrix<T, 1, 4> > >(); // RowVector4<T>
    py::to_python_converter<Eigen::Matrix<T, 1, Eigen::Dynamic>, eigen_vector_to_numpy_array<Eigen::Matrix<T, 1, Eigen::Dynamic> > >(); // RowVectorX<T>
}

template <typename T>
void convertEigen(Converters convert, bool isListConvertible = true)
{
    if (convert & Converters::Matrix)
        convertMatrix<T>(isListConvertible);
    if (convert & Converters::Vector)
        convertVector<T>(isListConvertible);
    if (convert & Converters::RowVector)
        convertRowVector<T>(isListConvertible);
}

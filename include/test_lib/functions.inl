
// Matrix relative
template <typename T>
RandomDynamicSizeMatrix<T>::RandomDynamicSizeMatrix(Eigen::Index row, Eigen::Index col)
    : mat_(EigenType::Random(row, col))
{
}

template <typename T>
typename RandomDynamicSizeMatrix<T>::EigenType RandomDynamicSizeMatrix<T>::get()
{
    return mat_;
}

template <typename T>
bool RandomDynamicSizeMatrix<T>::check(const EigenType& mat)
{
    return mat_.isApprox(mat);
}

template <typename T>
RandomFixedSizeMatrix<T>::RandomFixedSizeMatrix()
    : mat_(EigenType::Random())
{
}

template <typename T>
typename RandomFixedSizeMatrix<T>::EigenType RandomFixedSizeMatrix<T>::get()
{
    return mat_;
}

template <typename T>
bool RandomFixedSizeMatrix<T>::check(const EigenType& mat)
{
    return mat_.isApprox(mat);
}

template <typename T>
RandomHalfDynamicSizeMatrix<T>::RandomHalfDynamicSizeMatrix(Eigen::Index col)
    : mat_(EigenType::Random(2, col))
{
}

template <typename T>
typename RandomHalfDynamicSizeMatrix<T>::EigenType RandomHalfDynamicSizeMatrix<T>::get()
{
    return mat_;
}

template <typename T>
bool RandomHalfDynamicSizeMatrix<T>::check(const EigenType& mat)
{
    return mat_.isApprox(mat);
}

// Vector relative
template <typename T>
RandomDynamicSizeVector<T>::RandomDynamicSizeVector(Eigen::Index row)
    : vec_(EigenType::Random(row))
{
}

template <typename T>
typename RandomDynamicSizeVector<T>::EigenType RandomDynamicSizeVector<T>::get()
{
    return vec_;
}

template <typename T>
bool RandomDynamicSizeVector<T>::check(const EigenType& vec)
{
    return vec_.isApprox(vec);
}

template <typename T>
RandomDynamicSizeRowVector<T>::RandomDynamicSizeRowVector(Eigen::Index col)
    : vec_(EigenType::Random(col))
{
}

template <typename T>
typename RandomDynamicSizeRowVector<T>::EigenType RandomDynamicSizeRowVector<T>::get()
{
    return vec_;
}

template <typename T>
bool RandomDynamicSizeRowVector<T>::check(const EigenType& vec)
{
    return vec_.isApprox(vec);
}

template <typename T>
RandomFixedSizeVector<T>::RandomFixedSizeVector()
    : vec_(EigenType::Random())
{
}

template <typename T>
typename RandomFixedSizeVector<T>::EigenType RandomFixedSizeVector<T>::get()
{
    return vec_;
}

template <typename T>
bool RandomFixedSizeVector<T>::check(const EigenType& vec)
{
    return vec_.isApprox(vec);
}

template <typename T>
RandomFixedSizeRowVector<T>::RandomFixedSizeRowVector()
    : vec_(EigenType::Random())
{
}

template <typename T>
typename RandomFixedSizeRowVector<T>::EigenType RandomFixedSizeRowVector<T>::get()
{
    return vec_;
}

template <typename T>
bool RandomFixedSizeRowVector<T>::check(const EigenType& vec)
{
    return vec_.isApprox(vec);
}

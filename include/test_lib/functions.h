
#pragma once

#include <Eigen/Core>

// Matrix relative
template <typename T>
class RandomDynamicSizeMatrix {
public:
    using EigenType = Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>;

public:
    RandomDynamicSizeMatrix(Eigen::Index row, Eigen::Index col);

    EigenType get();
    bool check(const EigenType& mat);

private:
    EigenType mat_;
};

template <typename T>
class RandomFixedSizeMatrix {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
public:
    using EigenType = Eigen::Matrix<T, 4, 4>;

public:
    RandomFixedSizeMatrix();

    EigenType get();
    bool check(const EigenType& mat);

private:
    EigenType mat_;
};

template <typename T>
class RandomHalfDynamicSizeMatrix {
public:
    using EigenType = Eigen::Matrix<T, 4, Eigen::Dynamic>;

public:
    RandomHalfDynamicSizeMatrix(Eigen::Index col);

    EigenType get();
    bool check(const EigenType& mat);

private:
    EigenType mat_;
};

// Vector relative
template <typename T>
class RandomDynamicSizeVector {
public:
    using EigenType = Eigen::Matrix<T, Eigen::Dynamic, 1>;

public:
    RandomDynamicSizeVector(Eigen::Index row);

    EigenType get();
    bool check(const EigenType& vec);

private:
    EigenType vec_;
};

template <typename T>
class RandomDynamicSizeRowVector {
public:
    using EigenType = Eigen::Matrix<T, 1, Eigen::Dynamic>;

public:
    RandomDynamicSizeRowVector(Eigen::Index col);

    EigenType get();
    bool check(const EigenType& vec);

private:
    EigenType vec_;
};

template <typename T>
class RandomFixedSizeVector {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
public:
    using EigenType = Eigen::Matrix<T, 4, 1>;

public:
    RandomFixedSizeVector();

    EigenType get();
    bool check(const EigenType& vec);

private:
    EigenType vec_;
};

template <typename T>
class RandomFixedSizeRowVector {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
public:
    using EigenType = Eigen::Matrix<T, 1, 4>;

public:
    RandomFixedSizeRowVector();

    EigenType get();
    bool check(const EigenType& vec);

private:
    EigenType vec_;
};

#include "functions.inl"
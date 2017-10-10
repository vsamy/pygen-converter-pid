#include "functions.h"

// Matrix relative
RandomDynamicSizeMatrix::RandomDynamicSizeMatrix(Eigen::Index row, Eigen::Index col)
    : mat_(Eigen::MatrixXd::Random(row, col))
{
}

Eigen::MatrixXd RandomDynamicSizeMatrix::get()
{
    return mat_;
}

bool RandomDynamicSizeMatrix::check(const Eigen::MatrixXd& mat)
{
    return mat_.isApprox(mat);
}

RandomFixedSizeMatrix::RandomFixedSizeMatrix()
    : mat_(Eigen::Matrix3d::Random())
{
}

Eigen::Matrix3d RandomFixedSizeMatrix::get()
{
    return mat_;
}

bool RandomFixedSizeMatrix::check(const Eigen::Matrix3d& mat)
{
    return mat_.isApprox(mat);
}

RandomHalfDynamicSizeMatrix::RandomHalfDynamicSizeMatrix(Eigen::Index col)
    : mat_(Eigen::Matrix2Xd::Random(2, col))
{
}

Eigen::Matrix2Xd RandomHalfDynamicSizeMatrix::get()
{
    return mat_;
}

bool RandomHalfDynamicSizeMatrix::check(const Eigen::Matrix2Xd& mat)
{
    return mat_.isApprox(mat);
}

// Vector relative
RandomDynamicSizeVector::RandomDynamicSizeVector(Eigen::Index row)
    : vec_(Eigen::VectorXd::Random(row))
{
}

Eigen::VectorXd RandomDynamicSizeVector::get()
{
    return vec_;
}

bool RandomDynamicSizeVector::check(const Eigen::VectorXd& vec)
{
    return vec_.isApprox(vec);
}

RandomDynamicSizeRowVector::RandomDynamicSizeRowVector(Eigen::Index col)
    : vec_(Eigen::RowVectorXd::Random(col))
{
}

Eigen::RowVectorXd RandomDynamicSizeRowVector::get()
{
    return vec_;
}

bool RandomDynamicSizeRowVector::check(const Eigen::RowVectorXd& vec)
{
    return vec_.isApprox(vec);
}

RandomFixedSizeVector::RandomFixedSizeVector()
    : vec_(Eigen::Vector3d::Random())
{
}

Eigen::Vector3d RandomFixedSizeVector::get()
{
    return vec_;
}

bool RandomFixedSizeVector::check(const Eigen::Vector3d& vec)
{
    return vec_.isApprox(vec);
}

RandomFixedSizeRowVector::RandomFixedSizeRowVector()
    : vec_(Eigen::RowVector3d::Random())
{
}

Eigen::RowVector3d RandomFixedSizeRowVector::get()
{
    return vec_;
}

bool RandomFixedSizeRowVector::check(const Eigen::RowVector3d& vec)
{
    return vec_.isApprox(vec);
}

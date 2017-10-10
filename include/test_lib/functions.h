
#pragma once

#include <Eigen/Core>

// Matrix relative
class RandomDynamicSizeMatrix {
public:
    RandomDynamicSizeMatrix(Eigen::Index row, Eigen::Index col);

    Eigen::MatrixXd get();
    bool check(const Eigen::MatrixXd& mat);

private:
    Eigen::MatrixXd mat_;
};

class RandomFixedSizeMatrix {
public:
    RandomFixedSizeMatrix();

    Eigen::Matrix3d get();
    bool check(const Eigen::Matrix3d& mat);

private:
    Eigen::Matrix3d mat_;
};

class RandomHalfDynamicSizeMatrix {
public:
    RandomHalfDynamicSizeMatrix(Eigen::Index col);

    Eigen::Matrix2Xd get();
    bool check(const Eigen::Matrix2Xd& mat);

private:
    Eigen::Matrix2Xd mat_;
};

// Vector relative
class RandomDynamicSizeVector {
public:
    RandomDynamicSizeVector(Eigen::Index row);

    Eigen::VectorXd get();
    bool check(const Eigen::VectorXd& vec);

private:
    Eigen::VectorXd vec_;
};

class RandomDynamicSizeRowVector {
public:
    RandomDynamicSizeRowVector(Eigen::Index col);

    Eigen::RowVectorXd get();
    bool check(const Eigen::RowVectorXd& vec);

private:
    Eigen::RowVectorXd vec_;
};

class RandomFixedSizeVector {
public:
    RandomFixedSizeVector();

    Eigen::Vector3d get();
    bool check(const Eigen::Vector3d& vec);

private:
    Eigen::Vector3d vec_;
};

class RandomFixedSizeRowVector {
public:
    RandomFixedSizeRowVector();

    Eigen::RowVector3d get();
    bool check(const Eigen::RowVector3d& vec);

private:
    Eigen::RowVector3d vec_;
};

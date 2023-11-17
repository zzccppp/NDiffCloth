
#ifndef NDIFFCLOTH_TYPEDEFS_HEADER
#define NDIFFCLOTH_TYPEDEFS_HEADER

#include <Eigen/Core>
#include <utility>

typedef unsigned int Index;
typedef Eigen::VectorXd VecXd;
typedef Eigen::VectorXi VecXi;
typedef Eigen::Vector2i Vec2i;
typedef Eigen::Vector3i Vec3i;
typedef Eigen::Vector2d Vec2d;
typedef Eigen::Vector3d Vec3d;
typedef Eigen::Vector4d Vec4d;

typedef Eigen::Matrix<double, 5, 1> Vec5d;
typedef Eigen::Matrix<double, 6, 1> Vec6d;
typedef Eigen::Matrix<double, 9, 1> Vec9d;
typedef Eigen::Matrix<double, 12, 1> Vec12d;
typedef Eigen::Matrix<double, 12, 12> Mat12x12d;

typedef Eigen::MatrixXd MatXd;
typedef Eigen::MatrixXi MatXi;
typedef Eigen::Matrix<int, 2, 2> Mat2x2i;
typedef Eigen::Matrix<double, 1, 1> Mat1x1d;
typedef Eigen::Matrix<double, 2, 2> Mat2x2d;
typedef Eigen::Matrix<double, 2, 3> Mat2x3d;
typedef Eigen::Matrix<double, 3, 1> Mat3x1d;
typedef Eigen::Matrix<double, 3, 2> Mat3x2d;
typedef Eigen::Matrix<double, 3, 3> Mat3x3d;
typedef Eigen::Matrix<double, 3, 4> Mat3x4d;
typedef Eigen::Matrix<double, 3, 5> Mat3x5d;
typedef Eigen::Matrix<double, 3, 6> Mat3x6d;
typedef Eigen::Matrix<double, 3, 9> Mat3x9d;
typedef Eigen::Matrix<double, 3, 12> Mat3x12d;
typedef Eigen::Matrix<double, 4, 4> Mat4x4d;
typedef Eigen::Matrix<double, 4, 6> Mat4x6d;
typedef Eigen::Matrix<double, 4, 9> Mat4x9d;
typedef Eigen::Matrix<double, 5, 3> Mat5x3d;
typedef Eigen::Matrix<double, 6, 3> Mat6x3d;
typedef Eigen::Matrix<double, 6, 4> Mat6x4d;
typedef Eigen::Matrix<double, 6, 6> Mat6x6d;
typedef Eigen::Matrix<double, 6, 9> Mat6x9d;
typedef Eigen::Matrix<double, 9, 9> Mat9x9d;

typedef Eigen::SparseMatrix<double> SpMat;
typedef Eigen::Triplet<double> Triplet;
typedef std::vector<Eigen::Triplet<double>> TripleVector;
typedef Eigen::Transform<double, 3, Eigen::Affine> Rotation;

struct AABB {   // axis-aligned bounding box
    Vec3d min;
    Vec3d max;

    AABB() {
        min.setZero();
        max.setZero();
    }

    AABB(Vec3d min, Vec3d max) : min(std::move(min)), max(std::move(max)){};
};

#endif

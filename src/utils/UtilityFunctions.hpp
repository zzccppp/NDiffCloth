#ifndef NDIFFCLOTH_UTILS_UTILITY_FUNCTIONS_HEADER
#define NDIFFCLOTH_UTILS_UTILITY_FUNCTIONS_HEADER

#include "TypeDef.hpp"
#include <iomanip>
#include <string>
#include <vector>

namespace utils {
/**
 * @brief
 *
 * @tparam m dimension of the vector
 * @param v vector to be converted
 * @param precision precision of the output string, default is 2
 * @return std::string
 */
template <int m>
static std::string
vec2str(const Eigen::Matrix<double, m, 1> &v, int precision = 2) {
    std::ostringstream streamObj3;
    streamObj3 << std::fixed;
    streamObj3 << std::setprecision(precision);
    streamObj3 << "(" << v[0];

    for (int i = 1; i < m; i++)
        streamObj3 << "," << v[i];

    streamObj3 << ")";

    return streamObj3.str();
}

template <int m, int n, int p, int q>
static Eigen::Matrix<double, m * p, n * q>
kronecker(const Eigen::Matrix<double, m, n> &A,
          const Eigen::Matrix<double, p, q> &B) {
    Eigen::Matrix<double, m * p, n * q> C;
    C.setZero();
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < p; k++)
                for (int l = 0; l < q; l++)
                    C(i * p + k, j * q + l) = A(i, j) * B(k, l);

    return C;
}

template <int rows, int cols>
static void
insertIntoTriplets(TripleVector &triplets,
                   Eigen::Matrix<double, rows, cols> &src, int blockRows,
                   int blockCols, int srcStartRows, int srcStartCols,
                   int dstStartRow, int dstStartCol) {
    for (int i = 0; i < blockRows; i++) {
        for (int j = 0; j < blockCols; j++) {
            double val = src(srcStartRows + i, srcStartCols + j);
            if (std::abs(val) > 1e-12) {
                triplets.emplace_back(dstStartRow + i, dstStartCol + j, val);
            }
        }
    }
}

}   // namespace utils
#endif
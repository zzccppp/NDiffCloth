#ifndef NDIFFCLOTH_FILE_READER_HEADER
#define NDIFFCLOTH_FILE_READER_HEADER

#include "TypeDef.hpp"
#include <iomanip>
#include <string>
#include <vector>

namespace utils {

/**
 * @brief Load the obj file and store the vertices and triangles in the given
 * vectors.
 *
 * @param filename input obj file name
 * @param vertices output vertices
 * @param triangles output triangles
 * @return true if success
 * @return false if fail
 */
bool loadOBJFile(const std::string &filename, std::vector<Vec3d> &vertices,
                 std::vector<Vec3i> &triangles);

}   // namespace utils

#endif
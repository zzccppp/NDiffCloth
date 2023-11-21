#ifndef NDIFFCLOTH_FILE_READER_HEADER
#define NDIFFCLOTH_FILE_READER_HEADER

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
 * @return true
 * @return false
 */
bool loadOBJFile(const std::string &filename, std::vector<double> &vertices,
                 std::vector<int> &triangles);
}   // namespace utils

#endif
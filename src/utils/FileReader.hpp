#ifndef NDIFFCLOTH_FILE_READER_HEADER
#define NDIFFCLOTH_FILE_READER_HEADER

#include <string>
#include <vector>

namespace utils {
bool loadOBJFile(const std::string &filename, std::vector<double> &vertices,
                 std::vector<int> &triangles);
}

#endif
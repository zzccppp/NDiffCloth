#include "FileReader.hpp"

#include <cstdio>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

namespace utils {

bool
loadOBJFile(const std::string &filename, std::vector<double> &posVec,
            std::vector<int> &triVec) {
    FILE *file = fopen(filename.c_str(), "rb");
    if (!file) {
        std::cerr << "file not exist:" << filename << std::endl;
        return false;
    }

    bool has_normal = false;
    bool has_texture = false;
    char line_buffer[2000];
    while (fgets(line_buffer, 2000, file)) {
        char *first_token = strtok(line_buffer, "\r\n\t ");
        if (!first_token || first_token[0] == '#' || first_token[0] == 0)
            continue;

        switch (first_token[0]) {
        case 'v': {
            if (first_token[1] == 'n') {
                strtok(nullptr, "\t ");
                strtok(nullptr, "\t ");
                strtok(nullptr, "\t ");
                has_normal = true;
            } else if (first_token[1] == 't') {
                strtok(nullptr, "\t ");
                strtok(nullptr, "\t ");
                has_texture = true;
            } else {
                double x = atof(strtok(nullptr, "\t "));
                double y = atof(strtok(nullptr, "\t "));
                double z = atof(strtok(nullptr, "\t "));

                posVec.emplace_back(x, y, z);
            }
        } break;
        case 'f': {
            //        Triangle tri;
            int vIdx[3];
            char *data[30];
            int n = 0;
            while ((data[n] = strtok(nullptr, "\t \r\n")) != nullptr) {
                if (strlen(data[n]))
                    n++;
            }

            for (int t = 0; t < (n - 2); ++t) {
                if ((!has_texture) && (!has_normal)) {
                    vIdx[0] = atoi(data[0]) - 1;
                    vIdx[1] = atoi(data[1]) - 1;
                    vIdx[2] = atoi(data[2]) - 1;
                } else {
                    const char *v1;
                    for (int i = 0; i < 3; i++) {
                        // vertex ID
                        if (i == 0)
                            v1 = data[0];
                        else
                            v1 = data[t + i];

                        vIdx[i] = atoi(v1) - 1;
                    }
                }
                triVec.emplace_back(vIdx[0], vIdx[1], vIdx[2]);
            }
        }
        }
    }

    fclose(file);

    std::printf("Finished loading obj file %s: vertex %zu triangles: %zu\n",
                filename.c_str(), posVec.size(), triVec.size());
}
}   // namespace utils
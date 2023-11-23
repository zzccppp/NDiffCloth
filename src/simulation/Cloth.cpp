#include "Cloth.hpp"
#include "utils/FileReader.hpp"
#include "utils/UtilityFunctions.hpp"
#include <iostream>

using simulation::Cloth;
using utils::vec2str;

bool
Cloth::initialize() {
    // init all parameters
    std::string path = this->config.objPath;
    bool flag = utils::loadOBJFile(path, this->modelPoints, this->modelTris);
    if (!flag) {
        std::cerr << "load obj file failed" << std::endl;
        return false;
    }
    std::cout << this->modelPoints.size() << " vertices and "
              << this->modelTris.size() << " triangles loaded from " << path
              << std::endl;
    this->num = this->modelPoints.size();

    // TODO rotate points here

    Vec3d minDim = modelPoints[0], maxDim = modelPoints[0];
    for (Vec3d &p : modelPoints) {
        for (int i = 0; i < 3; i++) {
            minDim[i] = std::min(minDim[i], p[i]);
            maxDim[i] = std::max(maxDim[i], p[i]);
        }
    }
    std::printf("Bounding box min:%s max:%s\n", vec2str(minDim, 3).c_str(),
                vec2str(maxDim, 3).c_str());

    // TODO scale points here
    bool keepOriginalScalePoint = false;
    double clothDimX = 40;
    Vec3d restShapeMinDim, restShapeMaxDim, restShapeMidPoint,
        meshInitTransofrmMinDim;
    Vec3d dim = maxDim - minDim;

    double scale = keepOriginalScalePoint
                       ? 1.0
                       : std::max(std::max(dim[0], dim[1]), dim[2]) / clothDimX;

    if (keepOriginalScalePoint) {
        restShapeMaxDim = maxDim;
        restShapeMinDim = minDim;
    } else {
        restShapeMaxDim = maxDim - minDim;
        restShapeMaxDim /= scale;
        restShapeMinDim = Vec3d(0, 0, 0);
    }

    Vec3d translation =
        keepOriginalScalePoint ? Vec3d(0, 0, 0) : restShapeMaxDim / 2.0;
    restShapeMinDim -= translation;
    restShapeMaxDim -= translation;
    meshInitTransofrmMinDim = minDim;
    restShapeMidPoint = 0.5 * (restShapeMinDim + restShapeMaxDim);

    for (Vec3d &p : modelPoints) {
        if (std::isnan(p[0]) || std::isnan(p[1]) || std::isnan(p[2])) {
            std::printf("encountered NAN pos (%.3f, %.3f, %.3f) when loading "
                        "vertex number %zu from file\n",
                        p[0], p[1], p[2], particles.size());
        }
        Vec3d normalizedPos =
            keepOriginalScalePoint ? p : (p - minDim) / scale - restShapeMaxDim;
        int idx = particles.size();
        particles.emplace_back(1, normalizedPos, normalizedPos, Vec3d(0, 0, 0),
                               Vec2i(0, 0), idx);
        particleTriangleMap.emplace_back(std::vector<int>());
    }

    pointpointConnectionTable.resize(
        particles.size(), std::vector<bool>(particles.size(), false));

    for (Vec3i &t : modelTris) {
        mesh.emplace_back(t[0], t[1], t[2], particles, true);
        particleTriangleMap[t[0]].emplace_back(mesh.size() - 1);
        particleTriangleMap[t[1]].emplace_back(mesh.size() - 1);
        particleTriangleMap[t[2]].emplace_back(mesh.size() - 1);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                pointpointConnectionTable[t[i]][t[j]] = true;
            }
    }

    for (int i = 0; i < particles.size(); i++) {
        assert(particles[i].idx == i);
    }

    // createAttachments(true);

    // updateBackwardDefaultInfo();   // resize vectors whose length is
    //                                // parameter-dependent

    // init constraints
    return true;
}
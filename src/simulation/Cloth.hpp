#ifndef NDIFFCLOTH_CLOTH_HEADER
#define NDIFFCLOTH_CLOTH_HEADER

#include "simulation/Constraint.hpp"
#include "simulation/Particle.hpp"
#include "simulation/Triangle.hpp"
#include "utils/TypeDef.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace simulation {

/**
 * @brief Cloth configuration.
 *
 */
struct ClothConfig {
    string name;
    string objPath;
    double kStretch;
    double kBend;
    double density;
};

/**
 * @brief Class to describe cloth parameters, constraints and motion.
 */
class Cloth {
  public:
    /**
     * @brief number of particles
     */
    int num;
    /**
     * @brief positions of particles
     */
    vector<Vec3d> p;
    /**
     * @brief velocities of particles
     */
    vector<Vec3d> v;
    /**
     * @brief external forces of particles
     */
    VecXd fext;
    /**
     * @brief triangles of the cloth
     */
    vector<Vec3i> tri;

    /**
     * @brief mass of particles
     */
    MatXd M;
    /**
     * @brief inverse mass of particles
     */
    MatXd Minv;

    std::vector<Vec3d> modelPoints;
    std::vector<Vec3i> modelTris;

    std::vector<Particle> particles;
    std::vector<std::vector<int>> particleTriangleMap;
    std::vector<Triangle> mesh;
    std::vector<std::vector<bool>> pointpointConnectionTable;

    ClothConfig config;
    vector<Constraint *> constraints;

    Cloth(ClothConfig cf) : config(cf) {}
    ~Cloth() {}

    bool initialize();
};
}   // namespace simulation

#endif

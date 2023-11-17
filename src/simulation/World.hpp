#ifndef NDIFFCLOTH_WORLD_HEADER
#define NDIFFCLOTH_WORLD_HEADER

#include "Cloth.hpp"
#include "dynamics/ClothPD.hpp"
#include "dynamics/ClothVanilla.hpp"
#include "utils/TypeDef.hpp"

namespace simulation {
/* Class to store objects and simulation parameters.
 */
class World {
  public:
    double timeStep;
    Vec3d gravity;
    vector<Cloth> cloths;
    int numCloths = 0;

    VecXd p;   // total positions
    VecXd v;   // total velocities

    dynamics::ClothVanilla vanilla;
    dynamics::ClothPD PD;

    World(double ts = 0.05, Vec3d g = Vec3d(0.0, 0.0, -9.81)) {
        timeStep = ts;
        gravity = g;
        vanilla = dynamics::ClothVanilla(this);
        PD = dynamics::ClothPD(this);
    }
    ~World() {}

    void loadCloth(ClothConfig cf);

    void step();
};
}   // namespace simulation

#endif

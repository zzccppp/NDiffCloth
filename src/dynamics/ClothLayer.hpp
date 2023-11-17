#ifndef NDIFFCLOTH_CLOTHLAYER_HEADER
#define NDIFFCLOTH_CLOTHLAYER_HEADER

#include "simulation/Cloth.hpp"
// #include "simulation/World.hpp"
#include "utils/TypeDef.hpp"

using namespace std;
using namespace simulation;

namespace simulation {
class World;
}

namespace dynamics {
/* Temporal Class to solve single cloth dynamics.
 * Further design for auto-gradient
 */
class ClothLayer {
  public:
    World *world;
    double h;   // time step

    ClothLayer(World *w);
    ~ClothLayer() {}

    virtual VecXd forward(Cloth *cloth) = 0;
};
}   // namespace dynamics

#endif

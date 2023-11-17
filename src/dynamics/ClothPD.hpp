#ifndef NDIFFCLOTH_CLOTHPD_HEADER
#define NDIFFCLOTH_CLOTHPD_HEADER

#include "ClothLayer.hpp"
#include "simulation/Cloth.hpp"
#include "utils/TypeDef.hpp"

using namespace std;
using namespace simulation;

namespace simulation {
class World;
}

namespace dynamics {
/* ClothLayer for constraint-free dynamics
 */
class ClothPD : public ClothLayer {
  public:
    ClothPD() : ClothLayer(nullptr) {
        world = nullptr;
        h = 0.0;
    }
    ClothPD(World *w) : ClothLayer(w) {}
    ~ClothPD() {}

    VecXd forward(Cloth *cloth) override {
        // TODO
        return VecXd();
    }
};
}   // namespace dynamics

#endif

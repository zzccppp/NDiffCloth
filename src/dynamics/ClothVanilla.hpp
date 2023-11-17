#ifndef NDIFFCLOTH_CLOTHVANILLA_HEADER
#define NDIFFCLOTH_CLOTHVANILLA_HEADER

#include "ClothLayer.hpp"
#include "simulation/Cloth.hpp"
#include "utils/TypeDef.hpp"

namespace simulation {
class World;
}

namespace dynamics {
/* ClothLayer for constraint-free dynamics
 */
class ClothVanilla : public ClothLayer {
  public:
    ClothVanilla() : ClothLayer(nullptr) {
        world = nullptr;
        h = 0.0;
    }
    ClothVanilla(World *w) : ClothLayer(w) {}
    ~ClothVanilla() {}

    VecXd forward(Cloth *cloth) override {
        VecXd p_new = cloth->p;
        p_new += h * cloth->v;
        p_new += h * h * cloth->Minv * cloth->fext;
        VecXd v_new = (p_new - cloth->p) / h;

        cloth->p = p_new;
        cloth->v = v_new;

        return p_new;
    }
};
}   // namespace dynamics

#endif

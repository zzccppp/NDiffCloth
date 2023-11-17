#ifndef NDIFFCLOTH_CLOTHPD_HEADER
#define NDIFFCLOTH_CLOTHPD_HEADER

#include "ClothLayer.hpp"
#include "simulation/World.hpp"
#include "simulation/Cloth.hpp"
#include "utils/TypeDef.hpp"

using namespace std;
using namespace simulation;

namespace dynamics
{
    /* ClothLayer for constraint-free dynamics
    */
    class ClothPD : public ClothLayer
    {
    public:
        ClothPD(World* w) : ClothLayer(w) {}
        ~ClothPD() {}

        VecXd forward(Cloth* cloth) override
        {
            // TODO
        }
    };
}

#endif

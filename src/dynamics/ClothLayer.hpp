#ifndef NDIFFCLOTH_CLOTHLAYER_HEADER
#define NDIFFCLOTH_CLOTHLAYER_HEADER

#include "simulation/World.hpp"
#include "simulation/Cloth.hpp"
#include "utils/TypeDef.hpp"

using namespace std;
using namespace simulation;

namespace dynamics
{
    /* Temporal Class to solve single cloth dynamics. 
    * Further design for auto-gradient
    */
    class ClothLayer
    {
    public:
        World* world;
        double h; // time step

        ClothLayer(World* w) : world(w) { h = world->timeStep; }
        ~ClothLayer() {}

        virtual void forward(Cloth* cloth);
    };
}

#endif

#ifndef NDIFFCLOTH_WORLD_HEADER
#define NDIFFCLOTH_WORLD_HEADER

#include "Cloth.hpp"
#include "utils/TypeDef.hpp"
#include "dynamics/ClothVanilla.hpp"

using namespace std;
using namespace dynamics;

namespace simulation
{
    /* Class to store objects and simulation parameters. 
    */
    class World
    {
    public:
        double timeStep;
        Vec3d gravity;
        vector<Cloth*> cloths;
        int numCloths = 0;

        VecXd p; // total positions
        VecXd v; // total velocities

        ClothVanilla vanilla(this);
        ClothPD PD(this);
        
        World(double ts=0.05, Vec3d g=Vec3d(0.0, 0.0, -9.81)) : 
            timeStep(ts), gravity(g) {}
        ~World() {}

        void loadCloth(ClothConfig cf);

        void step();
    };
}

#endif

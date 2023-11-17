#ifndef NDIFFCLOTH_CLOTH_HEADER
#define NDIFFCLOTH_CLOTH_HEADER

#include "Constaint.hpp"
#include "utils/TypeDef.hpp"

using namespace std;

namespace simulation
{   
    struct ClothConfig {
        string name;
        string objDir;
        double kStretch;
        double kBend;
        double density;
    };

    /* Class to describe cloth parameters, constraints and motion. 
    */
    class Cloth
    {
    public:
        int num; // particle number
        VecXd p; // positions
        VecXd v; // velocities
        VecXd fext; // external forces
        MatXi tri; // triangles

        MatXd M; // mass matrix
        MatXd Minv; // inverse mass matrix

        ClothConfig config;
        vector<Constraint*> constraints;

        Cloth(ClothConfig cf) : config(cf) { initialize(); }
        ~Cloth() {}

        void initialize();
    };
}

#endif

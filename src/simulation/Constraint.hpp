#ifndef NDIFFCLOTH_CONSTRAINT_HEADER
#define NDIFFCLOTH_CONSTRAINT_HEADER

#include "utils/TypeDef.hpp"

using namespace std;

namespace simulation
{
    enum ConstraintType {
            CONSTRAINT_SPRING_STRETCH,
            CONSTRAINT_ATTACHMENT,
            CONSTRAINT_TRIANGLE,
            CONSTRAINT_TRIANGLE_BENDING,
            CONSTRAINT_NUM
        };

    /* Class to describe different types of constraints. 
    */
    class Constraint
    {
    public:
        ConstraintType constraintType;
        int constraintDim;
        double constraintWeight;

        Constraint(ConstraintType t) : constraintType(t) {}
        ~Constraint() {}
        
        virtual double evaluateEnergy(VecXd x);
        virtual VecXd project(VecXd x);
    };
}

#endif

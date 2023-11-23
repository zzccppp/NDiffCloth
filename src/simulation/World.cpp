#include "World.hpp"
#include "dynamics/ClothVanilla.hpp"

using namespace std;
using namespace simulation;



void
World::loadCloth(ClothConfig cf) {
    Cloth cloth(cf);
    if (cloth.initialize()) {
        numCloths += 1;
        cloths.push_back(cloth);
    }
}

void
World::step() {
    // vanilla layer
    for (auto cloth : cloths) {
        vanilla.forward(&cloth);
    }

    // PD layer
    for (auto cloth : cloths) {
        PD.forward(&cloth);
    }

    // dry friction layer

    // IPC layer
}
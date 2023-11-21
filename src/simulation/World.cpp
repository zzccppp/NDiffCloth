#include "World.hpp"
#include "dynamics/ClothVanilla.hpp"

using namespace std;
using namespace simulation;

// example cloth config for test
ClothConfig cfExample = {.name = "example",
                         .objPath = "",   // make a folder named example
                         .kStretch = 1.0,
                         .kBend = 1.0,
                         .density = 1.0};

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
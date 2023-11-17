#include "ClothLayer.hpp"
#include "simulation/World.hpp"

dynamics::ClothLayer::ClothLayer(simulation::World *w) {
    if (w == nullptr) {
        world = nullptr;
        h = 0.0;
        return;
    }
    world = w;
    h = w->timeStep;
}
#include "ClothLayer.hpp"
#include "simulation/World.hpp"

dynamics::ClothLayer::ClothLayer(simulation::World *w) {
    world = w;
    h = w->timeStep;
}
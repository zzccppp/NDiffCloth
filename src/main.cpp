#include <fstream>
#include <iostream>
#include <string>

#include "simulation/Cloth.hpp"
#include "utils/Configurations.hpp"

// example cloth config for test
simulation::ClothConfig cfExample = {.name = "example",
                                     .objPath =
                                         "/home/zzccppp/Codes/NDiffCloth/assets/meshes/remeshed/Hat/hat_target.obj",   // make a folder named example
                                     .kStretch = 1.0,
                                     .kBend = 1.0,
                                     .density = 1.0};

int
main(int argc, char **argv) {
    simulation::Cloth cloth(cfExample);

    // initialize cloth
    bool flag = cloth.initialize();
    if (!flag) {
        std::cerr << "initialize cloth failed" << std::endl;
        return 1;
    }
    std::cout << "initialize cloth success" << std::endl;
    return 0;
}

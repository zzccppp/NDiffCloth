#include <iostream>
#include <string>

#include "initialize/Configurations.hpp"

int
main(int argc, char **argv) {
    using json = nlohmann::json;
    std::cout << hatScene.dump_json_string() << std::endl;
    return 0;
}

#include <fstream>
#include <iostream>
#include <string>

#include "initialize/Configurations.hpp"

int
main(int argc, char **argv) {
    using json = nlohmann::json;
    std::ofstream out("test.json");
    out << hatScene.dump_json_string();
    out.close();
    return 0;
}

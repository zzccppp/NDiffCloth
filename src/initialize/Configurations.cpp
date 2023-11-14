#include "Configurations.hpp"

#include <iostream>
#include <string>

SceneConfiguration SceneConfiguration::load_json_string(const std::string& buf)
{
    std::cout << buf << std::endl;

    return SceneConfiguration();
}

std::string SceneConfiguration::dump_json_string() const
{
    std::string yml_string;

    return yml_string;
}

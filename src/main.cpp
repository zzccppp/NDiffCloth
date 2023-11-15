#include <iostream>
#include <string>

#include "initialize/Configurations.hpp"

void test_gen_yaml() {}

int main(int argc, char **argv) {
  using json = nlohmann::json;
  json j = hatScene;
  std::cout << to_string(j);
  return 0;
}

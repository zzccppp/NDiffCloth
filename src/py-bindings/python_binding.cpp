#include "initialize/Configurations.hpp"
#include "pybind11/pybind11.h"

namespace py = pybind11;

int
add(int i, int j) {
    return i + j;
}

PYBIND11_MODULE(ndf, m) {
    m.doc() = "pybind11 example plugin";

    m.def("add", &add, "A function which adds two numbers");

    py::class_<conf::SceneConfiguration>(m, "SceneConfiguration")
        .def(py::init<>())
        .def_static("load_json_string", &conf::SceneConfiguration::load_json_string)
        .def("dump_json_string", &conf::SceneConfiguration::dump_json_string);
}

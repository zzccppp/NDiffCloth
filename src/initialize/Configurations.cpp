#include <iostream>
#include <string>

#include "3rdparty/json.hpp"
#include "Configurations.hpp"

using json = nlohmann::json;

conf::SceneConfiguration
conf::SceneConfiguration::load_json_string(const std::string &buf) {
    conf::SceneConfiguration scene;
    json::parse(buf).get_to(scene);
    return scene;
}

std::string
conf::SceneConfiguration::dump_json_string() const {
    json j2;
    to_json(j2, *this);
    return to_string(j2);
}

void
conf::to_json(json &j, const conf::SceneConfiguration &scene) {
    j = json{
        {"name", scene.name},
        {"fabric", scene.fabric},
        {"orientation", scene.orientation},
        {"upVector", scene.upVector},
        {"attachmentPoints", scene.attachmentPoints},
        {"customAttachmentVertexIdx", scene.customAttachmentVertexIdx},
        {"trajectory", scene.trajectory},
        {"primitiveConfig", scene.primitiveConfig},
        {"windConfig", scene.windConfig},
        {"camPos", scene.camPos},
        {"camFocusPos", scene.camFocusPos},
        {"sockLegOrientation", scene.sockLegOrientation},
        {"camFocusPointType", scene.camFocusPointType},
        {"sceneBbox", scene.sceneBbox},
        {"timeStep", scene.timeStep},
        {"stepNum", scene.stepNum},
        {"forwardConvergenceThresh", scene.forwardConvergenceThresh},
        {"backwardConvergenceThresh", scene.backwardConvergenceThresh},
    };
}

void
conf::from_json(const json &j, conf::SceneConfiguration &scene) {
    //        j.at("name").get_to(p.name);
    //        j.at("address").get_to(p.address);
    //        j.at("age").get_to(p.age);
    j.at("name").get_to(scene.name);
    j.at("fabric").get_to(scene.fabric);
    j.at("orientation").get_to(scene.orientation);
    j.at("upVector").get_to(scene.upVector);
    j.at("attachmentPoints").get_to(scene.attachmentPoints);
    j.at("customAttachmentVertexIdx").get_to(scene.customAttachmentVertexIdx);
    j.at("trajectory").get_to(scene.trajectory);
    j.at("primitiveConfig").get_to(scene.primitiveConfig);
    j.at("windConfig").get_to(scene.windConfig);
    j.at("camPos").get_to(scene.camPos);
    j.at("camFocusPos").get_to(scene.camFocusPos);
    j.at("sockLegOrientation").get_to(scene.sockLegOrientation);
    j.at("camFocusPointType").get_to(scene.camFocusPointType);
    j.at("sceneBbox").get_to(scene.sceneBbox);
    j.at("timeStep").get_to(scene.timeStep);
    j.at("stepNum").get_to(scene.stepNum);
    j.at("forwardConvergenceThresh").get_to(scene.forwardConvergenceThresh);
    j.at("backwardConvergenceThresh").get_to(scene.backwardConvergenceThresh);
}

void
Eigen::to_json(json &j, const Vec3d &vec) {
    std::array<double, 3> v = {vec[0], vec[1], vec[2]};
    j = v;
}

void
Eigen::from_json(const json &j, Vec3d &vec) {
    std::array<double, 3> v{};
    j.get_to(v);
    vec[0] = v[0];
    vec[1] = v[1];
    vec[2] = v[2];
}

void
to_json(json &j, const AABB &box) {
    j = json{{"min", box.min}, {"max", box.max}};
}

void
from_json(const json &j, AABB &box) {
    box.min = j.at("min").template get<Vec3d>();
    box.max = j.at("max").template get<Vec3d>();
}

void
conf::to_json(json &j, const conf::FabricConfiguration &fc) {
    j = json{
        {"clothDimX", fc.clothDimX},
        {"clothDimY", fc.clothDimY},
        {"k_stiff_stretching", fc.k_stiff_stretching},
        {"k_stiff_bending", fc.k_stiff_bending},
        {"gridNumX", fc.gridNumX},
        {"gridNumY", fc.gridNumY},
        {"density", fc.density},
        {"keepOriginalScalePoint", fc.keepOriginalScalePoint},
        {"isModel", fc.isModel},
        {"custominitPos", fc.custominitPos},
        {"initPosFile", fc.initPosFile},
        {"fabricIdx", fc.fabricIdx},
        {"color", fc.color},
        {"name", fc.name},
    };
}

void
conf::from_json(const json &j, conf::FabricConfiguration &vec) {
    j.at("clothDimX").get_to(vec.clothDimX);
    j.at("clothDimY").get_to(vec.clothDimY);
    j.at("k_stiff_stretching").get_to(vec.k_stiff_stretching);
    j.at("k_stiff_bending").get_to(vec.k_stiff_bending);
    j.at("gridNumX").get_to(vec.gridNumX);
    j.at("gridNumY").get_to(vec.gridNumY);
    j.at("density").get_to(vec.density);
    j.at("keepOriginalScalePoint").get_to(vec.keepOriginalScalePoint);
    j.at("isModel").get_to(vec.isModel);
    j.at("custominitPos").get_to(vec.custominitPos);
    j.at("initPosFile").get_to(vec.initPosFile);
    j.at("fabricIdx").get_to(vec.fabricIdx);
    j.at("color").get_to(vec.color);
    j.at("name").get_to(vec.name);
}

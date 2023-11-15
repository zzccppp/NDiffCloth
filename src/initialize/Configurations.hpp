#ifndef NDIFFCLOTH_CONFIGURATIONS_HEADER
#define NDIFFCLOTH_CONFIGURATIONS_HEADER

#include "3rdparty/json.hpp"
#include "defs/Constants.hpp"
#include "defs/TypeDefs.hpp"

namespace conf {
struct FabricConfiguration {
  double clothDimX;
  double clothDimY;
  double k_stiff_stretching;
  double k_stiff_bending;
  int gridNumX;
  int gridNumY;
  double density;
  bool keepOriginalScalePoint;
  bool isModel;
  bool custominitPos;
  std::string initPosFile;
  int fabricIdx; // in SimulationConstant::fabricArrays
  Vec3d color;
  std::string name; // if ismodel, this is the path to the mesh model; otherwise
                    // describes a fabric
};

struct SceneConfiguration {
  FabricConfiguration fabric; // in SimulationConstant::fabricArrs
  Orientation orientation;
  Vec3d upVector;
  AttachmentConfigs attachmentPoints;
  std::vector<std::pair<double, std::vector<int>>>
      customAttachmentVertexIdx; // outside loop: different sets; each element:
                                 // startFrame x vIdx
  TrajectoryConfigs trajectory;
  PrimitiveConfiguration primitiveConfig;
  WindConfig windConfig;
  Vec3d camPos;
  Vec3d camFocusPos;
  Vec3d sockLegOrientation;
  CameraFocusPointType camFocusPointType;
  AABB sceneBbox;
  double timeStep;
  int stepNum;
  double forwardConvergenceThresh;
  double backwardConvergenceThresh;
  std::string name;

  static SceneConfiguration load_json_string(const std::string &buf);

  std::string dump_json_string() const;
};

using json = nlohmann::json;

void to_json(json &j, const SceneConfiguration &scene);

void from_json(const json &j, SceneConfiguration &scene);

void to_json(json &j, const FabricConfiguration &fc);

void from_json(const json &j, FabricConfiguration &fc);

} // namespace conf

namespace Eigen {
void to_json(nlohmann::json &j, const Vec3d &vec);

void from_json(const nlohmann::json &j, Vec3d &vec);
} // namespace Eigen

void to_json(nlohmann::json &j, const AABB &box);

void from_json(const nlohmann::json &j, AABB &box);

const conf::FabricConfiguration agenthat579 = {
    .clothDimX = 6,
    .clothDimY = 6,
    .k_stiff_stretching =
        1200, // old param: 300 // TODO: WARNING: change back to 1200
    .k_stiff_bending =
        120,          // old param: 50 // TODO: WARNING: change back to 120
    .gridNumX = 40,   //
    .gridNumY = 80,   //
    .density = 0.224, // old param: 0.324
    .keepOriginalScalePoint = false,
    .isModel = true,
    .custominitPos = false,
    .fabricIdx = FabricEnumArray::AGENT_HAT579,
    .color = Vec3d(1, 0, 0),
    .name = "remeshed/agenthat2-579-rotated.obj",
};

const conf::SceneConfiguration hatScene = {
    .fabric = agenthat579,
    .orientation = Orientation::FRONT,
    .attachmentPoints = AttachmentConfigs::CUSTOM_ARRAY,
    .customAttachmentVertexIdx = {{0.0, {394, 32}}}, //{{0.0, {501}}},
    .trajectory = TrajectoryConfigs::CORNERS_2_WEARHAT,
    .primitiveConfig = PrimitiveConfiguration::PLANE_BUST_WEARHAT,
    .windConfig = WindConfig::NO_WIND,
    .camPos = Vec3d(-22.14, 9.24, 7.59),
    .camFocusPointType = CameraFocusPointType::CLOTH_CENTER,
    .sceneBbox = AABB(Vec3d(-5, -1.5, -14), Vec3d(7, 10, 5)),
    .timeStep = 1.0 / 100.0,
    .stepNum = 400,
    .forwardConvergenceThresh = 1e-8,
    .backwardConvergenceThresh = 5e-4,
    .name = "demo_wearhat"};

#endif
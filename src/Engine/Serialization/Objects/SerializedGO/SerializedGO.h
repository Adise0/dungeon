#pragma once
#include "../SerializedComponent/SerializedComponent.h"
#include "../SerializedTransform/SerializedTransform.h"
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

namespace Dungeon::Engine::Serialization {

using json = nlohmann::json;
class SerializedGO {
  // #region Data
public:
  int id;
  std::string name;
  SerializedTransform transform;
  std::vector<SerializedComponent> components;
  std::vector<SerializedGO> children;
  int refId = -1;
  // #endregion

  // #region Methods
public:
  json ToJson() {

    json componentJsons = json::array();
    for (SerializedComponent component : components) {
      componentJsons.push_back(component.ToJson());
    }

    json cheldrenJson = json::array();
    for (SerializedGO child : children) {
      cheldrenJson.push_back(child.ToJson());
    }

    return json{{"id", id},
                {"name", name},
                {"transform", transform.ToJson()},
                {"components", componentJsons},
                {"children", cheldrenJson},
                {"refId", refId}};
  }
  // #endregion
};
} // namespace Dungeon::Engine::Serialization

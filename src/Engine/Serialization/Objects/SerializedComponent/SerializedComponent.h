#pragma once
#include <nlohmann/json.hpp>
#include <string>

namespace Dungeon::Engine::Serialization {
using json = nlohmann::json;
class SerializedComponent {
  // #region Data
public:
  int id;
  std::string name;
  int gameObject;
  int refId = -1;
  //TODO: Component serialization
  // #endregion

  // #region Methods
public:
  json ToJson() {
    return json{{"id", id}, {"name", name}, {"gameObject", gameObject}, {"refId", refId}};
  }
  // #endregion
};
} // namespace Dungeon::Engine::Serialization

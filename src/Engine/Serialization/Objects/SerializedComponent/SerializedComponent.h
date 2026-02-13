#pragma once
#include <string>

namespace Dungeon::Engine::Serialization {

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

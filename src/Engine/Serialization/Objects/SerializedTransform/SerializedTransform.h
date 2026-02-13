
#pragma once
#include <string>
#include <vector>

namespace Dungeon::Engine::Serialization {
class SerializedTransform {
  // #region Data
public:
  int id;
  std::string position;
  float rotation;
  std::string scale;
  int gameObject;
  int refid = -1;
  // #endregion

  // #region Methods
public:
  json ToJson() {
    return json{{"id", id},       {"position", position},     {"rotation", rotation},
                {"scale", scale}, {"gameObject", gameObject}, {"refid", refid}};
  }
  // #endregion
};
} // namespace Dungeon::Engine::Serialization

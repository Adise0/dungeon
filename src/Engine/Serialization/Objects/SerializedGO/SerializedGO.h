#pragma once
#include <string>
#include <vector>

namespace Dungeon::Engine::Serialization {
class SerializedGO {
  // #region Data
public:
  int id;
  std::string name;
  int transform;
  std::vector<int> components;
  // #endregion
};
} // namespace Dungeon::Engine::Serialization

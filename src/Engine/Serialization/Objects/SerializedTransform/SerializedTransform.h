
#pragma once
#include <string>
#include <vector>

namespace Dungeon::Engine::Serialization {
class SerializedTransform {
  // #region Data
public:
  int id;
  std::string serializedPosition;
  float rotation;
  std::string serializedScale;

  int gameObject;
  int parent;
  std::vector<int> children;
  // #endregion
};
} // namespace Dungeon::Engine::Serialization

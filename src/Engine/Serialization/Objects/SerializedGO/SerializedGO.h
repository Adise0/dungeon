#pragma once
#include "../SerializedComponent/SerializedComponent.h"
#include "../SerializedTransform/SerializedTransform.h"
#include <string>
#include <vector>

namespace Dungeon::Engine::Serialization {
class SerializedGO {
  // #region Data
public:
  int id;
  std::string name;
  SerializedTransform transform;
  std::vector<SerializedComponent> components;
  std::vector<SerializedGO> children;
  // #endregion
};
} // namespace Dungeon::Engine::Serialization

#pragma once
#include <string>

namespace Dungeon::Engine::Serialization {

class SerializedComponent {
  // #region Data
public:
  int id;
  std::string name;

  int gameObject;

  //TODO: Component serialization
  // #endregion
};
} // namespace Dungeon::Engine::Serialization

#pragma once
#include "../Component/Component.h"
#include "../Objects/Store/Store.h"
#include "../Transform/Transform.h"
#include <memory>
#include <string>
#include <vector>

namespace Dungeon::Engine {
class GameObject {
  // #region Static
public:
  /// @brief The GameObject store
  static Store<GameObject> store;
  // #endregion

  // #region Data
public:
  std::string name;
  Transform *transform;
  std::vector<std::unique_ptr<Component>> components;
  GameObject(std::string name);
  ~GameObject();

private:
  /// @brief Whether this GameObject is Enabled
  bool isEnabled;
  // #endregion

public:
  /// @brief Getter for whether this GameObject is enabled
  /// @return Whether it's enabled
  bool IsEnabled() { return isEnabled; };

  void AddComponent(std::unique_ptr<Component> component);
};
} // namespace Dungeon::Engine

#pragma once
#include "../Component/Component.h"
#include "../Objects/Store/Store.h"
#include "../Scene/Scene.h"
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
  Scene *scene;

  GameObject(Scene *scene, std::string name);
  GameObject(Scene *scene, Transform *parent, std::string name);
  ~GameObject();

private:
  /// @brief Whether this GameObject is Enabled
  bool isEnabled = true;
  // #endregion

public:
  /// @brief Getter for whether this GameObject is enabled
  /// @return Whether it's enabled
  bool IsEnabled() { return isEnabled; };

  void AddComponent(std::unique_ptr<Component> component);
  GameObject *CreateChild(std::string name);

  Component *GetComponentByName(std::string name);
};
} // namespace Dungeon::Engine

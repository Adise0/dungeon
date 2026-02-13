#pragma once

#include <string>
namespace Dungeon::Engine {

class GameObject;

class Component {
  // #region Data
public:
  std::string name;

private:
  /// @brief This component's GameObject
  GameObject *gameObject;
  // #endregion

  // #region Methods
protected:
  virtual void OnDestroy();

public:
  /// @brief Getter for this component's GameObject
  /// @return The component's GameObject
  GameObject *GetGameObject() { return gameObject; };
  // #endregion
};
} // namespace Dungeon::Engine

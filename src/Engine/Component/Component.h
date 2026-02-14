#pragma once

#include "../Transform/Transform.h"
#include <string>
namespace Dungeon::Engine {

class GameObject;

class Component {
  // #region Data
public:
  std::string name;

public:
  /// @brief This component's GameObject
  GameObject *gameObject;
  Transform *transform;
  // #endregion

  // #region Constructor
public:
  virtual ~Component() = default;
  // #endregion

  // #region Methods
protected:
  virtual void OnDestroy();

  // #endregion
};
} // namespace Dungeon::Engine

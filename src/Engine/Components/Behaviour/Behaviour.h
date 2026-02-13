#pragma once

#include "../../Component/Component.h"
#include "../../GameObject/GameObject.h"
#include "../../Objects/Store/Store.h"
#include <vector>
namespace Dungeon::Engine {

class Behaviour : public Component {
  // #region Static
public:
  /// @brief The behaviour store
  static Store<Behaviour> store;
  // #endregion

  // #region Constructor
public:
  Behaviour();
  // #endregion

  // #region Methods
public:
  virtual void Awake() {};
  virtual void Start() {};
  virtual void Update(float deltaTime) {};
  // #endregion
};
} // namespace Dungeon::Engine

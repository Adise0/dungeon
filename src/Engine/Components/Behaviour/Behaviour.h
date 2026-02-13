#pragma once

#include "../../Component/Component.h"
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
protected:
  virtual void Awake();
  virtual void Start();
  virtual void Update();
  // #endregion
};
} // namespace Dungeon::Engine

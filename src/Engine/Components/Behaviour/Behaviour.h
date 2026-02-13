#pragma once

#include "../../Component/Component.h"
#include "../../Objects/Store/Store.h"
#include <vector>
namespace Dungeon::Engine {

class Behaviour : public Component {
  // #region Static
public:
  Store<Behaviour> store;
  // #endregion

  // #region Methods
protected:
  virtual void Awake();
  virtual void Start();
  virtual void Update();
  // #endregion
};
} // namespace Dungeon::Engine

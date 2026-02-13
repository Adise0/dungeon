#pragma once

#pragma once
#include "../../Component/Component.h"
#include "../../Objects/Store/Store.h"
#include <vector>
namespace Dungeon::Engine {

class Renderer : public Component {
  // #region Static
public:
  Store<Renderer> store;
  // #endregion

  // #region Methods
protected:
  virtual void Awake();
  virtual void Start();
  virtual void Update();
  // #endregion
};
} // namespace Dungeon::Engine

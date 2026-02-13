#pragma once

#pragma once
#include "../../Component/Component.h"
#include "../../Objects/Store/Store.h"
#include <vector>
namespace Dungeon::Engine {

class Renderer : public Component {
  // #region Static
public:
  /// @brief The renderer store
  static Store<Renderer> store;
  // #endregion

  // #region Methods
public:
  /// @brief Renders this renderer contents to the screen
  void Render();
  // #endregion
};
} // namespace Dungeon::Engine

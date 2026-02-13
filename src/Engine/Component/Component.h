#include "../GameObject/GameObject.h"

namespace Dungeon::Engine {

class Component {
  // #region Data
public:
private:
  /// @brief This component's GameObject
  GameObject gameObject;
  // #endregion

  // #region Methods
public:
  /// @brief Getter for this component's GameObject
  /// @return The component's GameObject
  GameObject GameObject() { return gameObject; };
  // #endregion
};
} // namespace Dungeon::Engine

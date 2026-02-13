
#include "../Objects/Vector2/Vector2.h"

namespace Dungeon::Engine {

class GameObject;

class Transform {
  // #region Data
public:
  /// @brief The poistion of this transform
  Vector2 position;
  /// @brief The rotation of this transform| IN DEGREES
  float rotation;
  /// @brief The scale of this transform
  Vector2 scale;


private:
  /// @brief This transform's GameObject
  GameObject *gameObject;

  // #endregion

  // #region Methods
public:
  /// @brief Getter for this transform's GameObject
  /// @return The transform's GameObject
  GameObject *GameObject() { return gameObject; };
  // #endregion
};
} // namespace Dungeon::Engine

#include "../Component/Component.h"
#include "../Transform/Transform.h"
#include <memory>
#include <vector>

namespace Dungeon::Engine {
class GameObject {
  // #region Data
public:
  Transform transform;
  std::vector<std::unique_ptr<Component>> components;

private:
  /// @brief Whether this GameObject is Enabled
  bool isEnabled;
  // #endregion

public:
  /// @brief Getter for whether this GameObject is enabled
  /// @return Whether it's enabled
  bool IsEnabled() { return isEnabled; };
};
} // namespace Dungeon::Engine

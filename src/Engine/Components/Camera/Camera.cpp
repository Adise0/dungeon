#include "./Camera.h"

namespace Dungeon::Engine {
Camera::Camera() {
  store.RegisterItem(this);
  name = "Camera";
};
} // namespace Dungeon::Engine

#include "./Collider.h"
#include "../../Scene/Scene.h"
#include <stdexcept>
namespace Dungeon::Engine {


Collider::Collider(float width, float height) : width(width), height(height) {
  name = "Collider";
  Scene::activeScene->AppendCollider(this);
}
SDL_FRect Collider::GetBounds() {
  // #region GetBounds
  Vector2 origin(width / 2, height / 2);
  return {origin.x, origin.y, width, height};
  // #endregion
}
} // namespace Dungeon::Engine

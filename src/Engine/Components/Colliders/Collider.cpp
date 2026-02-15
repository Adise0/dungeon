#include "./Collider.h"
#include "../../Scene/Scene.h"
#include <stdexcept>
namespace Dungeon::Engine {


Collider::Collider() {
  name = "Collider";
  Scene::activeScene->AppendCollider(this);
}
SDL_FRect Collider::GetBounds() { throw std::runtime_error("Get bounds must be implemented"); }
} // namespace Dungeon::Engine

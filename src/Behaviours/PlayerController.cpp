#include "./PlayerController.h"
#include "../Engine/Objects/Vector2/Vector2.h"

namespace Dungeon::Engine {

void PlayerController::Update(float deltaTime) {
  transform->position = transform->position + Vector2(0, 1) * deltaTime;
}

} // namespace Dungeon::Engine

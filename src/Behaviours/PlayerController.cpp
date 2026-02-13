#include "./PlayerController.h"
#include "../Engine/Objects/Vector2/Vector2.h"

namespace Dungeon::Engine {

void PlayerController::Update(float deltaTime) {
  transform->position = transform->position + Vector2(1, 0) * deltaTime;
}

} // namespace Dungeon::Engine

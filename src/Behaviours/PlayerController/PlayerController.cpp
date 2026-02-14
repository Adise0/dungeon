#include "./PlayerController.h"
#include "../../Engine/InputSystem/InputSystem.h"
#include "../../Engine/Scene/Scene.h"
#include <SDL3/SDL.h>
#include <iostream>

namespace Dungeon::Behaviours {
using namespace Engine;

void PlayerController::Awake() {
  cam = (Camera *)Scene::activeScene->FindGameObjectByName("Main Camera")
            ->GetComponentByName("Main Camera");
}

void PlayerController::Update(float deltaTime) {


  Vector2 dir;
  if (InputSystem::GetKey("W").isPressed) dir += Vector2(0, 1);
  if (InputSystem::GetKey("A").isPressed) dir += Vector2(-1, 0);
  if (InputSystem::GetKey("S").isPressed) dir += Vector2(0, -1);
  if (InputSystem::GetKey("D").isPressed) dir += Vector2(1, 0);

  if (InputSystem::GetKey("Q").isPressed) cam->SetSize(cam->size -= 4 * deltaTime);
  if (InputSystem::GetKey("E").isPressed) cam->SetSize(cam->size += 4 * deltaTime);

  gameObject->transform->position += dir.Normalized() * speed * deltaTime;
}
} // namespace Dungeon::Behaviours

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

  kBody = (KinematicBody *)gameObject->GetComponentByName("KBody");
}

void PlayerController::Update(float deltaTime) {


  Vector2 dir;
  if (InputSystem::GetKey("W").isPressed) dir += Vector2(0, 1);
  if (InputSystem::GetKey("A").isPressed) dir += Vector2(-1, 0);
  if (InputSystem::GetKey("S").isPressed) dir += Vector2(0, -1);
  if (InputSystem::GetKey("D").isPressed) dir += Vector2(1, 0);

  if (InputSystem::GetKey("Q").isPressed) cam->SetSize(cam->size -= 4 * deltaTime);
  if (InputSystem::GetKey("E").isPressed) cam->SetSize(cam->size += 4 * deltaTime);

  Vector2 delta = dir.Normalized() * speed * deltaTime;
  float TOI = kBody->GetTOI(delta);
  Vector2 dest = delta * TOI;
  transform->position = dest;
  std::cout << "Delta: " + delta.ToString() + " TOI: " + std::to_string(TOI) +
                   " Dest: " + dest.ToString()
            << std::endl;
}
} // namespace Dungeon::Behaviours

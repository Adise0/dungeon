#include "GameManager.h"
#include "../Engine/Components/Behaviour/Behaviour.h"
#include "../Engine/Components/Camera/Camera.h"
#include "../Engine/InputSystem/InputSystem.h"
#include "../WindowManager/WindowManager.h"
#include <SDL3/SDL.h>
#include <algorithm>
#include <chrono>
#include <iostream>

namespace Dungeon {

using namespace Rendering;
using namespace Engine;

bool GameManager::isRunning = false;

std::string GetMouseButtonName(uint8_t button) {
  switch (button) {
  case SDL_BUTTON_LEFT:
    return "MouseLeft";
  case SDL_BUTTON_RIGHT:
    return "MouseRight";
  case SDL_BUTTON_MIDDLE:
    return "MouseMiddle";
  case SDL_BUTTON_X1:
    return "MouseX1";
  case SDL_BUTTON_X2:
    return "MouseX2";
  default:
    return "MouseUnknown";
  }
}

void GameManager::ProcessInput(SDL_Event &event) {
  // #region ProcessInput
  InputSystem::Frame();

  while (SDL_PollEvent(&event)) {

    switch (event.type) {
    case SDL_EVENT_QUIT:
      isRunning = false;
      break;

    case SDL_EVENT_MOUSE_MOTION:
      InputSystem::mousePos = Vector2(event.motion.x, event.motion.y);
      break;

    case SDL_EVENT_KEY_DOWN:
      InputSystem::GetKey(SDL_GetKeyName(event.key.key)).Press();
      break;

    case SDL_EVENT_KEY_UP:
      InputSystem::GetKey(SDL_GetKeyName(event.key.key)).Release();
      break;

    case SDL_EVENT_MOUSE_BUTTON_DOWN:
      InputSystem::GetKey(GetMouseButtonName(event.button.button)).Press();
      break;

    case SDL_EVENT_MOUSE_BUTTON_UP:
      InputSystem::GetKey(GetMouseButtonName(event.button.button)).Release();
      break;

    default:
      break;
    }
  }
  // #endregion
}

void GameManager::Update(float deltaTime) {
  // #region Update
  try {

    std::vector<Behaviour *> behaviours = Behaviour::store.GetItems();
    for (Behaviour *behaviour : behaviours) {
      behaviours.erase(std::remove_if(behaviours.begin(), behaviours.end(),
                                      [](Behaviour *beh) { return !beh->gameObject->IsEnabled(); }),
                       behaviours.end());

      behaviour->Update(deltaTime);
    }


  } catch (...) {
    std::cout << "BRUH" << std::endl;
  }
  // #endregion
}

void GameManager::Render(float deltaTime) {
  // #region Render

  try {
    Camera *activeCam = Camera::activeCamera;
    if (activeCam != nullptr) activeCam->Render(deltaTime);
    else SDL_RenderClear(WindowManager::renderer);


    SDL_RenderPresent(WindowManager::renderer);
  } catch (...) {
    std::cout << "BRUH" << std::endl;
  }
  // #endregion
}


void GameManager::LoadScreens() {
  // #region LoadScreens

  // #endregion
}

void GameManager::Run() {
  // #region Run
  LoadScreens();

  isRunning = true;
  SDL_Event event;
  auto lastFrame = std::chrono::high_resolution_clock::now();


  while (isRunning) {
    ProcessInput(event);
    auto thisFrame = std::chrono::high_resolution_clock::now();
    float deltaTime = std::chrono::duration<float>(thisFrame - lastFrame).count();
    lastFrame = thisFrame;


    Update(deltaTime);
    Render(deltaTime);
  }
  // #endregion
}

void GameManager::StartGame() {
  // #region StartGame

  // #endregion
}



} // namespace Dungeon

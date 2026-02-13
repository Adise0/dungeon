#include "GameManager.h"
#include "../Engine/Components/Behaviour/Behaviour.h"
#include "../Engine/Components/Camera/Camera.h"
#include "../WindowManager/WindowManager.h"
#include <SDL3/SDL.h>
#include <algorithm>
#include <chrono>
#include <iostream>

namespace Dungeon {

using namespace Rendering;
using namespace Engine;

bool GameManager::isRunning = false;


void GameManager::ProcessInput(SDL_Event &event) {
  // #region ProcessInput
  while (SDL_PollEvent(&event)) {

    switch (event.type) {
    case SDL_EVENT_QUIT:
      isRunning = false;
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

void GameManager::Render() {
  // #region Render

  try {
    Camera *activeCam = Camera::activeCamera;
    activeCam->Render();

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
    Render();
  }
  // #endregion
}

void GameManager::StartGame() {
  // #region StartGame

  // #endregion
}


} // namespace Dungeon

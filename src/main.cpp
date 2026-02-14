
#include "./GameManager/GameManager.h"
#include "./Scenes/MainScene/MainScene.h"
#include "./WindowManager/WindowManager.h"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>
#include <memory>

namespace Dungeon {
using namespace Rendering;
using namespace Scenes;

int Run() {
  try {
    WindowManager::InitializeWindow();

    MainScene *mainScene = new MainScene();
    mainScene->SetAsActiveScene();

    GameManager::Run();

    SDL_Quit();
    WindowManager::Dispose();
  } catch (const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception occurred" << std::endl;
  }
  return EXIT_SUCCESS;
}
} // namespace Dungeon


int main() {
  std::cout << "Initializing" << std::endl;
  return Dungeon::Run();
}

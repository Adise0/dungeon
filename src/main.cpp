#include "./GameManager/GameManager.h"
#include "./WindowManager/WindowManager.h"
#include <iostream>

namespace Dungeon {
using namespace Rendering;

int Run() {

  WindowManager::InitializeWindow();

  GameManager::Run();

  SDL_Quit();
  WindowManager::Dispose();
  return EXIT_SUCCESS;
}
} // namespace Dungeon


int main() {
  std::cout << "Initializing" << std::endl;
  return Dungeon::Run();
}

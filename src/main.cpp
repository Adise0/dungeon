#include "./Engine/GameObject/GameObject.h"
#include "./Engine/Serialization/Serializer/Serializer.h"
#include "./GameManager/GameManager.h"
#include "./WindowManager/WindowManager.h"
#include <iostream>
namespace Dungeon {
using namespace Rendering;
using namespace Engine;
using namespace Serialization;
int Run() {

  WindowManager::InitializeWindow();

  GameObject *testGO = new GameObject((std::string) "testGO");
  Serializer::SerializeToFile(testGO);

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

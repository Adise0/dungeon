#include "./Behaviours/PlayerController.h"
#include "./Engine/Components/Camera/Camera.h"
#include "./Engine/Components/Renderer/Renderer.h"
#include "./Engine/GameObject/GameObject.h"
#include "./Engine/Serialization/Serializer/Serializer.h"
#include "./GameManager/GameManager.h"
#include "./WindowManager/WindowManager.h"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>
#include <memory>

namespace Dungeon {
using namespace Rendering;
using namespace Engine;
using namespace Serialization;
int Run() {
  try {
    WindowManager::InitializeWindow();

    GameObject *cameraGO = new GameObject((std::string) "Camera");
    std::unique_ptr<Camera> cam = std::make_unique<Camera>();
    cam->background = {255, 0, 0, 255};
    cam->SetAsActiveCamera();
    cam->SetSize(15);
    cameraGO->AddComponent(std::move(cam));

    GameObject *test = new GameObject((std::string) "Dude");

    std::unique_ptr<Renderer> renderer = std::make_unique<Renderer>();
    renderer->sprite = IMG_LoadTexture(WindowManager::renderer, "assets/sprites/Discord.jpeg");
    renderer->size = Vector2(1, 1);

    std::unique_ptr<PlayerController> pc = std::make_unique<PlayerController>();

    test->AddComponent(std::move(renderer));
    test->AddComponent(std::move(pc));

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

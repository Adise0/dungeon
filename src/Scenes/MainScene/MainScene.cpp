#include "./MainScene.h"
#include "../../Engine/Components/Camera/Camera.h"
#include "../../Engine/Components/Renderer/Renderer.h"
#include "../../WindowManager/WindowManager.h"
#include <SDL3_image/SDL_image.h>


namespace Dungeon::Scenes {

using namespace Engine;
using namespace Rendering;

void MainScene::LoadHierarchy() {
  GameObject *camHolder = new GameObject(this, "Main Camera");
  auto cam = std::make_unique<Camera>();
  cam->name = "Main Camera";
  cam->SetAsActiveCamera();
  cam->SetSize(15);
  camHolder->AddComponent(std::move(cam));

  GameObject *backgroundHolder = new GameObject(this, "Background Holder");
  auto bgRenderer = std::make_unique<Renderer>();
  bgRenderer->useSprite = false;
  bgRenderer->color = {0, 0, 0, 255};
  bgRenderer->size = Vector2(15, 15);
  backgroundHolder->AddComponent(std::move(bgRenderer));
}
} // namespace Dungeon::Scenes

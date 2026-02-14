#include "./MainScene.h"
#include "../../Engine/Components/Animator/Animator.h"
#include "../../Engine/Components/Camera/Camera.h"
#include "../../Engine/Components/Renderer/Renderer.h"
#include "../../Engine/Objects/AnimationClip/AnimationClip.h"
#include "../../WindowManager/WindowManager.h"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>
#include <memory>
namespace Dungeon::Scenes {

using namespace Engine;
using namespace Rendering;

void MainScene::LoadHierarchy() {
  GameObject *camHolder = root->CreateChild("Main Camera");
  auto cam = std::make_unique<Camera>();
  cam->name = "Main Camera";
  cam->SetAsActiveCamera();
  cam->SetSize(15);
  camHolder->AddComponent(std::move(cam));

  GameObject *backgroundHolder = root->CreateChild("Background Holder");
  auto bgRenderer = std::make_unique<Renderer>();
  bgRenderer->useSprite = false;
  bgRenderer->color = {0, 0, 0, 255};
  bgRenderer->size = Vector2(15, 15);
  backgroundHolder->AddComponent(std::move(bgRenderer));

  GameObject *lilDude = root->CreateChild("Lil Dude");
  auto r = std::make_unique<Renderer>();
  r->size = Vector2(1, 1);
  r->useSprite = false;
  lilDude->AddComponent(std::move(r));

  auto a = std::make_unique<Animator>();
  Animator *anim = (Animator *)lilDude->AddComponent(std::move(a));
  SDL_Texture *spriteSheet = IMG_LoadTexture(WindowManager::renderer, "assets/sprites/Idle.png");
  SDL_SetTextureScaleMode(spriteSheet, SDL_SCALEMODE_NEAREST);
  AnimationClip clip(24, spriteSheet);
  clip.frameRate = 2;
  anim->AddAnimation("Idle", clip);
  anim->PlayAnimation("Idle");
}
} // namespace Dungeon::Scenes

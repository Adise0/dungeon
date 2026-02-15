#include "./MainScene.h"
#include "../../Behaviours/PlayerController/PlayerController.h"
#include "../../Engine/Components/Animator/Animator.h"
#include "../../Engine/Components/Camera/Camera.h"
#include "../../Engine/Components/Colliders/Collider.h"
#include "../../Engine/Components/KinematicBody/KinematicBody.h"
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
using namespace Behaviours;

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

  GameObject *obstacle = root->CreateChild("Obstacle");
  obstacle->transform->position = Vector2(0, 1);
  auto obstacleRenderer = std::make_unique<Renderer>();
  obstacleRenderer->useSprite = false;
  obstacleRenderer->color = {0, 0, 255, 255};
  obstacleRenderer->size = Vector2(1, 1);
  obstacle->AddComponent(std::move(obstacleRenderer));

  auto obsCollider = std::make_unique<Collider>(1, 1);
  obstacle->AddComponent(std::move(obsCollider));

  GameObject *lilDude = root->CreateChild("Lil Dude");
  auto lilDudeRenderer = std::make_unique<Renderer>();
  lilDudeRenderer->size = Vector2(1, 1);
  lilDudeRenderer->useSprite = false;
  lilDude->AddComponent(std::move(lilDudeRenderer));

  auto lilDudeCol = std::make_unique<Collider>(1, 1);
  lilDude->AddComponent(std::move(lilDudeCol));

  auto kbody = std::make_unique<KinematicBody>();
  lilDude->AddComponent(std::move(kbody));

  auto playerController = std::make_unique<PlayerController>();
  lilDude->AddComponent(std::move(playerController));

  auto lilDudeAnimatorOriginal = std::make_unique<Animator>();
  Animator *lilDudeAnimator = (Animator *)lilDude->AddComponent(std::move(lilDudeAnimatorOriginal));

  SDL_Texture *spriteSheet = WindowManager::LoadSprite("assets/sprites/lilDude/unarmed/Idle.png");
  SDL_SetTextureScaleMode(spriteSheet, SDL_SCALEMODE_NEAREST);

  AnimationClip idleFront(64, spriteSheet);
  idleFront.frameRate = 1;
  idleFront.nOfFrames = 4;
  lilDudeAnimator->AddAnimation("Idle Front", idleFront);

  AnimationClip idleLeft(64, spriteSheet);
  idleFront.frameRate = 4;
  idleFront.yCoord = 64;
  lilDudeAnimator->AddAnimation("Idle Left", idleFront);

  AnimationClip idleRight(64, spriteSheet);
  idleFront.frameRate = 4;
  idleRight.yCoord = 128;
  lilDudeAnimator->AddAnimation("Idle Right", idleFront);

  AnimationClip idleBack(64, spriteSheet);
  idleFront.frameRate = 4;
  idleRight.yCoord = 192;
  lilDudeAnimator->AddAnimation("Idle Back", idleFront);

  lilDudeAnimator->PlayAnimation("Idle Front");
}
} // namespace Dungeon::Scenes

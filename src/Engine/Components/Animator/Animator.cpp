#include "./Animator.h"
#include "../../GameObject/GameObject.h"
#include "../Renderer/Renderer.h"
#include <iostream>

namespace Dungeon::Engine {
Animator::Animator() { name = "Animator"; }


void Animator::AddAnimation(std::string clipName, AnimationClip clip) {
  clips.try_emplace(clipName, clip);
  std::cout << "GO is: " << gameObject->name << std::endl;
  Renderer *renderer = (Renderer *)gameObject->GetComponentByName("Renderer");
  std::cout << "Rend is: " << renderer << std::endl;

  renderer->useAnimator = true;
  if (currentClip == "none") currentClip = clipName;
}

void Animator::PlayAnimation(std::string clipName) {
  if (currentClip != "none") clips[currentClip].Reset();
  clips[clipName].Reset();
  clips[clipName].Play();
  currentClip = clipName;
}

void Animator::Pause() {
  if (currentClip == "none") return;
  clips[currentClip].Pause();
}
void Animator::Stop() {
  if (currentClip == "none") return;
  clips[currentClip].Stop();
}
void Animator::Reset() {
  if (currentClip == "none") return;
  clips[currentClip].Reset();
}

void Animator::Render(float deltaTime, SDL_FRect rect) {
  if (currentClip == "none") return;
  clips[currentClip].Render(deltaTime, rect);
}


} // namespace Dungeon::Engine

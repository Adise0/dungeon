#include "./Animator.h"
#include "../../GameObject/GameObject.h"
#include "../Renderer/Renderer.h"
namespace Dungeon::Engine {
Animator::Animator() { name = "Animator"; }


void Animator::AddAnimation(std::string clipName, AnimationClip clip) {
  clips[clipName] = clip;
  Renderer *renderer = (Renderer *)gameObject->GetComponentByName("Renderer");
  renderer->useAnimator = true;
  if (currentClip == "none") currentClip = name;
}

void Animator::PlayAnimation(std::string clipName) {
  if (currentClip != "none") clips[currentClip].Reset();
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


} // namespace Dungeon::Engine

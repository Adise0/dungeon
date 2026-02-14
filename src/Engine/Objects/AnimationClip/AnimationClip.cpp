

#include "./AnimationClip.h"
#include "../../../WindowManager/WindowManager.h"
#include <iostream>

namespace Dungeon::Engine {
using namespace Rendering;

short AnimationClip::Length() { return spriteSheet->w / cellSize; }

SDL_FRect AnimationClip::GetCurrentFrameRect() {
  // #region GetCurrentFrame

  return {cellSize * frame, 0, (float)spriteSheet->h, cellSize};
  // #endregion
}

void AnimationClip::Play() { isPlaying = true; }
void AnimationClip::Pause() { isPlaying = false; }
void AnimationClip::Stop() {
  Pause();
  currentTimer = 1 / (float)frameRate;
}
void AnimationClip::Reset() {
  Stop();
  frame = 0;
}

void AnimationClip::Render(float deltaTime, SDL_FRect rect) {
  currentTimer -= speed * deltaTime;
  if (currentTimer <= 0) {
    currentTimer = 1 / (float)frameRate;
    frame++;
    if (frame < spriteSheet->w / cellSize) return;
    if (loop) frame = 0;
    else {
      Stop();
    }
  }

  SDL_FRect srect = GetCurrentFrameRect();
  SDL_RenderTexture(WindowManager::renderer, spriteSheet, &srect, &rect);
}

} // namespace Dungeon::Engine

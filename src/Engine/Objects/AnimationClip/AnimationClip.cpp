

#include "./AnimationClip.h"

namespace Dungeon::Engine {

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
  currentTimer = msPerFrame;
}
void AnimationClip::Reset() {
  Stop();
  frame = 0;
}

void AnimationClip::Run(float deltaTime) {
  currentTimer -= speed * deltaTime;
  if (currentTimer > 0) return;

  currentTimer = msPerFrame;
  frame++;
  if (frame <= spriteSheet->w / cellSize) return;
  if (loop) frame = 0;
  else {
    Stop();
  }
}

} // namespace Dungeon::Engine

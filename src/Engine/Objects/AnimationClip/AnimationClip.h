#pragma once
#include <SDL3_image/SDL_image.h>

namespace Dungeon::Engine {
class AnimationClip {
public:
  SDL_Texture *spriteSheet;
  float cellSize;
  short frame;
  int frameRate;
  bool isPlaying;
  float currentTimer = 0;
  float speed = 1;
  bool loop = true;
  float yCoord = 0;
  short nOfFrames = 0;


public:
  AnimationClip(float cellSize, SDL_Texture *spriteSheet)
      : spriteSheet(spriteSheet), cellSize(cellSize) {};

  AnimationClip() : spriteSheet(nullptr), cellSize(0.0f) {}

public:
  short Length();
  SDL_FRect GetCurrentFrameRect();

  void Play();
  void Pause();
  void Stop();
  void Reset();
  void Render(float deltaTime, SDL_FRect rect);
};
} // namespace Dungeon::Engine

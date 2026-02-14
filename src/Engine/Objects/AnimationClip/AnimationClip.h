#pragma once
#include <SDL3_image/SDL_image.h>

namespace Dungeon::Engine {
class AnimationClip {
public:
  SDL_Texture *spriteSheet;
  float cellSize;
  short frame;
  int msPerFrame;
  bool isPlaying;
  float currentTimer;
  float speed = 1;
  bool loop = true;


public:
  AnimationClip(float cellSize, SDL_Texture *spriteSheet)
      : cellSize(cellSize), spriteSheet(spriteSheet) {};

public:
  short Length();
  SDL_FRect GetCurrentFrameRect();

  void Play();
  void Pause();
  void Stop();
  void Reset();
  void Run(float deltaTime);
};
} // namespace Dungeon::Engine

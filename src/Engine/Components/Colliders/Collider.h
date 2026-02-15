#pragma once
#include "../../Component/Component.h"
#include <SDL3/SDL.h>
#include <vector>
namespace Dungeon::Engine {

class Collider : public Component {

public:
  float width;
  float height;

public:
  Collider(float width, float height);

public:
  virtual SDL_FRect GetBounds();
};
} // namespace Dungeon::Engine

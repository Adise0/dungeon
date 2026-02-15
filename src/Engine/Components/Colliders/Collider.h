#pragma once
#include "../../Component/Component.h"
#include <SDL3/SDL.h>
#include <vector>
namespace Dungeon::Engine {

class Collider : public Component {
public:
  bool isStatic;

public:
  Collider();

public:
  virtual SDL_FRect GetBounds();
};
} // namespace Dungeon::Engine

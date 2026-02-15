#pragma once
#include "../../Component/Component.h"
#include "../../Scene/Scene.h"
namespace Dungeon::Engine {

class KinematicBody : public Component {

public:
  KinematicBody();

public:
  float GetTOI(Vector2 delta);
};
} // namespace Dungeon::Engine

#pragma once
#include "../../Component/Component.h"
#include "../../Objects/Vector2/Vector2.h"
#include "../../Scene/Scene.h"
namespace Dungeon::Engine {

class KinematicBody : public Component {

private:
  static constexpr float kSkin = 0.1f;


public:
  KinematicBody();

public:
  Vector2 GetTOI(Vector2 delta);
  Vector2 Translate(Vector2 delta);
};
} // namespace Dungeon::Engine

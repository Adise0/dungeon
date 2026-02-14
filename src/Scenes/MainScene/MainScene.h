#pragma once

#include "../../Engine/GameObject/GameObject.h"
#include "../../Engine/Scene/Scene.h"
#include <memory>
namespace Dungeon::Scenes {

using namespace Engine;

class MainScene : public Scene {

public:
  MainScene() {
    Scene();
    root = std::make_unique<GameObject>(this, "Root");

    LoadHierarchy();
  }

private:
  void LoadHierarchy();
};
} // namespace Dungeon::Scenes

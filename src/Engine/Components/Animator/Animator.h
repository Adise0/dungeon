#pragma once
#include "../../Component/Component.h"
#include "../../Objects/AnimationClip/AnimationClip.h"
#include <functional>
#include <map>
#include <string>

namespace Dungeon::Engine {

class Animator : public Component {

public:
  std::map<std::string, AnimationClip> clips;

private:
  std::string currentClip = "none";

public:
  Animator();

public:
  void PlayAnimation(std::string clipName);
  void Pause();
  void Stop();
  void Reset();
  void Run(float deltaTime);

  void AddAnimation(std::string clipName, AnimationClip clip);
};
} // namespace Dungeon::Engine

#include "../../Engine/Components/Behaviour/Behaviour.h"
#include "../../Engine/Components/Camera/Camera.h"
#include "../../Engine/Components/KinematicBody/KinematicBody.h"


namespace Dungeon::Behaviours {
using namespace Engine;

class PlayerController : public Behaviour {

public:
  float speed = 1;
  Camera *cam;
  KinematicBody *kBody;

public:
  void Awake() override;
  void Update(float deltaTime) override;
};
} // namespace Dungeon::Behaviours

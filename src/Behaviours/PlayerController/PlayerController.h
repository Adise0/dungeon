#include "../../Engine/Components/Behaviour/Behaviour.h"
#include "../../Engine/Components/Camera/Camera.h"


namespace Dungeon::Behaviours {
using namespace Engine;

class PlayerController : public Behaviour {

public:
  float speed = 1;
  Camera *cam;

public:
  void Awake() override;
  void Update(float deltaTime) override;
};
} // namespace Dungeon::Behaviours

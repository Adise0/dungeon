#include "../Engine/Components/Behaviour/Behaviour.h"


namespace Dungeon::Engine {
class PlayerController : public Behaviour {

  void Update(float deltaTime) override;
};

} // namespace Dungeon::Engine

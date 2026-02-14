#include "./Behaviour.h"


namespace Dungeon::Engine {



Behaviour::Behaviour() {
  store.RegisterItem(this);
  name = "Behaviour";
}

} // namespace Dungeon::Engine

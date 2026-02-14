#include "./InputSystem.h"


namespace Dungeon::Engine {

Input &InputSystem::GetKey(std::string keyName) {
  Input &foundKey = inputs[keyName];
  return foundKey;
}

void InputSystem::Frame() {
  for (auto &[_, input] : inputs) {
    input.Frame();
  }
}

} // namespace Dungeon::Engine

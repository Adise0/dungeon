#include "./InputSystem.h"
#include <iostream>

namespace Dungeon::Engine {

Vector2 InputSystem::mousePos = Vector2(0, 0);
std::map<std::string, Input> InputSystem::inputs{};

Input &InputSystem::GetKey(std::string keyName) {
  Input &foundKey = inputs[keyName];
  return foundKey;
}

void InputSystem::Frame() {
  for (auto &[name, input] : inputs) {
    input.Frame();
  }
}

} // namespace Dungeon::Engine

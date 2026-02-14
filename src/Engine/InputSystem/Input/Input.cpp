#include "./Input.h"

namespace Dungeon::Engine {



void Input::Press() {
  wasPressedThisFrame = true;
  isPressed = true;
}

void Input::Release() {
  wasPressedThisFrame = false;
  isPressed = false;
}

void Input::Frame() { wasPressedThisFrame = false; }
} // namespace Dungeon::Engine

#include "../../Objects/Store/Store.h"
#include <string>
namespace Dungeon::Engine {

class Input {

public:
  std::string name;
  bool wasPressedThisFrame;
  bool isPressed;


public:
  void Press();
  void Release();
  void Frame();
};
} // namespace Dungeon::Engine

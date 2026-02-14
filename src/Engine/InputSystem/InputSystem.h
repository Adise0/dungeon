
#include "../Objects/Vector2/Vector2.h"
#include "./Input/Input.h"
#include <map>
namespace Dungeon::Engine {

class InputSystem {
public:
  static Vector2 mousePos;
  static std::map<std::string, Input> inputs;

public:
  static Input &GetKey(std::string keyName);
  static void Frame();
};
} // namespace Dungeon::Engine

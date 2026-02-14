#pragma once

#include "../../Component/Component.h"
#include "../../GameObject/GameObject.h"
#include "../../Objects/Store/Store.h"
#include "../../Objects/Vector2/Vector2.h"
#include <SDL3/SDL.h>
#include <vector>
namespace Dungeon::Engine {

class Renderer : public Component {
  // #region Static
public:
  /// @brief The renderer store
  static Store<Renderer> store;
  // #endregion

  // #region Data
public:
  float zIndex = 0;
  Vector2 size;
  SDL_Texture *sprite;
  SDL_FRect srect{0, 0, size.x, size.y};
  SDL_Color color{248, 24, 148, 255};
  bool useSprite = true;
  bool useAnimator = false;

private:
  bool overrideSRect = false;
  // #endregion

  // #region Constructor
public:
  Renderer();
  // #endregion

  // #region Methods
public:
  /// @brief Renders this renderer contents to the screen
  void Render(float deltaTime, SDL_FRect rect);
  void SetSRect(SDL_FRect srect);
  // #endregion
};
} // namespace Dungeon::Engine

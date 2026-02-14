#include "./Renderer.h"
#include "../../../WindowManager/WindowManager.h"
#include <iostream>

namespace Dungeon::Engine {

using namespace Rendering;

Renderer::Renderer() { store.RegisterItem(this); }

void Renderer::Render(SDL_FRect rect) {
  // #region Render
  if (useSprite) SDL_RenderTexture(WindowManager::renderer, sprite, NULL, &rect);
  else {
    SDL_SetRenderDrawColor(WindowManager::renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(WindowManager::renderer, &rect);
  }
  // #endregion
}
} // namespace Dungeon::Engine

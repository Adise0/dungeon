#include "./Renderer.h"
#include "../../../WindowManager/WindowManager.h"
#include <iostream>

namespace Dungeon::Engine {

using namespace Rendering;

Renderer::Renderer() { store.RegisterItem(this); }

void Renderer::Render(SDL_FRect rect) {
  // #region Render
  SDL_RenderTexture(WindowManager::renderer, sprite, NULL, &rect);

  // #endregion
}
} // namespace Dungeon::Engine

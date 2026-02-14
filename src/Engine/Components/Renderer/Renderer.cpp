#include "./Renderer.h"
#include "../../../WindowManager/WindowManager.h"
#include "../Animator/Animator.h"
#include <iostream>

namespace Dungeon::Engine {

using namespace Rendering;

Renderer::Renderer() {
  store.RegisterItem(this);
  name = "Renderer";
}

void Renderer::Render(float deltaTime, SDL_FRect rect) {

  // #region Render
  if (useAnimator) {
    Animator *animator = (Animator *)(gameObject->GetComponentByName("Animator"));
    animator->Render(deltaTime, rect);
  } else {
    if (useSprite)
      SDL_RenderTexture(WindowManager::renderer, sprite, overrideSRect ? &srect : NULL, &rect);
    else {
      SDL_SetRenderDrawColor(WindowManager::renderer, color.r, color.g, color.b, color.a);
      SDL_RenderFillRect(WindowManager::renderer, &rect);
    }
  }
  // #endregion
}

void Renderer::SetSRect(SDL_FRect srect) {
  this->srect = srect;
  overrideSRect = true;
}
} // namespace Dungeon::Engine

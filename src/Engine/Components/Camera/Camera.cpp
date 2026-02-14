#include "./Camera.h"
#include "../../../WindowManager/WindowManager.h"
#include "../Renderer/Renderer.h"
#include <SDL3/SDL.h>
#include <algorithm>
#include <iostream>

namespace Dungeon::Engine {
using namespace Rendering;

Camera::Camera() {
  // #region Camera
  int index = store.RegisterItem(this);
  name = "Camera " + index;
  ComputeRect();
  // #endregion
};

void Camera::SetAsActiveCamera() {
  // #region SetAsActiveCamera
  isActive = true;
  auto &cameras = store.GetItems();
  auto it = std::find_if(cameras.begin(), cameras.end(), [](Camera *cam) { return cam->isActive; });
  if (it != cameras.end()) (*it)->isActive = false;

  activeCamera = this;
  // #endregion
}

void Camera::Render(float deltaTime) {
  SDL_SetRenderDrawColor(WindowManager::renderer, background.r, background.g, background.b,
                         background.a);
  SDL_RenderClear(WindowManager::renderer);

  std::vector<Renderer *> renderers = Renderer::store.GetItems();
  renderers.erase(std::remove_if(renderers.begin(), renderers.end(),
                                 [](Renderer *ren) { return !ren->gameObject->IsEnabled(); }),
                  renderers.end());

  // TODO: sort by zIndex

  for (Renderer *renderer : renderers) {
    Vector2 relativePosition =
        renderer->gameObject->transform->position - gameObject->transform->position;

    Vector2 normalizedPosition =
        Vector2(relativePosition.x / (width / 2), relativePosition.y / (height / 2));

    // TODO: Swap to AABB culling
    if (normalizedPosition.x < -1 || normalizedPosition.x > 1 || normalizedPosition.y < -1 ||
        normalizedPosition.y > 1)
      continue;


    Vector2 screenPosition =
        Vector2(((normalizedPosition.x * 0.5) + 0.5) * (float)WindowManager::resolutionX,
                ((-normalizedPosition.y * 0.5) + 0.5) * (float)WindowManager::resolutionY);


    float pixelsPerUnit = (float)WindowManager::resolutionX / width;
    Vector2 rendererSize =
        Vector2(renderer->size.x * pixelsPerUnit, renderer->size.y * pixelsPerUnit);


    SDL_FRect rect = {screenPosition.x - (rendererSize.x * 0.5f),
                      screenPosition.y - (rendererSize.y * 0.5f), rendererSize.x, rendererSize.y};
    renderer->Render(deltaTime, rect);
  }
}

void Camera::SetSize(float newSize) {
  size = newSize;
  ComputeRect();
}

void Camera::ComputeRect() {
  // #region ComputeRect
  width = size;
  height = width * ((float)WindowManager::resolutionY / (float)WindowManager::resolutionX);
  // #endregion
}
} // namespace Dungeon::Engine

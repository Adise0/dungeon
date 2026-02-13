#include "./Camera.h"
#include "../../../WindowManager/WindowManager.h"
#include "../Renderer/Renderer.h"
#include <SDL3/SDL.h>
#include <algorithm>

namespace Dungeon::Engine {
using namespace Rendering;
Camera::Camera() {
  // #region Camera
  int index = store.RegisterItem(this);
  name = index == 0 ? "Main Camera" : "Camera " + index;

  ComputeRect();
  // #endregion
};

void Camera::SetAsActiveCamera() {
  // #region SetAsActiveCamera
  isActive = true;
  auto it = std::find_if(store.GetItems().begin(), store.GetItems().end(),
                         [](Camera *cam) { return cam->isActive; });
  if (it != store.GetItems().end()) (*it)->isActive = false;

  activeCamera = this;
  // #endregion
}

void Camera::Render() {
  std::vector<Renderer *> renderers = Renderer::store.GetItems();
  renderers.erase(std::remove_if(renderers.begin(), renderers.end(),
                                 [](Renderer *ren) { return !ren->GetGameObject()->IsEnabled(); }),
                  renderers.end());

  // TODO: sort by zIndex

  for (Renderer *renderer : renderers) {
    Vector2 relativePosition =
        renderer->GetGameObject()->transform->position - GetGameObject()->transform->position;
    Vector2 normalizedPosition =
        Vector2(relativePosition.x / (width / 2), relativePosition.y / (height / 2));

    if (normalizedPosition.x < -1 || normalizedPosition.x > 1 || normalizedPosition.y < -1 ||
        normalizedPosition.y > 1)
      continue;

    Vector2 screenPosition =
        Vector2(((normalizedPosition.x * 0.5) + 0.5) * WindowManager::resolutionX,
                ((-normalizedPosition.y * 0.5) + 0.5) * WindowManager::resolutionY);

    float pixelsPerUnit = WindowManager::resolutionX / width;
    Vector2 rendererSize =
        Vector2(renderer->size.x * pixelsPerUnit, renderer->size.y * pixelsPerUnit);

    SDL_FRect rect = {screenPosition.x, screenPosition.y, rendererSize.x, rendererSize.y};
    renderer->Render(rect);
  }
}

void Camera::ComputeRect() {
  // #region ComputeRect
  width = size;
  height = width * (WindowManager::resolutionY / WindowManager::resolutionX);
  // #endregion
}
} // namespace Dungeon::Engine

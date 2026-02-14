#pragma once

#include "../../Component/Component.h"
#include "../../Objects/Store/Store.h"
#include <SDL3/SDL.h>

namespace Dungeon::Engine {

class Camera : public Component {
  // #region Static
public:
  static Store<Camera> store;
  inline static Camera *activeCamera = nullptr;

  // #endregion
  // #region Data
public:
  bool isActive;
  float size;
  SDL_Color background{0, 0, 0, 0};

private:
  float width;
  float height;
  // #endregion
  // #region Constructor
public:
  Camera();
  // #endregion

  // #region Methods
public:
  void SetAsActiveCamera();
  void Render(float deltaTime);
  void SetSize(float newSize);

private:
  void ComputeRect();
  // #endregion
};
} // namespace Dungeon::Engine

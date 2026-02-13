#include "../../Component/Component.h"
#include "../../Objects/Store/Store.h"

namespace Dungeon::Engine {

class Camera : public Component {
  // #region Static
public:
  Store<Camera> store;
  Camera *activeCamera;

public:
  void SetActiveCamera(Camera *camera);
  // #endregion

public:
  bool isActive;
  float size;

public:
  Camera();

public:
  void Render();
};
} // namespace Dungeon::Engine

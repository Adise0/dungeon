#include "../../Component/Component.h"
#include "../../Objects/Store/Store.h"

namespace Dungeon::Engine {

class Camera : public Component {
  // #region Static
public:
  static Store<Camera> store;
  static Camera *activeCamera;

  // #endregion
  // #region Data
public:
  bool isActive;
  float size;

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
  void Render();

private:
  void ComputeRect();
  // #endregion
};
} // namespace Dungeon::Engine

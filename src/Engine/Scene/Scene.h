#pragma once

#include "../Components/Colliders/Collider.h"
#include "../Objects/Store/Store.h"
#include "../Objects/Vector2/Vector2.h"
#include <memory>
#include <string>
#include <unordered_map>


namespace Dungeon::Engine {
class GameObject;
class Scene {
  // #region Static
public:
  static Store<Scene> store;
  static Scene *activeScene;
  static std::unordered_map<int64_t, std::vector<Collider *>> sceneColliders;
  static constexpr float ColliderCellSize = 3;
  // #endregion

  // #region Constrcutor
public:
  Scene();
  // #endregion

  // #region Data
public:
  std::unique_ptr<GameObject> root;
  bool isActive = false;
  // #endregion

  // #region Methods
  void SetAsActiveScene();

  GameObject *FindGameObjectByName(std::string name);

  void AppendCollider(Collider *collider);
  // #endregion
};
} // namespace Dungeon::Engine

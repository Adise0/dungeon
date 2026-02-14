#pragma once

#include "../Objects/Store/Store.h"
#include <memory>
#include <string>


namespace Dungeon::Engine {
class GameObject;
class Scene {
  // #region Static
public:
  Store<Scene> store;
  Scene *activeScene;
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
  // #endregion
};
} // namespace Dungeon::Engine

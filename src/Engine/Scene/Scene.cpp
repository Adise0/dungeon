#include "./Scene.h"
#include "../../Engine/Components/Camera/Camera.h"
#include "../../Engine/GameObject/GameObject.h"
#include <algorithm>
#include <iostream>

namespace Dungeon::Engine {

Scene::Scene() { store.RegisterItem(this); }

void Scene::SetAsActiveScene() {
  // #region SetAsActiveScene
  isActive = true;
  auto &scenes = store.GetItems();
  auto it =
      std::find_if(scenes.begin(), scenes.end(), [](Scene *scene) { return scene->isActive; });
  if (it != scenes.end()) (*it)->isActive = false;

  activeScene = this;

  Camera *cam = (Camera *)(FindGameObjectByName("Main Camera")->GetComponentByName("Main Camera"));
  cam->SetAsActiveCamera();
  std::cout << "Activated Main Camera" << std::endl;
  // #endregion
}

GameObject *Scene::FindGameObjectByName(std::string name) {
  // #region FindGameObjectByName
  std::vector<GameObject *> &allGameObjects = GameObject::store.GetItems();
  auto it = std::find_if(allGameObjects.begin(), allGameObjects.end(),
                         [&](GameObject *go) { return go->name == name && go->scene == this; });

  if (it == allGameObjects.end()) return nullptr;
  return *it;
  // #endregion
}
} // namespace Dungeon::Engine

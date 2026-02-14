#include "./Scene.h"
#include "../../Engine/Components/Behaviour/Behaviour.h"
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

  std::vector<GameObject *> sceneObjects = GameObject::store.GetItems();
  sceneObjects.erase(std::remove_if(sceneObjects.begin(), sceneObjects.end(),
                                    [&](GameObject *go) { return go->scene != this; }));

  for (GameObject *sceneObject : sceneObjects) {
    for (size_t i = 0; i < sceneObject->components.size(); i++) {
      if (auto *behaviour = dynamic_cast<Behaviour *>(sceneObject->components[i].get())) {
        behaviour->Awake();
      }
    }
  }


  for (GameObject *sceneObject : sceneObjects) {
    if (!sceneObject->IsEnabled()) continue;
    for (size_t i = 0; i < sceneObject->components.size(); i++) {
      if (auto *behaviour = dynamic_cast<Behaviour *>(sceneObject->components[i].get())) {
        behaviour->Start();
      }
    }
  }

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

#include "./Scene.h"
#include "../../Engine/Components/Behaviour/Behaviour.h"
#include "../../Engine/Components/Camera/Camera.h"
#include "../../Engine/GameObject/GameObject.h"
#include <SDL3/SDL.h>
#include <algorithm>
#include <iostream>

namespace Dungeon::Engine {

Store<Scene> Scene::store;
Scene *Scene::activeScene;
std::unordered_map<int64_t, std::vector<Collider *>> Scene::sceneColliders;

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

  std::vector<GameObject *> sceneObjects = GameObject::store.GetItems();
  sceneObjects.erase(std::remove_if(sceneObjects.begin(), sceneObjects.end(),
                                    [&](GameObject *go) { return go->scene != this; }),
                     sceneObjects.end());


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

void Scene::AppendCollider(Collider *collider) {
  // #region AppendCollider
  SDL_FRect rect = collider->GetBounds();

  int gridMinX = std::floor(rect.x / ColliderCellSize);
  int gridMinY = std::floor(rect.y / ColliderCellSize);

  int gridMaxX = std::floor((rect.x + rect.w) / ColliderCellSize);
  int gridMaxY = std::floor((rect.y + rect.h) / ColliderCellSize);

  for (size_t x = gridMinX; x <= gridMaxX; x++) {
    for (size_t y = gridMinY; y <= gridMaxY; y++) {
      int64_t packed = ((int64_t)x << 32) | (uint32_t)y;
      sceneColliders[packed].push_back(collider);
    }
  }
  // #endregion
}

} // namespace Dungeon::Engine

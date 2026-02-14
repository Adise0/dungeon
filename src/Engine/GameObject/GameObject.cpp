#include "GameObject.h"
#include <algorithm>
namespace Dungeon::Engine {


GameObject::GameObject(Scene *scene, std::string name) : name(name) {
  store.RegisterItem(this);
  transform = new Transform(this);
  this->scene = scene;
}
GameObject::~GameObject() {}

void GameObject::AddComponent(std::unique_ptr<Component> component) {
  // #region Component
  component->gameObject = this;
  component->transform = transform;
  components.push_back(std::move(component));
  // #endregion
}

Component *GameObject::GetComponentByName(std::string name) {

  auto it = std::find_if(components.begin(), components.end(),
                         [name](Component *c) { return c->name == name; });

  if (it == components.end()) return nullptr;
  return (*it).get();
}

} // namespace Dungeon::Engine

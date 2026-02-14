#include "GameObject.h"
#include <algorithm>
namespace Dungeon::Engine {


GameObject::GameObject(Scene *scene, std::string name) : name(name) {
  store.RegisterItem(this);
  transform = new Transform(this);
  this->scene = scene;
}
GameObject::GameObject(Scene *scene, Transform *parent, std::string name) : name(name) {
  store.RegisterItem(this);
  std::unique_ptr<Transform> original = std::make_unique<Transform>(this);
  transform = original.get();
  parent->AppendChild(std::move(original));
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
                         [name](const std::unique_ptr<Component> &c) { return c->name == name; });

  if (it == components.end()) return nullptr;
  return it->get();
}

GameObject *GameObject::CreateChild(std::string name) {
  return new GameObject(scene, transform, name);
}

} // namespace Dungeon::Engine

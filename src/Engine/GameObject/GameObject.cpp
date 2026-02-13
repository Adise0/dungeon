#include "GameObject.h"
namespace Dungeon::Engine {


GameObject::GameObject(std::string name) : name(name) {
  store.RegisterItem(this);
  transform = new Transform(this);
}
GameObject::~GameObject() {}

void GameObject::AddComponent(std::unique_ptr<Component> component) {
  // #region Component
  component->gameObject = this;
  component->transform = transform;
  components.push_back(std::move(component));
  // #endregion
}

} // namespace Dungeon::Engine

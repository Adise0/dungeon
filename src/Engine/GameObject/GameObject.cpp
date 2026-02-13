#include "GameObject.h"
namespace Dungeon::Engine {


GameObject::GameObject(std::string name) : name(name) { transform = new Transform(this); }
GameObject::~GameObject() {}

} // namespace Dungeon::Engine

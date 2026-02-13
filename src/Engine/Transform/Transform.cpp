#include "Transform.h"
#include <algorithm>
#include <stdexcept>

namespace Dungeon::Engine {

Transform::Transform(GameObject *gameObject) : gameObject(gameObject) {};

void Transform::AppendChild(std::unique_ptr<Transform> child) {
  // #region AppendChild
  if (!child) return;

  if (child->parent && child->parent != this) {
    auto detachedChild = child->parent->RemoveChild(child.get());
    if (!detachedChild) return;
    child = std::move(detachedChild);
  }
  child->parent = this;
  children.push_back(std::move(child));
  // #endregion
};

std::unique_ptr<Transform> Transform::RemoveChild(Transform *child) {
  // #region Removechild
  if (!child) return nullptr;

  auto &siblings = child->parent->children;
  auto it = std::find_if(
      siblings.begin(), siblings.end(),
      [&](const std::unique_ptr<Transform> &sibling) { return sibling.get() == child; });

  if (it == siblings.end()) return nullptr;

  auto out = std::move(*it);
  children.erase(it);
  out->parent = nullptr;
  return out;
  // #endregion
}


short Transform::GetSiblingIndex() {
  // #region GetSiblingIndex
  if (!parent) throw std::runtime_error("Cannot call GetSiblingIndex on root");
  return parent->GetChildIndex(this);
  // #endregion
}



void Transform::SetChildIndex(Transform *child, short newIndex) {
  // #region SetChildIndex
  if (!child) return;
  if (newIndex < 0 || newIndex >= children.size()) {
    throw std::runtime_error("Cannot set child to index " + std::to_string(newIndex) +
                             ". Index out of range.");
  }

  short oldIndex = GetChildIndex(child);

  auto replacedChild = std::move(children[newIndex]);
  auto childToMove = std::move(children[oldIndex]);

  children[newIndex] = nullptr;
  children[oldIndex] = nullptr;

  children[newIndex] = std::move(childToMove);
  children[oldIndex] = std::move(replacedChild);
  // #endregion
}


} // namespace Dungeon::Engine

#pragma once

#include "../Objects/Vector2/Vector2.h"
#include <memory>
#include <vector>
namespace Dungeon::Engine {

class GameObject;

class Transform {
  // #region Data
public:
  /// @brief The poistion of this transform
  Vector2 position;
  /// @brief The rotation of this transform| IN DEGREES
  float rotation = 0;
  /// @brief The scale of this transform
  Vector2 scale;


private:
  /// @brief This transform's GameObject
  GameObject *gameObject;
  /// @brief The teransform's parent
  Transform *parent = nullptr;

public:
  std::vector<std::unique_ptr<Transform>> children;
  // #endregion

  // #region Constructor
public:
  Transform(GameObject *gameObject);
  // #endregion

  // #region Methods
public:
  /// @brief Getter for this transform's GameObject
  /// @return The transform's GameObject
  GameObject *GetGameObject() { return gameObject; };
  /// @brief Getter for this transform's parent
  /// @return The transform's parent
  Transform *GetParent() { return parent; };

  void AppendChild(std::unique_ptr<Transform> child);
  Transform *GetChild(short index);
  short GetSiblingIndex();

  short GetChildIndex(Transform *child);
  void SetChildIndex(Transform *child, short newIndex);
  std::unique_ptr<Transform> RemoveChild(Transform *child);
  // #endregion
};
} // namespace Dungeon::Engine

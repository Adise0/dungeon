#include "Serializer.h"

#include <stack>
namespace Dungeon::Engine::Serialization {


Serializer::Serializer(GameObject *gameObject) : gameObject(gameObject) {};


std::string Serializer::GetGOSerializedIdString() {
  // #region GetGOSerializedIdString
  std::string stringId = "";
  std::stack<std::string> paths;

  Transform *current = gameObject->transform;
  while (current) {
    paths.push(current->GetGameObject()->name);
    current = current->GetParent();
  }

  while (!paths.empty()) {
    stringId += paths.top();
    paths.pop();
  }
  return stringId;
  // #endregion
}

int Serializer::GetStringHash(std::string stringId) {
  // #region GetStringHash
  return (int)std::hash<std::string>{}(stringId);
  // #endregion
}

int Serializer::GetGOSerializedId() {
  // #region GetGOSerializedId
  return GetStringHash(GetGOSerializedIdString());

  // #endregion
}

int Serializer::GetTSerializedId() {
  // #region GetTSerializedId
  std::string stringId = GetGOSerializedIdString();
  stringId += "T";
  return GetStringHash(stringId);
  // #endregion
}

int Serializer::GetCSerializedId(Component *component) {
  // #region GetCSerializedId
  std::string stringId = GetGOSerializedIdString();
  stringId += component->name;

  return GetStringHash(stringId);
  // #endregion
}
} // namespace Dungeon::Engine::Serialization

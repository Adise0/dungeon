#include "Serializer.h"

#include <stack>
namespace Dungeon::Engine::Serialization {


std::string Serializer::GetGOSerializedIdString(GameObject *gameObject) {
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

int Serializer::GetGOSerializedId(GameObject *gameObject) {
  // #region GetGOSerializedId
  return GetStringHash(GetGOSerializedIdString(gameObject));

  // #endregion
}

int Serializer::GetTSerializedId(GameObject *gameObject) {
  // #region GetTSerializedId
  std::string stringId = GetGOSerializedIdString(gameObject);
  stringId += "T";
  return GetStringHash(stringId);
  // #endregion
}

int Serializer::GetCSerializedId(GameObject *gameObject, Component *component) {
  // #region GetCSerializedId
  std::string stringId = GetGOSerializedIdString(gameObject);
  stringId += component->name;

  return GetStringHash(stringId);
  // #endregion
}


SerializedGO Serializer::Serialize(GameObject *gameObject) {
  // #region Serialize

  SerializedGO serializedGO;
  serializedGO.id = GetGOSerializedId(gameObject);
  serializedGO.name = gameObject->name;
  serializedGO.transform = SerializeTransform(gameObject);
  serializedGO.components = SerializeComponents(gameObject);

  std::vector<SerializedGO> serializedGOs;
  for (size_t i = 0; i < gameObject->transform->children.size(); i++) {
    GameObject *child = gameObject->transform->children[i].get()->GetGameObject();
    serializedGOs.push_back(Serialize(child));
  }
  serializedGO.children = serializedGOs;

  return serializedGO;
  // #endregion
}

SerializedTransform Serializer::SerializeTransform(GameObject *gameObject) {
  // #region SerializeTransform

  SerializedTransform serializedTransform;
  serializedTransform.id = GetTSerializedId(gameObject);
  serializedTransform.gameObject = GetGOSerializedId(gameObject);
  serializedTransform.serializedPosition = gameObject->transform->position.ToString();
  serializedTransform.rotation = gameObject->transform->rotation;
  serializedTransform.serializedScale = gameObject->transform->scale.ToString();

  return serializedTransform;
  // #endregion
}

std::vector<SerializedComponent> Serializer::SerializeComponents(GameObject *gameObject) {
  // #region SerializeComponents

  std::vector<SerializedComponent> serializedComponents;

  return serializedComponents;
  // #endregion
}

} // namespace Dungeon::Engine::Serialization

#pragma once
#include "../../GameObject/GameObject.h"
#include "../Objects/SerializedGO/SerializedGO.h"
#include "../Objects/SerializedTransform/SerializedTransform.h"
#include <string>
#include <vector>

namespace Dungeon::Engine::Serialization {
class Serializer {



  // #region Methods
public:
  static SerializedGO Serialize(GameObject *gameObject);

private:
  static std::string GetGOSerializedIdString(GameObject *gameObject);
  static int GetGOSerializedId(GameObject *gameObject);
  static int GetTSerializedId(GameObject *gameObject);
  static int GetStringHash(std::string stringId);
  static int GetCSerializedId(GameObject *gameObject, Component *component);


  static SerializedTransform SerializeTransform(GameObject *gameObject);
  static std::vector<SerializedComponent> SerializeComponents(GameObject *gameObject);
  // #endregion
};
} // namespace Dungeon::Engine::Serialization

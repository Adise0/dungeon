#pragma once
#include "../../GameObject/GameObject.h"
#include "../Objects/SerializedGO/SerializedGO.h"
#include "../Objects/SerializedTransform/SerializedTransform.h"
#include <string>

namespace Dungeon::Engine::Serialization {
class Serializer {
  // #region Data
private:
  GameObject *gameObject;
  // #endregion

  // #region Constructor
public:
  Serializer(GameObject *gameObject);
  // #endregion

  // #region Methods
public:
  SerializedGO Serialize();

private:
  std::string GetGOSerializedIdString();
  int GetGOSerializedId();
  int GetTSerializedId();
  int GetCSerializedId();
  int GetStringHash(std::string stringId);
  int GetCSerializedId(Component *component);
  // #endregion
};
} // namespace Dungeon::Engine::Serialization

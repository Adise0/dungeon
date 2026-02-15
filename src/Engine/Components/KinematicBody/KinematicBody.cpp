#include "./KinematicBody.h"
#include "../../GameObject/GameObject.h"
#include "../Colliders/Collider.h"
#include <SDL3/SDL.h>
#include <iostream>
namespace Dungeon::Engine {

KinematicBody::KinematicBody() { name = "KBody"; }

inline bool PointInRange(float v, float a, float b) {
  if (a > b) std::swap(a, b);
  return v >= a && v <= b;
}
float KinematicBody::GetTOI(Vector2 delta) {
  // #region GetTOI

  Collider *myCollider = (Collider *)(gameObject->GetComponentByName("Collider"));
  SDL_FRect myBox = myCollider->GetBounds();

  Vector2 startMin(transform->position.x - myBox.x, transform->position.y - myBox.y);
  Vector2 startMax = startMin + Vector2(myBox.w, myBox.h);

  Vector2 endPos = transform->position + delta;

  Vector2 endMin = endPos - Vector2(myBox.x, myBox.y);
  Vector2 endMax = endPos + Vector2(myBox.w, myBox.h);

  Vector2 sweepBoxMin(std::min(startMin.x, endMin.x), std::min(startMin.y, endMin.y));
  Vector2 sweepBoxMax(std::max(startMax.x, endMax.x), std::max(startMax.y, endMax.y));


  Vector2Int minCell(std::floor(sweepBoxMin.x / Scene::ColliderCellSize),
                     std::floor(sweepBoxMin.y / Scene::ColliderCellSize));
  Vector2Int maxCell(std::floor(sweepBoxMax.x / Scene::ColliderCellSize),
                     std::floor(sweepBoxMax.y / Scene::ColliderCellSize));

  Vector2 myHalf(myBox.w * 0.5f, myBox.h * 0.5f);
  Vector2 myCenter = startMin + myHalf;

  float earliestTOI = 1.0f;

  for (int x = minCell.x; x <= maxCell.x; x++) {
    for (int y = minCell.y; y <= maxCell.y; y++) {

      int64_t packed = ((int64_t)x << 32) | (uint32_t)y;

      auto it = Scene::sceneColliders.find(packed);
      if (it == Scene::sceneColliders.end()) continue;
      std::cout << "Checking cell " + std::to_string(x) + " | " + std::to_string(y) << std::endl;
      std::cout << "Found: " << it->second.size() << " colliders" << std::endl;
      for (Collider *collider : it->second) {
        if (collider == myCollider) continue;

        SDL_FRect colRect = collider->GetBounds();
        Vector2 colMin(collider->transform->position.x - colRect.x,
                       collider->transform->position.y - colRect.y);
        Vector2 colMax = colMin + Vector2(colRect.w, colRect.h);

        Vector2 expColMin = colMin - myHalf;
        Vector2 expColMax = colMax + myHalf;

        float txEntry, txExit;
        float tyEntry, tyExit;

        std::cout << "My min: " + startMin.ToString() + " My max: " + startMax.ToString()
                  << std::endl;
        std::cout << "Other min: " + colMin.ToString() + " Other max: " + colMax.ToString()
                  << std::endl;

        // X axis
        if (delta.x == 0.0f) {
          if (!PointInRange(myCenter.x, expColMin.x, expColMax.x)) continue;
          txEntry = -INFINITY;
          txExit = +INFINITY;
        } else {
          float tx1 = (expColMin.x - myCenter.x) / delta.x;
          float tx2 = (expColMax.x - myCenter.x) / delta.x;
          txEntry = std::min(tx1, tx2);
          txExit = std::max(tx1, tx2);
        }

        // Y axis
        if (delta.y == 0.0f) {
          if (!PointInRange(myCenter.y, expColMin.y, expColMax.y)) continue;
          tyEntry = -INFINITY;
          tyExit = +INFINITY;
        } else {
          float ty1 = (expColMin.y - myCenter.y) / delta.y;
          float ty2 = (expColMax.y - myCenter.y) / delta.y;
          tyEntry = std::min(ty1, ty2);
          tyExit = std::max(ty1, ty2);
        }

        float entryTime = std::max(txEntry, tyEntry);
        float exitTime = std::min(txExit, tyExit);

        if (entryTime > exitTime) continue;
        if (exitTime < 0.0f) continue;
        if (entryTime > 1.0f) continue;

        float toi = std::max(0.0f, entryTime);
        toi = std::max(0.0f, toi - kSkin);

        if (toi < earliestTOI) {
          earliestTOI = toi;
        }
      }
    }
  }
  return earliestTOI;
  // #endregion
}
} // namespace Dungeon::Engine

#include "./Store.h"

namespace Dungeon::Engine {
template <typename StoreType> int Store<StoreType>::RegisterItem(StoreType *item) {
  // #region RegisterItem
  int currentIndex = store.size();
  store.push_back(item);
  return currentIndex;
  // #endregion
}

template <typename StoreType> void Store<StoreType>::UnregisterItem(StoreType *item) {
  // #region UnregisterItem
  auto it = std::remove(store.begin(), store.end(), item);
  if (it != store.end()) store.erase(it, store.end());
  // #endregion
}

} // namespace Dungeon::Engine

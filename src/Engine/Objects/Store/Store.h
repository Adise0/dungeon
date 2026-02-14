#pragma once

#include <algorithm>
#include <vector>
namespace Dungeon::Engine {

template <typename StoreType> class Store {
private:
  /// @brief The store
  inline static std::vector<StoreType *> store{};

public:
  /// @brief Registers the item to the store
  /// @param item The item to register
  static int RegisterItem(StoreType *item) {
    // #region RegisterItem
    int currentIndex = store.size();
    store.push_back(item);
    return currentIndex;
    // #endregion
  }
  /// @brief Unregisters the item from the store
  /// @param item The item to unregister
  static void UnregisterItem(StoreType *item) {
    // #region UnregisterItem
    auto it = std::remove(store.begin(), store.end(), item);
    if (it != store.end()) store.erase(it, store.end());
    // #endregion
  }



public:
  /// @brief Getter for the item store
  /// @return The item store
  static std::vector<StoreType *> &GetItems() { return store; }
};
} // namespace Dungeon::Engine

#pragma once

#include <vector>
namespace Dungeon::Engine {

template <typename StoreType> class Store {
private:
  /// @brief The store
  static std::vector<StoreType *> store;

public:
  /// @brief Registers the item to the store
  /// @param item The item to register
  static int RegisterItem(StoreType *item);
  /// @brief Unregisters the item from the store
  /// @param item The item to unregister
  static void UnregisterItem(StoreType *item);

public:
  /// @brief Getter for the item store
  /// @return The item store
  static std::vector<StoreType *> GetItems() { return store; };
};
} // namespace Dungeon::Engine

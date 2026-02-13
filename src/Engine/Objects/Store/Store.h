#pragma once

namespace Dungeon::Engine {

template <typename StoreType> class Store {
private:
  /// @brief The store
  static std::vector<StoreType *> store;

private:
  /// @brief Registers the item to the store
  /// @param behaviour The item to register
  static void RegisterItem(StoreType *item);
  /// @brief Unregisters the item from the store
  /// @param behaviour The item to unregister
  static void UnregisterBehaviour(StoreType *item);

public:
  /// @brief Getter for the item store
  /// @return The item store
  static std::vector<StoreType *> GetItems() { return store; };
};
} // namespace Dungeon::Engine

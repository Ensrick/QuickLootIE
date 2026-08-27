#pragma once

namespace QuickLoot::Policies
{
	template <class Owner>
	[[nodiscard]] constexpr Owner* ResolveEffectiveItemOwner(
		Owner* entryOwner,
		Owner* actorOwner,
		Owner* containerOwner) noexcept
	{
		return entryOwner ? entryOwner : (actorOwner ? actorOwner : containerOwner);
	}

	[[nodiscard]] constexpr bool ShouldCheckItemRemovalPermission(
		bool isPlayerInventory,
		bool isDeadActor,
		bool hasEffectiveOwner) noexcept
	{
		return !isPlayerInventory && !isDeadActor && hasEffectiveOwner;
	}

	[[nodiscard]] constexpr bool IsItemRemovalTheft(
		bool isPlayerInventory,
		bool isDeadActor,
		bool hasEffectiveOwner,
		bool playerMayTakeItem) noexcept
	{
		return ShouldCheckItemRemovalPermission(isPlayerInventory, isDeadActor, hasEffectiveOwner) && !playerMayTakeItem;
	}
}

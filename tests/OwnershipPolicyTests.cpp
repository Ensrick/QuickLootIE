#include <catch2/catch_test_macros.hpp>

#include "Policies/OwnershipPolicy.h"

using namespace QuickLoot::Policies;

TEST_CASE("Effective item ownership follows entry, actor, then container precedence", "[items][ownership]")
{
	int entryOwner{};
	int actorOwner{};
	int containerOwner{};

	CHECK(ResolveEffectiveItemOwner(&entryOwner, &actorOwner, &containerOwner) == &entryOwner);
	CHECK(ResolveEffectiveItemOwner<int>(nullptr, &actorOwner, &containerOwner) == &actorOwner);
	CHECK(ResolveEffectiveItemOwner<int>(nullptr, nullptr, &containerOwner) == &containerOwner);
	CHECK(ResolveEffectiveItemOwner<int>(nullptr, nullptr, nullptr) == nullptr);
}

TEST_CASE("Theft requires a live foreign source, an owner, and denied permission", "[items][ownership]")
{
	CHECK_FALSE(ShouldCheckItemRemovalPermission(true, false, true));
	CHECK_FALSE(ShouldCheckItemRemovalPermission(false, true, true));
	CHECK_FALSE(ShouldCheckItemRemovalPermission(false, false, false));
	CHECK(ShouldCheckItemRemovalPermission(false, false, true));

	CHECK_FALSE(IsItemRemovalTheft(true, false, true, false));
	CHECK_FALSE(IsItemRemovalTheft(false, true, true, false));
	CHECK_FALSE(IsItemRemovalTheft(false, false, false, false));
	CHECK_FALSE(IsItemRemovalTheft(false, false, true, true));
	CHECK(IsItemRemovalTheft(false, false, true, false));
}

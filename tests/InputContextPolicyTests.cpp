#include <catch2/catch_test_macros.hpp>

#include "Policies/InputContextPolicy.h"

using namespace QuickLoot::Policies;

TEST_CASE("Flatrim input context follows the 1.6.1130 marketplace boundary", "[input][runtime]")
{
	CHECK(SelectFlatrimInputContext(0) == PRE_MARKETPLACE_NONE_INPUT_CONTEXT);
	CHECK(SelectFlatrimInputContext(1129) == PRE_MARKETPLACE_NONE_INPUT_CONTEXT);
	CHECK(SelectFlatrimInputContext(1130) == POST_MARKETPLACE_NONE_INPUT_CONTEXT);
	CHECK(SelectFlatrimInputContext(1170) == POST_MARKETPLACE_NONE_INPUT_CONTEXT);
	CHECK(SelectFlatrimInputContext(1179) == POST_MARKETPLACE_NONE_INPUT_CONTEXT);
}

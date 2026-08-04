#pragma once

#include <cstdint>

namespace QuickLoot::Policies
{
	// CommonLibSSE-NG's all-runtime Context::kNone cannot express the flatrim
	// value that moved when the Marketplace context was added in 1.6.1130.
	inline constexpr std::uint32_t PRE_MARKETPLACE_NONE_INPUT_CONTEXT = 18;
	inline constexpr std::uint32_t POST_MARKETPLACE_NONE_INPUT_CONTEXT = 19;
	inline constexpr std::uint32_t MARKETPLACE_CONTEXT_RUNTIME_PATCH = 1130;

	[[nodiscard]] constexpr std::uint32_t SelectFlatrimInputContext(std::uint32_t runtimePatch) noexcept
	{
		return runtimePatch >= MARKETPLACE_CONTEXT_RUNTIME_PATCH ?
		           POST_MARKETPLACE_NONE_INPUT_CONTEXT :
		           PRE_MARKETPLACE_NONE_INPUT_CONTEXT;
	}
}

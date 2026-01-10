#pragma once

#include <RE/Skyrim.h>
#include <SKSE/SKSE.h>

namespace stl
{
	using namespace SKSE::stl;

	template <class T>
	void write_thunk_jump(std::uintptr_t a_src)
	{
		auto& trampoline = SKSE::GetTrampoline();
		T::func = trampoline.write_branch<5>(a_src, T::thunk);
	}
}

namespace logs = SKSE::log;
using namespace std::literals;

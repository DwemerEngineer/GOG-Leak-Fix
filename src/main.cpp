struct ReplaceRelease
{
	static void thunk(RE::BSGraphics::Renderer* renderer, RE::BSGraphics::Texture* tex)
	{
		if (_InterlockedExchangeAdd(&tex->unk20, 0xFFFFFFFF) == 1) {
			if(tex->resourceView)
				tex->resourceView->Release();
			if (tex->texture) 
				tex->texture->Release();
			if (tex->unk08)
				reinterpret_cast<ID3D11UnorderedAccessView*>(tex->unk08)->Release();

			REL::Relocation<void (void*, int)> NiMemFee{ RELOCATION_ID(102158, 109588) };
			NiMemFee(tex, 0x28);
		}

		return;
	}
	static inline REL::Relocation<decltype(thunk)> func;

	static void Install()
	{
		stl::write_thunk_jump<ReplaceRelease>(RELOCATION_ID(75527, 77322).address());
	}

};

SKSEPluginLoad(const SKSE::LoadInterface* a_skse)
{
	SKSE::Init(a_skse);

	SKSE::AllocTrampoline(14);
	ReplaceRelease::Install();

	return true;
}

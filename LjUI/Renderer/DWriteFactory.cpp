#include "DWriteFactory.h"

namespace ljui
{
	namespace renderer
	{

		IDWriteFactory* DWriteFactory::factory = nullptr;
		IDWriteFactory* DWriteFactory::GetDWriteFactory()
		{
			if (factory == nullptr)
			{
				HRESULT hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED,
					__uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&factory));
				if (!SUCCEEDED(hr))
					return nullptr;
			}
			return factory;
		}

	}//namespace renderer
}//namespace ljui
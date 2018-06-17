#include "RenderFactory.h"

namespace ljui
{
	namespace renderer
	{
		/*
		class RenderFactory
		*/
		ID2D1Factory *RenderFactory::factory = nullptr;
		ID2D1Factory* RenderFactory::GetRenderFactory()
		{
			if (factory == nullptr)
			{
				HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);
				if (!SUCCEEDED(hr))
					return nullptr;
			}
			return factory;
		}

	}//namespace renderer
}//namespace ljui
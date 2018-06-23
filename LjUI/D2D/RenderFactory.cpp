#include "RenderFactory.h"

namespace ljui
{
	namespace renderer
	{
		/*
		class RenderFactory
		*/
		ID2D1Factory *RenderFactory::_factory = nullptr;
		ID2D1Factory* RenderFactory::GetRenderFactory()
		{
			if (_factory == nullptr)
			{
				HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &_factory);
				if (!SUCCEEDED(hr))
					return nullptr;
			}
			return _factory;
		}

	}//namespace renderer
}//namespace ljui
#include "DWriteFactory.h"

namespace ljui
{
	namespace renderer
	{

		IDWriteFactory* DWriteFactory::_factory = nullptr;
		IDWriteFactory* DWriteFactory::GetOriginalDWriteFactory()
		{
			if (_factory == nullptr)
			{
				HRESULT hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED,
					__uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&_factory));
				if (!SUCCEEDED(hr))
					return nullptr;
			}
			return _factory;
		}

		HRESULT DWriteFactory::CreateTextLayout(const std::wstring str, TextFormat* text_format,
			types::FLOAT max_width, types::FLOAT max_height, TextLayout** text_layout)
		{
			return GetOriginalDWriteFactory()->CreateTextLayout(str.c_str(), str.size(), text_format, max_width, max_height, text_layout);
		}
	}//namespace renderer
}//namespace ljui
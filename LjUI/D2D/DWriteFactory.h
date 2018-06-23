#ifndef _YL_DWRITEFACTORY_H_
#define _YL_DWRITEFACTORY_H_

#pragma comment(lib,"dwrite.lib")
#include "../Types/Types.h"
#include "D2DTypes.h"

namespace ljui
{
	namespace renderer
	{
		class DWriteFactory
		{
		public:
			static IDWriteFactory* GetOriginalDWriteFactory();
			static HRESULT CreateTextLayout(const std::wstring str, TextFormat* text_format,
				types::FLOAT max_width, types::FLOAT max_height, TextLayout** text_layout);
		private:
			static IDWriteFactory* _factory;
			DWriteFactory();
		};
	}//namespace renderer
}//namespace ljui

#endif
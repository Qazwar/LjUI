#ifndef _YL_DWRITEFACTORY_H_
#define _YL_DWRITEFACTORY_H_

#include <dwrite.h>
#pragma comment(lib,"dwrite.lib")

namespace ljui
{
	namespace renderer
	{
		class DWriteFactory
		{
		public:
			static IDWriteFactory* GetDWriteFactory();
		private:
			static IDWriteFactory* factory;
			DWriteFactory();
		};
	}//namespace renderer
}//namespace ljui

#endif
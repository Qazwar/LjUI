#ifndef _YL_RENDERFACTORY_H_
#define _YL_RENDERFACTORY_H_

#include <d2d1.h>

namespace ljui
{
	namespace renderer
	{
		class RenderFactory
		{
		public:
			static ID2D1Factory* GetRenderFactory();
		private:
			static ID2D1Factory * factory;
			RenderFactory();
		};

	}//namespace renderer
}//namespace ljui

#endif
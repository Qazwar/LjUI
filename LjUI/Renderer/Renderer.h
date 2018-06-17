

#ifndef _YL_RENDERER_H_
#define _YL_RENDERER_H_

#include <d2d1.h>
#pragma comment(lib,"d2d1.lib")

#include <windows.h>
#include "../Types/Types.h"

namespace ljui
{
	namespace renderer
	{
		/*
		defines
		*/
		using SolidBrush = ID2D1SolidColorBrush;


		class RenderFactory
		{
		public:
			static ID2D1Factory* GetRenderFactory();
		private:
			static ID2D1Factory * factory;
			RenderFactory();
		};

		class HwndRenderer
		{
		public:
			bool Initialized()const;
			HRESULT Initialize(HWND hwnd, types::SizeU size);
			HWND GetHwnd()const;
			HRESULT Resize(const types::SizeU& size);
			HRESULT Resize(types::SizeU* size);

			void BeginDraw();
			HRESULT EndDraw();


		private:
			HWND hwnd_ = NULL;
			ID2D1HwndRenderTarget* hwnd_render_target_ = nullptr;
		};

	}//namespace renderer
}//namespace ljui

#endif
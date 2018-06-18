#ifndef _YL_HWNDRENDERER_H_
#define _YL_HWNDRENDERER_H_

#include "IRenderer.h"


namespace ljui
{
	namespace renderer
	{
		class HwndRenderer :public IRenderer
		{
		public:
			virtual bool Initialized()const;
			virtual HRESULT Initialize(HWND hwnd, types::SizeU size);
			HRESULT Resize(const types::SizeU& size);
			HRESULT Resize(types::SizeU* size);
			HWND GetHwnd()const;
		private:
			HWND hwnd_;
		};
	}
}



#endif
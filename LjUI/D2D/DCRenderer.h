#ifndef _YL_DCRENDERER_H_
#define _YL_DCRENDERER_H_

#include "BaseRenderer.h"
namespace ljui
{
	namespace renderer
	{
		class DCRender :public BaseRenderer
		{
		public:
			virtual bool Initialized()const override;
			virtual HRESULT Initialize(types::TRenderTargetProperties* property = nullptr);
			HRESULT BindDC(const HDC hdc, const types::Rect* rect);
			HRESULT BindDC(const HDC hdc, const types::Rect& rect);
			HDC GetDC()const;
		private:
			HDC _hdc = nullptr;
		};

	}//namespace renderer
}//namespace ljui

#endif
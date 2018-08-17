#include "DCRenderer.h"
#include "RenderFactory.h"

namespace ljui
{
	namespace renderer
	{

		bool DCRender::Initialized()const
		{
			return _hdc != nullptr && _render_target != nullptr;
		}

		HRESULT DCRender::Initialize(types::TRenderTargetProperties* property)
		{
			//default property
			HRESULT hr = S_OK;
			if (property == nullptr)
			{
				D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(
					D2D1_RENDER_TARGET_TYPE_DEFAULT,
					D2D1::PixelFormat(
						DXGI_FORMAT_B8G8R8A8_UNORM,
						D2D1_ALPHA_MODE_IGNORE),
					0, 0,
					D2D1_RENDER_TARGET_USAGE_NONE,
					D2D1_FEATURE_LEVEL_DEFAULT
				);
				hr = RenderFactory::GetRenderFactory()->CreateDCRenderTarget(&props, (reinterpret_cast<ID2D1DCRenderTarget**>(&_render_target)));
			}
			else
			{
				hr = RenderFactory::GetRenderFactory()->CreateDCRenderTarget(property, (reinterpret_cast<ID2D1DCRenderTarget**>(&_render_target)));
			}
			return hr;
		}

		HRESULT DCRender::BindDC(const HDC hdc, const types::Rect* rect)
		{
			_hdc = hdc;
			return dynamic_cast<ID2D1DCRenderTarget*>(_render_target)->BindDC(hdc, rect);;
		}

		HRESULT DCRender::BindDC(const HDC hdc, const types::Rect& rect)
		{
			return BindDC(hdc, &rect);
		}

		HDC DCRender::GetDC()const
		{
			return _hdc;
		}
	}//namespace renderer
}//namespace ljui
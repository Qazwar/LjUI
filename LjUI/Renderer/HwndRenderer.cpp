#include "HwndRenderer.h"
#include <typeinfo>
namespace ljui
{
	namespace renderer
	{
		bool HwndRenderer::Initialized()const
		{
			return hwnd_ != NULL && render_target_ != nullptr;
		}

		HRESULT HwndRenderer::Initialize(HWND hwnd, types::SizeU size)
		{
			hwnd_ = hwnd;
			return RenderFactory::GetRenderFactory()->CreateHwndRenderTarget(
				D2D1::RenderTargetProperties(),
				D2D1::HwndRenderTargetProperties(reinterpret_cast<HWND>(hwnd_), size),
				reinterpret_cast<ID2D1HwndRenderTarget**>(&render_target_));
		}

		HRESULT HwndRenderer::Resize(const types::SizeU& size)
		{
			return reinterpret_cast<ID2D1HwndRenderTarget*>(render_target_)->Resize(size);
		}

		HRESULT HwndRenderer::Resize(types::SizeU* size)
		{
			return reinterpret_cast<ID2D1HwndRenderTarget*>(render_target_)->Resize(size);
		}

		HWND HwndRenderer::GetHwnd()const
		{
			return hwnd_;
		}
	}//namespace renderer
}//namespace ljui
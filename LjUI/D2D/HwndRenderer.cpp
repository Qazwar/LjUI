#include "HwndRenderer.h"

namespace ljui
{
	namespace renderer
	{
		bool HwndRenderer::Initialized()const
		{
			return _hwnd != nullptr && _render_target != nullptr;
		}

		HRESULT HwndRenderer::Initialize(HWND hwnd, types::SizeU size)
		{
			_hwnd = hwnd;
			return RenderFactory::GetRenderFactory()->CreateHwndRenderTarget(
				D2D1::RenderTargetProperties(),
				D2D1::HwndRenderTargetProperties(reinterpret_cast<HWND>(_hwnd), size),
				reinterpret_cast<ID2D1HwndRenderTarget**>(&_render_target));
		}

		HRESULT HwndRenderer::Resize(const types::SizeU& size)
		{
			return reinterpret_cast<ID2D1HwndRenderTarget*>(_render_target)->Resize(size);
		}

		HRESULT HwndRenderer::Resize(types::SizeU* size)
		{
			return reinterpret_cast<ID2D1HwndRenderTarget*>(_render_target)->Resize(size);
		}

		HWND HwndRenderer::GetHwnd()const
		{
			return _hwnd;
		}
	}//namespace renderer
}//namespace ljui
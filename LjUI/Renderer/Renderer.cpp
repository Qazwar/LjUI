#include "Renderer.h"

namespace ljui
{

	namespace renderer
	{

		/*
		class HwndRenderer
		*/

		bool HwndRenderer::Initialized()const
		{
			return hwnd_ != NULL && hwnd_render_target_ != nullptr;
		}

		HRESULT HwndRenderer::Initialize(HWND hwnd, types::SizeU size)
		{
			hwnd_ = hwnd;
			return RenderFactory::GetRenderFactory()->CreateHwndRenderTarget(
				D2D1::RenderTargetProperties(),
				D2D1::HwndRenderTargetProperties(hwnd_, size),
				&hwnd_render_target_);
		}

		HWND HwndRenderer::GetHwnd() const
		{
			return hwnd_render_target_->GetHwnd();
		}

		HRESULT HwndRenderer::Resize(const types::SizeU& size)
		{
			return hwnd_render_target_->Resize(size);
		}

		HRESULT HwndRenderer::Resize(types::SizeU* size)
		{
			return hwnd_render_target_->Resize(size);
		}

		void HwndRenderer::BeginDraw()
		{
			hwnd_render_target_->BeginDraw();
		}

		HRESULT HwndRenderer::EndDraw()
		{
			return hwnd_render_target_->EndDraw();
		}

	}//namespace renderer
}//namespace ljui
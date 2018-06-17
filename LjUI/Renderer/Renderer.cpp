#include "Renderer.h"

namespace ljui
{

	namespace renderer
	{

		/*
		class RenderFactory
		*/
		ID2D1Factory *RenderFactory::factory = nullptr;
		ID2D1Factory* RenderFactory::GetRenderFactory()
		{
			if (factory == nullptr)
			{
				HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);
				if (!SUCCEEDED(hr))
					return nullptr;
			}
			return factory;
		}

		/*
		class HwndRenderer
		*/

		bool HwndRenderer::Initialized()const
		{
			return hwnd_ != NULL && hwnd_render_target_ != nullptr;
		}

		HRESULT HwndRenderer::Initialize(HWND hwnd, types::SizeU size)
		{
			if (hwnd_ == NULL || hwnd_render_target_ == nullptr)
				return false;
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
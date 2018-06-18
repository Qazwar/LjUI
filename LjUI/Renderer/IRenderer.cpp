#include "IRenderer.h"

namespace ljui
{

	namespace renderer
	{
		void IRenderer::BeginDraw()
		{
			render_target_->BeginDraw();
		}

		HRESULT IRenderer::EndDraw()
		{
			return render_target_->EndDraw();
		}

		void IRenderer::Clear(const types::ColorF& color)
		{
			render_target_->Clear(color);
		}

		void IRenderer::Clear(types::ColorF* color)
		{
			render_target_->Clear(color);
		}

		void IRenderer::Clear(types::KnownColors color)
		{
			render_target_->Clear(types::ColorF(color));
		}

		LRESULT IRenderer::CreateSolidColorBrush(const types::ColorF& color, SolidColorBrush** ppBrush)
		{
			return render_target_->CreateSolidColorBrush(color, ppBrush);
		}

		void IRenderer::DrawEllipse(const types::Ellipse& ellipse, SolidColorBrush* brush, types::FLOAT width)
		{
			render_target_->DrawEllipse(const_cast<types::Ellipse&>(ellipse), brush, width);
		}

		void IRenderer::DrawEllipse(types::Ellipse* ellipse, SolidColorBrush* brush, types::FLOAT width)
		{
			render_target_->DrawEllipse(*ellipse, brush, width);
		}

		void IRenderer::DrawLine(types::Point2F point0, types::Point2F point1, SolidColorBrush *brush, types::FLOAT strokeWidth)
		{
			render_target_->DrawLine(point0, point1, brush, strokeWidth);
		}

		void IRenderer::DrawRectangle(const types::RectF &rect, Brush *brush, types::FLOAT strokeWidth)
		{
			render_target_->DrawRectangle(rect, brush, strokeWidth);
		}

		void IRenderer::DrawRectangle(types::RectF* rect, Brush *brush, types::FLOAT strokeWidth)
		{
			render_target_->DrawRectangle(rect, brush, strokeWidth);
		}

		void IRenderer::DrawRoundedRectangle(const types::RoundRect &roundedRect, Brush *brush, types::FLOAT strokeWidth)
		{
			render_target_->DrawRoundedRectangle((const_cast<types::RoundRect&>(roundedRect)), brush, strokeWidth);
		}

		void IRenderer::DrawRoundedRectangle(types::RoundRect* roundedRect, Brush *brush, types::FLOAT strokeWidth)
		{
			render_target_->DrawRoundedRectangle(*roundedRect, brush, strokeWidth);
		}

		void IRenderer::FillEllipse(const types::Ellipse &ellipse, Brush *brush)
		{
			render_target_->FillEllipse(const_cast<types::Ellipse&>(ellipse), brush);
		}

		void IRenderer::FillEllipse(types::Ellipse* ellipse, Brush *brush)
		{
			render_target_->FillEllipse(*ellipse, brush);
		}

		void IRenderer::FillRectangle(const types::RectF& rect, Brush *brush)
		{
			render_target_->FillRectangle(rect, brush);
		}

		void IRenderer::FillRectangle(types::RectF* rect, Brush *brush)
		{
			render_target_->FillRectangle(*rect, brush);
		}

		void IRenderer::FillRoundedRectangle(const types::RoundRect &roundedRect, Brush *brush)
		{
			render_target_->FillRoundedRectangle(const_cast<types::RoundRect&>(roundedRect), brush);
		}

		void IRenderer::FillRoundedRectangle(types::RoundRect* roundedRect, Brush *brush)
		{
			render_target_->FillRoundedRectangle(*roundedRect, brush);
		}


		void IRenderer::SetAntialiasMode(ANTIALIAS_MODE antialiasMode)
		{
			render_target_->SetAntialiasMode(static_cast<D2D1_ANTIALIAS_MODE>(antialiasMode));
		}

		ANTIALIAS_MODE IRenderer::GetAntialiasMode()const
		{
			return static_cast<ANTIALIAS_MODE>(render_target_->GetAntialiasMode());
		}

		void IRenderer::SetTextAntialiasMode(TEXT_ANTIALIAS_MODE textAntialiasMode)
		{
			render_target_->SetTextAntialiasMode(static_cast<D2D1_TEXT_ANTIALIAS_MODE>(textAntialiasMode));
		}

		TEXT_ANTIALIAS_MODE IRenderer::GetTextAntialiasMode()const
		{
			return static_cast<TEXT_ANTIALIAS_MODE>(render_target_->GetTextAntialiasMode());
		}

	}//namespace renderer
}//namespace ljui
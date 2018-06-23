#include "BaseRenderer.h"

namespace ljui
{

	namespace renderer
	{
		void BaseRenderer::BeginDraw()
		{
			_render_target->BeginDraw();
		}

		HRESULT BaseRenderer::EndDraw()
		{
			return _render_target->EndDraw();
		}

		void BaseRenderer::Clear(const types::ColorF& color)
		{
			_render_target->Clear(color);
		}

		void BaseRenderer::Clear(types::ColorF* color)
		{
			_render_target->Clear(color);
		}

		void BaseRenderer::Clear(types::KnownColors color)
		{
			_render_target->Clear(types::ColorF(color));
		}

		LRESULT BaseRenderer::CreateSolidColorBrush(const types::ColorF& color, SolidColorBrush** ppBrush)
		{
			return _render_target->CreateSolidColorBrush(color, ppBrush);
		}

		void BaseRenderer::DrawEllipse(const types::Ellipse& ellipse, SolidColorBrush* brush, types::FLOAT width)
		{
			_render_target->DrawEllipse(const_cast<types::Ellipse&>(ellipse), brush, width);
		}

		void BaseRenderer::DrawEllipse(types::Ellipse* ellipse, SolidColorBrush* brush, types::FLOAT width)
		{
			_render_target->DrawEllipse(*ellipse, brush, width);
		}

		void BaseRenderer::DrawLine(types::Point2F point0, types::Point2F point1, SolidColorBrush* brush, types::FLOAT stroke_width)
		{
			_render_target->DrawLine(point0, point1, brush, stroke_width);
		}

		void BaseRenderer::DrawRectangle(const types::RectF& rect, Brush* brush, types::FLOAT stroke_width)
		{
			_render_target->DrawRectangle(rect, brush, stroke_width);
		}

		void BaseRenderer::DrawRectangle(types::RectF* rect, Brush* brush, types::FLOAT stroke_width)
		{
			_render_target->DrawRectangle(rect, brush, stroke_width);
		}

		void BaseRenderer::DrawRoundedRectangle(const types::RoundRect& rounded_rect, Brush* brush, types::FLOAT stroke_width)
		{
			_render_target->DrawRoundedRectangle((const_cast<types::RoundRect&>(rounded_rect)), brush, stroke_width);
		}

		void BaseRenderer::DrawRoundedRectangle(types::RoundRect* rounded_rect, Brush* brush, types::FLOAT stroke_width)
		{
			_render_target->DrawRoundedRectangle(*rounded_rect, brush, stroke_width);
		}

		void BaseRenderer::DrawText(std::wstring str, UINT string_len, TextFormat* text_format, const types::RectF& layout_rect,
			Brush* brush, DrawTextOptions options, MeasuringMode measuring_mode)
		{
			_render_target->DrawTextW(str.c_str(), string_len, text_format, layout_rect, brush,
				static_cast<D2D1_DRAW_TEXT_OPTIONS>(options), static_cast<DWRITE_MEASURING_MODE>(measuring_mode));
		}

		void BaseRenderer::DrawText(std::wstring str, UINT string_len, TextFormat* text_format, const types::RectF* layout_rect,
			Brush* brush, DrawTextOptions options, MeasuringMode measuring_mode)
		{
			_render_target->DrawTextW(str.c_str(), string_len, text_format, *layout_rect, brush,
				static_cast<D2D1_DRAW_TEXT_OPTIONS>(options), static_cast<DWRITE_MEASURING_MODE>(measuring_mode));
		}

		void BaseRenderer::DrawTextLayout(types::Point2F origin, TextLayout* text_layout,
			Brush* brush, DrawTextOptions options)
		{
			_render_target->DrawTextLayout(origin, text_layout, brush, static_cast<D2D1_DRAW_TEXT_OPTIONS>(options));
		}

		void BaseRenderer::FillEllipse(const types::Ellipse& ellipse, Brush* brush)
		{
			_render_target->FillEllipse(const_cast<types::Ellipse&>(ellipse), brush);
		}

		void BaseRenderer::FillEllipse(types::Ellipse* ellipse, Brush* brush)
		{
			_render_target->FillEllipse(*ellipse, brush);
		}

		void BaseRenderer::FillRectangle(const types::RectF& rect, Brush* brush)
		{
			_render_target->FillRectangle(rect, brush);
		}

		void BaseRenderer::FillRectangle(types::RectF* rect, Brush* brush)
		{
			_render_target->FillRectangle(*rect, brush);
		}

		void BaseRenderer::FillRoundedRectangle(const types::RoundRect& rounded_rect, Brush* brush)
		{
			_render_target->FillRoundedRectangle(const_cast<types::RoundRect&>(rounded_rect), brush);
		}

		void BaseRenderer::FillRoundedRectangle(types::RoundRect* rounded_rect, Brush* brush)
		{
			_render_target->FillRoundedRectangle(*rounded_rect, brush);
		}


		void BaseRenderer::SetAntialiasMode(ANTIALIAS_MODE antialias_mode)
		{
			_render_target->SetAntialiasMode(static_cast<D2D1_ANTIALIAS_MODE>(antialias_mode));
		}

		ANTIALIAS_MODE BaseRenderer::GetAntialiasMode()const
		{
			return static_cast<ANTIALIAS_MODE>(_render_target->GetAntialiasMode());
		}

		void BaseRenderer::SetTextAntialiasMode(TEXT_ANTIALIAS_MODE text_antialias_mode)
		{
			_render_target->SetTextAntialiasMode(static_cast<D2D1_TEXT_ANTIALIAS_MODE>(text_antialias_mode));
		}

		TEXT_ANTIALIAS_MODE BaseRenderer::GetTextAntialiasMode()const
		{
			return static_cast<TEXT_ANTIALIAS_MODE>(_render_target->GetTextAntialiasMode());
		}

		HRESULT BaseRenderer::Flush()
		{
			return _render_target->Flush();
		}
	}//namespace renderer
}//namespace ljui
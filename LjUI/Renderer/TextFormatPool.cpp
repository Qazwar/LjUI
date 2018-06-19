#include "TextFormatPool.h"

namespace ljui
{
	namespace renderer
	{

		bool operator==(const TextFormatRequiredProperty& lhs, const TextFormatRequiredProperty& rhs)
		{
			return (lhs.font_collection == rhs.font_collection) &&
				(lhs.font_family == rhs.font_family) &&
				(lhs.font_size == rhs.font_size) &&
				(lhs.font_stretch == rhs.font_stretch) &&
				(lhs.font_style == rhs.font_style) &&
				(lhs.font_weight == rhs.font_weight);
		}

		bool operator<(const TextFormatRequiredProperty& lhs, const TextFormatRequiredProperty& rhs)
		{
			return !(lhs == rhs);
		}


		TextFormatPool* TextFormatPool::text_format_pool = nullptr;

		TextFormatPool* TextFormatPool::GetTextFormatPool()
		{
			if (!text_format_pool)
			{
				text_format_pool = new TextFormatPool;
			}
			return text_format_pool;
		}

		TextFormat* TextFormatPool::CreateResource(const TextFormatRequiredProperty& _property)
		{
			TextFormat* text_format;
			HRESULT hr = DWriteFactory::GetDWriteFactory()->CreateTextFormat(_property.font_family.c_str(), nullptr,
				static_cast<DWRITE_FONT_WEIGHT>(_property.font_weight), static_cast<DWRITE_FONT_STYLE>(_property.font_style),
				static_cast<DWRITE_FONT_STRETCH>(_property.font_stretch), _property.font_size, L"", &text_format);
			if (SUCCEEDED(hr))
			{
				return text_format;
			}
			else
			{
				return nullptr;
			}
		}

		TextFormat* TextFormatPool::CreateResource(const TextFormatRequiredProperty& _property, const TextFormatAlternativeProperty& _alt_property)
		{
			TextFormat* text_format = CreateResource(_property);
			if (text_format)
			{
				text_format->SetParagraphAlignment(static_cast<DWRITE_PARAGRAPH_ALIGNMENT>(_alt_property.paragraph_alignment));
				text_format->SetTextAlignment(static_cast<DWRITE_TEXT_ALIGNMENT>(_alt_property.text_alignment));
				text_format->SetWordWrapping(static_cast<DWRITE_WORD_WRAPPING>(_alt_property.word_wrapping));
			}
			return text_format;
		}

	}//namespace renderer
}//namespace ljui
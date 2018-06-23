#ifndef _YL_D2DTYPES_H_
#define _YL_D2DTYPES_H_
#include <d2d1.h>
#include <dwrite.h>
#include <string>
namespace ljui
{
	namespace renderer
	{

		using Brush = ID2D1Brush;
		using SolidColorBrush = ID2D1SolidColorBrush;

		enum ANTIALIAS_MODE
		{
			ANTIALIAS_MODE_PER_PRIMITIVE = 0,
			ANTIALIAS_MODE_ALIASED = 1
		};
		enum TEXT_ANTIALIAS_MODE
		{
			TEXT_ANTIALIAS_MODE_DEFAULT = 0,
			TEXT_ANTIALIAS_MODE_CLEARTYPE = 1,
			TEXT_ANTIALIAS_MODE_GRAYSCALE = 2,
			TEXT_ANTIALIAS_MODE_ALIASED = 3
		};

		enum DrawTextOptions
		{
			DRAW_TEXT_OPTIONS_NO_SNAP = 0x00000001,
			DRAW_TEXT_OPTIONS_CLIP = 0x00000002,
			DRAW_TEXT_OPTIONS_ENABLE_COLOR_FONT = 0x00000004,
			DRAW_TEXT_OPTIONS_DISABLE_COLOR_BITMAP_SNAPPING = 0x00000008,
			DRAW_TEXT_OPTIONS_NONE = 0x00000000,
			DRAW_TEXT_OPTIONS_FORCE_DWORD = 0xffffffff
		};

		enum MeasuringMode
		{
			MEASURING_MODE_NATURAL,
			MEASURING_MODE_GDI_CLASSIC,
			MEASURING_MODE_GDI_NATURAL
		};

		using FontCollection = IDWriteFontCollection;

		enum FontWeight
		{
			FONT_WEIGHT_THIN = 100,
			FONT_WEIGHT_EXTRA_LIGHT = 200,
			FONT_WEIGHT_ULTRA_LIGHT = 200,
			FONT_WEIGHT_LIGHT = 300,
			FONT_WEIGHT_SEMI_LIGHT = 350,
			FONT_WEIGHT_NORMAL = 400,
			FONT_WEIGHT_REGULAR = 400,
			FONT_WEIGHT_MEDIUM = 500,
			FONT_WEIGHT_DEMI_BOLD = 600,
			FONT_WEIGHT_SEMI_BOLD = 600,
			FONT_WEIGHT_BOLD = 700,
			FONT_WEIGHT_EXTRA_BOLD = 800,
			FONT_WEIGHT_ULTRA_BOLD = 800,
			FONT_WEIGHT_BLACK = 900,
			FONT_WEIGHT_HEAVY = 900,
			FONT_WEIGHT_EXTRA_BLACK = 950,
			FONT_WEIGHT_ULTRA_BLACK = 950
		};

		enum FontStyle
		{
			FONT_STYLE_NORMAL = 0,
			FONT_STYLE_OBLIQUE = 1,
			FONT_STYLE_ITALIC = 2
		};

		enum FontStretch
		{
			FONT_STRETCH_UNDEFINED = 0,
			FONT_STRETCH_ULTRA_CONDENSED = 1,
			FONT_STRETCH_EXTRA_CONDENSED = 2,
			FONT_STRETCH_CONDENSED = 3,
			FONT_STRETCH_SEMI_CONDENSED = 4,
			FONT_STRETCH_NORMAL = 5,
			FONT_STRETCH_MEDIUM = 5,
			FONT_STRETCH_SEMI_EXPANDED = 6,
			FONT_STRETCH_EXPANDED = 7,
			FONT_STRETCH_EXTRA_EXPANDED = 8,
			FONT_STRETCH_ULTRA_EXPANDED = 9
		};

		struct TextFormatRequiredProperty
		{
			std::wstring font_family = L"Microsoft YaHei";
			FontCollection* font_collection = nullptr;
			FontWeight font_weight = FontWeight::FONT_WEIGHT_NORMAL;
			FontStyle font_style = FontStyle::FONT_STYLE_NORMAL;
			FontStretch font_stretch = FontStretch::FONT_STRETCH_NORMAL;
			types::FLOAT font_size = 15;
			std::wstring local_name = L"";
		};

		bool operator==(const TextFormatRequiredProperty& lhs, const TextFormatRequiredProperty& rhs);
		bool operator<(const TextFormatRequiredProperty& lhs, const TextFormatRequiredProperty& rhs);

		enum ParagraphAlignment
		{
			PARAGRAPH_ALIGNMENT_NEAR,
			PARAGRAPH_ALIGNMENT_FAR,
			PARAGRAPH_ALIGNMENT_CENTER
		};

		enum TextAlignment
		{
			TEXT_ALIGNMENT_LEADING,
			TEXT_ALIGNMENT_TRAILING,
			TEXT_ALIGNMENT_CENTER,
			TEXT_ALIGNMENT_JUSTIFIED
		};

		enum WordWrapping
		{
			WORD_WRAPPING_WRAP = 0,
			WORD_WRAPPING_NO_WRAP = 1,
			WORD_WRAPPING_EMERGENCY_BREAK = 2,
			WORD_WRAPPING_WHOLE_WORD = 3,
			WORD_WRAPPING_CHARACTER = 4,
		};

		struct TextFormatAlternativeProperty
		{
			ParagraphAlignment paragraph_alignment = ParagraphAlignment::PARAGRAPH_ALIGNMENT_CENTER;
			TextAlignment text_alignment = TextAlignment::TEXT_ALIGNMENT_CENTER;
			WordWrapping word_wrapping = WordWrapping::WORD_WRAPPING_NO_WRAP;
		};

		using TextFormat = IDWriteTextFormat;

		using TextLayout = IDWriteTextLayout;

	}//namespace renderer
}//namespace ljui

#endif
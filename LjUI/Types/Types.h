
#ifndef _YL_TYPES_H_
#define _YL_TYPES_H_

#include <d2d1.h>

namespace ljui
{
	namespace types
	{
		using uint32 = UINT32;
		using FLOAT = float;
		using SizeU = D2D1_SIZE_U;
		SizeU MakeSizeU(uint32 width, uint32 height);
		using SizeF = D2D1_SIZE_F;
		using ColorF = D2D1::ColorF;
		using KnownColors = ColorF::Enum;
		typedef struct Point2F
		{
			FLOAT x;
			FLOAT y;
		public:
			Point2F() :x(0), y(0) {};
			Point2F(FLOAT _x, FLOAT _y) :x(_x), y(_y) {};
			operator D2D1_POINT_2F();
		} Point2F;
		typedef struct Ellipse
		{
			Point2F point;
			FLOAT radiusX;
			FLOAT radiusY;
		public:
			operator D2D1_ELLIPSE();
		}Ellipse;
		using Rect = RECT;
		using RectF = D2D1_RECT_F;
		using RectL = D2D1_RECT_L;
		using RectU = D2D1_RECT_U;
		typedef struct RoundRect
		{
			RectF rect;
			FLOAT       radiusX;
			FLOAT       radiusY;
		public:
			operator D2D1_ROUNDED_RECT();
		}RoundRect;

		using TRenderTargetProperties = D2D1_RENDER_TARGET_PROPERTIES;
		namespace d2d = D2D1;
	}//namespace type
}//namespace ljui


#endif








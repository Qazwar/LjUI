#include "Types.h"

namespace ljui
{
	namespace types
	{

		SizeU MakeSizeU(uint32 width, uint32 height)
		{
			return D2D1::SizeU(width, height);
		}

		Point2F::operator D2D1_POINT_2F()
		{
			D2D1_POINT_2F pt;
			pt.x = x;
			pt.y = y;
			return pt;
		}

		Ellipse::operator D2D1_ELLIPSE()
		{
			D2D1_ELLIPSE e;
			e.point.x = point.x;
			e.point.y = point.y;
			e.radiusX = radiusX;
			e.radiusY = radiusY;
			return e;
		}

		RoundRect::operator D2D1_ROUNDED_RECT()
		{
			D2D1_ROUNDED_RECT rrc;
			rrc.rect = rect;
			rrc.radiusX = radiusX;
			rrc.radiusY = radiusY;
			return rrc;
		}
	}//namespace type
}//namespace ljui
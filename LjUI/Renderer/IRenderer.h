#ifndef _YL_IRENDERER_H_
#define _YL_IRENDERER_H_

#include <d2d1.h>
#pragma comment(lib,"d2d1.lib")

#include <windows.h>
#include "../Types/Types.h"
#include "RenderFactory.h"
#include "TextFormatPool.h"

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

		class IRenderer
		{
		public:
			virtual bool Initialized()const = 0;
			virtual void BeginDraw();
			virtual HRESULT EndDraw();

			virtual void Clear(const types::ColorF& color);
			virtual void Clear(types::ColorF* color);
			virtual void Clear(types::KnownColors color);

			virtual LRESULT CreateSolidColorBrush(const types::ColorF& color, SolidColorBrush** ppBrush);
			virtual void DrawEllipse(const types::Ellipse& ellipse, SolidColorBrush* brush, types::FLOAT width);
			virtual void DrawEllipse(types::Ellipse* ellipse, SolidColorBrush* brush, types::FLOAT width);
			virtual void DrawLine(types::Point2F point0, types::Point2F point1, SolidColorBrush* brush, types::FLOAT stroke_width = 1.0f);
			virtual void DrawRectangle(const types::RectF& rect, Brush* brush, types::FLOAT stroke_width = 1.0f);
			virtual void DrawRectangle(types::RectF* rect, Brush* brush, types::FLOAT stroke_width = 1.0f);
			virtual void DrawRoundedRectangle(const types::RoundRect& rounded_rect, Brush* brush, types::FLOAT stroke_width = 1.0f);
			virtual void DrawRoundedRectangle(types::RoundRect* rounded_rect, Brush* brush, types::FLOAT stroke_width = 1.0f);
			virtual void DrawText(std::wstring str, UINT string_len, TextFormat* text_format, const types::RectF& layout_rect,
				Brush* brush, DrawTextOptions options = DrawTextOptions::DRAW_TEXT_OPTIONS_NONE,
				MeasuringMode measuring_mode = MeasuringMode::MEASURING_MODE_NATURAL);
			virtual void DrawText(std::wstring str, UINT string_len, TextFormat* text_format, const types::RectF* layout_rect,
				Brush* brush, DrawTextOptions options = DrawTextOptions::DRAW_TEXT_OPTIONS_NONE,
				MeasuringMode measuring_mode = MeasuringMode::MEASURING_MODE_NATURAL);
			virtual void FillEllipse(const types::Ellipse& ellipse, Brush* brush);
			virtual void FillEllipse(types::Ellipse* ellipse, Brush* brush);
			virtual void FillRectangle(const types::RectF& rect, Brush* brush);
			virtual void FillRectangle(types::RectF* rect, Brush* brush);
			virtual void FillRoundedRectangle(const types::RoundRect& rounded_rect, Brush* brush);
			virtual void FillRoundedRectangle(types::RoundRect* rounded_rect, Brush* brush);

			virtual void SetAntialiasMode(ANTIALIAS_MODE antialias_mode);
			virtual ANTIALIAS_MODE GetAntialiasMode()const;
			virtual void SetTextAntialiasMode(TEXT_ANTIALIAS_MODE text_antialias_mode);
			virtual TEXT_ANTIALIAS_MODE GetTextAntialiasMode()const;
			virtual HRESULT Flush();

		protected:
			ID2D1RenderTarget * render_target_ = nullptr;
		};

		/*todo::

CreateBitmap
创建 Direct2D 位图。（3 个重载。）

CreateBitmapBrush
从指定位图创建 ID2D1BitmapBrush。（4 个重载。）

CreateBitmapFromWicBitmap
通过复制指定的 Microsoft Windows 图像处理组件 (WIC) 位图，创建 ID2D1Bitmap。（3 个重载。）

CreateCompatibleRenderTarget
创建与当前呈现器目标兼容的新位图呈现器目标，以供在中间屏幕外绘制期间使用。（6 个重载。）

CreateGradientStopCollection
从指定的 D2D1_GRADIENT_STOP 结构数组创建 ID2D1GradientStopCollection。（2 个重载。）

CreateLayer
创建可用于此呈现器目标及其兼容的呈现器目标的层资源。（3 个重载。）

CreateLinearGradientBrush
创建 ID2D1LinearGradientBrush 对象，以便使用线性渐变绘制区域。（3 个重载。）

CreateMesh
创建一个使用三角形来描述形状的网格。

CreateRadialGradientBrush
创建 ID2D1RadialGradientBrush 对象，该对象可用于使用径向渐变来绘制区域。（3 个重载。）

CreateSharedBitmap
创建其数据与另一个资源共享的 ID2D1Bitmap。

DrawBitmap
绘制指定的 ID2D1Bitmap。（3 个重载。）

DrawGeometry
使用指定笔画样式绘制指定几何对象的轮廓。

DrawGlyphRun
绘制指定字形。

DrawTextLayout
绘制由指定 IDWriteTextLayout 对象描述的格式化文本。

FillGeometry
绘制指定几何对象的内部区域。

FillMesh
绘制指定网格的内部区域。

FillOpacityMask
将由指定位图描述的不透明蒙板应用于画笔，并使用该画笔来绘制呈现器目标的区域。（2 个重载。）

Flush
执行所有挂起的绘制命令。

GetAntialiasMode
检索用于非文本绘制操作的当前抗锯齿模式。

GetDpi
返回呈现器目标的每英寸点数 (DPI)。

GetMaximumBitmapSize
获取呈现器目标所支持的任何一个位图尺寸的最大大小，以与设备有关的单位（像素）来表示。

GetPixelFormat
检索呈现器目标的像素格式和 Alpha 模式。

GetPixelSize
返回以设备像素表示的呈现器目标大小。

GetSize
返回以与设备无关的像素表示的呈现器目标大小。

GetTags
获取用于后续绘制操作的标签。

GetTextAntialiasMode
获取用于文本和字形绘制操作的当前抗锯齿模式。

GetTextRenderingParams
检索呈现器目标的当前文本呈现选项。

GetTransform
获取呈现器目标的当前转换。

IsSupported
指示呈现器目标是否支持指定的属性。

PopAxisAlignedClip
从呈现器目标中删除最后一个轴对齐剪辑。调用此方法后，该剪辑不再应用于后续绘制操作。

PopLayer
停止将绘制操作重定向到由最后一个 PushLayer 调用指定的层。

PushAxisAlignedClip
指定一个矩形，将按其对所有后续绘制操作进行剪辑。（2 个重载。）

PushLayer
将指定的层添加到呈现器目标，以便呈现器目标接收所有后续绘制操作，直至调用 PopLayer。（2 个重载。）

RestoreDrawingState
将呈现器目标的绘制状态设置为指定 ID2D1DrawingStateBlock 的状态。

SaveDrawingState
将当前绘制状态保存到指定的 ID2D1DrawingStateBlock。

SetDpi
设置呈现器目标的每英寸点数 (DPI)。

SetTags
指定用于后续绘制操作的标签。

SetTextRenderingParams
指定将应用于所有后续文本和字形绘制操作的文本呈现选项。

SetTransform
将指定转换应用于呈现器目标，替换现有转换。所有后续绘制操作都将在转换后的空间中执行。（2 个重载。）
		*/
	}//namespace renderer
}//namespace ljui

#endif
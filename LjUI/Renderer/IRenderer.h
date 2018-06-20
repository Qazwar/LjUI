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
���� Direct2D λͼ����3 �����ء���

CreateBitmapBrush
��ָ��λͼ���� ID2D1BitmapBrush����4 �����ء���

CreateBitmapFromWicBitmap
ͨ������ָ���� Microsoft Windows ͼ������� (WIC) λͼ������ ID2D1Bitmap����3 �����ء���

CreateCompatibleRenderTarget
�����뵱ǰ������Ŀ����ݵ���λͼ������Ŀ�꣬�Թ����м���Ļ������ڼ�ʹ�á���6 �����ء���

CreateGradientStopCollection
��ָ���� D2D1_GRADIENT_STOP �ṹ���鴴�� ID2D1GradientStopCollection����2 �����ء���

CreateLayer
���������ڴ˳�����Ŀ�꼰����ݵĳ�����Ŀ��Ĳ���Դ����3 �����ء���

CreateLinearGradientBrush
���� ID2D1LinearGradientBrush �����Ա�ʹ�����Խ���������򡣣�3 �����ء���

CreateMesh
����һ��ʹ����������������״������

CreateRadialGradientBrush
���� ID2D1RadialGradientBrush ���󣬸ö��������ʹ�þ��򽥱����������򡣣�3 �����ء���

CreateSharedBitmap
��������������һ����Դ����� ID2D1Bitmap��

DrawBitmap
����ָ���� ID2D1Bitmap����3 �����ء���

DrawGeometry
ʹ��ָ���ʻ���ʽ����ָ�����ζ����������

DrawGlyphRun
����ָ�����Ρ�

DrawTextLayout
������ָ�� IDWriteTextLayout ���������ĸ�ʽ���ı���

FillGeometry
����ָ�����ζ�����ڲ�����

FillMesh
����ָ��������ڲ�����

FillOpacityMask
����ָ��λͼ�����Ĳ�͸���ɰ�Ӧ���ڻ��ʣ���ʹ�øû��������Ƴ�����Ŀ������򡣣�2 �����ء���

Flush
ִ�����й���Ļ������

GetAntialiasMode
�������ڷ��ı����Ʋ����ĵ�ǰ�����ģʽ��

GetDpi
���س�����Ŀ���ÿӢ����� (DPI)��

GetMaximumBitmapSize
��ȡ������Ŀ����֧�ֵ��κ�һ��λͼ�ߴ������С�������豸�йصĵ�λ�����أ�����ʾ��

GetPixelFormat
����������Ŀ������ظ�ʽ�� Alpha ģʽ��

GetPixelSize
�������豸���ر�ʾ�ĳ�����Ŀ���С��

GetSize
���������豸�޹ص����ر�ʾ�ĳ�����Ŀ���С��

GetTags
��ȡ���ں������Ʋ����ı�ǩ��

GetTextAntialiasMode
��ȡ�����ı������λ��Ʋ����ĵ�ǰ�����ģʽ��

GetTextRenderingParams
����������Ŀ��ĵ�ǰ�ı�����ѡ�

GetTransform
��ȡ������Ŀ��ĵ�ǰת����

IsSupported
ָʾ������Ŀ���Ƿ�֧��ָ�������ԡ�

PopAxisAlignedClip
�ӳ�����Ŀ����ɾ�����һ���������������ô˷����󣬸ü�������Ӧ���ں������Ʋ�����

PopLayer
ֹͣ�����Ʋ����ض��������һ�� PushLayer ����ָ���Ĳ㡣

PushAxisAlignedClip
ָ��һ�����Σ�����������к������Ʋ������м�������2 �����ء���

PushLayer
��ָ���Ĳ���ӵ�������Ŀ�꣬�Ա������Ŀ��������к������Ʋ�����ֱ������ PopLayer����2 �����ء���

RestoreDrawingState
��������Ŀ��Ļ���״̬����Ϊָ�� ID2D1DrawingStateBlock ��״̬��

SaveDrawingState
����ǰ����״̬���浽ָ���� ID2D1DrawingStateBlock��

SetDpi
���ó�����Ŀ���ÿӢ����� (DPI)��

SetTags
ָ�����ں������Ʋ����ı�ǩ��

SetTextRenderingParams
ָ����Ӧ�������к����ı������λ��Ʋ������ı�����ѡ�

SetTransform
��ָ��ת��Ӧ���ڳ�����Ŀ�꣬�滻����ת�������к������Ʋ���������ת����Ŀռ���ִ�С���2 �����ء���
		*/
	}//namespace renderer
}//namespace ljui

#endif
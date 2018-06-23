#ifndef _YL_TEXTFORMATPOOL_H_
#define _YL_TEXTFORMATPOOL_H_

#include "IResourcePool.h"
#include "../Types/Types.h"
#include "D2DTypes.h"
#include "DWriteFactory.h"

namespace ljui
{
	namespace renderer
	{

		class TextFormatPool :public IResourcePool<TextFormatRequiredProperty, TextFormatAlternativeProperty, TextFormat>
		{
		public:
			static TextFormatPool* GetTextFormatPool();
		private:
			static TextFormatPool* _text_format_pool;
			TextFormatPool() {};
		protected:
			virtual TextFormat* CreateResource(const TextFormatRequiredProperty& _property)override;
			virtual TextFormat* CreateResource(const TextFormatRequiredProperty& _property, const TextFormatAlternativeProperty& _alt_property)override;
			virtual void SetAlternativeProperty(TextFormat* text_format, const TextFormatAlternativeProperty& _alt_property)override;
		};

	}//namespace renderer
}//namespace ljui

#endif
#ifndef _YL_IRESOURCEPOOL_H_
#define _YL_IRESOURCEPOOL_H_

#include <map>

namespace ljui
{
	namespace renderer
	{
		template<typename RequiredProperty, typename AlternativeProperty, typename Resource>
		class IResourcePool
		{
		public:
			Resource * GetResource(const RequiredProperty& _property);
			Resource* GetResource(const RequiredProperty& _property, const AlternativeProperty& _alt_property);
		protected:
			std::map<RequiredProperty, Resource*> resources_;
			virtual Resource* CreateResource(const RequiredProperty& _property) = 0;
			virtual Resource* CreateResource(const RequiredProperty& _property, const AlternativeProperty& _alt_property) = 0;
			virtual void SetAlternativeProperty(Resource* res, const AlternativeProperty& _alt_property) = 0;
		};

		template<typename RequiredProperty, typename AlternativeProperty, typename Resource>
		Resource* IResourcePool<RequiredProperty, AlternativeProperty, Resource>::GetResource(const RequiredProperty& _property)
		{

			auto it = resources_.find(_property);

			if (it != resources_.end())
			{
				return it->second;
			}
			else
			{
				auto res = CreateResource(_property);
				resources_.insert(std::make_pair(_property, res));
				return res;
			}
		}

		template<typename RequiredProperty, typename AlternativeProperty, typename Resource>
		Resource* IResourcePool<RequiredProperty, AlternativeProperty, Resource>::
			GetResource(const RequiredProperty& _property, const AlternativeProperty& _alt_property)
		{

			Resource* res = GetResource(_property);
			SetAlternativeProperty(res, _alt_property);
			return res;
		}
	}//namespace renderer
}//namespace ljui

#endif
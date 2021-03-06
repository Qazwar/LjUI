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
			virtual void ReleaseResource(Resource* resource){}
			virtual ~IResourcePool();
		protected:
			std::map<RequiredProperty, Resource*> _resources;
			virtual Resource* CreateResource(const RequiredProperty& _property) = 0;
			virtual Resource* CreateResource(const RequiredProperty& _property, const AlternativeProperty& _alt_property) = 0;
			virtual void SetAlternativeProperty(Resource* res, const AlternativeProperty& _alt_property) = 0;
		};

		template<typename RequiredProperty, typename AlternativeProperty, typename Resource>
		Resource* IResourcePool<RequiredProperty, AlternativeProperty, Resource>::
			GetResource(const RequiredProperty& _property)
		{

			auto it = _resources.find(_property);

			if (it != _resources.end())
			{
				return it->second;
			}
			else
			{
				auto res = CreateResource(_property);
				_resources.insert(std::make_pair(_property, res));
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

		template<typename RequiredProperty, typename AlternativeProperty, typename Resource>
		IResourcePool<RequiredProperty, AlternativeProperty, Resource>::
			~IResourcePool()
		{
			for (auto& p : _resources)
			{
				ReleaseResource(p.second);
			}
		}

	}//namespace renderer
}//namespace ljui

#endif
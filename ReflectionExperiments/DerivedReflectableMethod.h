#pragma once
#include <functional>
#include <assert.h>
#include "ReflectableMethod.h"

template<class ownerT, class rtnT, class... paramsTs>
class DerivedReflectableMethod : public ReflectableMethod
{
public:
   DerivedReflectableMethod( std::function<rtnT( ownerT&, paramsTs&&... )>&& method, Reflectable& owner, const char* name ) : ReflectableMethod( owner, name )
   {
      m_Method = std::move( method );
   }

protected:
   void* GetMethodPtr( const std::type_info& inputType ) override
   {
      assert( typeid(std::function<rtnT( ownerT&, paramsTs&&... )>).hash_code() == inputType.hash_code() );

      return static_cast<void*>(&m_Method);
   }

private:
   std::function<rtnT( ownerT&, paramsTs&&... )> m_Method;
};

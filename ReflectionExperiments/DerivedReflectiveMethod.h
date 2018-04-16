#pragma once
#include <functional>
#include <assert.h>
#include "ReflectiveMethod.h"

template<int id, class qualifiedOwnerT, class rtnT, class... paramsTs>
class DerivedReflectiveMethod : public ReflectiveMethod<typename std::decay<qualifiedOwnerT>::type>
{
public:
   static DerivedReflectiveMethod<id, qualifiedOwnerT, rtnT, paramsTs...>& Instance( std::function<rtnT( qualifiedOwnerT&, paramsTs&&... )>&& method, const char* name )
   {
      static DerivedReflectiveMethod<id, qualifiedOwnerT, rtnT, paramsTs...> instance;
      instance.Init( std::move( method ), name );
      return instance;
   }

protected:
   void* GetMethodPtr( const std::type_info& inputType ) override
   {
      assert( typeid(std::function<rtnT( qualifiedOwnerT&, paramsTs&&... )>).hash_code() == inputType.hash_code() );
      return static_cast<void*>(&m_Method);
   }

private:

   DerivedReflectiveMethod()
   {
      m_FirstInit = true;
   }

   void Init( std::function<rtnT( qualifiedOwnerT&, paramsTs&&... )>&& method, const char* name )
   {
      if (m_FirstInit)
      {
         m_FirstInit = false;
         m_Method = std::move( method );
         Register( name );
      }
   }

   std::function<rtnT( qualifiedOwnerT&, paramsTs&&... )> m_Method;
   bool m_FirstInit;
};

#pragma once
#include <functional>
#include <assert.h>
#include "ReflectableMethod.h"

template<int id, class qualifiedOwnerT, class rtnT, class... paramsTs>
class DerivedReflectableMethod : public ReflectableMethod<typename std::decay<qualifiedOwnerT>::type>
{
   friend typename std::decay<qualifiedOwnerT>::type;

protected:
   void* GetMethodPtr( const std::type_info& inputType ) override
   {
      assert( typeid(std::function<rtnT( qualifiedOwnerT&, paramsTs&&... )>).hash_code() == inputType.hash_code() );
      return static_cast<void*>(&m_Method);
   }

private:

   DerivedReflectableMethod()
   {
      m_FirstInit = true;
   }

   static DerivedReflectableMethod<id, qualifiedOwnerT, rtnT, paramsTs...>& Instance( std::function<rtnT( qualifiedOwnerT&, paramsTs&&... )>&& method, const char* name )
   {
      static DerivedReflectableMethod<id, qualifiedOwnerT, rtnT, paramsTs...> instance;
      instance.Init( std::move( method ), name );
      return instance;
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

#pragma once
#include <typeinfo>
#include "Reflection.h"

template<class ownerT>
class ReflectableMethod
{
public:
   template<class T>
   T GetMethod()
   {
      return *(static_cast<T*>(GetMethodPtr( typeid(T) )));
   }

   template<class rtnT, class... paramsTs>
   rtnT Invoke( ownerT& owner, paramsTs&&... params )
   {
      auto method = GetMethod<std::function<rtnT( ownerT&, paramsTs&&... )>>();

      return method( owner, std::forward<paramsTs>( params )... );
   }

   template<class rtnT, class... paramsTs>
   rtnT Invoke( const ownerT& owner, paramsTs&&... params )
   {
      auto method = GetMethod<std::function<rtnT( const ownerT&, paramsTs&&... )>>();

      return method( owner, std::forward<paramsTs>( params )... );
   }

protected:
   virtual void* GetMethodPtr( const std::type_info& inputType ) = 0;

   void Register( const char* name )
   {
      Reflection<ownerT>::Instance().Register( *this, name );
   }
};

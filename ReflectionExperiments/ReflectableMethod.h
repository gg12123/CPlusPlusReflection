#pragma once
#include <typeinfo>

class Reflectable;

class ReflectableMethod
{
public:
   ReflectableMethod( Reflectable& owner, const char* name );

public:

   template<class T>
   T GetMethod()
   {
      return *(static_cast<T*>(GetMethodPtr( typeid(T) )));
   }

   template<class ownerT, class rtnT, class... paramsTs>
   rtnT Invoke( ownerT& owner, paramsTs&&... params )
   {
      auto method = GetMethod<std::function<rtnT( ownerT&, paramsTs&&... )>>();

      return method( owner, std::forward<paramsTs>( params )... );
   }

protected:
   virtual void* GetMethodPtr( const std::type_info& inputType ) = 0;
};

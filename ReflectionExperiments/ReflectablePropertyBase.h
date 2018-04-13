#pragma once
#include <string>
#include <typeinfo>

class Reflectable;

class ReflectablePropertyBase
{
public:
   ReflectablePropertyBase( Reflectable& owner, std::string name );

   template<class T>
   T GetValue()
   {
      return *(static_cast<T*>(GetValuePtr( typeid(T) )));
   }

   template<class T>
   void SetValue( T value )
   {
      SetValue( static_cast<void*>(&value), typeid(T) );
   }

protected:
   virtual void* GetValuePtr( const std::type_info& inputType ) = 0;
   virtual void SetValue( void* value , const std::type_info& inputType ) = 0;
};

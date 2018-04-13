#pragma once
#include <assert.h>
#include "ReflectablePropertyBase.h"

template<class T>
class ReflectableProperty : public ReflectablePropertyBase
{
public:
   ReflectableProperty( T& prop, Reflectable& owner, std::string name ) : ReflectablePropertyBase( owner, std::move( name ) )
   {
      m_Property = &prop;
   }

protected:
   void* GetValuePtr( const std::type_info& inputType ) override
   {
      assert( inputType.hash_code() == typeid(T).hash_code() );
      return static_cast<void*>(m_Property);
   }

   void SetValue( void* value, const std::type_info& inputType ) override
   {
      assert( inputType.hash_code() == typeid(T).hash_code() );
      *m_Property = *(static_cast<T*>(value));
   }

private:
   T* m_Property;
};
#pragma once
#include <assert.h>
#include "ReflectableProperty.h"

template<class T>
class DerivedReflectableProperty : public ReflectableProperty
{
public:
   DerivedReflectableProperty( T& prop, Reflectable& owner, const char* name ) : ReflectableProperty( owner, name )
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

      *m_Property = std::move( *(static_cast<T*>(value)) ); // The move is safe because a value is passed into the base
   }

private:
   T* m_Property;
};
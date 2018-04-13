#pragma once
#include <assert.h>
#include "ReflectableProperty.h"

template<class T>
class DerivedReflectableProperty : public ReflectableProperty
{
public:
   DerivedReflectableProperty( T& prop, Reflectable& owner, std::string name ) : ReflectableProperty( owner, std::move( name ) )
   {
      m_Property = &prop;
   }

protected:
   void* GetValuePtr( const std::type_info& inputType ) override
   {
      assert( inputType.hash_code() == typeid(T).hash_code() );
      return static_cast<void*>(m_Property);
   }

   void SetValue( const void* value, const std::type_info& inputType ) override
   {
      assert( inputType.hash_code() == typeid(T).hash_code() );
      *m_Property = *(static_cast<const T*>(value));
   }

private:
   T* m_Property;
};
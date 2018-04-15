#pragma once
#include <typeinfo>
#include "Reflection.h"

template<class ownerT>
class ReflectableProperty
{
public:
   template<class propT>
   propT GetValue( const ownerT& owner )
   {
      AssertCorrectPropType( typeid(propT) );

      const char * ptr = reinterpret_cast<const char*>(&owner);
      ptr += GetOffset( owner );

      return *(reinterpret_cast<const propT*>(ptr));
   }

   template<class propT>
   void SetValue( ownerT& owner, propT prop )
   {
      AssertCorrectPropType( typeid(propT) );

      char * ptr = reinterpret_cast<char*>(&owner);
      ptr += GetOffset( owner );

      *(reinterpret_cast<propT*>(ptr)) = std::move( prop );
   }

protected:
   virtual void AssertCorrectPropType( const type_info& inputType ) = 0;
   virtual size_t GetOffset( const ownerT& owner ) = 0;

   void Register( const char* propName )
   {
      dynamic_cast<Reflection<ownerT>&>(Reflection<ownerT>::Instance()).Register( *this, propName );
   }
};

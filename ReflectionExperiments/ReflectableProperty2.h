#pragma once
#include <typeinfo>
#include "Reflection2.h"

template<class ownerT>
class ReflectableProperty2
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
      Reflection2<ownerT>::Instance().Register( *this, propName );
   }
};

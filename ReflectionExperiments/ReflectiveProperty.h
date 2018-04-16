#pragma once
#include <typeinfo>
#include "Reflection.h"
#include "Reflective.h"

template<class ownerT>
class ReflectiveProperty : public Reflective
{
public:
   template<class propT>
   propT GetValue( const ownerT& owner )
   {
      AssertCorrectPropType( typeid(propT) );
      return *(static_cast<const propT*>(GetValuePtr( owner )));
   }

   template<class propT>
   void SetValue( ownerT& owner, propT prop )
   {
      AssertCorrectPropType( typeid(propT) );
      SetValue( owner, static_cast<void*>(&prop) );
   }

protected:
   virtual void AssertCorrectPropType( const type_info& inputType ) = 0;
   virtual const void* GetValuePtr( const ownerT& owner ) = 0;
   virtual void SetValue( ownerT& owner, void* ptrToValue ) = 0;

   void Register( const char* propName )
   {
      SetName( propName );
      dynamic_cast<Reflection<ownerT>&>(Reflection<ownerT>::Instance()).Register( *this, propName );
   }
};

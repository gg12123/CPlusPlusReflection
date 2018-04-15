#pragma once
#include <assert.h>
#include "ReflectableProperty.h"

template<class propT, class ownerT, int id>
class DerivedReflectableProperty : public ReflectableProperty<ownerT>
{
public:
   static DerivedReflectableProperty<propT, ownerT, id>& Instance( propT ownerT::*member, const char* name )
   {
      static DerivedReflectableProperty<propT, ownerT, id> instance;
      instance.Init( member, name );
      return instance;
   }

protected:
   void AssertCorrectPropType( const type_info& inputType ) override
   {
      assert( inputType.hash_code() == typeid(propT).hash_code() );
   }

   size_t GetOffset( const ownerT& owner ) override
   {
      return size_t( &(owner.*m_Member) ) - size_t( &owner );
   }

private:
   DerivedReflectableProperty()
   {
      m_FirstInit = true;
   }

   void Init( propT ownerT::*member, const char* name )
   {
      if (m_FirstInit)
      {
         m_FirstInit = false;
         m_Member = member;
         Register( name );
      }
   }

   bool m_FirstInit;
   propT ownerT::*m_Member;
};
#pragma once
#include <assert.h>
#include "ReflectableProperty2.h"

template<class propT, class ownerT, const char* propName>
class DerivedReflectableProperty2 : public ReflectableProperty2<ownerT>
{
public:

   static DerivedReflectableProperty2<propT, ownerT, const char* propName>& Instance( propT ownerT::*member )
   {
      static DerivedReflectableProperty2<propT, ownerT, propName> instance;
      instance.Init( member );
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

   DerivedReflectableProperty2()
   {
      m_FirstInit = true;
   }

   void Init( propT ownerT::*member )
   {
      if (m_FirstInit)
      {
         m_FirstInit = false;
         m_Member = member;
         Register( propName );
      }
   }

   bool m_FirstInit;
   propT ownerT::*m_Member;
};
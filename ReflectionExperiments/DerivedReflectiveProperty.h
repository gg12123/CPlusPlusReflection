#pragma once
#include <assert.h>
#include "ReflectiveProperty.h"

template<class propT, class ownerT, int id>
class DerivedReflectiveProperty : public ReflectiveProperty<ownerT>
{
public:
   static DerivedReflectiveProperty<propT, ownerT, id>& Instance( propT ownerT::*member, const char* name )
   {
      static DerivedReflectiveProperty<propT, ownerT, id> instance;
      instance.Init( member, name );
      return instance;
   }

protected:
   void AssertCorrectPropType( const type_info& inputType ) override
   {
      assert( inputType.hash_code() == typeid(propT).hash_code() );
   }

   const void* GetValuePtr( const ownerT& owner ) override
   {
      return static_cast<const void*>(&(owner.*m_Member));
   }

   void SetValue(ownerT& owner, void* ptrToValue) override
   {
      owner.*m_Member = std::move( *(static_cast<propT*>(ptrToValue)) ); // move is safe becasue a copy is passed to the base.
   }

private:
   DerivedReflectiveProperty()
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
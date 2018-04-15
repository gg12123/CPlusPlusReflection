#include "stdafx.h"
#include "ReflectionIncludes.h"
#include <iostream>

class SomeOtherReflectable
{
   MAKE_REFLECTABLE( SomeOtherReflectable );

public:
   SomeOtherReflectable()
   {
   }

   REFLECTABLE_PROPERTY( int, m_OtherProp );
};

class TestReflectable
{
   MAKE_REFLECTABLE( TestReflectable );

public:
   TestReflectable()
   {
      m_Prop = 1;
   }

private:
   REFLECTABLE_PROPERTY( int, m_Prop );

   REFLECTABLE_METHOD( double, SomeMethod, int );
   CONST_REFLECTABLE_METHOD( double, SomeConstMethod, int );
};

double TestReflectable::SomeMethod( int i )
{
   return 1.0;
}

double TestReflectable::SomeConstMethod( int i ) const
{
   return 3.0;
}

int main()
{
   TestReflectable tr;
   TestReflectable tr2;

   auto* prop = Reflection<TestReflectable>::Instance().GetProperty( "m_Prop" );
   auto x = prop->GetValue<int>( tr );
   prop->SetValue<int>( tr2, 40 );

   auto* method = Reflection<TestReflectable>::Instance().GetMethod( "SomeMethod" );
   double xx = method->Invoke<double, int>( tr, 1 );
   double xx2 = method->Invoke<double, int>( tr2, 1 );

   auto* constMethod = Reflection<TestReflectable>::Instance().GetMethod( "SomeConstMethod" );
   double cxx = constMethod->Invoke<double, int>( (const TestReflectable&)tr, 1 );
   double cxx2 = constMethod->Invoke<double, int>( (const TestReflectable&)tr2, 1 );

   SomeOtherReflectable other;
   auto *prop2 = Reflection<SomeOtherReflectable>::Instance().GetProperty( "m_OtherProp" );
   prop2->SetValue<int>( other, 1 );

   return 0;
}


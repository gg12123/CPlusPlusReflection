// ReflectionExperiments.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Reflectable.h"
#include <iostream>

class TestReflectable : public Reflectable
{
public:
   TestReflectable()
   {
      m_X = 99.0;
   }

   double GetX() { return m_X; }

   DECLARE_REFLECTABLE_PROP( double, m_X );
   DECLARE_REFLECTABLE_PROP( double, m_abc );
   DECLARE_REFLECTABLE_PROP( double, m_Num );

   DerivedReflectableMethod<const TestReflectable, int, double> method =
      DerivedReflectableMethod<const TestReflectable, int, double>( &TestReflectable::TestFunc, *this, "method" );

   int TestFunc( double x ) const
   {
      return 5;
   }

   DerivedReflectableMethod<TestReflectable, double> method2 =
      DerivedReflectableMethod<TestReflectable, double>( &TestReflectable::GetX, *this, "method2" );

   DerivedReflectableMethod<TestReflectable, void> method3 =
      DerivedReflectableMethod<TestReflectable, void>( &TestReflectable::VoidMethod, *this, "method3" );

   void VoidMethod() {}
};


int main()
{
   std::vector<std::string> names;
   Reflection::GetPropertyNames<TestReflectable>( names );

   TestReflectable tr;

   auto* prop = Reflection::GetProperty( names[ 0 ], tr );

   prop->SetValue<double>( 1.0 );

   ReflectableMethod* method = Reflection::GetMethod( "method", tr );

   auto i = method->Invoke<const TestReflectable, int, double>( tr, 1.0 );

   return 0;
}


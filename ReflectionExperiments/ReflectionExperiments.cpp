// ReflectionExperiments.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Reflectable.h"
#include "DerivedReflectableMethod.h"
#include <iostream>

class TestReflectable : public Reflectable
{
public:
   TestReflectable()
   {
      m_X = 99.0;
   }

   int TestFunc( double x ) { return 0; }

   double GetX() { return m_X; }

   void VoidMethod() {}

   DECLARE_REFLECTABLE_PROP( double, m_X );
   DECLARE_REFLECTABLE_PROP( double, m_abc );
   DECLARE_REFLECTABLE_PROP( double, m_Num );

   DerivedReflectableMethod<TestReflectable, int, double> method =
      DerivedReflectableMethod<TestReflectable, int, double>( &TestReflectable::TestFunc, *this, "method" );

   DerivedReflectableMethod<TestReflectable, double> method2 =
      DerivedReflectableMethod<TestReflectable, double>( &TestReflectable::GetX, *this, "method2" );

   DerivedReflectableMethod<TestReflectable, void> method3 =
      DerivedReflectableMethod<TestReflectable, void>( &TestReflectable::VoidMethod, *this, "method2" );
};


int main()
{
   std::vector<std::string> names;
   Reflection::GetPropertyNames<TestReflectable>( names );

   TestReflectable tr;
   auto* prop = Reflection::GetProperty( names[ 0 ], tr );

   prop->SetValue<double>( 1.0 );

   return 0;
}


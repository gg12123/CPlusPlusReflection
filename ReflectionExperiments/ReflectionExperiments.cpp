// ReflectionExperiments.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "DerivedReflectableProperty2.h"
#include <iostream>

class TestReflectable
{
public:

   TestReflectable()
   {
      someProp = 20.0;

      someProp_.SetValue<double>( *this, 2.0f );

      double x = someProp_.GetValue<double>( *this );
   }

private:
   double someProp;

   const char* name = "someProp";

   DerivedReflectableProperty2<double, TestReflectable>& someProp_ =
      DerivedReflectableProperty2<double, TestReflectable, name>::Instance( &TestReflectable::someProp );
};

int main()
{
   TestReflectable tr;

   auto* prop = Reflection2<TestReflectable>::Instance().GetProperty( "someProp" );

   auto x = prop->GetValue<double>( tr );

   return 0;
}


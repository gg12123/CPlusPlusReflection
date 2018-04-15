// ReflectionExperiments.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "DerivedReflectableProperty2.h"
#include "ReflectionMacros.h"
#include <iostream>

class SomeOtherReflectable
{
   MAKE_REFLECTABLE( SomeOtherReflectable );

public:
   SomeOtherReflectable()
   {
   }
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
   DECLARE_REFLECTABLE_PROP_2( int, m_Prop );
};

int main()
{
   TestReflectable tr;
   TestReflectable tr2;

   auto* prop = Reflection2<TestReflectable>::Instance().GetProperty( "m_Prop" );

   auto x = prop->GetValue<int>( tr );

   prop->SetValue<int>( tr2, 40 );

   return 0;
}


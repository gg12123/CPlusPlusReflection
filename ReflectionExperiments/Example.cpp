#include "stdafx.h"
#include "ReflectionIncludes.h"
#include <iostream>

class Example
{
   // Register this class with the reflection system.
   MAKE_REFLECTIVE( Example );

public:
   Example()
   {
   }

private:
   // Declare some properties that can be reflected on.
   REFLECTIVE_PROPERTY( int, m_Prop );
   REFLECTIVE_PROPERTY( int, m_Prop2 );
   REFLECTIVE_PROPERTY( double, m_Prop3 );

   // Declare some methods that can be reflected on.
   REFLECTIVE_METHOD( double, SomeMethod, int );
   CONST_REFLECTIVE_METHOD( double, SomeConstMethod, int );
};

double Example::SomeMethod( int i )
{
   return static_cast<double>(i);
}

double Example::SomeConstMethod( int i ) const
{
   return static_cast<double>(i);
}

int main()
{
   // Get all the properties and methods
   auto properties = Reflection<Example>::Instance().GetProperties();
   auto methods = Reflection<Example>::Instance().GetMethods();

   // Get specific ones
   auto prop = Reflection<Example>::Instance().GetProperty( "m_Prop2" );
   auto method = Reflection<Example>::Instance().GetMethod( "SomeMethod" );

   Example test;

   // Set and get a property
   prop->SetValue<int>( test, 1 );
   auto value = prop->GetValue<int>( test );

   // Invoke a method
   auto output = method->Invoke<double, int>( test, 1 );

   return 0;
}


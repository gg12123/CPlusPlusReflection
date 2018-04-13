// ReflectionExperiments.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Reflectable.h"
#include "Reflection.h"
#include <iostream>

class TestReflectable : public Reflectable
{
public:
   TestReflectable()
   {
      m_X = 99.0;
   }

   double GetX() { return m_X; }

   DECLARE_REFLECTABLE( double, m_X );
};


int main()
{
   TestReflectable tr;

   ReflectablePropertyBase* prop = Reflection::GetProperty( "m_X", tr );

   std::cout << prop->GetValue<double>() << std::endl;

   prop->SetValue<double>( 1.0 );

   std::cout << tr.GetX();

   int x;
   std::cin >> x;

   return 0;
}


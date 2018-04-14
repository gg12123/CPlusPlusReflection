#pragma once
#include <string>

class Reflectable;

class Reflection
{
public:
   static ReflectableProperty* GetProperty( const std::string& name, Reflectable& owner );
   static ReflectableMethod* GetMethod( const std::string& name, Reflectable& owner );

   static auto PropertiesBegin( Reflectable& owner );
   static auto PropertiesEnd( Reflectable& owner );

   template<class T>
   static void GetPropertyNames( std::vector<std::string>& names )
   {
      T propOwner;
      propOwner.GetPropertyNames( names );
   }
};

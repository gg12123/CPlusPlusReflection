#pragma once
#include <string>

class ReflectablePropertyBase;

class Reflection
{
public:
   static ReflectablePropertyBase* GetProperty( const std::string& name, Reflectable& owner );
   static auto PropertiesBegin( const std::string& name, Reflectable& owner );
   static auto PropertiesEnd( const std::string& name, Reflectable& owner );
};

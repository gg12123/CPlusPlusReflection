#include "stdafx.h"
#include "Reflectable.h"

ReflectablePropertyBase* Reflection::GetProperty( const std::string& name, Reflectable& owner )
{
   return owner.GetProperty( name );
}

auto Reflection::PropertiesBegin( const std::string& name, Reflectable& owner )
{
   return owner.PropertiesBegin();
}

auto Reflection::PropertiesEnd( const std::string& name, Reflectable& owner )
{
   return owner.PropertiesEnd();
}
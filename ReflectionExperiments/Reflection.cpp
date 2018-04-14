#include "stdafx.h"
#include "Reflectable.h"

ReflectableProperty* Reflection::GetProperty( const std::string& name, Reflectable& owner )
{
   return owner.GetProperty( name );
}

ReflectableMethod* Reflection::GetMethod( const std::string& name, Reflectable& owner )
{
   return owner.GetMethod( name );
}

auto Reflection::PropertiesBegin( Reflectable& owner )
{
   return owner.PropertiesBegin();
}

auto Reflection::PropertiesEnd( Reflectable& owner )
{
   return owner.PropertiesEnd();
}
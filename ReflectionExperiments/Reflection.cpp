#include "stdafx.h"
#include "Reflectable.h"

ReflectableProperty* Reflection::GetProperty( const std::string& name, Reflectable& owner )
{
   return owner.GetProperty( name );
}

auto Reflection::PropertiesBegin( Reflectable& owner )
{
   return owner.PropertiesBegin();
}

auto Reflection::PropertiesEnd( Reflectable& owner )
{
   return owner.PropertiesEnd();
}
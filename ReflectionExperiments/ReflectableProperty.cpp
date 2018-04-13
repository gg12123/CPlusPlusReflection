#include "stdafx.h"
#include "Reflectable.h"
#include "ReflectableProperty.h"

ReflectableProperty::ReflectableProperty( Reflectable& owner, std::string name )
{
   owner.Register( *this, std::move( name ) );
}
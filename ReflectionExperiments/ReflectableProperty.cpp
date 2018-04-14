#include "stdafx.h"
#include "Reflectable.h"
#include "ReflectableProperty.h"

ReflectableProperty::ReflectableProperty( Reflectable& owner, const char* name )
{
   owner.Register( *this, name );
}
#include "stdafx.h"
#include "Reflectable.h"
#include "ReflectableMethod.h"

ReflectableMethod::ReflectableMethod( Reflectable& owner, const char* name )
{
   owner.Register( *this, name );
}
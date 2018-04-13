#include "stdafx.h"
#include "Reflectable.h"
#include "ReflectablePropertyBase.h"

ReflectablePropertyBase::ReflectablePropertyBase( Reflectable& owner, std::string name )
{
   owner.Register( *this, std::move( name ) );
}
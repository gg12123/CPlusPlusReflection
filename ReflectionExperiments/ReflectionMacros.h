#pragma once

#define DECLARE_REFLECTABLE_PROP( type, name )\
   type name;\
   DerivedReflectableProperty<type> ___##name = DerivedReflectableProperty<type>( name , *this , #name )

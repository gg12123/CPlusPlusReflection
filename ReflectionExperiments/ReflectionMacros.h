#pragma once

#define DECLARE_REFLECTABLE( type, name )\
   type name;\
   ReflectableProperty<type> ref##name = ReflectableProperty<type>( name , *this , #name )

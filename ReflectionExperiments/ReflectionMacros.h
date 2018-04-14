#pragma once

#define DECLARE_REFLECTABLE_PROP( type, name )\
   type name;\
   DerivedReflectableProperty<type> ___##name = DerivedReflectableProperty<type>( name , *this , #name )

#define DECLARE_REFLECTABLE_METHOD( rtnType, methodName, ... )\
   DerivedReflectableMethod<ReflectableClassType, rtnType, __VA_ARGS__> ___##methodName =\
      DerivedReflectableMethod<ReflectableClassType, rtnType, __VA_ARGS__>( &ReflectableClassType::methodName, *this, #methodName );\
   rtnType methodName( __VA_ARGS__ )

#define DECLARE_CONST_REFLECTABLE_METHOD( rtnType, methodName, ... )\
   DerivedReflectableMethod<const ReflectableClassType, rtnType, __VA_ARGS__> ___##methodName =\
      DerivedReflectableMethod<const ReflectableClassType, rtnType, __VA_ARGS__>( &ReflectableClassType::methodName, *this, #methodName );\
   rtnType methodName( __VA_ARGS__ ) const

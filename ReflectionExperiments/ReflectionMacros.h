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



#define MAKE_REFLECTABLE( className )     typedef className ReflectableClassType

#define DECLARE_REFLECTABLE_PROP_2( type, name )\
   type name;\
   DerivedReflectableProperty2<type, ReflectableClassType, __LINE__>& ___##name = DerivedReflectableProperty2<type, ReflectableClassType, __LINE__>::Instance( &ReflectableClassType::name, #name )

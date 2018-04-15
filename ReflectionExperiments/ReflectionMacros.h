#pragma once

#define MAKE_REFLECTABLE( className )     typedef className ReflectableClassType


#define REFLECTABLE_PROPERTY( type, name )\
   type name;\
   DerivedReflectableProperty<type, ReflectableClassType, __LINE__>& ___##name = DerivedReflectableProperty<type, ReflectableClassType, __LINE__>::Instance( &ReflectableClassType::name, #name )


#define REFLECTABLE_METHOD( rtnType, methodName, ... )\
   rtnType methodName( __VA_ARGS__ );\
   DerivedReflectableMethod<__LINE__, ReflectableClassType, rtnType, __VA_ARGS__> ___##methodName = DerivedReflectableMethod<__LINE__, ReflectableClassType, rtnType, __VA_ARGS__>::Instance( &ReflectableClassType::methodName, #methodName )


#define CONST_REFLECTABLE_METHOD( rtnType, methodName, ... )\
   rtnType methodName( __VA_ARGS__ ) const;\
   DerivedReflectableMethod<__LINE__, const ReflectableClassType, rtnType, __VA_ARGS__> ___##methodName = DerivedReflectableMethod<__LINE__, const ReflectableClassType, rtnType, __VA_ARGS__>::Instance( &ReflectableClassType::methodName, #methodName )
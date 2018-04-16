#pragma once

#define MAKE_REFLECTIVE( className )     typedef className ReflectiveClassType


#define REFLECTIVE_PROPERTY( type, name )\
   type name;\
   DerivedReflectiveProperty<type, ReflectiveClassType, __LINE__>& ___##name = DerivedReflectiveProperty<type, ReflectiveClassType, __LINE__>::Instance( &ReflectiveClassType::name, #name )


#define REFLECTIVE_METHOD( rtnType, methodName, ... )\
   rtnType methodName( __VA_ARGS__ );\
   DerivedReflectiveMethod<__LINE__, ReflectiveClassType, rtnType, __VA_ARGS__> ___##methodName = DerivedReflectiveMethod<__LINE__, ReflectiveClassType, rtnType, __VA_ARGS__>::Instance( &ReflectiveClassType::methodName, #methodName )


#define CONST_REFLECTIVE_METHOD( rtnType, methodName, ... )\
   rtnType methodName( __VA_ARGS__ ) const;\
   DerivedReflectiveMethod<__LINE__, const ReflectiveClassType, rtnType, __VA_ARGS__> ___##methodName = DerivedReflectiveMethod<__LINE__, const ReflectiveClassType, rtnType, __VA_ARGS__>::Instance( &ReflectiveClassType::methodName, #methodName )
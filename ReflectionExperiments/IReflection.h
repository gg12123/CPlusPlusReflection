#pragma once

template<class T>
class ReflectableProperty;

template<class T>
class ReflectableMethod;

template<class ownerT>
class IReflection
{
public:
   virtual ReflectableProperty<ownerT>* GetProperty( const std::string& name ) = 0;
   virtual ReflectableMethod<ownerT>* GetMethod( const std::string& name ) = 0;
};

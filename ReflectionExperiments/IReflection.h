#pragma once
#include <vector>
#include <string>

template<class T>
class ReflectiveProperty;

template<class T>
class ReflectiveMethod;

template<class ownerT>
class IReflection
{
public:
   virtual ReflectiveProperty<ownerT>* GetProperty( const std::string& name ) = 0;
   virtual std::vector<ReflectiveProperty<ownerT>*> GetProperties() = 0;

   virtual ReflectiveMethod<ownerT>* GetMethod( const std::string& name ) = 0;
   virtual std::vector<ReflectiveMethod<ownerT>*> GetMethods() = 0;
};

#pragma once
#include <unordered_map>
#include "ReflectableProperty.h"
#include "ReflectionMacros.h"
#include "Reflection.h"

class Reflectable
{
   friend ReflectablePropertyBase;
   friend Reflection;

private:
   void Register( ReflectablePropertyBase& prop, std::string name );

   ReflectablePropertyBase* GetProperty( const std::string& name );

   auto PropertiesBegin() { return m_Properties.begin(); }
   auto PropertiesEnd() { return m_Properties.end(); }

   std::unordered_map<std::string, ReflectablePropertyBase*> m_Properties;
};

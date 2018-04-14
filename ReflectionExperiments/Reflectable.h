#pragma once
#include <unordered_map>
#include "DerivedReflectableProperty.h"
#include "ReflectionMacros.h"
#include "Reflection.h"

class Reflectable
{
   friend ReflectableProperty;
   friend Reflection;

private:
   void Register( ReflectableProperty& prop, const char* name );

   ReflectableProperty* GetProperty( const std::string& name );

   void GetPropertyNames( std::vector<std::string>& names );

   auto PropertiesBegin() { return m_Properties.begin(); }
   auto PropertiesEnd() { return m_Properties.end(); }

   std::unordered_map<std::string, ReflectableProperty*> m_Properties;
};

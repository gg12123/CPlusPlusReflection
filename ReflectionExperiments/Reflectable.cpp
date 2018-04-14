#include "stdafx.h"
#include "Reflectable.h"

void Reflectable::Register( ReflectableMethod& method, const char* name )
{
   m_Methods[ name ] = &method;
}

void Reflectable::Register( ReflectableProperty& prop, const char* name )
{
   m_Properties[ name ] = &prop;
}

ReflectableProperty* Reflectable::GetProperty( const std::string& name )
{
   ReflectableProperty* prop = nullptr;
   auto it = m_Properties.find( name );

   if (it != m_Properties.end())
   {
      prop = it->second;
   }

   return prop;
}

ReflectableMethod* Reflectable::GetMethod( const std::string& name )
{
   ReflectableMethod* method = nullptr;
   auto it = m_Methods.find( name );

   if (it != m_Methods.end())
   {
      method = it->second;
   }

   return method;
}

void Reflectable::GetPropertyNames( std::vector<std::string>& names )
{
   for (auto it = m_Properties.begin(); it != m_Properties.end(); it++)
   {
      names.push_back( it->first );
   }
}
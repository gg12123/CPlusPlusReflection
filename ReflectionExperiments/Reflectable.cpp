#include "stdafx.h"
#include "Reflectable.h"

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

void Reflectable::GetPropertyNames( std::vector<std::string>& names )
{
   for (auto it = m_Properties.begin(); it != m_Properties.end(); it++)
   {
      names.push_back( it->first );
   }
}
#include "stdafx.h"
#include "Reflectable.h"

void Reflectable::Register( ReflectablePropertyBase& prop, std::string name )
{
   m_Properties[ std::move( name ) ] = &prop;
}

ReflectablePropertyBase* Reflectable::GetProperty( const std::string& name )
{
   ReflectablePropertyBase* prop = nullptr;
   auto it = m_Properties.find( name );

   if (it != m_Properties.end())
   {
      prop = it->second;
   }

   return prop;
}
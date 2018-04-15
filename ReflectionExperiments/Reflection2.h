#pragma once
#include <assert.h>
#include <string>
#include <unordered_map>

template<class T>
T* GetFromMap( std::unordered_map<std::string, T*>& map, const std::string& name )
{
   T* prop = nullptr;
   auto it = map.find( name );

   if (it != map.end())
   {
      prop = it->second;
   }

   return prop;
}

template<class T>
class ReflectableProperty2;

template<class ownerT>
class Reflection2
{
public:
   static Reflection2<ownerT>& Instance()
   {
      static Reflection2<ownerT> inst;
      return inst;
   }

   // Need to somehow make this accesible to only the ReflectableProperty2 class
   void Register( ReflectableProperty2<ownerT>& prop, const char * name )
   {
      assert( m_Properties.find( name ) == m_Properties.end() );
      m_Properties[ name ] = &prop;
   }

   ReflectableProperty2<ownerT>* GetProperty( const std::string& name )
   {
      LazyInit();
      return GetFromMap<ReflectableProperty2<ownerT>>( m_Properties, name );
   }

private:
   Reflection2()
   {
      m_Initialised = false;
   }

   void LazyInit()
   {
      if (!m_Initialised)
      {
         m_Initialised = true;
         ownerT obj; // This will make the ownerT type register itself with this class.
      }
   }

   std::unordered_map<std::string, ReflectableProperty2<ownerT>*> m_Properties;
   bool m_Initialised;
};
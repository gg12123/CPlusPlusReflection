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
class ReflectableProperty;

template<class T>
class ReflectableMethod;

template<class ownerT>
class Reflection
{
public:
   static Reflection<ownerT>& Instance()
   {
      static Reflection<ownerT> inst;
      return inst;
   }

   // TODO - It would be good if these registration methods were more private.

   void Register( ReflectableProperty<ownerT>& prop, const char * name )
   {
      assert( m_Properties.find( name ) == m_Properties.end() );
      m_Properties[ name ] = &prop;
   }

   void Register( ReflectableMethod<ownerT>& method, const char * name )
   {
      assert( m_Methods.find( name ) == m_Methods.end() );
      m_Methods[ name ] = &method;
   }

   ReflectableProperty<ownerT>* GetProperty( const std::string& name )
   {
      LazyInit();
      return GetFromMap<ReflectableProperty<ownerT>>( m_Properties, name );
   }

   ReflectableMethod<ownerT>* GetMethod( const std::string& name )
   {
      LazyInit();
      return GetFromMap<ReflectableMethod<ownerT>>( m_Methods, name );
   }

private:
   Reflection()
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

   std::unordered_map<std::string, ReflectableProperty<ownerT>*> m_Properties;
   std::unordered_map<std::string, ReflectableMethod<ownerT>*> m_Methods;
   bool m_Initialised;
};
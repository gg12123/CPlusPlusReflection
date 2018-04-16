#pragma once
#include <assert.h>
#include <string>
#include <unordered_map>
#include "IReflection.h"

template<class ownerT>
class Reflection : public IReflection<ownerT>
{
public:
   static IReflection<ownerT>& Instance()
   {
      static Reflection<ownerT> inst;
      return inst;
   }

   void Register( ReflectiveProperty<ownerT>& prop, const char * name )
   {
      assert( m_Properties.find( name ) == m_Properties.end() );
      m_Properties[ name ] = &prop;
   }

   void Register( ReflectiveMethod<ownerT>& method, const char * name )
   {
      assert( m_Methods.find( name ) == m_Methods.end() );
      m_Methods[ name ] = &method;
   }

   ReflectiveProperty<ownerT>* GetProperty( const std::string& name )
   {
      LazyInit();
      return GetFromMap<ReflectiveProperty<ownerT>>( m_Properties, name );
   }

   ReflectiveMethod<ownerT>* GetMethod( const std::string& name )
   {
      LazyInit();
      return GetFromMap<ReflectiveMethod<ownerT>>( m_Methods, name );
   }

   std::vector<ReflectiveProperty<ownerT>*> GetProperties()
   {
      LazyInit();
      return GetAllFromMap<ReflectiveProperty<ownerT>>( m_Properties );
   }

   std::vector<ReflectiveMethod<ownerT>*> GetMethods()
   {
      LazyInit();
      return GetAllFromMap<ReflectiveMethod<ownerT>>( m_Methods );
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
   std::vector<T*> GetAllFromMap( std::unordered_map<std::string, T*>& map )
   {
      std::vector<T*> values;

      for (auto it = map.begin(); it != map.end(); it++)
         values.push_back( it->second );

      return values;
   }

   std::unordered_map<std::string, ReflectiveProperty<ownerT>*> m_Properties;
   std::unordered_map<std::string, ReflectiveMethod<ownerT>*> m_Methods;
   bool m_Initialised;
};
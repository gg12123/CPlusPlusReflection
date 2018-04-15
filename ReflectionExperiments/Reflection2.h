#pragma once
#include <assert.h>
#include <unordered_map>

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
      ReflectableProperty2<ownerT>* prop = nullptr;
      auto it = m_Properties.find( name );

      if (it != m_Properties.end())
      {
         prop = it->second;
      }

      return prop;
   }

private:
   Reflection2()
   {
   }

   std::unordered_map<std::string, ReflectableProperty2<ownerT>*> m_Properties;
};
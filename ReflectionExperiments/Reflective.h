#pragma once
#include <string>

class Reflective
{
public:
   std::string GetName()
   {
      return m_Name;
   }

protected:
   void SetName( const char* name )
   {
      m_Name = name;
   }

private:
   std::string m_Name;
};

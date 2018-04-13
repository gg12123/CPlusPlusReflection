#pragma once
#include <functional>
#include <string>

template<class ownerT, class rtnT, class... paramsTs>
class DerivedReflectableMethod
{
public:
   DerivedReflectableMethod( std::function<rtnT( ownerT&, paramsTs... )> method, ownerT& owner, std::string name )
   {
      m_Method = std::move( method );
      m_Owner = &owner;
   }

private:
   std::function<rtnT( ownerT&, paramsTs... )> m_Method;
   ownerT* m_Owner;
};

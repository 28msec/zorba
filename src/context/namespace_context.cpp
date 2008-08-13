/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "context/namespace_context.h"
#include "context/static_context.h"


namespace zorba {

namespace_context::namespace_context(static_context *sctx, store::NsBindings& bindings)
      : m_sctx(sctx)
{
    for (unsigned long i = 0; i < bindings.size(); i++)
    {
        bind_ns( bindings[i].first.getStore(), bindings[i].second.getStore() );
    }    
}
      
void namespace_context::bind_ns(xqp_string prefix, xqp_string ns)
{
  m_bindings.push_back(std::pair<xqp_string, xqp_string>(prefix, ns));
}

bool namespace_context::findBinding(xqp_string aPrefix, xqp_string &aNamespace)
{
  bindings_t::const_iterator lIter = m_bindings.begin();
  bindings_t::const_iterator lEnd = m_bindings.end();
  for (; lIter != lEnd ; ++lIter)
  {
    if ( (*lIter).first == aPrefix)
    {
      if ((*lIter).second == "")
      {
        // namespace is undeclared
        return false;
      }
      aNamespace = (*lIter).second;
      return true;
    }
  }
  if (m_parent != 0)
  {
    return m_parent->findBinding(aPrefix, aNamespace);
  } else {
    return m_sctx->lookup_elem_namespace(aPrefix, aNamespace);
  }
}

}
/* vim:set ts=2 sw=2: */

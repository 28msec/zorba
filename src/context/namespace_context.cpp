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

SERIALIZABLE_CLASS_VERSIONS(namespace_context)
END_SERIALIZABLE_CLASS_VERSIONS(namespace_context)



namespace_context::namespace_context(static_context *sctx, store::NsBindings& bindings)
  :
  m_sctx(sctx)
{
  for (unsigned long i = 0; i < bindings.size(); i++)
  {
    bind_ns(bindings[i].first, bindings[i].second);
  }    
}


void namespace_context::serialize(::zorba::serialization::Archiver &ar)
{
  //serialize_baseclass(ar, (SimpleRCObject*)this);
  ar & m_sctx;
  ar & m_parent;
  ar & m_bindings;
}
  
    
void namespace_context::bind_ns(xqpStringStore_t& prefix, xqpStringStore_t& ns)
{
  m_bindings.push_back(std::pair<xqpStringStore_t, xqpStringStore_t>(prefix, ns));
}


bool namespace_context::findBinding(
    const xqpStringStore_t& aPrefix,
    xqpStringStore_t& aNamespace)
{
  bindings_t::const_iterator lIter = m_bindings.begin();
  bindings_t::const_iterator lEnd = m_bindings.end();
  for (; lIter != lEnd ; ++lIter)
  {
    if ( (*lIter).first->byteEqual(*aPrefix.getp()))
    {
      if ((*lIter).second->empty())
      {
        // namespace is undeclared
        aNamespace = new xqpStringStore("");
        return false;
      }
      aNamespace = (*lIter).second;
      return true;
    }
  }

  if (m_parent != 0)
  {
    return m_parent->findBinding(aPrefix, aNamespace);
  }
  else
  {
    xqpString ns;
    bool found = m_sctx->lookup_elem_ns(aPrefix.getp(), ns);
    aNamespace = ns.getStore();
    return found;
  }
}

}
/* vim:set ts=2 sw=2: */

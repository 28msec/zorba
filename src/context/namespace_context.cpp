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
#include "stdafx.h"

#include "context/namespace_context.h"
#include "context/static_context.h"

#include "compiler/parser/query_loc.h"


namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(namespace_context)
END_SERIALIZABLE_CLASS_VERSIONS(namespace_context)



/*******************************************************************************

********************************************************************************/
namespace_context::namespace_context(const static_context *sctx, store::NsBindings& bindings)
  :
  m_sctx(const_cast<static_context*>(sctx))
{
  for (unsigned long i = 0; i < bindings.size(); ++i)
  {
    bind_ns(bindings[i].first, bindings[i].second);
  }    
}


/*******************************************************************************

********************************************************************************/
void namespace_context::serialize(::zorba::serialization::Archiver& ar)
{
  //serialize_baseclass(ar, (SimpleRCObject*)this);
  ar & m_sctx;
  ar & m_parent;
  ar & m_bindings;
}
  

/*******************************************************************************

********************************************************************************/
void namespace_context::bind_ns(
    const zstring& prefix,
    const zstring& ns)
{
  m_bindings.push_back(std::pair<zstring, zstring>(prefix, ns));
}


/*******************************************************************************

********************************************************************************/
bool namespace_context::findBinding(
    const zstring& aPrefix,
    zstring& aNamespace)
{
  store::NsBindings::const_iterator lIter = m_bindings.begin();
  store::NsBindings::const_iterator lEnd = m_bindings.end();
  for (; lIter != lEnd ; ++lIter)
  {
    if ((*lIter).first == aPrefix)
    {
      if ((*lIter).second.empty())
      {
        // namespace is undeclared
        //aNamespace.clear();
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
    QueryLoc loc;
    bool found = m_sctx->lookup_ns(aNamespace, aPrefix, loc, zerr::ZXQP0000_NO_ERROR);

    if (!found && aPrefix.empty())
    {
      aNamespace = m_sctx->default_elem_type_ns();

      if (!aNamespace.empty())
        found = true;
    }

    return found;
  }
}


/*******************************************************************************
  Collect all the in-scope bindings into the given vector
********************************************************************************/
void namespace_context::getAllBindings(store::NsBindings& bindings) const
{
  bindings = m_bindings;

  const namespace_context* parentContext = m_parent;

  while (parentContext)
  {
    const store::NsBindings& parentBindings = parentContext->m_bindings;
    ulong parentSize = (ulong)parentBindings.size();
    ulong currSize = (ulong)bindings.size();

    // for each parent binding, add it to the result, if it doesn't have the
    // same prefix as another binding that is already in the result.
    for (ulong i = 0; i < parentSize; ++i)
    {
      ulong j;
      for (j = 0; j < currSize; ++j)
      {
        if (bindings[j].first == parentBindings[i].first)
          break;
      }

      if (j == currSize)
      {
        bindings.push_back(parentBindings[i]);
      }
    }

    parentContext = parentContext->m_parent;
  }
}


}
/* vim:set et sw=2 ts=2: */

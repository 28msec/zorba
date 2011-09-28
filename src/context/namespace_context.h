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
#pragma once
#ifndef ZORBA_NAMESPACE_CONTEXT_H
#define ZORBA_NAMESPACE_CONTEXT_H

#include <string>
#include <vector>

#include "zorbatypes/schema_types.h"
#include "zorbatypes/rchandle.h"

#include "zorbamisc/ns_consts.h"
#include "store/api/item.h"

#include "zorbaserialization/class_serializer.h"

namespace zorba {

class static_context;
class namespace_context;

typedef rchandle<namespace_context> NamespaceContext_t;


class namespace_context : public SimpleRCObject 
{
private:
  static_context              * m_sctx;
  rchandle<namespace_context>   m_parent;
  store::NsBindings             m_bindings;

public:
  SERIALIZABLE_CLASS(namespace_context)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(namespace_context, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  namespace_context(const static_context* sctx) : m_sctx(const_cast<static_context*>(sctx)) { }

  namespace_context(const static_context* sctx, store::NsBindings& bindings);

  namespace_context(rchandle<namespace_context> parent)
    :
    m_sctx(parent->m_sctx),
    m_parent(parent)
  { 
  }
  
  rchandle<namespace_context> get_parent() const { return m_parent; }

  const static_context* get_context() const { return m_sctx; }
  
  void bind_ns(const zstring& prefix, const zstring& ns);

  const store::NsBindings& getLocalBindings() const { return m_bindings; }

  void getAllBindings(store::NsBindings& bindings) const;

  bool findBinding(const zstring& aPrefix, zstring& aNamespace);
};

}

#endif /* ZORBA_NAMESPACE_CONTEXT_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */

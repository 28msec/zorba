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
#ifndef ZORBA_SIMPLE_STORE_NSBINDINGS
#define ZORBA_SIMPLE_STORE_NSBINDINGS

#include <vector>

#include "common/common.h"
#include "common/shared_types.h"

namespace zorba { namespace store {


typedef std::vector<std::pair<xqpString, xqpString> > NsBindings;


/*******************************************************************************

********************************************************************************/
class NsBindingsContext : public SimpleRCObject
{
private:
  NsBindings           theBindings;
  NsBindingsContext_t  theParent;

public:
  NsBindingsContext() { }

  NsBindingsContext(ulong numBindings);

  NsBindingsContext(const NsBindings& bindings);

  ~NsBindingsContext();

  bool empty() const                          { return theBindings.empty(); }

  const NsBindings& getBindings() const       { return theBindings; }
  NsBindings& getBindings()                   { return theBindings; }

  void setParent(NsBindingsContext* p)        { theParent = p; }
  const NsBindingsContext* getParent() const  { return theParent.getp(); }

  xqpStringStore* findBinding(const xqpStringStore* prefix) const;

  void addBinding(xqpStringStore* prefix, xqpStringStore* ns);
};


} // namespace store
} // namespace zorba

#endif

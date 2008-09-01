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
#ifndef ZORBA_MINIMAL_STORE_NSBINDINGS
#define ZORBA_MINIMAL_STORE_NSBINDINGS

#include <vector>

#include "zorbamisc/config/platform.h"
#include "store/api/item.h"

namespace zorba { namespace storeminimal {



/*******************************************************************************

********************************************************************************/
class NsBindingsContext : public SimpleRCObject
{
private:
  store::NsBindings           theBindings;
  rchandle<NsBindingsContext> theParent;

public:
  NsBindingsContext() { }

  NsBindingsContext(ulong numBindings);

  NsBindingsContext(const store::NsBindings& bindings, bool doswap = false);

  ~NsBindingsContext();

  bool empty() const                          { return theBindings.empty(); }

  const store::NsBindings& getBindings() const       { return theBindings; }
  store::NsBindings& getBindings()                   { return theBindings; }

  void setParent(NsBindingsContext* p)        { theParent = p; }
  const NsBindingsContext* getParent() const  { return theParent.getp(); }

  xqpStringStore* findBinding(const xqpStringStore* prefix) const;

  void addBinding(xqpStringStore* prefix, xqpStringStore* ns);
  void removeBinding(xqpStringStore* prefix, xqpStringStore* ns);
};


} // namespace storeminimal
} // namespace zorba

#endif

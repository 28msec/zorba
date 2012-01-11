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

#include "zorbatypes/rchandle.h"
#include "zorbamisc/config/platform.h"
#include "store/api/shared_types.h"

namespace zorba { namespace simplestore {


/*******************************************************************************

********************************************************************************/
class NsBindingsContext : public SimpleRCObject
{
private:
  store::NsBindings            theBindings;
  rchandle<NsBindingsContext>  theParent;

public:
  NsBindingsContext() { }

  NsBindingsContext(NsBindingsContext* parent);

  NsBindingsContext(csize numBindings);

  NsBindingsContext(const store::NsBindings& bindings);

  ~NsBindingsContext();

  bool empty() const                           { return theBindings.empty(); }

  const store::NsBindings& getBindings() const { return theBindings; }

  store::NsBindings& getBindings()             { return theBindings; }

  void setParent(NsBindingsContext* p)         { theParent = p; }

  const NsBindingsContext* getParent() const   { return theParent.getp(); }

  bool findBinding(const zstring& prefix, zstring& nsuri) const;

  static void check_ns_binding(const zstring& prefix, const zstring& uri);
  
  void addBinding(const zstring& prefix, const zstring& ns, bool soft = false);

  void updateBinding(const zstring& prefix, const zstring& ns);

  void removeBinding(const zstring& prefix, const zstring& ns);
};


} // namespace store
} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */

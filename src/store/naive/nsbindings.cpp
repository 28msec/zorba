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

#include "zorbautils/fatal.h"
#include "zorbatypes/xqpstring.h"
#include "store/naive/nsbindings.h"

namespace zorba { namespace store {

NsBindingsContext::NsBindingsContext(ulong numBindings)
{
  theBindings.resize(numBindings);
#if 0
  std::cout << "Create binding context1 " << this << "; num bindings = "
            << numBindings << std::endl;
#endif
}


NsBindingsContext::NsBindingsContext(const NsBindings& bindings)
  :
  theBindings(bindings)
{
#if 0
  std::cout << "Create binding context2 " << this << "; num bindings = "
            << bindings.size() << std::endl;
#endif
}


NsBindingsContext::~NsBindingsContext()
{
#if 0
  std::cout << "Removing binding context " << this << "; num bindings = "
            << theBindings.size() << std::endl;
#endif
}


xqpStringStore* NsBindingsContext::findBinding(const xqpStringStore* prefix) const
{
  const NsBindingsContext* currentContext = this;

  while (currentContext != NULL)
  {
    const NsBindings& bindings = currentContext->theBindings;
    ulong numBindings = bindings.size();

    for (ulong i = 0; i < numBindings; i++)
    {
      if (bindings[i].first.getStore()->byteEqual(*prefix))
        return bindings[i].second.getStore();
    }

    currentContext = currentContext->getParent();
  }

  return NULL;
}


void NsBindingsContext::addBinding(
    xqpStringStore* prefix,
    xqpStringStore* ns)
{
  ulong numBindings = theBindings.size();

  for (ulong i = 0; i < numBindings; i++)
  {
    if (theBindings[i].first.getStore()->byteEqual(*prefix))
    {
      ZORBA_FATAL(theBindings[i].second.getStore()->byteEqual(*ns), "");

      return;
    }
  }

  theBindings.push_back(std::pair<xqpString, xqpString>(prefix, ns));
}


} // namespace store
} // namespace zorba



#include "util/Assert.h"
#include "util/utf8/xqpString.h"
#include "store/naive/nsbindings.h"

namespace xqp
{

NsBindingsContext::NsBindingsContext(unsigned long numBindings)
{
  theBindings.resize(numBindings);
}


NsBindingsContext::NsBindingsContext(const NamespaceBindings& bindings)
  :
  theBindings(bindings)
{
}


xqpStringStore* NsBindingsContext::findBinding(xqpString prefix)
{
  NsBindingsContext* currentContext = this;

  while (currentContext != NULL)
  {
    NamespaceBindings& bindings = currentContext->theBindings;
    unsigned long numBindings = bindings.size();

    for (unsigned long i = 0; i < numBindings; i++)
    {
      if (bindings[i].first.byteEqual(prefix))
        return bindings[i].second.getStore();
    }

    currentContext = currentContext->getParent();
  }

  return NULL;
}


void NsBindingsContext::addBinding(
    xqpString prefix,
    xqpString ns)
{
  unsigned long numBindings = theBindings.size();

  for (unsigned long i = 0; i < numBindings; i++)
  {
    if (theBindings[i].first.byteEqual(prefix))
    {
      if (theBindings[i].second.byteEqual(ns))
        Assert(0);

      return;
    }
  }

  theBindings.push_back(std::pair<xqpString, xqpString>(prefix, ns));
}

}



#include "zorbatypes/xqpstring.h"
#include "errors/fatal.h"
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



#include "zorbatypes/xqpstring.h"
#include "util/Assert.h"
#include "store/naive/nsbindings.h"

namespace zorba { namespace store {

NsBindingsContext::NsBindingsContext(unsigned long numBindings)
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


xqpStringStore* NsBindingsContext::findBinding(xqpStringStore* prefix) const
{
  const NsBindingsContext* currentContext = this;

  while (currentContext != NULL)
  {
    const NsBindings& bindings = currentContext->theBindings;
    unsigned long numBindings = bindings.size();

    for (unsigned long i = 0; i < numBindings; i++)
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
  unsigned long numBindings = theBindings.size();

  for (unsigned long i = 0; i < numBindings; i++)
  {
    if (theBindings[i].first.getStore()->byteEqual(*prefix))
    {
      if (!theBindings[i].second.getStore()->byteEqual(*ns))
        ZORBA_ASSERT(0);

      return;
    }
  }

  theBindings.push_back(std::pair<xqpString, xqpString>(prefix, ns));
}


} // namespace store
} // namespace zorba


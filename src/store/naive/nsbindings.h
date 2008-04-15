#ifndef ZORBA_SIMPLE_STORE_NSBINDINGS
#define ZORBA_SIMPLE_STORE_NSBINDINGS

#include <vector>

#include "common/common.h"
#include "util/rchandle.h"
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

#ifndef XQP_DEFAULT_STORE_NSBINDINGS
#define XQP_DEFAULT_STORE_NSBINDINGS

#include <vector>

#include "common.h"
#include "util/rchandle.h"

#if defined (WIN32)
#include "util/win32/compatib_defs.h"
#elif defined (__FreeBSD__)
typedef unsigned long unsigned long;
#endif

namespace xqp
{
class xqpString;
class xqpStringStore;

typedef rchandle<class xqpStringStore> xqpStringStore_t;

typedef rchandle<class NsBindingsContext> NsBindingsContext_t;

typedef std::vector<std::pair<xqpString, xqpString> > NsBindings;


/*******************************************************************************

********************************************************************************/
class NsBindingsContext : public rcobject
{
private:
  NsBindings           theBindings;
  NsBindingsContext_t  theParent;

public:
  NsBindingsContext() { }

  NsBindingsContext(unsigned long numBindings);

  NsBindingsContext(const NsBindings& bindings);

  ~NsBindingsContext();

  bool empty() const                          { return theBindings.empty(); }

  const NsBindings& getBindings() const       { return theBindings; }
  NsBindings& getBindings()                   { return theBindings; }

  void setParent(NsBindingsContext* p)        { theParent = p; }
  const NsBindingsContext* getParent() const  { return theParent.getp(); }

  xqpStringStore* findBinding(xqpStringStore* prefix) const;

  void addBinding(xqpStringStore* prefix, xqpStringStore* ns);
};


}

#endif

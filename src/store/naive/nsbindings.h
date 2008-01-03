#ifndef XQP_DEFAULT_STORE_NSBINDINGS
#define XQP_DEFAULT_STORE_NSBINDINGS

#include <vector>

#include "util/rchandle.h"


namespace xqp
{
class xqpString;
class xqpStringStore;

typedef rchandle<class xqpStringStore> xqpStringStore_t;

typedef rchandle<class NsBindingsContext> NsBindingsContext_t;

typedef std::vector<std::pair<xqpString, xqpString> > NamespaceBindings;


/*******************************************************************************

********************************************************************************/
class NsBindingsContext : public rcobject
{
private:
  NamespaceBindings    theBindings;
  NsBindingsContext_t  theParent;

public:
  NsBindingsContext() { }

  NsBindingsContext(unsigned long numBindings);

  NsBindingsContext(const NamespaceBindings& bindings);

  ~NsBindingsContext();

  const NamespaceBindings& getBindings() const { return theBindings; }
  NamespaceBindings& getBindings()             { return theBindings; }

  void setParent(NsBindingsContext* p)         { theParent = p; }
  NsBindingsContext* getParent() const         { return theParent.get_ptr(); }

  xqpStringStore* findBinding(xqpString prefix);

  void addBinding(xqpString prefix, xqpString ns);
};


}

#endif

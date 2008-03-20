#ifndef XQP_RUNTIMECB_H
#define XQP_RUNTIMECB_H

namespace zorba {

  class static_context;
  class dynamic_context;
  class CollationCache;

  class RuntimeCB {

    public:
      RuntimeCB() :
        theDynamicContext(0) {}

      // TODO remove the static context from here
      static_context*  theStaticContext;  
      dynamic_context* theDynamicContext; 
      CollationCache*  theCollationCache;

  }; /* class RuntimeCB */

} /* namespace zorba */
#endif

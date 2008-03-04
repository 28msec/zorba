#ifndef ZORBA_ZORBAENGINE_API_H
#define ZORBA_ZORBAENGINE_API_H

#include <zorba/zorba_baseengine_api.h>

namespace zorba
{

  // TODO move into api_shared_types?
  class ZorbaEngine;
  typedef rchandle<ZorbaEngine> ZorbaEngine_t;

  class ZorbaEngine : public virtual ZorbaBaseEngine
  {
    public:
      static ZorbaEngine_t 
      getInstance();

    public:
      virtual ~ZorbaEngine() {}

      virtual void 
      initThread() = 0;

      virtual void 
      uninitThread() = 0;
  };
} /* namespace zorba */
#endif

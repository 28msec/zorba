#ifndef ZORBA_ZORBA_ENGINE_SINGLETHREAD_API_H
#define ZORBA_ZORBA_ENGINE_SINGLETHREAD_API_H

#include <zorba/zorba_baseengine_api.h>

namespace xqp{

  // TODO move into api_shared_types.h
  class ZorbaSingleThread;
  typedef rchandle<ZorbaSingleThread>		ZorbaSingleThread_t;

  class ZorbaSingleThread : public virtual ZorbaBaseEngine
  {
    public:
      static ZorbaSingleThread_t 
      getInstance();

      static bool
      execute(xqp_string xquery_text, std::ostream &os);

    public:
      virtual ~ZorbaSingleThread();
  };
} /* namespace xqp */
#endif


#ifndef ZORBA_ENGINE_SINGLE_THREAD_API_11_JAN_2008
#define ZORBA_ENGINE_SINGLE_THREAD_API_11_JAN_2008

#include "zorba_baseengine_api.h"

namespace xqp{


class ZorbaSingleThread;
typedef rchandle<ZorbaSingleThread>		ZorbaSingleThread_t;

class ZorbaSingleThread : public virtual ZorbaBaseEngine
{
public:
	static ZorbaSingleThread_t getInstance();

public:
  virtual ~ZorbaSingleThread() {}
};


}//end namespace xqp

#endif

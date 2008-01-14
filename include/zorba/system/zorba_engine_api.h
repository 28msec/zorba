
#ifndef INCLUDE_ZORBA_ENGINE_API
#define INCLUDE_ZORBA_ENGINE_API

#include "system/zorba_engine_singlethread_api.h"

namespace xqp
{


class ZorbaEngine : public virtual ZorbaBaseEngine
{
public:
	static ZorbaEngine& getInstance();

public:
  virtual ~ZorbaEngine() {}

	virtual void initThread() = 0;

	virtual void uninitThread() = 0;

};



}//end namespace xqp

#endif


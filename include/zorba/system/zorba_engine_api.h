
#ifndef INCLUDE_ZORBA_ENGINE_API
#define INCLUDE_ZORBA_ENGINE_API

#include "system/zorba_baseengine_api.h"

namespace xqp
{

class ZorbaEngine;
typedef rchandle<ZorbaEngine>		ZorbaEngine_t;

class ZorbaEngine : public virtual ZorbaBaseEngine
{
public:
	static ZorbaEngine_t getInstance();

public:
  virtual ~ZorbaEngine() {}

	virtual void initThread() = 0;

	virtual void uninitThread() = 0;

};



}//end namespace xqp

#endif


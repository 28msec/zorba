
#ifndef XQUERY_RESULT_ITERATOR_API_WRAPPER_31_JAN_2008
#define XQUERY_RESULT_ITERATOR_API_WRAPPER_31_JAN_2008

#include "runtime/result_iterator.h"
#include "runtime/base/plan_wrapper.h"

#include "common/shared_types.h"

namespace xqp{

class Zorba_XQueryBinary;
typedef rchandle<Zorba_XQueryBinary>		Zorba_XQueryBinary_t;

class dynamic_context;
class DynamicContextWrapper;

class ResultIteratorWrapper : public ResultIterator, public PlanWrapper
{
	friend class Zorba;
	friend class Zorba_XQueryBinary;


	Zorba_XQueryBinary_t       xquery;
//	bool		                   theClosed;
	dynamic_context		       * internal_dyn_context;
public:
	
	ResultIteratorWrapper(Zorba_XQueryBinary_t x, DynamicContextWrapper *dctx);
	virtual ~ResultIteratorWrapper();

	virtual void		openIterator();

	virtual Item_t	nextItem();

	virtual void		closeIterator();


  ///from PlanWrapper
  virtual void open();
  virtual Item_t next();
  virtual void close();

};

/*
class ResultIteratorInternalWrapper : public PlanWrapper
{
	ResultIterator_t result;
public:
	ResultIteratorInternalWrapper(ResultIterator_t result);
	virtual ~ResultIteratorInternalWrapper();
  virtual void open();
  virtual Item_t next();
  virtual void reset();
  virtual void close();
};
*/

}//end namespace xqp

#endif


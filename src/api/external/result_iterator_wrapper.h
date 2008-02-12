
#ifndef XQUERY_RESULT_ITERATOR_API_WRAPPER_31_JAN_2008
#define XQUERY_RESULT_ITERATOR_API_WRAPPER_31_JAN_2008

#include "runtime/result_iterator.h"


namespace xqp{

class PlanState;
class PlanIterator;
typedef rchandle<class PlanIterator> PlanIter_t;

class Zorba_XQueryBinary;
typedef rchandle<Zorba_XQueryBinary>		Zorba_XQueryBinary_t;

class dynamic_context;
class DynamicContextWrapper;

class ResultIteratorWrapper : public ResultIterator
{
	friend class Zorba;
	friend class Zorba_XQueryBinary;


	Zorba_XQueryBinary_t       xquery;
	PlanState		             * state_block;
	bool		                   theClosed;
	dynamic_context		       * internal_dyn_context;
public:
	
	ResultIteratorWrapper(Zorba_XQueryBinary_t x, DynamicContextWrapper *dctx);
	virtual ~ResultIteratorWrapper();

	virtual void		open();

	virtual Item_t	next();

	virtual void		close();

	//from Iterator
  virtual void reset();
};


class ResultIteratorInternalWrapper : public Iterator
{
	ResultIterator_t result;
public:
	ResultIteratorInternalWrapper(ResultIterator_t result);
	virtual ~ResultIteratorInternalWrapper();
  virtual Item_t next();
  virtual void reset();
  virtual void close();
};

}//end namespace xqp

#endif


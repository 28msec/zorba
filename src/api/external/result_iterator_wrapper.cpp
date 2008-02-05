
#include "util/rchandle.h"
#include "errors/errors.h"
#include "errors/error_factory.h"
#include "api/external/result_iterator_wrapper.h"
#include "context/dynamic_context.h"
#include "api/external/dynamic_context_wrapper.h"
#include "api/external/xquery.h"
#include "runtime/base/iterator.h"
#include "system/zorba.h"
#include "system/zorba_engine.h"

namespace xqp{

ResultIteratorWrapper::ResultIteratorWrapper(Zorba_XQueryBinary_t x,
																						 DynamicContextWrapper *dctx)
{
	xquery = x;

	theClosed = false;
  ///compute the offsets for each iterator into the state block
	int32_t		lStateSize;
  lStateSize = x->top_iterator->getStateSizeOfSubtree();
  state_block = new PlanState(lStateSize);
  uint32_t lOffset = 0;
  x->top_iterator->open(*state_block, lOffset);

  ///and construct the state block of state objects...
  state_block->theZorba = ZORBA_FOR_CURRENT_THREAD();

	if(dctx != NULL)
  {
    internal_dyn_context = dctx->create_dynamic_context(x->internal_sctx);
  }
	else
	{
		internal_dyn_context = new dynamic_context;
	}

}

ResultIteratorWrapper::~ResultIteratorWrapper()
{
	try{

  //delete internal_sctx;
  close();
  delete state_block;
	delete internal_dyn_context;
	}CATCH_ALL_NO_RETURN(;);
}


void		ResultIteratorWrapper::open()
{
}

Item_t	ResultIteratorWrapper::next()
{
	try{
		if(!state_block)
		{
			ZORBA_ERROR_ALERT(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED);
			return NULL;
		}
		if (theClosed)
		{
			ZORBA_ERROR_ALERT(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED);
			return NULL;
		}
	}
	CATCH_ALL_RETURN_NULL;

	Zorba_XQueryBinary        *prev_current_xquery = state_block->theZorba->current_xquery;
	ResultIteratorWrapper			*prev_result = state_block->theZorba->current_xqueryresult;

  state_block->theZorba->current_xquery = xquery;
  state_block->theZorba->current_xqueryresult = this;
  try
  {
    Item_t it = xquery->top_iterator->produceNext( *state_block );

    state_block->theZorba->current_xquery = prev_current_xquery;
		state_block->theZorba->current_xqueryresult = prev_result;

    return it;
  }
	CATCH_ALL_NO_RETURN(  \
  state_block->theZorba->current_xquery = prev_current_xquery;\
	state_block->theZorba->current_xqueryresult = prev_result;)

  return NULL;
}

void		ResultIteratorWrapper::close()
{
	try{
		if(!state_block)
		{
			ZORBA_ERROR_ALERT(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED);
			return;
		}
	}CATCH_ALL_NO_RETURN(;);

	Zorba			*zorba = ZORBA_FOR_CURRENT_THREAD();
	Zorba_XQueryBinary        *prev_current_xquery = NULL;
	ResultIteratorWrapper			*prev_result = NULL;
	if(zorba)
	{
		prev_current_xquery = zorba->current_xquery;
		prev_result = zorba->current_xqueryresult;
		zorba->current_xquery = xquery;
		zorba->current_xqueryresult = this;
	}

	try
  {
    if (!theClosed)
    {
      xquery->top_iterator->close(*state_block); 
	    delete state_block;
			state_block = NULL;
      theClosed = true;
    }
		if(zorba)
		{
			zorba->current_xquery = prev_current_xquery;
			zorba->current_xqueryresult = prev_result;
		}
		return;
	}
	CATCH_ALL_NO_RETURN(if(zorba) {zorba->current_xquery = prev_current_xquery;\
		zorba->current_xqueryresult = prev_result;});
}

void ResultIteratorWrapper::reset()
{
}






ResultIteratorInternalWrapper::ResultIteratorInternalWrapper(ResultIterator_t result)
{
	this->result = result;
}

ResultIteratorInternalWrapper::~ResultIteratorInternalWrapper()
{
}

Item_t ResultIteratorInternalWrapper::next()
{
	return result->next();
}

void ResultIteratorInternalWrapper::reset()
{
}

void ResultIteratorInternalWrapper::close()
{
	result->close();
}


}//end namespace xqp

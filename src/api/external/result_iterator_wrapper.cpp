
#include <zorba/rchandle.h>
#include <zorba/errors.h>

#include "system/zorba.h"
#include "system/zorba_engine.h"
#include "api/external/xquery.h"
#include "errors/error_factory.h"
#include "api/external/result_iterator_wrapper.h"
#include "context/dynamic_context.h"
#include "api/external/dynamic_context_wrapper.h"
#include "runtime/base/plan_iterator.h" // for state block, TODO should be removed

namespace xqp{

ResultIteratorWrapper::ResultIteratorWrapper(Zorba_XQueryInfo* xinfo,
                                             DynamicContextWrapper *dctx) :
        PlanWrapper(xinfo->top_iterator)
{
	xquery_info = xinfo;

  openIterator();
/*
	theClosed = false;
  ///compute the offsets for each iterator into the state block
	int32_t		lStateSize;
  lStateSize = x->top_iterator->getStateSizeOfSubtree();
  theStateBlock = new PlanState(lStateSize);
  uint32_t lOffset = 0;
  x->top_iterator->open(*theStateBlock, lOffset);

  ///and construct the state block of state objects...
  theStateBlock->theZorba = ZORBA_FOR_CURRENT_THREAD();
*/
	if(dctx != NULL)
  {
    internal_dyn_context = dctx->create_dynamic_context(xinfo->internal_sctx);
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
  closeIterator();
  //delete theStateBlock;
	delete internal_dyn_context;
	}CATCH_ALL_NO_RETURN(;);
}


void		ResultIteratorWrapper::openIterator()
{
  PlanWrapper::open();
}

Item_t	ResultIteratorWrapper::nextItem()
{
	try{
		if(!theStateBlock)
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

	Zorba_XQueryInfo          *prev_current_xquery = theStateBlock->theZorba->current_xquery;
	ResultIteratorWrapper			*prev_result = theStateBlock->theZorba->current_xqueryresult;

  theStateBlock->theZorba->current_xquery = xquery_info;
  theStateBlock->theZorba->current_xqueryresult = this;
  try
  {
    //Item_t it = PlanIterator::consumeNext( xquery->top_iterator, *theStateBlock );
    Item_t  it = PlanWrapper::next();

    theStateBlock->theZorba->current_xquery = prev_current_xquery;
		theStateBlock->theZorba->current_xqueryresult = prev_result;

    return it;
  }
	CATCH_ALL_NO_RETURN(  \
  theStateBlock->theZorba->current_xquery = prev_current_xquery;\
	theStateBlock->theZorba->current_xqueryresult = prev_result;)

  return NULL;
}

void		ResultIteratorWrapper::closeIterator()
{
	if(theClosed)
		return;

	try{
		if(!theStateBlock)
		{
			ZORBA_ERROR_ALERT(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED);
			return;
		}
	}CATCH_ALL_NO_RETURN(;);

	Zorba			*zorba = ZORBA_FOR_CURRENT_THREAD();
	Zorba_XQueryInfo          *prev_current_xquery = NULL;
	ResultIteratorWrapper			*prev_result = NULL;
	if(zorba)
	{
		prev_current_xquery = zorba->current_xquery;
		prev_result = zorba->current_xqueryresult;
		zorba->current_xquery = xquery_info;
		zorba->current_xqueryresult = this;
	}

	try
  {
/*    if (!theClosed)
    {
      xquery->top_iterator->close(*theStateBlock); 
	    delete theStateBlock;
			theStateBlock = NULL;
      theClosed = true;
    }
*/
    PlanWrapper::close();
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

void ResultIteratorWrapper::open()
{
  openIterator();
}

Item_t ResultIteratorWrapper::next()
{
  return nextItem();
}

void ResultIteratorWrapper::close()
{
  closeIterator();
}




/*
ResultIteratorInternalWrapper::ResultIteratorInternalWrapper(ResultIterator_t result)
{
	this->result = result;
}

ResultIteratorInternalWrapper::~ResultIteratorInternalWrapper()
{
}


void ResultIteratorInternalWrapper::open()
{
  result->open();
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
*/

}//end namespace xqp

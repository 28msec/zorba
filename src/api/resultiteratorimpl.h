#ifndef ZORBA_RESULTITERATOR_H
#define ZORBA_RESULTITERATOR_H

#include <zorba/result_iterator.h>

#include <zorba/api_shared_types.h>
#include "common/shared_types.h"

namespace zorba {

  class ErrorHandler;

  class ResultIteratorImpl  : public ResultIterator 
  {
    public:
      ResultIteratorImpl(const PlanWrapper_t&, error::ErrorManager*, ErrorHandler*);
      virtual ~ResultIteratorImpl();

      virtual void 
      open();

      virtual bool
      next(Item&);

      virtual void 
      close();

      friend class Unmarshaller;
    protected:
      PlanWrapper_t        thePlan;         
      bool                 theIsOpened;     
      error::ErrorManager* theErrorManager; 
      ErrorHandler*        theErrorHandler; 

  };
}

#endif

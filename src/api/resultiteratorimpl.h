/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ZORBA_RESULTITERATOR_H
#define ZORBA_RESULTITERATOR_H

#include <zorba/result_iterator.h>

#include <zorba/api_shared_types.h>
#include "common/shared_types.h"

namespace zorba {

class ErrorHandler;
class XQueryImpl;

/*******************************************************************************
  Iterator used for computing and retrieving the result of a query in a 
  one-item-at-a-time fashion. For each XQuery there can be at most 1 result
  iterator obj: it is created during the 1st invocation of the XQuery::iterator()
  method and destroyed when the query is closed.
********************************************************************************/
class ResultIteratorImpl  : public ResultIterator 
{
  friend class XQueryImpl;
  friend class Unmarshaller;

 protected:
  XQueryImpl     * theQuery; 
  PlanWrapper_t    thePlan;         
  bool             theIsOpened;     
  bool             theHaveLock;

 protected:
  ResultIteratorImpl(XQueryImpl*, const PlanWrapper_t&);

 public:
  virtual ~ResultIteratorImpl();

  virtual void 
  open();

  virtual bool
  next(Item&);

  virtual void 
  close();

  bool isActive() const { return theHaveLock; }
};


}

#endif

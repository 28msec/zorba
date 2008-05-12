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
#ifndef ZORBA_RESULT_ITERATOR_CHAINER_H
#define ZORBA_RESULT_ITERATOR_CHAINER_H

#include <vector>
#include "store/api/iterator.h"
#include "common/shared_types.h"

namespace zorba { 
  
class ResultIterator;

namespace store {

/*******************************************************************************
  This class wraps the result iterator of the c+ api in order to convert is
  interface to the interface of the internal zorba iterators. This is needed
  for query chaining where an external variabe of query Q2 is bound to the
  result iterator of query Q1 (see DynamicContextImpl::setVariable).
********************************************************************************/
class ResultIteratorChainer : public Iterator
{
private:
  ResultIterator* theResult;

public:
  ResultIteratorChainer(ResultIterator*);

  virtual ~ResultIteratorChainer();

  virtual void open();
  virtual Item_t next();
  virtual void reset();
  virtual void close();
};

} // namespace store
} // namespace zorba

#endif

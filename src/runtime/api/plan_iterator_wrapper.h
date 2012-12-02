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
#ifndef XQP_PLAN_ITERATOR_WRAPPER_H
#define XQP_PLAN_ITERATOR_WRAPPER_H

#include "store/api/iterator.h"
#include "common/shared_types.h"
#include "runtime/base/plan_iterator.h"

namespace zorba {

class PlanState;

/*******************************************************************************
  This is a "helper" wrapper that is used when we need to pass a plan iterator
  to the store. The wrapper wraps the plan iterator in order to provide a
  simpler interface that the store can use.

  The wrapper does not allocate a new state block, but it points to the same
  block that contains the state of the wrapped plan iterator.
********************************************************************************/
class PlanIteratorWrapper : public store::Iterator
{
// private: TODO: debugging purposes
public:
  const PlanIterator * theIterator;
  PlanState          * theStateBlock;

public:
  PlanIteratorWrapper(const PlanIterator* iter, PlanState& planState);

  virtual ~PlanIteratorWrapper();

  void open() {}

  bool next(store::Item_t&);

  void reset();

  void close() {}

#ifndef NDEBUG
  virtual std::string toString() const;
#endif
};

/*******************************************************************************

********************************************************************************/
class PlanStateIteratorWrapper : public PlanIterator
{
protected:
  const PlanIterator      * theIterator;          // only one of these is used
  const store::Iterator_t   theStoreIterator; 
  
  PlanState               * theStateBlock;

public:
  SERIALIZABLE_ABSTRACT_CLASS(PlanStoreIteratorWrapper);

  PlanStateIteratorWrapper(zorba::serialization::Archiver& ar);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  PlanStateIteratorWrapper(const PlanIterator* iterator, PlanState& planState);
  
  PlanStateIteratorWrapper(const store::Iterator_t& iterator);

  virtual ~PlanStateIteratorWrapper();

  virtual void accept(PlanIterVisitor& v) const;

  virtual void open(PlanState& planState, uint32_t& offset) {}

  virtual bool produceNext(store::Item_t& result, PlanState& planState) const;

  virtual bool next(store::Item_t&);

  virtual void reset() const;

  virtual void reset(PlanState& planState) const;

  virtual void close(PlanState& planState) {}

  virtual uint32_t getStateSize() const { return 0; }

  virtual uint32_t getStateSizeOfSubtree() const { return 0; }

#ifndef NDEBUG
  virtual std::string toString() const;
#endif
};


} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */

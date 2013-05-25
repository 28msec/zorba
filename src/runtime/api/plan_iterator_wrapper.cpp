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
#include "stdafx.h"

#include "runtime/api/plan_iterator_wrapper.h"

#include "runtime/base/plan_iterator.h"

namespace zorba 
{

/*******************************************************************************
  class PlanIteratorWrapper
********************************************************************************/
PlanIteratorWrapper::PlanIteratorWrapper(const PlanIterator* iter, PlanState& state) 
  :
  theIterator(iter),
  theStateBlock(&state)
{
}


PlanIteratorWrapper::~PlanIteratorWrapper()
{
}
  
  
bool PlanIteratorWrapper::next(store::Item_t& result)
{
  return PlanIterator::consumeNext(result, theIterator, *theStateBlock);
}


#ifndef NDEBUG
std::string PlanIteratorWrapper::toString() const
{
  std::stringstream ss;
  ss << " = PlanIteratorWrapper iterator: " << theIterator->toString();
  return ss.str();
}
#endif


/*******************************************************************************
  class PlanStoreIteratorWrapper
********************************************************************************/
SERIALIZE_INTERNAL_METHOD(PlanStateIteratorWrapper);


void PlanStateIteratorWrapper::serialize(::zorba::serialization::Archiver& ar)
{
  PlanIterator::serialize(ar);
}


PlanStateIteratorWrapper::PlanStateIteratorWrapper(const store::Iterator_t& iter)
  :
  PlanIterator(NULL, QueryLoc()),
  theStoreIterator(iter),
  theStateBlock(NULL)
{
}



PlanStateIteratorWrapper::~PlanStateIteratorWrapper()
{
}


void PlanStateIteratorWrapper::open(PlanState& planState, uint32_t& offset) 
{
  theStoreIterator->open();
}


bool PlanStateIteratorWrapper::produceNext(
    store::Item_t& result,
    PlanState& planState) const
{
  return theStoreIterator->next(result);
}


bool PlanStateIteratorWrapper::next(store::Item_t& result)
{
  return theStoreIterator->next(result);
}


void PlanStateIteratorWrapper::reset() const
{
  theStoreIterator->reset();
}


void PlanStateIteratorWrapper::reset(PlanState& planState) const
{
  theStoreIterator->reset();
}


void PlanStateIteratorWrapper::accept(PlanIterVisitor& v) const
{
}


#ifndef NDEBUG
std::string PlanStateIteratorWrapper::toString() const
{
  std::stringstream ss;
  ss << getId() << " = PlanStateIteratorWrapper iterator: " << theStoreIterator->toString();
  return ss.str();
}
#endif


} /* namespace zorba */
/* vim:set et sw=2 ts=2: */

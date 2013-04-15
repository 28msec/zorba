/*
 * Copyright 2006-2012 The FLWOR Foundation.
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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************

#include "stdafx.h"
#include "zorbatypes/rchandle.h"
#include "zorbatypes/zstring.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/hof/fn_hof_functions.h"
#include "system/globalenv.h"


#include "context/static_context.h"
#include "compiler/api/compilercb.h"
#include "context/dynamic_context.h"
#include "store/api/temp_seq.h"

namespace zorba {

// <FunctionLookupIterator>
SERIALIZABLE_CLASS_VERSIONS(FunctionLookupIterator)

void FunctionLookupIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FunctionLookupIterator, FunctionLookupIteratorState>*)this);
}


void FunctionLookupIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FunctionLookupIterator::~FunctionLookupIterator() {}

FunctionLookupIteratorState::FunctionLookupIteratorState() {}

FunctionLookupIteratorState::~FunctionLookupIteratorState() {}


void FunctionLookupIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void FunctionLookupIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </FunctionLookupIterator>


// <FunctionNameIterator>
SERIALIZABLE_CLASS_VERSIONS(FunctionNameIterator)

void FunctionNameIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FunctionNameIterator, PlanIteratorState>*)this);
}


void FunctionNameIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FunctionNameIterator::~FunctionNameIterator() {}

// </FunctionNameIterator>


// <FunctionArityIterator>
SERIALIZABLE_CLASS_VERSIONS(FunctionArityIterator)

void FunctionArityIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FunctionArityIterator, PlanIteratorState>*)this);
}


void FunctionArityIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FunctionArityIterator::~FunctionArityIterator() {}

// </FunctionArityIterator>


// <FnMapPairsIterator>
SERIALIZABLE_CLASS_VERSIONS(FnMapPairsIterator)

void FnMapPairsIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnMapPairsIterator, FnMapPairsIteratorState>*)this);
}


void FnMapPairsIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnMapPairsIterator::~FnMapPairsIterator() {}

FnMapPairsIteratorState::FnMapPairsIteratorState() {}

// </FnMapPairsIterator>


// <FnFoldLeftIterator>
SERIALIZABLE_CLASS_VERSIONS(FnFoldLeftIterator)

void FnFoldLeftIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnFoldLeftIterator, FnFoldLeftIteratorState>*)this);

    ar & theIsFoldRight;
}


void FnFoldLeftIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnFoldLeftIterator::~FnFoldLeftIterator() {}

FnFoldLeftIteratorState::FnFoldLeftIteratorState() {}

// </FnFoldLeftIterator>



}



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
#include "runtime/errors_and_diagnostics/errors_and_diagnostics.h"
#include "system/globalenv.h"


#include "api/serialization/serializer.h"

namespace zorba {

// <ErrorIterator>
SERIALIZABLE_CLASS_VERSIONS(ErrorIterator)

void ErrorIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ErrorIterator, PlanIteratorState>*)this);
}


void ErrorIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ErrorIterator::~ErrorIterator() {}

// </ErrorIterator>


// <TraceIterator>
SERIALIZABLE_CLASS_VERSIONS(TraceIterator)

void TraceIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<TraceIterator, TraceIteratorState>*)this);
}


void TraceIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

TraceIterator::~TraceIterator() {}

TraceIteratorState::TraceIteratorState() {}

TraceIteratorState::~TraceIteratorState() {}


void TraceIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theTagItem = NULL;
  theIndex = 0;
  theOS = 0;
  theSerializer = NULL;
}

void TraceIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theTagItem = NULL;
  theIndex = 0;
  theOS = 0;
  theSerializer = NULL;
}
// </TraceIterator>



}



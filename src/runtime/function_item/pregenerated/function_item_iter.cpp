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
#include "runtime/function_item/function_item_iter.h"
#include "system/globalenv.h"


#include "context/static_context.h"
#include "compiler/api/compilercb.h"
#include "context/dynamic_context.h"

namespace zorba {

// <FunctionNameIterator>
SERIALIZABLE_CLASS_VERSIONS(FunctionNameIterator)void FunctionNameIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<FunctionNameIterator, PlanIteratorState>*)this);
}


void FunctionNameIterator::accept(PlanIterVisitor& v) const {
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
SERIALIZABLE_CLASS_VERSIONS(FunctionArityIterator)void FunctionArityIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<FunctionArityIterator, PlanIteratorState>*)this);
}


void FunctionArityIterator::accept(PlanIterVisitor& v) const {
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


// <PartialApplyIterator>
SERIALIZABLE_CLASS_VERSIONS(PartialApplyIterator)void PartialApplyIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<PartialApplyIterator, PlanIteratorState>*)this);
}


void PartialApplyIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

PartialApplyIterator::~PartialApplyIterator() {}

// </PartialApplyIterator>



}



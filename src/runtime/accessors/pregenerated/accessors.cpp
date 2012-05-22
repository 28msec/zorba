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
#include "runtime/accessors/accessors.h"
#include "system/globalenv.h"


#include "store/api/iterator.h"

namespace zorba {

// <NodeNameIterator>
SERIALIZABLE_CLASS_VERSIONS(NodeNameIterator)

void NodeNameIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<NodeNameIterator, PlanIteratorState>*)this);
}


void NodeNameIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

NodeNameIterator::~NodeNameIterator() {}

// </NodeNameIterator>


// <NilledIterator>
SERIALIZABLE_CLASS_VERSIONS(NilledIterator)

void NilledIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<NilledIterator, PlanIteratorState>*)this);
}


void NilledIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

NilledIterator::~NilledIterator() {}

// </NilledIterator>


// <FnStringIterator>
SERIALIZABLE_CLASS_VERSIONS(FnStringIterator)

void FnStringIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnStringIterator, FnStringIteratorState>*)this);

    ar & theEmptyStringOnNULL;
}


void FnStringIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnStringIterator::~FnStringIterator() {}

FnStringIteratorState::FnStringIteratorState() {}

FnStringIteratorState::~FnStringIteratorState() {}


void FnStringIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  hasOutput = false;
}

void FnStringIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  hasOutput = false;
}
// </FnStringIterator>


// <FnDataIterator>
SERIALIZABLE_CLASS_VERSIONS(FnDataIterator)

void FnDataIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnDataIterator, FnDataIteratorState>*)this);
}


void FnDataIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnDataIterator::~FnDataIterator() {}

FnDataIteratorState::FnDataIteratorState() {}

FnDataIteratorState::~FnDataIteratorState() {}


void FnDataIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theTypedValueIter = NULL;
}

void FnDataIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theTypedValueIter = NULL;
}
// </FnDataIterator>


// <BaseUriIterator>
SERIALIZABLE_CLASS_VERSIONS(BaseUriIterator)

void BaseUriIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<BaseUriIterator, PlanIteratorState>*)this);
}


void BaseUriIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

BaseUriIterator::~BaseUriIterator() {}

// </BaseUriIterator>


// <DocumentUriIterator>
SERIALIZABLE_CLASS_VERSIONS(DocumentUriIterator)

void DocumentUriIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<DocumentUriIterator, PlanIteratorState>*)this);
}


void DocumentUriIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

DocumentUriIterator::~DocumentUriIterator() {}

// </DocumentUriIterator>


// <RootIterator>
SERIALIZABLE_CLASS_VERSIONS(RootIterator)

void RootIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<RootIterator, PlanIteratorState>*)this);
}


void RootIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

RootIterator::~RootIterator() {}

// </RootIterator>



}



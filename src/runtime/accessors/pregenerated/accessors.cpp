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
const char* NodeNameIterator::class_name_str = "NodeNameIterator";
NodeNameIterator::class_factory<NodeNameIterator>
NodeNameIterator::g_class_factory;

const serialization::ClassVersion 
NodeNameIterator::class_versions[] ={{ 1, 0x000905, false}};

const int NodeNameIterator::class_versions_count =
sizeof(NodeNameIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void NodeNameIterator::accept(PlanIterVisitor& v) const {
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
const char* NilledIterator::class_name_str = "NilledIterator";
NilledIterator::class_factory<NilledIterator>
NilledIterator::g_class_factory;

const serialization::ClassVersion 
NilledIterator::class_versions[] ={{ 1, 0x000905, false}};

const int NilledIterator::class_versions_count =
sizeof(NilledIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void NilledIterator::accept(PlanIterVisitor& v) const {
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
const char* FnStringIterator::class_name_str = "FnStringIterator";
FnStringIterator::class_factory<FnStringIterator>
FnStringIterator::g_class_factory;

const serialization::ClassVersion 
FnStringIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnStringIterator::class_versions_count =
sizeof(FnStringIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FnStringIterator::accept(PlanIterVisitor& v) const {
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
const char* FnDataIterator::class_name_str = "FnDataIterator";
FnDataIterator::class_factory<FnDataIterator>
FnDataIterator::g_class_factory;

const serialization::ClassVersion 
FnDataIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnDataIterator::class_versions_count =
sizeof(FnDataIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FnDataIterator::accept(PlanIterVisitor& v) const {
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
const char* BaseUriIterator::class_name_str = "BaseUriIterator";
BaseUriIterator::class_factory<BaseUriIterator>
BaseUriIterator::g_class_factory;

const serialization::ClassVersion 
BaseUriIterator::class_versions[] ={{ 1, 0x000905, false}};

const int BaseUriIterator::class_versions_count =
sizeof(BaseUriIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void BaseUriIterator::accept(PlanIterVisitor& v) const {
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
const char* DocumentUriIterator::class_name_str = "DocumentUriIterator";
DocumentUriIterator::class_factory<DocumentUriIterator>
DocumentUriIterator::g_class_factory;

const serialization::ClassVersion 
DocumentUriIterator::class_versions[] ={{ 1, 0x000905, false}};

const int DocumentUriIterator::class_versions_count =
sizeof(DocumentUriIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void DocumentUriIterator::accept(PlanIterVisitor& v) const {
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
const char* RootIterator::class_name_str = "RootIterator";
RootIterator::class_factory<RootIterator>
RootIterator::g_class_factory;

const serialization::ClassVersion 
RootIterator::class_versions[] ={{ 1, 0x000905, false}};

const int RootIterator::class_versions_count =
sizeof(RootIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void RootIterator::accept(PlanIterVisitor& v) const {
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



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

#include "runtime/visitors/planiter_visitor.h"
#include "runtime/scripting/scripting.h"
#include "system/globalenv.h"



namespace zorba {

// <SequentialIterator>
const char* SequentialIterator::class_name_str = "SequentialIterator";
SequentialIterator::class_factory<SequentialIterator>
SequentialIterator::g_class_factory;

const serialization::ClassVersion 
SequentialIterator::class_versions[] ={{ 1, 0x000905, false}};

const int SequentialIterator::class_versions_count =
sizeof(SequentialIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void SequentialIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

SequentialIterator::~SequentialIterator() {}

// </SequentialIterator>


// <LoopIterator>
const char* LoopIterator::class_name_str = "LoopIterator";
LoopIterator::class_factory<LoopIterator>
LoopIterator::g_class_factory;

const serialization::ClassVersion 
LoopIterator::class_versions[] ={{ 1, 0x000905, false}};

const int LoopIterator::class_versions_count =
sizeof(LoopIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void LoopIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

LoopIterator::~LoopIterator() {}

// </LoopIterator>


// <FlowCtlIterator>
const char* FlowCtlIterator::class_name_str = "FlowCtlIterator";
FlowCtlIterator::class_factory<FlowCtlIterator>
FlowCtlIterator::g_class_factory;

const serialization::ClassVersion 
FlowCtlIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FlowCtlIterator::class_versions_count =
sizeof(FlowCtlIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FlowCtlIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FlowCtlIterator::~FlowCtlIterator() {}

// </FlowCtlIterator>



}
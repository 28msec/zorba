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
#include "runtime/booleans/booleans.h"
#include "system/globalenv.h"



namespace zorba {

// <IsSameNodeIterator>
const char* IsSameNodeIterator::class_name_str = "IsSameNodeIterator";
IsSameNodeIterator::class_factory<IsSameNodeIterator>
IsSameNodeIterator::g_class_factory;

const serialization::ClassVersion 
IsSameNodeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsSameNodeIterator::class_versions_count =
sizeof(IsSameNodeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsSameNodeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}
IsSameNodeIterator::~IsSameNodeIterator() {}

// </IsSameNodeIterator>


// <NodeBeforeIterator>
const char* NodeBeforeIterator::class_name_str = "NodeBeforeIterator";
NodeBeforeIterator::class_factory<NodeBeforeIterator>
NodeBeforeIterator::g_class_factory;

const serialization::ClassVersion 
NodeBeforeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int NodeBeforeIterator::class_versions_count =
sizeof(NodeBeforeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void NodeBeforeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}
NodeBeforeIterator::~NodeBeforeIterator() {}

// </NodeBeforeIterator>


// <NodeAfterIterator>
const char* NodeAfterIterator::class_name_str = "NodeAfterIterator";
NodeAfterIterator::class_factory<NodeAfterIterator>
NodeAfterIterator::g_class_factory;

const serialization::ClassVersion 
NodeAfterIterator::class_versions[] ={{ 1, 0x000905, false}};

const int NodeAfterIterator::class_versions_count =
sizeof(NodeAfterIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void NodeAfterIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}
NodeAfterIterator::~NodeAfterIterator() {}

// </NodeAfterIterator>



}
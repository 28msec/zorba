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
#include "runtime/store/identifiers.h"
#include "system/globalenv.h"



namespace zorba {

// <NodeIdentifierIterator>
const char* NodeIdentifierIterator::class_name_str = "NodeIdentifierIterator";
NodeIdentifierIterator::class_factory<NodeIdentifierIterator>
NodeIdentifierIterator::g_class_factory;

const serialization::ClassVersion 
NodeIdentifierIterator::class_versions[] ={{ 1, 0x000905, false}};

const int NodeIdentifierIterator::class_versions_count =
sizeof(NodeIdentifierIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void NodeIdentifierIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

NodeIdentifierIterator::~NodeIdentifierIterator() {}

// </NodeIdentifierIterator>


// <HasIdentifierIterator>
const char* HasIdentifierIterator::class_name_str = "HasIdentifierIterator";
HasIdentifierIterator::class_factory<HasIdentifierIterator>
HasIdentifierIterator::g_class_factory;

const serialization::ClassVersion 
HasIdentifierIterator::class_versions[] ={{ 1, 0x000905, false}};

const int HasIdentifierIterator::class_versions_count =
sizeof(HasIdentifierIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void HasIdentifierIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

HasIdentifierIterator::~HasIdentifierIterator() {}

// </HasIdentifierIterator>


// <NodeByIdentifierIterator>
const char* NodeByIdentifierIterator::class_name_str = "NodeByIdentifierIterator";
NodeByIdentifierIterator::class_factory<NodeByIdentifierIterator>
NodeByIdentifierIterator::g_class_factory;

const serialization::ClassVersion 
NodeByIdentifierIterator::class_versions[] ={{ 1, 0x000905, false}};

const int NodeByIdentifierIterator::class_versions_count =
sizeof(NodeByIdentifierIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void NodeByIdentifierIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

NodeByIdentifierIterator::~NodeByIdentifierIterator() {}

// </NodeByIdentifierIterator>



}



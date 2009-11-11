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
#include "runtime/nodes/nodes.h"
#include "system/globalenv.h"



namespace zorba {

// <NodeReferenceIterator>
const char* NodeReferenceIterator::class_name_str = "NodeReferenceIterator";
NodeReferenceIterator::class_factory<NodeReferenceIterator>
NodeReferenceIterator::g_class_factory;

const serialization::ClassVersion 
NodeReferenceIterator::class_versions[] ={{ 1, 0x000905, false}};

const int NodeReferenceIterator::class_versions_count =
sizeof(NodeReferenceIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void NodeReferenceIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

NodeReferenceIterator::~NodeReferenceIterator() {}

// </NodeReferenceIterator>


// <NodeByReferenceIterator>
const char* NodeByReferenceIterator::class_name_str = "NodeByReferenceIterator";
NodeByReferenceIterator::class_factory<NodeByReferenceIterator>
NodeByReferenceIterator::g_class_factory;

const serialization::ClassVersion 
NodeByReferenceIterator::class_versions[] ={{ 1, 0x000905, false}};

const int NodeByReferenceIterator::class_versions_count =
sizeof(NodeByReferenceIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void NodeByReferenceIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

NodeByReferenceIterator::~NodeByReferenceIterator() {}

// </NodeByReferenceIterator>


// <FnLocalNameIterator>
const char* FnLocalNameIterator::class_name_str = "FnLocalNameIterator";
FnLocalNameIterator::class_factory<FnLocalNameIterator>
FnLocalNameIterator::g_class_factory;

const serialization::ClassVersion 
FnLocalNameIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnLocalNameIterator::class_versions_count =
sizeof(FnLocalNameIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FnLocalNameIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnLocalNameIterator::~FnLocalNameIterator() {}

// </FnLocalNameIterator>


// <FnNamespaceUriIterator>
const char* FnNamespaceUriIterator::class_name_str = "FnNamespaceUriIterator";
FnNamespaceUriIterator::class_factory<FnNamespaceUriIterator>
FnNamespaceUriIterator::g_class_factory;

const serialization::ClassVersion 
FnNamespaceUriIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnNamespaceUriIterator::class_versions_count =
sizeof(FnNamespaceUriIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FnNamespaceUriIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnNamespaceUriIterator::~FnNamespaceUriIterator() {}

// </FnNamespaceUriIterator>


// <FnLangIterator>
const char* FnLangIterator::class_name_str = "FnLangIterator";
FnLangIterator::class_factory<FnLangIterator>
FnLangIterator::g_class_factory;

const serialization::ClassVersion 
FnLangIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnLangIterator::class_versions_count =
sizeof(FnLangIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FnLangIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnLangIterator::~FnLangIterator() {}

// </FnLangIterator>



}
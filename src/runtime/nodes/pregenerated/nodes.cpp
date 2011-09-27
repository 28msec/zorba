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
#include "runtime/nodes/nodes.h"
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


// <FnHasChildrenIterator>
const char* FnHasChildrenIterator::class_name_str = "FnHasChildrenIterator";
FnHasChildrenIterator::class_factory<FnHasChildrenIterator>
FnHasChildrenIterator::g_class_factory;

const serialization::ClassVersion 
FnHasChildrenIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnHasChildrenIterator::class_versions_count =
sizeof(FnHasChildrenIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FnHasChildrenIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnHasChildrenIterator::~FnHasChildrenIterator() {}

// </FnHasChildrenIterator>


// <FnInnermostIterator>
const char* FnInnermostIterator::class_name_str = "FnInnermostIterator";
FnInnermostIterator::class_factory<FnInnermostIterator>
FnInnermostIterator::g_class_factory;

const serialization::ClassVersion 
FnInnermostIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnInnermostIterator::class_versions_count =
sizeof(FnInnermostIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FnInnermostIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnInnermostIterator::~FnInnermostIterator() {}

FnInnermostIteratorState::FnInnermostIteratorState() {}

FnInnermostIteratorState::~FnInnermostIteratorState() {}


void FnInnermostIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void FnInnermostIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </FnInnermostIterator>


// <FnOutermostIterator>
const char* FnOutermostIterator::class_name_str = "FnOutermostIterator";
FnOutermostIterator::class_factory<FnOutermostIterator>
FnOutermostIterator::g_class_factory;

const serialization::ClassVersion 
FnOutermostIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnOutermostIterator::class_versions_count =
sizeof(FnOutermostIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FnOutermostIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnOutermostIterator::~FnOutermostIterator() {}

FnOutermostIteratorState::FnOutermostIteratorState() {}

FnOutermostIteratorState::~FnOutermostIteratorState() {}


void FnOutermostIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void FnOutermostIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </FnOutermostIterator>


// <FnGenerateIdIterator>
const char* FnGenerateIdIterator::class_name_str = "FnGenerateIdIterator";
FnGenerateIdIterator::class_factory<FnGenerateIdIterator>
FnGenerateIdIterator::g_class_factory;

const serialization::ClassVersion 
FnGenerateIdIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnGenerateIdIterator::class_versions_count =
sizeof(FnGenerateIdIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FnGenerateIdIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnGenerateIdIterator::~FnGenerateIdIterator() {}

// </FnGenerateIdIterator>


// <IsAncestorIterator>
const char* IsAncestorIterator::class_name_str = "IsAncestorIterator";
IsAncestorIterator::class_factory<IsAncestorIterator>
IsAncestorIterator::g_class_factory;

const serialization::ClassVersion 
IsAncestorIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsAncestorIterator::class_versions_count =
sizeof(IsAncestorIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsAncestorIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsAncestorIterator::~IsAncestorIterator() {}

// </IsAncestorIterator>


// <IsDescendantIterator>
const char* IsDescendantIterator::class_name_str = "IsDescendantIterator";
IsDescendantIterator::class_factory<IsDescendantIterator>
IsDescendantIterator::g_class_factory;

const serialization::ClassVersion 
IsDescendantIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsDescendantIterator::class_versions_count =
sizeof(IsDescendantIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsDescendantIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsDescendantIterator::~IsDescendantIterator() {}

// </IsDescendantIterator>


// <IsParentIterator>
const char* IsParentIterator::class_name_str = "IsParentIterator";
IsParentIterator::class_factory<IsParentIterator>
IsParentIterator::g_class_factory;

const serialization::ClassVersion 
IsParentIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsParentIterator::class_versions_count =
sizeof(IsParentIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsParentIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsParentIterator::~IsParentIterator() {}

// </IsParentIterator>


// <IsChildIterator>
const char* IsChildIterator::class_name_str = "IsChildIterator";
IsChildIterator::class_factory<IsChildIterator>
IsChildIterator::g_class_factory;

const serialization::ClassVersion 
IsChildIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsChildIterator::class_versions_count =
sizeof(IsChildIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsChildIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsChildIterator::~IsChildIterator() {}

// </IsChildIterator>


// <IsFollowingIterator>
const char* IsFollowingIterator::class_name_str = "IsFollowingIterator";
IsFollowingIterator::class_factory<IsFollowingIterator>
IsFollowingIterator::g_class_factory;

const serialization::ClassVersion 
IsFollowingIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsFollowingIterator::class_versions_count =
sizeof(IsFollowingIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsFollowingIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsFollowingIterator::~IsFollowingIterator() {}

// </IsFollowingIterator>


// <IsPrecedingIterator>
const char* IsPrecedingIterator::class_name_str = "IsPrecedingIterator";
IsPrecedingIterator::class_factory<IsPrecedingIterator>
IsPrecedingIterator::g_class_factory;

const serialization::ClassVersion 
IsPrecedingIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsPrecedingIterator::class_versions_count =
sizeof(IsPrecedingIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsPrecedingIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsPrecedingIterator::~IsPrecedingIterator() {}

// </IsPrecedingIterator>


// <IsFollowingSiblingIterator>
const char* IsFollowingSiblingIterator::class_name_str = "IsFollowingSiblingIterator";
IsFollowingSiblingIterator::class_factory<IsFollowingSiblingIterator>
IsFollowingSiblingIterator::g_class_factory;

const serialization::ClassVersion 
IsFollowingSiblingIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsFollowingSiblingIterator::class_versions_count =
sizeof(IsFollowingSiblingIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsFollowingSiblingIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsFollowingSiblingIterator::~IsFollowingSiblingIterator() {}

// </IsFollowingSiblingIterator>


// <IsPrecedingSiblingIterator>
const char* IsPrecedingSiblingIterator::class_name_str = "IsPrecedingSiblingIterator";
IsPrecedingSiblingIterator::class_factory<IsPrecedingSiblingIterator>
IsPrecedingSiblingIterator::g_class_factory;

const serialization::ClassVersion 
IsPrecedingSiblingIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsPrecedingSiblingIterator::class_versions_count =
sizeof(IsPrecedingSiblingIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsPrecedingSiblingIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsPrecedingSiblingIterator::~IsPrecedingSiblingIterator() {}

// </IsPrecedingSiblingIterator>


// <LevelIterator>
const char* LevelIterator::class_name_str = "LevelIterator";
LevelIterator::class_factory<LevelIterator>
LevelIterator::g_class_factory;

const serialization::ClassVersion 
LevelIterator::class_versions[] ={{ 1, 0x000905, false}};

const int LevelIterator::class_versions_count =
sizeof(LevelIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void LevelIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

LevelIterator::~LevelIterator() {}

// </LevelIterator>


// <LeastCommonAncestor>
const char* LeastCommonAncestor::class_name_str = "LeastCommonAncestor";
LeastCommonAncestor::class_factory<LeastCommonAncestor>
LeastCommonAncestor::g_class_factory;

const serialization::ClassVersion 
LeastCommonAncestor::class_versions[] ={{ 1, 0x000905, false}};

const int LeastCommonAncestor::class_versions_count =
sizeof(LeastCommonAncestor::class_versions)/sizeof(struct serialization::ClassVersion);

void LeastCommonAncestor::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

LeastCommonAncestor::~LeastCommonAncestor() {}

// </LeastCommonAncestor>



}



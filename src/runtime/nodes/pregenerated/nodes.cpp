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

// <NodeReferenceIterator>
NodeReferenceIterator::class_factory<NodeReferenceIterator>
NodeReferenceIterator::g_class_factory;


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
NodeByReferenceIterator::class_factory<NodeByReferenceIterator>
NodeByReferenceIterator::g_class_factory;


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
FnLocalNameIterator::class_factory<FnLocalNameIterator>
FnLocalNameIterator::g_class_factory;


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
FnNamespaceUriIterator::class_factory<FnNamespaceUriIterator>
FnNamespaceUriIterator::g_class_factory;


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
FnLangIterator::class_factory<FnLangIterator>
FnLangIterator::g_class_factory;


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
FnHasChildrenIterator::class_factory<FnHasChildrenIterator>
FnHasChildrenIterator::g_class_factory;


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
FnInnermostIterator::class_factory<FnInnermostIterator>
FnInnermostIterator::g_class_factory;


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
FnOutermostIterator::class_factory<FnOutermostIterator>
FnOutermostIterator::g_class_factory;


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
FnGenerateIdIterator::class_factory<FnGenerateIdIterator>
FnGenerateIdIterator::g_class_factory;


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
IsAncestorIterator::class_factory<IsAncestorIterator>
IsAncestorIterator::g_class_factory;


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
IsDescendantIterator::class_factory<IsDescendantIterator>
IsDescendantIterator::g_class_factory;


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
IsParentIterator::class_factory<IsParentIterator>
IsParentIterator::g_class_factory;


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
IsChildIterator::class_factory<IsChildIterator>
IsChildIterator::g_class_factory;


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
IsFollowingIterator::class_factory<IsFollowingIterator>
IsFollowingIterator::g_class_factory;


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
IsPrecedingIterator::class_factory<IsPrecedingIterator>
IsPrecedingIterator::g_class_factory;


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
IsFollowingSiblingIterator::class_factory<IsFollowingSiblingIterator>
IsFollowingSiblingIterator::g_class_factory;


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
IsPrecedingSiblingIterator::class_factory<IsPrecedingSiblingIterator>
IsPrecedingSiblingIterator::g_class_factory;


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
LevelIterator::class_factory<LevelIterator>
LevelIterator::g_class_factory;


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
LeastCommonAncestor::class_factory<LeastCommonAncestor>
LeastCommonAncestor::g_class_factory;


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



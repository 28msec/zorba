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
SERIALIZABLE_CLASS_VERSIONS(NodeReferenceIterator)

void NodeReferenceIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<NodeReferenceIterator, PlanIteratorState>*)this);
}


void NodeReferenceIterator::accept(PlanIterVisitor& v) const
{
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


// <HasNodeReferenceIterator>
SERIALIZABLE_CLASS_VERSIONS(HasNodeReferenceIterator)

void HasNodeReferenceIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<HasNodeReferenceIterator, PlanIteratorState>*)this);
}


void HasNodeReferenceIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

HasNodeReferenceIterator::~HasNodeReferenceIterator() {}

// </HasNodeReferenceIterator>


// <AssignNodeReferenceIterator>
SERIALIZABLE_CLASS_VERSIONS(AssignNodeReferenceIterator)

void AssignNodeReferenceIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<AssignNodeReferenceIterator, PlanIteratorState>*)this);
}


void AssignNodeReferenceIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

AssignNodeReferenceIterator::~AssignNodeReferenceIterator() {}

// </AssignNodeReferenceIterator>


// <NodeByReferenceIterator>
SERIALIZABLE_CLASS_VERSIONS(NodeByReferenceIterator)

void NodeByReferenceIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<NodeByReferenceIterator, PlanIteratorState>*)this);
}


void NodeByReferenceIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(FnLocalNameIterator)

void FnLocalNameIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnLocalNameIterator, PlanIteratorState>*)this);
}


void FnLocalNameIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(FnNamespaceUriIterator)

void FnNamespaceUriIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnNamespaceUriIterator, PlanIteratorState>*)this);
}


void FnNamespaceUriIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(FnLangIterator)

void FnLangIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnLangIterator, PlanIteratorState>*)this);
}


void FnLangIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(FnHasChildrenIterator)

void FnHasChildrenIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnHasChildrenIterator, PlanIteratorState>*)this);
}


void FnHasChildrenIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(FnInnermostIterator)

void FnInnermostIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnInnermostIterator, FnInnermostIteratorState>*)this);
}


void FnInnermostIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(FnOutermostIterator)

void FnOutermostIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnOutermostIterator, FnOutermostIteratorState>*)this);
}


void FnOutermostIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(FnGenerateIdIterator)

void FnGenerateIdIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnGenerateIdIterator, PlanIteratorState>*)this);
}


void FnGenerateIdIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(IsAncestorIterator)

void IsAncestorIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<IsAncestorIterator, PlanIteratorState>*)this);
}


void IsAncestorIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(IsDescendantIterator)

void IsDescendantIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<IsDescendantIterator, PlanIteratorState>*)this);
}


void IsDescendantIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(IsParentIterator)

void IsParentIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<IsParentIterator, PlanIteratorState>*)this);
}


void IsParentIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(IsChildIterator)

void IsChildIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<IsChildIterator, PlanIteratorState>*)this);
}


void IsChildIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(IsFollowingIterator)

void IsFollowingIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<IsFollowingIterator, PlanIteratorState>*)this);
}


void IsFollowingIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(IsPrecedingIterator)

void IsPrecedingIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<IsPrecedingIterator, PlanIteratorState>*)this);
}


void IsPrecedingIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(IsFollowingSiblingIterator)

void IsFollowingSiblingIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<IsFollowingSiblingIterator, PlanIteratorState>*)this);
}


void IsFollowingSiblingIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(IsPrecedingSiblingIterator)

void IsPrecedingSiblingIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<IsPrecedingSiblingIterator, PlanIteratorState>*)this);
}


void IsPrecedingSiblingIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(LevelIterator)

void LevelIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<LevelIterator, PlanIteratorState>*)this);
}


void LevelIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(LeastCommonAncestor)

void LeastCommonAncestor::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<LeastCommonAncestor, PlanIteratorState>*)this);
}


void LeastCommonAncestor::accept(PlanIterVisitor& v) const
{
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


// <FnPathIterator>
SERIALIZABLE_CLASS_VERSIONS(FnPathIterator)

void FnPathIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnPathIterator, PlanIteratorState>*)this);
}


void FnPathIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnPathIterator::~FnPathIterator() {}

// </FnPathIterator>


// <NodeCopyIterator>
SERIALIZABLE_CLASS_VERSIONS(NodeCopyIterator)

void NodeCopyIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<NodeCopyIterator, PlanIteratorState>*)this);
}


void NodeCopyIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

NodeCopyIterator::~NodeCopyIterator() {}

// </NodeCopyIterator>



}



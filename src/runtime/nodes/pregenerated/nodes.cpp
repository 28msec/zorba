/*
 * Copyright 2006-2012 The FLWOR Foundation.
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

// <FnLocalNameIterator>
SERIALIZABLE_CLASS_VERSIONS(FnLocalNameIterator)

void FnLocalNameIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnLocalNameIterator, PlanIteratorState>*)this);
}


void FnLocalNameIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnLocalNameIterator::~FnLocalNameIterator() {}


zstring FnLocalNameIterator::getNameAsString() const {
  return "fn:local-name";
}
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
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnNamespaceUriIterator::~FnNamespaceUriIterator() {}


zstring FnNamespaceUriIterator::getNameAsString() const {
  return "fn:namespace-uri";
}
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
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnLangIterator::~FnLangIterator() {}


zstring FnLangIterator::getNameAsString() const {
  return "fn:lang";
}
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
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnHasChildrenIterator::~FnHasChildrenIterator() {}


zstring FnHasChildrenIterator::getNameAsString() const {
  return "fn:has-children";
}
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
  if (!v.hasToVisit(this))
    return;

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

zstring FnInnermostIterator::getNameAsString() const {
  return "fn:innermost";
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
  if (!v.hasToVisit(this))
    return;

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

zstring FnOutermostIterator::getNameAsString() const {
  return "fn:outermost";
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
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnGenerateIdIterator::~FnGenerateIdIterator() {}


zstring FnGenerateIdIterator::getNameAsString() const {
  return "fn:generate-id";
}
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
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsAncestorIterator::~IsAncestorIterator() {}


zstring IsAncestorIterator::getNameAsString() const {
  return "fn-zorba-node:ancestor-of";
}
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
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsDescendantIterator::~IsDescendantIterator() {}


zstring IsDescendantIterator::getNameAsString() const {
  return "fn-zorba-node:descendant-of";
}
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
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsParentIterator::~IsParentIterator() {}


zstring IsParentIterator::getNameAsString() const {
  return "fn-zorba-node:parent-of";
}
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
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsChildIterator::~IsChildIterator() {}


zstring IsChildIterator::getNameAsString() const {
  return "fn-zorba-node:child-of";
}
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
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsFollowingIterator::~IsFollowingIterator() {}


zstring IsFollowingIterator::getNameAsString() const {
  return "fn-zorba-node:following-of";
}
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
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsPrecedingIterator::~IsPrecedingIterator() {}


zstring IsPrecedingIterator::getNameAsString() const {
  return "fn-zorba-node:preceding-of";
}
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
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsFollowingSiblingIterator::~IsFollowingSiblingIterator() {}


zstring IsFollowingSiblingIterator::getNameAsString() const {
  return "fn-zorba-node:following-sibling-of";
}
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
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsPrecedingSiblingIterator::~IsPrecedingSiblingIterator() {}


zstring IsPrecedingSiblingIterator::getNameAsString() const {
  return "fn-zorba-node:preceding-sibling-of";
}
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
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

LevelIterator::~LevelIterator() {}


zstring LevelIterator::getNameAsString() const {
  return "fn-zorba-node:level";
}
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
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

LeastCommonAncestor::~LeastCommonAncestor() {}


zstring LeastCommonAncestor::getNameAsString() const {
  return "fn-zorba-node:least-common-ancestor";
}
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
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnPathIterator::~FnPathIterator() {}


zstring FnPathIterator::getNameAsString() const {
  return "fn:path";
}
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
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

NodeCopyIterator::~NodeCopyIterator() {}


zstring NodeCopyIterator::getNameAsString() const {
  return "fn-zorba-node:copy";
}
// </NodeCopyIterator>



}



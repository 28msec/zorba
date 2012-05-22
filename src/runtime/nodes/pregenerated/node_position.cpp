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
#include "runtime/nodes/node_position.h"
#include "system/globalenv.h"



namespace zorba {

// <NodePositionIterator>
SERIALIZABLE_CLASS_VERSIONS(NodePositionIterator)void NodePositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<NodePositionIterator, PlanIteratorState>*)this);
}


void NodePositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

NodePositionIterator::~NodePositionIterator() {}

// </NodePositionIterator>


// <IsAncestorPositionIterator>
SERIALIZABLE_CLASS_VERSIONS(IsAncestorPositionIterator)void IsAncestorPositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<IsAncestorPositionIterator, PlanIteratorState>*)this);
}


void IsAncestorPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsAncestorPositionIterator::~IsAncestorPositionIterator() {}

// </IsAncestorPositionIterator>


// <IsFollowingSiblingPositionIterator>
SERIALIZABLE_CLASS_VERSIONS(IsFollowingSiblingPositionIterator)void IsFollowingSiblingPositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<IsFollowingSiblingPositionIterator, PlanIteratorState>*)this);
}


void IsFollowingSiblingPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsFollowingSiblingPositionIterator::~IsFollowingSiblingPositionIterator() {}

// </IsFollowingSiblingPositionIterator>


// <IsFollowingPositionIterator>
SERIALIZABLE_CLASS_VERSIONS(IsFollowingPositionIterator)void IsFollowingPositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<IsFollowingPositionIterator, PlanIteratorState>*)this);
}


void IsFollowingPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsFollowingPositionIterator::~IsFollowingPositionIterator() {}

// </IsFollowingPositionIterator>


// <IsInSubtreeOfPositionIterator>
SERIALIZABLE_CLASS_VERSIONS(IsInSubtreeOfPositionIterator)void IsInSubtreeOfPositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<IsInSubtreeOfPositionIterator, PlanIteratorState>*)this);
}


void IsInSubtreeOfPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsInSubtreeOfPositionIterator::~IsInSubtreeOfPositionIterator() {}

// </IsInSubtreeOfPositionIterator>


// <IsDescendantPositionIterator>
SERIALIZABLE_CLASS_VERSIONS(IsDescendantPositionIterator)void IsDescendantPositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<IsDescendantPositionIterator, PlanIteratorState>*)this);
}


void IsDescendantPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsDescendantPositionIterator::~IsDescendantPositionIterator() {}

// </IsDescendantPositionIterator>


// <IsPrecedingSiblingPositionIterator>
SERIALIZABLE_CLASS_VERSIONS(IsPrecedingSiblingPositionIterator)void IsPrecedingSiblingPositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<IsPrecedingSiblingPositionIterator, PlanIteratorState>*)this);
}


void IsPrecedingSiblingPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsPrecedingSiblingPositionIterator::~IsPrecedingSiblingPositionIterator() {}

// </IsPrecedingSiblingPositionIterator>


// <IsPrecedingPositionIterator>
SERIALIZABLE_CLASS_VERSIONS(IsPrecedingPositionIterator)void IsPrecedingPositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<IsPrecedingPositionIterator, PlanIteratorState>*)this);
}


void IsPrecedingPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsPrecedingPositionIterator::~IsPrecedingPositionIterator() {}

// </IsPrecedingPositionIterator>


// <IsChildPositionIterator>
SERIALIZABLE_CLASS_VERSIONS(IsChildPositionIterator)void IsChildPositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<IsChildPositionIterator, PlanIteratorState>*)this);
}


void IsChildPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsChildPositionIterator::~IsChildPositionIterator() {}

// </IsChildPositionIterator>


// <IsAttributeOfPositionIterator>
SERIALIZABLE_CLASS_VERSIONS(IsAttributeOfPositionIterator)void IsAttributeOfPositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<IsAttributeOfPositionIterator, PlanIteratorState>*)this);
}


void IsAttributeOfPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsAttributeOfPositionIterator::~IsAttributeOfPositionIterator() {}

// </IsAttributeOfPositionIterator>


// <IsParentPositionIterator>
SERIALIZABLE_CLASS_VERSIONS(IsParentPositionIterator)void IsParentPositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<IsParentPositionIterator, PlanIteratorState>*)this);
}


void IsParentPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsParentPositionIterator::~IsParentPositionIterator() {}

// </IsParentPositionIterator>


// <IsPrecedingInDocumentOrderPositionIterator>
SERIALIZABLE_CLASS_VERSIONS(IsPrecedingInDocumentOrderPositionIterator)void IsPrecedingInDocumentOrderPositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<IsPrecedingInDocumentOrderPositionIterator, PlanIteratorState>*)this);
}


void IsPrecedingInDocumentOrderPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsPrecedingInDocumentOrderPositionIterator::~IsPrecedingInDocumentOrderPositionIterator() {}

// </IsPrecedingInDocumentOrderPositionIterator>


// <IsFollowingInDocumentOrderPositionIterator>
SERIALIZABLE_CLASS_VERSIONS(IsFollowingInDocumentOrderPositionIterator)void IsFollowingInDocumentOrderPositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<IsFollowingInDocumentOrderPositionIterator, PlanIteratorState>*)this);
}


void IsFollowingInDocumentOrderPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsFollowingInDocumentOrderPositionIterator::~IsFollowingInDocumentOrderPositionIterator() {}

// </IsFollowingInDocumentOrderPositionIterator>


// <LevelPositionIterator>
SERIALIZABLE_CLASS_VERSIONS(LevelPositionIterator)void LevelPositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<LevelPositionIterator, PlanIteratorState>*)this);
}


void LevelPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

LevelPositionIterator::~LevelPositionIterator() {}

// </LevelPositionIterator>


// <IsAttributePositionIterator>
SERIALIZABLE_CLASS_VERSIONS(IsAttributePositionIterator)void IsAttributePositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<IsAttributePositionIterator, PlanIteratorState>*)this);
}


void IsAttributePositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsAttributePositionIterator::~IsAttributePositionIterator() {}

// </IsAttributePositionIterator>


// <IsCommentPositionIterator>
SERIALIZABLE_CLASS_VERSIONS(IsCommentPositionIterator)void IsCommentPositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<IsCommentPositionIterator, PlanIteratorState>*)this);
}


void IsCommentPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsCommentPositionIterator::~IsCommentPositionIterator() {}

// </IsCommentPositionIterator>


// <IsDocumentPositionIterator>
SERIALIZABLE_CLASS_VERSIONS(IsDocumentPositionIterator)void IsDocumentPositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<IsDocumentPositionIterator, PlanIteratorState>*)this);
}


void IsDocumentPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsDocumentPositionIterator::~IsDocumentPositionIterator() {}

// </IsDocumentPositionIterator>


// <IsElementPositionIterator>
SERIALIZABLE_CLASS_VERSIONS(IsElementPositionIterator)void IsElementPositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<IsElementPositionIterator, PlanIteratorState>*)this);
}


void IsElementPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsElementPositionIterator::~IsElementPositionIterator() {}

// </IsElementPositionIterator>


// <IsProcessingInstructionPositionIterator>
SERIALIZABLE_CLASS_VERSIONS(IsProcessingInstructionPositionIterator)void IsProcessingInstructionPositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<IsProcessingInstructionPositionIterator, PlanIteratorState>*)this);
}


void IsProcessingInstructionPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsProcessingInstructionPositionIterator::~IsProcessingInstructionPositionIterator() {}

// </IsProcessingInstructionPositionIterator>


// <IsTextPositionIterator>
SERIALIZABLE_CLASS_VERSIONS(IsTextPositionIterator)void IsTextPositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<IsTextPositionIterator, PlanIteratorState>*)this);
}


void IsTextPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsTextPositionIterator::~IsTextPositionIterator() {}

// </IsTextPositionIterator>


// <IsSiblingPositionIterator>
SERIALIZABLE_CLASS_VERSIONS(IsSiblingPositionIterator)void IsSiblingPositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<IsSiblingPositionIterator, PlanIteratorState>*)this);
}


void IsSiblingPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsSiblingPositionIterator::~IsSiblingPositionIterator() {}

// </IsSiblingPositionIterator>


// <InSameTreePositionIterator>
SERIALIZABLE_CLASS_VERSIONS(InSameTreePositionIterator)void InSameTreePositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<InSameTreePositionIterator, PlanIteratorState>*)this);
}


void InSameTreePositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

InSameTreePositionIterator::~InSameTreePositionIterator() {}

// </InSameTreePositionIterator>


// <InCollectionPositionIterator>
SERIALIZABLE_CLASS_VERSIONS(InCollectionPositionIterator)void InCollectionPositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<InCollectionPositionIterator, PlanIteratorState>*)this);
}


void InCollectionPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

InCollectionPositionIterator::~InCollectionPositionIterator() {}

// </InCollectionPositionIterator>


// <InSameCollectionPositionIterator>
SERIALIZABLE_CLASS_VERSIONS(InSameCollectionPositionIterator)void InSameCollectionPositionIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<InSameCollectionPositionIterator, PlanIteratorState>*)this);
}


void InSameCollectionPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

InSameCollectionPositionIterator::~InSameCollectionPositionIterator() {}

// </InSameCollectionPositionIterator>



}



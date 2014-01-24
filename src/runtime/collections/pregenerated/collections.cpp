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
#include "runtime/collections/collections.h"
#include "system/globalenv.h"


#include "store/api/iterator.h"

namespace zorba {

// <ZorbaCreateCollectionIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaCreateCollectionIterator)

void ZorbaCreateCollectionIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ZorbaCreateCollectionIterator, PlanIteratorState>*)this);

    ar & theIsDynamic;
}


void ZorbaCreateCollectionIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaCreateCollectionIterator::~ZorbaCreateCollectionIterator() {}


zstring ZorbaCreateCollectionIterator::getNameAsString() const {
  return "zorba-store-static-collections-ddl:create";
}
// </ZorbaCreateCollectionIterator>


// <ZorbaDeleteCollectionIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaDeleteCollectionIterator)

void ZorbaDeleteCollectionIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ZorbaDeleteCollectionIterator, PlanIteratorState>*)this);

    ar & theIsDynamic;
}


void ZorbaDeleteCollectionIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaDeleteCollectionIterator::~ZorbaDeleteCollectionIterator() {}


zstring ZorbaDeleteCollectionIterator::getNameAsString() const {
  return "zorba-store-static-collections-ddl:delete";
}
// </ZorbaDeleteCollectionIterator>


// <IsAvailableCollectionIterator>
SERIALIZABLE_CLASS_VERSIONS(IsAvailableCollectionIterator)

void IsAvailableCollectionIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<IsAvailableCollectionIterator, PlanIteratorState>*)this);

    ar & theIsDynamic;
}


void IsAvailableCollectionIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsAvailableCollectionIterator::~IsAvailableCollectionIterator() {}


zstring IsAvailableCollectionIterator::getNameAsString() const {
  return "zorba-store-static-collections-ddl:is-available-collection";
}
// </IsAvailableCollectionIterator>


// <AvailableCollectionsIterator>
SERIALIZABLE_CLASS_VERSIONS(AvailableCollectionsIterator)

void AvailableCollectionsIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<AvailableCollectionsIterator, AvailableCollectionsIteratorState>*)this);

    ar & theIsDynamic;
}


void AvailableCollectionsIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

AvailableCollectionsIterator::~AvailableCollectionsIterator() {}

AvailableCollectionsIteratorState::AvailableCollectionsIteratorState() {}


zstring AvailableCollectionsIterator::getNameAsString() const {
  return "zorba-store-static-collections-ddl:available-collections";
}
// </AvailableCollectionsIterator>


// <FnCollectionIterator>
SERIALIZABLE_CLASS_VERSIONS(FnCollectionIterator)

void FnCollectionIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnCollectionIterator, FnCollectionIteratorState>*)this);
}


void FnCollectionIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnCollectionIterator::~FnCollectionIterator() {}

FnCollectionIteratorState::FnCollectionIteratorState() {}


zstring FnCollectionIterator::getNameAsString() const {
  return "fn:collection";
}
// </FnCollectionIterator>


// <ZorbaCollectionIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaCollectionIterator)

void ZorbaCollectionIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ZorbaCollectionIterator, ZorbaCollectionIteratorState>*)this);

    ar & theIsDynamic;
}


void ZorbaCollectionIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaCollectionIterator::~ZorbaCollectionIterator() {}

ZorbaCollectionIteratorState::ZorbaCollectionIteratorState() {}


zstring ZorbaCollectionIterator::getNameAsString() const {
  return "zorba-store-static-collections-dml:collection";
}
// </ZorbaCollectionIterator>


// <ZorbaCollectionNameIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaCollectionNameIterator)

void ZorbaCollectionNameIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ZorbaCollectionNameIterator, PlanIteratorState>*)this);
}


void ZorbaCollectionNameIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaCollectionNameIterator::~ZorbaCollectionNameIterator() {}


zstring ZorbaCollectionNameIterator::getNameAsString() const {
  return "zorba-store-static-collections-dml:collection-name";
}
// </ZorbaCollectionNameIterator>


// <ZorbaIndexOfIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaIndexOfIterator)

void ZorbaIndexOfIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ZorbaIndexOfIterator, PlanIteratorState>*)this);

    ar & theIsDynamic;
}


void ZorbaIndexOfIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaIndexOfIterator::~ZorbaIndexOfIterator() {}


zstring ZorbaIndexOfIterator::getNameAsString() const {
  return "zorba-store-static-collections-dml:index-of";
}
// </ZorbaIndexOfIterator>


// <ZorbaApplyInsertIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaApplyInsertIterator)

void ZorbaApplyInsertIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (ZorbaCollectionIteratorHelper<ZorbaApplyInsertIterator, ZorbaApplyInsertIteratorState>*)this);
}


void ZorbaApplyInsertIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaApplyInsertIterator::~ZorbaApplyInsertIterator() {}

ZorbaApplyInsertIteratorState::ZorbaApplyInsertIteratorState() {}


zstring ZorbaApplyInsertIterator::getNameAsString() const {
  return "zorba-store-static-collections-dml:apply-insert";
}
// </ZorbaApplyInsertIterator>


// <ZorbaInsertAfterIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaInsertAfterIterator)

void ZorbaInsertAfterIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (ZorbaCollectionIteratorHelper<ZorbaInsertAfterIterator, PlanIteratorState>*)this);

    ar & theIsDynamic;
}


void ZorbaInsertAfterIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaInsertAfterIterator::~ZorbaInsertAfterIterator() {}


zstring ZorbaInsertAfterIterator::getNameAsString() const {
  return "zorba-store-static-collections-dml:insert-after";
}
// </ZorbaInsertAfterIterator>


// <ZorbaInsertBeforeIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaInsertBeforeIterator)

void ZorbaInsertBeforeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (ZorbaCollectionIteratorHelper<ZorbaInsertBeforeIterator, PlanIteratorState>*)this);
}


void ZorbaInsertBeforeIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaInsertBeforeIterator::~ZorbaInsertBeforeIterator() {}


zstring ZorbaInsertBeforeIterator::getNameAsString() const {
  return "zorba-store-static-collections-dml:insert-before";
}
// </ZorbaInsertBeforeIterator>


// <ZorbaInsertFirstIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaInsertFirstIterator)

void ZorbaInsertFirstIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (ZorbaCollectionIteratorHelper<ZorbaInsertFirstIterator,PlanIteratorState>*)this);
}


void ZorbaInsertFirstIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaInsertFirstIterator::~ZorbaInsertFirstIterator() {}


zstring ZorbaInsertFirstIterator::getNameAsString() const {
  return "zorba-store-static-collections-dml:insert-first";
}
// </ZorbaInsertFirstIterator>


// <ZorbaInsertLastIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaInsertLastIterator)

void ZorbaInsertLastIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (ZorbaCollectionIteratorHelper<ZorbaInsertLastIterator, PlanIteratorState>*)this);
}


void ZorbaInsertLastIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaInsertLastIterator::~ZorbaInsertLastIterator() {}


zstring ZorbaInsertLastIterator::getNameAsString() const {
  return "zorba-store-static-collections-dml:insert-last";
}
// </ZorbaInsertLastIterator>


// <ZorbaApplyInsertFirstIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaApplyInsertFirstIterator)

void ZorbaApplyInsertFirstIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (ZorbaCollectionIteratorHelper<ZorbaApplyInsertFirstIterator, ZorbaApplyInsertFirstIteratorState>*)this);
}


void ZorbaApplyInsertFirstIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaApplyInsertFirstIterator::~ZorbaApplyInsertFirstIterator() {}

ZorbaApplyInsertFirstIteratorState::ZorbaApplyInsertFirstIteratorState() {}


zstring ZorbaApplyInsertFirstIterator::getNameAsString() const {
  return "zorba-store-static-collections-dml:apply-insert-first";
}
// </ZorbaApplyInsertFirstIterator>


// <ZorbaApplyInsertLastIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaApplyInsertLastIterator)

void ZorbaApplyInsertLastIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (ZorbaCollectionIteratorHelper<ZorbaApplyInsertLastIterator, ZorbaApplyInsertLastIteratorState>*)this);
}


void ZorbaApplyInsertLastIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaApplyInsertLastIterator::~ZorbaApplyInsertLastIterator() {}

ZorbaApplyInsertLastIteratorState::ZorbaApplyInsertLastIteratorState() {}


zstring ZorbaApplyInsertLastIterator::getNameAsString() const {
  return "zorba-store-static-collections-dml:apply-insert-last";
}
// </ZorbaApplyInsertLastIterator>


// <ZorbaApplyInsertBeforeIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaApplyInsertBeforeIterator)

void ZorbaApplyInsertBeforeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (ZorbaCollectionIteratorHelper<ZorbaApplyInsertBeforeIterator, ZorbaApplyInsertBeforeIteratorState>*)this);
}


void ZorbaApplyInsertBeforeIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaApplyInsertBeforeIterator::~ZorbaApplyInsertBeforeIterator() {}

ZorbaApplyInsertBeforeIteratorState::ZorbaApplyInsertBeforeIteratorState() {}


zstring ZorbaApplyInsertBeforeIterator::getNameAsString() const {
  return "zorba-store-static-collections-dml:apply-insert-before";
}
// </ZorbaApplyInsertBeforeIterator>


// <ZorbaApplyInsertAfterIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaApplyInsertAfterIterator)

void ZorbaApplyInsertAfterIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (ZorbaCollectionIteratorHelper<ZorbaApplyInsertAfterIterator, ZorbaApplyInsertAfterIteratorState>*)this);
}


void ZorbaApplyInsertAfterIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaApplyInsertAfterIterator::~ZorbaApplyInsertAfterIterator() {}

ZorbaApplyInsertAfterIteratorState::ZorbaApplyInsertAfterIteratorState() {}


zstring ZorbaApplyInsertAfterIterator::getNameAsString() const {
  return "zorba-store-static-collections-dml:apply-insert-after";
}
// </ZorbaApplyInsertAfterIterator>


// <ZorbaDeleteIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaDeleteIterator)

void ZorbaDeleteIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ZorbaDeleteIterator, PlanIteratorState>*)this);

    ar & theIsDynamic;
}


void ZorbaDeleteIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaDeleteIterator::~ZorbaDeleteIterator() {}


zstring ZorbaDeleteIterator::getNameAsString() const {
  return "zorba-store-static-collections-dml:delete";
}
// </ZorbaDeleteIterator>


// <ZorbaDeleteFirstIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaDeleteFirstIterator)

void ZorbaDeleteFirstIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ZorbaDeleteFirstIterator, PlanIteratorState>*)this);

    ar & theIsDynamic;
}


void ZorbaDeleteFirstIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaDeleteFirstIterator::~ZorbaDeleteFirstIterator() {}


zstring ZorbaDeleteFirstIterator::getNameAsString() const {
  return "zorba-store-static-collections-dml:delete-first";
}
// </ZorbaDeleteFirstIterator>


// <ZorbaDeleteLastIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaDeleteLastIterator)

void ZorbaDeleteLastIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ZorbaDeleteLastIterator, PlanIteratorState>*)this);

    ar & theIsDynamic;
}


void ZorbaDeleteLastIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaDeleteLastIterator::~ZorbaDeleteLastIterator() {}


zstring ZorbaDeleteLastIterator::getNameAsString() const {
  return "zorba-store-static-collections-dml:delete-last";
}
// </ZorbaDeleteLastIterator>


// <ZorbaEditIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaEditIterator)

void ZorbaEditIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ZorbaEditIterator, PlanIteratorState>*)this);

    ar & theIsDynamic;
    ar & theNeedToCopy;
}


void ZorbaEditIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaEditIterator::~ZorbaEditIterator() {}


zstring ZorbaEditIterator::getNameAsString() const {
  return "zorba-store-static-collections-dml:edit";
}
// </ZorbaEditIterator>


// <ZorbaInsertIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaInsertIterator)

void ZorbaInsertIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (ZorbaCollectionIteratorHelper<ZorbaInsertIterator, PlanIteratorState>*)this);
}


void ZorbaInsertIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaInsertIterator::~ZorbaInsertIterator() {}


zstring ZorbaInsertIterator::getNameAsString() const {
  return "zorba-store-static-collections-dml:insert";
}
// </ZorbaInsertIterator>


// <ZorbaTruncateCollectionIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaTruncateCollectionIterator)

void ZorbaTruncateCollectionIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ZorbaTruncateCollectionIterator, PlanIteratorState>*)this);

    ar & theIsDynamic;
}


void ZorbaTruncateCollectionIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaTruncateCollectionIterator::~ZorbaTruncateCollectionIterator() {}


zstring ZorbaTruncateCollectionIterator::getNameAsString() const {
  return "zorba-store-static-collections-dml:truncate";
}
// </ZorbaTruncateCollectionIterator>


// <IsAvailableIndexIterator>
SERIALIZABLE_CLASS_VERSIONS(IsAvailableIndexIterator)

void IsAvailableIndexIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<IsAvailableIndexIterator, PlanIteratorState>*)this);
}


void IsAvailableIndexIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsAvailableIndexIterator::~IsAvailableIndexIterator() {}


zstring IsAvailableIndexIterator::getNameAsString() const {
  return "zorba-store-indexes-static-ddl:is-available-index";
}
// </IsAvailableIndexIterator>


// <AvailableIndexesIterator>
SERIALIZABLE_CLASS_VERSIONS(AvailableIndexesIterator)

void AvailableIndexesIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<AvailableIndexesIterator, AvailableIndexesIteratorState>*)this);
}


void AvailableIndexesIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

AvailableIndexesIterator::~AvailableIndexesIterator() {}

AvailableIndexesIteratorState::AvailableIndexesIteratorState() {}


zstring AvailableIndexesIterator::getNameAsString() const {
  return "zorba-store-indexes-static-ddl:available-indexes";
}
// </AvailableIndexesIterator>


// <IsActivatedICIterator>
SERIALIZABLE_CLASS_VERSIONS(IsActivatedICIterator)

void IsActivatedICIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<IsActivatedICIterator, PlanIteratorState>*)this);
}


void IsActivatedICIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsActivatedICIterator::~IsActivatedICIterator() {}


zstring IsActivatedICIterator::getNameAsString() const {
  return "zorba-store-static-integrity-constraints-ddl:is-activated-integrity-constraint";
}
// </IsActivatedICIterator>


// <ActivatedICsIterator>
SERIALIZABLE_CLASS_VERSIONS(ActivatedICsIterator)

void ActivatedICsIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ActivatedICsIterator, ActivatedICsIteratorState>*)this);
}


void ActivatedICsIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ActivatedICsIterator::~ActivatedICsIterator() {}

ActivatedICsIteratorState::ActivatedICsIteratorState() {}


zstring ActivatedICsIterator::getNameAsString() const {
  return "zorba-store-static-integrity-constraints-ddl:activated-integrity-constraints";
}
// </ActivatedICsIterator>


// <IsDeclaredCollectionIterator>
SERIALIZABLE_CLASS_VERSIONS(IsDeclaredCollectionIterator)

void IsDeclaredCollectionIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<IsDeclaredCollectionIterator, PlanIteratorState>*)this);
}


void IsDeclaredCollectionIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsDeclaredCollectionIterator::~IsDeclaredCollectionIterator() {}


zstring IsDeclaredCollectionIterator::getNameAsString() const {
  return "zorba-store-static-collections-ddl:is-declared-collection";
}
// </IsDeclaredCollectionIterator>


// <DeclaredCollectionsIterator>
SERIALIZABLE_CLASS_VERSIONS(DeclaredCollectionsIterator)

void DeclaredCollectionsIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<DeclaredCollectionsIterator, DeclaredCollectionsIteratorState>*)this);
}


void DeclaredCollectionsIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

DeclaredCollectionsIterator::~DeclaredCollectionsIterator() {}

DeclaredCollectionsIteratorState::DeclaredCollectionsIteratorState() {}


zstring DeclaredCollectionsIterator::getNameAsString() const {
  return "zorba-store-static-collections-ddl:declared-collections";
}
// </DeclaredCollectionsIterator>


// <IsDeclaredIndexIterator>
SERIALIZABLE_CLASS_VERSIONS(IsDeclaredIndexIterator)

void IsDeclaredIndexIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<IsDeclaredIndexIterator, PlanIteratorState>*)this);
}


void IsDeclaredIndexIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsDeclaredIndexIterator::~IsDeclaredIndexIterator() {}


zstring IsDeclaredIndexIterator::getNameAsString() const {
  return "zorba-store-indexes-static-ddl:is-declared-index";
}
// </IsDeclaredIndexIterator>


// <DeclaredIndexesIterator>
SERIALIZABLE_CLASS_VERSIONS(DeclaredIndexesIterator)

void DeclaredIndexesIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<DeclaredIndexesIterator, DeclaredIndexesIteratorState>*)this);
}


void DeclaredIndexesIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

DeclaredIndexesIterator::~DeclaredIndexesIterator() {}

DeclaredIndexesIteratorState::DeclaredIndexesIteratorState() {}


void DeclaredIndexesIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  nameItState = NULL;
}

zstring DeclaredIndexesIterator::getNameAsString() const {
  return "zorba-store-indexes-static-ddl:declared-indexes";
}
// </DeclaredIndexesIterator>


// <IsDeclaredICIterator>
SERIALIZABLE_CLASS_VERSIONS(IsDeclaredICIterator)

void IsDeclaredICIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<IsDeclaredICIterator, PlanIteratorState>*)this);
}


void IsDeclaredICIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsDeclaredICIterator::~IsDeclaredICIterator() {}


zstring IsDeclaredICIterator::getNameAsString() const {
  return "zorba-store-static-integrity-constraints-ddl:is-declared-integrity-constraint";
}
// </IsDeclaredICIterator>


// <DeclaredICsIterator>
SERIALIZABLE_CLASS_VERSIONS(DeclaredICsIterator)

void DeclaredICsIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<DeclaredICsIterator, DeclaredICsIteratorState>*)this);
}


void DeclaredICsIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

DeclaredICsIterator::~DeclaredICsIterator() {}

DeclaredICsIteratorState::DeclaredICsIteratorState() {}


void DeclaredICsIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  nameItState = NULL;
}

zstring DeclaredICsIterator::getNameAsString() const {
  return "zorba-store-static-integrity-constraints-ddl:declared-integrity-constraints";
}
// </DeclaredICsIterator>


// <FnURICollectionIterator>
SERIALIZABLE_CLASS_VERSIONS(FnURICollectionIterator)

void FnURICollectionIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnURICollectionIterator, FnURICollectionIteratorState>*)this);
}


void FnURICollectionIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnURICollectionIterator::~FnURICollectionIterator() {}

FnURICollectionIteratorState::FnURICollectionIteratorState() {}


zstring FnURICollectionIterator::getNameAsString() const {
  return "fn:uri-collection";
}
// </FnURICollectionIterator>



}



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

// </ZorbaIndexOfIterator>


// <ZorbaInsertNodesIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaInsertNodesIterator)

void ZorbaInsertNodesIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (ZorbaCollectionIteratorHelper<ZorbaInsertNodesIterator, PlanIteratorState>*)this);
}


void ZorbaInsertNodesIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaInsertNodesIterator::~ZorbaInsertNodesIterator() {}

// </ZorbaInsertNodesIterator>


// <ZorbaInsertNodesFirstIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaInsertNodesFirstIterator)

void ZorbaInsertNodesFirstIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (ZorbaCollectionIteratorHelper<ZorbaInsertNodesFirstIterator, PlanIteratorState>*)this);
}


void ZorbaInsertNodesFirstIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaInsertNodesFirstIterator::~ZorbaInsertNodesFirstIterator() {}

// </ZorbaInsertNodesFirstIterator>


// <ZorbaInsertNodesLastIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaInsertNodesLastIterator)

void ZorbaInsertNodesLastIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (ZorbaCollectionIteratorHelper<ZorbaInsertNodesLastIterator, PlanIteratorState>*)this);
}


void ZorbaInsertNodesLastIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaInsertNodesLastIterator::~ZorbaInsertNodesLastIterator() {}

// </ZorbaInsertNodesLastIterator>


// <ZorbaInsertNodesBeforeIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaInsertNodesBeforeIterator)

void ZorbaInsertNodesBeforeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (ZorbaCollectionIteratorHelper<ZorbaInsertNodesBeforeIterator, PlanIteratorState>*)this);
}


void ZorbaInsertNodesBeforeIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaInsertNodesBeforeIterator::~ZorbaInsertNodesBeforeIterator() {}

// </ZorbaInsertNodesBeforeIterator>


// <ZorbaInsertNodesAfterIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaInsertNodesAfterIterator)

void ZorbaInsertNodesAfterIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (ZorbaCollectionIteratorHelper<ZorbaInsertNodesAfterIterator, PlanIteratorState>*)this);

    ar & theIsDynamic;
}


void ZorbaInsertNodesAfterIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaInsertNodesAfterIterator::~ZorbaInsertNodesAfterIterator() {}

// </ZorbaInsertNodesAfterIterator>


// <ZorbaApplyInsertNodesIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaApplyInsertNodesIterator)

void ZorbaApplyInsertNodesIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesIterator, ZorbaApplyInsertNodesIteratorState>*)this);
}


void ZorbaApplyInsertNodesIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaApplyInsertNodesIterator::~ZorbaApplyInsertNodesIterator() {}

ZorbaApplyInsertNodesIteratorState::ZorbaApplyInsertNodesIteratorState() {}

// </ZorbaApplyInsertNodesIterator>


// <ZorbaApplyInsertNodesFirstIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaApplyInsertNodesFirstIterator)

void ZorbaApplyInsertNodesFirstIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesFirstIterator, ZorbaApplyInsertNodesFirstIteratorState>*)this);
}


void ZorbaApplyInsertNodesFirstIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaApplyInsertNodesFirstIterator::~ZorbaApplyInsertNodesFirstIterator() {}

ZorbaApplyInsertNodesFirstIteratorState::ZorbaApplyInsertNodesFirstIteratorState() {}

// </ZorbaApplyInsertNodesFirstIterator>


// <ZorbaApplyInsertNodesLastIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaApplyInsertNodesLastIterator)

void ZorbaApplyInsertNodesLastIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesLastIterator, ZorbaApplyInsertNodesLastIteratorState>*)this);
}


void ZorbaApplyInsertNodesLastIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaApplyInsertNodesLastIterator::~ZorbaApplyInsertNodesLastIterator() {}

ZorbaApplyInsertNodesLastIteratorState::ZorbaApplyInsertNodesLastIteratorState() {}

// </ZorbaApplyInsertNodesLastIterator>


// <ZorbaApplyInsertNodesBeforeIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaApplyInsertNodesBeforeIterator)

void ZorbaApplyInsertNodesBeforeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesBeforeIterator, ZorbaApplyInsertNodesBeforeIteratorState>*)this);
}


void ZorbaApplyInsertNodesBeforeIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaApplyInsertNodesBeforeIterator::~ZorbaApplyInsertNodesBeforeIterator() {}

ZorbaApplyInsertNodesBeforeIteratorState::ZorbaApplyInsertNodesBeforeIteratorState() {}

// </ZorbaApplyInsertNodesBeforeIterator>


// <ZorbaApplyInsertNodesAfterIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaApplyInsertNodesAfterIterator)

void ZorbaApplyInsertNodesAfterIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (ZorbaCollectionIteratorHelper<ZorbaApplyInsertNodesAfterIterator, ZorbaApplyInsertNodesAfterIteratorState>*)this);
}


void ZorbaApplyInsertNodesAfterIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaApplyInsertNodesAfterIterator::~ZorbaApplyInsertNodesAfterIterator() {}

ZorbaApplyInsertNodesAfterIteratorState::ZorbaApplyInsertNodesAfterIteratorState() {}

// </ZorbaApplyInsertNodesAfterIterator>


// <ZorbaDeleteNodesIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaDeleteNodesIterator)

void ZorbaDeleteNodesIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ZorbaDeleteNodesIterator, PlanIteratorState>*)this);

    ar & theIsDynamic;
}


void ZorbaDeleteNodesIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaDeleteNodesIterator::~ZorbaDeleteNodesIterator() {}

// </ZorbaDeleteNodesIterator>


// <ZorbaDeleteNodesFirstIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaDeleteNodesFirstIterator)

void ZorbaDeleteNodesFirstIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ZorbaDeleteNodesFirstIterator, PlanIteratorState>*)this);

    ar & theIsDynamic;
}


void ZorbaDeleteNodesFirstIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaDeleteNodesFirstIterator::~ZorbaDeleteNodesFirstIterator() {}

// </ZorbaDeleteNodesFirstIterator>


// <ZorbaDeleteNodesLastIterator>
SERIALIZABLE_CLASS_VERSIONS(ZorbaDeleteNodesLastIterator)

void ZorbaDeleteNodesLastIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ZorbaDeleteNodesLastIterator, PlanIteratorState>*)this);

    ar & theIsDynamic;
}


void ZorbaDeleteNodesLastIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaDeleteNodesLastIterator::~ZorbaDeleteNodesLastIterator() {}

// </ZorbaDeleteNodesLastIterator>


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

// </FnURICollectionIterator>



}



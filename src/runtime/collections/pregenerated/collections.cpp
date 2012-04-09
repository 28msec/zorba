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

// <FnCollectionIterator>
FnCollectionIterator::class_factory<FnCollectionIterator>
FnCollectionIterator::g_class_factory;


void FnCollectionIterator::accept(PlanIterVisitor& v) const {
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
ZorbaCollectionIterator::class_factory<ZorbaCollectionIterator>
ZorbaCollectionIterator::g_class_factory;


void ZorbaCollectionIterator::accept(PlanIterVisitor& v) const {
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


// <ZorbaIndexOfIterator>
ZorbaIndexOfIterator::class_factory<ZorbaIndexOfIterator>
ZorbaIndexOfIterator::g_class_factory;


void ZorbaIndexOfIterator::accept(PlanIterVisitor& v) const {
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


// <ZorbaCreateCollectionIterator>
ZorbaCreateCollectionIterator::class_factory<ZorbaCreateCollectionIterator>
ZorbaCreateCollectionIterator::g_class_factory;


void ZorbaCreateCollectionIterator::accept(PlanIterVisitor& v) const {
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
ZorbaDeleteCollectionIterator::class_factory<ZorbaDeleteCollectionIterator>
ZorbaDeleteCollectionIterator::g_class_factory;


void ZorbaDeleteCollectionIterator::accept(PlanIterVisitor& v) const {
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


// <ZorbaInsertNodesIterator>
ZorbaInsertNodesIterator::class_factory<ZorbaInsertNodesIterator>
ZorbaInsertNodesIterator::g_class_factory;


void ZorbaInsertNodesIterator::accept(PlanIterVisitor& v) const {
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
ZorbaInsertNodesFirstIterator::class_factory<ZorbaInsertNodesFirstIterator>
ZorbaInsertNodesFirstIterator::g_class_factory;


void ZorbaInsertNodesFirstIterator::accept(PlanIterVisitor& v) const {
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
ZorbaInsertNodesLastIterator::class_factory<ZorbaInsertNodesLastIterator>
ZorbaInsertNodesLastIterator::g_class_factory;


void ZorbaInsertNodesLastIterator::accept(PlanIterVisitor& v) const {
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
ZorbaInsertNodesBeforeIterator::class_factory<ZorbaInsertNodesBeforeIterator>
ZorbaInsertNodesBeforeIterator::g_class_factory;


void ZorbaInsertNodesBeforeIterator::accept(PlanIterVisitor& v) const {
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
ZorbaInsertNodesAfterIterator::class_factory<ZorbaInsertNodesAfterIterator>
ZorbaInsertNodesAfterIterator::g_class_factory;


void ZorbaInsertNodesAfterIterator::accept(PlanIterVisitor& v) const {
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
ZorbaApplyInsertNodesIterator::class_factory<ZorbaApplyInsertNodesIterator>
ZorbaApplyInsertNodesIterator::g_class_factory;


void ZorbaApplyInsertNodesIterator::accept(PlanIterVisitor& v) const {
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
ZorbaApplyInsertNodesFirstIterator::class_factory<ZorbaApplyInsertNodesFirstIterator>
ZorbaApplyInsertNodesFirstIterator::g_class_factory;


void ZorbaApplyInsertNodesFirstIterator::accept(PlanIterVisitor& v) const {
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
ZorbaApplyInsertNodesLastIterator::class_factory<ZorbaApplyInsertNodesLastIterator>
ZorbaApplyInsertNodesLastIterator::g_class_factory;


void ZorbaApplyInsertNodesLastIterator::accept(PlanIterVisitor& v) const {
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
ZorbaApplyInsertNodesBeforeIterator::class_factory<ZorbaApplyInsertNodesBeforeIterator>
ZorbaApplyInsertNodesBeforeIterator::g_class_factory;


void ZorbaApplyInsertNodesBeforeIterator::accept(PlanIterVisitor& v) const {
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
ZorbaApplyInsertNodesAfterIterator::class_factory<ZorbaApplyInsertNodesAfterIterator>
ZorbaApplyInsertNodesAfterIterator::g_class_factory;


void ZorbaApplyInsertNodesAfterIterator::accept(PlanIterVisitor& v) const {
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
ZorbaDeleteNodesIterator::class_factory<ZorbaDeleteNodesIterator>
ZorbaDeleteNodesIterator::g_class_factory;


void ZorbaDeleteNodesIterator::accept(PlanIterVisitor& v) const {
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
ZorbaDeleteNodesFirstIterator::class_factory<ZorbaDeleteNodesFirstIterator>
ZorbaDeleteNodesFirstIterator::g_class_factory;


void ZorbaDeleteNodesFirstIterator::accept(PlanIterVisitor& v) const {
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
ZorbaDeleteNodesLastIterator::class_factory<ZorbaDeleteNodesLastIterator>
ZorbaDeleteNodesLastIterator::g_class_factory;


void ZorbaDeleteNodesLastIterator::accept(PlanIterVisitor& v) const {
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
ZorbaTruncateCollectionIterator::class_factory<ZorbaTruncateCollectionIterator>
ZorbaTruncateCollectionIterator::g_class_factory;


void ZorbaTruncateCollectionIterator::accept(PlanIterVisitor& v) const {
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


// <ZorbaCollectionNameIterator>
ZorbaCollectionNameIterator::class_factory<ZorbaCollectionNameIterator>
ZorbaCollectionNameIterator::g_class_factory;


void ZorbaCollectionNameIterator::accept(PlanIterVisitor& v) const {
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


// <IsAvailableCollectionIterator>
IsAvailableCollectionIterator::class_factory<IsAvailableCollectionIterator>
IsAvailableCollectionIterator::g_class_factory;


void IsAvailableCollectionIterator::accept(PlanIterVisitor& v) const {
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
AvailableCollectionsIterator::class_factory<AvailableCollectionsIterator>
AvailableCollectionsIterator::g_class_factory;


void AvailableCollectionsIterator::accept(PlanIterVisitor& v) const {
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


// <IsAvailableIndexIterator>
IsAvailableIndexIterator::class_factory<IsAvailableIndexIterator>
IsAvailableIndexIterator::g_class_factory;


void IsAvailableIndexIterator::accept(PlanIterVisitor& v) const {
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
AvailableIndexesIterator::class_factory<AvailableIndexesIterator>
AvailableIndexesIterator::g_class_factory;


void AvailableIndexesIterator::accept(PlanIterVisitor& v) const {
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
IsActivatedICIterator::class_factory<IsActivatedICIterator>
IsActivatedICIterator::g_class_factory;


void IsActivatedICIterator::accept(PlanIterVisitor& v) const {
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
ActivatedICsIterator::class_factory<ActivatedICsIterator>
ActivatedICsIterator::g_class_factory;


void ActivatedICsIterator::accept(PlanIterVisitor& v) const {
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
IsDeclaredCollectionIterator::class_factory<IsDeclaredCollectionIterator>
IsDeclaredCollectionIterator::g_class_factory;


void IsDeclaredCollectionIterator::accept(PlanIterVisitor& v) const {
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
DeclaredCollectionsIterator::class_factory<DeclaredCollectionsIterator>
DeclaredCollectionsIterator::g_class_factory;


void DeclaredCollectionsIterator::accept(PlanIterVisitor& v) const {
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
IsDeclaredIndexIterator::class_factory<IsDeclaredIndexIterator>
IsDeclaredIndexIterator::g_class_factory;


void IsDeclaredIndexIterator::accept(PlanIterVisitor& v) const {
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
DeclaredIndexesIterator::class_factory<DeclaredIndexesIterator>
DeclaredIndexesIterator::g_class_factory;


void DeclaredIndexesIterator::accept(PlanIterVisitor& v) const {
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
IsDeclaredICIterator::class_factory<IsDeclaredICIterator>
IsDeclaredICIterator::g_class_factory;


void IsDeclaredICIterator::accept(PlanIterVisitor& v) const {
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
DeclaredICsIterator::class_factory<DeclaredICsIterator>
DeclaredICsIterator::g_class_factory;


void DeclaredICsIterator::accept(PlanIterVisitor& v) const {
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
FnURICollectionIterator::class_factory<FnURICollectionIterator>
FnURICollectionIterator::g_class_factory;


void FnURICollectionIterator::accept(PlanIterVisitor& v) const {
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



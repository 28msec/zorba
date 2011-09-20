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
const char* FnCollectionIterator::class_name_str = "FnCollectionIterator";
FnCollectionIterator::class_factory<FnCollectionIterator>
FnCollectionIterator::g_class_factory;

const serialization::ClassVersion 
FnCollectionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnCollectionIterator::class_versions_count =
sizeof(FnCollectionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* ZorbaCollectionIterator::class_name_str = "ZorbaCollectionIterator";
ZorbaCollectionIterator::class_factory<ZorbaCollectionIterator>
ZorbaCollectionIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaCollectionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaCollectionIterator::class_versions_count =
sizeof(ZorbaCollectionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* ZorbaIndexOfIterator::class_name_str = "ZorbaIndexOfIterator";
ZorbaIndexOfIterator::class_factory<ZorbaIndexOfIterator>
ZorbaIndexOfIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaIndexOfIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaIndexOfIterator::class_versions_count =
sizeof(ZorbaIndexOfIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* ZorbaCreateCollectionIterator::class_name_str = "ZorbaCreateCollectionIterator";
ZorbaCreateCollectionIterator::class_factory<ZorbaCreateCollectionIterator>
ZorbaCreateCollectionIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaCreateCollectionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaCreateCollectionIterator::class_versions_count =
sizeof(ZorbaCreateCollectionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* ZorbaDeleteCollectionIterator::class_name_str = "ZorbaDeleteCollectionIterator";
ZorbaDeleteCollectionIterator::class_factory<ZorbaDeleteCollectionIterator>
ZorbaDeleteCollectionIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaDeleteCollectionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaDeleteCollectionIterator::class_versions_count =
sizeof(ZorbaDeleteCollectionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* ZorbaInsertNodesIterator::class_name_str = "ZorbaInsertNodesIterator";
ZorbaInsertNodesIterator::class_factory<ZorbaInsertNodesIterator>
ZorbaInsertNodesIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaInsertNodesIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaInsertNodesIterator::class_versions_count =
sizeof(ZorbaInsertNodesIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* ZorbaInsertNodesFirstIterator::class_name_str = "ZorbaInsertNodesFirstIterator";
ZorbaInsertNodesFirstIterator::class_factory<ZorbaInsertNodesFirstIterator>
ZorbaInsertNodesFirstIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaInsertNodesFirstIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaInsertNodesFirstIterator::class_versions_count =
sizeof(ZorbaInsertNodesFirstIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* ZorbaInsertNodesLastIterator::class_name_str = "ZorbaInsertNodesLastIterator";
ZorbaInsertNodesLastIterator::class_factory<ZorbaInsertNodesLastIterator>
ZorbaInsertNodesLastIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaInsertNodesLastIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaInsertNodesLastIterator::class_versions_count =
sizeof(ZorbaInsertNodesLastIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* ZorbaInsertNodesBeforeIterator::class_name_str = "ZorbaInsertNodesBeforeIterator";
ZorbaInsertNodesBeforeIterator::class_factory<ZorbaInsertNodesBeforeIterator>
ZorbaInsertNodesBeforeIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaInsertNodesBeforeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaInsertNodesBeforeIterator::class_versions_count =
sizeof(ZorbaInsertNodesBeforeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* ZorbaInsertNodesAfterIterator::class_name_str = "ZorbaInsertNodesAfterIterator";
ZorbaInsertNodesAfterIterator::class_factory<ZorbaInsertNodesAfterIterator>
ZorbaInsertNodesAfterIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaInsertNodesAfterIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaInsertNodesAfterIterator::class_versions_count =
sizeof(ZorbaInsertNodesAfterIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* ZorbaApplyInsertNodesIterator::class_name_str = "ZorbaApplyInsertNodesIterator";
ZorbaApplyInsertNodesIterator::class_factory<ZorbaApplyInsertNodesIterator>
ZorbaApplyInsertNodesIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaApplyInsertNodesIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaApplyInsertNodesIterator::class_versions_count =
sizeof(ZorbaApplyInsertNodesIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* ZorbaApplyInsertNodesFirstIterator::class_name_str = "ZorbaApplyInsertNodesFirstIterator";
ZorbaApplyInsertNodesFirstIterator::class_factory<ZorbaApplyInsertNodesFirstIterator>
ZorbaApplyInsertNodesFirstIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaApplyInsertNodesFirstIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaApplyInsertNodesFirstIterator::class_versions_count =
sizeof(ZorbaApplyInsertNodesFirstIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* ZorbaApplyInsertNodesLastIterator::class_name_str = "ZorbaApplyInsertNodesLastIterator";
ZorbaApplyInsertNodesLastIterator::class_factory<ZorbaApplyInsertNodesLastIterator>
ZorbaApplyInsertNodesLastIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaApplyInsertNodesLastIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaApplyInsertNodesLastIterator::class_versions_count =
sizeof(ZorbaApplyInsertNodesLastIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* ZorbaApplyInsertNodesBeforeIterator::class_name_str = "ZorbaApplyInsertNodesBeforeIterator";
ZorbaApplyInsertNodesBeforeIterator::class_factory<ZorbaApplyInsertNodesBeforeIterator>
ZorbaApplyInsertNodesBeforeIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaApplyInsertNodesBeforeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaApplyInsertNodesBeforeIterator::class_versions_count =
sizeof(ZorbaApplyInsertNodesBeforeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* ZorbaApplyInsertNodesAfterIterator::class_name_str = "ZorbaApplyInsertNodesAfterIterator";
ZorbaApplyInsertNodesAfterIterator::class_factory<ZorbaApplyInsertNodesAfterIterator>
ZorbaApplyInsertNodesAfterIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaApplyInsertNodesAfterIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaApplyInsertNodesAfterIterator::class_versions_count =
sizeof(ZorbaApplyInsertNodesAfterIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* ZorbaDeleteNodesIterator::class_name_str = "ZorbaDeleteNodesIterator";
ZorbaDeleteNodesIterator::class_factory<ZorbaDeleteNodesIterator>
ZorbaDeleteNodesIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaDeleteNodesIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaDeleteNodesIterator::class_versions_count =
sizeof(ZorbaDeleteNodesIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* ZorbaDeleteNodesFirstIterator::class_name_str = "ZorbaDeleteNodesFirstIterator";
ZorbaDeleteNodesFirstIterator::class_factory<ZorbaDeleteNodesFirstIterator>
ZorbaDeleteNodesFirstIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaDeleteNodesFirstIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaDeleteNodesFirstIterator::class_versions_count =
sizeof(ZorbaDeleteNodesFirstIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* ZorbaDeleteNodesLastIterator::class_name_str = "ZorbaDeleteNodesLastIterator";
ZorbaDeleteNodesLastIterator::class_factory<ZorbaDeleteNodesLastIterator>
ZorbaDeleteNodesLastIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaDeleteNodesLastIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaDeleteNodesLastIterator::class_versions_count =
sizeof(ZorbaDeleteNodesLastIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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


// <ZorbaCollectionNameIterator>
const char* ZorbaCollectionNameIterator::class_name_str = "ZorbaCollectionNameIterator";
ZorbaCollectionNameIterator::class_factory<ZorbaCollectionNameIterator>
ZorbaCollectionNameIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaCollectionNameIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaCollectionNameIterator::class_versions_count =
sizeof(ZorbaCollectionNameIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* IsAvailableCollectionIterator::class_name_str = "IsAvailableCollectionIterator";
IsAvailableCollectionIterator::class_factory<IsAvailableCollectionIterator>
IsAvailableCollectionIterator::g_class_factory;

const serialization::ClassVersion 
IsAvailableCollectionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsAvailableCollectionIterator::class_versions_count =
sizeof(IsAvailableCollectionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* AvailableCollectionsIterator::class_name_str = "AvailableCollectionsIterator";
AvailableCollectionsIterator::class_factory<AvailableCollectionsIterator>
AvailableCollectionsIterator::g_class_factory;

const serialization::ClassVersion 
AvailableCollectionsIterator::class_versions[] ={{ 1, 0x000905, false}};

const int AvailableCollectionsIterator::class_versions_count =
sizeof(AvailableCollectionsIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* IsAvailableIndexIterator::class_name_str = "IsAvailableIndexIterator";
IsAvailableIndexIterator::class_factory<IsAvailableIndexIterator>
IsAvailableIndexIterator::g_class_factory;

const serialization::ClassVersion 
IsAvailableIndexIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsAvailableIndexIterator::class_versions_count =
sizeof(IsAvailableIndexIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* AvailableIndexesIterator::class_name_str = "AvailableIndexesIterator";
AvailableIndexesIterator::class_factory<AvailableIndexesIterator>
AvailableIndexesIterator::g_class_factory;

const serialization::ClassVersion 
AvailableIndexesIterator::class_versions[] ={{ 1, 0x000905, false}};

const int AvailableIndexesIterator::class_versions_count =
sizeof(AvailableIndexesIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* IsActivatedICIterator::class_name_str = "IsActivatedICIterator";
IsActivatedICIterator::class_factory<IsActivatedICIterator>
IsActivatedICIterator::g_class_factory;

const serialization::ClassVersion 
IsActivatedICIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsActivatedICIterator::class_versions_count =
sizeof(IsActivatedICIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* ActivatedICsIterator::class_name_str = "ActivatedICsIterator";
ActivatedICsIterator::class_factory<ActivatedICsIterator>
ActivatedICsIterator::g_class_factory;

const serialization::ClassVersion 
ActivatedICsIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ActivatedICsIterator::class_versions_count =
sizeof(ActivatedICsIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* IsDeclaredCollectionIterator::class_name_str = "IsDeclaredCollectionIterator";
IsDeclaredCollectionIterator::class_factory<IsDeclaredCollectionIterator>
IsDeclaredCollectionIterator::g_class_factory;

const serialization::ClassVersion 
IsDeclaredCollectionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsDeclaredCollectionIterator::class_versions_count =
sizeof(IsDeclaredCollectionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* DeclaredCollectionsIterator::class_name_str = "DeclaredCollectionsIterator";
DeclaredCollectionsIterator::class_factory<DeclaredCollectionsIterator>
DeclaredCollectionsIterator::g_class_factory;

const serialization::ClassVersion 
DeclaredCollectionsIterator::class_versions[] ={{ 1, 0x000905, false}};

const int DeclaredCollectionsIterator::class_versions_count =
sizeof(DeclaredCollectionsIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* IsDeclaredIndexIterator::class_name_str = "IsDeclaredIndexIterator";
IsDeclaredIndexIterator::class_factory<IsDeclaredIndexIterator>
IsDeclaredIndexIterator::g_class_factory;

const serialization::ClassVersion 
IsDeclaredIndexIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsDeclaredIndexIterator::class_versions_count =
sizeof(IsDeclaredIndexIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* DeclaredIndexesIterator::class_name_str = "DeclaredIndexesIterator";
DeclaredIndexesIterator::class_factory<DeclaredIndexesIterator>
DeclaredIndexesIterator::g_class_factory;

const serialization::ClassVersion 
DeclaredIndexesIterator::class_versions[] ={{ 1, 0x000905, false}};

const int DeclaredIndexesIterator::class_versions_count =
sizeof(DeclaredIndexesIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* IsDeclaredICIterator::class_name_str = "IsDeclaredICIterator";
IsDeclaredICIterator::class_factory<IsDeclaredICIterator>
IsDeclaredICIterator::g_class_factory;

const serialization::ClassVersion 
IsDeclaredICIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsDeclaredICIterator::class_versions_count =
sizeof(IsDeclaredICIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* DeclaredICsIterator::class_name_str = "DeclaredICsIterator";
DeclaredICsIterator::class_factory<DeclaredICsIterator>
DeclaredICsIterator::g_class_factory;

const serialization::ClassVersion 
DeclaredICsIterator::class_versions[] ={{ 1, 0x000905, false}};

const int DeclaredICsIterator::class_versions_count =
sizeof(DeclaredICsIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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



}



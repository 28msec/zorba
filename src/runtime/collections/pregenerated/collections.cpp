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



}



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

#include "runtime/visitors/planiter_visitor.h"
#include "runtime/indexing/index_ddl.h"
#include "system/globalenv.h"


#include "store/api/iterator.h"

namespace zorba {

// <CreateIndexIterator>
const char* CreateIndexIterator::class_name_str = "CreateIndexIterator";
CreateIndexIterator::class_factory<CreateIndexIterator>
CreateIndexIterator::g_class_factory;

const serialization::ClassVersion 
CreateIndexIterator::class_versions[] ={{ 1, 0x000905, false}};

const int CreateIndexIterator::class_versions_count =
sizeof(CreateIndexIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void CreateIndexIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

CreateIndexIterator::~CreateIndexIterator() {}

// </CreateIndexIterator>


// <DeleteIndexIterator>
const char* DeleteIndexIterator::class_name_str = "DeleteIndexIterator";
DeleteIndexIterator::class_factory<DeleteIndexIterator>
DeleteIndexIterator::g_class_factory;

const serialization::ClassVersion 
DeleteIndexIterator::class_versions[] ={{ 1, 0x000905, false}};

const int DeleteIndexIterator::class_versions_count =
sizeof(DeleteIndexIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void DeleteIndexIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

DeleteIndexIterator::~DeleteIndexIterator() {}

// </DeleteIndexIterator>


// <CreateInternalIndexIterator>
const char* CreateInternalIndexIterator::class_name_str = "CreateInternalIndexIterator";
CreateInternalIndexIterator::class_factory<CreateInternalIndexIterator>
CreateInternalIndexIterator::g_class_factory;

const serialization::ClassVersion 
CreateInternalIndexIterator::class_versions[] ={{ 1, 0x000905, false}};

const int CreateInternalIndexIterator::class_versions_count =
sizeof(CreateInternalIndexIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void CreateInternalIndexIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

CreateInternalIndexIterator::~CreateInternalIndexIterator() {}

// </CreateInternalIndexIterator>


// <RefreshIndexIterator>
const char* RefreshIndexIterator::class_name_str = "RefreshIndexIterator";
RefreshIndexIterator::class_factory<RefreshIndexIterator>
RefreshIndexIterator::g_class_factory;

const serialization::ClassVersion 
RefreshIndexIterator::class_versions[] ={{ 1, 0x000905, false}};

const int RefreshIndexIterator::class_versions_count =
sizeof(RefreshIndexIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void RefreshIndexIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

RefreshIndexIterator::~RefreshIndexIterator() {}

// </RefreshIndexIterator>


// <IndexEntryBuilderIterator>
const char* IndexEntryBuilderIterator::class_name_str = "IndexEntryBuilderIterator";
IndexEntryBuilderIterator::class_factory<IndexEntryBuilderIterator>
IndexEntryBuilderIterator::g_class_factory;

const serialization::ClassVersion 
IndexEntryBuilderIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IndexEntryBuilderIterator::class_versions_count =
sizeof(IndexEntryBuilderIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IndexEntryBuilderIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IndexEntryBuilderIterator::~IndexEntryBuilderIterator() {}

IndexEntryBuilderIteratorState::IndexEntryBuilderIteratorState() {}

IndexEntryBuilderIteratorState::~IndexEntryBuilderIteratorState() {}


void IndexEntryBuilderIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theCurChild = 0;
}

void IndexEntryBuilderIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theCurChild = 0;
}
// </IndexEntryBuilderIterator>


// <IndexPointProbeIterator>
const char* IndexPointProbeIterator::class_name_str = "IndexPointProbeIterator";
IndexPointProbeIterator::class_factory<IndexPointProbeIterator>
IndexPointProbeIterator::g_class_factory;

const serialization::ClassVersion 
IndexPointProbeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IndexPointProbeIterator::class_versions_count =
sizeof(IndexPointProbeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IndexPointProbeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IndexPointProbeIterator::~IndexPointProbeIterator() {}

IndexPointProbeIteratorState::IndexPointProbeIteratorState() {}

IndexPointProbeIteratorState::~IndexPointProbeIteratorState() {}


void IndexPointProbeIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theQname = 0;
  theIndex = 0;
  theIterator = NULL;
}
// </IndexPointProbeIterator>


// <IndexRangeProbeIterator>
const char* IndexRangeProbeIterator::class_name_str = "IndexRangeProbeIterator";
IndexRangeProbeIterator::class_factory<IndexRangeProbeIterator>
IndexRangeProbeIterator::g_class_factory;

const serialization::ClassVersion 
IndexRangeProbeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IndexRangeProbeIterator::class_versions_count =
sizeof(IndexRangeProbeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IndexRangeProbeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IndexRangeProbeIterator::~IndexRangeProbeIterator() {}

IndexRangeProbeIteratorState::IndexRangeProbeIteratorState() {}

IndexRangeProbeIteratorState::~IndexRangeProbeIteratorState() {}


void IndexRangeProbeIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theQname = 0;
  theIndex = 0;
  theIterator = NULL;
}
// </IndexRangeProbeIterator>



}
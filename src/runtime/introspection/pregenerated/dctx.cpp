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
#include "runtime/introspection/dctx.h"
#include "system/globalenv.h"


#include "store/api/iterator.h"

namespace zorba {

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



}



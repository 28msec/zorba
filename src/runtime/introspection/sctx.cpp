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
#include "runtime/introspection/sctx.h"
#include "system/globalenv.h"


#include "store/api/iterator.h"

namespace zorba {

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

IsDeclaredCollectionIteratorState::IsDeclaredCollectionIteratorState() {}

IsDeclaredCollectionIteratorState::~IsDeclaredCollectionIteratorState() {}


void IsDeclaredCollectionIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void IsDeclaredCollectionIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
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

IsDeclaredIndexIteratorState::IsDeclaredIndexIteratorState() {}

IsDeclaredIndexIteratorState::~IsDeclaredIndexIteratorState() {}


void IsDeclaredIndexIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void IsDeclaredIndexIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
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



}
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
#include "runtime/store/documents.h"
#include "system/globalenv.h"


#include "store/api/iterator.h"

namespace zorba {

// <PutDocumentIterator>
const char* PutDocumentIterator::class_name_str = "PutDocumentIterator";
PutDocumentIterator::class_factory<PutDocumentIterator>
PutDocumentIterator::g_class_factory;

const serialization::ClassVersion 
PutDocumentIterator::class_versions[] ={{ 1, 0x000905, false}};

const int PutDocumentIterator::class_versions_count =
sizeof(PutDocumentIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void PutDocumentIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

PutDocumentIterator::~PutDocumentIterator() {}

// </PutDocumentIterator>


// <RemoveDocumentIterator>
const char* RemoveDocumentIterator::class_name_str = "RemoveDocumentIterator";
RemoveDocumentIterator::class_factory<RemoveDocumentIterator>
RemoveDocumentIterator::g_class_factory;

const serialization::ClassVersion 
RemoveDocumentIterator::class_versions[] ={{ 1, 0x000905, false}};

const int RemoveDocumentIterator::class_versions_count =
sizeof(RemoveDocumentIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void RemoveDocumentIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

RemoveDocumentIterator::~RemoveDocumentIterator() {}

// </RemoveDocumentIterator>


// <RetrieveDocumentIterator>
const char* RetrieveDocumentIterator::class_name_str = "RetrieveDocumentIterator";
RetrieveDocumentIterator::class_factory<RetrieveDocumentIterator>
RetrieveDocumentIterator::g_class_factory;

const serialization::ClassVersion 
RetrieveDocumentIterator::class_versions[] ={{ 1, 0x000905, false}};

const int RetrieveDocumentIterator::class_versions_count =
sizeof(RetrieveDocumentIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void RetrieveDocumentIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

RetrieveDocumentIterator::~RetrieveDocumentIterator() {}

// </RetrieveDocumentIterator>


// <AvailableDocumentsIterator>
const char* AvailableDocumentsIterator::class_name_str = "AvailableDocumentsIterator";
AvailableDocumentsIterator::class_factory<AvailableDocumentsIterator>
AvailableDocumentsIterator::g_class_factory;

const serialization::ClassVersion 
AvailableDocumentsIterator::class_versions[] ={{ 1, 0x000905, false}};

const int AvailableDocumentsIterator::class_versions_count =
sizeof(AvailableDocumentsIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void AvailableDocumentsIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

AvailableDocumentsIterator::~AvailableDocumentsIterator() {}

AvailableDocumentsIteratorState::AvailableDocumentsIteratorState() {}

// </AvailableDocumentsIterator>


// <IsAvailableDocumentIterator>
const char* IsAvailableDocumentIterator::class_name_str = "IsAvailableDocumentIterator";
IsAvailableDocumentIterator::class_factory<IsAvailableDocumentIterator>
IsAvailableDocumentIterator::g_class_factory;

const serialization::ClassVersion 
IsAvailableDocumentIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsAvailableDocumentIterator::class_versions_count =
sizeof(IsAvailableDocumentIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsAvailableDocumentIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsAvailableDocumentIterator::~IsAvailableDocumentIterator() {}

// </IsAvailableDocumentIterator>



}



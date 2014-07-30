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
#include "runtime/store/documents.h"
#include "system/globalenv.h"


#include "store/api/iterator.h"

namespace zorba {

// <AvailableDocumentsIterator>
SERIALIZABLE_CLASS_VERSIONS(AvailableDocumentsIterator)

void AvailableDocumentsIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<AvailableDocumentsIterator, AvailableDocumentsIteratorState>*)this);
}


void AvailableDocumentsIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

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


zstring AvailableDocumentsIterator::getNameAsString() const {
  return "zorba-store-documents:available-documents";
}
// </AvailableDocumentsIterator>


// <IsAvailableDocumentIterator>
SERIALIZABLE_CLASS_VERSIONS(IsAvailableDocumentIterator)

void IsAvailableDocumentIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<IsAvailableDocumentIterator, PlanIteratorState>*)this);
}


void IsAvailableDocumentIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsAvailableDocumentIterator::~IsAvailableDocumentIterator() {}


zstring IsAvailableDocumentIterator::getNameAsString() const {
  return "zorba-store-documents:is-available-document";
}
// </IsAvailableDocumentIterator>


// <PutDocumentIterator>
SERIALIZABLE_CLASS_VERSIONS(PutDocumentIterator)

void PutDocumentIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<PutDocumentIterator, PlanIteratorState>*)this);
}


void PutDocumentIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

PutDocumentIterator::~PutDocumentIterator() {}


zstring PutDocumentIterator::getNameAsString() const {
  return "zorba-store-documents:put";
}
// </PutDocumentIterator>


// <RemoveDocumentIterator>
SERIALIZABLE_CLASS_VERSIONS(RemoveDocumentIterator)

void RemoveDocumentIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<RemoveDocumentIterator, PlanIteratorState>*)this);
}


void RemoveDocumentIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

RemoveDocumentIterator::~RemoveDocumentIterator() {}


zstring RemoveDocumentIterator::getNameAsString() const {
  return "zorba-store-documents:remove";
}
// </RemoveDocumentIterator>


// <RetrieveDocumentIterator>
SERIALIZABLE_CLASS_VERSIONS(RetrieveDocumentIterator)

void RetrieveDocumentIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<RetrieveDocumentIterator, PlanIteratorState>*)this);
}


void RetrieveDocumentIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

RetrieveDocumentIterator::~RetrieveDocumentIterator() {}


zstring RetrieveDocumentIterator::getNameAsString() const {
  return "zorba-store-documents:document";
}
// </RetrieveDocumentIterator>



}



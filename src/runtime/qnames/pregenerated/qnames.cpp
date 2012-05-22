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
#include "runtime/qnames/qnames.h"
#include "system/globalenv.h"



namespace zorba {

// <ResolveQNameIterator>
SERIALIZABLE_CLASS_VERSIONS(ResolveQNameIterator)void ResolveQNameIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (BinaryBaseIterator<ResolveQNameIterator, PlanIteratorState>*)this);
}


void ResolveQNameIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

ResolveQNameIterator::~ResolveQNameIterator() {}

// </ResolveQNameIterator>


// <QNameIterator>
SERIALIZABLE_CLASS_VERSIONS(QNameIterator)void QNameIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (BinaryBaseIterator<QNameIterator, PlanIteratorState>*)this);
}


void QNameIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

QNameIterator::~QNameIterator() {}

// </QNameIterator>


// <QNameEqualIterator>
SERIALIZABLE_CLASS_VERSIONS(QNameEqualIterator)void QNameEqualIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (BinaryBaseIterator<QNameEqualIterator, PlanIteratorState>*)this);
}


void QNameEqualIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

QNameEqualIterator::~QNameEqualIterator() {}

// </QNameEqualIterator>


// <PrefixFromQNameIterator>
SERIALIZABLE_CLASS_VERSIONS(PrefixFromQNameIterator)void PrefixFromQNameIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (UnaryBaseIterator<PrefixFromQNameIterator, PlanIteratorState>*)this);
}


void PrefixFromQNameIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

PrefixFromQNameIterator::~PrefixFromQNameIterator() {}

// </PrefixFromQNameIterator>


// <LocalNameFromQNameIterator>
SERIALIZABLE_CLASS_VERSIONS(LocalNameFromQNameIterator)void LocalNameFromQNameIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (UnaryBaseIterator<LocalNameFromQNameIterator, PlanIteratorState>*)this);
}


void LocalNameFromQNameIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

LocalNameFromQNameIterator::~LocalNameFromQNameIterator() {}

// </LocalNameFromQNameIterator>


// <NamespaceUriFromQNameIterator>
SERIALIZABLE_CLASS_VERSIONS(NamespaceUriFromQNameIterator)void NamespaceUriFromQNameIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (UnaryBaseIterator<NamespaceUriFromQNameIterator, PlanIteratorState>*)this);
}


void NamespaceUriFromQNameIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

NamespaceUriFromQNameIterator::~NamespaceUriFromQNameIterator() {}

// </NamespaceUriFromQNameIterator>


// <NamespaceUriForPrefixIterator>
SERIALIZABLE_CLASS_VERSIONS(NamespaceUriForPrefixIterator)void NamespaceUriForPrefixIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (NaryBaseIterator<NamespaceUriForPrefixIterator, PlanIteratorState>*)this);
}


void NamespaceUriForPrefixIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

NamespaceUriForPrefixIterator::~NamespaceUriForPrefixIterator() {}

// </NamespaceUriForPrefixIterator>


// <InScopePrefixesIterator>
SERIALIZABLE_CLASS_VERSIONS(InScopePrefixesIterator)void InScopePrefixesIterator::serialize( ::zorba::serialization::Archiver& ar)
{
    serialize_baseclass(ar,
    (UnaryBaseIterator<InScopePrefixesIterator, InScopePrefixesIteratorState>*)this);
}


void InScopePrefixesIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

InScopePrefixesIterator::~InScopePrefixesIterator() {}

InScopePrefixesIteratorState::InScopePrefixesIteratorState() {}

InScopePrefixesIteratorState::~InScopePrefixesIteratorState() {}

// </InScopePrefixesIterator>



}



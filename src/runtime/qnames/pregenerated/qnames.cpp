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
const char* ResolveQNameIterator::class_name_str = "ResolveQNameIterator";
ResolveQNameIterator::class_factory<ResolveQNameIterator>
ResolveQNameIterator::g_class_factory;

const serialization::ClassVersion 
ResolveQNameIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ResolveQNameIterator::class_versions_count =
sizeof(ResolveQNameIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ResolveQNameIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

ResolveQNameIterator::~ResolveQNameIterator() {}

// </ResolveQNameIterator>


// <QNameIterator>
const char* QNameIterator::class_name_str = "QNameIterator";
QNameIterator::class_factory<QNameIterator>
QNameIterator::g_class_factory;

const serialization::ClassVersion 
QNameIterator::class_versions[] ={{ 1, 0x000905, false}};

const int QNameIterator::class_versions_count =
sizeof(QNameIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void QNameIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

QNameIterator::~QNameIterator() {}

// </QNameIterator>


// <QNameEqualIterator>
const char* QNameEqualIterator::class_name_str = "QNameEqualIterator";
QNameEqualIterator::class_factory<QNameEqualIterator>
QNameEqualIterator::g_class_factory;

const serialization::ClassVersion 
QNameEqualIterator::class_versions[] ={{ 1, 0x000905, false}};

const int QNameEqualIterator::class_versions_count =
sizeof(QNameEqualIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void QNameEqualIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

QNameEqualIterator::~QNameEqualIterator() {}

// </QNameEqualIterator>


// <PrefixFromQNameIterator>
const char* PrefixFromQNameIterator::class_name_str = "PrefixFromQNameIterator";
PrefixFromQNameIterator::class_factory<PrefixFromQNameIterator>
PrefixFromQNameIterator::g_class_factory;

const serialization::ClassVersion 
PrefixFromQNameIterator::class_versions[] ={{ 1, 0x000905, false}};

const int PrefixFromQNameIterator::class_versions_count =
sizeof(PrefixFromQNameIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void PrefixFromQNameIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

PrefixFromQNameIterator::~PrefixFromQNameIterator() {}

// </PrefixFromQNameIterator>


// <LocalNameFromQNameIterator>
const char* LocalNameFromQNameIterator::class_name_str = "LocalNameFromQNameIterator";
LocalNameFromQNameIterator::class_factory<LocalNameFromQNameIterator>
LocalNameFromQNameIterator::g_class_factory;

const serialization::ClassVersion 
LocalNameFromQNameIterator::class_versions[] ={{ 1, 0x000905, false}};

const int LocalNameFromQNameIterator::class_versions_count =
sizeof(LocalNameFromQNameIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void LocalNameFromQNameIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

LocalNameFromQNameIterator::~LocalNameFromQNameIterator() {}

// </LocalNameFromQNameIterator>


// <NamespaceUriFromQNameIterator>
const char* NamespaceUriFromQNameIterator::class_name_str = "NamespaceUriFromQNameIterator";
NamespaceUriFromQNameIterator::class_factory<NamespaceUriFromQNameIterator>
NamespaceUriFromQNameIterator::g_class_factory;

const serialization::ClassVersion 
NamespaceUriFromQNameIterator::class_versions[] ={{ 1, 0x000905, false}};

const int NamespaceUriFromQNameIterator::class_versions_count =
sizeof(NamespaceUriFromQNameIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void NamespaceUriFromQNameIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

NamespaceUriFromQNameIterator::~NamespaceUriFromQNameIterator() {}

// </NamespaceUriFromQNameIterator>


// <NamespaceUriForPrefixIterator>
const char* NamespaceUriForPrefixIterator::class_name_str = "NamespaceUriForPrefixIterator";
NamespaceUriForPrefixIterator::class_factory<NamespaceUriForPrefixIterator>
NamespaceUriForPrefixIterator::g_class_factory;

const serialization::ClassVersion 
NamespaceUriForPrefixIterator::class_versions[] ={{ 1, 0x000905, false}};

const int NamespaceUriForPrefixIterator::class_versions_count =
sizeof(NamespaceUriForPrefixIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* InScopePrefixesIterator::class_name_str = "InScopePrefixesIterator";
InScopePrefixesIterator::class_factory<InScopePrefixesIterator>
InScopePrefixesIterator::g_class_factory;

const serialization::ClassVersion 
InScopePrefixesIterator::class_versions[] ={{ 1, 0x000905, false}};

const int InScopePrefixesIterator::class_versions_count =
sizeof(InScopePrefixesIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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



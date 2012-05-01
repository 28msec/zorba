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
ResolveQNameIterator::class_factory<ResolveQNameIterator>
ResolveQNameIterator::g_class_factory;


void ResolveQNameIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

ResolveQNameIterator::~ResolveQNameIterator() {}

// </ResolveQNameIterator>


// <QNameIterator>
QNameIterator::class_factory<QNameIterator>
QNameIterator::g_class_factory;


void QNameIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

QNameIterator::~QNameIterator() {}

// </QNameIterator>


// <QNameEqualIterator>
QNameEqualIterator::class_factory<QNameEqualIterator>
QNameEqualIterator::g_class_factory;


void QNameEqualIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

QNameEqualIterator::~QNameEqualIterator() {}

// </QNameEqualIterator>


// <PrefixFromQNameIterator>
PrefixFromQNameIterator::class_factory<PrefixFromQNameIterator>
PrefixFromQNameIterator::g_class_factory;


void PrefixFromQNameIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

PrefixFromQNameIterator::~PrefixFromQNameIterator() {}

// </PrefixFromQNameIterator>


// <LocalNameFromQNameIterator>
LocalNameFromQNameIterator::class_factory<LocalNameFromQNameIterator>
LocalNameFromQNameIterator::g_class_factory;


void LocalNameFromQNameIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

LocalNameFromQNameIterator::~LocalNameFromQNameIterator() {}

// </LocalNameFromQNameIterator>


// <NamespaceUriFromQNameIterator>
NamespaceUriFromQNameIterator::class_factory<NamespaceUriFromQNameIterator>
NamespaceUriFromQNameIterator::g_class_factory;


void NamespaceUriFromQNameIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

NamespaceUriFromQNameIterator::~NamespaceUriFromQNameIterator() {}

// </NamespaceUriFromQNameIterator>


// <NamespaceUriForPrefixIterator>
NamespaceUriForPrefixIterator::class_factory<NamespaceUriForPrefixIterator>
NamespaceUriForPrefixIterator::g_class_factory;


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
InScopePrefixesIterator::class_factory<InScopePrefixesIterator>
InScopePrefixesIterator::g_class_factory;


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



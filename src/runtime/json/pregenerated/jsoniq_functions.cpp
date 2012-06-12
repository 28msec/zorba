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
#include "runtime/json/jsoniq_functions.h"
#include "system/globalenv.h"



namespace zorba {

#ifdef ZORBA_WITH_JSON
// <JSONParseIterator>
JSONParseIterator::class_factory<JSONParseIterator>
JSONParseIterator::g_class_factory;


void JSONParseIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONParseIterator::~JSONParseIterator() {}

// </JSONParseIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONObjectNamesIterator>
JSONObjectNamesIterator::class_factory<JSONObjectNamesIterator>
JSONObjectNamesIterator::g_class_factory;


void JSONObjectNamesIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

JSONObjectNamesIterator::~JSONObjectNamesIterator() {}

JSONObjectNamesIteratorState::JSONObjectNamesIteratorState() {}

JSONObjectNamesIteratorState::~JSONObjectNamesIteratorState() {}


void JSONObjectNamesIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void JSONObjectNamesIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </JSONObjectNamesIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONObjectValueIterator>
JSONObjectValueIterator::class_factory<JSONObjectValueIterator>
JSONObjectValueIterator::g_class_factory;


void JSONObjectValueIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

JSONObjectValueIterator::~JSONObjectValueIterator() {}

// </JSONObjectValueIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONObjectProjectIterator>
JSONObjectProjectIterator::class_factory<JSONObjectProjectIterator>
JSONObjectProjectIterator::g_class_factory;


void JSONObjectProjectIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

JSONObjectProjectIterator::~JSONObjectProjectIterator() {}

// </JSONObjectProjectIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONArraySizeIterator>
JSONArraySizeIterator::class_factory<JSONArraySizeIterator>
JSONArraySizeIterator::g_class_factory;


void JSONArraySizeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

JSONArraySizeIterator::~JSONArraySizeIterator() {}

// </JSONArraySizeIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONArrayMemberIterator>
JSONArrayMemberIterator::class_factory<JSONArrayMemberIterator>
JSONArrayMemberIterator::g_class_factory;


void JSONArrayMemberIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

JSONArrayMemberIterator::~JSONArrayMemberIterator() {}

// </JSONArrayMemberIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONArrayMembersIterator>
JSONArrayMembersIterator::class_factory<JSONArrayMembersIterator>
JSONArrayMembersIterator::g_class_factory;


void JSONArrayMembersIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

JSONArrayMembersIterator::~JSONArrayMembersIterator() {}

JSONArrayMembersIteratorState::JSONArrayMembersIteratorState() {}

JSONArrayMembersIteratorState::~JSONArrayMembersIteratorState() {}


void JSONArrayMembersIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void JSONArrayMembersIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </JSONArrayMembersIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONArrayFlattenIterator>
JSONArrayFlattenIterator::class_factory<JSONArrayFlattenIterator>
JSONArrayFlattenIterator::g_class_factory;


void JSONArrayFlattenIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

JSONArrayFlattenIterator::~JSONArrayFlattenIterator() {}

JSONArrayFlattenIteratorState::JSONArrayFlattenIteratorState() {}

JSONArrayFlattenIteratorState::~JSONArrayFlattenIteratorState() {}


void JSONArrayFlattenIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}
// </JSONArrayFlattenIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONItemAccessorIterator>
JSONItemAccessorIterator::class_factory<JSONItemAccessorIterator>
JSONItemAccessorIterator::g_class_factory;


void JSONItemAccessorIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

JSONItemAccessorIterator::~JSONItemAccessorIterator() {}

// </JSONItemAccessorIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONNullIterator>
JSONNullIterator::class_factory<JSONNullIterator>
JSONNullIterator::g_class_factory;


void JSONNullIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  

  v.endVisit(*this);
}

JSONNullIterator::~JSONNullIterator() {}

// </JSONNullIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONArrayInsertIterator>
JSONArrayInsertIterator::class_factory<JSONArrayInsertIterator>
JSONArrayInsertIterator::g_class_factory;


void JSONArrayInsertIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONArrayInsertIterator::~JSONArrayInsertIterator() {}

// </JSONArrayInsertIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONDeleteIterator>
JSONDeleteIterator::class_factory<JSONDeleteIterator>
JSONDeleteIterator::g_class_factory;


void JSONDeleteIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONDeleteIterator::~JSONDeleteIterator() {}

// </JSONDeleteIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONReplaceValueIterator>
JSONReplaceValueIterator::class_factory<JSONReplaceValueIterator>
JSONReplaceValueIterator::g_class_factory;


void JSONReplaceValueIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONReplaceValueIterator::~JSONReplaceValueIterator() {}

// </JSONReplaceValueIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONRenameIterator>
JSONRenameIterator::class_factory<JSONRenameIterator>
JSONRenameIterator::g_class_factory;


void JSONRenameIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONRenameIterator::~JSONRenameIterator() {}

// </JSONRenameIterator>

#endif

}



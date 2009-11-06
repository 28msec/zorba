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
#include "runtime/convertors/convertors.h"
#include "system/globalenv.h"


#include "store/api/item.h"
#include "store/api/item_factory.h"

namespace zorba {

// <ZorbaJsonParseIterator>
const char* ZorbaJsonParseIterator::class_name_str = "ZorbaJsonParseIterator";
ZorbaJsonParseIterator::class_factory<ZorbaJsonParseIterator>
ZorbaJsonParseIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaJsonParseIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaJsonParseIterator::class_versions_count =
sizeof(ZorbaJsonParseIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ZorbaJsonParseIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}
ZorbaJsonParseIterator::~ZorbaJsonParseIterator() {}


void ZorbaJsonParseIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theBaseUri = xqp_string();
}

void ZorbaJsonParseIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theBaseUri = xqp_string();
}
// </ZorbaJsonParseIterator>


// <ZorbaJsonSerializeIterator>
const char* ZorbaJsonSerializeIterator::class_name_str = "ZorbaJsonSerializeIterator";
ZorbaJsonSerializeIterator::class_factory<ZorbaJsonSerializeIterator>
ZorbaJsonSerializeIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaJsonSerializeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaJsonSerializeIterator::class_versions_count =
sizeof(ZorbaJsonSerializeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ZorbaJsonSerializeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}
ZorbaJsonSerializeIterator::~ZorbaJsonSerializeIterator() {}

// </ZorbaJsonSerializeIterator>


// <ZorbaJsonMLParseIterator>
const char* ZorbaJsonMLParseIterator::class_name_str = "ZorbaJsonMLParseIterator";
ZorbaJsonMLParseIterator::class_factory<ZorbaJsonMLParseIterator>
ZorbaJsonMLParseIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaJsonMLParseIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaJsonMLParseIterator::class_versions_count =
sizeof(ZorbaJsonMLParseIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ZorbaJsonMLParseIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}
ZorbaJsonMLParseIterator::~ZorbaJsonMLParseIterator() {}


void ZorbaJsonMLParseIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theBaseUri = xqp_string();
}

void ZorbaJsonMLParseIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theBaseUri = xqp_string();
}
// </ZorbaJsonMLParseIterator>


// <ZorbaJsonMLSerializeIterator>
const char* ZorbaJsonMLSerializeIterator::class_name_str = "ZorbaJsonMLSerializeIterator";
ZorbaJsonMLSerializeIterator::class_factory<ZorbaJsonMLSerializeIterator>
ZorbaJsonMLSerializeIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaJsonMLSerializeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaJsonMLSerializeIterator::class_versions_count =
sizeof(ZorbaJsonMLSerializeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ZorbaJsonMLSerializeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}
ZorbaJsonMLSerializeIterator::~ZorbaJsonMLSerializeIterator() {}

// </ZorbaJsonMLSerializeIterator>



}
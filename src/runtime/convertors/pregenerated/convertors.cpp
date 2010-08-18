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

ZorbaJsonParseIteratorState::ZorbaJsonParseIteratorState() {}

ZorbaJsonParseIteratorState::~ZorbaJsonParseIteratorState() {}


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


// <ZorbaJsonParseMLIterator>
const char* ZorbaJsonParseMLIterator::class_name_str = "ZorbaJsonParseMLIterator";
ZorbaJsonParseMLIterator::class_factory<ZorbaJsonParseMLIterator>
ZorbaJsonParseMLIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaJsonParseMLIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaJsonParseMLIterator::class_versions_count =
sizeof(ZorbaJsonParseMLIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ZorbaJsonParseMLIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaJsonParseMLIterator::~ZorbaJsonParseMLIterator() {}

ZorbaJsonParseMLIteratorState::ZorbaJsonParseMLIteratorState() {}

ZorbaJsonParseMLIteratorState::~ZorbaJsonParseMLIteratorState() {}


void ZorbaJsonParseMLIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theBaseUri = xqp_string();
}

void ZorbaJsonParseMLIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theBaseUri = xqp_string();
}
// </ZorbaJsonParseMLIterator>


// <ZorbaJsonSerializeMLIterator>
const char* ZorbaJsonSerializeMLIterator::class_name_str = "ZorbaJsonSerializeMLIterator";
ZorbaJsonSerializeMLIterator::class_factory<ZorbaJsonSerializeMLIterator>
ZorbaJsonSerializeMLIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaJsonSerializeMLIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaJsonSerializeMLIterator::class_versions_count =
sizeof(ZorbaJsonSerializeMLIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ZorbaJsonSerializeMLIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaJsonSerializeMLIterator::~ZorbaJsonSerializeMLIterator() {}

// </ZorbaJsonSerializeMLIterator>


// <ZorbaCSV2XMLIterator>
const char* ZorbaCSV2XMLIterator::class_name_str = "ZorbaCSV2XMLIterator";
ZorbaCSV2XMLIterator::class_factory<ZorbaCSV2XMLIterator>
ZorbaCSV2XMLIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaCSV2XMLIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaCSV2XMLIterator::class_versions_count =
sizeof(ZorbaCSV2XMLIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ZorbaCSV2XMLIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaCSV2XMLIterator::~ZorbaCSV2XMLIterator() {}

ZorbaCSV2XMLIteratorState::ZorbaCSV2XMLIteratorState() {}

ZorbaCSV2XMLIteratorState::~ZorbaCSV2XMLIteratorState() {}


void ZorbaCSV2XMLIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  first_row_is_header = false;
}

void ZorbaCSV2XMLIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  first_row_is_header = false;
}
// </ZorbaCSV2XMLIterator>


// <ZorbaTXT2XMLIterator>
const char* ZorbaTXT2XMLIterator::class_name_str = "ZorbaTXT2XMLIterator";
ZorbaTXT2XMLIterator::class_factory<ZorbaTXT2XMLIterator>
ZorbaTXT2XMLIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaTXT2XMLIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaTXT2XMLIterator::class_versions_count =
sizeof(ZorbaTXT2XMLIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ZorbaTXT2XMLIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaTXT2XMLIterator::~ZorbaTXT2XMLIterator() {}

ZorbaTXT2XMLIteratorState::ZorbaTXT2XMLIteratorState() {}

ZorbaTXT2XMLIteratorState::~ZorbaTXT2XMLIteratorState() {}


void ZorbaTXT2XMLIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  first_row_is_header = false;
}

void ZorbaTXT2XMLIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  first_row_is_header = false;
}
// </ZorbaTXT2XMLIterator>


// <ZorbaCSV2XMLFromFileIterator>
const char* ZorbaCSV2XMLFromFileIterator::class_name_str = "ZorbaCSV2XMLFromFileIterator";
ZorbaCSV2XMLFromFileIterator::class_factory<ZorbaCSV2XMLFromFileIterator>
ZorbaCSV2XMLFromFileIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaCSV2XMLFromFileIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaCSV2XMLFromFileIterator::class_versions_count =
sizeof(ZorbaCSV2XMLFromFileIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ZorbaCSV2XMLFromFileIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaCSV2XMLFromFileIterator::~ZorbaCSV2XMLFromFileIterator() {}

ZorbaCSV2XMLFromFileIteratorState::ZorbaCSV2XMLFromFileIteratorState() {}

ZorbaCSV2XMLFromFileIteratorState::~ZorbaCSV2XMLFromFileIteratorState() {}


void ZorbaCSV2XMLFromFileIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  first_row_is_header = false;
}

void ZorbaCSV2XMLFromFileIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  first_row_is_header = false;
}
// </ZorbaCSV2XMLFromFileIterator>


// <ZorbaTXT2XMLFromFileIterator>
const char* ZorbaTXT2XMLFromFileIterator::class_name_str = "ZorbaTXT2XMLFromFileIterator";
ZorbaTXT2XMLFromFileIterator::class_factory<ZorbaTXT2XMLFromFileIterator>
ZorbaTXT2XMLFromFileIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaTXT2XMLFromFileIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaTXT2XMLFromFileIterator::class_versions_count =
sizeof(ZorbaTXT2XMLFromFileIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ZorbaTXT2XMLFromFileIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaTXT2XMLFromFileIterator::~ZorbaTXT2XMLFromFileIterator() {}

ZorbaTXT2XMLFromFileIteratorState::ZorbaTXT2XMLFromFileIteratorState() {}

ZorbaTXT2XMLFromFileIteratorState::~ZorbaTXT2XMLFromFileIteratorState() {}


void ZorbaTXT2XMLFromFileIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  first_row_is_header = false;
}

void ZorbaTXT2XMLFromFileIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  first_row_is_header = false;
}
// </ZorbaTXT2XMLFromFileIterator>


// <ZorbaXML2CSVIterator>
const char* ZorbaXML2CSVIterator::class_name_str = "ZorbaXML2CSVIterator";
ZorbaXML2CSVIterator::class_factory<ZorbaXML2CSVIterator>
ZorbaXML2CSVIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaXML2CSVIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaXML2CSVIterator::class_versions_count =
sizeof(ZorbaXML2CSVIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ZorbaXML2CSVIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaXML2CSVIterator::~ZorbaXML2CSVIterator() {}

ZorbaXML2CSVIteratorState::ZorbaXML2CSVIteratorState() {}

ZorbaXML2CSVIteratorState::~ZorbaXML2CSVIteratorState() {}


void ZorbaXML2CSVIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void ZorbaXML2CSVIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </ZorbaXML2CSVIterator>


// <ZorbaXML2CSVFILEIterator>
const char* ZorbaXML2CSVFILEIterator::class_name_str = "ZorbaXML2CSVFILEIterator";
ZorbaXML2CSVFILEIterator::class_factory<ZorbaXML2CSVFILEIterator>
ZorbaXML2CSVFILEIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaXML2CSVFILEIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaXML2CSVFILEIterator::class_versions_count =
sizeof(ZorbaXML2CSVFILEIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ZorbaXML2CSVFILEIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaXML2CSVFILEIterator::~ZorbaXML2CSVFILEIterator() {}

ZorbaXML2CSVFILEIteratorState::ZorbaXML2CSVFILEIteratorState() {}

ZorbaXML2CSVFILEIteratorState::~ZorbaXML2CSVFILEIteratorState() {}


void ZorbaXML2CSVFILEIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void ZorbaXML2CSVFILEIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </ZorbaXML2CSVFILEIterator>


// <ZorbaXML2TXTIterator>
const char* ZorbaXML2TXTIterator::class_name_str = "ZorbaXML2TXTIterator";
ZorbaXML2TXTIterator::class_factory<ZorbaXML2TXTIterator>
ZorbaXML2TXTIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaXML2TXTIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaXML2TXTIterator::class_versions_count =
sizeof(ZorbaXML2TXTIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ZorbaXML2TXTIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaXML2TXTIterator::~ZorbaXML2TXTIterator() {}

ZorbaXML2TXTIteratorState::ZorbaXML2TXTIteratorState() {}

ZorbaXML2TXTIteratorState::~ZorbaXML2TXTIteratorState() {}


void ZorbaXML2TXTIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void ZorbaXML2TXTIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </ZorbaXML2TXTIterator>


// <ZorbaXML2TXTFILEIterator>
const char* ZorbaXML2TXTFILEIterator::class_name_str = "ZorbaXML2TXTFILEIterator";
ZorbaXML2TXTFILEIterator::class_factory<ZorbaXML2TXTFILEIterator>
ZorbaXML2TXTFILEIterator::g_class_factory;

const serialization::ClassVersion 
ZorbaXML2TXTFILEIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ZorbaXML2TXTFILEIterator::class_versions_count =
sizeof(ZorbaXML2TXTFILEIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ZorbaXML2TXTFILEIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ZorbaXML2TXTFILEIterator::~ZorbaXML2TXTFILEIterator() {}

ZorbaXML2TXTFILEIteratorState::ZorbaXML2TXTFILEIteratorState() {}

ZorbaXML2TXTFILEIteratorState::~ZorbaXML2TXTFILEIteratorState() {}


void ZorbaXML2TXTFILEIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void ZorbaXML2TXTFILEIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </ZorbaXML2TXTFILEIterator>



}



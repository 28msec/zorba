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
#include "runtime/full_text/ft_module.h"
#include "system/globalenv.h"


#include "store/api/iterator.h"

namespace zorba {

// <HostLangIterator>
const char* HostLangIterator::class_name_str = "HostLangIterator";
HostLangIterator::class_factory<HostLangIterator>
HostLangIterator::g_class_factory;

const serialization::ClassVersion 
HostLangIterator::class_versions[] ={{ 1, 0x000905, false}};

const int HostLangIterator::class_versions_count =
sizeof(HostLangIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void HostLangIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

HostLangIterator::~HostLangIterator() {}

// </HostLangIterator>


// <IsStopWordIterator>
const char* IsStopWordIterator::class_name_str = "IsStopWordIterator";
IsStopWordIterator::class_factory<IsStopWordIterator>
IsStopWordIterator::g_class_factory;

const serialization::ClassVersion 
IsStopWordIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsStopWordIterator::class_versions_count =
sizeof(IsStopWordIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsStopWordIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsStopWordIterator::~IsStopWordIterator() {}

// </IsStopWordIterator>


// <StemIterator>
const char* StemIterator::class_name_str = "StemIterator";
StemIterator::class_factory<StemIterator>
StemIterator::g_class_factory;

const serialization::ClassVersion 
StemIterator::class_versions[] ={{ 1, 0x000905, false}};

const int StemIterator::class_versions_count =
sizeof(StemIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void StemIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

StemIterator::~StemIterator() {}

// </StemIterator>


// <StripDiacriticsIterator>
const char* StripDiacriticsIterator::class_name_str = "StripDiacriticsIterator";
StripDiacriticsIterator::class_factory<StripDiacriticsIterator>
StripDiacriticsIterator::g_class_factory;

const serialization::ClassVersion 
StripDiacriticsIterator::class_versions[] ={{ 1, 0x000905, false}};

const int StripDiacriticsIterator::class_versions_count =
sizeof(StripDiacriticsIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void StripDiacriticsIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

StripDiacriticsIterator::~StripDiacriticsIterator() {}

// </StripDiacriticsIterator>


// <ThesaurusLookupIterator>
const char* ThesaurusLookupIterator::class_name_str = "ThesaurusLookupIterator";
ThesaurusLookupIterator::class_factory<ThesaurusLookupIterator>
ThesaurusLookupIterator::g_class_factory;

const serialization::ClassVersion 
ThesaurusLookupIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ThesaurusLookupIterator::class_versions_count =
sizeof(ThesaurusLookupIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ThesaurusLookupIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ThesaurusLookupIterator::~ThesaurusLookupIterator() {}

ThesaurusLookupIteratorState::ThesaurusLookupIteratorState() {}

ThesaurusLookupIteratorState::~ThesaurusLookupIteratorState() {}


void ThesaurusLookupIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </ThesaurusLookupIterator>


// <TokenizeIterator>
const char* TokenizeIterator::class_name_str = "TokenizeIterator";
TokenizeIterator::class_factory<TokenizeIterator>
TokenizeIterator::g_class_factory;

const serialization::ClassVersion 
TokenizeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int TokenizeIterator::class_versions_count =
sizeof(TokenizeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void TokenizeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

TokenizeIterator::~TokenizeIterator() {}

TokenizeIteratorState::TokenizeIteratorState() {}

TokenizeIteratorState::~TokenizeIteratorState() {}


void TokenizeIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </TokenizeIterator>



}



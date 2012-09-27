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
#include "runtime/full_text/ft_module.h"
#include "system/globalenv.h"


#include "store/api/iterator.h"

namespace zorba {

#ifndef ZORBA_NO_FULL_TEXT
// <CurrentCompareOptionsIterator>
SERIALIZABLE_CLASS_VERSIONS(CurrentCompareOptionsIterator)

void CurrentCompareOptionsIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<CurrentCompareOptionsIterator, PlanIteratorState>*)this);
}


void CurrentCompareOptionsIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

CurrentCompareOptionsIterator::~CurrentCompareOptionsIterator() {}

// </CurrentCompareOptionsIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <CurrentLangIterator>
SERIALIZABLE_CLASS_VERSIONS(CurrentLangIterator)

void CurrentLangIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<CurrentLangIterator, PlanIteratorState>*)this);
}


void CurrentLangIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

CurrentLangIterator::~CurrentLangIterator() {}

// </CurrentLangIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <HostLangIterator>
SERIALIZABLE_CLASS_VERSIONS(HostLangIterator)

void HostLangIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<HostLangIterator, PlanIteratorState>*)this);
}


void HostLangIterator::accept(PlanIterVisitor& v) const
{
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

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <IsStemLangSupportedIterator>
SERIALIZABLE_CLASS_VERSIONS(IsStemLangSupportedIterator)

void IsStemLangSupportedIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<IsStemLangSupportedIterator, PlanIteratorState>*)this);
}


void IsStemLangSupportedIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsStemLangSupportedIterator::~IsStemLangSupportedIterator() {}

// </IsStemLangSupportedIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <IsStopWordIterator>
SERIALIZABLE_CLASS_VERSIONS(IsStopWordIterator)

void IsStopWordIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<IsStopWordIterator, PlanIteratorState>*)this);
}


void IsStopWordIterator::accept(PlanIterVisitor& v) const
{
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

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <IsStopWordLangSupportedIterator>
SERIALIZABLE_CLASS_VERSIONS(IsStopWordLangSupportedIterator)

void IsStopWordLangSupportedIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<IsStopWordLangSupportedIterator, PlanIteratorState>*)this);
}


void IsStopWordLangSupportedIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsStopWordLangSupportedIterator::~IsStopWordLangSupportedIterator() {}

// </IsStopWordLangSupportedIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <IsThesaurusLangSupportedIterator>
SERIALIZABLE_CLASS_VERSIONS(IsThesaurusLangSupportedIterator)

void IsThesaurusLangSupportedIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<IsThesaurusLangSupportedIterator, PlanIteratorState>*)this);
}


void IsThesaurusLangSupportedIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsThesaurusLangSupportedIterator::~IsThesaurusLangSupportedIterator() {}

// </IsThesaurusLangSupportedIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <IsTokenizerLangSupportedIterator>
SERIALIZABLE_CLASS_VERSIONS(IsTokenizerLangSupportedIterator)

void IsTokenizerLangSupportedIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<IsTokenizerLangSupportedIterator, PlanIteratorState>*)this);
}


void IsTokenizerLangSupportedIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsTokenizerLangSupportedIterator::~IsTokenizerLangSupportedIterator() {}

// </IsTokenizerLangSupportedIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <StemIterator>
SERIALIZABLE_CLASS_VERSIONS(StemIterator)

void StemIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<StemIterator, PlanIteratorState>*)this);
}


void StemIterator::accept(PlanIterVisitor& v) const
{
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

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <StripDiacriticsIterator>
SERIALIZABLE_CLASS_VERSIONS(StripDiacriticsIterator)

void StripDiacriticsIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<StripDiacriticsIterator, PlanIteratorState>*)this);
}


void StripDiacriticsIterator::accept(PlanIterVisitor& v) const
{
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

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <ThesaurusLookupIterator>
SERIALIZABLE_CLASS_VERSIONS(ThesaurusLookupIterator)

void ThesaurusLookupIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ThesaurusLookupIterator, ThesaurusLookupIteratorState>*)this);
}


void ThesaurusLookupIterator::accept(PlanIterVisitor& v) const
{
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

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <TokenizeNodeIterator>
SERIALIZABLE_CLASS_VERSIONS(TokenizeNodeIterator)

void TokenizeNodeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<TokenizeNodeIterator, TokenizeNodeIteratorState>*)this);
}


void TokenizeNodeIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

TokenizeNodeIterator::~TokenizeNodeIterator() {}

TokenizeNodeIteratorState::TokenizeNodeIteratorState() {}

TokenizeNodeIteratorState::~TokenizeNodeIteratorState() {}


void TokenizeNodeIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </TokenizeNodeIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <TokenizeNodesIterator>
SERIALIZABLE_CLASS_VERSIONS(TokenizeNodesIterator)

void TokenizeNodesIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<TokenizeNodesIterator, TokenizeNodesIteratorState>*)this);
}


void TokenizeNodesIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

TokenizeNodesIterator::~TokenizeNodesIterator() {}

TokenizeNodesIteratorState::TokenizeNodesIteratorState() {}

TokenizeNodesIteratorState::~TokenizeNodesIteratorState() {}


void TokenizeNodesIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </TokenizeNodesIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <TokenizerPropertiesIterator>
SERIALIZABLE_CLASS_VERSIONS(TokenizerPropertiesIterator)

void TokenizerPropertiesIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<TokenizerPropertiesIterator, PlanIteratorState>*)this);
}


void TokenizerPropertiesIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

TokenizerPropertiesIterator::~TokenizerPropertiesIterator() {}

// </TokenizerPropertiesIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <TokenizeStringIterator>
SERIALIZABLE_CLASS_VERSIONS(TokenizeStringIterator)

void TokenizeStringIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<TokenizeStringIterator, TokenizeStringIteratorState>*)this);
}


void TokenizeStringIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

TokenizeStringIterator::~TokenizeStringIterator() {}

TokenizeStringIteratorState::TokenizeStringIteratorState() {}

TokenizeStringIteratorState::~TokenizeStringIteratorState() {}


void TokenizeStringIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </TokenizeStringIterator>

#endif

}



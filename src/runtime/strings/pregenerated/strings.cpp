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
#include "runtime/strings/strings.h"
#include "system/globalenv.h"



namespace zorba {

// <CodepointsToStringIterator>
SERIALIZABLE_CLASS_VERSIONS(CodepointsToStringIterator)

void CodepointsToStringIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<CodepointsToStringIterator, PlanIteratorState>*)this);
}


void CodepointsToStringIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

CodepointsToStringIterator::~CodepointsToStringIterator() {}


zstring CodepointsToStringIterator::getNameAsString() const {
  return "fn:codepoints-to-string";
}
// </CodepointsToStringIterator>


// <StringToCodepointsIterator>
SERIALIZABLE_CLASS_VERSIONS(StringToCodepointsIterator)

void StringToCodepointsIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<StringToCodepointsIterator, StringToCodepointsIteratorState>*)this);
}


void StringToCodepointsIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

StringToCodepointsIterator::~StringToCodepointsIterator() {}

StringToCodepointsIteratorState::StringToCodepointsIteratorState() {}

StringToCodepointsIteratorState::~StringToCodepointsIteratorState() {}


zstring StringToCodepointsIterator::getNameAsString() const {
  return "fn:string-to-codepoints";
}
// </StringToCodepointsIterator>


// <CompareStrIterator>
SERIALIZABLE_CLASS_VERSIONS(CompareStrIterator)

void CompareStrIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<CompareStrIterator, PlanIteratorState>*)this);
}


void CompareStrIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

CompareStrIterator::~CompareStrIterator() {}


zstring CompareStrIterator::getNameAsString() const {
  return "fn:compare";
}
// </CompareStrIterator>


// <CodepointEqualIterator>
SERIALIZABLE_CLASS_VERSIONS(CodepointEqualIterator)

void CodepointEqualIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<CodepointEqualIterator, PlanIteratorState>*)this);
}


void CodepointEqualIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

CodepointEqualIterator::~CodepointEqualIterator() {}


zstring CodepointEqualIterator::getNameAsString() const {
  return "fn:codepoint-equal";
}
// </CodepointEqualIterator>


// <ConcatStrIterator>
SERIALIZABLE_CLASS_VERSIONS(ConcatStrIterator)

void ConcatStrIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ConcatStrIterator, PlanIteratorState>*)this);
}


void ConcatStrIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ConcatStrIterator::~ConcatStrIterator() {}


zstring ConcatStrIterator::getNameAsString() const {
  return "fn:concat";
}
// </ConcatStrIterator>


// <StringJoinIterator>
SERIALIZABLE_CLASS_VERSIONS(StringJoinIterator)

void StringJoinIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<StringJoinIterator, PlanIteratorState>*)this);
}


void StringJoinIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

StringJoinIterator::~StringJoinIterator() {}


zstring StringJoinIterator::getNameAsString() const {
  return "fn:string-join";
}
// </StringJoinIterator>


// <SubstringIterator>
SERIALIZABLE_CLASS_VERSIONS(SubstringIterator)

void SubstringIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<SubstringIterator, PlanIteratorState>*)this);
}


void SubstringIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

SubstringIterator::~SubstringIterator() {}


zstring SubstringIterator::getNameAsString() const {
  return "fn:substring";
}
// </SubstringIterator>


// <SubstringIntOptIterator>
SERIALIZABLE_CLASS_VERSIONS(SubstringIntOptIterator)

void SubstringIntOptIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<SubstringIntOptIterator, PlanIteratorState>*)this);
}


void SubstringIntOptIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

SubstringIntOptIterator::~SubstringIntOptIterator() {}


zstring SubstringIntOptIterator::getNameAsString() const {
  return "op:substring_int";
}
// </SubstringIntOptIterator>


// <StringLengthIterator>
SERIALIZABLE_CLASS_VERSIONS(StringLengthIterator)

void StringLengthIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<StringLengthIterator, PlanIteratorState>*)this);
}


void StringLengthIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

StringLengthIterator::~StringLengthIterator() {}


zstring StringLengthIterator::getNameAsString() const {
  return "fn:string-length";
}
// </StringLengthIterator>


// <NormalizeSpaceIterator>
SERIALIZABLE_CLASS_VERSIONS(NormalizeSpaceIterator)

void NormalizeSpaceIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<NormalizeSpaceIterator, PlanIteratorState>*)this);
}


void NormalizeSpaceIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

NormalizeSpaceIterator::~NormalizeSpaceIterator() {}


zstring NormalizeSpaceIterator::getNameAsString() const {
  return "fn:normalize-space";
}
// </NormalizeSpaceIterator>


// <NormalizeUnicodeIterator>
SERIALIZABLE_CLASS_VERSIONS(NormalizeUnicodeIterator)

void NormalizeUnicodeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<NormalizeUnicodeIterator, PlanIteratorState>*)this);
}


void NormalizeUnicodeIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

NormalizeUnicodeIterator::~NormalizeUnicodeIterator() {}


zstring NormalizeUnicodeIterator::getNameAsString() const {
  return "fn:normalize-unicode";
}
// </NormalizeUnicodeIterator>


// <UpperCaseIterator>
SERIALIZABLE_CLASS_VERSIONS(UpperCaseIterator)

void UpperCaseIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<UpperCaseIterator, PlanIteratorState>*)this);
}


void UpperCaseIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

UpperCaseIterator::~UpperCaseIterator() {}


zstring UpperCaseIterator::getNameAsString() const {
  return "fn:upper-case";
}
// </UpperCaseIterator>


// <LowerCaseIterator>
SERIALIZABLE_CLASS_VERSIONS(LowerCaseIterator)

void LowerCaseIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<LowerCaseIterator, PlanIteratorState>*)this);
}


void LowerCaseIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

LowerCaseIterator::~LowerCaseIterator() {}


zstring LowerCaseIterator::getNameAsString() const {
  return "fn:lower-case";
}
// </LowerCaseIterator>


// <TranslateIterator>
SERIALIZABLE_CLASS_VERSIONS(TranslateIterator)

void TranslateIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<TranslateIterator, PlanIteratorState>*)this);
}


void TranslateIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

TranslateIterator::~TranslateIterator() {}


zstring TranslateIterator::getNameAsString() const {
  return "fn:translate";
}
// </TranslateIterator>


// <EncodeForUriIterator>
SERIALIZABLE_CLASS_VERSIONS(EncodeForUriIterator)

void EncodeForUriIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<EncodeForUriIterator, PlanIteratorState>*)this);
}


void EncodeForUriIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

EncodeForUriIterator::~EncodeForUriIterator() {}


zstring EncodeForUriIterator::getNameAsString() const {
  return "fn:encode-for-uri";
}
// </EncodeForUriIterator>


// <IriToUriIterator>
SERIALIZABLE_CLASS_VERSIONS(IriToUriIterator)

void IriToUriIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<IriToUriIterator, PlanIteratorState>*)this);
}


void IriToUriIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IriToUriIterator::~IriToUriIterator() {}


zstring IriToUriIterator::getNameAsString() const {
  return "fn:iri-to-uri";
}
// </IriToUriIterator>


// <EscapeHtmlUriIterator>
SERIALIZABLE_CLASS_VERSIONS(EscapeHtmlUriIterator)

void EscapeHtmlUriIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<EscapeHtmlUriIterator, PlanIteratorState>*)this);
}


void EscapeHtmlUriIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

EscapeHtmlUriIterator::~EscapeHtmlUriIterator() {}


zstring EscapeHtmlUriIterator::getNameAsString() const {
  return "fn:escape-html-uri";
}
// </EscapeHtmlUriIterator>


// <ContainsIterator>
SERIALIZABLE_CLASS_VERSIONS(ContainsIterator)

void ContainsIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ContainsIterator, PlanIteratorState>*)this);
}


void ContainsIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ContainsIterator::~ContainsIterator() {}


zstring ContainsIterator::getNameAsString() const {
  return "fn:contains";
}
// </ContainsIterator>


// <StartsWithIterator>
SERIALIZABLE_CLASS_VERSIONS(StartsWithIterator)

void StartsWithIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<StartsWithIterator, PlanIteratorState>*)this);
}


void StartsWithIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

StartsWithIterator::~StartsWithIterator() {}


zstring StartsWithIterator::getNameAsString() const {
  return "fn:starts-with";
}
// </StartsWithIterator>


// <EndsWithIterator>
SERIALIZABLE_CLASS_VERSIONS(EndsWithIterator)

void EndsWithIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<EndsWithIterator, PlanIteratorState>*)this);
}


void EndsWithIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

EndsWithIterator::~EndsWithIterator() {}


zstring EndsWithIterator::getNameAsString() const {
  return "fn:ends-with";
}
// </EndsWithIterator>


// <SubstringBeforeIterator>
SERIALIZABLE_CLASS_VERSIONS(SubstringBeforeIterator)

void SubstringBeforeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<SubstringBeforeIterator, PlanIteratorState>*)this);
}


void SubstringBeforeIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

SubstringBeforeIterator::~SubstringBeforeIterator() {}


zstring SubstringBeforeIterator::getNameAsString() const {
  return "fn:substring-before";
}
// </SubstringBeforeIterator>


// <SubstringAfterIterator>
SERIALIZABLE_CLASS_VERSIONS(SubstringAfterIterator)

void SubstringAfterIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<SubstringAfterIterator, PlanIteratorState>*)this);
}


void SubstringAfterIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

SubstringAfterIterator::~SubstringAfterIterator() {}


zstring SubstringAfterIterator::getNameAsString() const {
  return "fn:substring-after";
}
// </SubstringAfterIterator>


// <FnMatchesIterator>
SERIALIZABLE_CLASS_VERSIONS(FnMatchesIterator)

void FnMatchesIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnMatchesIterator, PlanIteratorState>*)this);
}


void FnMatchesIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnMatchesIterator::~FnMatchesIterator() {}


zstring FnMatchesIterator::getNameAsString() const {
  return "fn:matches";
}
// </FnMatchesIterator>


// <FnReplaceIterator>
SERIALIZABLE_CLASS_VERSIONS(FnReplaceIterator)

void FnReplaceIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnReplaceIterator, PlanIteratorState>*)this);
}


void FnReplaceIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnReplaceIterator::~FnReplaceIterator() {}


zstring FnReplaceIterator::getNameAsString() const {
  return "fn:replace";
}
// </FnReplaceIterator>


// <FnTokenizeIterator>
SERIALIZABLE_CLASS_VERSIONS(FnTokenizeIterator)

void FnTokenizeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnTokenizeIterator, FnTokenizeIteratorState>*)this);
}


void FnTokenizeIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnTokenizeIterator::~FnTokenizeIterator() {}

FnTokenizeIteratorState::FnTokenizeIteratorState() {}

FnTokenizeIteratorState::~FnTokenizeIteratorState() {}


void FnTokenizeIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  start_pos = 0;
  hasmatched = false;
}

zstring FnTokenizeIterator::getNameAsString() const {
  return "fn:tokenize";
}
// </FnTokenizeIterator>


// <FnAnalyzeStringIterator>
SERIALIZABLE_CLASS_VERSIONS(FnAnalyzeStringIterator)

void FnAnalyzeStringIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnAnalyzeStringIterator, PlanIteratorState>*)this);
}


void FnAnalyzeStringIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnAnalyzeStringIterator::~FnAnalyzeStringIterator() {}


zstring FnAnalyzeStringIterator::getNameAsString() const {
  return "fn:analyze-string";
}
// </FnAnalyzeStringIterator>


// <StringAnalyzeStringIterator>
SERIALIZABLE_CLASS_VERSIONS(StringAnalyzeStringIterator)

void StringAnalyzeStringIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<StringAnalyzeStringIterator, PlanIteratorState>*)this);
}


void StringAnalyzeStringIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

StringAnalyzeStringIterator::~StringAnalyzeStringIterator() {}


zstring StringAnalyzeStringIterator::getNameAsString() const {
  return "fn-zorba-string:analyze-string";
}
// </StringAnalyzeStringIterator>


// <StringMaterializeIterator>
SERIALIZABLE_CLASS_VERSIONS(StringMaterializeIterator)

void StringMaterializeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<StringMaterializeIterator, PlanIteratorState>*)this);
}


void StringMaterializeIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

StringMaterializeIterator::~StringMaterializeIterator() {}


zstring StringMaterializeIterator::getNameAsString() const {
  return "fn-zorba-string:materialize";
}
// </StringMaterializeIterator>


// <StringIsStreamableIterator>
SERIALIZABLE_CLASS_VERSIONS(StringIsStreamableIterator)

void StringIsStreamableIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<StringIsStreamableIterator, PlanIteratorState>*)this);
}


void StringIsStreamableIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

StringIsStreamableIterator::~StringIsStreamableIterator() {}


zstring StringIsStreamableIterator::getNameAsString() const {
  return "fn-zorba-string:is-streamable";
}
// </StringIsStreamableIterator>


// <StringIsSeekableIterator>
SERIALIZABLE_CLASS_VERSIONS(StringIsSeekableIterator)

void StringIsSeekableIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<StringIsSeekableIterator, PlanIteratorState>*)this);
}


void StringIsSeekableIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

StringIsSeekableIterator::~StringIsSeekableIterator() {}


zstring StringIsSeekableIterator::getNameAsString() const {
  return "fn-zorba-string:is-seekable";
}
// </StringIsSeekableIterator>


// <StringSplitIterator>
SERIALIZABLE_CLASS_VERSIONS(StringSplitIterator)

void StringSplitIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<StringSplitIterator, StringSplitIteratorState>*)this);
}


void StringSplitIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

StringSplitIterator::~StringSplitIterator() {}

StringSplitIteratorState::StringSplitIteratorState() {}

StringSplitIteratorState::~StringSplitIteratorState() {}


void StringSplitIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theNextStartPos = 0;
}

void StringSplitIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theNextStartPos = 0;
}

zstring StringSplitIterator::getNameAsString() const {
  return "fn-zorba-string:split";
}
// </StringSplitIterator>



}



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
#include "runtime/strings/strings.h"
#include "system/globalenv.h"



namespace zorba {

// <CodepointsToStringIterator>
const char* CodepointsToStringIterator::class_name_str = "CodepointsToStringIterator";
CodepointsToStringIterator::class_factory<CodepointsToStringIterator>
CodepointsToStringIterator::g_class_factory;

const serialization::ClassVersion 
CodepointsToStringIterator::class_versions[] ={{ 1, 0x000905, false}};

const int CodepointsToStringIterator::class_versions_count =
sizeof(CodepointsToStringIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void CodepointsToStringIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

CodepointsToStringIterator::~CodepointsToStringIterator() {}

// </CodepointsToStringIterator>


// <StringToCodepointsIterator>
const char* StringToCodepointsIterator::class_name_str = "StringToCodepointsIterator";
StringToCodepointsIterator::class_factory<StringToCodepointsIterator>
StringToCodepointsIterator::g_class_factory;

const serialization::ClassVersion 
StringToCodepointsIterator::class_versions[] ={{ 1, 0x000905, false}};

const int StringToCodepointsIterator::class_versions_count =
sizeof(StringToCodepointsIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void StringToCodepointsIterator::accept(PlanIterVisitor& v) const {
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

// </StringToCodepointsIterator>


// <CompareStrIterator>
const char* CompareStrIterator::class_name_str = "CompareStrIterator";
CompareStrIterator::class_factory<CompareStrIterator>
CompareStrIterator::g_class_factory;

const serialization::ClassVersion 
CompareStrIterator::class_versions[] ={{ 1, 0x000905, false}};

const int CompareStrIterator::class_versions_count =
sizeof(CompareStrIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void CompareStrIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

CompareStrIterator::~CompareStrIterator() {}

// </CompareStrIterator>


// <CodepointEqualIterator>
const char* CodepointEqualIterator::class_name_str = "CodepointEqualIterator";
CodepointEqualIterator::class_factory<CodepointEqualIterator>
CodepointEqualIterator::g_class_factory;

const serialization::ClassVersion 
CodepointEqualIterator::class_versions[] ={{ 1, 0x000905, false}};

const int CodepointEqualIterator::class_versions_count =
sizeof(CodepointEqualIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void CodepointEqualIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

CodepointEqualIterator::~CodepointEqualIterator() {}

// </CodepointEqualIterator>


// <ConcatStrIterator>
const char* ConcatStrIterator::class_name_str = "ConcatStrIterator";
ConcatStrIterator::class_factory<ConcatStrIterator>
ConcatStrIterator::g_class_factory;

const serialization::ClassVersion 
ConcatStrIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ConcatStrIterator::class_versions_count =
sizeof(ConcatStrIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ConcatStrIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ConcatStrIterator::~ConcatStrIterator() {}

// </ConcatStrIterator>


// <StringJoinIterator>
const char* StringJoinIterator::class_name_str = "StringJoinIterator";
StringJoinIterator::class_factory<StringJoinIterator>
StringJoinIterator::g_class_factory;

const serialization::ClassVersion 
StringJoinIterator::class_versions[] ={{ 1, 0x000905, false}};

const int StringJoinIterator::class_versions_count =
sizeof(StringJoinIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void StringJoinIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

StringJoinIterator::~StringJoinIterator() {}

// </StringJoinIterator>


// <SubstringIterator>
const char* SubstringIterator::class_name_str = "SubstringIterator";
SubstringIterator::class_factory<SubstringIterator>
SubstringIterator::g_class_factory;

const serialization::ClassVersion 
SubstringIterator::class_versions[] ={{ 1, 0x000905, false}};

const int SubstringIterator::class_versions_count =
sizeof(SubstringIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void SubstringIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

SubstringIterator::~SubstringIterator() {}

// </SubstringIterator>


// <SubstringIntOptIterator>
const char* SubstringIntOptIterator::class_name_str = "SubstringIntOptIterator";
SubstringIntOptIterator::class_factory<SubstringIntOptIterator>
SubstringIntOptIterator::g_class_factory;

const serialization::ClassVersion 
SubstringIntOptIterator::class_versions[] ={{ 1, 0x000905, false}};

const int SubstringIntOptIterator::class_versions_count =
sizeof(SubstringIntOptIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void SubstringIntOptIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

SubstringIntOptIterator::~SubstringIntOptIterator() {}

// </SubstringIntOptIterator>


// <StringLengthIterator>
const char* StringLengthIterator::class_name_str = "StringLengthIterator";
StringLengthIterator::class_factory<StringLengthIterator>
StringLengthIterator::g_class_factory;

const serialization::ClassVersion 
StringLengthIterator::class_versions[] ={{ 1, 0x000905, false}};

const int StringLengthIterator::class_versions_count =
sizeof(StringLengthIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void StringLengthIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

StringLengthIterator::~StringLengthIterator() {}

// </StringLengthIterator>


// <NormalizeSpaceIterator>
const char* NormalizeSpaceIterator::class_name_str = "NormalizeSpaceIterator";
NormalizeSpaceIterator::class_factory<NormalizeSpaceIterator>
NormalizeSpaceIterator::g_class_factory;

const serialization::ClassVersion 
NormalizeSpaceIterator::class_versions[] ={{ 1, 0x000905, false}};

const int NormalizeSpaceIterator::class_versions_count =
sizeof(NormalizeSpaceIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void NormalizeSpaceIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

NormalizeSpaceIterator::~NormalizeSpaceIterator() {}

// </NormalizeSpaceIterator>


// <NormalizeUnicodeIterator>
const char* NormalizeUnicodeIterator::class_name_str = "NormalizeUnicodeIterator";
NormalizeUnicodeIterator::class_factory<NormalizeUnicodeIterator>
NormalizeUnicodeIterator::g_class_factory;

const serialization::ClassVersion 
NormalizeUnicodeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int NormalizeUnicodeIterator::class_versions_count =
sizeof(NormalizeUnicodeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void NormalizeUnicodeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

NormalizeUnicodeIterator::~NormalizeUnicodeIterator() {}

// </NormalizeUnicodeIterator>


// <UpperCaseIterator>
const char* UpperCaseIterator::class_name_str = "UpperCaseIterator";
UpperCaseIterator::class_factory<UpperCaseIterator>
UpperCaseIterator::g_class_factory;

const serialization::ClassVersion 
UpperCaseIterator::class_versions[] ={{ 1, 0x000905, false}};

const int UpperCaseIterator::class_versions_count =
sizeof(UpperCaseIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void UpperCaseIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

UpperCaseIterator::~UpperCaseIterator() {}

// </UpperCaseIterator>


// <LowerCaseIterator>
const char* LowerCaseIterator::class_name_str = "LowerCaseIterator";
LowerCaseIterator::class_factory<LowerCaseIterator>
LowerCaseIterator::g_class_factory;

const serialization::ClassVersion 
LowerCaseIterator::class_versions[] ={{ 1, 0x000905, false}};

const int LowerCaseIterator::class_versions_count =
sizeof(LowerCaseIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void LowerCaseIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

LowerCaseIterator::~LowerCaseIterator() {}

// </LowerCaseIterator>


// <TranslateIterator>
const char* TranslateIterator::class_name_str = "TranslateIterator";
TranslateIterator::class_factory<TranslateIterator>
TranslateIterator::g_class_factory;

const serialization::ClassVersion 
TranslateIterator::class_versions[] ={{ 1, 0x000905, false}};

const int TranslateIterator::class_versions_count =
sizeof(TranslateIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void TranslateIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

TranslateIterator::~TranslateIterator() {}

// </TranslateIterator>


// <EncodeForUriIterator>
const char* EncodeForUriIterator::class_name_str = "EncodeForUriIterator";
EncodeForUriIterator::class_factory<EncodeForUriIterator>
EncodeForUriIterator::g_class_factory;

const serialization::ClassVersion 
EncodeForUriIterator::class_versions[] ={{ 1, 0x000905, false}};

const int EncodeForUriIterator::class_versions_count =
sizeof(EncodeForUriIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void EncodeForUriIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

EncodeForUriIterator::~EncodeForUriIterator() {}

// </EncodeForUriIterator>


// <IriToUriIterator>
const char* IriToUriIterator::class_name_str = "IriToUriIterator";
IriToUriIterator::class_factory<IriToUriIterator>
IriToUriIterator::g_class_factory;

const serialization::ClassVersion 
IriToUriIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IriToUriIterator::class_versions_count =
sizeof(IriToUriIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IriToUriIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IriToUriIterator::~IriToUriIterator() {}

// </IriToUriIterator>


// <EscapeHtmlUriIterator>
const char* EscapeHtmlUriIterator::class_name_str = "EscapeHtmlUriIterator";
EscapeHtmlUriIterator::class_factory<EscapeHtmlUriIterator>
EscapeHtmlUriIterator::g_class_factory;

const serialization::ClassVersion 
EscapeHtmlUriIterator::class_versions[] ={{ 1, 0x000905, false}};

const int EscapeHtmlUriIterator::class_versions_count =
sizeof(EscapeHtmlUriIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void EscapeHtmlUriIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

EscapeHtmlUriIterator::~EscapeHtmlUriIterator() {}

// </EscapeHtmlUriIterator>


// <ContainsIterator>
const char* ContainsIterator::class_name_str = "ContainsIterator";
ContainsIterator::class_factory<ContainsIterator>
ContainsIterator::g_class_factory;

const serialization::ClassVersion 
ContainsIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ContainsIterator::class_versions_count =
sizeof(ContainsIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ContainsIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ContainsIterator::~ContainsIterator() {}

// </ContainsIterator>


// <StartsWithIterator>
const char* StartsWithIterator::class_name_str = "StartsWithIterator";
StartsWithIterator::class_factory<StartsWithIterator>
StartsWithIterator::g_class_factory;

const serialization::ClassVersion 
StartsWithIterator::class_versions[] ={{ 1, 0x000905, false}};

const int StartsWithIterator::class_versions_count =
sizeof(StartsWithIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void StartsWithIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

StartsWithIterator::~StartsWithIterator() {}

// </StartsWithIterator>


// <EndsWithIterator>
const char* EndsWithIterator::class_name_str = "EndsWithIterator";
EndsWithIterator::class_factory<EndsWithIterator>
EndsWithIterator::g_class_factory;

const serialization::ClassVersion 
EndsWithIterator::class_versions[] ={{ 1, 0x000905, false}};

const int EndsWithIterator::class_versions_count =
sizeof(EndsWithIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void EndsWithIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

EndsWithIterator::~EndsWithIterator() {}

// </EndsWithIterator>


// <SubstringBeforeIterator>
const char* SubstringBeforeIterator::class_name_str = "SubstringBeforeIterator";
SubstringBeforeIterator::class_factory<SubstringBeforeIterator>
SubstringBeforeIterator::g_class_factory;

const serialization::ClassVersion 
SubstringBeforeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int SubstringBeforeIterator::class_versions_count =
sizeof(SubstringBeforeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void SubstringBeforeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

SubstringBeforeIterator::~SubstringBeforeIterator() {}

// </SubstringBeforeIterator>


// <SubstringAfterIterator>
const char* SubstringAfterIterator::class_name_str = "SubstringAfterIterator";
SubstringAfterIterator::class_factory<SubstringAfterIterator>
SubstringAfterIterator::g_class_factory;

const serialization::ClassVersion 
SubstringAfterIterator::class_versions[] ={{ 1, 0x000905, false}};

const int SubstringAfterIterator::class_versions_count =
sizeof(SubstringAfterIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void SubstringAfterIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

SubstringAfterIterator::~SubstringAfterIterator() {}

// </SubstringAfterIterator>


// <FnMatchesIterator>
const char* FnMatchesIterator::class_name_str = "FnMatchesIterator";
FnMatchesIterator::class_factory<FnMatchesIterator>
FnMatchesIterator::g_class_factory;

const serialization::ClassVersion 
FnMatchesIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnMatchesIterator::class_versions_count =
sizeof(FnMatchesIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FnMatchesIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnMatchesIterator::~FnMatchesIterator() {}

// </FnMatchesIterator>


// <FnReplaceIterator>
const char* FnReplaceIterator::class_name_str = "FnReplaceIterator";
FnReplaceIterator::class_factory<FnReplaceIterator>
FnReplaceIterator::g_class_factory;

const serialization::ClassVersion 
FnReplaceIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnReplaceIterator::class_versions_count =
sizeof(FnReplaceIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FnReplaceIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnReplaceIterator::~FnReplaceIterator() {}

// </FnReplaceIterator>


// <FnTokenizeIterator>
const char* FnTokenizeIterator::class_name_str = "FnTokenizeIterator";
FnTokenizeIterator::class_factory<FnTokenizeIterator>
FnTokenizeIterator::g_class_factory;

const serialization::ClassVersion 
FnTokenizeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnTokenizeIterator::class_versions_count =
sizeof(FnTokenizeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FnTokenizeIterator::accept(PlanIterVisitor& v) const {
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
// </FnTokenizeIterator>


// <FnAnalyzeStringIterator>
const char* FnAnalyzeStringIterator::class_name_str = "FnAnalyzeStringIterator";
FnAnalyzeStringIterator::class_factory<FnAnalyzeStringIterator>
FnAnalyzeStringIterator::g_class_factory;

const serialization::ClassVersion 
FnAnalyzeStringIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnAnalyzeStringIterator::class_versions_count =
sizeof(FnAnalyzeStringIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FnAnalyzeStringIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnAnalyzeStringIterator::~FnAnalyzeStringIterator() {}

// </FnAnalyzeStringIterator>


// <StringMaterializeIterator>
const char* StringMaterializeIterator::class_name_str = "StringMaterializeIterator";
StringMaterializeIterator::class_factory<StringMaterializeIterator>
StringMaterializeIterator::g_class_factory;

const serialization::ClassVersion 
StringMaterializeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int StringMaterializeIterator::class_versions_count =
sizeof(StringMaterializeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void StringMaterializeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

StringMaterializeIterator::~StringMaterializeIterator() {}

// </StringMaterializeIterator>


// <StringIsStreamableIterator>
const char* StringIsStreamableIterator::class_name_str = "StringIsStreamableIterator";
StringIsStreamableIterator::class_factory<StringIsStreamableIterator>
StringIsStreamableIterator::g_class_factory;

const serialization::ClassVersion 
StringIsStreamableIterator::class_versions[] ={{ 1, 0x000905, false}};

const int StringIsStreamableIterator::class_versions_count =
sizeof(StringIsStreamableIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void StringIsStreamableIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

StringIsStreamableIterator::~StringIsStreamableIterator() {}

// </StringIsStreamableIterator>



}



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
CodepointsToStringIterator::class_factory<CodepointsToStringIterator>
CodepointsToStringIterator::g_class_factory;


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
StringToCodepointsIterator::class_factory<StringToCodepointsIterator>
StringToCodepointsIterator::g_class_factory;


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
CompareStrIterator::class_factory<CompareStrIterator>
CompareStrIterator::g_class_factory;


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
CodepointEqualIterator::class_factory<CodepointEqualIterator>
CodepointEqualIterator::g_class_factory;


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
ConcatStrIterator::class_factory<ConcatStrIterator>
ConcatStrIterator::g_class_factory;


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
StringJoinIterator::class_factory<StringJoinIterator>
StringJoinIterator::g_class_factory;


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
SubstringIterator::class_factory<SubstringIterator>
SubstringIterator::g_class_factory;


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
SubstringIntOptIterator::class_factory<SubstringIntOptIterator>
SubstringIntOptIterator::g_class_factory;


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
StringLengthIterator::class_factory<StringLengthIterator>
StringLengthIterator::g_class_factory;


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
NormalizeSpaceIterator::class_factory<NormalizeSpaceIterator>
NormalizeSpaceIterator::g_class_factory;


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
NormalizeUnicodeIterator::class_factory<NormalizeUnicodeIterator>
NormalizeUnicodeIterator::g_class_factory;


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
UpperCaseIterator::class_factory<UpperCaseIterator>
UpperCaseIterator::g_class_factory;


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
LowerCaseIterator::class_factory<LowerCaseIterator>
LowerCaseIterator::g_class_factory;


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
TranslateIterator::class_factory<TranslateIterator>
TranslateIterator::g_class_factory;


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
EncodeForUriIterator::class_factory<EncodeForUriIterator>
EncodeForUriIterator::g_class_factory;


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
IriToUriIterator::class_factory<IriToUriIterator>
IriToUriIterator::g_class_factory;


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
EscapeHtmlUriIterator::class_factory<EscapeHtmlUriIterator>
EscapeHtmlUriIterator::g_class_factory;


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
ContainsIterator::class_factory<ContainsIterator>
ContainsIterator::g_class_factory;


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
StartsWithIterator::class_factory<StartsWithIterator>
StartsWithIterator::g_class_factory;


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
EndsWithIterator::class_factory<EndsWithIterator>
EndsWithIterator::g_class_factory;


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
SubstringBeforeIterator::class_factory<SubstringBeforeIterator>
SubstringBeforeIterator::g_class_factory;


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
SubstringAfterIterator::class_factory<SubstringAfterIterator>
SubstringAfterIterator::g_class_factory;


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
FnMatchesIterator::class_factory<FnMatchesIterator>
FnMatchesIterator::g_class_factory;


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
FnReplaceIterator::class_factory<FnReplaceIterator>
FnReplaceIterator::g_class_factory;


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
FnTokenizeIterator::class_factory<FnTokenizeIterator>
FnTokenizeIterator::g_class_factory;


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
FnAnalyzeStringIterator::class_factory<FnAnalyzeStringIterator>
FnAnalyzeStringIterator::g_class_factory;


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
StringMaterializeIterator::class_factory<StringMaterializeIterator>
StringMaterializeIterator::g_class_factory;


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
StringIsStreamableIterator::class_factory<StringIsStreamableIterator>
StringIsStreamableIterator::g_class_factory;


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


// <StringSplitIterator>
StringSplitIterator::class_factory<StringSplitIterator>
StringSplitIterator::g_class_factory;


void StringSplitIterator::accept(PlanIterVisitor& v) const {
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
// </StringSplitIterator>



}



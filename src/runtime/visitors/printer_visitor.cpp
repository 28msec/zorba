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

#include "runtime/visitors/printer_visitor.h"

// get forward declarations for all classes from planitervisitor.h

#include "runtime/visitors/planiter_visitor.h"

#include "runtime/visitors/iterprinter.h"

#include "util/properties.h"

#include "zorbautils/strutil.h"

#include "runtime/sequences/sequences.h"
#include "runtime/strings/strings.h"

namespace zorba{

void PrinterVisitor::print() {
  thePrinter.start();
  theIterator->accept(*this);
  thePrinter.stop();
}

void PrinterVisitor::printCommons(const PlanIterator* aIter, int theId) {
  if (! Properties::instance()->noTreeIds()) {
    std::stringstream lStream;
    if (Properties::instance()->stableIteratorIds())
      lStream << theId;
    else
      lStream << aIter;
    thePrinter.addAttribute("id", lStream.str());
  }
}

void PrinterVisitor::printNameOrKindTest(const AxisIteratorHelper* a) {
  thePrinter.addAttribute("test kind", toString(a->getTestKind()));

  if (a->getDocTestKind() != match_no_test)
    thePrinter.addAttribute("doc_test_kind", toString(a->getDocTestKind()));

  if (a->getQName() != 0)
    thePrinter.addAttribute("qname", a->getQName()->show());
  else
    thePrinter.addAttribute("qname","*");

  if (a->getType() != 0)
    thePrinter.addAttribute("typename", a->getType()->toString());
  else
    thePrinter.addAttribute("typename","*");

  std::stringstream lStream;
  lStream << a->nilledAllowed();
  thePrinter.addAttribute("nill allowed", lStream.str());

  if (a->getTargetPos() >= 0)
    thePrinter.addAttribute("target_position", to_string(a->getTargetPos()));
}

// <FnConcatIterator>
void PrinterVisitor::beginVisit ( const FnConcatIterator& a) {
  thePrinter.startBeginVisit("FnConcatIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnConcatIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnConcatIterator>

// <FnIndexOfIterator>
void PrinterVisitor::beginVisit ( const FnIndexOfIterator& a) {
  thePrinter.startBeginVisit("FnIndexOfIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnIndexOfIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnIndexOfIterator>

// <FnEmptyIterator>
void PrinterVisitor::beginVisit ( const FnEmptyIterator& a) {
  thePrinter.startBeginVisit("FnEmptyIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnEmptyIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnEmptyIterator>

// <FnExistsIterator>
void PrinterVisitor::beginVisit ( const FnExistsIterator& a) {
  thePrinter.startBeginVisit("FnExistsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnExistsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnExistsIterator>

// <FnInsertBeforeIterator>
void PrinterVisitor::beginVisit ( const FnInsertBeforeIterator& a) {
  thePrinter.startBeginVisit("FnInsertBeforeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnInsertBeforeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnInsertBeforeIterator>

// <FnRemoveIterator>
void PrinterVisitor::beginVisit ( const FnRemoveIterator& a) {
  thePrinter.startBeginVisit("FnRemoveIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnRemoveIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnRemoveIterator>

// <FnReverseIterator>
void PrinterVisitor::beginVisit ( const FnReverseIterator& a) {
  thePrinter.startBeginVisit("FnReverseIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnReverseIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnReverseIterator>

// <FnSubsequenceIterator>
void PrinterVisitor::beginVisit ( const FnSubsequenceIterator& a) {
  thePrinter.startBeginVisit("FnSubsequenceIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnSubsequenceIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnSubsequenceIterator>

// <FnZeroOrOneIterator>
void PrinterVisitor::beginVisit ( const FnZeroOrOneIterator& a) {
  thePrinter.startBeginVisit("FnZeroOrOneIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnZeroOrOneIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnZeroOrOneIterator>

// <FnOneOrMoreIterator>
void PrinterVisitor::beginVisit ( const FnOneOrMoreIterator& a) {
  thePrinter.startBeginVisit("FnOneOrMoreIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnOneOrMoreIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnOneOrMoreIterator>

// <FnExactlyOneIterator>
void PrinterVisitor::beginVisit ( const FnExactlyOneIterator& a) {
  thePrinter.startBeginVisit("FnExactlyOneIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnExactlyOneIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnExactlyOneIterator>

// <FnDeepEqualIterator>
void PrinterVisitor::beginVisit ( const FnDeepEqualIterator& a) {
  thePrinter.startBeginVisit("FnDeepEqualIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnDeepEqualIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnDeepEqualIterator>

// <HashSemiJoinIterator>
void PrinterVisitor::beginVisit ( const HashSemiJoinIterator& a) {
  thePrinter.startBeginVisit("HashSemiJoinIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const HashSemiJoinIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </HashSemiJoinIterator>

// <SortSemiJoinIterator>
void PrinterVisitor::beginVisit ( const SortSemiJoinIterator& a) {
  thePrinter.startBeginVisit("SortSemiJoinIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const SortSemiJoinIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SortSemiJoinIterator>

// <FnCountIterator>
void PrinterVisitor::beginVisit ( const FnCountIterator& a) {
  thePrinter.startBeginVisit("FnCountIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnCountIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnCountIterator>

// <FnAvgIterator>
void PrinterVisitor::beginVisit ( const FnAvgIterator& a) {
  thePrinter.startBeginVisit("FnAvgIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnAvgIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnAvgIterator>

// <FnSumIterator>
void PrinterVisitor::beginVisit ( const FnSumIterator& a) {
  thePrinter.startBeginVisit("FnSumIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnSumIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnSumIterator>

// <FnSumDoubleIterator>
void PrinterVisitor::beginVisit ( const FnSumDoubleIterator& a) {
  thePrinter.startBeginVisit("FnSumDoubleIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnSumDoubleIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnSumDoubleIterator>

// <FnSumFloatIterator>
void PrinterVisitor::beginVisit ( const FnSumFloatIterator& a) {
  thePrinter.startBeginVisit("FnSumFloatIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnSumFloatIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnSumFloatIterator>

// <FnSumDecimalIterator>
void PrinterVisitor::beginVisit ( const FnSumDecimalIterator& a) {
  thePrinter.startBeginVisit("FnSumDecimalIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnSumDecimalIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnSumDecimalIterator>

// <FnSumIntegerIterator>
void PrinterVisitor::beginVisit ( const FnSumIntegerIterator& a) {
  thePrinter.startBeginVisit("FnSumIntegerIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnSumIntegerIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnSumIntegerIterator>

// <OpToIterator>
void PrinterVisitor::beginVisit ( const OpToIterator& a) {
  thePrinter.startBeginVisit("OpToIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const OpToIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </OpToIterator>

// <FnDocIterator>
void PrinterVisitor::beginVisit ( const FnDocIterator& a) {
  thePrinter.startBeginVisit("FnDocIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnDocIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnDocIterator>

// <FnDocAvailableIterator>
void PrinterVisitor::beginVisit ( const FnDocAvailableIterator& a) {
  thePrinter.startBeginVisit("FnDocAvailableIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnDocAvailableIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnDocAvailableIterator>

// <FnParseIterator>
void PrinterVisitor::beginVisit ( const FnParseIterator& a) {
  thePrinter.startBeginVisit("FnParseIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnParseIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnParseIterator>

// <CodepointsToStringIterator>
void PrinterVisitor::beginVisit ( const CodepointsToStringIterator& a) {
  thePrinter.startBeginVisit("CodepointsToStringIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const CodepointsToStringIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CodepointsToStringIterator>

// <CompareStrIterator>
void PrinterVisitor::beginVisit ( const CompareStrIterator& a) {
  thePrinter.startBeginVisit("CompareStrIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const CompareStrIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CompareStrIterator>

// <CodepointEqualIterator>
void PrinterVisitor::beginVisit ( const CodepointEqualIterator& a) {
  thePrinter.startBeginVisit("CodepointEqualIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const CodepointEqualIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CodepointEqualIterator>

// <ConcatStrIterator>
void PrinterVisitor::beginVisit ( const ConcatStrIterator& a) {
  thePrinter.startBeginVisit("ConcatStrIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ConcatStrIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ConcatStrIterator>

// <StringJoinIterator>
void PrinterVisitor::beginVisit ( const StringJoinIterator& a) {
  thePrinter.startBeginVisit("StringJoinIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const StringJoinIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StringJoinIterator>

// <SubstringIterator>
void PrinterVisitor::beginVisit ( const SubstringIterator& a) {
  thePrinter.startBeginVisit("SubstringIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const SubstringIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SubstringIterator>

// <StringLengthIterator>
void PrinterVisitor::beginVisit ( const StringLengthIterator& a) {
  thePrinter.startBeginVisit("StringLengthIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const StringLengthIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StringLengthIterator>

// <NormalizeSpaceIterator>
void PrinterVisitor::beginVisit ( const NormalizeSpaceIterator& a) {
  thePrinter.startBeginVisit("NormalizeSpaceIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const NormalizeSpaceIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NormalizeSpaceIterator>

// <NormalizeUnicodeIterator>
void PrinterVisitor::beginVisit ( const NormalizeUnicodeIterator& a) {
  thePrinter.startBeginVisit("NormalizeUnicodeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const NormalizeUnicodeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NormalizeUnicodeIterator>

// <UpperCaseIterator>
void PrinterVisitor::beginVisit ( const UpperCaseIterator& a) {
  thePrinter.startBeginVisit("UpperCaseIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const UpperCaseIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </UpperCaseIterator>

// <LowerCaseIterator>
void PrinterVisitor::beginVisit ( const LowerCaseIterator& a) {
  thePrinter.startBeginVisit("LowerCaseIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const LowerCaseIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </LowerCaseIterator>

// <TranslateIterator>
void PrinterVisitor::beginVisit ( const TranslateIterator& a) {
  thePrinter.startBeginVisit("TranslateIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const TranslateIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </TranslateIterator>

// <EncodeForUriIterator>
void PrinterVisitor::beginVisit ( const EncodeForUriIterator& a) {
  thePrinter.startBeginVisit("EncodeForUriIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const EncodeForUriIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </EncodeForUriIterator>

// <IriToUriIterator>
void PrinterVisitor::beginVisit ( const IriToUriIterator& a) {
  thePrinter.startBeginVisit("IriToUriIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IriToUriIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IriToUriIterator>

// <EscapeHtmlUriIterator>
void PrinterVisitor::beginVisit ( const EscapeHtmlUriIterator& a) {
  thePrinter.startBeginVisit("EscapeHtmlUriIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const EscapeHtmlUriIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </EscapeHtmlUriIterator>

// <ContainsIterator>
void PrinterVisitor::beginVisit ( const ContainsIterator& a) {
  thePrinter.startBeginVisit("ContainsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ContainsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ContainsIterator>

// <StartsWithIterator>
void PrinterVisitor::beginVisit ( const StartsWithIterator& a) {
  thePrinter.startBeginVisit("StartsWithIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const StartsWithIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StartsWithIterator>

// <EndsWithIterator>
void PrinterVisitor::beginVisit ( const EndsWithIterator& a) {
  thePrinter.startBeginVisit("EndsWithIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const EndsWithIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </EndsWithIterator>

// <SubstringBeforeIterator>
void PrinterVisitor::beginVisit ( const SubstringBeforeIterator& a) {
  thePrinter.startBeginVisit("SubstringBeforeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const SubstringBeforeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SubstringBeforeIterator>

// <SubstringAfterIterator>
void PrinterVisitor::beginVisit ( const SubstringAfterIterator& a) {
  thePrinter.startBeginVisit("SubstringAfterIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const SubstringAfterIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SubstringAfterIterator>

// <FnMatchesIterator>
void PrinterVisitor::beginVisit ( const FnMatchesIterator& a) {
  thePrinter.startBeginVisit("FnMatchesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnMatchesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnMatchesIterator>

// <FnReplaceIterator>
void PrinterVisitor::beginVisit ( const FnReplaceIterator& a) {
  thePrinter.startBeginVisit("FnReplaceIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnReplaceIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnReplaceIterator>


}
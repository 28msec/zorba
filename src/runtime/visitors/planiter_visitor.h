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

#ifndef ZORBA_RUNTIME_VISITORS_PLAN_ITER_VISITOR_H
#define ZORBA_RUNTIME_VISITORS_PLAN_ITER_VISITOR_H

#include <vector>
#include "common/common.h"
#include "zorbatypes/zorbatypes_decl.h"
#include "types/typeconstants.h"


namespace zorba{

    class CodepointsToStringIterator;
    class CompareStrIterator;
    class CodepointEqualIterator;
    class ConcatStrIterator;
    class StringJoinIterator;
    class SubstringIterator;
    class StringLengthIterator;
    class NormalizeSpaceIterator;
    class NormalizeUnicodeIterator;
    class UpperCaseIterator;
    class LowerCaseIterator;
    class TranslateIterator;
    class EncodeForUriIterator;
    class IriToUriIterator;
    class EscapeHtmlUriIterator;
    class ContainsIterator;
    class StartsWithIterator;
    class EndsWithIterator;
    class SubstringBeforeIterator;
    class SubstringAfterIterator;
    class FnMatchesIterator;
    class FnReplaceIterator;
    class FnConcatIterator;
    class FnIndexOfIterator;
    class FnEmptyIterator;
    class FnExistsIterator;
    class FnInsertBeforeIterator;
    class FnRemoveIterator;
    class FnReverseIterator;
    class FnSubsequenceIterator;
    class FnZeroOrOneIterator;
    class FnOneOrMoreIterator;
    class FnExactlyOneIterator;
    class FnDeepEqualIterator;
    class HashSemiJoinIterator;
    class SortSemiJoinIterator;
    class FnCountIterator;
    class FnAvgIterator;
    class FnSumIterator;
    class FnSumDoubleIterator;
    class FnSumFloatIterator;
    class FnSumDecimalIterator;
    class FnSumIntegerIterator;
    class OpToIterator;
    class FnDocIterator;
    class FnDocAvailableIterator;
    class FnParseIterator;

#include "runtime/visitors/planiter_visitor_impl_include.h"

/**
 * Visitor to visit a PlanIterator tree.
 */
class PlanIterVisitor {
public:
  virtual ~PlanIterVisitor() {}

#include "runtime/visitors/planiter_visitor_impl_code.h"

    virtual void beginVisit ( const CodepointsToStringIterator& ) = 0;
    virtual void endVisit   ( const CodepointsToStringIterator& ) = 0;

    virtual void beginVisit ( const CompareStrIterator& ) = 0;
    virtual void endVisit   ( const CompareStrIterator& ) = 0;

    virtual void beginVisit ( const CodepointEqualIterator& ) = 0;
    virtual void endVisit   ( const CodepointEqualIterator& ) = 0;

    virtual void beginVisit ( const ConcatStrIterator& ) = 0;
    virtual void endVisit   ( const ConcatStrIterator& ) = 0;

    virtual void beginVisit ( const StringJoinIterator& ) = 0;
    virtual void endVisit   ( const StringJoinIterator& ) = 0;

    virtual void beginVisit ( const SubstringIterator& ) = 0;
    virtual void endVisit   ( const SubstringIterator& ) = 0;

    virtual void beginVisit ( const StringLengthIterator& ) = 0;
    virtual void endVisit   ( const StringLengthIterator& ) = 0;

    virtual void beginVisit ( const NormalizeSpaceIterator& ) = 0;
    virtual void endVisit   ( const NormalizeSpaceIterator& ) = 0;

    virtual void beginVisit ( const NormalizeUnicodeIterator& ) = 0;
    virtual void endVisit   ( const NormalizeUnicodeIterator& ) = 0;

    virtual void beginVisit ( const UpperCaseIterator& ) = 0;
    virtual void endVisit   ( const UpperCaseIterator& ) = 0;

    virtual void beginVisit ( const LowerCaseIterator& ) = 0;
    virtual void endVisit   ( const LowerCaseIterator& ) = 0;

    virtual void beginVisit ( const TranslateIterator& ) = 0;
    virtual void endVisit   ( const TranslateIterator& ) = 0;

    virtual void beginVisit ( const EncodeForUriIterator& ) = 0;
    virtual void endVisit   ( const EncodeForUriIterator& ) = 0;

    virtual void beginVisit ( const IriToUriIterator& ) = 0;
    virtual void endVisit   ( const IriToUriIterator& ) = 0;

    virtual void beginVisit ( const EscapeHtmlUriIterator& ) = 0;
    virtual void endVisit   ( const EscapeHtmlUriIterator& ) = 0;

    virtual void beginVisit ( const ContainsIterator& ) = 0;
    virtual void endVisit   ( const ContainsIterator& ) = 0;

    virtual void beginVisit ( const StartsWithIterator& ) = 0;
    virtual void endVisit   ( const StartsWithIterator& ) = 0;

    virtual void beginVisit ( const EndsWithIterator& ) = 0;
    virtual void endVisit   ( const EndsWithIterator& ) = 0;

    virtual void beginVisit ( const SubstringBeforeIterator& ) = 0;
    virtual void endVisit   ( const SubstringBeforeIterator& ) = 0;

    virtual void beginVisit ( const SubstringAfterIterator& ) = 0;
    virtual void endVisit   ( const SubstringAfterIterator& ) = 0;

    virtual void beginVisit ( const FnMatchesIterator& ) = 0;
    virtual void endVisit   ( const FnMatchesIterator& ) = 0;

    virtual void beginVisit ( const FnReplaceIterator& ) = 0;
    virtual void endVisit   ( const FnReplaceIterator& ) = 0;

    virtual void beginVisit ( const FnConcatIterator& ) = 0;
    virtual void endVisit   ( const FnConcatIterator& ) = 0;

    virtual void beginVisit ( const FnIndexOfIterator& ) = 0;
    virtual void endVisit   ( const FnIndexOfIterator& ) = 0;

    virtual void beginVisit ( const FnEmptyIterator& ) = 0;
    virtual void endVisit   ( const FnEmptyIterator& ) = 0;

    virtual void beginVisit ( const FnExistsIterator& ) = 0;
    virtual void endVisit   ( const FnExistsIterator& ) = 0;

    virtual void beginVisit ( const FnInsertBeforeIterator& ) = 0;
    virtual void endVisit   ( const FnInsertBeforeIterator& ) = 0;

    virtual void beginVisit ( const FnRemoveIterator& ) = 0;
    virtual void endVisit   ( const FnRemoveIterator& ) = 0;

    virtual void beginVisit ( const FnReverseIterator& ) = 0;
    virtual void endVisit   ( const FnReverseIterator& ) = 0;

    virtual void beginVisit ( const FnSubsequenceIterator& ) = 0;
    virtual void endVisit   ( const FnSubsequenceIterator& ) = 0;

    virtual void beginVisit ( const FnZeroOrOneIterator& ) = 0;
    virtual void endVisit   ( const FnZeroOrOneIterator& ) = 0;

    virtual void beginVisit ( const FnOneOrMoreIterator& ) = 0;
    virtual void endVisit   ( const FnOneOrMoreIterator& ) = 0;

    virtual void beginVisit ( const FnExactlyOneIterator& ) = 0;
    virtual void endVisit   ( const FnExactlyOneIterator& ) = 0;

    virtual void beginVisit ( const FnDeepEqualIterator& ) = 0;
    virtual void endVisit   ( const FnDeepEqualIterator& ) = 0;

    virtual void beginVisit ( const HashSemiJoinIterator& ) = 0;
    virtual void endVisit   ( const HashSemiJoinIterator& ) = 0;

    virtual void beginVisit ( const SortSemiJoinIterator& ) = 0;
    virtual void endVisit   ( const SortSemiJoinIterator& ) = 0;

    virtual void beginVisit ( const FnCountIterator& ) = 0;
    virtual void endVisit   ( const FnCountIterator& ) = 0;

    virtual void beginVisit ( const FnAvgIterator& ) = 0;
    virtual void endVisit   ( const FnAvgIterator& ) = 0;

    virtual void beginVisit ( const FnSumIterator& ) = 0;
    virtual void endVisit   ( const FnSumIterator& ) = 0;

    virtual void beginVisit ( const FnSumDoubleIterator& ) = 0;
    virtual void endVisit   ( const FnSumDoubleIterator& ) = 0;

    virtual void beginVisit ( const FnSumFloatIterator& ) = 0;
    virtual void endVisit   ( const FnSumFloatIterator& ) = 0;

    virtual void beginVisit ( const FnSumDecimalIterator& ) = 0;
    virtual void endVisit   ( const FnSumDecimalIterator& ) = 0;

    virtual void beginVisit ( const FnSumIntegerIterator& ) = 0;
    virtual void endVisit   ( const FnSumIntegerIterator& ) = 0;

    virtual void beginVisit ( const OpToIterator& ) = 0;
    virtual void endVisit   ( const OpToIterator& ) = 0;

    virtual void beginVisit ( const FnDocIterator& ) = 0;
    virtual void endVisit   ( const FnDocIterator& ) = 0;

    virtual void beginVisit ( const FnDocAvailableIterator& ) = 0;
    virtual void endVisit   ( const FnDocAvailableIterator& ) = 0;

    virtual void beginVisit ( const FnParseIterator& ) = 0;
    virtual void endVisit   ( const FnParseIterator& ) = 0;


  }; //class PlanIterVisitor
} //namespace zorba


#endif
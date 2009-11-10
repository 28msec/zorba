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

#ifndef ZORBA_RUNTIME_PRINTER_VISITOR_H
#define ZORBA_RUNTIME_PRINTER_VISITOR_H

#include "runtime/visitors/planiter_visitor.h"

#include "common/common.h"

namespace zorba {

  class PlanIterator;
  class IterPrinter;

  class PrinterVisitor : public PlanIterVisitor {
  private:
    IterPrinter& thePrinter;
    PlanIterator* theIterator;
    int theId;
  public:
    PrinterVisitor(IterPrinter& aPrinter, PlanIterator* aIter)
    :    thePrinter(aPrinter), theIterator(aIter), theId(0) {}

    void print();
    void printCommons(const PlanIterator* aIter, int theId);

#include "runtime/visitors/printer_visitor_impl.h"

    void beginVisit( const NodeNameIterator& );
    void endVisit  ( const NodeNameIterator& );

    void beginVisit( const NilledIterator& );
    void endVisit  ( const NilledIterator& );

    void beginVisit( const FnStringIterator& );
    void endVisit  ( const FnStringIterator& );

    void beginVisit( const FnDataIterator& );
    void endVisit  ( const FnDataIterator& );

    void beginVisit( const BaseUriIterator& );
    void endVisit  ( const BaseUriIterator& );

    void beginVisit( const DocumentUriIterator& );
    void endVisit  ( const DocumentUriIterator& );

    void beginVisit( const RootIterator& );
    void endVisit  ( const RootIterator& );
    void beginVisit( const IsSameNodeIterator& );
    void endVisit  ( const IsSameNodeIterator& );

    void beginVisit( const NodeBeforeIterator& );
    void endVisit  ( const NodeBeforeIterator& );

    void beginVisit( const NodeAfterIterator& );
    void endVisit  ( const NodeAfterIterator& );
    void beginVisit( const CurrentDateTimeIterator& );
    void endVisit  ( const CurrentDateTimeIterator& );

    void beginVisit( const CurrentDateIterator& );
    void endVisit  ( const CurrentDateIterator& );

    void beginVisit( const CurrentTimeIterator& );
    void endVisit  ( const CurrentTimeIterator& );

    void beginVisit( const ImplicitTimezoneIterator& );
    void endVisit  ( const ImplicitTimezoneIterator& );

    void beginVisit( const DefaultCollationIterator& );
    void endVisit  ( const DefaultCollationIterator& );
    void beginVisit( const ZorbaJsonParseIterator& );
    void endVisit  ( const ZorbaJsonParseIterator& );

    void beginVisit( const ZorbaJsonSerializeIterator& );
    void endVisit  ( const ZorbaJsonSerializeIterator& );

    void beginVisit( const ZorbaJsonMLParseIterator& );
    void endVisit  ( const ZorbaJsonMLParseIterator& );

    void beginVisit( const ZorbaJsonMLSerializeIterator& );
    void endVisit  ( const ZorbaJsonMLSerializeIterator& );
    void beginVisit( const YearsFromDurationIterator& );
    void endVisit  ( const YearsFromDurationIterator& );

    void beginVisit( const MonthsFromDurationIterator& );
    void endVisit  ( const MonthsFromDurationIterator& );

    void beginVisit( const DaysFromDurationIterator& );
    void endVisit  ( const DaysFromDurationIterator& );

    void beginVisit( const HoursFromDurationIterator& );
    void endVisit  ( const HoursFromDurationIterator& );

    void beginVisit( const MinutesFromDurationIterator& );
    void endVisit  ( const MinutesFromDurationIterator& );

    void beginVisit( const SecondsFromDurationIterator& );
    void endVisit  ( const SecondsFromDurationIterator& );

    void beginVisit( const YearFromDatetimeIterator& );
    void endVisit  ( const YearFromDatetimeIterator& );

    void beginVisit( const MonthFromDatetimeIterator& );
    void endVisit  ( const MonthFromDatetimeIterator& );

    void beginVisit( const DayFromDatetimeIterator& );
    void endVisit  ( const DayFromDatetimeIterator& );

    void beginVisit( const HoursFromDatetimeIterator& );
    void endVisit  ( const HoursFromDatetimeIterator& );

    void beginVisit( const MinutesFromDatetimeIterator& );
    void endVisit  ( const MinutesFromDatetimeIterator& );

    void beginVisit( const SecondsFromDatetimeIterator& );
    void endVisit  ( const SecondsFromDatetimeIterator& );

    void beginVisit( const TimezoneFromDatetimeIterator& );
    void endVisit  ( const TimezoneFromDatetimeIterator& );

    void beginVisit( const YearFromDateIterator& );
    void endVisit  ( const YearFromDateIterator& );

    void beginVisit( const MonthFromDateIterator& );
    void endVisit  ( const MonthFromDateIterator& );

    void beginVisit( const DayFromDateIterator& );
    void endVisit  ( const DayFromDateIterator& );

    void beginVisit( const TimezoneFromDateIterator& );
    void endVisit  ( const TimezoneFromDateIterator& );

    void beginVisit( const HoursFromTimeIterator& );
    void endVisit  ( const HoursFromTimeIterator& );

    void beginVisit( const MinutesFromTimeIterator& );
    void endVisit  ( const MinutesFromTimeIterator& );

    void beginVisit( const SecondsFromTimeIterator& );
    void endVisit  ( const SecondsFromTimeIterator& );

    void beginVisit( const TimezoneFromTimeIterator& );
    void endVisit  ( const TimezoneFromTimeIterator& );
    void beginVisit( const FnPutIterator& );
    void endVisit  ( const FnPutIterator& );
    void beginVisit( const TraceIterator& );
    void endVisit  ( const TraceIterator& );

    void beginVisit( const ReadLineIterator& );
    void endVisit  ( const ReadLineIterator& );

    void beginVisit( const PrintIterator& );
    void endVisit  ( const PrintIterator& );

    void beginVisit( const ResolveUriIterator& );
    void endVisit  ( const ResolveUriIterator& );

    void beginVisit( const ErrorIterator& );
    void endVisit  ( const ErrorIterator& );
    void beginVisit( const NodeReferenceIterator& );
    void endVisit  ( const NodeReferenceIterator& );

    void beginVisit( const NodeByReferenceIterator& );
    void endVisit  ( const NodeByReferenceIterator& );

    void beginVisit( const FnLocalNameIterator& );
    void endVisit  ( const FnLocalNameIterator& );

    void beginVisit( const FnNamespaceUriIterator& );
    void endVisit  ( const FnNamespaceUriIterator& );

    void beginVisit( const FnLangIterator& );
    void endVisit  ( const FnLangIterator& );
    void beginVisit( const AbsIterator& );
    void endVisit  ( const AbsIterator& );

    void beginVisit( const CeilingIterator& );
    void endVisit  ( const CeilingIterator& );

    void beginVisit( const FloorIterator& );
    void endVisit  ( const FloorIterator& );

    void beginVisit( const RoundIterator& );
    void endVisit  ( const RoundIterator& );

    void beginVisit( const RoundHalfToEvenIterator& );
    void endVisit  ( const RoundHalfToEvenIterator& );

    void beginVisit( const FormatNumberIterator& );
    void endVisit  ( const FormatNumberIterator& );
    void beginVisit( const FnConcatIterator& );
    void endVisit  ( const FnConcatIterator& );

    void beginVisit( const FnIndexOfIterator& );
    void endVisit  ( const FnIndexOfIterator& );

    void beginVisit( const FnEmptyIterator& );
    void endVisit  ( const FnEmptyIterator& );

    void beginVisit( const FnExistsIterator& );
    void endVisit  ( const FnExistsIterator& );

    void beginVisit( const FnInsertBeforeIterator& );
    void endVisit  ( const FnInsertBeforeIterator& );

    void beginVisit( const FnRemoveIterator& );
    void endVisit  ( const FnRemoveIterator& );

    void beginVisit( const FnReverseIterator& );
    void endVisit  ( const FnReverseIterator& );

    void beginVisit( const FnSubsequenceIterator& );
    void endVisit  ( const FnSubsequenceIterator& );

    void beginVisit( const FnZeroOrOneIterator& );
    void endVisit  ( const FnZeroOrOneIterator& );

    void beginVisit( const FnOneOrMoreIterator& );
    void endVisit  ( const FnOneOrMoreIterator& );

    void beginVisit( const FnExactlyOneIterator& );
    void endVisit  ( const FnExactlyOneIterator& );

    void beginVisit( const FnDeepEqualIterator& );
    void endVisit  ( const FnDeepEqualIterator& );

    void beginVisit( const HashSemiJoinIterator& );
    void endVisit  ( const HashSemiJoinIterator& );

    void beginVisit( const SortSemiJoinIterator& );
    void endVisit  ( const SortSemiJoinIterator& );

    void beginVisit( const FnCountIterator& );
    void endVisit  ( const FnCountIterator& );

    void beginVisit( const FnAvgIterator& );
    void endVisit  ( const FnAvgIterator& );

    void beginVisit( const FnSumIterator& );
    void endVisit  ( const FnSumIterator& );

    void beginVisit( const FnSumDoubleIterator& );
    void endVisit  ( const FnSumDoubleIterator& );

    void beginVisit( const FnSumFloatIterator& );
    void endVisit  ( const FnSumFloatIterator& );

    void beginVisit( const FnSumDecimalIterator& );
    void endVisit  ( const FnSumDecimalIterator& );

    void beginVisit( const FnSumIntegerIterator& );
    void endVisit  ( const FnSumIntegerIterator& );

    void beginVisit( const OpToIterator& );
    void endVisit  ( const OpToIterator& );

    void beginVisit( const FnDocIterator& );
    void endVisit  ( const FnDocIterator& );

    void beginVisit( const FnDocAvailableIterator& );
    void endVisit  ( const FnDocAvailableIterator& );

    void beginVisit( const FnParseIterator& );
    void endVisit  ( const FnParseIterator& );
    void beginVisit( const CodepointsToStringIterator& );
    void endVisit  ( const CodepointsToStringIterator& );

    void beginVisit( const StringToCodepointsIterator& );
    void endVisit  ( const StringToCodepointsIterator& );

    void beginVisit( const CompareStrIterator& );
    void endVisit  ( const CompareStrIterator& );

    void beginVisit( const CodepointEqualIterator& );
    void endVisit  ( const CodepointEqualIterator& );

    void beginVisit( const ConcatStrIterator& );
    void endVisit  ( const ConcatStrIterator& );

    void beginVisit( const StringJoinIterator& );
    void endVisit  ( const StringJoinIterator& );

    void beginVisit( const SubstringIterator& );
    void endVisit  ( const SubstringIterator& );

    void beginVisit( const StringLengthIterator& );
    void endVisit  ( const StringLengthIterator& );

    void beginVisit( const NormalizeSpaceIterator& );
    void endVisit  ( const NormalizeSpaceIterator& );

    void beginVisit( const NormalizeUnicodeIterator& );
    void endVisit  ( const NormalizeUnicodeIterator& );

    void beginVisit( const UpperCaseIterator& );
    void endVisit  ( const UpperCaseIterator& );

    void beginVisit( const LowerCaseIterator& );
    void endVisit  ( const LowerCaseIterator& );

    void beginVisit( const TranslateIterator& );
    void endVisit  ( const TranslateIterator& );

    void beginVisit( const EncodeForUriIterator& );
    void endVisit  ( const EncodeForUriIterator& );

    void beginVisit( const IriToUriIterator& );
    void endVisit  ( const IriToUriIterator& );

    void beginVisit( const EscapeHtmlUriIterator& );
    void endVisit  ( const EscapeHtmlUriIterator& );

    void beginVisit( const ContainsIterator& );
    void endVisit  ( const ContainsIterator& );

    void beginVisit( const StartsWithIterator& );
    void endVisit  ( const StartsWithIterator& );

    void beginVisit( const EndsWithIterator& );
    void endVisit  ( const EndsWithIterator& );

    void beginVisit( const SubstringBeforeIterator& );
    void endVisit  ( const SubstringBeforeIterator& );

    void beginVisit( const SubstringAfterIterator& );
    void endVisit  ( const SubstringAfterIterator& );

    void beginVisit( const FnMatchesIterator& );
    void endVisit  ( const FnMatchesIterator& );

    void beginVisit( const FnReplaceIterator& );
    void endVisit  ( const FnReplaceIterator& );

    void beginVisit( const FnTokenizeIterator& );
    void endVisit  ( const FnTokenizeIterator& );

  }; //class PrinterVisitor
} //namespace zorba


#endif
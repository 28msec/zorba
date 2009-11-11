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
    class NodeNameIterator;
    class NilledIterator;
    class FnStringIterator;
    class FnDataIterator;
    class BaseUriIterator;
    class DocumentUriIterator;
    class RootIterator;
    class IsSameNodeIterator;
    class NodeBeforeIterator;
    class NodeAfterIterator;
    class CurrentDateTimeIterator;
    class CurrentDateIterator;
    class CurrentTimeIterator;
    class ImplicitTimezoneIterator;
    class DefaultCollationIterator;
    class ZorbaJsonParseIterator;
    class ZorbaJsonSerializeIterator;
    class ZorbaJsonMLParseIterator;
    class ZorbaJsonMLSerializeIterator;
    class YearsFromDurationIterator;
    class MonthsFromDurationIterator;
    class DaysFromDurationIterator;
    class HoursFromDurationIterator;
    class MinutesFromDurationIterator;
    class SecondsFromDurationIterator;
    class YearFromDatetimeIterator;
    class MonthFromDatetimeIterator;
    class DayFromDatetimeIterator;
    class HoursFromDatetimeIterator;
    class MinutesFromDatetimeIterator;
    class SecondsFromDatetimeIterator;
    class TimezoneFromDatetimeIterator;
    class YearFromDateIterator;
    class MonthFromDateIterator;
    class DayFromDateIterator;
    class TimezoneFromDateIterator;
    class HoursFromTimeIterator;
    class MinutesFromTimeIterator;
    class SecondsFromTimeIterator;
    class TimezoneFromTimeIterator;
    class EvalIterator;
    class FnPutIterator;
    class FnSQRTIterator;
    class FnAtan2Iterator;
    class TraceIterator;
    class ReadLineIterator;
    class PrintIterator;
    class ResolveUriIterator;
    class ErrorIterator;
    class NodeReferenceIterator;
    class NodeByReferenceIterator;
    class FnLocalNameIterator;
    class FnNamespaceUriIterator;
    class FnLangIterator;
    class AbsIterator;
    class CeilingIterator;
    class FloorIterator;
    class RoundIterator;
    class RoundHalfToEvenIterator;
    class FormatNumberIterator;
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
    class CodepointsToStringIterator;
    class StringToCodepointsIterator;
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
    class FnTokenizeIterator;

#include "runtime/visitors/planiter_visitor_impl_include.h"
/**
 * Visitor to visit a PlanIterator tree.
 */
class PlanIterVisitor {
public:
  virtual ~PlanIterVisitor() {}

#include "runtime/visitors/planiter_visitor_impl_code.h"
    virtual void beginVisit ( const NodeNameIterator& ) = 0;
    virtual void endVisit   ( const NodeNameIterator& ) = 0;

    virtual void beginVisit ( const NilledIterator& ) = 0;
    virtual void endVisit   ( const NilledIterator& ) = 0;

    virtual void beginVisit ( const FnStringIterator& ) = 0;
    virtual void endVisit   ( const FnStringIterator& ) = 0;

    virtual void beginVisit ( const FnDataIterator& ) = 0;
    virtual void endVisit   ( const FnDataIterator& ) = 0;

    virtual void beginVisit ( const BaseUriIterator& ) = 0;
    virtual void endVisit   ( const BaseUriIterator& ) = 0;

    virtual void beginVisit ( const DocumentUriIterator& ) = 0;
    virtual void endVisit   ( const DocumentUriIterator& ) = 0;

    virtual void beginVisit ( const RootIterator& ) = 0;
    virtual void endVisit   ( const RootIterator& ) = 0;

    virtual void beginVisit ( const IsSameNodeIterator& ) = 0;
    virtual void endVisit   ( const IsSameNodeIterator& ) = 0;

    virtual void beginVisit ( const NodeBeforeIterator& ) = 0;
    virtual void endVisit   ( const NodeBeforeIterator& ) = 0;

    virtual void beginVisit ( const NodeAfterIterator& ) = 0;
    virtual void endVisit   ( const NodeAfterIterator& ) = 0;

    virtual void beginVisit ( const CurrentDateTimeIterator& ) = 0;
    virtual void endVisit   ( const CurrentDateTimeIterator& ) = 0;

    virtual void beginVisit ( const CurrentDateIterator& ) = 0;
    virtual void endVisit   ( const CurrentDateIterator& ) = 0;

    virtual void beginVisit ( const CurrentTimeIterator& ) = 0;
    virtual void endVisit   ( const CurrentTimeIterator& ) = 0;

    virtual void beginVisit ( const ImplicitTimezoneIterator& ) = 0;
    virtual void endVisit   ( const ImplicitTimezoneIterator& ) = 0;

    virtual void beginVisit ( const DefaultCollationIterator& ) = 0;
    virtual void endVisit   ( const DefaultCollationIterator& ) = 0;

    virtual void beginVisit ( const ZorbaJsonParseIterator& ) = 0;
    virtual void endVisit   ( const ZorbaJsonParseIterator& ) = 0;

    virtual void beginVisit ( const ZorbaJsonSerializeIterator& ) = 0;
    virtual void endVisit   ( const ZorbaJsonSerializeIterator& ) = 0;

    virtual void beginVisit ( const ZorbaJsonMLParseIterator& ) = 0;
    virtual void endVisit   ( const ZorbaJsonMLParseIterator& ) = 0;

    virtual void beginVisit ( const ZorbaJsonMLSerializeIterator& ) = 0;
    virtual void endVisit   ( const ZorbaJsonMLSerializeIterator& ) = 0;

    virtual void beginVisit ( const YearsFromDurationIterator& ) = 0;
    virtual void endVisit   ( const YearsFromDurationIterator& ) = 0;

    virtual void beginVisit ( const MonthsFromDurationIterator& ) = 0;
    virtual void endVisit   ( const MonthsFromDurationIterator& ) = 0;

    virtual void beginVisit ( const DaysFromDurationIterator& ) = 0;
    virtual void endVisit   ( const DaysFromDurationIterator& ) = 0;

    virtual void beginVisit ( const HoursFromDurationIterator& ) = 0;
    virtual void endVisit   ( const HoursFromDurationIterator& ) = 0;

    virtual void beginVisit ( const MinutesFromDurationIterator& ) = 0;
    virtual void endVisit   ( const MinutesFromDurationIterator& ) = 0;

    virtual void beginVisit ( const SecondsFromDurationIterator& ) = 0;
    virtual void endVisit   ( const SecondsFromDurationIterator& ) = 0;

    virtual void beginVisit ( const YearFromDatetimeIterator& ) = 0;
    virtual void endVisit   ( const YearFromDatetimeIterator& ) = 0;

    virtual void beginVisit ( const MonthFromDatetimeIterator& ) = 0;
    virtual void endVisit   ( const MonthFromDatetimeIterator& ) = 0;

    virtual void beginVisit ( const DayFromDatetimeIterator& ) = 0;
    virtual void endVisit   ( const DayFromDatetimeIterator& ) = 0;

    virtual void beginVisit ( const HoursFromDatetimeIterator& ) = 0;
    virtual void endVisit   ( const HoursFromDatetimeIterator& ) = 0;

    virtual void beginVisit ( const MinutesFromDatetimeIterator& ) = 0;
    virtual void endVisit   ( const MinutesFromDatetimeIterator& ) = 0;

    virtual void beginVisit ( const SecondsFromDatetimeIterator& ) = 0;
    virtual void endVisit   ( const SecondsFromDatetimeIterator& ) = 0;

    virtual void beginVisit ( const TimezoneFromDatetimeIterator& ) = 0;
    virtual void endVisit   ( const TimezoneFromDatetimeIterator& ) = 0;

    virtual void beginVisit ( const YearFromDateIterator& ) = 0;
    virtual void endVisit   ( const YearFromDateIterator& ) = 0;

    virtual void beginVisit ( const MonthFromDateIterator& ) = 0;
    virtual void endVisit   ( const MonthFromDateIterator& ) = 0;

    virtual void beginVisit ( const DayFromDateIterator& ) = 0;
    virtual void endVisit   ( const DayFromDateIterator& ) = 0;

    virtual void beginVisit ( const TimezoneFromDateIterator& ) = 0;
    virtual void endVisit   ( const TimezoneFromDateIterator& ) = 0;

    virtual void beginVisit ( const HoursFromTimeIterator& ) = 0;
    virtual void endVisit   ( const HoursFromTimeIterator& ) = 0;

    virtual void beginVisit ( const MinutesFromTimeIterator& ) = 0;
    virtual void endVisit   ( const MinutesFromTimeIterator& ) = 0;

    virtual void beginVisit ( const SecondsFromTimeIterator& ) = 0;
    virtual void endVisit   ( const SecondsFromTimeIterator& ) = 0;

    virtual void beginVisit ( const TimezoneFromTimeIterator& ) = 0;
    virtual void endVisit   ( const TimezoneFromTimeIterator& ) = 0;

    virtual void beginVisit ( const EvalIterator& ) = 0;
    virtual void endVisit   ( const EvalIterator& ) = 0;

    virtual void beginVisit ( const FnPutIterator& ) = 0;
    virtual void endVisit   ( const FnPutIterator& ) = 0;

    virtual void beginVisit ( const FnSQRTIterator& ) = 0;
    virtual void endVisit   ( const FnSQRTIterator& ) = 0;

    virtual void beginVisit ( const FnAtan2Iterator& ) = 0;
    virtual void endVisit   ( const FnAtan2Iterator& ) = 0;

    virtual void beginVisit ( const TraceIterator& ) = 0;
    virtual void endVisit   ( const TraceIterator& ) = 0;

    virtual void beginVisit ( const ReadLineIterator& ) = 0;
    virtual void endVisit   ( const ReadLineIterator& ) = 0;

    virtual void beginVisit ( const PrintIterator& ) = 0;
    virtual void endVisit   ( const PrintIterator& ) = 0;

    virtual void beginVisit ( const ResolveUriIterator& ) = 0;
    virtual void endVisit   ( const ResolveUriIterator& ) = 0;

    virtual void beginVisit ( const ErrorIterator& ) = 0;
    virtual void endVisit   ( const ErrorIterator& ) = 0;

    virtual void beginVisit ( const NodeReferenceIterator& ) = 0;
    virtual void endVisit   ( const NodeReferenceIterator& ) = 0;

    virtual void beginVisit ( const NodeByReferenceIterator& ) = 0;
    virtual void endVisit   ( const NodeByReferenceIterator& ) = 0;

    virtual void beginVisit ( const FnLocalNameIterator& ) = 0;
    virtual void endVisit   ( const FnLocalNameIterator& ) = 0;

    virtual void beginVisit ( const FnNamespaceUriIterator& ) = 0;
    virtual void endVisit   ( const FnNamespaceUriIterator& ) = 0;

    virtual void beginVisit ( const FnLangIterator& ) = 0;
    virtual void endVisit   ( const FnLangIterator& ) = 0;

    virtual void beginVisit ( const AbsIterator& ) = 0;
    virtual void endVisit   ( const AbsIterator& ) = 0;

    virtual void beginVisit ( const CeilingIterator& ) = 0;
    virtual void endVisit   ( const CeilingIterator& ) = 0;

    virtual void beginVisit ( const FloorIterator& ) = 0;
    virtual void endVisit   ( const FloorIterator& ) = 0;

    virtual void beginVisit ( const RoundIterator& ) = 0;
    virtual void endVisit   ( const RoundIterator& ) = 0;

    virtual void beginVisit ( const RoundHalfToEvenIterator& ) = 0;
    virtual void endVisit   ( const RoundHalfToEvenIterator& ) = 0;

    virtual void beginVisit ( const FormatNumberIterator& ) = 0;
    virtual void endVisit   ( const FormatNumberIterator& ) = 0;

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

    virtual void beginVisit ( const CodepointsToStringIterator& ) = 0;
    virtual void endVisit   ( const CodepointsToStringIterator& ) = 0;

    virtual void beginVisit ( const StringToCodepointsIterator& ) = 0;
    virtual void endVisit   ( const StringToCodepointsIterator& ) = 0;

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

    virtual void beginVisit ( const FnTokenizeIterator& ) = 0;
    virtual void endVisit   ( const FnTokenizeIterator& ) = 0;

  }; //class PlanIterVisitor
} //namespace zorba

#endif
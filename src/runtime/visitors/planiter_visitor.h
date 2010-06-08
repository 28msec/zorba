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

    class ResolveUriIterator;

    class Base64DecodeIterator;

    class Base64EncodeIterator;

    class IsSameNodeIterator;

    class NodeBeforeIterator;

    class NodeAfterIterator;

    class FnCollectionIterator;

    class ZorbaCollectionIterator;

    class ZorbaIndexOfIterator;

    class ZorbaCreateCollectionIterator;

    class ZorbaDeleteCollectionIterator;

    class ZorbaInsertNodesIterator;

    class ZorbaInsertNodesFirstIterator;

    class ZorbaInsertNodesLastIterator;

    class ZorbaInsertNodesBeforeIterator;

    class ZorbaInsertNodesAfterIterator;

    class ZorbaDeleteNodesIterator;

    class ZorbaDeleteNodesFirstIterator;

    class ZorbaDeleteNodesLastIterator;

    class CurrentDateTimeIterator;

    class CurrentDateIterator;

    class CurrentTimeIterator;

    class ImplicitTimezoneIterator;

    class DefaultCollationIterator;

    class ZorbaJsonParseIterator;

    class ZorbaJsonSerializeIterator;

    class ZorbaJsonParseMLIterator;

    class ZorbaJsonSerializeMLIterator;

    class ZorbaCSV2XMLIterator;

    class ZorbaTXT2XMLIterator;

    class ZorbaCSV2XMLFromFileIterator;

    class ZorbaTXT2XMLFromFileIterator;

    class ZorbaXML2CSVIterator;

    class ZorbaXML2CSVFILEIterator;

    class ZorbaXML2TXTIterator;

    class ZorbaXML2TXTFILEIterator;

    class TraceIterator;

    class ReadLineIterator;

    class PrintIterator;

    class ZorbaDebugIterator;

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

    class TimestampIterator;

    class EvalIterator;

    class ErrorIterator;

    class FnPutIterator;

    class FunctionNameIterator;

    class FunctionArityIterator;

    class ActivateICIterator;

    class DeactivateICIterator;

    class CheckICIterator;

    class IsAvailableCollectionIterator;

    class AvailableCollectionsIterator;

    class IsAvailableIndexIterator;

    class AvailableIndexesIterator;

    class IsActivatedICIterator;

    class ActivatedICsIterator;

    class IsDeclaredCollectionIterator;

    class DeclaredCollectionsIterator;

    class IsDeclaredIndexIterator;

    class DeclaredIndexesIterator;

    class StaticNamespacesIterator;

    class StaticNamespaceBindingIterator;

    class InscopeVariablesIterator;

    class DefaultCollectionTypeIterator;

    class XPath10CompatModeIterator;

    class StaticallyKnownDocumentsIterator;

    class StaticallyKnownDocumentTypeIterator;

    class StaticallyKnownCollationsIterator;

    class ConstructionModeIterator;

    class OrderingModeIterator;

    class DefaultOrderIterator;

    class BoundarySpacePolicyIterator;

    class CopyNamespacesModeIterator;

    class FunctionNamesIterator;

    class FunctionArgumentsCountIterator;

    class InScopeSchemaTypesIterator;

    class InScopeElementDeclarationsIterator;

    class InScopeAttributeDeclarationsIterator;

    class InScopeElementGroupsIterator;

    class InScopeAttributeGroupsIterator;

    class IsDeclaredICIterator;

    class DeclaredICsIterator;

    class OptionIterator;

    class SqrtIterator;

    class ExpIterator;

    class LogIterator;

    class SinIterator;

    class CosIterator;

    class TanIterator;

    class ArcSinIterator;

    class ArcCosIterator;

    class ArcTanIterator;

    class Atan2Iterator;

    class CoshIterator;

    class AcoshIterator;

    class FmodIterator;

    class LdexpIterator;

    class Log10Iterator;

    class PowIterator;

    class SinhIterator;

    class AsinhIterator;

    class TanhIterator;

    class AtanhIterator;

    class PiNumberIterator;

    class IsInfIterator;

    class IsNaNIterator;

    class ModfIterator;

    class FrexpIterator;

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

    class ResolveQNameIterator;

    class QNameIterator;

    class QNameEqualIterator;

    class PrefixFromQNameIterator;

    class LocalNameFromQNameIterator;

    class NamespaceUriFromQNameIterator;

    class NamespaceUriForPrefixIterator;

    class InScopePrefixesIterator;

    class NumGenIterator;

    class RandomIterator;

    class UuidIterator;

#ifndef ZORBA_NO_XMLSCHEMA
    class ValidateIterator;
#endif
    class ZorbaSchemaTypeIterator;

    class SequentialIterator;

    class LoopIterator;

    class FlowCtlIterator;

    class FnConcatIterator;

    class FnIndexOfIterator;

    class FnEmptyIterator;

    class FnExistsIterator;

    class FnDistinctValuesIterator;

    class FnInsertBeforeIterator;

    class FnRemoveIterator;

    class FnReverseIterator;

    class FnSubsequenceIterator;

    class SubsequenceIntIterator;

    class SequencePointAccessIterator;

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

    class UtilsParseIterator;

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

    class XQDocIterator;


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

    virtual void beginVisit ( const ResolveUriIterator& ) = 0;
    virtual void endVisit   ( const ResolveUriIterator& ) = 0;

    virtual void beginVisit ( const Base64DecodeIterator& ) = 0;
    virtual void endVisit   ( const Base64DecodeIterator& ) = 0;

    virtual void beginVisit ( const Base64EncodeIterator& ) = 0;
    virtual void endVisit   ( const Base64EncodeIterator& ) = 0;

    virtual void beginVisit ( const IsSameNodeIterator& ) = 0;
    virtual void endVisit   ( const IsSameNodeIterator& ) = 0;

    virtual void beginVisit ( const NodeBeforeIterator& ) = 0;
    virtual void endVisit   ( const NodeBeforeIterator& ) = 0;

    virtual void beginVisit ( const NodeAfterIterator& ) = 0;
    virtual void endVisit   ( const NodeAfterIterator& ) = 0;

    virtual void beginVisit ( const FnCollectionIterator& ) = 0;
    virtual void endVisit   ( const FnCollectionIterator& ) = 0;

    virtual void beginVisit ( const ZorbaCollectionIterator& ) = 0;
    virtual void endVisit   ( const ZorbaCollectionIterator& ) = 0;

    virtual void beginVisit ( const ZorbaIndexOfIterator& ) = 0;
    virtual void endVisit   ( const ZorbaIndexOfIterator& ) = 0;

    virtual void beginVisit ( const ZorbaCreateCollectionIterator& ) = 0;
    virtual void endVisit   ( const ZorbaCreateCollectionIterator& ) = 0;

    virtual void beginVisit ( const ZorbaDeleteCollectionIterator& ) = 0;
    virtual void endVisit   ( const ZorbaDeleteCollectionIterator& ) = 0;

    virtual void beginVisit ( const ZorbaInsertNodesIterator& ) = 0;
    virtual void endVisit   ( const ZorbaInsertNodesIterator& ) = 0;

    virtual void beginVisit ( const ZorbaInsertNodesFirstIterator& ) = 0;
    virtual void endVisit   ( const ZorbaInsertNodesFirstIterator& ) = 0;

    virtual void beginVisit ( const ZorbaInsertNodesLastIterator& ) = 0;
    virtual void endVisit   ( const ZorbaInsertNodesLastIterator& ) = 0;

    virtual void beginVisit ( const ZorbaInsertNodesBeforeIterator& ) = 0;
    virtual void endVisit   ( const ZorbaInsertNodesBeforeIterator& ) = 0;

    virtual void beginVisit ( const ZorbaInsertNodesAfterIterator& ) = 0;
    virtual void endVisit   ( const ZorbaInsertNodesAfterIterator& ) = 0;

    virtual void beginVisit ( const ZorbaDeleteNodesIterator& ) = 0;
    virtual void endVisit   ( const ZorbaDeleteNodesIterator& ) = 0;

    virtual void beginVisit ( const ZorbaDeleteNodesFirstIterator& ) = 0;
    virtual void endVisit   ( const ZorbaDeleteNodesFirstIterator& ) = 0;

    virtual void beginVisit ( const ZorbaDeleteNodesLastIterator& ) = 0;
    virtual void endVisit   ( const ZorbaDeleteNodesLastIterator& ) = 0;

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

    virtual void beginVisit ( const ZorbaJsonParseMLIterator& ) = 0;
    virtual void endVisit   ( const ZorbaJsonParseMLIterator& ) = 0;

    virtual void beginVisit ( const ZorbaJsonSerializeMLIterator& ) = 0;
    virtual void endVisit   ( const ZorbaJsonSerializeMLIterator& ) = 0;

    virtual void beginVisit ( const ZorbaCSV2XMLIterator& ) = 0;
    virtual void endVisit   ( const ZorbaCSV2XMLIterator& ) = 0;

    virtual void beginVisit ( const ZorbaTXT2XMLIterator& ) = 0;
    virtual void endVisit   ( const ZorbaTXT2XMLIterator& ) = 0;

    virtual void beginVisit ( const ZorbaCSV2XMLFromFileIterator& ) = 0;
    virtual void endVisit   ( const ZorbaCSV2XMLFromFileIterator& ) = 0;

    virtual void beginVisit ( const ZorbaTXT2XMLFromFileIterator& ) = 0;
    virtual void endVisit   ( const ZorbaTXT2XMLFromFileIterator& ) = 0;

    virtual void beginVisit ( const ZorbaXML2CSVIterator& ) = 0;
    virtual void endVisit   ( const ZorbaXML2CSVIterator& ) = 0;

    virtual void beginVisit ( const ZorbaXML2CSVFILEIterator& ) = 0;
    virtual void endVisit   ( const ZorbaXML2CSVFILEIterator& ) = 0;

    virtual void beginVisit ( const ZorbaXML2TXTIterator& ) = 0;
    virtual void endVisit   ( const ZorbaXML2TXTIterator& ) = 0;

    virtual void beginVisit ( const ZorbaXML2TXTFILEIterator& ) = 0;
    virtual void endVisit   ( const ZorbaXML2TXTFILEIterator& ) = 0;

    virtual void beginVisit ( const TraceIterator& ) = 0;
    virtual void endVisit   ( const TraceIterator& ) = 0;

    virtual void beginVisit ( const ReadLineIterator& ) = 0;
    virtual void endVisit   ( const ReadLineIterator& ) = 0;

    virtual void beginVisit ( const PrintIterator& ) = 0;
    virtual void endVisit   ( const PrintIterator& ) = 0;

    virtual void beginVisit ( const ZorbaDebugIterator& ) = 0;
    virtual void endVisit   ( const ZorbaDebugIterator& ) = 0;

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

    virtual void beginVisit ( const TimestampIterator& ) = 0;
    virtual void endVisit   ( const TimestampIterator& ) = 0;

    virtual void beginVisit ( const EvalIterator& ) = 0;
    virtual void endVisit   ( const EvalIterator& ) = 0;

    virtual void beginVisit ( const ErrorIterator& ) = 0;
    virtual void endVisit   ( const ErrorIterator& ) = 0;

    virtual void beginVisit ( const FnPutIterator& ) = 0;
    virtual void endVisit   ( const FnPutIterator& ) = 0;

    virtual void beginVisit ( const FunctionNameIterator& ) = 0;
    virtual void endVisit   ( const FunctionNameIterator& ) = 0;

    virtual void beginVisit ( const FunctionArityIterator& ) = 0;
    virtual void endVisit   ( const FunctionArityIterator& ) = 0;

    virtual void beginVisit ( const ActivateICIterator& ) = 0;
    virtual void endVisit   ( const ActivateICIterator& ) = 0;

    virtual void beginVisit ( const DeactivateICIterator& ) = 0;
    virtual void endVisit   ( const DeactivateICIterator& ) = 0;

    virtual void beginVisit ( const CheckICIterator& ) = 0;
    virtual void endVisit   ( const CheckICIterator& ) = 0;

    virtual void beginVisit ( const IsAvailableCollectionIterator& ) = 0;
    virtual void endVisit   ( const IsAvailableCollectionIterator& ) = 0;

    virtual void beginVisit ( const AvailableCollectionsIterator& ) = 0;
    virtual void endVisit   ( const AvailableCollectionsIterator& ) = 0;

    virtual void beginVisit ( const IsAvailableIndexIterator& ) = 0;
    virtual void endVisit   ( const IsAvailableIndexIterator& ) = 0;

    virtual void beginVisit ( const AvailableIndexesIterator& ) = 0;
    virtual void endVisit   ( const AvailableIndexesIterator& ) = 0;

    virtual void beginVisit ( const IsActivatedICIterator& ) = 0;
    virtual void endVisit   ( const IsActivatedICIterator& ) = 0;

    virtual void beginVisit ( const ActivatedICsIterator& ) = 0;
    virtual void endVisit   ( const ActivatedICsIterator& ) = 0;

    virtual void beginVisit ( const IsDeclaredCollectionIterator& ) = 0;
    virtual void endVisit   ( const IsDeclaredCollectionIterator& ) = 0;

    virtual void beginVisit ( const DeclaredCollectionsIterator& ) = 0;
    virtual void endVisit   ( const DeclaredCollectionsIterator& ) = 0;

    virtual void beginVisit ( const IsDeclaredIndexIterator& ) = 0;
    virtual void endVisit   ( const IsDeclaredIndexIterator& ) = 0;

    virtual void beginVisit ( const DeclaredIndexesIterator& ) = 0;
    virtual void endVisit   ( const DeclaredIndexesIterator& ) = 0;

    virtual void beginVisit ( const StaticNamespacesIterator& ) = 0;
    virtual void endVisit   ( const StaticNamespacesIterator& ) = 0;

    virtual void beginVisit ( const StaticNamespaceBindingIterator& ) = 0;
    virtual void endVisit   ( const StaticNamespaceBindingIterator& ) = 0;

    virtual void beginVisit ( const InscopeVariablesIterator& ) = 0;
    virtual void endVisit   ( const InscopeVariablesIterator& ) = 0;

    virtual void beginVisit ( const DefaultCollectionTypeIterator& ) = 0;
    virtual void endVisit   ( const DefaultCollectionTypeIterator& ) = 0;

    virtual void beginVisit ( const XPath10CompatModeIterator& ) = 0;
    virtual void endVisit   ( const XPath10CompatModeIterator& ) = 0;

    virtual void beginVisit ( const StaticallyKnownDocumentsIterator& ) = 0;
    virtual void endVisit   ( const StaticallyKnownDocumentsIterator& ) = 0;

    virtual void beginVisit ( const StaticallyKnownDocumentTypeIterator& ) = 0;
    virtual void endVisit   ( const StaticallyKnownDocumentTypeIterator& ) = 0;

    virtual void beginVisit ( const StaticallyKnownCollationsIterator& ) = 0;
    virtual void endVisit   ( const StaticallyKnownCollationsIterator& ) = 0;

    virtual void beginVisit ( const ConstructionModeIterator& ) = 0;
    virtual void endVisit   ( const ConstructionModeIterator& ) = 0;

    virtual void beginVisit ( const OrderingModeIterator& ) = 0;
    virtual void endVisit   ( const OrderingModeIterator& ) = 0;

    virtual void beginVisit ( const DefaultOrderIterator& ) = 0;
    virtual void endVisit   ( const DefaultOrderIterator& ) = 0;

    virtual void beginVisit ( const BoundarySpacePolicyIterator& ) = 0;
    virtual void endVisit   ( const BoundarySpacePolicyIterator& ) = 0;

    virtual void beginVisit ( const CopyNamespacesModeIterator& ) = 0;
    virtual void endVisit   ( const CopyNamespacesModeIterator& ) = 0;

    virtual void beginVisit ( const FunctionNamesIterator& ) = 0;
    virtual void endVisit   ( const FunctionNamesIterator& ) = 0;

    virtual void beginVisit ( const FunctionArgumentsCountIterator& ) = 0;
    virtual void endVisit   ( const FunctionArgumentsCountIterator& ) = 0;

    virtual void beginVisit ( const InScopeSchemaTypesIterator& ) = 0;
    virtual void endVisit   ( const InScopeSchemaTypesIterator& ) = 0;

    virtual void beginVisit ( const InScopeElementDeclarationsIterator& ) = 0;
    virtual void endVisit   ( const InScopeElementDeclarationsIterator& ) = 0;

    virtual void beginVisit ( const InScopeAttributeDeclarationsIterator& ) = 0;
    virtual void endVisit   ( const InScopeAttributeDeclarationsIterator& ) = 0;

    virtual void beginVisit ( const InScopeElementGroupsIterator& ) = 0;
    virtual void endVisit   ( const InScopeElementGroupsIterator& ) = 0;

    virtual void beginVisit ( const InScopeAttributeGroupsIterator& ) = 0;
    virtual void endVisit   ( const InScopeAttributeGroupsIterator& ) = 0;

    virtual void beginVisit ( const IsDeclaredICIterator& ) = 0;
    virtual void endVisit   ( const IsDeclaredICIterator& ) = 0;

    virtual void beginVisit ( const DeclaredICsIterator& ) = 0;
    virtual void endVisit   ( const DeclaredICsIterator& ) = 0;

    virtual void beginVisit ( const OptionIterator& ) = 0;
    virtual void endVisit   ( const OptionIterator& ) = 0;

    virtual void beginVisit ( const SqrtIterator& ) = 0;
    virtual void endVisit   ( const SqrtIterator& ) = 0;

    virtual void beginVisit ( const ExpIterator& ) = 0;
    virtual void endVisit   ( const ExpIterator& ) = 0;

    virtual void beginVisit ( const LogIterator& ) = 0;
    virtual void endVisit   ( const LogIterator& ) = 0;

    virtual void beginVisit ( const SinIterator& ) = 0;
    virtual void endVisit   ( const SinIterator& ) = 0;

    virtual void beginVisit ( const CosIterator& ) = 0;
    virtual void endVisit   ( const CosIterator& ) = 0;

    virtual void beginVisit ( const TanIterator& ) = 0;
    virtual void endVisit   ( const TanIterator& ) = 0;

    virtual void beginVisit ( const ArcSinIterator& ) = 0;
    virtual void endVisit   ( const ArcSinIterator& ) = 0;

    virtual void beginVisit ( const ArcCosIterator& ) = 0;
    virtual void endVisit   ( const ArcCosIterator& ) = 0;

    virtual void beginVisit ( const ArcTanIterator& ) = 0;
    virtual void endVisit   ( const ArcTanIterator& ) = 0;

    virtual void beginVisit ( const Atan2Iterator& ) = 0;
    virtual void endVisit   ( const Atan2Iterator& ) = 0;

    virtual void beginVisit ( const CoshIterator& ) = 0;
    virtual void endVisit   ( const CoshIterator& ) = 0;

    virtual void beginVisit ( const AcoshIterator& ) = 0;
    virtual void endVisit   ( const AcoshIterator& ) = 0;

    virtual void beginVisit ( const FmodIterator& ) = 0;
    virtual void endVisit   ( const FmodIterator& ) = 0;

    virtual void beginVisit ( const LdexpIterator& ) = 0;
    virtual void endVisit   ( const LdexpIterator& ) = 0;

    virtual void beginVisit ( const Log10Iterator& ) = 0;
    virtual void endVisit   ( const Log10Iterator& ) = 0;

    virtual void beginVisit ( const PowIterator& ) = 0;
    virtual void endVisit   ( const PowIterator& ) = 0;

    virtual void beginVisit ( const SinhIterator& ) = 0;
    virtual void endVisit   ( const SinhIterator& ) = 0;

    virtual void beginVisit ( const AsinhIterator& ) = 0;
    virtual void endVisit   ( const AsinhIterator& ) = 0;

    virtual void beginVisit ( const TanhIterator& ) = 0;
    virtual void endVisit   ( const TanhIterator& ) = 0;

    virtual void beginVisit ( const AtanhIterator& ) = 0;
    virtual void endVisit   ( const AtanhIterator& ) = 0;

    virtual void beginVisit ( const PiNumberIterator& ) = 0;
    virtual void endVisit   ( const PiNumberIterator& ) = 0;

    virtual void beginVisit ( const IsInfIterator& ) = 0;
    virtual void endVisit   ( const IsInfIterator& ) = 0;

    virtual void beginVisit ( const IsNaNIterator& ) = 0;
    virtual void endVisit   ( const IsNaNIterator& ) = 0;

    virtual void beginVisit ( const ModfIterator& ) = 0;
    virtual void endVisit   ( const ModfIterator& ) = 0;

    virtual void beginVisit ( const FrexpIterator& ) = 0;
    virtual void endVisit   ( const FrexpIterator& ) = 0;

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

    virtual void beginVisit ( const ResolveQNameIterator& ) = 0;
    virtual void endVisit   ( const ResolveQNameIterator& ) = 0;

    virtual void beginVisit ( const QNameIterator& ) = 0;
    virtual void endVisit   ( const QNameIterator& ) = 0;

    virtual void beginVisit ( const QNameEqualIterator& ) = 0;
    virtual void endVisit   ( const QNameEqualIterator& ) = 0;

    virtual void beginVisit ( const PrefixFromQNameIterator& ) = 0;
    virtual void endVisit   ( const PrefixFromQNameIterator& ) = 0;

    virtual void beginVisit ( const LocalNameFromQNameIterator& ) = 0;
    virtual void endVisit   ( const LocalNameFromQNameIterator& ) = 0;

    virtual void beginVisit ( const NamespaceUriFromQNameIterator& ) = 0;
    virtual void endVisit   ( const NamespaceUriFromQNameIterator& ) = 0;

    virtual void beginVisit ( const NamespaceUriForPrefixIterator& ) = 0;
    virtual void endVisit   ( const NamespaceUriForPrefixIterator& ) = 0;

    virtual void beginVisit ( const InScopePrefixesIterator& ) = 0;
    virtual void endVisit   ( const InScopePrefixesIterator& ) = 0;

    virtual void beginVisit ( const NumGenIterator& ) = 0;
    virtual void endVisit   ( const NumGenIterator& ) = 0;

    virtual void beginVisit ( const RandomIterator& ) = 0;
    virtual void endVisit   ( const RandomIterator& ) = 0;

    virtual void beginVisit ( const UuidIterator& ) = 0;
    virtual void endVisit   ( const UuidIterator& ) = 0;

#ifndef ZORBA_NO_XMLSCHEMA
    virtual void beginVisit ( const ValidateIterator& ) = 0;
    virtual void endVisit   ( const ValidateIterator& ) = 0;
#endif
    virtual void beginVisit ( const ZorbaSchemaTypeIterator& ) = 0;
    virtual void endVisit   ( const ZorbaSchemaTypeIterator& ) = 0;

    virtual void beginVisit ( const SequentialIterator& ) = 0;
    virtual void endVisit   ( const SequentialIterator& ) = 0;

    virtual void beginVisit ( const LoopIterator& ) = 0;
    virtual void endVisit   ( const LoopIterator& ) = 0;

    virtual void beginVisit ( const FlowCtlIterator& ) = 0;
    virtual void endVisit   ( const FlowCtlIterator& ) = 0;

    virtual void beginVisit ( const FnConcatIterator& ) = 0;
    virtual void endVisit   ( const FnConcatIterator& ) = 0;

    virtual void beginVisit ( const FnIndexOfIterator& ) = 0;
    virtual void endVisit   ( const FnIndexOfIterator& ) = 0;

    virtual void beginVisit ( const FnEmptyIterator& ) = 0;
    virtual void endVisit   ( const FnEmptyIterator& ) = 0;

    virtual void beginVisit ( const FnExistsIterator& ) = 0;
    virtual void endVisit   ( const FnExistsIterator& ) = 0;

    virtual void beginVisit ( const FnDistinctValuesIterator& ) = 0;
    virtual void endVisit   ( const FnDistinctValuesIterator& ) = 0;

    virtual void beginVisit ( const FnInsertBeforeIterator& ) = 0;
    virtual void endVisit   ( const FnInsertBeforeIterator& ) = 0;

    virtual void beginVisit ( const FnRemoveIterator& ) = 0;
    virtual void endVisit   ( const FnRemoveIterator& ) = 0;

    virtual void beginVisit ( const FnReverseIterator& ) = 0;
    virtual void endVisit   ( const FnReverseIterator& ) = 0;

    virtual void beginVisit ( const FnSubsequenceIterator& ) = 0;
    virtual void endVisit   ( const FnSubsequenceIterator& ) = 0;

    virtual void beginVisit ( const SubsequenceIntIterator& ) = 0;
    virtual void endVisit   ( const SubsequenceIntIterator& ) = 0;

    virtual void beginVisit ( const SequencePointAccessIterator& ) = 0;
    virtual void endVisit   ( const SequencePointAccessIterator& ) = 0;

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

    virtual void beginVisit ( const UtilsParseIterator& ) = 0;
    virtual void endVisit   ( const UtilsParseIterator& ) = 0;

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

    virtual void beginVisit ( const XQDocIterator& ) = 0;
    virtual void endVisit   ( const XQDocIterator& ) = 0;

  }; //class PlanIterVisitor
} //namespace zorba

#endif
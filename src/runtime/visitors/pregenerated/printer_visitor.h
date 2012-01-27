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

    void beginVisit( const ResolveUriIterator& );
    void endVisit  ( const ResolveUriIterator& );

    void beginVisit( const Base64DecodeIterator& );
    void endVisit  ( const Base64DecodeIterator& );

    void beginVisit( const Base64EncodeIterator& );
    void endVisit  ( const Base64EncodeIterator& );

    void beginVisit( const IsSameNodeIterator& );
    void endVisit  ( const IsSameNodeIterator& );

    void beginVisit( const NodeBeforeIterator& );
    void endVisit  ( const NodeBeforeIterator& );

    void beginVisit( const NodeAfterIterator& );
    void endVisit  ( const NodeAfterIterator& );

    void beginVisit( const FnCollectionIterator& );
    void endVisit  ( const FnCollectionIterator& );

    void beginVisit( const ZorbaCollectionIterator& );
    void endVisit  ( const ZorbaCollectionIterator& );

    void beginVisit( const ZorbaIndexOfIterator& );
    void endVisit  ( const ZorbaIndexOfIterator& );

    void beginVisit( const ZorbaCreateCollectionIterator& );
    void endVisit  ( const ZorbaCreateCollectionIterator& );

    void beginVisit( const ZorbaDeleteCollectionIterator& );
    void endVisit  ( const ZorbaDeleteCollectionIterator& );

    void beginVisit( const ZorbaInsertNodesIterator& );
    void endVisit  ( const ZorbaInsertNodesIterator& );

    void beginVisit( const ZorbaInsertNodesFirstIterator& );
    void endVisit  ( const ZorbaInsertNodesFirstIterator& );

    void beginVisit( const ZorbaInsertNodesLastIterator& );
    void endVisit  ( const ZorbaInsertNodesLastIterator& );

    void beginVisit( const ZorbaInsertNodesBeforeIterator& );
    void endVisit  ( const ZorbaInsertNodesBeforeIterator& );

    void beginVisit( const ZorbaInsertNodesAfterIterator& );
    void endVisit  ( const ZorbaInsertNodesAfterIterator& );

    void beginVisit( const ZorbaApplyInsertNodesIterator& );
    void endVisit  ( const ZorbaApplyInsertNodesIterator& );

    void beginVisit( const ZorbaApplyInsertNodesFirstIterator& );
    void endVisit  ( const ZorbaApplyInsertNodesFirstIterator& );

    void beginVisit( const ZorbaApplyInsertNodesLastIterator& );
    void endVisit  ( const ZorbaApplyInsertNodesLastIterator& );

    void beginVisit( const ZorbaApplyInsertNodesBeforeIterator& );
    void endVisit  ( const ZorbaApplyInsertNodesBeforeIterator& );

    void beginVisit( const ZorbaApplyInsertNodesAfterIterator& );
    void endVisit  ( const ZorbaApplyInsertNodesAfterIterator& );

    void beginVisit( const ZorbaDeleteNodesIterator& );
    void endVisit  ( const ZorbaDeleteNodesIterator& );

    void beginVisit( const ZorbaDeleteNodesFirstIterator& );
    void endVisit  ( const ZorbaDeleteNodesFirstIterator& );

    void beginVisit( const ZorbaDeleteNodesLastIterator& );
    void endVisit  ( const ZorbaDeleteNodesLastIterator& );

    void beginVisit( const ZorbaCollectionNameIterator& );
    void endVisit  ( const ZorbaCollectionNameIterator& );

    void beginVisit( const IsAvailableCollectionIterator& );
    void endVisit  ( const IsAvailableCollectionIterator& );

    void beginVisit( const AvailableCollectionsIterator& );
    void endVisit  ( const AvailableCollectionsIterator& );

    void beginVisit( const IsAvailableIndexIterator& );
    void endVisit  ( const IsAvailableIndexIterator& );

    void beginVisit( const AvailableIndexesIterator& );
    void endVisit  ( const AvailableIndexesIterator& );

    void beginVisit( const IsActivatedICIterator& );
    void endVisit  ( const IsActivatedICIterator& );

    void beginVisit( const ActivatedICsIterator& );
    void endVisit  ( const ActivatedICsIterator& );

    void beginVisit( const IsDeclaredCollectionIterator& );
    void endVisit  ( const IsDeclaredCollectionIterator& );

    void beginVisit( const DeclaredCollectionsIterator& );
    void endVisit  ( const DeclaredCollectionsIterator& );

    void beginVisit( const IsDeclaredIndexIterator& );
    void endVisit  ( const IsDeclaredIndexIterator& );

    void beginVisit( const DeclaredIndexesIterator& );
    void endVisit  ( const DeclaredIndexesIterator& );

    void beginVisit( const IsDeclaredICIterator& );
    void endVisit  ( const IsDeclaredICIterator& );

    void beginVisit( const DeclaredICsIterator& );
    void endVisit  ( const DeclaredICsIterator& );

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

#ifdef ZORBA_WITH_DEBUGGER
    void beginVisit( const DebugIterator& );
    void endVisit  ( const DebugIterator& );
#endif

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

    void beginVisit( const ErrorIterator& );
    void endVisit  ( const ErrorIterator& );

    void beginVisit( const TraceIterator& );
    void endVisit  ( const TraceIterator& );

    void beginVisit( const ReadLineIterator& );
    void endVisit  ( const ReadLineIterator& );

    void beginVisit( const PrintIterator& );
    void endVisit  ( const PrintIterator& );

    void beginVisit( const FunctionTraceIterator& );
    void endVisit  ( const FunctionTraceIterator& );

    void beginVisit( const FetchContentIterator& );
    void endVisit  ( const FetchContentIterator& );

    void beginVisit( const FetchContentTypeIterator& );
    void endVisit  ( const FetchContentTypeIterator& );

    void beginVisit( const FnPutIterator& );
    void endVisit  ( const FnPutIterator& );

    void beginVisit( const FunctionNameIterator& );
    void endVisit  ( const FunctionNameIterator& );

    void beginVisit( const FunctionArityIterator& );
    void endVisit  ( const FunctionArityIterator& );

    void beginVisit( const PartialApplyIterator& );
    void endVisit  ( const PartialApplyIterator& );

    void beginVisit( const ActivateICIterator& );
    void endVisit  ( const ActivateICIterator& );

    void beginVisit( const DeactivateICIterator& );
    void endVisit  ( const DeactivateICIterator& );

    void beginVisit( const CheckICIterator& );
    void endVisit  ( const CheckICIterator& );

    void beginVisit( const StaticNamespacesIterator& );
    void endVisit  ( const StaticNamespacesIterator& );

    void beginVisit( const DefaultFunctionNamespaceIterator& );
    void endVisit  ( const DefaultFunctionNamespaceIterator& );

    void beginVisit( const SctxBaseUriIterator& );
    void endVisit  ( const SctxBaseUriIterator& );

    void beginVisit( const SctxDefaultCollationIterator& );
    void endVisit  ( const SctxDefaultCollationIterator& );

    void beginVisit( const StaticNamespaceBindingIterator& );
    void endVisit  ( const StaticNamespaceBindingIterator& );

    void beginVisit( const InscopeVariablesIterator& );
    void endVisit  ( const InscopeVariablesIterator& );

    void beginVisit( const DefaultCollectionTypeIterator& );
    void endVisit  ( const DefaultCollectionTypeIterator& );

    void beginVisit( const XPath10CompatModeIterator& );
    void endVisit  ( const XPath10CompatModeIterator& );

    void beginVisit( const StaticallyKnownDocumentsIterator& );
    void endVisit  ( const StaticallyKnownDocumentsIterator& );

    void beginVisit( const StaticallyKnownDocumentTypeIterator& );
    void endVisit  ( const StaticallyKnownDocumentTypeIterator& );

    void beginVisit( const StaticallyKnownCollationsIterator& );
    void endVisit  ( const StaticallyKnownCollationsIterator& );

    void beginVisit( const ConstructionModeIterator& );
    void endVisit  ( const ConstructionModeIterator& );

    void beginVisit( const OrderingModeIterator& );
    void endVisit  ( const OrderingModeIterator& );

    void beginVisit( const DefaultOrderIterator& );
    void endVisit  ( const DefaultOrderIterator& );

    void beginVisit( const BoundarySpacePolicyIterator& );
    void endVisit  ( const BoundarySpacePolicyIterator& );

    void beginVisit( const CopyNamespacesModeIterator& );
    void endVisit  ( const CopyNamespacesModeIterator& );

    void beginVisit( const FunctionNamesIterator& );
    void endVisit  ( const FunctionNamesIterator& );

    void beginVisit( const FunctionArgumentsCountIterator& );
    void endVisit  ( const FunctionArgumentsCountIterator& );

    void beginVisit( const InScopeSchemaTypesIterator& );
    void endVisit  ( const InScopeSchemaTypesIterator& );

    void beginVisit( const InScopeElementDeclarationsIterator& );
    void endVisit  ( const InScopeElementDeclarationsIterator& );

    void beginVisit( const InScopeAttributeDeclarationsIterator& );
    void endVisit  ( const InScopeAttributeDeclarationsIterator& );

    void beginVisit( const InScopeElementGroupsIterator& );
    void endVisit  ( const InScopeElementGroupsIterator& );

    void beginVisit( const InScopeAttributeGroupsIterator& );
    void endVisit  ( const InScopeAttributeGroupsIterator& );

    void beginVisit( const OptionIterator& );
    void endVisit  ( const OptionIterator& );

    void beginVisit( const FunctionAnnotationsIterator& );
    void endVisit  ( const FunctionAnnotationsIterator& );

    void beginVisit( const JSONParseInternal& );
    void endVisit  ( const JSONParseInternal& );

    void beginVisit( const JSONSerializeInternal& );
    void endVisit  ( const JSONSerializeInternal& );

#ifdef ZORBA_WITH_JSON
    void beginVisit( const JSONParseIterator& );
    void endVisit  ( const JSONParseIterator& );
#endif

#ifdef ZORBA_WITH_JSON
    void beginVisit( const JSONNameIterator& );
    void endVisit  ( const JSONNameIterator& );
#endif

#ifdef ZORBA_WITH_JSON
    void beginVisit( const JSONValueIterator& );
    void endVisit  ( const JSONValueIterator& );
#endif

#ifdef ZORBA_WITH_JSON
    void beginVisit( const JSONNamesIterator& );
    void endVisit  ( const JSONNamesIterator& );
#endif

#ifdef ZORBA_WITH_JSON
    void beginVisit( const JSONPairsIterator& );
    void endVisit  ( const JSONPairsIterator& );
#endif

#ifdef ZORBA_WITH_JSON
    void beginVisit( const JSONPairAccessorIterator& );
    void endVisit  ( const JSONPairAccessorIterator& );
#endif

#ifdef ZORBA_WITH_JSON
    void beginVisit( const JSONMemberAccessorIterator& );
    void endVisit  ( const JSONMemberAccessorIterator& );
#endif

#ifdef ZORBA_WITH_JSON
    void beginVisit( const JSONFlattenIterator& );
    void endVisit  ( const JSONFlattenIterator& );
#endif

#ifdef ZORBA_WITH_JSON
    void beginVisit( const JSONItemAccessorIterator& );
    void endVisit  ( const JSONItemAccessorIterator& );
#endif

#ifdef ZORBA_WITH_JSON
    void beginVisit( const JSONValuesIterator& );
    void endVisit  ( const JSONValuesIterator& );
#endif

#ifdef ZORBA_WITH_JSON
    void beginVisit( const JSONSizeIterator& );
    void endVisit  ( const JSONSizeIterator& );
#endif

    void beginVisit( const SqrtIterator& );
    void endVisit  ( const SqrtIterator& );

    void beginVisit( const ExpIterator& );
    void endVisit  ( const ExpIterator& );

    void beginVisit( const Exp10Iterator& );
    void endVisit  ( const Exp10Iterator& );

    void beginVisit( const LogIterator& );
    void endVisit  ( const LogIterator& );

    void beginVisit( const Log10Iterator& );
    void endVisit  ( const Log10Iterator& );

    void beginVisit( const SinIterator& );
    void endVisit  ( const SinIterator& );

    void beginVisit( const CosIterator& );
    void endVisit  ( const CosIterator& );

    void beginVisit( const TanIterator& );
    void endVisit  ( const TanIterator& );

    void beginVisit( const ArcSinIterator& );
    void endVisit  ( const ArcSinIterator& );

    void beginVisit( const ArcCosIterator& );
    void endVisit  ( const ArcCosIterator& );

    void beginVisit( const ArcTanIterator& );
    void endVisit  ( const ArcTanIterator& );

    void beginVisit( const Atan2Iterator& );
    void endVisit  ( const Atan2Iterator& );

    void beginVisit( const CoshIterator& );
    void endVisit  ( const CoshIterator& );

    void beginVisit( const AcoshIterator& );
    void endVisit  ( const AcoshIterator& );

    void beginVisit( const FmodIterator& );
    void endVisit  ( const FmodIterator& );

    void beginVisit( const LdexpIterator& );
    void endVisit  ( const LdexpIterator& );

    void beginVisit( const PowIterator& );
    void endVisit  ( const PowIterator& );

    void beginVisit( const SinhIterator& );
    void endVisit  ( const SinhIterator& );

    void beginVisit( const AsinhIterator& );
    void endVisit  ( const AsinhIterator& );

    void beginVisit( const TanhIterator& );
    void endVisit  ( const TanhIterator& );

    void beginVisit( const AtanhIterator& );
    void endVisit  ( const AtanhIterator& );

    void beginVisit( const PiNumberIterator& );
    void endVisit  ( const PiNumberIterator& );

    void beginVisit( const IsInfIterator& );
    void endVisit  ( const IsInfIterator& );

    void beginVisit( const IsNaNIterator& );
    void endVisit  ( const IsNaNIterator& );

    void beginVisit( const ModfIterator& );
    void endVisit  ( const ModfIterator& );

    void beginVisit( const FrexpIterator& );
    void endVisit  ( const FrexpIterator& );

    void beginVisit( const NodePositionIterator& );
    void endVisit  ( const NodePositionIterator& );

    void beginVisit( const IsAncestorPositionIterator& );
    void endVisit  ( const IsAncestorPositionIterator& );

    void beginVisit( const IsFollowingSiblingPositionIterator& );
    void endVisit  ( const IsFollowingSiblingPositionIterator& );

    void beginVisit( const IsFollowingPositionIterator& );
    void endVisit  ( const IsFollowingPositionIterator& );

    void beginVisit( const IsInSubtreeOfPositionIterator& );
    void endVisit  ( const IsInSubtreeOfPositionIterator& );

    void beginVisit( const IsDescendantPositionIterator& );
    void endVisit  ( const IsDescendantPositionIterator& );

    void beginVisit( const IsPrecedingSiblingPositionIterator& );
    void endVisit  ( const IsPrecedingSiblingPositionIterator& );

    void beginVisit( const IsPrecedingPositionIterator& );
    void endVisit  ( const IsPrecedingPositionIterator& );

    void beginVisit( const IsChildPositionIterator& );
    void endVisit  ( const IsChildPositionIterator& );

    void beginVisit( const IsAttributeOfPositionIterator& );
    void endVisit  ( const IsAttributeOfPositionIterator& );

    void beginVisit( const IsParentPositionIterator& );
    void endVisit  ( const IsParentPositionIterator& );

    void beginVisit( const IsPrecedingInDocumentOrderPositionIterator& );
    void endVisit  ( const IsPrecedingInDocumentOrderPositionIterator& );

    void beginVisit( const IsFollowingInDocumentOrderPositionIterator& );
    void endVisit  ( const IsFollowingInDocumentOrderPositionIterator& );

    void beginVisit( const LevelPositionIterator& );
    void endVisit  ( const LevelPositionIterator& );

    void beginVisit( const IsAttributePositionIterator& );
    void endVisit  ( const IsAttributePositionIterator& );

    void beginVisit( const IsCommentPositionIterator& );
    void endVisit  ( const IsCommentPositionIterator& );

    void beginVisit( const IsDocumentPositionIterator& );
    void endVisit  ( const IsDocumentPositionIterator& );

    void beginVisit( const IsElementPositionIterator& );
    void endVisit  ( const IsElementPositionIterator& );

    void beginVisit( const IsProcessingInstructionPositionIterator& );
    void endVisit  ( const IsProcessingInstructionPositionIterator& );

    void beginVisit( const IsTextPositionIterator& );
    void endVisit  ( const IsTextPositionIterator& );

    void beginVisit( const IsSiblingPositionIterator& );
    void endVisit  ( const IsSiblingPositionIterator& );

    void beginVisit( const InSameTreePositionIterator& );
    void endVisit  ( const InSameTreePositionIterator& );

    void beginVisit( const InCollectionPositionIterator& );
    void endVisit  ( const InCollectionPositionIterator& );

    void beginVisit( const InSameCollectionPositionIterator& );
    void endVisit  ( const InSameCollectionPositionIterator& );

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

    void beginVisit( const FnHasChildrenIterator& );
    void endVisit  ( const FnHasChildrenIterator& );

    void beginVisit( const FnInnermostIterator& );
    void endVisit  ( const FnInnermostIterator& );

    void beginVisit( const FnOutermostIterator& );
    void endVisit  ( const FnOutermostIterator& );

    void beginVisit( const FnGenerateIdIterator& );
    void endVisit  ( const FnGenerateIdIterator& );

    void beginVisit( const IsAncestorIterator& );
    void endVisit  ( const IsAncestorIterator& );

    void beginVisit( const IsDescendantIterator& );
    void endVisit  ( const IsDescendantIterator& );

    void beginVisit( const IsParentIterator& );
    void endVisit  ( const IsParentIterator& );

    void beginVisit( const IsChildIterator& );
    void endVisit  ( const IsChildIterator& );

    void beginVisit( const IsFollowingIterator& );
    void endVisit  ( const IsFollowingIterator& );

    void beginVisit( const IsPrecedingIterator& );
    void endVisit  ( const IsPrecedingIterator& );

    void beginVisit( const IsFollowingSiblingIterator& );
    void endVisit  ( const IsFollowingSiblingIterator& );

    void beginVisit( const IsPrecedingSiblingIterator& );
    void endVisit  ( const IsPrecedingSiblingIterator& );

    void beginVisit( const LevelIterator& );
    void endVisit  ( const LevelIterator& );

    void beginVisit( const LeastCommonAncestor& );
    void endVisit  ( const LeastCommonAncestor& );

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

    void beginVisit( const FormatIntegerIterator& );
    void endVisit  ( const FormatIntegerIterator& );

    void beginVisit( const FnParseXmlFragmentIterator& );
    void endVisit  ( const FnParseXmlFragmentIterator& );

    void beginVisit( const FnParseXmlIterator& );
    void endVisit  ( const FnParseXmlIterator& );

    void beginVisit( const FnSerializeIterator& );
    void endVisit  ( const FnSerializeIterator& );

    void beginVisit( const ResolveQNameIterator& );
    void endVisit  ( const ResolveQNameIterator& );

    void beginVisit( const QNameIterator& );
    void endVisit  ( const QNameIterator& );

    void beginVisit( const QNameEqualIterator& );
    void endVisit  ( const QNameEqualIterator& );

    void beginVisit( const PrefixFromQNameIterator& );
    void endVisit  ( const PrefixFromQNameIterator& );

    void beginVisit( const LocalNameFromQNameIterator& );
    void endVisit  ( const LocalNameFromQNameIterator& );

    void beginVisit( const NamespaceUriFromQNameIterator& );
    void endVisit  ( const NamespaceUriFromQNameIterator& );

    void beginVisit( const NamespaceUriForPrefixIterator& );
    void endVisit  ( const NamespaceUriForPrefixIterator& );

    void beginVisit( const InScopePrefixesIterator& );
    void endVisit  ( const InScopePrefixesIterator& );

    void beginVisit( const SeededRandomIterator& );
    void endVisit  ( const SeededRandomIterator& );

    void beginVisit( const RandomIterator& );
    void endVisit  ( const RandomIterator& );

    void beginVisit( const UuidIterator& );
    void endVisit  ( const UuidIterator& );

#ifndef ZORBA_NO_XMLSCHEMA
    void beginVisit( const ValidateIterator& );
    void endVisit  ( const ValidateIterator& );
#endif

    void beginVisit( const ZorbaValidateInPlaceIterator& );
    void endVisit  ( const ZorbaValidateInPlaceIterator& );

    void beginVisit( const ZorbaSchemaTypeIterator& );
    void endVisit  ( const ZorbaSchemaTypeIterator& );

    void beginVisit( const ZorbaIsValidatedIterator& );
    void endVisit  ( const ZorbaIsValidatedIterator& );

    void beginVisit( const FnConcatIterator& );
    void endVisit  ( const FnConcatIterator& );

    void beginVisit( const FnIndexOfIterator& );
    void endVisit  ( const FnIndexOfIterator& );

    void beginVisit( const FnEmptyIterator& );
    void endVisit  ( const FnEmptyIterator& );

    void beginVisit( const FnExistsIterator& );
    void endVisit  ( const FnExistsIterator& );

    void beginVisit( const FnDistinctValuesIterator& );
    void endVisit  ( const FnDistinctValuesIterator& );

    void beginVisit( const FnInsertBeforeIterator& );
    void endVisit  ( const FnInsertBeforeIterator& );

    void beginVisit( const FnRemoveIterator& );
    void endVisit  ( const FnRemoveIterator& );

    void beginVisit( const FnReverseIterator& );
    void endVisit  ( const FnReverseIterator& );

    void beginVisit( const FnSubsequenceIterator& );
    void endVisit  ( const FnSubsequenceIterator& );

    void beginVisit( const SubsequenceIntIterator& );
    void endVisit  ( const SubsequenceIntIterator& );

    void beginVisit( const SequencePointAccessIterator& );
    void endVisit  ( const SequencePointAccessIterator& );

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

    void beginVisit( const FnIdIterator& );
    void endVisit  ( const FnIdIterator& );

    void beginVisit( const FnElementWithIdIterator& );
    void endVisit  ( const FnElementWithIdIterator& );

    void beginVisit( const FnIdRefIterator& );
    void endVisit  ( const FnIdRefIterator& );

    void beginVisit( const FnDocIterator& );
    void endVisit  ( const FnDocIterator& );

    void beginVisit( const FnDocAvailableIterator& );
    void endVisit  ( const FnDocAvailableIterator& );

    void beginVisit( const PutDocumentIterator& );
    void endVisit  ( const PutDocumentIterator& );

    void beginVisit( const RemoveDocumentIterator& );
    void endVisit  ( const RemoveDocumentIterator& );

    void beginVisit( const RetrieveDocumentIterator& );
    void endVisit  ( const RetrieveDocumentIterator& );

    void beginVisit( const AvailableDocumentsIterator& );
    void endVisit  ( const AvailableDocumentsIterator& );

    void beginVisit( const IsAvailableDocumentIterator& );
    void endVisit  ( const IsAvailableDocumentIterator& );

    void beginVisit( const MapCreateIterator& );
    void endVisit  ( const MapCreateIterator& );

    void beginVisit( const MapDestroyIterator& );
    void endVisit  ( const MapDestroyIterator& );

    void beginVisit( const MapGetIterator& );
    void endVisit  ( const MapGetIterator& );

    void beginVisit( const MapInsertIterator& );
    void endVisit  ( const MapInsertIterator& );

    void beginVisit( const MapRemoveIterator& );
    void endVisit  ( const MapRemoveIterator& );

    void beginVisit( const MapKeysIterator& );
    void endVisit  ( const MapKeysIterator& );

    void beginVisit( const MapSizeIterator& );
    void endVisit  ( const MapSizeIterator& );

    void beginVisit( const AvailableMapsIterator& );
    void endVisit  ( const AvailableMapsIterator& );

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

    void beginVisit( const SubstringIntOptIterator& );
    void endVisit  ( const SubstringIntOptIterator& );

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

    void beginVisit( const FnAnalyzeStringIterator& );
    void endVisit  ( const FnAnalyzeStringIterator& );

    void beginVisit( const StringMaterializeIterator& );
    void endVisit  ( const StringMaterializeIterator& );

    void beginVisit( const StringIsStreamableIterator& );
    void endVisit  ( const StringIsStreamableIterator& );

    void beginVisit( const StringSplitIterator& );
    void endVisit  ( const StringSplitIterator& );

    void beginVisit( const XQDocIterator& );
    void endVisit  ( const XQDocIterator& );

    void beginVisit( const XQDocContentIterator& );
    void endVisit  ( const XQDocContentIterator& );

  }; //class PrinterVisitor
} //namespace zorba


#endif
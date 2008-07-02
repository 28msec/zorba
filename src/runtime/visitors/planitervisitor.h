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
#ifndef ZORBA_PLANITERVISITOR_H
#define ZORBA_PLANITERVISITOR_H

#include "common/common.h"

namespace zorba
{
  class xqpStringStore;

  class PlanIterator;
  class SequentialIterator;
  class FlowCtlIterator;
  class FnDataIterator;
  class FnRootIterator;
  class FnNodeNameIterator;
  class FnNilledIterator;
  class FnBaseUriIterator;
  class FnDocumentUriIterator;
  class FnErrorIterator;
  class FnResolveUriIterator;
  class FnStringIterator;
  class FnBooleanIterator;
#ifndef ZORBA_NO_XMLSCHEMA
  class ValidateIterator;
#endif
  class LogicIterator;
  class CompareIterator;
  class UDFunctionCallIterator;
  class StatelessExtFunctionCallIterator;
  class ElementIterator;
  class AttributeIterator;
  class CommentIterator;
  class PiIterator;
  class RefIterator;
  class SingletonIterator;
  class EmptyIterator;
  class ForVarIterator;
  class LetVarIterator;
  class EnclosedIterator;
  class IfThenElseIterator;
  class FLWORIterator;
  class TryCatchIterator;
  class NodeDistinctIterator;
  class NodeSortIterator;
  template <class Object, class State> class AxisIterator;
  class SelfAxisIterator;
  class AttributeAxisIterator;
  class ParentAxisIterator;
  class AncestorAxisIterator;
  class AncestorSelfAxisIterator;
  class RSiblingAxisIterator;
  class LSiblingAxisIterator;
  class ChildAxisIterator;
  class DescendantAxisIterator;
  class DescendantSelfAxisIterator;
  class PrecedingAxisIterator;
  class FollowingAxisIterator;
  class InstanceOfIterator;
  class TreatIterator;
  class EitherNodesOrAtomicsIterator;
  class AddOperation;
  class SubtractOperation;
  class MultiplyOperation;
  class DivideOperation;
  class IntegerDivideOperation;
  class ModOperation;
  template < class AddOperation> class NumArithIterator;
  template < class SubtractOperation> class NumArithIterator;
  template < class MultiplyOperation> class NumArithIterator;
  template < class DivideOperation> class NumArithIterator;
  template < class IntegerDivideOperation> class NumArithIterator;
  template < class ModOperation> class NumArithIterator;
  template < class AddOperation> class GenericArithIterator;
  template < class SubtractOperation> class GenericArithIterator;
  template < class MultiplyOperation> class GenericArithIterator;
  template < class DivideOperation> class GenericArithIterator;
  template < class IntegerDivideOperation> class GenericArithIterator;
  template < class ModOperation> class GenericArithIterator;
  class OpNumericUnaryIterator;
  class FnAbsIterator;
  class FnCeilingIterator;
  class FnFloorIterator;
  class FnRoundIterator;
  class FnRoundHalfToEvenIterator;
  class FnSQRTIterator;
  class FnExpIterator;
  class FnLogIterator;
  class FnSinIterator;
  class FnCosIterator;
  class FnTanIterator;
  class FnArcSinIterator;
  class FnArcCosIterator;
  class FnArcTanIterator;
  class FnConcatIterator;
  class FnEmptyIterator;
  class FnExistsIterator;
  class FnIndexOfIterator;
  class FnRemoveIterator;
  class FnReverseIterator;
  class OpToIterator;
  class FnIdIterator;
  class FnIdRefIterator;
  class FnDistinctValuesIterator;
  class FnInsertBeforeIterator;  
  class FnSubsequenceIterator;
  class FnZeroOrOneIterator;
  class FnOneOrMoreIterator;
  class FnExactlyOneIterator;
  class FnCountIterator;
  class FnAvgIterator;
  class FnMinMaxIterator;
  class FnSumIterator;
  class FnDocIterator;
  class FnDocAvailableIterator;
  class HashSemiJoinIterator;
  class SortSemiJoinIterator;
  class FnTraceIterator;
  class ResolveQNameIterator;
  class QNameIterator;
  class QNameEqualIterator;
  class PrefixFromQNameIterator;
  class LocalNameFromQNameIterator;
  class NamespaceUriFromQNameIterator;
  class NamespaceUriForPrefixlIterator;
  class InScopePrefixesIterator;
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
  class ZorNumGen;
  class TextIterator;
  class DocumentIterator;
  class DocumentContentIterator;
  class CastIterator;
  class NameCastIterator;
  class CastableIterator;
  class PromoteIterator;
  class CtxVariableIterator;
  class CtxVarAssignIterator;
  class EvalIterator;
  class FnDateTimeConstructorIterator;
  class FnYearsFromDurationIterator;
  class FnMonthsFromDurationIterator;
  class FnDaysFromDurationIterator;
  class FnHoursFromDurationIterator;
  class FnMinutesFromDurationIterator;
  class FnSecondsFromDurationIterator;
  class FnYearFromDatetimeIterator;
  class FnMonthFromDatetimeIterator;
  class FnDayFromDatetimeIterator;
  class FnHoursFromDatetimeIterator;
  class FnMinutesFromDatetimeIterator;
  class FnSecondsFromDatetimeIterator;
  class FnTimezoneFromDatetimeIterator;
  class FnYearFromDateIterator;
  class FnMonthFromDateIterator;
  class FnDayFromDateIterator;
  class FnTimezoneFromDateIterator;
  class FnHoursFromTimeIterator;
  class FnMinutesFromTimeIterator;
  class FnSecondsFromTimeIterator;
  class FnTimezoneFromTimeIterator;
  class FnAdjustToTimeZoneIterator_1;
  class FnAdjustToTimeZoneIterator_2;
  class OpIsSameNodeIterator;
  class OpNodeBeforeIterator;
  class OpNodeAfterIterator;
  class FnCurrentDateTimeIterator;
  class FnCurrentDateIterator;
  class FnCurrentTimeIterator;
  class FnImplicitTimezoneIterator;
  class FnDefaultCollationIterator;
  class InsertIterator;
  class DeleteIterator;
  class ReplaceIterator;
  class RenameIterator;
  class TransformIterator;
  class NodeReferenceIterator;
  class NodeByReferenceIterator;
  class FnLocalNameIterator;
  class FnNamespaceUriIterator;
  class FnLangIterator;
  class FnCollectionIterator;
  class FnDeepEqualIterator;

#ifdef ZORBA_DEBUGGER
  class FnDebugIterator;
#endif

#ifdef ZORBA_WITH_REST
  class ZorbaRestGetIterator;
  class ZorbaRestPostIterator;
#endif

#define PLAN_ITER_VISITOR(class)                  \
  virtual void beginVisit ( const class& ) = 0;  \
  virtual void endVisit ( const class& ) = 0

  
  /**
   * Visitor to visit a PlanIterator tree.
   */
  class PlanIterVisitor
  {
  public:
    virtual ~PlanIterVisitor() {}

    PLAN_ITER_VISITOR(NodeReferenceIterator);

    PLAN_ITER_VISITOR(NodeByReferenceIterator);
    
    PLAN_ITER_VISITOR (SequentialIterator);

    PLAN_ITER_VISITOR (FlowCtlIterator);

    PLAN_ITER_VISITOR (FnDataIterator);
       
    PLAN_ITER_VISITOR (FnRootIterator);
       
    PLAN_ITER_VISITOR (FnNodeNameIterator);

    PLAN_ITER_VISITOR (FnNilledIterator);

    PLAN_ITER_VISITOR (FnBaseUriIterator);

    PLAN_ITER_VISITOR (FnDocumentUriIterator);

    PLAN_ITER_VISITOR (FnResolveUriIterator);

    PLAN_ITER_VISITOR (FnStringIterator);

    PLAN_ITER_VISITOR (FnLocalNameIterator);

    PLAN_ITER_VISITOR (FnNamespaceUriIterator);

    PLAN_ITER_VISITOR (FnLangIterator);

    PLAN_ITER_VISITOR (FnCollectionIterator);

    PLAN_ITER_VISITOR (FnErrorIterator);
       
    PLAN_ITER_VISITOR (FnBooleanIterator);

#ifndef ZORBA_NO_XMLSCHEMA
    PLAN_ITER_VISITOR (ValidateIterator);
#endif
       
    PLAN_ITER_VISITOR (LogicIterator);
       
    PLAN_ITER_VISITOR (CompareIterator);
       
    PLAN_ITER_VISITOR (ElementIterator);
       
    PLAN_ITER_VISITOR (AttributeIterator );
      
    PLAN_ITER_VISITOR (DocumentIterator);
      
    PLAN_ITER_VISITOR (DocumentContentIterator);
       
    PLAN_ITER_VISITOR (UDFunctionCallIterator);
       
    PLAN_ITER_VISITOR (StatelessExtFunctionCallIterator);
       
    PLAN_ITER_VISITOR (CommentIterator);
       
    PLAN_ITER_VISITOR (PiIterator);
       
    PLAN_ITER_VISITOR (SingletonIterator);

    PLAN_ITER_VISITOR (EmptyIterator);
       
    PLAN_ITER_VISITOR (ForVarIterator);
       
    PLAN_ITER_VISITOR (LetVarIterator);

    PLAN_ITER_VISITOR (EnclosedIterator);
      
    PLAN_ITER_VISITOR (IfThenElseIterator);
       
    PLAN_ITER_VISITOR (FLWORIterator);
 
    PLAN_ITER_VISITOR (TryCatchIterator);

    PLAN_ITER_VISITOR (NodeDistinctIterator);

    PLAN_ITER_VISITOR (NodeSortIterator);

    PLAN_ITER_VISITOR (SelfAxisIterator);
       
    PLAN_ITER_VISITOR (AttributeAxisIterator);
       
    PLAN_ITER_VISITOR (ParentAxisIterator);
       
    PLAN_ITER_VISITOR (AncestorAxisIterator);
       
    PLAN_ITER_VISITOR (AncestorSelfAxisIterator);
       
    PLAN_ITER_VISITOR (RSiblingAxisIterator);
       
    PLAN_ITER_VISITOR (LSiblingAxisIterator);
       
    PLAN_ITER_VISITOR (ChildAxisIterator);
       
    PLAN_ITER_VISITOR (DescendantAxisIterator);
       
    PLAN_ITER_VISITOR (DescendantSelfAxisIterator);
       
    PLAN_ITER_VISITOR (PrecedingAxisIterator);
       
    PLAN_ITER_VISITOR (FollowingAxisIterator);

    PLAN_ITER_VISITOR (InstanceOfIterator);
       
    PLAN_ITER_VISITOR (TreatIterator);
    PLAN_ITER_VISITOR (EitherNodesOrAtomicsIterator);
              
    virtual void beginVisit ( const NumArithIterator<AddOperation>& ) = 0;
    virtual void beginVisit ( const NumArithIterator<SubtractOperation>& ) = 0;
    virtual void beginVisit ( const NumArithIterator<MultiplyOperation>& ) = 0;
    virtual void beginVisit ( const NumArithIterator<DivideOperation>& ) = 0;
    virtual void beginVisit ( const NumArithIterator<IntegerDivideOperation>& ) = 0;
    virtual void beginVisit ( const NumArithIterator<ModOperation>& ) = 0;
    virtual void endVisit ( const NumArithIterator<AddOperation>& ) = 0;
    virtual void endVisit ( const NumArithIterator<SubtractOperation>& ) = 0;
    virtual void endVisit ( const NumArithIterator<MultiplyOperation>& ) = 0;
    virtual void endVisit ( const NumArithIterator<DivideOperation>& ) = 0;
    virtual void endVisit ( const NumArithIterator<IntegerDivideOperation>& ) = 0;
    virtual void endVisit ( const NumArithIterator<ModOperation>& ) = 0;
    
    virtual void beginVisit ( const GenericArithIterator<AddOperation>& ) = 0;
    virtual void beginVisit ( const GenericArithIterator<SubtractOperation>& ) = 0;
    virtual void beginVisit ( const GenericArithIterator<MultiplyOperation>& ) = 0;
    virtual void beginVisit ( const GenericArithIterator<DivideOperation>& ) = 0;
    virtual void beginVisit ( const GenericArithIterator<IntegerDivideOperation>& ) = 0;
    virtual void beginVisit ( const GenericArithIterator<ModOperation>& ) = 0;
    virtual void endVisit ( const GenericArithIterator<AddOperation>& ) = 0;
    virtual void endVisit ( const GenericArithIterator<SubtractOperation>& ) = 0;
    virtual void endVisit ( const GenericArithIterator<MultiplyOperation>& ) = 0;
    virtual void endVisit ( const GenericArithIterator<DivideOperation>& ) = 0;
    virtual void endVisit ( const GenericArithIterator<IntegerDivideOperation>& ) = 0;
    virtual void endVisit ( const GenericArithIterator<ModOperation>& ) = 0;
    
    PLAN_ITER_VISITOR (OpNumericUnaryIterator);
    
    PLAN_ITER_VISITOR (FnAbsIterator);

    PLAN_ITER_VISITOR (FnCeilingIterator);

    PLAN_ITER_VISITOR (FnFloorIterator);

    PLAN_ITER_VISITOR (FnRoundIterator);

    PLAN_ITER_VISITOR (FnRoundHalfToEvenIterator);
      
    PLAN_ITER_VISITOR (FnSQRTIterator);

    PLAN_ITER_VISITOR (FnExpIterator);
    PLAN_ITER_VISITOR (FnLogIterator);
    PLAN_ITER_VISITOR (FnSinIterator);
    PLAN_ITER_VISITOR (FnCosIterator);
    PLAN_ITER_VISITOR (FnTanIterator);
    PLAN_ITER_VISITOR (FnArcSinIterator);
    PLAN_ITER_VISITOR (FnArcCosIterator);
    PLAN_ITER_VISITOR (FnArcTanIterator);

    PLAN_ITER_VISITOR (FnConcatIterator);

    PLAN_ITER_VISITOR (FnEmptyIterator);

    PLAN_ITER_VISITOR (FnExistsIterator);

    PLAN_ITER_VISITOR (FnIndexOfIterator);

    PLAN_ITER_VISITOR (FnRemoveIterator);

    PLAN_ITER_VISITOR (FnReverseIterator);

    PLAN_ITER_VISITOR (OpToIterator);

    PLAN_ITER_VISITOR (FnIdIterator);

    PLAN_ITER_VISITOR (FnIdRefIterator);

    PLAN_ITER_VISITOR (FnDistinctValuesIterator);

    PLAN_ITER_VISITOR (FnInsertBeforeIterator);

    PLAN_ITER_VISITOR (FnSubsequenceIterator);

    PLAN_ITER_VISITOR (FnZeroOrOneIterator);

    PLAN_ITER_VISITOR (FnOneOrMoreIterator);
       
    PLAN_ITER_VISITOR (FnExactlyOneIterator);

    PLAN_ITER_VISITOR (FnCountIterator);

    PLAN_ITER_VISITOR (FnAvgIterator);

    PLAN_ITER_VISITOR (FnMinMaxIterator);

    PLAN_ITER_VISITOR (FnSumIterator);

    PLAN_ITER_VISITOR (FnDocIterator);

    PLAN_ITER_VISITOR (FnDocAvailableIterator);
      
    PLAN_ITER_VISITOR (HashSemiJoinIterator);

    PLAN_ITER_VISITOR (SortSemiJoinIterator);

    PLAN_ITER_VISITOR (FnTraceIterator);

    PLAN_ITER_VISITOR (ResolveQNameIterator);

    PLAN_ITER_VISITOR (QNameIterator);
      
    PLAN_ITER_VISITOR (QNameEqualIterator);

    PLAN_ITER_VISITOR (PrefixFromQNameIterator);

    PLAN_ITER_VISITOR (LocalNameFromQNameIterator);

    PLAN_ITER_VISITOR (NamespaceUriFromQNameIterator);

    PLAN_ITER_VISITOR (InScopePrefixesIterator);

    PLAN_ITER_VISITOR (NamespaceUriForPrefixlIterator);

    PLAN_ITER_VISITOR (CodepointsToStringIterator);
       
    PLAN_ITER_VISITOR (StringToCodepointsIterator);
       
    PLAN_ITER_VISITOR (CompareStrIterator);
       
    PLAN_ITER_VISITOR (CodepointEqualIterator);
       
    PLAN_ITER_VISITOR (ConcatStrIterator);
       
    PLAN_ITER_VISITOR (StringJoinIterator);
       
    PLAN_ITER_VISITOR (SubstringIterator);
       
    PLAN_ITER_VISITOR (StringLengthIterator);
       
    PLAN_ITER_VISITOR (NormalizeSpaceIterator);
       
    PLAN_ITER_VISITOR (NormalizeUnicodeIterator);
       
    PLAN_ITER_VISITOR (UpperCaseIterator);
       
    PLAN_ITER_VISITOR (LowerCaseIterator);
       
    PLAN_ITER_VISITOR (TranslateIterator);
       
    PLAN_ITER_VISITOR (EncodeForUriIterator);
       
    PLAN_ITER_VISITOR (IriToUriIterator);
       
    PLAN_ITER_VISITOR (EscapeHtmlUriIterator);
       
    PLAN_ITER_VISITOR (ContainsIterator);
       
    PLAN_ITER_VISITOR (StartsWithIterator);
       
    PLAN_ITER_VISITOR (EndsWithIterator);
       
    PLAN_ITER_VISITOR (SubstringBeforeIterator);
       
    PLAN_ITER_VISITOR (SubstringAfterIterator);

    PLAN_ITER_VISITOR (FnMatchesIterator);

    PLAN_ITER_VISITOR (FnReplaceIterator);

    PLAN_ITER_VISITOR (FnTokenizeIterator);

    PLAN_ITER_VISITOR (ZorNumGen);
      
    PLAN_ITER_VISITOR (TextIterator);
            
    virtual void beginVisitFlworWhereClause(const  PlanIterator&) = 0;
    virtual void endVisitFlworWhereClause(const PlanIterator&) = 0;
    
    virtual void beginVisitFlworLetVariable(const PlanIterator&, bool, const xqpStringStore&) = 0;
    virtual void endVisitFlworLetVariable(const PlanIterator&) = 0;
    
    virtual void beginVisitFlworForVariable(const PlanIterator&, const xqpStringStore&) = 0;
    virtual void endVisitFlworForVariable(const PlanIterator&) = 0;
    
    virtual void beginVisitFlworGroupBy() = 0;
    virtual void endVisitFlworGroupBy() = 0;
    
    virtual void beginVisitFlworGroupBySpec() = 0;
    virtual void endVisitFlworGroupBySpec() = 0;
    
    virtual void beginVisitFlworGroupByOuterVar() = 0;
    virtual void endVisitFlworGroupByOuterVar() = 0;
    
    virtual void beginVisitFlworOrderBy(const PlanIterator&) = 0;
    virtual void endVisitFlworOrderBy(const PlanIterator&) = 0;
    
    virtual void beginVisitFlworReturn(const PlanIterator&) = 0;
    virtual void endVisitFlworReturn(const PlanIterator&) = 0;
      
    PLAN_ITER_VISITOR (CastIterator);

    PLAN_ITER_VISITOR (NameCastIterator);

    PLAN_ITER_VISITOR (PromoteIterator);

    PLAN_ITER_VISITOR (CastableIterator);

    PLAN_ITER_VISITOR (FnDateTimeConstructorIterator);

    PLAN_ITER_VISITOR (FnYearsFromDurationIterator);

    PLAN_ITER_VISITOR (FnMonthsFromDurationIterator);

    PLAN_ITER_VISITOR (FnDaysFromDurationIterator);

    PLAN_ITER_VISITOR (FnHoursFromDurationIterator);

    PLAN_ITER_VISITOR (FnMinutesFromDurationIterator);

    PLAN_ITER_VISITOR (FnSecondsFromDurationIterator);

    PLAN_ITER_VISITOR (FnYearFromDatetimeIterator);

    PLAN_ITER_VISITOR (FnMonthFromDatetimeIterator);

    PLAN_ITER_VISITOR (FnDayFromDatetimeIterator);

    PLAN_ITER_VISITOR (FnHoursFromDatetimeIterator);
      
    PLAN_ITER_VISITOR (FnMinutesFromDatetimeIterator);

    PLAN_ITER_VISITOR (FnSecondsFromDatetimeIterator);

    PLAN_ITER_VISITOR (FnTimezoneFromDatetimeIterator);

    PLAN_ITER_VISITOR (FnYearFromDateIterator);

    PLAN_ITER_VISITOR (FnMonthFromDateIterator);

    PLAN_ITER_VISITOR (FnDayFromDateIterator);

    PLAN_ITER_VISITOR (FnTimezoneFromDateIterator);

    PLAN_ITER_VISITOR (FnHoursFromTimeIterator);
      
    PLAN_ITER_VISITOR (FnMinutesFromTimeIterator);

    PLAN_ITER_VISITOR (FnSecondsFromTimeIterator);

    PLAN_ITER_VISITOR (FnTimezoneFromTimeIterator);

    PLAN_ITER_VISITOR (CtxVariableIterator);

    PLAN_ITER_VISITOR (CtxVarAssignIterator);

    PLAN_ITER_VISITOR (EvalIterator);

    PLAN_ITER_VISITOR (OpIsSameNodeIterator);

    PLAN_ITER_VISITOR (OpNodeBeforeIterator);

    PLAN_ITER_VISITOR (OpNodeAfterIterator);

    PLAN_ITER_VISITOR (FnCurrentDateTimeIterator);

    PLAN_ITER_VISITOR (FnCurrentDateIterator);

    PLAN_ITER_VISITOR (FnCurrentTimeIterator);

    PLAN_ITER_VISITOR (FnImplicitTimezoneIterator);

    PLAN_ITER_VISITOR (FnDefaultCollationIterator);

    PLAN_ITER_VISITOR(FnAdjustToTimeZoneIterator_1);

    PLAN_ITER_VISITOR(FnAdjustToTimeZoneIterator_2);

    PLAN_ITER_VISITOR(InsertIterator);

    PLAN_ITER_VISITOR(DeleteIterator);

    PLAN_ITER_VISITOR(ReplaceIterator);

    PLAN_ITER_VISITOR(RenameIterator);

    PLAN_ITER_VISITOR(TransformIterator);

    PLAN_ITER_VISITOR(FnDeepEqualIterator);

#ifdef ZORBA_DEBUGGER
    PLAN_ITER_VISITOR ( FnDebugIterator );  
#endif

#ifdef ZORBA_WITH_REST
    PLAN_ITER_VISITOR(ZorbaRestGetIterator);
    PLAN_ITER_VISITOR(ZorbaRestPostIterator);
#endif
	  
  }; /* class PlanIterVisitor */
} /* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */

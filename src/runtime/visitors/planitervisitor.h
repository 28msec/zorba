#ifndef XQP_PLANITERVISITOR_H
#define XQP_PLANITERVISITOR_H

namespace xqp
{
  class xqpStringStore;

  class PlanIterator;
  class FnDataIterator;
  class FnRootIterator;
  class FnNodeNameIterator;
  class FnStringIterator;
  class FnBooleanIterator;
  class LogicIterator;
  class CompareIterator;
  class UDFunctionCallIterator;
  class ElementIterator;
  class ElementContentIterator;
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
  class NodeDistinctIterator;
  class NodeSortIterator;
  class KindTestIterator;
  class NameTestIterator;
  template <class Object> class AxisIterator;
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
  class AddOperations;
  template <class AddOperations> class ArithmeticIterator;
  class SubtractOperations;
  template <class SubtractOperations> class ArithmeticIterator;
  class MultiplyOperations;
  template <class MultiplyOperations> class ArithmeticIterator;
  class DivideOperations;
  template <class DivideOperations> class ArithmeticIterator;
  class IntegerDivideOperations;
  template <class IntegerDivideOperations> class ArithmeticIterator;
  class ModOperations;
  template <class ModOperations> class ArithmeticIterator;
  class OpNumericUnaryIterator;
  class FnAbsIterator;
  class FnCeilingIterator;
  class FnFloorIterator;
  class FnRoundIterator;
  class FnRoundHalfToEvenIterator;
  class FnConcatIterator;
  class FnEmptyIterator;
  class FnExistsIterator;
  class FnIndexOfIterator;
  class FnRemoveIterator;
  class FnReverseIterator;
  class OpToIterator;
  class FnDistinctValuesIterator;
  class FnInsertBeforeIterator;  
  class FnSubsequenceIterator;
  class FnZeroOrOneIterator;
  class FnOneOrMoreIterator;
  class FnExactlyOneIterator;
  class FnCountIterator;
  class FnAvgIterator;
  class FnMaxIterator;
  class FnMinIterator;
  class FnSumIterator;
  class FnDocIterator;
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
  class ZorNumGen;
  class TextIterator;
  class DocumentIterator;
  class DocumentContentIterator;
  class DocFilterIterator;
  class CastIterator;
  class CastableIterator;
  class CtxVariableIterator;
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

      
  /**
   * Visitor to visit a PlanIterator tree.
   */
  class PlanIterVisitor
  {
    public:
      virtual ~PlanIterVisitor() {}

      virtual void beginVisit ( const FnDataIterator& ) = 0;
      virtual void endVisit ( const FnDataIterator& ) = 0;
       
      virtual void beginVisit ( const FnRootIterator& ) = 0;
      virtual void endVisit ( const FnRootIterator& ) = 0;
       
      virtual void beginVisit ( const FnNodeNameIterator& ) = 0;
      virtual void endVisit ( const FnNodeNameIterator& ) = 0;
       
      virtual void beginVisit ( const FnStringIterator& ) = 0;
      virtual void endVisit ( const FnStringIterator& ) = 0;
       
      virtual void beginVisit ( const FnBooleanIterator& ) = 0;
      virtual void endVisit ( const FnBooleanIterator& ) = 0;
       
      virtual void beginVisit ( const LogicIterator& ) = 0;
      virtual void endVisit ( const LogicIterator& ) = 0;
       
      virtual void beginVisit ( const CompareIterator& ) = 0;
      virtual void endVisit ( const CompareIterator& ) = 0;
       
      virtual void beginVisit ( const ElementIterator& ) = 0;
      virtual void endVisit ( const ElementIterator& ) = 0;
       
      virtual void beginVisit ( const ElementContentIterator& ) = 0;
      virtual void endVisit ( const ElementContentIterator& ) = 0;
       
      virtual void beginVisit ( const AttributeIterator & ) = 0;
      virtual void endVisit ( const AttributeIterator& ) = 0;
      
      virtual void beginVisit ( const DocumentIterator& ) = 0;
      virtual void endVisit ( const DocumentIterator& ) = 0;
      
      virtual void beginVisit ( const DocumentContentIterator& ) = 0;
      virtual void endVisit ( const DocumentContentIterator& ) = 0;
       
      virtual void beginVisit ( const UDFunctionCallIterator& ) = 0;
      virtual void endVisit ( const UDFunctionCallIterator& ) = 0;
       
      virtual void beginVisit ( const CommentIterator& ) = 0;
      virtual void endVisit ( const CommentIterator& ) = 0;
       
      virtual void beginVisit ( const PiIterator& ) = 0;
      virtual void endVisit ( const PiIterator& ) = 0;
       
      virtual void beginVisit ( const SingletonIterator& ) = 0;
      virtual void endVisit ( const SingletonIterator& ) = 0;

      virtual void beginVisit ( const EmptyIterator& ) = 0;
      virtual void endVisit ( const EmptyIterator& ) = 0;
       
      virtual void beginVisit ( const ForVarIterator& ) = 0;
      virtual void endVisit ( const ForVarIterator& ) = 0;
       
      virtual void beginVisit ( const LetVarIterator& ) = 0;
      virtual void endVisit ( const LetVarIterator& ) = 0;

      virtual void beginVisit ( const EnclosedIterator& ) = 0;
      virtual void endVisit ( const EnclosedIterator& ) = 0;
      
      virtual void beginVisit ( const DocFilterIterator& ) = 0;
      virtual void endVisit ( const DocFilterIterator& ) = 0;
       
      virtual void beginVisit ( const IfThenElseIterator& ) = 0;
      virtual void endVisit ( const IfThenElseIterator& ) = 0;
       
      virtual void beginVisit ( const FLWORIterator& ) = 0;
      virtual void endVisit ( const FLWORIterator& ) = 0;
 
      virtual void beginVisit ( const NodeDistinctIterator& a ) = 0;
      virtual void endVisit ( const NodeDistinctIterator& a ) = 0;

      virtual void beginVisit ( const NodeSortIterator& a ) = 0;
      virtual void endVisit ( const NodeSortIterator& a ) = 0;

      virtual void beginVisit ( const KindTestIterator& ) = 0;
      virtual void endVisit ( const KindTestIterator& ) = 0;
       
      virtual void beginVisit ( const NameTestIterator& ) = 0;
      virtual void endVisit ( const NameTestIterator& ) = 0;
       
      virtual void beginVisit ( const SelfAxisIterator& ) = 0;
      virtual void endVisit ( const SelfAxisIterator& ) = 0;
       
      virtual void beginVisit ( const AttributeAxisIterator& ) = 0;
      virtual void endVisit ( const AttributeAxisIterator& ) = 0;
       
      virtual void beginVisit ( const ParentAxisIterator& ) = 0;
      virtual void endVisit ( const ParentAxisIterator& ) = 0;
       
      virtual void beginVisit ( const AncestorAxisIterator& ) = 0;
      virtual void endVisit ( const AncestorAxisIterator& ) = 0;
       
      virtual void beginVisit ( const AncestorSelfAxisIterator& ) = 0;
      virtual void endVisit ( const AncestorSelfAxisIterator& ) = 0;
       
      virtual void beginVisit ( const RSiblingAxisIterator& ) = 0;
      virtual void endVisit ( const RSiblingAxisIterator& ) = 0;
       
      virtual void beginVisit ( const LSiblingAxisIterator& ) = 0;
      virtual void endVisit ( const LSiblingAxisIterator& ) = 0;
       
      virtual void beginVisit ( const ChildAxisIterator& ) = 0;
      virtual void endVisit ( const ChildAxisIterator& ) = 0;
       
      virtual void beginVisit ( const DescendantAxisIterator& ) = 0;
      virtual void endVisit ( const DescendantAxisIterator& ) = 0;
       
      virtual void beginVisit ( const DescendantSelfAxisIterator& ) = 0;
      virtual void endVisit ( const DescendantSelfAxisIterator& ) = 0;
       
      virtual void beginVisit ( const PrecedingAxisIterator& ) = 0;
      virtual void endVisit ( const PrecedingAxisIterator& ) = 0;
       
      virtual void beginVisit ( const FollowingAxisIterator& ) = 0;
      virtual void endVisit ( const FollowingAxisIterator& ) = 0;

      virtual void beginVisit ( const InstanceOfIterator& ) = 0;
      virtual void endVisit ( const InstanceOfIterator& ) = 0;
       
      virtual void beginVisit ( const ArithmeticIterator<AddOperations>& ) = 0;
      virtual void beginVisit ( const ArithmeticIterator<SubtractOperations>& ) = 0;
      virtual void beginVisit ( const ArithmeticIterator<MultiplyOperations>& ) = 0;
      virtual void beginVisit ( const ArithmeticIterator<DivideOperations>& ) = 0;
      virtual void beginVisit ( const ArithmeticIterator<IntegerDivideOperations>& ) = 0;
      virtual void beginVisit ( const ArithmeticIterator<ModOperations>& ) = 0;
      virtual void endVisit ( const ArithmeticIterator<AddOperations>& ) = 0;
      virtual void endVisit ( const ArithmeticIterator<SubtractOperations>& ) = 0;
      virtual void endVisit ( const ArithmeticIterator<MultiplyOperations>& ) = 0;
      virtual void endVisit ( const ArithmeticIterator<DivideOperations>& ) = 0;
      virtual void endVisit ( const ArithmeticIterator<IntegerDivideOperations>& ) = 0;
      virtual void endVisit ( const ArithmeticIterator<ModOperations>& ) = 0;
       
      virtual void beginVisit ( const OpNumericUnaryIterator& ) = 0;
      virtual void endVisit ( const OpNumericUnaryIterator& ) = 0;
       
      virtual void beginVisit ( const FnAbsIterator& ) = 0;
      virtual void endVisit ( const FnAbsIterator& ) = 0;

      virtual void beginVisit( const FnCeilingIterator& ) = 0;
      virtual void endVisit( const FnCeilingIterator& ) = 0;

      virtual void beginVisit( const FnFloorIterator& ) = 0;
      virtual void endVisit( const FnFloorIterator& ) = 0;

      virtual void beginVisit( const FnRoundIterator& ) = 0;
      virtual void endVisit( const FnRoundIterator& ) = 0;

      virtual void beginVisit( const FnRoundHalfToEvenIterator& ) = 0;
      virtual void endVisit( const FnRoundHalfToEvenIterator& ) = 0;
      
      virtual void beginVisit ( const FnConcatIterator& ) = 0;
      virtual void endVisit ( const FnConcatIterator& ) = 0;

      virtual void beginVisit ( const FnEmptyIterator& ) = 0;
      virtual void endVisit ( const FnEmptyIterator& ) = 0;

      virtual void beginVisit ( const FnExistsIterator& ) = 0;
      virtual void endVisit ( const FnExistsIterator& ) = 0;

      virtual void beginVisit ( const FnIndexOfIterator& ) = 0;
      virtual void endVisit ( const FnIndexOfIterator& ) = 0;

      virtual void beginVisit ( const FnRemoveIterator& ) = 0;
      virtual void endVisit ( const FnRemoveIterator& ) = 0;

      virtual void beginVisit ( const FnReverseIterator& ) = 0;
      virtual void endVisit ( const FnReverseIterator& ) = 0;

      virtual void beginVisit ( const OpToIterator& ) = 0;
      virtual void endVisit ( const OpToIterator& ) = 0;

      virtual void beginVisit ( const FnDistinctValuesIterator& ) = 0;
      virtual void endVisit ( const FnDistinctValuesIterator& ) = 0;       

      virtual void beginVisit ( const FnInsertBeforeIterator& ) = 0;
      virtual void endVisit ( const FnInsertBeforeIterator& ) = 0;       

      virtual void beginVisit ( const FnSubsequenceIterator& ) = 0;
      virtual void endVisit ( const FnSubsequenceIterator& ) = 0;       

      virtual void beginVisit ( const FnZeroOrOneIterator& ) = 0;
      virtual void endVisit ( const FnZeroOrOneIterator& ) = 0;       

      virtual void beginVisit ( const FnOneOrMoreIterator& ) = 0;
      virtual void endVisit ( const FnOneOrMoreIterator& ) = 0;       
       
      virtual void beginVisit ( const FnExactlyOneIterator& ) = 0;
      virtual void endVisit ( const FnExactlyOneIterator& ) = 0;       

      virtual void beginVisit ( const FnCountIterator& ) = 0;
      virtual void endVisit ( const FnCountIterator& ) = 0;

      virtual void beginVisit ( const FnAvgIterator& ) = 0;
      virtual void endVisit ( const FnAvgIterator& ) = 0;

      virtual void beginVisit ( const FnMaxIterator& ) = 0;
      virtual void endVisit ( const FnMaxIterator& ) = 0;

      virtual void beginVisit ( const FnMinIterator& ) = 0;
      virtual void endVisit ( const FnMinIterator& ) = 0;

      virtual void beginVisit ( const FnSumIterator& ) = 0;
      virtual void endVisit ( const FnSumIterator& ) = 0;

      virtual void beginVisit ( const FnDocIterator& ) = 0;
      virtual void endVisit ( const FnDocIterator& ) = 0;

      virtual void beginVisit ( const FnTraceIterator& ) = 0;
      virtual void endVisit ( const FnTraceIterator& ) = 0;

      virtual void beginVisit( const ResolveQNameIterator& ) = 0;
      virtual void endVisit( const ResolveQNameIterator& ) = 0;

      virtual void beginVisit( const QNameIterator& ) = 0;
      virtual void endVisit( const QNameIterator& ) = 0;
      
      virtual void beginVisit( const QNameEqualIterator& ) = 0;
      virtual void endVisit( const QNameEqualIterator& ) = 0;

      virtual void beginVisit( const PrefixFromQNameIterator& ) = 0;
      virtual void endVisit( const PrefixFromQNameIterator& ) = 0;

      virtual void beginVisit( const LocalNameFromQNameIterator& ) = 0;
      virtual void endVisit( const LocalNameFromQNameIterator& ) = 0;

      virtual void beginVisit( const NamespaceUriFromQNameIterator& ) = 0;
      virtual void endVisit( const NamespaceUriFromQNameIterator& ) = 0;

      virtual void beginVisit( const InScopePrefixesIterator& ) = 0;
      virtual void endVisit( const InScopePrefixesIterator& ) = 0;

      virtual void beginVisit( const NamespaceUriForPrefixlIterator& ) = 0;
      virtual void endVisit( const NamespaceUriForPrefixlIterator& ) = 0;

      virtual void beginVisit ( const CodepointsToStringIterator& ) = 0;
      virtual void endVisit ( const CodepointsToStringIterator& ) = 0;
       
      virtual void beginVisit ( const StringToCodepointsIterator& ) = 0;
      virtual void endVisit ( const StringToCodepointsIterator& ) = 0;
       
      virtual void beginVisit ( const CompareStrIterator& ) = 0;
      virtual void endVisit ( const CompareStrIterator& ) = 0;
       
      virtual void beginVisit ( const CodepointEqualIterator& ) = 0;
      virtual void endVisit ( const CodepointEqualIterator& ) = 0;
       
      virtual void beginVisit ( const ConcatStrIterator& ) = 0;
      virtual void endVisit ( const ConcatStrIterator& ) = 0;
       
      virtual void beginVisit ( const StringJoinIterator& ) = 0;
      virtual void endVisit ( const StringJoinIterator& ) = 0;
       
      virtual void beginVisit ( const SubstringIterator& ) = 0;
      virtual void endVisit ( const SubstringIterator& ) = 0;
       
      virtual void beginVisit ( const StringLengthIterator& ) = 0;
      virtual void endVisit ( const StringLengthIterator& ) = 0;
       
      virtual void beginVisit ( const NormalizeSpaceIterator& ) = 0;
      virtual void endVisit ( const NormalizeSpaceIterator& ) = 0;
       
      virtual void beginVisit ( const NormalizeUnicodeIterator& ) = 0;
      virtual void endVisit ( const NormalizeUnicodeIterator& ) = 0;
       
      virtual void beginVisit ( const UpperCaseIterator& ) = 0;
      virtual void endVisit ( const UpperCaseIterator& ) = 0;
       
      virtual void beginVisit ( const LowerCaseIterator& ) = 0;
      virtual void endVisit ( const LowerCaseIterator& ) = 0;
       
      virtual void beginVisit ( const TranslateIterator& ) = 0;
      virtual void endVisit ( const TranslateIterator& ) = 0;
       
      virtual void beginVisit ( const EncodeForUriIterator& ) = 0;
      virtual void endVisit ( const EncodeForUriIterator& ) = 0;
       
      virtual void beginVisit ( const IriToUriIterator& ) = 0;
      virtual void endVisit ( const IriToUriIterator& ) = 0;
       
      virtual void beginVisit ( const EscapeHtmlUriIterator& ) = 0;
      virtual void endVisit ( const EscapeHtmlUriIterator& ) = 0;
       
      virtual void beginVisit ( const ContainsIterator& ) = 0;
      virtual void endVisit ( const ContainsIterator& ) = 0;
       
      virtual void beginVisit ( const StartsWithIterator& ) = 0;
      virtual void endVisit ( const StartsWithIterator& ) = 0;
       
      virtual void beginVisit ( const EndsWithIterator& ) = 0;
      virtual void endVisit ( const EndsWithIterator& ) = 0;
       
      virtual void beginVisit ( const SubstringBeforeIterator& ) = 0;
      virtual void endVisit ( const SubstringBeforeIterator& ) = 0;
       
      virtual void beginVisit ( const SubstringAfterIterator& ) = 0;
      virtual void endVisit ( const SubstringAfterIterator& ) = 0;
      
      virtual void beginVisit ( const ZorNumGen& ) = 0;
      virtual void endVisit ( const ZorNumGen& ) = 0;
      
      virtual void beginVisit ( const TextIterator& ) = 0;
      virtual void endVisit ( const TextIterator& ) = 0;
            
    virtual void beginVisitFlworWhereClause(const  PlanIterator&) = 0;
    virtual void endVisitFlworWhereClause(const PlanIterator&) = 0;
      
    virtual void beginVisitFlworVariables() = 0;
    virtual void endVisitFlworVariables() = 0;
      
    virtual void beginVisitFlworLetVariable(const PlanIterator&, bool, const xqpStringStore&) = 0;
    virtual void endVisitFlworLetVariable(const PlanIterator&) = 0;
      
    virtual void beginVisitFlworForVariable(const PlanIterator&, const xqpStringStore&) = 0;
    virtual void endVisitFlworForVariable(const PlanIterator&) = 0;
      
    virtual void beginVisitFlworOrderBy(const PlanIterator&) = 0;
    virtual void endVisitFlworOrderBy(const PlanIterator&) = 0;
      
    virtual void beginVisitFlworReturn(const PlanIterator&) = 0;
    virtual void endVisitFlworReturn(const PlanIterator&) = 0;
      
      virtual void beginVisit ( const CastIterator& ) = 0;
      virtual void endVisit ( const CastIterator& ) = 0;

      virtual void beginVisit ( const CastableIterator& ) = 0;
      virtual void endVisit ( const CastableIterator& ) = 0;

      virtual void beginVisit ( const FnDateTimeConstructorIterator&) = 0;
      virtual void endVisit ( const FnDateTimeConstructorIterator&) = 0;

      virtual void beginVisit ( const FnYearsFromDurationIterator&) = 0;
      virtual void endVisit ( const FnYearsFromDurationIterator&) = 0;

      virtual void beginVisit ( const FnMonthsFromDurationIterator&) = 0;
      virtual void endVisit ( const FnMonthsFromDurationIterator&) = 0;

      virtual void beginVisit ( const FnDaysFromDurationIterator&) = 0;
      virtual void endVisit ( const FnDaysFromDurationIterator&) = 0;

      virtual void beginVisit ( const FnHoursFromDurationIterator&) = 0;
      virtual void endVisit ( const FnHoursFromDurationIterator&) = 0;

      virtual void beginVisit ( const FnMinutesFromDurationIterator&) = 0;
      virtual void endVisit ( const FnMinutesFromDurationIterator&) = 0;

      virtual void beginVisit ( const FnSecondsFromDurationIterator&) = 0;
      virtual void endVisit ( const FnSecondsFromDurationIterator&) = 0;

      virtual void beginVisit ( const FnYearFromDatetimeIterator&) = 0;
      virtual void endVisit ( const FnYearFromDatetimeIterator&) = 0;

      virtual void beginVisit ( const FnMonthFromDatetimeIterator&) = 0;
      virtual void endVisit ( const FnMonthFromDatetimeIterator&) = 0;

      virtual void beginVisit ( const FnDayFromDatetimeIterator&) = 0;
      virtual void endVisit ( const FnDayFromDatetimeIterator&) = 0;

      virtual void beginVisit ( const FnHoursFromDatetimeIterator&) = 0;
      virtual void endVisit ( const FnHoursFromDatetimeIterator&) = 0;
      
      virtual void beginVisit ( const FnMinutesFromDatetimeIterator&) = 0;
      virtual void endVisit ( const FnMinutesFromDatetimeIterator&) = 0;

      virtual void beginVisit ( const FnSecondsFromDatetimeIterator&) = 0;
      virtual void endVisit ( const FnSecondsFromDatetimeIterator&) = 0;

      virtual void beginVisit ( const FnTimezoneFromDatetimeIterator&) = 0;
      virtual void endVisit ( const FnTimezoneFromDatetimeIterator&) = 0;

      virtual void beginVisit ( const FnYearFromDateIterator&) = 0;
      virtual void endVisit ( const FnYearFromDateIterator&) = 0;

      virtual void beginVisit ( const FnMonthFromDateIterator&) = 0;
      virtual void endVisit ( const FnMonthFromDateIterator&) = 0;

      virtual void beginVisit ( const FnDayFromDateIterator&) = 0;
      virtual void endVisit ( const FnDayFromDateIterator&) = 0;

      virtual void beginVisit ( const FnTimezoneFromDateIterator&) = 0;
      virtual void endVisit ( const FnTimezoneFromDateIterator&) = 0;
  

      virtual void beginVisit(const CtxVariableIterator&) = 0;
      virtual void endVisit(const CtxVariableIterator&) = 0;

  }; /* class PlanIterVisitor */
} /* namespace xqp */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */

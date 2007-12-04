#ifndef XQP_PLANITERVISITOR_H
#define XQP_PLANITERVISITOR_H

namespace xqp
{
  class FnDataIterator;
  class FnRootIterator;
  class FnBooleanIterator;
  class LogicIterator;
  class CompareIterator;
  class ElementIterator;
  class ElementContentIterator;
  class AttributeIterator;
  class CommentIterator;
  class RefIterator;
  class SingletonIterator;
  class EmptyIterator;
  class var_iterator;
  class RefIterator;
  class EnclosedIterator;
  class IfThenElseIterator;
  class FLWORIterator;
  class NodeDistinctIterator;
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
  class FnConcatIterator;
  class FnEmptyIterator;
  class FnExistsIterator;
  class FnIndexOfIterator;
  class DocIterator;
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
       
      virtual void beginVisit ( const CommentIterator& ) = 0;
      virtual void endVisit ( const CommentIterator& ) = 0;
       
      virtual void beginVisit ( const RefIterator& ) = 0;
      virtual void endVisit ( const RefIterator& ) = 0;
       
      virtual void beginVisit ( const SingletonIterator& ) = 0;
      virtual void endVisit ( const SingletonIterator& ) = 0;

      virtual void beginVisit ( const EmptyIterator& ) = 0;
      virtual void endVisit ( const EmptyIterator& ) = 0;
       
      virtual void beginVisit ( const var_iterator& ) = 0;
      virtual void endVisit ( const var_iterator& ) = 0;
       
      virtual void beginVisit ( const EnclosedIterator& ) = 0;
      virtual void endVisit ( const EnclosedIterator& ) = 0;
       
      virtual void beginVisit ( const IfThenElseIterator& ) = 0;
      virtual void endVisit ( const IfThenElseIterator& ) = 0;
       
      virtual void beginVisit ( const FLWORIterator& ) = 0;
      virtual void endVisit ( const FLWORIterator& ) = 0;
 
      //virtual void beginVisit ( const NodeDistinctIterator& a ) = 0;
      //virtual void endVisit ( const NodeDistinctIterator& a ) = 0;

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
       
      virtual void beginVisit ( const FnConcatIterator& ) = 0;
      virtual void endVisit ( const FnConcatIterator& ) = 0;

      virtual void beginVisit ( const FnEmptyIterator& ) = 0;
      virtual void endVisit ( const FnEmptyIterator& ) = 0;

      virtual void beginVisit ( const FnExistsIterator& ) = 0;
      virtual void endVisit ( const FnExistsIterator& ) = 0;

      virtual void beginVisit ( const FnIndexOfIterator& ) = 0;
      virtual void endVisit ( const FnIndexOfIterator& ) = 0;
       
      virtual void beginVisit ( const DocIterator& ) = 0;
      virtual void endVisit ( const DocIterator& ) = 0;
       
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

  }; /* class PlanIterVisitor */
} /* namespace xqp */

#endif

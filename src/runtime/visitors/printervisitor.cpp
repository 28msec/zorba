#include <sstream>

#include "runtime/visitors/printervisitor.h"
#include "runtime/core/item_iterator.h"
#include "runtime/core/constructors.h"
#include "runtime/core/path_iterators.h"
#include "runtime/core/sequencetypes.h"
#include "runtime/accessors/AccessorsImpl.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/core/flwor_iterator.h"
#include "runtime/core/nodeid_iterators.h"
#include "runtime/numerics/NumericsImpl.h"
#include "runtime/sequences/SequencesImpl.h"
#include "runtime/strings/StringsImpl.h"

namespace xqp {
  void PrinterVisitor::printCommons(const PlanIterator* aIter) {
    {
      std::stringstream lStream;
      lStream << aIter->loc;
      thePrinter.addAttribute("loc", lStream.str());
    }
    {
      std::stringstream lStream;
      lStream << aIter;
      thePrinter.addAttribute("addr", lStream.str());
    }
  }
  
  void PrinterVisitor::beginVisit ( const FnDataIterator& a ) {
    thePrinter.startIter("FnDataIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const FnDataIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const FnRootIterator& a ) {
    thePrinter.startIter("FnRootIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const FnRootIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const FnBooleanIterator& a ) {
    thePrinter.startIter("FnBooleanIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const FnBooleanIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const LogicIterator& a ) {
    thePrinter.startIter("LogicIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const LogicIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const CompareIterator& a ) {
    thePrinter.startIter("CompareIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const CompareIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const ElementIterator& a) {
    thePrinter.startIter("ElementIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const ElementIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const ElementContentIterator& a ) {
    thePrinter.startIter("ElementContentIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const ElementContentIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const AttributeIterator& a ) {
    thePrinter.startIter("AttributeIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const AttributeIterator& a ) {
    thePrinter.endIter();
  }
  
  void PrinterVisitor::beginVisit ( const DocumentIterator& a ) {
    thePrinter.startIter("DocumentIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const DocumentIterator& a ) {
    thePrinter.endIter();
  }
  
  void PrinterVisitor::beginVisit ( const DocumentContentIterator& a ) {
    thePrinter.startIter("DocumentContentIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const DocumentContentIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const CommentIterator& a ) {
    thePrinter.startIter("CommentIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const CommentIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const RefIterator& a ) {
    thePrinter.startIter("RefIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const RefIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const SingletonIterator& a) {
    thePrinter.startIter("SingletonIterator");
    thePrinter.addAttribute("value", a.getValue()->show());
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const SingletonIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const EmptyIterator& a ) {
    thePrinter.startIter("EmptyIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const EmptyIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const var_iterator& a ) {
    thePrinter.startIter("var_iterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const var_iterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const EnclosedIterator& a ) {
    thePrinter.startIter("EnclosedIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const EnclosedIterator& a ) {
    thePrinter.endIter();
  }
  
  void PrinterVisitor::beginVisit ( const DocFilterIterator& a ) {
    thePrinter.startIter("DocFilterIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const DocFilterIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const IfThenElseIterator& a ) {
    thePrinter.startIter("IfThenElseIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const IfThenElseIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const FLWORIterator& a ) {
    thePrinter.startIter("FLWORIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const FLWORIterator& a ) {
    thePrinter.endIter();
  }

  void PrinterVisitor::beginVisit ( const NodeDistinctIterator& a ) {
    thePrinter.startIter("NodeDistinctIterator");
    printCommons(&a);
  }

  void PrinterVisitor::endVisit ( const NodeDistinctIterator& a ) {
    thePrinter.endIter();
  }

  void PrinterVisitor::beginVisit ( const NodeSortIterator& a ) {
    thePrinter.startIter("NodeSortIterator");
    printCommons(&a);
  }

  void PrinterVisitor::endVisit ( const NodeSortIterator& a ) {
    thePrinter.endIter();
  }

  void PrinterVisitor::beginVisit ( const KindTestIterator& a ) {
    thePrinter.startIter("KindTestIterator");
    {
      std::stringstream lStream;
      lStream << a.getTestKind();
      thePrinter.addAttribute("test kind", lStream.str());
    }
    if (a.getQName() != 0)
      thePrinter.addAttribute("qname",a.getQName()->show());
    else
      thePrinter.addAttribute("qname","*");
    if (a.getTypeName() != 0)
      thePrinter.addAttribute("typename",a.getTypeName()->show());
    else
      thePrinter.addAttribute("typename","*");
    {
      std::stringstream lStream;
      lStream << a.nilledAllowed();
      thePrinter.addAttribute("nill allowed",lStream.str());
    }
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const KindTestIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const NameTestIterator& a ) {
    thePrinter.startIter("NameTestIterator");
    if (a.getQName() != NULL)
      thePrinter.addAttribute("qname", a.getQName()->show());
    else
      thePrinter.addAttribute("qname", "*");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const NameTestIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const SelfAxisIterator& a ) {
    thePrinter.startIter("SelfAxisIterator");
    printCommons( &a );
    
  }
  void PrinterVisitor::endVisit ( const SelfAxisIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const AttributeAxisIterator& a ) {
    thePrinter.startIter("AttributeAxisIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const AttributeAxisIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const ParentAxisIterator& a ) {
    thePrinter.startIter("ParentAxisIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const ParentAxisIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const AncestorAxisIterator& a ) {
    thePrinter.startIter("AncestorAxisIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const AncestorAxisIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const AncestorSelfAxisIterator& a ) {
    thePrinter.startIter("AncestorSelfAxisIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const AncestorSelfAxisIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const RSiblingAxisIterator& a ) {
    thePrinter.startIter("RSiblingAxisIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const RSiblingAxisIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const LSiblingAxisIterator& a ) {
    thePrinter.startIter("LSiblingAxisIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const LSiblingAxisIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const ChildAxisIterator& a ) {
    thePrinter.startIter("ChildAxisIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const ChildAxisIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const DescendantAxisIterator& a ) {
    thePrinter.startIter("DescendantAxisIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const DescendantAxisIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const DescendantSelfAxisIterator& a ) {
    thePrinter.startIter("DescendantSelfAxisIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const DescendantSelfAxisIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const PrecedingAxisIterator& a ) {
    thePrinter.startIter("PrecedingAxisIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const PrecedingAxisIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const FollowingAxisIterator& a ) {
    thePrinter.startIter("FollowingAxisIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const FollowingAxisIterator& a ) {
    thePrinter.endIter();
  }

  void PrinterVisitor::beginVisit ( const InstanceOfIterator& a ) {
    thePrinter.startIter("InstanceOfIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const InstanceOfIterator& a ) {
    thePrinter.endIter();
  }

  void PrinterVisitor::beginVisit ( const ArithmeticIterator<AddOperations>& a ) {
    thePrinter.startIter("ArithmeticIterator_AddOperations");
    printCommons( &a );
  }
  void PrinterVisitor::beginVisit ( const ArithmeticIterator<SubtractOperations>& a ) {
    thePrinter.startIter("ArithmeticIterator_SubtractOperations");
    printCommons( &a );
  }
  void PrinterVisitor::beginVisit ( const ArithmeticIterator<MultiplyOperations>& a ) {
    thePrinter.startIter("ArithmeticIterator_MultiplyOperations");
    printCommons( &a );
  }
  void PrinterVisitor::beginVisit ( const ArithmeticIterator<DivideOperations>& a ) {
    thePrinter.startIter("ArithmeticIterator_DivideOperations");
    printCommons( &a );
  }
  void PrinterVisitor::beginVisit ( const ArithmeticIterator<IntegerDivideOperations>& a ) {
    thePrinter.startIter("ArithmeticIterator_IntegerDivideOperations");
    printCommons( &a );
  }
  void PrinterVisitor::beginVisit ( const ArithmeticIterator<ModOperations>& a ) {
    thePrinter.startIter("ArithmeticIterator_ModOperations");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const ArithmeticIterator<AddOperations>& a ) {
    thePrinter.endIter();
  }
  void PrinterVisitor::endVisit ( const ArithmeticIterator<SubtractOperations>& a ) {
    thePrinter.endIter();
  }
  void PrinterVisitor::endVisit ( const ArithmeticIterator<MultiplyOperations>& a ) {
    thePrinter.endIter();
  }
  void PrinterVisitor::endVisit ( const ArithmeticIterator<DivideOperations>& a ) {
    thePrinter.endIter();
  }
  void PrinterVisitor::endVisit ( const ArithmeticIterator<IntegerDivideOperations>& a ) {
    thePrinter.endIter();
  }
  void PrinterVisitor::endVisit ( const ArithmeticIterator<ModOperations>& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const OpNumericUnaryIterator& a ) {
    thePrinter.startIter("OpNumericUnaryIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const OpNumericUnaryIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const FnAbsIterator& a ) {
    thePrinter.startIter("FnAbsIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const FnAbsIterator& a ) {
    thePrinter.endIter();
  }

  void PrinterVisitor::beginVisit( const FnCeilingIterator& a)
  {
    thePrinter.startIter("FnCeilingIterator");
    printCommons( &a );
  }

  void PrinterVisitor::endVisit( const FnCeilingIterator& a)
  {
    thePrinter.endIter();
  }

  void PrinterVisitor::beginVisit( const FnFloorIterator& a)
  {
    thePrinter.startIter("FnFloorIterator");
    printCommons( &a );
  }

  void PrinterVisitor::endVisit( const FnFloorIterator& a )
  {
    thePrinter.endIter();
  }

  void PrinterVisitor::beginVisit( const FnRoundIterator& a)
  {
    thePrinter.startIter("FnRoundIterator");
    printCommons( &a );
  }

  void PrinterVisitor::endVisit( const FnRoundIterator& a )
  {
    thePrinter.endIter();
  }

  void PrinterVisitor::beginVisit( const FnRoundHalfToEvenIterator& a)
  {
    thePrinter.startIter("FnRoundHalfToEvenIterator");
    printCommons( &a );
  }

  void PrinterVisitor::endVisit( const FnRoundHalfToEvenIterator& a )
  {
    thePrinter.endIter();
  }
  
  void PrinterVisitor::beginVisit ( const FnConcatIterator& a ) {
    thePrinter.startIter("FnConcatIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const FnConcatIterator& a ) {
    thePrinter.endIter();
  }

  void PrinterVisitor::beginVisit ( const FnEmptyIterator& a ) {
    thePrinter.startIter("FnEmptyIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const FnEmptyIterator& a ) {
    thePrinter.endIter();
  }

  void PrinterVisitor::beginVisit ( const FnExistsIterator& a ) {
    thePrinter.startIter("FnExistsIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const FnExistsIterator& a ) {
    thePrinter.endIter();
  }

  void PrinterVisitor::beginVisit ( const FnIndexOfIterator& a ) {
    thePrinter.startIter("FnIndexOfIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const FnIndexOfIterator& a ) {
    thePrinter.endIter();
  }

  void PrinterVisitor::beginVisit ( const FnRemoveIterator& a ) {
    thePrinter.startIter("FnIndexOfIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const FnRemoveIterator& a ) {
    thePrinter.endIter();
  }

  void PrinterVisitor::beginVisit ( const FnDistinctValuesIterator& a ) {
    thePrinter.startIter("FnDistinctValuesIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const FnDistinctValuesIterator& a ) {
    thePrinter.endIter();
  }

  void PrinterVisitor::beginVisit ( const FnInsertBeforeIterator& a ) {
    thePrinter.startIter("FnInsertBeforeIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const FnInsertBeforeIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const FnDocIterator& a ) {
    thePrinter.startIter("FnDocIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const FnDocIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const CodepointsToStringIterator& a ) {
    thePrinter.startIter("CodepointsToStringIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const CodepointsToStringIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const StringToCodepointsIterator& a ) {
    thePrinter.startIter("StringToCodepointsIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const StringToCodepointsIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const CompareStrIterator& a ) {
    thePrinter.startIter("CompareStrIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const CompareStrIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const CodepointEqualIterator& a ) {
    thePrinter.startIter("CodepointEqualIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const CodepointEqualIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const ConcatStrIterator& a ) {
    thePrinter.startIter("ConcatStrIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const ConcatStrIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const StringJoinIterator& a ) {
    thePrinter.startIter("StringJoinIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const StringJoinIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const SubstringIterator& a ) {
    thePrinter.startIter("SubstringIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const SubstringIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const StringLengthIterator& a ) {
    thePrinter.startIter("StringLengthIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const StringLengthIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const NormalizeSpaceIterator& a ) {
    thePrinter.startIter("NormalizeSpaceIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const NormalizeSpaceIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const NormalizeUnicodeIterator& a ) {
    thePrinter.startIter("NormalizeUnicodeIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const NormalizeUnicodeIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const UpperCaseIterator& a ) {
    thePrinter.startIter("UpperCaseIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const UpperCaseIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const LowerCaseIterator& a ) {
    thePrinter.startIter("LowerCaseIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const LowerCaseIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const TranslateIterator& a ) {
    thePrinter.startIter("TranslateIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const TranslateIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const EncodeForUriIterator& a ) {
    thePrinter.startIter("EncodeForUriIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const EncodeForUriIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const IriToUriIterator& a ) {
    thePrinter.startIter("IriToUriIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const IriToUriIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const EscapeHtmlUriIterator& a ) {
    thePrinter.startIter("EscapeHtmlUriIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const EscapeHtmlUriIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const ContainsIterator& a ) {
    thePrinter.startIter("ContainsIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const ContainsIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const StartsWithIterator& a ) {
    thePrinter.startIter("StartsWithIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const StartsWithIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const EndsWithIterator& a ) {
    thePrinter.startIter("EndsWithIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const EndsWithIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const SubstringBeforeIterator& a ) {
    thePrinter.startIter("SubstringBeforeIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const SubstringBeforeIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const SubstringAfterIterator& a ) {
    thePrinter.startIter("SubstringAfterIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const SubstringAfterIterator& ) {
    thePrinter.endIter();
  }
      
  void PrinterVisitor::beginVisit ( const ZorNumGen& a ) {
    thePrinter.startIter("ZorNumGen");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const ZorNumGen& ) {
    thePrinter.endIter();
  }
  
  void PrinterVisitor::beginVisit ( const TextIterator& a )  {
    thePrinter.startIter("TextIterator");
    printCommons( &a );
  }
  void PrinterVisitor::endVisit ( const TextIterator& ) {
    thePrinter.endIter();
  }
} /* namespace xqp */

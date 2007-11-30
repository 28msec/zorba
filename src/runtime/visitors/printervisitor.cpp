#include <sstream>

#include "runtime/visitors/printervisitor.h"
#include "runtime/core/item_iterator.h"
#include "runtime/core/constructors.h"
#include "runtime/core/path_iterators.h"
#include "runtime/accessors/AccessorsImpl.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/core/flwor_iterator.h"
#include "runtime/numerics/NumericsImpl.h"
#include "runtime/sequences/SequencesImpl.h"
#include "runtime/strings/StringsImpl.h"

namespace xqp {
  void PrinterVisitor::printLoc(const yy::location& loc) {
    std::stringstream lStream;
    lStream << loc;
    thePrinter.addAttribute("loc", lStream.str());
  }
  
  void PrinterVisitor::beginVisit ( const FnDataIterator& a ) {
    thePrinter.startIter("FnDataIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const FnDataIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const FnRootIterator& a ) {
    thePrinter.startIter("FnRootIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const FnRootIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const FnBooleanIterator& a ) {
    thePrinter.startIter("FnBooleanIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const FnBooleanIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const LogicIterator& a ) {
    thePrinter.startIter("LogicIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const LogicIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const CompareIterator& a ) {
    thePrinter.startIter("CompareIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const CompareIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const ElementIterator& a) {
    thePrinter.startIter("ElementIterator");
    thePrinter.addAttribute("qname",a.getQName()->show());
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const ElementIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const ElementContentIterator& a ) {
    thePrinter.startIter("ElementContentIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const ElementContentIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const AttributeIterator& a ) {
    thePrinter.startIter("AttributeIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const AttributeIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const CommentIterator& a ) {
    thePrinter.startIter("CommentIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const CommentIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const RefIterator& a ) {
    thePrinter.startIter("RefIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const RefIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const SingletonIterator& a) {
    thePrinter.startIter("SingletonIterator");
    thePrinter.addAttribute("value", a.getValue()->show());
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const SingletonIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const EmptyIterator& a ) {
    thePrinter.startIter("EmptyIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const EmptyIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const var_iterator& a ) {
    thePrinter.startIter("var_iterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const var_iterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const EnclosedIterator& a ) {
    thePrinter.startIter("EnclosedIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const EnclosedIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const IfThenElseIterator& a ) {
    thePrinter.startIter("IfThenElseIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const IfThenElseIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const FLWORIterator& a ) {
    thePrinter.startIter("FLWORIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const FLWORIterator& a ) {
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
    printLoc(a.loc);
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
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const NameTestIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const SelfAxisIterator& a ) {
    thePrinter.startIter("SelfAxisIterator");
    printLoc(a.loc);
    
  }
  void PrinterVisitor::endVisit ( const SelfAxisIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const AttributeAxisIterator& a ) {
    thePrinter.startIter("AttributeAxisIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const AttributeAxisIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const ParentAxisIterator& a ) {
    thePrinter.startIter("ParentAxisIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const ParentAxisIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const AncestorAxisIterator& a ) {
    thePrinter.startIter("AncestorAxisIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const AncestorAxisIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const AncestorSelfAxisIterator& a ) {
    thePrinter.startIter("AncestorSelfAxisIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const AncestorSelfAxisIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const RSiblingAxisIterator& a ) {
    thePrinter.startIter("RSiblingAxisIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const RSiblingAxisIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const LSiblingAxisIterator& a ) {
    thePrinter.startIter("LSiblingAxisIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const LSiblingAxisIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const ChildAxisIterator& a ) {
    thePrinter.startIter("ChildAxisIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const ChildAxisIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const DescendantAxisIterator& a ) {
    thePrinter.startIter("DescendantAxisIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const DescendantAxisIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const DescendantSelfAxisIterator& a ) {
    thePrinter.startIter("DescendantSelfAxisIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const DescendantSelfAxisIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const PrecedingAxisIterator& a ) {
    thePrinter.startIter("PrecedingAxisIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const PrecedingAxisIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const FollowingAxisIterator& a ) {
    thePrinter.startIter("FollowingAxisIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const FollowingAxisIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const ArithmeticIterator<AddOperations>& a ) {
    thePrinter.startIter("ArithmeticIterator_AddOperations");
    printLoc(a.loc);
  }
  void PrinterVisitor::beginVisit ( const ArithmeticIterator<SubtractOperations>& a ) {
    thePrinter.startIter("ArithmeticIterator_SubtractOperations");
    printLoc(a.loc);
  }
  void PrinterVisitor::beginVisit ( const ArithmeticIterator<MultiplyOperations>& a ) {
    thePrinter.startIter("ArithmeticIterator_MultiplyOperations");
    printLoc(a.loc);
  }
  void PrinterVisitor::beginVisit ( const ArithmeticIterator<DivideOperations>& a ) {
    thePrinter.startIter("ArithmeticIterator_DivideOperations");
    printLoc(a.loc);
  }
  void PrinterVisitor::beginVisit ( const ArithmeticIterator<IntegerDivideOperations>& a ) {
    thePrinter.startIter("ArithmeticIterator_IntegerDivideOperations");
    printLoc(a.loc);
  }
  void PrinterVisitor::beginVisit ( const ArithmeticIterator<ModOperations>& a ) {
    thePrinter.startIter("ArithmeticIterator_ModOperations");
    printLoc(a.loc);
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
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const OpNumericUnaryIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const FnAbsIterator& a ) {
    thePrinter.startIter("FnAbsIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const FnAbsIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const ConcatIterator& a ) {
    thePrinter.startIter("ConcatIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const ConcatIterator& a ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const DocIterator& a ) {
    thePrinter.startIter("DocIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const DocIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const CodepointsToStringIterator& a ) {
    thePrinter.startIter("CodepointsToStringIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const CodepointsToStringIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const StringToCodepointsIterator& a ) {
    thePrinter.startIter("StringToCodepointsIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const StringToCodepointsIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const CompareStrIterator& a ) {
    thePrinter.startIter("CompareStrIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const CompareStrIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const CodepointEqualIterator& a ) {
    thePrinter.startIter("CodepointEqualIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const CodepointEqualIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const ConcatStrIterator& a ) {
    thePrinter.startIter("ConcatStrIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const ConcatStrIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const StringJoinIterator& a ) {
    thePrinter.startIter("StringJoinIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const StringJoinIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const SubstringIterator& a ) {
    thePrinter.startIter("SubstringIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const SubstringIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const StringLengthIterator& a ) {
    thePrinter.startIter("StringLengthIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const StringLengthIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const NormalizeSpaceIterator& a ) {
    thePrinter.startIter("NormalizeSpaceIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const NormalizeSpaceIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const NormalizeUnicodeIterator& a ) {
    thePrinter.startIter("NormalizeUnicodeIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const NormalizeUnicodeIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const UpperCaseIterator& a ) {
    thePrinter.startIter("UpperCaseIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const UpperCaseIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const LowerCaseIterator& a ) {
    thePrinter.startIter("LowerCaseIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const LowerCaseIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const TranslateIterator& a ) {
    thePrinter.startIter("TranslateIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const TranslateIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const EncodeForUriIterator& a ) {
    thePrinter.startIter("EncodeForUriIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const EncodeForUriIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const IriToUriIterator& a ) {
    thePrinter.startIter("IriToUriIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const IriToUriIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const EscapeHtmlUriIterator& a ) {
    thePrinter.startIter("EscapeHtmlUriIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const EscapeHtmlUriIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const ContainsIterator& a ) {
    thePrinter.startIter("ContainsIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const ContainsIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const StartsWithIterator& a ) {
    thePrinter.startIter("StartsWithIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const StartsWithIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const EndsWithIterator& a ) {
    thePrinter.startIter("EndsWithIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const EndsWithIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const SubstringBeforeIterator& a ) {
    thePrinter.startIter("SubstringBeforeIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const SubstringBeforeIterator& ) {
    thePrinter.endIter();
  }
       
  void PrinterVisitor::beginVisit ( const SubstringAfterIterator& a ) {
    thePrinter.startIter("SubstringAfterIterator");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const SubstringAfterIterator& ) {
    thePrinter.endIter();
  }
      
  void PrinterVisitor::beginVisit ( const ZorNumGen& a ) {
    thePrinter.startIter("ZorNumGen");
    printLoc(a.loc);
  }
  void PrinterVisitor::endVisit ( const ZorNumGen& ) {
    thePrinter.endIter();
  }
} /* namespace xqp */

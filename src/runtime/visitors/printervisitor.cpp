#include <sstream>

#include "runtime/visitors/printervisitor.h"
#include "runtime/context/ContextImpl.h"
#include "runtime/core/item_iterator.h"
#include "runtime/core/var_iterators.h"
#include "runtime/core/constructors.h"
#include "runtime/core/path_iterators.h"
#include "runtime/core/fncall_iterator.h"
#include "runtime/qnames/QNamesImpl.h"
#include "runtime/core/sequencetypes.h"
#include "runtime/accessors/AccessorsImpl.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/core/flwor_iterator.h"
#include "runtime/core/trycatch.h"
#include "runtime/core/nodeid_iterators.h"
#include "runtime/numerics/NumericsImpl.h"
#include "runtime/core/arithmetic_impl.h"
#include "runtime/sequences/SequencesImpl.h"
#include "runtime/strings/StringsImpl.h"
#include "runtime/dateTime/DurationsDatesTimes.h"
#include "runtime/fncontext/FnContextImpl.h"
#include "runtime/debug/debug_iterators.h"
#include "types/root_typemanager.h"
#include "runtime/visitors/iterprinter.h"

#include "system/globalenv.h"

namespace xqp {
  void PrinterVisitor::print() {
    thePrinter.start();
    theIterator->accept(*this);
    thePrinter.stop();
  }

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

  void PrinterVisitor::beginVisit ( const FnDataIterator& a) {
    thePrinter.startBeginVisit("FnDataIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FnDataIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnRootIterator& a ) {
    thePrinter.startBeginVisit("FnRootIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FnRootIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnNodeNameIterator& a ) {
    thePrinter.startBeginVisit("FnNodeNameIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FnNodeNameIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const UDFunctionCallIterator& a ) {
    thePrinter.startBeginVisit("UDFunctionCallIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const UDFunctionCallIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const StatelessExtFunctionCallIterator& a ) {
    thePrinter.startBeginVisit("StatelessExtFunctionCallIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const StatelessExtFunctionCallIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnStringIterator& a ) {
    thePrinter.startBeginVisit("FnStringIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FnStringIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnBooleanIterator& a ) {
    thePrinter.startBeginVisit("FnBooleanIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FnBooleanIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const LogicIterator& a ) {
    thePrinter.startBeginVisit("LogicIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const LogicIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const CompareIterator& a ) {
    thePrinter.startBeginVisit("CompareIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const CompareIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const ElementIterator& a) {
    thePrinter.startBeginVisit("ElementIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const ElementIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const ElementContentIterator& a ) {
    thePrinter.startBeginVisit("ElementContentIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const ElementContentIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const AttributeIterator& a ) {
    thePrinter.startBeginVisit("AttributeIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const AttributeIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const DocumentIterator& a ) {
    thePrinter.startBeginVisit("DocumentIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const DocumentIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const DocumentContentIterator& a ) {
    thePrinter.startBeginVisit("DocumentContentIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const DocumentContentIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const CommentIterator& a ) {
    thePrinter.startBeginVisit("CommentIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const CommentIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const PiIterator& a ) {
    thePrinter.startBeginVisit("PiIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const PiIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const SingletonIterator& a) {
    thePrinter.startBeginVisit("SingletonIterator", (intptr_t) &a);
    thePrinter.addAttribute("value", a.getValue()->show());
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const SingletonIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const EmptyIterator& a ) {
    thePrinter.startBeginVisit("EmptyIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const EmptyIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const ForVarIterator& a ) {
    thePrinter.startBeginVisit("ForVarIterator", (intptr_t) &a);
    thePrinter.addAttribute("varname", a.getVarName());
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const ForVarIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const LetVarIterator& a ) {
    thePrinter.startBeginVisit("LetVarIterator", (intptr_t) &a);
    thePrinter.addAttribute("varname", a.getVarName());
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const LetVarIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const EnclosedIterator& a ) {
    thePrinter.startBeginVisit("EnclosedIterator", (intptr_t) &a);
    thePrinter.addAttribute("attr_cont", (a.getAttrContent() ? "true" : "false"));
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const EnclosedIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const DocFilterIterator& a ) {
    thePrinter.startBeginVisit("DocFilterIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const DocFilterIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const IfThenElseIterator& a ) {
    thePrinter.startBeginVisit("IfThenElseIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const IfThenElseIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }



  void PrinterVisitor::beginVisit ( const NodeDistinctIterator& a ) {
    thePrinter.startBeginVisit("NodeDistinctIterator", (intptr_t) &a);
    printCommons(  &a);
    thePrinter.endBeginVisit((intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const NodeDistinctIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const NodeSortIterator& a ) {
    thePrinter.startBeginVisit("NodeSortIterator", (intptr_t) &a);
    printCommons(  &a);
    thePrinter.endBeginVisit((intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const NodeSortIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const KindTestIterator& a ) {
    thePrinter.startBeginVisit("KindTestIterator", (intptr_t) &a);
    thePrinter.addAttribute("test kind", toString(a.getTestKind()));
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
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const KindTestIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const NameTestIterator& a ) {
    thePrinter.startBeginVisit("NameTestIterator", (intptr_t) &a);
    if (a.getQName() != NULL)
      thePrinter.addAttribute("qname", a.getQName()->show());
    else
      thePrinter.addAttribute("qname", "*");
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const NameTestIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const SelfAxisIterator& a ) {
    thePrinter.startBeginVisit("SelfAxisIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);

  }
  void PrinterVisitor::endVisit ( const SelfAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const AttributeAxisIterator& a ) {
    thePrinter.startBeginVisit("AttributeAxisIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const AttributeAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const ParentAxisIterator& a ) {
    thePrinter.startBeginVisit("ParentAxisIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const ParentAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const AncestorAxisIterator& a ) {
    thePrinter.startBeginVisit("AncestorAxisIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const AncestorAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const AncestorSelfAxisIterator& a ) {
    thePrinter.startBeginVisit("AncestorSelfAxisIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const AncestorSelfAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const RSiblingAxisIterator& a ) {
    thePrinter.startBeginVisit("RSiblingAxisIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const RSiblingAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const LSiblingAxisIterator& a ) {
    thePrinter.startBeginVisit("LSiblingAxisIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const LSiblingAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const ChildAxisIterator& a ) {
    thePrinter.startBeginVisit("ChildAxisIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const ChildAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const DescendantAxisIterator& a ) {
    thePrinter.startBeginVisit("DescendantAxisIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const DescendantAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const DescendantSelfAxisIterator& a ) {
    thePrinter.startBeginVisit("DescendantSelfAxisIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const DescendantSelfAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const PrecedingAxisIterator& a ) {
    thePrinter.startBeginVisit("PrecedingAxisIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const PrecedingAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FollowingAxisIterator& a ) {
    thePrinter.startBeginVisit("FollowingAxisIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FollowingAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const InstanceOfIterator& a ) {
    thePrinter.startBeginVisit("InstanceOfIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const InstanceOfIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const TreatIterator& a ) {
    thePrinter.startBeginVisit("InstanceOfIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const TreatIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const NumArithIterator<AddOperation>& a ) {
    thePrinter.startBeginVisit("NumArithIterator_AddOperation", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::beginVisit ( const NumArithIterator<SubtractOperation>& a ) {
    thePrinter.startBeginVisit("NumArithIterator_SubtractOperation", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::beginVisit ( const NumArithIterator<MultiplyOperation>& a ) {
    thePrinter.startBeginVisit("NumArithIterator_MultiplyOperation", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::beginVisit ( const NumArithIterator<DivideOperation>& a ) {
    thePrinter.startBeginVisit("NumArithIterator_DivideOperation", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::beginVisit ( const NumArithIterator<IntegerDivideOperation>& a ) {
    thePrinter.startBeginVisit("NumArithIterator_IntegerDivideOperation", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::beginVisit ( const NumArithIterator<ModOperation>& a ) {
    thePrinter.startBeginVisit("NumArithIterator_ModOperation", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const NumArithIterator<AddOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  void PrinterVisitor::endVisit ( const NumArithIterator<SubtractOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  void PrinterVisitor::endVisit ( const NumArithIterator<MultiplyOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  void PrinterVisitor::endVisit ( const NumArithIterator<DivideOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  void PrinterVisitor::endVisit ( const NumArithIterator<IntegerDivideOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  void PrinterVisitor::endVisit ( const NumArithIterator<ModOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const GenericArithIterator<AddOperation>& a ) {
    thePrinter.startBeginVisit("GenericArithIterator_AddOperation", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::beginVisit ( const GenericArithIterator<SubtractOperation>& a ) {
    thePrinter.startBeginVisit("GenericArithIterator_SubtractOperation", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::beginVisit ( const GenericArithIterator<MultiplyOperation>& a ) {
    thePrinter.startBeginVisit("GenericArithIterator_MultiplyOperation", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::beginVisit ( const GenericArithIterator<DivideOperation>& a ) {
    thePrinter.startBeginVisit("GenericArithIterator_DivideOperation", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::beginVisit ( const GenericArithIterator<IntegerDivideOperation>& a ) {
    thePrinter.startBeginVisit("GenericArithIterator_IntegerDivideOperation", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::beginVisit ( const GenericArithIterator<ModOperation>& a ) {
    thePrinter.startBeginVisit("GenericArithIterator_ModOperation", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const GenericArithIterator<AddOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  void PrinterVisitor::endVisit ( const GenericArithIterator<SubtractOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  void PrinterVisitor::endVisit ( const GenericArithIterator<MultiplyOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  void PrinterVisitor::endVisit ( const GenericArithIterator<DivideOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  void PrinterVisitor::endVisit ( const GenericArithIterator<IntegerDivideOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  void PrinterVisitor::endVisit ( const GenericArithIterator<ModOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const OpNumericUnaryIterator& a ) {
    thePrinter.startBeginVisit("OpNumericUnaryIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const OpNumericUnaryIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnAbsIterator& a ) {
    thePrinter.startBeginVisit("FnAbsIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FnAbsIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit( const FnCeilingIterator& a)
  {
    thePrinter.startBeginVisit("FnCeilingIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit( const FnCeilingIterator& )
  {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit( const FnFloorIterator& a )
  {
    thePrinter.startBeginVisit("FnFloorIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit( const FnFloorIterator& )
  {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit( const FnRoundIterator& a)
  {
    thePrinter.startBeginVisit("FnRoundIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit( const FnRoundIterator& )
  {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit( const FnRoundHalfToEvenIterator& a)
  {
    thePrinter.startBeginVisit("FnRoundHalfToEvenIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit( const FnRoundHalfToEvenIterator& )
  {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnConcatIterator& a ) {
    thePrinter.startBeginVisit("FnConcatIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FnConcatIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnEmptyIterator& a ) {
    thePrinter.startBeginVisit("FnEmptyIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FnEmptyIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnExistsIterator& a ) {
    thePrinter.startBeginVisit("FnExistsIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FnExistsIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnIndexOfIterator& a ) {
    thePrinter.startBeginVisit("FnIndexOfIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FnIndexOfIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnRemoveIterator& a ) {
    thePrinter.startBeginVisit("FnRemoveIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FnRemoveIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnReverseIterator& a ) {
    thePrinter.startBeginVisit("FnReverseIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FnReverseIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const OpToIterator& a ) {
    thePrinter.startBeginVisit("OpToIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const OpToIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnDistinctValuesIterator& a ) {
    thePrinter.startBeginVisit("FnDistinctValuesIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FnDistinctValuesIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnInsertBeforeIterator& a ) {
    thePrinter.startBeginVisit("FnInsertBeforeIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FnInsertBeforeIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnSubsequenceIterator& a ) {
    thePrinter.startBeginVisit("FnSubsequenceIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FnSubsequenceIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnZeroOrOneIterator& a ) {
    thePrinter.startBeginVisit("FnZeroOrOneIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FnZeroOrOneIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnOneOrMoreIterator& a ) {
    thePrinter.startBeginVisit("FnOneOrMoreIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FnOneOrMoreIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnExactlyOneIterator& a ) {
    thePrinter.startBeginVisit("FnExactlyOneIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FnExactlyOneIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnCountIterator& a){
    thePrinter.startBeginVisit("FnCountIterator", (intptr_t) &a);
    printCommons(  &a);
    thePrinter.endBeginVisit((intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnCountIterator& ){
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnAvgIterator& a){
    thePrinter.startBeginVisit("FnAvgIterator", (intptr_t) &a);
    printCommons(  &a);
    thePrinter.endBeginVisit((intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnAvgIterator& ){
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnMinMaxIterator& a){
    thePrinter.startBeginVisit("FnMinMaxIterator", (intptr_t) &a);
    thePrinter.addAttribute("type", 
        ((a.getType() == FnMinMaxIterator::MIN) != 0 ? std::string("min") : std::string("max")));
    printCommons(  &a);
    thePrinter.endBeginVisit((intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnMinMaxIterator& ){
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnSumIterator& a){
    thePrinter.startBeginVisit("FnSumIterator", (intptr_t) &a);
    printCommons(  &a);
    thePrinter.endBeginVisit((intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnSumIterator& ){
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnDocIterator& a ) {
    thePrinter.startBeginVisit("FnDocIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FnDocIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnTraceIterator& a ) {
    thePrinter.startBeginVisit("FnTraceIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FnTraceIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const ResolveQNameIterator& a ) {
    thePrinter.startBeginVisit("ResolveQNameIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const ResolveQNameIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const QNameIterator& a ) {
    thePrinter.startBeginVisit("QNameIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const QNameIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const QNameEqualIterator& a ) {
    thePrinter.startBeginVisit("QNameEqualIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const QNameEqualIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const PrefixFromQNameIterator& a ) {
    thePrinter.startBeginVisit("PrefixFromQNameIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const PrefixFromQNameIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const LocalNameFromQNameIterator& a ) {
    thePrinter.startBeginVisit("LocalNameFromQNameIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const LocalNameFromQNameIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const NamespaceUriFromQNameIterator& a ) {
    thePrinter.startBeginVisit("NamespaceUriFromQNameIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const NamespaceUriFromQNameIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const NamespaceUriForPrefixlIterator& a ) {
    thePrinter.startBeginVisit("NamespaceUriForPrefixlIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const NamespaceUriForPrefixlIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const InScopePrefixesIterator& a ) {
    thePrinter.startBeginVisit("InScopePrefixesIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const InScopePrefixesIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const CodepointsToStringIterator& a ) {
    thePrinter.startBeginVisit("CodepointsToStringIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const CodepointsToStringIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const StringToCodepointsIterator& a ) {
    thePrinter.startBeginVisit("StringToCodepointsIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const StringToCodepointsIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const CompareStrIterator& a ) {
    thePrinter.startBeginVisit("CompareStrIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const CompareStrIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const CodepointEqualIterator& a ) {
    thePrinter.startBeginVisit("CodepointEqualIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const CodepointEqualIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const ConcatStrIterator& a ) {
    thePrinter.startBeginVisit("ConcatStrIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const ConcatStrIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const StringJoinIterator& a ) {
    thePrinter.startBeginVisit("StringJoinIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const StringJoinIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const SubstringIterator& a ) {
    thePrinter.startBeginVisit("SubstringIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const SubstringIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const StringLengthIterator& a ) {
    thePrinter.startBeginVisit("StringLengthIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const StringLengthIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const NormalizeSpaceIterator& a ) {
    thePrinter.startBeginVisit("NormalizeSpaceIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const NormalizeSpaceIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const NormalizeUnicodeIterator& a ) {
    thePrinter.startBeginVisit("NormalizeUnicodeIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const NormalizeUnicodeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const UpperCaseIterator& a ) {
    thePrinter.startBeginVisit("UpperCaseIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const UpperCaseIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const LowerCaseIterator& a ) {
    thePrinter.startBeginVisit("LowerCaseIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const LowerCaseIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const TranslateIterator& a ) {
    thePrinter.startBeginVisit("TranslateIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const TranslateIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const EncodeForUriIterator& a ) {
    thePrinter.startBeginVisit("EncodeForUriIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const EncodeForUriIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const IriToUriIterator& a ) {
    thePrinter.startBeginVisit("IriToUriIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const IriToUriIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const EscapeHtmlUriIterator& a ) {
    thePrinter.startBeginVisit("EscapeHtmlUriIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const EscapeHtmlUriIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const ContainsIterator& a ) {
    thePrinter.startBeginVisit("ContainsIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const ContainsIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const StartsWithIterator& a ) {
    thePrinter.startBeginVisit("StartsWithIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const StartsWithIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const EndsWithIterator& a ) {
    thePrinter.startBeginVisit("EndsWithIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const EndsWithIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const SubstringBeforeIterator& a ) {
    thePrinter.startBeginVisit("SubstringBeforeIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const SubstringBeforeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const SubstringAfterIterator& a ) {
    thePrinter.startBeginVisit("SubstringAfterIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const SubstringAfterIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const ZorNumGen& a ) {
    thePrinter.startBeginVisit("ZorNumGen", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const ZorNumGen& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const TextIterator& a )  {
    thePrinter.startBeginVisit("TextIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const TextIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnDateTimeConstructorIterator& a )  {
    thePrinter.startBeginVisit("FnDateTimeConstructorIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FnDateTimeConstructorIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnYearsFromDurationIterator& a )  {
    thePrinter.startBeginVisit("FnYearsFromDurationIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FnYearsFromDurationIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnMonthsFromDurationIterator& a )  {
    thePrinter.startBeginVisit("FnMonthsFromDurationIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnMonthsFromDurationIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnDaysFromDurationIterator& a )  {
    thePrinter.startBeginVisit("FnDaysFromDurationIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnDaysFromDurationIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnHoursFromDurationIterator& a )  {
    thePrinter.startBeginVisit("FnHoursFromDurationIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnHoursFromDurationIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnMinutesFromDurationIterator& a )  {
    thePrinter.startBeginVisit("FnMinutesFromDurationIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnMinutesFromDurationIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnSecondsFromDurationIterator& a )  {
    thePrinter.startBeginVisit("FnSecondsFromDurationIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnSecondsFromDurationIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnYearFromDatetimeIterator& a )  {
    thePrinter.startBeginVisit("FnYearFromDatetimeIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnYearFromDatetimeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnMonthFromDatetimeIterator& a )  {
    thePrinter.startBeginVisit("FnMonthFromDatetimeIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnMonthFromDatetimeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnDayFromDatetimeIterator& a )  {
    thePrinter.startBeginVisit("FnDayFromDatetimeIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnDayFromDatetimeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnHoursFromDatetimeIterator& a )  {
    thePrinter.startBeginVisit("FnHoursFromDatetimeIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnHoursFromDatetimeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnMinutesFromDatetimeIterator& a )  {
    thePrinter.startBeginVisit("FnMinutesFromDatetimeIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnMinutesFromDatetimeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnSecondsFromDatetimeIterator& a )  {
    thePrinter.startBeginVisit("FnSecondsFromDatetimeIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnSecondsFromDatetimeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnTimezoneFromDatetimeIterator& a )  {
    thePrinter.startBeginVisit("FnTimezoneFromDatetimeIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnTimezoneFromDatetimeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnYearFromDateIterator& a )  {
    thePrinter.startBeginVisit("FnYearFromDateIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnYearFromDateIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnMonthFromDateIterator& a )  {
    thePrinter.startBeginVisit("FnMonthFromDateIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnMonthFromDateIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnDayFromDateIterator& a )  {
    thePrinter.startBeginVisit("FnDayFromDateIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnDayFromDateIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnTimezoneFromDateIterator& a )  {
    thePrinter.startBeginVisit("FnTimezoneFromDateIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnTimezoneFromDateIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnHoursFromTimeIterator& a )  {
    thePrinter.startBeginVisit("FnHoursFromTimeIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnHoursFromTimeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnMinutesFromTimeIterator& a )  {
    thePrinter.startBeginVisit("FnMinutesFromTimeIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnMinutesFromTimeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnSecondsFromTimeIterator& a )  {
    thePrinter.startBeginVisit("FnSecondsFromTimeIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnSecondsFromTimeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnTimezoneFromTimeIterator& a )  {
    thePrinter.startBeginVisit("FnTimezoneFromTimeIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit ( const FnTimezoneFromTimeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FLWORIterator& a ) {
    thePrinter.startBeginVisit("FLWORIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const FLWORIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const TryCatchIterator& a ) {
    thePrinter.startBeginVisit("TryCatchIterator", (intptr_t) &a);
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }
  void PrinterVisitor::endVisit ( const TryCatchIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisitFlworWhereClause(const  PlanIterator& a){
    thePrinter.startBeginVisit("WhereClause", (intptr_t) &a);
    thePrinter.endBeginVisit( (intptr_t) &a);
    a.accept(*this);
  }

  void PrinterVisitor::endVisitFlworWhereClause(const PlanIterator& /*a*/){
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  //void PrinterVisitor::beginVisitFlworVariables(){
  //  thePrinter.startBeginVisit("FlworVariables", (intptr_t) &a);
  //}
  //
  //void PrinterVisitor::endVisitFlworVariables(){
  //  thePrinter.startEndVisit();
  //  thePrinter.endEndVisit();
  //}


void PrinterVisitor::beginVisitFlworLetVariable(
      const PlanIterator& a,
      bool materialize,
      const xqpStringStore& varName)
{
  thePrinter.startBeginVisit("LetVariable", (intptr_t) &a);
#ifndef NDEBUG
  thePrinter.addAttribute("name", varName);
#endif
  thePrinter.addAttribute("materialize", materialize ? "true" : "false");
  thePrinter.endBeginVisit( (intptr_t) &a);
  a.accept(*this);
}

void PrinterVisitor::endVisitFlworLetVariable(const PlanIterator& /*a*/)
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}


void PrinterVisitor::beginVisitFlworForVariable(
      const PlanIterator& a,
      const xqpStringStore& varName)
{
  thePrinter.startBeginVisit("ForVariable", (intptr_t) &a);
#ifndef NDEBUG
  thePrinter.addAttribute("name", varName);
#endif
  thePrinter.endBeginVisit( (intptr_t) &a);
  a.accept(*this);
}


void PrinterVisitor::endVisitFlworForVariable(const PlanIterator& /*a*/)
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}


  void PrinterVisitor::beginVisitFlworOrderBy(const PlanIterator& a){
    thePrinter.startBeginVisit("OrderByClause", (intptr_t) &a);
    thePrinter.endBeginVisit( (intptr_t) &a);
    a.accept(*this);
  }    

  void PrinterVisitor::endVisitFlworOrderBy(const PlanIterator& /*a*/){
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisitFlworReturn(const PlanIterator& a){
    thePrinter.startBeginVisit("ReturnClause", (intptr_t) &a);
    thePrinter.endBeginVisit( (intptr_t) &a);
    a.accept(*this);
  }

  void PrinterVisitor::endVisitFlworReturn(const PlanIterator& /*a*/){
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const CastIterator& a) {
    thePrinter.startBeginVisit("CastIterator", (intptr_t) &a);
    std::ostringstream lStream;
    GENV_TYPESYSTEM.serialize(lStream, *a.theCastType);
    thePrinter.addAttribute("type", lStream.str());
    printCommons(  &a );
    thePrinter.endBeginVisit((intptr_t) &a);
  }

  void PrinterVisitor::endVisit(const CastIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const PromoteIterator& a) {
    thePrinter.startBeginVisit("PromoteIterator", (intptr_t) &a);
    std::ostringstream lStream;
    GENV_TYPESYSTEM.serialize(lStream, *a.thePromoteType);
    thePrinter.addAttribute("type", lStream.str());
    printCommons(  &a );
    thePrinter.endBeginVisit((intptr_t) &a);
  }

  void PrinterVisitor::endVisit(const PromoteIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const CastableIterator& a) {
    thePrinter.startBeginVisit("CastableIterator", (intptr_t) &a);
    std::ostringstream lStream;
    GENV_TYPESYSTEM.serialize(lStream, *a.theCastType);
    thePrinter.addAttribute("type", lStream.str());
    printCommons(  &a );
    thePrinter.endBeginVisit((intptr_t) &a);
  }

  void PrinterVisitor::endVisit(const CastableIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const CtxVariableIterator& a) {
    thePrinter.startBeginVisit("CtxVariableIterator", (intptr_t) &a);
    thePrinter.addAttribute("varname", a.getVarName());
    printCommons(  &a );
    thePrinter.endBeginVisit( (intptr_t) &a);
  }

  void PrinterVisitor::endVisit(const CtxVariableIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const OpIsSameNodeIterator& a) {
    thePrinter.startBeginVisit("OpIsSameNodeIterator", (intptr_t) &a);
    printCommons(  &a);
    thePrinter.endBeginVisit((intptr_t) &a);
  }

  void PrinterVisitor::endVisit(const OpIsSameNodeIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const OpNodeBeforeIterator& a) {
    thePrinter.startBeginVisit("OpNodeBeforeIterator", (intptr_t) &a);
    printCommons(  &a);
    thePrinter.endBeginVisit((intptr_t) &a);
  }

  void PrinterVisitor::endVisit(const OpNodeBeforeIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const OpNodeAfterIterator& a) {
    thePrinter.startBeginVisit("OpNodeAfterIterator", (intptr_t) &a);
    printCommons(  &a);
    thePrinter.endBeginVisit((intptr_t) &a);
  }

  void PrinterVisitor::endVisit(const OpNodeAfterIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const FnCurrentDateTimeIterator& a) {
    thePrinter.startBeginVisit("FnCurrentDateTimeIterator", (intptr_t) &a);
    printCommons(  &a);
    thePrinter.endBeginVisit((intptr_t) &a);
  }

  void PrinterVisitor::endVisit(const FnCurrentDateTimeIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const FnCurrentDateIterator& a) {
    thePrinter.startBeginVisit("FnCurrentDateIterator", (intptr_t) &a);
    printCommons(  &a);
    thePrinter.endBeginVisit((intptr_t) &a);
  }

  void PrinterVisitor::endVisit(const FnCurrentDateIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const FnCurrentTimeIterator& a) {
    thePrinter.startBeginVisit("FnCurrentTimeIterator", (intptr_t) &a);
    printCommons(  &a);
    thePrinter.endBeginVisit((intptr_t) &a);
  }

  void PrinterVisitor::endVisit(const FnCurrentTimeIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const FnImplicitTimezoneIterator& a) {
    thePrinter.startBeginVisit("FnImplicitTimezoneIterator", (intptr_t) &a);
    printCommons(  &a);
    thePrinter.endBeginVisit((intptr_t) &a);
  }

  void PrinterVisitor::endVisit(const FnImplicitTimezoneIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const FnDefaultCollationIterator& a) {
    thePrinter.startBeginVisit("FnDefaultCollationIterator", (intptr_t) &a);
    printCommons(  &a);
    thePrinter.endBeginVisit((intptr_t) &a);
  }

  void PrinterVisitor::endVisit(const FnDefaultCollationIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
} /* namespace xqp */
/* vim:set ts=2 sw=2: */

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
#include "runtime/update/update.h"
#include "runtime/misc/MiscImpl.h"
#include "runtime/nodes/NodesImpl.h"
#include "store/api/iterator.h"
#include "util/properties.h"

#include "types/typeops.h"

namespace zorba {

#define PRINTER_VISITOR_DEFINITION(class)  \
  void PrinterVisitor::beginVisit ( const class& a )  {  \
    thePrinter.startBeginVisit(#class, ++theId);  \
    printCommons(  &a, theId );  \
    thePrinter.endBeginVisit( theId); \
  } \
  void PrinterVisitor::endVisit ( const class& ) { \
    thePrinter.startEndVisit(); \
    thePrinter.endEndVisit(); \
  }

  
  void PrinterVisitor::print() {
    thePrinter.start();
    theIterator->accept(*this);
    thePrinter.stop();
  }

  void PrinterVisitor::printCommons(const PlanIterator* aIter, int theId) {
    {
      std::stringstream lStream;
      lStream << aIter->loc;
      thePrinter.addAttribute("loc", lStream.str());
    }
    {
      std::stringstream lStream;
      if (Properties::instance()->stableIteratorIds()) 
        lStream << theId;
      else
        lStream << aIter;
      thePrinter.addAttribute("id", lStream.str());
    }
  }

  void PrinterVisitor::beginVisit ( const FnDataIterator& a) {
    thePrinter.startBeginVisit("FnDataIterator", ++theId);
    printCommons(  &a, theId );
    thePrinter.endBeginVisit( theId);
  }
  void PrinterVisitor::endVisit ( const FnDataIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnRootIterator& a ) {
    thePrinter.startBeginVisit("FnRootIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnRootIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnNodeNameIterator& a ) {
    thePrinter.startBeginVisit("FnNodeNameIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnNodeNameIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  
  void PrinterVisitor::beginVisit ( const FnNilledIterator& a ) {
    thePrinter.startBeginVisit("FnNilledIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnNilledIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnBaseUriIterator& a ) {
    thePrinter.startBeginVisit("FnBaseUriIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  
  void PrinterVisitor::endVisit ( const FnBaseUriIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnDocumentUriIterator& a ) {
    thePrinter.startBeginVisit("FnDocumentUriIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  
  void PrinterVisitor::endVisit ( const FnDocumentUriIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnErrorIterator& a ) {
    thePrinter.startBeginVisit("FnErrorIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  
  void PrinterVisitor::endVisit ( const FnErrorIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnResolveUriIterator& a ) {
    thePrinter.startBeginVisit("FnResolveUriIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  
  void PrinterVisitor::endVisit ( const FnResolveUriIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  
  void PrinterVisitor::beginVisit ( const UDFunctionCallIterator& a ) {
    thePrinter.startBeginVisit("UDFunctionCallIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const UDFunctionCallIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const StatelessExtFunctionCallIterator& a ) {
    thePrinter.startBeginVisit("StatelessExtFunctionCallIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const StatelessExtFunctionCallIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnStringIterator& a ) {
    thePrinter.startBeginVisit("FnStringIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnStringIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnLocalNameIterator& a ) {
    thePrinter.startBeginVisit("FnLocalNameIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnLocalNameIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnNamespaceUriIterator& a ) {
    thePrinter.startBeginVisit("FnNamespaceUriIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnNamespaceUriIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnLangIterator& a ) {
    thePrinter.startBeginVisit("FnLangIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnLangIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnCollectionIterator& a ) {
    thePrinter.startBeginVisit("FnCollectionIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnCollectionIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnBooleanIterator& a ) {
    thePrinter.startBeginVisit("FnBooleanIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnBooleanIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const LogicIterator& a ) {
    thePrinter.startBeginVisit("LogicIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const LogicIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const CompareIterator& a ) {
    thePrinter.startBeginVisit("CompareIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const CompareIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const ElementIterator& a) {
    thePrinter.startBeginVisit("ElementIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const ElementIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const ElementContentIterator& a ) {
    thePrinter.startBeginVisit("ElementContentIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const ElementContentIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const AttributeIterator& a ) {
    thePrinter.startBeginVisit("AttributeIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const AttributeIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const DocumentIterator& a ) {
    thePrinter.startBeginVisit("DocumentIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const DocumentIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const DocumentContentIterator& a ) {
    thePrinter.startBeginVisit("DocumentContentIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const DocumentContentIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const CommentIterator& a ) {
    thePrinter.startBeginVisit("CommentIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const CommentIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const PiIterator& a ) {
    thePrinter.startBeginVisit("PiIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const PiIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const SingletonIterator& a) {
    thePrinter.startBeginVisit("SingletonIterator", ++theId);
    thePrinter.addAttribute("value", a.getValue()->show());
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const SingletonIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const EmptyIterator& a ) {
    thePrinter.startBeginVisit("EmptyIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const EmptyIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const ForVarIterator& a ) {
    thePrinter.startBeginVisit("ForVarIterator", ++theId);
    thePrinter.addAttribute("varname", a.getVarName());
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const ForVarIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const LetVarIterator& a ) {
    thePrinter.startBeginVisit("LetVarIterator", ++theId);
    thePrinter.addAttribute("varname", a.getVarName());
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const LetVarIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const EnclosedIterator& a ) {
    thePrinter.startBeginVisit("EnclosedIterator", ++theId);
    thePrinter.addAttribute("attr_cont", (a.getAttrContent() ? "true" : "false"));
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const EnclosedIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const IfThenElseIterator& a ) {
    thePrinter.startBeginVisit("IfThenElseIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const IfThenElseIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }



  void PrinterVisitor::beginVisit ( const NodeDistinctIterator& a ) {
    thePrinter.startBeginVisit("NodeDistinctIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(++theId);
  }

  void PrinterVisitor::endVisit ( const NodeDistinctIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const NodeSortIterator& a ) {
    thePrinter.startBeginVisit("NodeSortIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(++theId);
  }

  void PrinterVisitor::endVisit ( const NodeSortIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const KindTestIterator& a ) {
    thePrinter.startBeginVisit("KindTestIterator", ++theId);
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
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const KindTestIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const NameTestIterator& a ) {
    thePrinter.startBeginVisit("NameTestIterator", ++theId);
    if (a.getQName() != NULL)
      thePrinter.addAttribute("qname", a.getQName()->show());
    else
      thePrinter.addAttribute("qname", "*");
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const NameTestIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const SelfAxisIterator& a ) {
    thePrinter.startBeginVisit("SelfAxisIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);

  }
  void PrinterVisitor::endVisit ( const SelfAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const AttributeAxisIterator& a ) {
    thePrinter.startBeginVisit("AttributeAxisIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const AttributeAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const ParentAxisIterator& a ) {
    thePrinter.startBeginVisit("ParentAxisIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const ParentAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const AncestorAxisIterator& a ) {
    thePrinter.startBeginVisit("AncestorAxisIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const AncestorAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const AncestorSelfAxisIterator& a ) {
    thePrinter.startBeginVisit("AncestorSelfAxisIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const AncestorSelfAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const RSiblingAxisIterator& a ) {
    thePrinter.startBeginVisit("RSiblingAxisIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const RSiblingAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const LSiblingAxisIterator& a ) {
    thePrinter.startBeginVisit("LSiblingAxisIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const LSiblingAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const ChildAxisIterator& a ) {
    thePrinter.startBeginVisit("ChildAxisIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const ChildAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const DescendantAxisIterator& a ) {
    thePrinter.startBeginVisit("DescendantAxisIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const DescendantAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const DescendantSelfAxisIterator& a ) {
    thePrinter.startBeginVisit("DescendantSelfAxisIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const DescendantSelfAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const PrecedingAxisIterator& a ) {
    thePrinter.startBeginVisit("PrecedingAxisIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const PrecedingAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FollowingAxisIterator& a ) {
    thePrinter.startBeginVisit("FollowingAxisIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FollowingAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const InstanceOfIterator& a ) {
    thePrinter.startBeginVisit("InstanceOfIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const InstanceOfIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const TreatIterator& a ) {
    thePrinter.startBeginVisit("TreatIterator", ++theId);
    if (a.check_prime)
      thePrinter.addAttribute("type", TypeOps::toString(*a.theTreatType));
    thePrinter.addAttribute("quant", TypeOps::decode_quantifier (a.theQuantifier));
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const TreatIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const EitherNodesOrAtomicsIterator& a ) {
    thePrinter.startBeginVisit("EitherNodesOrAtomicsIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const EitherNodesOrAtomicsIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const NumArithIterator<AddOperation>& a ) {
    thePrinter.startBeginVisit("NumArithIterator_AddOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::beginVisit ( const NumArithIterator<SubtractOperation>& a ) {
    thePrinter.startBeginVisit("NumArithIterator_SubtractOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::beginVisit ( const NumArithIterator<MultiplyOperation>& a ) {
    thePrinter.startBeginVisit("NumArithIterator_MultiplyOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::beginVisit ( const NumArithIterator<DivideOperation>& a ) {
    thePrinter.startBeginVisit("NumArithIterator_DivideOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::beginVisit ( const NumArithIterator<IntegerDivideOperation>& a ) {
    thePrinter.startBeginVisit("NumArithIterator_IntegerDivideOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::beginVisit ( const NumArithIterator<ModOperation>& a ) {
    thePrinter.startBeginVisit("NumArithIterator_ModOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
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
    thePrinter.startBeginVisit("GenericArithIterator_AddOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::beginVisit ( const GenericArithIterator<SubtractOperation>& a ) {
    thePrinter.startBeginVisit("GenericArithIterator_SubtractOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::beginVisit ( const GenericArithIterator<MultiplyOperation>& a ) {
    thePrinter.startBeginVisit("GenericArithIterator_MultiplyOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::beginVisit ( const GenericArithIterator<DivideOperation>& a ) {
    thePrinter.startBeginVisit("GenericArithIterator_DivideOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::beginVisit ( const GenericArithIterator<IntegerDivideOperation>& a ) {
    thePrinter.startBeginVisit("GenericArithIterator_IntegerDivideOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::beginVisit ( const GenericArithIterator<ModOperation>& a ) {
    thePrinter.startBeginVisit("GenericArithIterator_ModOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
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
    thePrinter.startBeginVisit("OpNumericUnaryIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const OpNumericUnaryIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnAbsIterator& a ) {
    thePrinter.startBeginVisit("FnAbsIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnAbsIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit( const FnCeilingIterator& a)
  {
    thePrinter.startBeginVisit("FnCeilingIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit( const FnCeilingIterator& )
  {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit( const FnFloorIterator& a )
  {
    thePrinter.startBeginVisit("FnFloorIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit( const FnFloorIterator& )
  {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit( const FnRoundIterator& a)
  {
    thePrinter.startBeginVisit("FnRoundIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit( const FnRoundIterator& )
  {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit( const FnRoundHalfToEvenIterator& a)
  {
    thePrinter.startBeginVisit("FnRoundHalfToEvenIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit( const FnRoundHalfToEvenIterator& )
  {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnConcatIterator& a ) {
    thePrinter.startBeginVisit("FnConcatIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnConcatIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnEmptyIterator& a ) {
    thePrinter.startBeginVisit("FnEmptyIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnEmptyIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnExistsIterator& a ) {
    thePrinter.startBeginVisit("FnExistsIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnExistsIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnIndexOfIterator& a ) {
    thePrinter.startBeginVisit("FnIndexOfIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnIndexOfIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnRemoveIterator& a ) {
    thePrinter.startBeginVisit("FnRemoveIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnRemoveIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnReverseIterator& a ) {
    thePrinter.startBeginVisit("FnReverseIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnReverseIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const OpToIterator& a ) {
    thePrinter.startBeginVisit("OpToIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit (const OpToIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnIdIterator& a ) {
    thePrinter.startBeginVisit("FnIdIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit (const FnIdIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnIdRefIterator& a ) {
    thePrinter.startBeginVisit("FnIdRefIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit (const FnIdRefIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnDistinctValuesIterator& a ) {
    thePrinter.startBeginVisit("FnDistinctValuesIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnDistinctValuesIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnInsertBeforeIterator& a ) {
    thePrinter.startBeginVisit("FnInsertBeforeIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnInsertBeforeIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnSubsequenceIterator& a ) {
    thePrinter.startBeginVisit("FnSubsequenceIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnSubsequenceIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnZeroOrOneIterator& a ) {
    thePrinter.startBeginVisit("FnZeroOrOneIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnZeroOrOneIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnOneOrMoreIterator& a ) {
    thePrinter.startBeginVisit("FnOneOrMoreIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnOneOrMoreIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnExactlyOneIterator& a ) {
    thePrinter.startBeginVisit("FnExactlyOneIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnExactlyOneIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnCountIterator& a){
    thePrinter.startBeginVisit("FnCountIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(++theId);
  }

  void PrinterVisitor::endVisit ( const FnCountIterator& ){
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnAvgIterator& a){
    thePrinter.startBeginVisit("FnAvgIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(++theId);
  }

  void PrinterVisitor::endVisit ( const FnAvgIterator& ){
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnMinMaxIterator& a){
    thePrinter.startBeginVisit("FnMinMaxIterator", ++theId);
    thePrinter.addAttribute("type", 
        ((a.getType() == FnMinMaxIterator::MIN) != 0 ? std::string("min") : std::string("max")));
    printCommons( &a, theId );
    thePrinter.endBeginVisit(++theId);
  }

  void PrinterVisitor::endVisit ( const FnMinMaxIterator& ){
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnSumIterator& a){
    thePrinter.startBeginVisit("FnSumIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(++theId);
  }

  void PrinterVisitor::endVisit ( const FnSumIterator& ){
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnDocIterator& a ) {
    thePrinter.startBeginVisit("FnDocIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnDocIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnDocAvailableIterator& a ) {
    thePrinter.startBeginVisit("FnDocAvailableIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnDocAvailableIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void 
  PrinterVisitor::beginVisit ( const HashSemiJoinIterator& a) 
  {
    thePrinter.startBeginVisit("HashSemiJoinIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void 
  PrinterVisitor::endVisit ( const HashSemiJoinIterator& ) 
  {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void
  PrinterVisitor::beginVisit ( const SortSemiJoinIterator& a) 
  {
    thePrinter.startBeginVisit("SortSemiJoinIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void 
  PrinterVisitor::endVisit ( const SortSemiJoinIterator& ) 
  {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnTraceIterator& a ) {
    thePrinter.startBeginVisit("FnTraceIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnTraceIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const ResolveQNameIterator& a ) {
    thePrinter.startBeginVisit("ResolveQNameIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const ResolveQNameIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const QNameIterator& a ) {
    thePrinter.startBeginVisit("QNameIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const QNameIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const QNameEqualIterator& a ) {
    thePrinter.startBeginVisit("QNameEqualIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const QNameEqualIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const PrefixFromQNameIterator& a ) {
    thePrinter.startBeginVisit("PrefixFromQNameIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const PrefixFromQNameIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const LocalNameFromQNameIterator& a ) {
    thePrinter.startBeginVisit("LocalNameFromQNameIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const LocalNameFromQNameIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const NamespaceUriFromQNameIterator& a ) {
    thePrinter.startBeginVisit("NamespaceUriFromQNameIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const NamespaceUriFromQNameIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const NamespaceUriForPrefixlIterator& a ) {
    thePrinter.startBeginVisit("NamespaceUriForPrefixlIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const NamespaceUriForPrefixlIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const InScopePrefixesIterator& a ) {
    thePrinter.startBeginVisit("InScopePrefixesIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const InScopePrefixesIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const CodepointsToStringIterator& a ) {
    thePrinter.startBeginVisit("CodepointsToStringIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const CodepointsToStringIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const StringToCodepointsIterator& a ) {
    thePrinter.startBeginVisit("StringToCodepointsIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const StringToCodepointsIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const CompareStrIterator& a ) {
    thePrinter.startBeginVisit("CompareStrIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const CompareStrIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const CodepointEqualIterator& a ) {
    thePrinter.startBeginVisit("CodepointEqualIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const CodepointEqualIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const ConcatStrIterator& a ) {
    thePrinter.startBeginVisit("ConcatStrIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const ConcatStrIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const StringJoinIterator& a ) {
    thePrinter.startBeginVisit("StringJoinIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const StringJoinIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const SubstringIterator& a ) {
    thePrinter.startBeginVisit("SubstringIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const SubstringIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const StringLengthIterator& a ) {
    thePrinter.startBeginVisit("StringLengthIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const StringLengthIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const NormalizeSpaceIterator& a ) {
    thePrinter.startBeginVisit("NormalizeSpaceIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const NormalizeSpaceIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const NormalizeUnicodeIterator& a ) {
    thePrinter.startBeginVisit("NormalizeUnicodeIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const NormalizeUnicodeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const UpperCaseIterator& a ) {
    thePrinter.startBeginVisit("UpperCaseIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const UpperCaseIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const LowerCaseIterator& a ) {
    thePrinter.startBeginVisit("LowerCaseIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const LowerCaseIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const TranslateIterator& a ) {
    thePrinter.startBeginVisit("TranslateIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const TranslateIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const EncodeForUriIterator& a ) {
    thePrinter.startBeginVisit("EncodeForUriIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const EncodeForUriIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const IriToUriIterator& a ) {
    thePrinter.startBeginVisit("IriToUriIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const IriToUriIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const EscapeHtmlUriIterator& a ) {
    thePrinter.startBeginVisit("EscapeHtmlUriIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const EscapeHtmlUriIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const ContainsIterator& a ) {
    thePrinter.startBeginVisit("ContainsIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const ContainsIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const StartsWithIterator& a ) {
    thePrinter.startBeginVisit("StartsWithIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const StartsWithIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const EndsWithIterator& a ) {
    thePrinter.startBeginVisit("EndsWithIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const EndsWithIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const SubstringBeforeIterator& a ) {
    thePrinter.startBeginVisit("SubstringBeforeIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const SubstringBeforeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const SubstringAfterIterator& a ) {
    thePrinter.startBeginVisit("SubstringAfterIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const SubstringAfterIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  
  void PrinterVisitor::beginVisit ( const FnMatchesIterator& a ) {
    thePrinter.startBeginVisit("FnMatchesIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnMatchesIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  
  void PrinterVisitor::beginVisit ( const FnReplaceIterator& a ) {
    thePrinter.startBeginVisit("FnReplaceIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnReplaceIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  
  void PrinterVisitor::beginVisit ( const FnTokenizeIterator& a ) {
    thePrinter.startBeginVisit("FnTokenizeIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnTokenizeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const ZorNumGen& a ) {
    thePrinter.startBeginVisit("ZorNumGen", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const ZorNumGen& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const TextIterator& a )  {
    thePrinter.startBeginVisit("TextIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const TextIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnDateTimeConstructorIterator& a )  {
    thePrinter.startBeginVisit("FnDateTimeConstructorIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnDateTimeConstructorIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnYearsFromDurationIterator& a )  {
    thePrinter.startBeginVisit("FnYearsFromDurationIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FnYearsFromDurationIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnMonthsFromDurationIterator& a )  {
    thePrinter.startBeginVisit("FnMonthsFromDurationIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const FnMonthsFromDurationIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnDaysFromDurationIterator& a )  {
    thePrinter.startBeginVisit("FnDaysFromDurationIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const FnDaysFromDurationIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnHoursFromDurationIterator& a )  {
    thePrinter.startBeginVisit("FnHoursFromDurationIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const FnHoursFromDurationIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnMinutesFromDurationIterator& a )  {
    thePrinter.startBeginVisit("FnMinutesFromDurationIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const FnMinutesFromDurationIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnSecondsFromDurationIterator& a )  {
    thePrinter.startBeginVisit("FnSecondsFromDurationIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const FnSecondsFromDurationIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnYearFromDatetimeIterator& a )  {
    thePrinter.startBeginVisit("FnYearFromDatetimeIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const FnYearFromDatetimeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnMonthFromDatetimeIterator& a )  {
    thePrinter.startBeginVisit("FnMonthFromDatetimeIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const FnMonthFromDatetimeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnDayFromDatetimeIterator& a )  {
    thePrinter.startBeginVisit("FnDayFromDatetimeIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const FnDayFromDatetimeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnHoursFromDatetimeIterator& a )  {
    thePrinter.startBeginVisit("FnHoursFromDatetimeIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const FnHoursFromDatetimeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnMinutesFromDatetimeIterator& a )  {
    thePrinter.startBeginVisit("FnMinutesFromDatetimeIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const FnMinutesFromDatetimeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnSecondsFromDatetimeIterator& a )  {
    thePrinter.startBeginVisit("FnSecondsFromDatetimeIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const FnSecondsFromDatetimeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnTimezoneFromDatetimeIterator& a )  {
    thePrinter.startBeginVisit("FnTimezoneFromDatetimeIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const FnTimezoneFromDatetimeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnYearFromDateIterator& a )  {
    thePrinter.startBeginVisit("FnYearFromDateIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const FnYearFromDateIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnMonthFromDateIterator& a )  {
    thePrinter.startBeginVisit("FnMonthFromDateIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const FnMonthFromDateIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnDayFromDateIterator& a )  {
    thePrinter.startBeginVisit("FnDayFromDateIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const FnDayFromDateIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnTimezoneFromDateIterator& a )  {
    thePrinter.startBeginVisit("FnTimezoneFromDateIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const FnTimezoneFromDateIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnHoursFromTimeIterator& a )  {
    thePrinter.startBeginVisit("FnHoursFromTimeIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const FnHoursFromTimeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnMinutesFromTimeIterator& a )  {
    thePrinter.startBeginVisit("FnMinutesFromTimeIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const FnMinutesFromTimeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnSecondsFromTimeIterator& a )  {
    thePrinter.startBeginVisit("FnSecondsFromTimeIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const FnSecondsFromTimeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FnTimezoneFromTimeIterator& a )  {
    thePrinter.startBeginVisit("FnTimezoneFromTimeIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit ( const FnTimezoneFromTimeIterator& ) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const FLWORIterator& a ) {
    thePrinter.startBeginVisit("FLWORIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const FLWORIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit ( const TryCatchIterator& a ) {
    thePrinter.startBeginVisit("TryCatchIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void PrinterVisitor::endVisit ( const TryCatchIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisitFlworWhereClause(const  PlanIterator& a){
    thePrinter.startBeginVisit("WhereClause", ++theId);
    thePrinter.endBeginVisit(theId);
    a.accept(*this);
  }

  void PrinterVisitor::endVisitFlworWhereClause(const PlanIterator& /*a*/){
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  //void PrinterVisitor::beginVisitFlworVariables(){
  //  thePrinter.startBeginVisit("FlworVariables", ++theId);
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
  thePrinter.startBeginVisit("LetVariable", ++theId);
#ifndef NDEBUG
  thePrinter.addAttribute("name", varName.str());
#endif
  thePrinter.addAttribute("materialize", materialize ? "true" : "false");
  thePrinter.endBeginVisit(theId);
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
  thePrinter.startBeginVisit("ForVariable", ++theId);
#ifndef NDEBUG
  thePrinter.addAttribute("name", varName.str());
#endif
  thePrinter.endBeginVisit(theId);
  a.accept(*this);
}


void PrinterVisitor::endVisitFlworForVariable(const PlanIterator& /*a*/)
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisitFlworGroupBy(const PlanIterator& a) {
  thePrinter.startBeginVisit("GroupByClause", ++theId);
  thePrinter.endBeginVisit(theId);
  a.accept(*this);
}

void PrinterVisitor::endVisitFlworGroupBy(const PlanIterator& a) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}


  void PrinterVisitor::beginVisitFlworOrderBy(const PlanIterator& a){
    thePrinter.startBeginVisit("OrderByClause", ++theId);
    thePrinter.endBeginVisit(theId);
    a.accept(*this);
  }    

  void PrinterVisitor::endVisitFlworOrderBy(const PlanIterator& /*a*/){
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisitFlworReturn(const PlanIterator& a){
    thePrinter.startBeginVisit("ReturnClause", ++theId);
    thePrinter.endBeginVisit(theId);
    a.accept(*this);
  }

  void PrinterVisitor::endVisitFlworReturn(const PlanIterator& /*a*/){
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const CastIterator& a) {
    thePrinter.startBeginVisit("CastIterator", ++theId);
    std::ostringstream lStream;
    TypeOps::serialize(lStream, *a.theCastType);
    thePrinter.addAttribute("type", lStream.str());
    printCommons( &a, theId );
    thePrinter.endBeginVisit(++theId);
  }

  void PrinterVisitor::endVisit(const CastIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const NameCastIterator& a) {
    thePrinter.startBeginVisit("NameCastIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(++theId);
  }

  void PrinterVisitor::endVisit(const NameCastIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const PromoteIterator& a) {
    thePrinter.startBeginVisit("PromoteIterator", ++theId);
    std::ostringstream lStream;
    TypeOps::serialize(lStream, *a.thePromoteType);
    thePrinter.addAttribute("type", lStream.str());
    printCommons( &a, theId );
    thePrinter.endBeginVisit(++theId);
  }

  void PrinterVisitor::endVisit(const PromoteIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const CastableIterator& a) {
    thePrinter.startBeginVisit("CastableIterator", ++theId);
    std::ostringstream lStream;
    TypeOps::serialize(lStream, *a.theCastType);
    thePrinter.addAttribute("type", lStream.str());
    printCommons( &a, theId );
    thePrinter.endBeginVisit(++theId);
  }

  void PrinterVisitor::endVisit(const CastableIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const CtxVariableIterator& a) {
    thePrinter.startBeginVisit("CtxVariableIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit(const CtxVariableIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const OpIsSameNodeIterator& a) {
    thePrinter.startBeginVisit("OpIsSameNodeIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(++theId);
  }

  void PrinterVisitor::endVisit(const OpIsSameNodeIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const OpNodeBeforeIterator& a) {
    thePrinter.startBeginVisit("OpNodeBeforeIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(++theId);
  }

  void PrinterVisitor::endVisit(const OpNodeBeforeIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const OpNodeAfterIterator& a) {
    thePrinter.startBeginVisit("OpNodeAfterIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(++theId);
  }

  void PrinterVisitor::endVisit(const OpNodeAfterIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const FnCurrentDateTimeIterator& a) {
    thePrinter.startBeginVisit("FnCurrentDateTimeIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(++theId);
  }

  void PrinterVisitor::endVisit(const FnCurrentDateTimeIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const FnCurrentDateIterator& a) {
    thePrinter.startBeginVisit("FnCurrentDateIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(++theId);
  }

  void PrinterVisitor::endVisit(const FnCurrentDateIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const FnCurrentTimeIterator& a) {
    thePrinter.startBeginVisit("FnCurrentTimeIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(++theId);
  }

  void PrinterVisitor::endVisit(const FnCurrentTimeIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const FnImplicitTimezoneIterator& a) {
    thePrinter.startBeginVisit("FnImplicitTimezoneIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(++theId);
  }

  void PrinterVisitor::endVisit(const FnImplicitTimezoneIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const FnDefaultCollationIterator& a) {
    thePrinter.startBeginVisit("FnDefaultCollationIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(++theId);
  }

  void PrinterVisitor::endVisit(const FnDefaultCollationIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  
  PRINTER_VISITOR_DEFINITION(FnAdjustToTimeZoneIterator_1);
  PRINTER_VISITOR_DEFINITION(FnAdjustToTimeZoneIterator_2);
  PRINTER_VISITOR_DEFINITION(InsertIterator);
  PRINTER_VISITOR_DEFINITION(DeleteIterator);
  PRINTER_VISITOR_DEFINITION(ReplaceIterator);
  PRINTER_VISITOR_DEFINITION(RenameIterator);
  PRINTER_VISITOR_DEFINITION(TransformIterator);
  PRINTER_VISITOR_DEFINITION(FnDeepEqualIterator);
} /* namespace zorba */
/* vim:set ts=2 sw=2: */


#include <sstream>

#include "common/common.h"

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
#ifdef ZORBA_WITH_REST
#include "runtime/rest/rest.h"
#endif
#include "types/root_typemanager.h"
#include "runtime/visitors/iterprinter.h"
#include "runtime/update/update.h"
#include "runtime/misc/MiscImpl.h"
#include "runtime/nodes/NodesImpl.h"
#include "store/api/iterator.h"
#include "util/properties.h"

#include "types/typeops.h"

namespace zorba {

#define PRINTER_VISITOR_DEFINITION(class)                \
  void beginVisit ( const class& a )  {                  \
    thePrinter.startBeginVisit(#class, ++theId);         \
    printCommons(  &a, theId );                          \
    thePrinter.endBeginVisit( theId);                    \
  }                                                      \
  void endVisit ( const class& ) {                       \
    thePrinter.startEndVisit();                          \
    thePrinter.endEndVisit();                            \
  }


class PrinterVisitor : public PlanIterVisitor
{
private:
  IterPrinter& thePrinter;
  PlanIterator* theIterator;
  int      theId;

public:
  PrinterVisitor(IterPrinter& aPrinter, PlanIterator* aIter)
    : thePrinter(aPrinter),
      theIterator(aIter),
      theId(0)
  {}

  void print() {
    thePrinter.start();
    theIterator->accept(*this);
    thePrinter.stop();
  }

  void printCommons(const PlanIterator* aIter, int theId) {
    if (! Properties::instance()->noTreeIds()) {
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
  }

  PRINTER_VISITOR_DEFINITION (FnDataIterator)

  PRINTER_VISITOR_DEFINITION (FnRootIterator)

  PRINTER_VISITOR_DEFINITION (FnNodeNameIterator)

  PRINTER_VISITOR_DEFINITION (FnNilledIterator)

  PRINTER_VISITOR_DEFINITION (FnBaseUriIterator)

  PRINTER_VISITOR_DEFINITION (FnDocumentUriIterator)

  PRINTER_VISITOR_DEFINITION (FnErrorIterator)

  PRINTER_VISITOR_DEFINITION (FnResolveUriIterator)

  PRINTER_VISITOR_DEFINITION (UDFunctionCallIterator)

  PRINTER_VISITOR_DEFINITION (StatelessExtFunctionCallIterator)

  PRINTER_VISITOR_DEFINITION (FnStringIterator)

  PRINTER_VISITOR_DEFINITION (FnLocalNameIterator)

  PRINTER_VISITOR_DEFINITION (FnNamespaceUriIterator)

  PRINTER_VISITOR_DEFINITION (FnLangIterator)

  PRINTER_VISITOR_DEFINITION (FnCollectionIterator)

  PRINTER_VISITOR_DEFINITION (FnBooleanIterator)

  PRINTER_VISITOR_DEFINITION (LogicIterator)

  PRINTER_VISITOR_DEFINITION (CompareIterator)

  PRINTER_VISITOR_DEFINITION (ElementIterator)

  PRINTER_VISITOR_DEFINITION (ElementContentIterator)

  PRINTER_VISITOR_DEFINITION (AttributeIterator)

  PRINTER_VISITOR_DEFINITION (DocumentIterator)

  PRINTER_VISITOR_DEFINITION (DocumentContentIterator)

  PRINTER_VISITOR_DEFINITION (CommentIterator)

  PRINTER_VISITOR_DEFINITION (PiIterator)

  void beginVisit ( const SingletonIterator& a) {
    thePrinter.startBeginVisit("SingletonIterator", ++theId);
    thePrinter.addAttribute("value", a.getValue()->show());
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void endVisit ( const SingletonIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  PRINTER_VISITOR_DEFINITION (EmptyIterator)

  void beginVisit ( const ForVarIterator& a ) {
    thePrinter.startBeginVisit("ForVarIterator", ++theId);
    thePrinter.addAttribute("varname", a.getVarName());
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void endVisit ( const ForVarIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void beginVisit ( const LetVarIterator& a ) {
    thePrinter.startBeginVisit("LetVarIterator", ++theId);
    thePrinter.addAttribute("varname", a.getVarName());
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void endVisit ( const LetVarIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void beginVisit ( const EnclosedIterator& a ) {
    thePrinter.startBeginVisit("EnclosedIterator", ++theId);
    thePrinter.addAttribute("attr_cont", (a.getAttrContent() ? "true" : "false"));
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void endVisit ( const EnclosedIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  PRINTER_VISITOR_DEFINITION (IfThenElseIterator)



  PRINTER_VISITOR_DEFINITION (NodeDistinctIterator)

  PRINTER_VISITOR_DEFINITION (NodeSortIterator)

  void beginVisit ( const KindTestIterator& a ) {
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
  void endVisit ( const KindTestIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void beginVisit ( const NameTestIterator& a ) {
    thePrinter.startBeginVisit("NameTestIterator", ++theId);
    if (a.getQName() != NULL)
      thePrinter.addAttribute("qname", a.getQName()->show());
    else
      thePrinter.addAttribute("qname", "*");
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void endVisit ( const NameTestIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void beginVisit ( const SelfAxisIterator& a ) {
    thePrinter.startBeginVisit("SelfAxisIterator", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);

  }
  void endVisit ( const SelfAxisIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  PRINTER_VISITOR_DEFINITION (AttributeAxisIterator)

  PRINTER_VISITOR_DEFINITION (ParentAxisIterator)

  PRINTER_VISITOR_DEFINITION (AncestorAxisIterator)

  PRINTER_VISITOR_DEFINITION (AncestorSelfAxisIterator)

  PRINTER_VISITOR_DEFINITION (RSiblingAxisIterator)

  PRINTER_VISITOR_DEFINITION (LSiblingAxisIterator)

  PRINTER_VISITOR_DEFINITION (ChildAxisIterator)

  PRINTER_VISITOR_DEFINITION (DescendantAxisIterator)

  PRINTER_VISITOR_DEFINITION (DescendantSelfAxisIterator)

  PRINTER_VISITOR_DEFINITION (PrecedingAxisIterator)

  PRINTER_VISITOR_DEFINITION (FollowingAxisIterator)

  PRINTER_VISITOR_DEFINITION (InstanceOfIterator)

  void beginVisit ( const TreatIterator& a ) {
    thePrinter.startBeginVisit("TreatIterator", ++theId);
    if (a.check_prime)
      thePrinter.addAttribute("type", TypeOps::toString(*a.theTreatType));
    thePrinter.addAttribute("quant", TypeOps::decode_quantifier (a.theQuantifier));
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void endVisit ( const TreatIterator& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  PRINTER_VISITOR_DEFINITION (EitherNodesOrAtomicsIterator)

  void beginVisit ( const NumArithIterator<AddOperation>& a ) {
    thePrinter.startBeginVisit("NumArithIterator_AddOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void beginVisit ( const NumArithIterator<SubtractOperation>& a ) {
    thePrinter.startBeginVisit("NumArithIterator_SubtractOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void beginVisit ( const NumArithIterator<MultiplyOperation>& a ) {
    thePrinter.startBeginVisit("NumArithIterator_MultiplyOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void beginVisit ( const NumArithIterator<DivideOperation>& a ) {
    thePrinter.startBeginVisit("NumArithIterator_DivideOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void beginVisit ( const NumArithIterator<IntegerDivideOperation>& a ) {
    thePrinter.startBeginVisit("NumArithIterator_IntegerDivideOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void beginVisit ( const NumArithIterator<ModOperation>& a ) {
    thePrinter.startBeginVisit("NumArithIterator_ModOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void endVisit ( const NumArithIterator<AddOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  void endVisit ( const NumArithIterator<SubtractOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  void endVisit ( const NumArithIterator<MultiplyOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  void endVisit ( const NumArithIterator<DivideOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  void endVisit ( const NumArithIterator<IntegerDivideOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  void endVisit ( const NumArithIterator<ModOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void beginVisit ( const GenericArithIterator<AddOperation>& a ) {
    thePrinter.startBeginVisit("GenericArithIterator_AddOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void beginVisit ( const GenericArithIterator<SubtractOperation>& a ) {
    thePrinter.startBeginVisit("GenericArithIterator_SubtractOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void beginVisit ( const GenericArithIterator<MultiplyOperation>& a ) {
    thePrinter.startBeginVisit("GenericArithIterator_MultiplyOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void beginVisit ( const GenericArithIterator<DivideOperation>& a ) {
    thePrinter.startBeginVisit("GenericArithIterator_DivideOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void beginVisit ( const GenericArithIterator<IntegerDivideOperation>& a ) {
    thePrinter.startBeginVisit("GenericArithIterator_IntegerDivideOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void beginVisit ( const GenericArithIterator<ModOperation>& a ) {
    thePrinter.startBeginVisit("GenericArithIterator_ModOperation", ++theId);
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }
  void endVisit ( const GenericArithIterator<AddOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  void endVisit ( const GenericArithIterator<SubtractOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  void endVisit ( const GenericArithIterator<MultiplyOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  void endVisit ( const GenericArithIterator<DivideOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  void endVisit ( const GenericArithIterator<IntegerDivideOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }
  void endVisit ( const GenericArithIterator<ModOperation>& /*a*/) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  PRINTER_VISITOR_DEFINITION (OpNumericUnaryIterator)

  PRINTER_VISITOR_DEFINITION (FnAbsIterator)

  PRINTER_VISITOR_DEFINITION (FnCeilingIterator)

  PRINTER_VISITOR_DEFINITION (FnFloorIterator)

  PRINTER_VISITOR_DEFINITION (FnRoundIterator)

  PRINTER_VISITOR_DEFINITION (FnRoundHalfToEvenIterator)

  PRINTER_VISITOR_DEFINITION (FnConcatIterator)

  PRINTER_VISITOR_DEFINITION (FnEmptyIterator)

  PRINTER_VISITOR_DEFINITION (FnExistsIterator)

  PRINTER_VISITOR_DEFINITION (FnIndexOfIterator)

  PRINTER_VISITOR_DEFINITION (FnRemoveIterator)

  PRINTER_VISITOR_DEFINITION (FnReverseIterator)

  PRINTER_VISITOR_DEFINITION (OpToIterator)

  PRINTER_VISITOR_DEFINITION (FnIdIterator)

  PRINTER_VISITOR_DEFINITION (FnIdRefIterator)

  PRINTER_VISITOR_DEFINITION (FnDistinctValuesIterator)

  PRINTER_VISITOR_DEFINITION (FnInsertBeforeIterator)

  PRINTER_VISITOR_DEFINITION (FnSubsequenceIterator)

  PRINTER_VISITOR_DEFINITION (FnZeroOrOneIterator)

  PRINTER_VISITOR_DEFINITION (FnOneOrMoreIterator)

  PRINTER_VISITOR_DEFINITION (FnExactlyOneIterator)

  PRINTER_VISITOR_DEFINITION (FnCountIterator)

  PRINTER_VISITOR_DEFINITION (FnAvgIterator)

  void beginVisit ( const FnMinMaxIterator& a){
    thePrinter.startBeginVisit("FnMinMaxIterator", ++theId);
    thePrinter.addAttribute("type",
        ((a.getType() == FnMinMaxIterator::MIN) != 0 ? std::string("min") : std::string("max")));
    printCommons( &a, theId );
    thePrinter.endBeginVisit(++theId);
  }

  void endVisit ( const FnMinMaxIterator& ){
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  PRINTER_VISITOR_DEFINITION (FnSumIterator)

  PRINTER_VISITOR_DEFINITION (FnDocIterator)

  PRINTER_VISITOR_DEFINITION (FnDocAvailableIterator)

  PRINTER_VISITOR_DEFINITION (HashSemiJoinIterator)

  PRINTER_VISITOR_DEFINITION (SortSemiJoinIterator)

  PRINTER_VISITOR_DEFINITION (FnTraceIterator)

  PRINTER_VISITOR_DEFINITION (ResolveQNameIterator)

  PRINTER_VISITOR_DEFINITION (QNameIterator)

  PRINTER_VISITOR_DEFINITION (QNameEqualIterator)

  PRINTER_VISITOR_DEFINITION (PrefixFromQNameIterator)

  PRINTER_VISITOR_DEFINITION (LocalNameFromQNameIterator)

  PRINTER_VISITOR_DEFINITION (NamespaceUriFromQNameIterator)

  PRINTER_VISITOR_DEFINITION (NamespaceUriForPrefixlIterator)

  PRINTER_VISITOR_DEFINITION (InScopePrefixesIterator)

  PRINTER_VISITOR_DEFINITION (CodepointsToStringIterator)

  PRINTER_VISITOR_DEFINITION (StringToCodepointsIterator)

  PRINTER_VISITOR_DEFINITION (CompareStrIterator)

  PRINTER_VISITOR_DEFINITION (CodepointEqualIterator)

  PRINTER_VISITOR_DEFINITION (ConcatStrIterator)

  PRINTER_VISITOR_DEFINITION (StringJoinIterator)

  PRINTER_VISITOR_DEFINITION (SubstringIterator)

  PRINTER_VISITOR_DEFINITION (StringLengthIterator)

  PRINTER_VISITOR_DEFINITION (NormalizeSpaceIterator)

  PRINTER_VISITOR_DEFINITION (NormalizeUnicodeIterator)

  PRINTER_VISITOR_DEFINITION (UpperCaseIterator)

  PRINTER_VISITOR_DEFINITION (LowerCaseIterator)

  PRINTER_VISITOR_DEFINITION (TranslateIterator)

  PRINTER_VISITOR_DEFINITION (EncodeForUriIterator)

  PRINTER_VISITOR_DEFINITION (IriToUriIterator)

  PRINTER_VISITOR_DEFINITION (EscapeHtmlUriIterator)

  PRINTER_VISITOR_DEFINITION (ContainsIterator)

  PRINTER_VISITOR_DEFINITION (StartsWithIterator)

  PRINTER_VISITOR_DEFINITION (EndsWithIterator)

  PRINTER_VISITOR_DEFINITION (SubstringBeforeIterator)

  PRINTER_VISITOR_DEFINITION (SubstringAfterIterator)

  PRINTER_VISITOR_DEFINITION (FnMatchesIterator)

  PRINTER_VISITOR_DEFINITION (FnReplaceIterator)

  PRINTER_VISITOR_DEFINITION (FnTokenizeIterator)

  PRINTER_VISITOR_DEFINITION (ZorNumGen)

  PRINTER_VISITOR_DEFINITION (TextIterator)

  PRINTER_VISITOR_DEFINITION (FnDateTimeConstructorIterator)

  PRINTER_VISITOR_DEFINITION (FnYearsFromDurationIterator)

  PRINTER_VISITOR_DEFINITION (FnMonthsFromDurationIterator)

  PRINTER_VISITOR_DEFINITION (FnDaysFromDurationIterator)

  PRINTER_VISITOR_DEFINITION (FnHoursFromDurationIterator)

  PRINTER_VISITOR_DEFINITION (FnMinutesFromDurationIterator)

  PRINTER_VISITOR_DEFINITION (FnSecondsFromDurationIterator)

  PRINTER_VISITOR_DEFINITION (FnYearFromDatetimeIterator)

  PRINTER_VISITOR_DEFINITION (FnMonthFromDatetimeIterator)

  PRINTER_VISITOR_DEFINITION (FnDayFromDatetimeIterator)

  PRINTER_VISITOR_DEFINITION (FnHoursFromDatetimeIterator)

  PRINTER_VISITOR_DEFINITION (FnMinutesFromDatetimeIterator)

  PRINTER_VISITOR_DEFINITION (FnSecondsFromDatetimeIterator)

  PRINTER_VISITOR_DEFINITION (FnTimezoneFromDatetimeIterator)

  PRINTER_VISITOR_DEFINITION (FnYearFromDateIterator)

  PRINTER_VISITOR_DEFINITION (FnMonthFromDateIterator)

  PRINTER_VISITOR_DEFINITION (FnDayFromDateIterator)

  PRINTER_VISITOR_DEFINITION (FnTimezoneFromDateIterator)

  PRINTER_VISITOR_DEFINITION (FnHoursFromTimeIterator)

  PRINTER_VISITOR_DEFINITION (FnMinutesFromTimeIterator)

  PRINTER_VISITOR_DEFINITION (FnSecondsFromTimeIterator)

  PRINTER_VISITOR_DEFINITION (FnTimezoneFromTimeIterator)

  PRINTER_VISITOR_DEFINITION (FLWORIterator)

  PRINTER_VISITOR_DEFINITION (TryCatchIterator)

  void beginVisitFlworWhereClause(const  PlanIterator& a){
    thePrinter.startBeginVisit("WhereClause", ++theId);
    thePrinter.endBeginVisit(theId);
    a.accept(*this);
  }

  void endVisitFlworWhereClause(const PlanIterator& /*a*/){
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  //void beginVisitFlworVariables(){
  //  thePrinter.startBeginVisit("FlworVariables", ++theId);
  //}
  //
  //void endVisitFlworVariables(){
  //  thePrinter.startEndVisit();
  //  thePrinter.endEndVisit();
  //}


void beginVisitFlworLetVariable(
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

void endVisitFlworLetVariable(const PlanIterator& /*a*/)
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}


void beginVisitFlworForVariable(
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


void endVisitFlworForVariable(const PlanIterator& /*a*/)
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void beginVisitFlworGroupBy(const PlanIterator& a) {
  thePrinter.startBeginVisit("GroupByClause", ++theId);
  thePrinter.endBeginVisit(theId);
  a.accept(*this);
}

void endVisitFlworGroupBy(const PlanIterator& a) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}


  void beginVisitFlworOrderBy(const PlanIterator& a){
    thePrinter.startBeginVisit("OrderByClause", ++theId);
    thePrinter.endBeginVisit(theId);
    a.accept(*this);
  }

  void endVisitFlworOrderBy(const PlanIterator& /*a*/){
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void beginVisitFlworReturn(const PlanIterator& a){
    thePrinter.startBeginVisit("ReturnClause", ++theId);
    thePrinter.endBeginVisit(theId);
    a.accept(*this);
  }

  void endVisitFlworReturn(const PlanIterator& /*a*/){
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void beginVisit(const CastIterator& a) {
    thePrinter.startBeginVisit("CastIterator", ++theId);
    std::ostringstream lStream;
    TypeOps::serialize(lStream, *a.theCastType);
    thePrinter.addAttribute("type", lStream.str());
    printCommons( &a, theId );
    thePrinter.endBeginVisit(++theId);
  }

  void endVisit(const CastIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  PRINTER_VISITOR_DEFINITION (NameCastIterator)

  void beginVisit(const PromoteIterator& a) {
    thePrinter.startBeginVisit("PromoteIterator", ++theId);
    std::ostringstream lStream;
    TypeOps::serialize(lStream, *a.thePromoteType);
    thePrinter.addAttribute("type", lStream.str());
    printCommons( &a, theId );
    thePrinter.endBeginVisit(++theId);
  }

  void endVisit(const PromoteIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void beginVisit(const CastableIterator& a) {
    thePrinter.startBeginVisit("CastableIterator", ++theId);
    std::ostringstream lStream;
    TypeOps::serialize(lStream, *a.theCastType);
    thePrinter.addAttribute("type", lStream.str());
    printCommons( &a, theId );
    thePrinter.endBeginVisit(++theId);
  }

  void endVisit(const CastableIterator&) {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  PRINTER_VISITOR_DEFINITION (CtxVariableIterator)

  PRINTER_VISITOR_DEFINITION (EvalIterator)

  PRINTER_VISITOR_DEFINITION (OpIsSameNodeIterator)

  PRINTER_VISITOR_DEFINITION (OpNodeBeforeIterator)

  PRINTER_VISITOR_DEFINITION (OpNodeAfterIterator)

  PRINTER_VISITOR_DEFINITION (FnCurrentDateTimeIterator)

  PRINTER_VISITOR_DEFINITION (FnCurrentDateIterator)

  PRINTER_VISITOR_DEFINITION (FnCurrentTimeIterator)

  PRINTER_VISITOR_DEFINITION (FnImplicitTimezoneIterator)

  PRINTER_VISITOR_DEFINITION (FnDefaultCollationIterator)

  PRINTER_VISITOR_DEFINITION(FnAdjustToTimeZoneIterator_1);

  PRINTER_VISITOR_DEFINITION(FnAdjustToTimeZoneIterator_2);

  PRINTER_VISITOR_DEFINITION(InsertIterator);

  PRINTER_VISITOR_DEFINITION(DeleteIterator);

  PRINTER_VISITOR_DEFINITION(ReplaceIterator);

  PRINTER_VISITOR_DEFINITION(RenameIterator);

  PRINTER_VISITOR_DEFINITION(TransformIterator);

  PRINTER_VISITOR_DEFINITION(FnDeepEqualIterator);

#ifdef ZORBA_WITH_REST
  PRINTER_VISITOR_DEFINITION(ZorbaRestGetIterator);
#endif

};

void print_iter_plan (IterPrinter& aPrinter, PlanIterator* aIter) {
  PrinterVisitor v (aPrinter, aIter);
  v.print ();
}

} /* namespace zorba */
/* vim:set ts=2 sw=2: */


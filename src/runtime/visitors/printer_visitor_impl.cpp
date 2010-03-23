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
 
#include "runtime/visitors/printer_visitor.h"

#include "types/typeops.h"
#include "util/properties.h"

#include "runtime/core/item_iterator.h"
#include "runtime/core/var_iterators.h"
#include "runtime/core/constructors.h"
#include "runtime/core/path_iterators.h"
#include "runtime/core/fncall_iterator.h"
#include "runtime/core/sequencetypes.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/core/gflwor/let_iterator.h"
#include "runtime/core/gflwor/for_iterator.h"
#include "runtime/core/gflwor/outerfor_iterator.h"
#include "runtime/core/gflwor/count_iterator.h"
#include "runtime/core/gflwor/where_iterator.h"
#include "runtime/core/gflwor/tuplesource_iterator.h"
#include "runtime/core/gflwor/tuplestream_iterator.h"
#include "runtime/core/gflwor/groupby_iterator.h"
#include "runtime/core/gflwor/window_iterator.h"
#include "runtime/core/flwor_iterator.h"
#include "runtime/core/tuple_iterators.h"
#include "runtime/core/trycatch.h"
#include "runtime/core/apply_updates.h"
#include "runtime/core/nodeid_iterators.h"
#include "runtime/core/internal_operators.h"
#include "runtime/numerics/NumericsImpl.h"
#include "runtime/core/arithmetic_impl.h"
#include "runtime/sequences/SequencesImpl.h"
#include "runtime/durations_dates_times/DurationsDatesTimesImpl.h"
#include "runtime/debug/zorba_debug_iterator.h"
#include "debugger/zorba_debugger_commons.h"
#include "runtime/util/UtilImpl.h"
#include "context/static_context.h"
#include "context/namespace_context.h"

#ifdef ZORBA_WITH_REST
#include "runtime/rest/rest.h"
#endif
#ifdef ZORBA_WITH_FOP
#include "runtime/fop/FopImpl.h"
#endif // ZORBA_WITH_FOP

#include "runtime/visitors/iterprinter.h"
#include "runtime/update/update.h"

namespace zorba{

#define PRINTER_VISITOR_DEFINITION(class)                \
  void PrinterVisitor::beginVisit ( const class& a )  {                  \
    thePrinter.startBeginVisit(#class, ++theId);         \
    printCommons(  &a, theId );                          \
    thePrinter.endBeginVisit( theId);                    \
  }                                                      \
  void PrinterVisitor::endVisit ( const class& ) {                       \
    thePrinter.startEndVisit();                          \
    thePrinter.endEndVisit();                            \
  }


#define PRINTER_VISITOR_AXIS_DEFINITION(class)           \
  void PrinterVisitor::beginVisit ( const class& a )  {                  \
    thePrinter.startBeginVisit(#class, ++theId);         \
    printCommons(&a, theId);                             \
    printNameOrKindTest(&a);                             \
    thePrinter.endBeginVisit( theId);                    \
  }                                                      \
  void PrinterVisitor::endVisit ( const class& ) {                       \
    thePrinter.startEndVisit();                          \
    thePrinter.endEndVisit();                            \
  }

void PrinterVisitor::beginVisit ( const SingletonIterator& a) {
  thePrinter.startBeginVisit("SingletonIterator", ++theId);
  thePrinter.addAttribute("value", a.getValue()->show());
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}

void PrinterVisitor::endVisit ( const SingletonIterator&) {
      thePrinter.startEndVisit();
      thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisit ( const EnclosedIterator& a ) {
  thePrinter.startBeginVisit("EnclosedIterator", ++theId);
  thePrinter.addAttribute("attr_cont", (a.getAttrContent() ? "true" :
      "false"));
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::endVisit ( const EnclosedIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisit ( const NodeSortIterator& a )
{
  thePrinter.startBeginVisit("NodeSortIterator", ++theId);
  printCommons(&a, theId);
  thePrinter.addAttribute("distinct", (a.getDistinct() ? "true" : "false"));
  thePrinter.addAttribute("ascending", (a.getAscending() ? "true" : "false"));
  thePrinter.endBeginVisit( theId);
}

void PrinterVisitor::endVisit ( const NodeSortIterator& ) 
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

#if 0
void PrinterVisitor::beginVisit ( const PathIterator& a ) 
{
  thePrinter.startBeginVisit("PathIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}

void PrinterVisitor::endVisit(const PathIterator& ) 
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
#endif

void PrinterVisitor::beginVisit ( const SelfAxisIterator& a )
{
  thePrinter.startBeginVisit("SelfAxisIteratorator", ++theId);
  printCommons( &a, theId );
  printNameOrKindTest(&a);
  thePrinter.endBeginVisit(theId);
}

void PrinterVisitor::endVisit(const SelfAxisIterator&) 
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisit ( const TreatIterator& a ) {
  thePrinter.startBeginVisit("TreatIterator", ++theId);
  if (a.check_prime)
    thePrinter.addAttribute("type", TypeOps::toString(*a.theTreatType));
  thePrinter.addAttribute("quant", TypeOps::decode_quantifier
      (a.theQuantifier));
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}

void PrinterVisitor::endVisit ( const TreatIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisit ( const NumArithIterator<AddOperation>& a ) {
  thePrinter.startBeginVisit("NumArithIterator_AddOperation", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const NumArithIterator<SubtractOperation>& a )
{
  thePrinter.startBeginVisit("NumArithIterator_SubtractOperation", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const NumArithIterator<MultiplyOperation>& a )
{
  thePrinter.startBeginVisit("NumArithIterator_MultiplyOperation", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const NumArithIterator<DivideOperation>& a ) {
  thePrinter.startBeginVisit("NumArithIterator_DivideOperation", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const
NumArithIterator<IntegerDivideOperation>& a ) {
  thePrinter.startBeginVisit("NumArithIterator_IntegerDivideOperation",
                              ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}

void PrinterVisitor::beginVisit ( const NumArithIterator<ModOperation>& a ) {
  thePrinter.startBeginVisit("NumArithIterator_ModOperation", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::endVisit ( const NumArithIterator<AddOperation>& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const NumArithIterator<SubtractOperation>&) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const NumArithIterator<MultiplyOperation>& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const NumArithIterator<DivideOperation>&) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const NumArithIterator<IntegerDivideOperation>&
) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const NumArithIterator<ModOperation>& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisit ( const GenericArithIterator<AddOperation>& a )
{
  thePrinter.startBeginVisit("GenericArithIterator_AddOperation", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const GenericArithIterator<SubtractOperation>&
a ) {
  thePrinter.startBeginVisit("GenericArithIterator_SubtractOperation",
                              ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const GenericArithIterator<MultiplyOperation>&
a ) {
  thePrinter.startBeginVisit("GenericArithIterator_MultiplyOperation",
                              ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const GenericArithIterator<DivideOperation>& a
) {
  thePrinter.startBeginVisit("GenericArithIterator_DivideOperation", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const
GenericArithIterator<IntegerDivideOperation>& a ) {
  thePrinter.startBeginVisit("GenericArithIterator_IntegerDivideOperation",
                              ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const GenericArithIterator<ModOperation>& a )
{
  thePrinter.startBeginVisit("GenericArithIterator_ModOperation", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}

void PrinterVisitor::endVisit ( const GenericArithIterator<AddOperation>& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const GenericArithIterator<SubtractOperation>& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const GenericArithIterator<MultiplyOperation>& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const GenericArithIterator<DivideOperation>& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const
GenericArithIterator<IntegerDivideOperation>& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const GenericArithIterator<ModOperation>& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisit ( const SpecificNumArithIterator<AddOperation,
                    TypeConstants::XS_DECIMAL>& a)
{
  thePrinter.startBeginVisit("SpecificNumArithIterator_AddOperation_DECIMAL",
                             ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const SpecificNumArithIterator<AddOperation,
                    TypeConstants::XS_INTEGER>& a)
{
  thePrinter.startBeginVisit("SpecificNumArithIterator_AddOperation_INTEGER",
                             ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const SpecificNumArithIterator<AddOperation,
                    TypeConstants::XS_FLOAT>& a)
{
  thePrinter.startBeginVisit("SpecificNumArithIterator_AddOperation_FLOAT",
                             ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const SpecificNumArithIterator<AddOperation,
                    TypeConstants::XS_DOUBLE>& a)
{
  thePrinter.startBeginVisit("SpecificNumArithIterator_AddOperation_DOUBLE",
                             ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const
SpecificNumArithIterator<SubtractOperation,
                    TypeConstants::XS_DECIMAL>& a)
{
thePrinter.startBeginVisit("SpecificNumArithIterator_SubtractOperation_DECIMAL",
                             ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}

void PrinterVisitor::beginVisit ( const
SpecificNumArithIterator<SubtractOperation,
                    TypeConstants::XS_INTEGER>& a)
{
thePrinter.startBeginVisit("SpecificNumArithIterator_SubtractOperation_INTEGER",
                             ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const
SpecificNumArithIterator<SubtractOperation,
                    TypeConstants::XS_FLOAT>& a)
{
  thePrinter.startBeginVisit("SpecificNumArithIterator_SubtractOperation_FLOAT",
                             ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const
SpecificNumArithIterator<SubtractOperation,
                    TypeConstants::XS_DOUBLE>& a)
{
thePrinter.startBeginVisit("SpecificNumArithIterator_SubtractOperation_DOUBLE",
                             ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const
SpecificNumArithIterator<MultiplyOperation,
                    TypeConstants::XS_DECIMAL>& a)
{
thePrinter.startBeginVisit("SpecificNumArithIterator_MultiplyOperation_DECIMAL",
                             ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const
SpecificNumArithIterator<MultiplyOperation,
                    TypeConstants::XS_INTEGER>& a)
{
thePrinter.startBeginVisit("SpecificNumArithIterator_MultiplyOperation_INTEGER",
                             ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}

void PrinterVisitor::beginVisit ( const
SpecificNumArithIterator<MultiplyOperation,
                    TypeConstants::XS_FLOAT>& a)
{
  thePrinter.startBeginVisit("SpecificNumArithIterator_MultiplyOperation_FLOAT",
                             ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const
SpecificNumArithIterator<MultiplyOperation,
                    TypeConstants::XS_DOUBLE>& a)
{
thePrinter.startBeginVisit("SpecificNumArithIterator_MultiplyOperation_DOUBLE",
                             ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const
SpecificNumArithIterator<DivideOperation,
                    TypeConstants::XS_DECIMAL>& a)
{
  thePrinter.startBeginVisit("SpecificNumArithIterator_DivideOperation_DECIMAL",
                             ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const
SpecificNumArithIterator<DivideOperation,
                    TypeConstants::XS_INTEGER>& a)
{
  thePrinter.startBeginVisit("SpecificNumArithIterator_DivideOperation_INTEGER",
                             ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const
SpecificNumArithIterator<DivideOperation,
                    TypeConstants::XS_FLOAT>& a)
{
  thePrinter.startBeginVisit("SpecificNumArithIterator_DivideOperation_FLOAT",
                             ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}

void PrinterVisitor::beginVisit ( const
SpecificNumArithIterator<DivideOperation,
                    TypeConstants::XS_DOUBLE>& a)
{
   
  thePrinter.startBeginVisit("SpecificNumArithIterator_DivideOperation_DOUBLE",
                             ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const SpecificNumArithIterator<ModOperation,
                    TypeConstants::XS_DECIMAL>& a)
{
  thePrinter.startBeginVisit("SpecificNumArithIterator_ModOperation_DECIMAL",
                             ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const SpecificNumArithIterator<ModOperation,
                    TypeConstants::XS_INTEGER>& a)
{
  thePrinter.startBeginVisit("SpecificNumArithIterator_ModOperation_INTEGER",
                             ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const SpecificNumArithIterator<ModOperation,
                    TypeConstants::XS_FLOAT>& a)
{
  thePrinter.startBeginVisit("SpecificNumArithIterator_ModOperation_FLOAT",
                             ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}
void PrinterVisitor::beginVisit ( const SpecificNumArithIterator<ModOperation,
                    TypeConstants::XS_DOUBLE>& a)
{
  thePrinter.startBeginVisit("SpecificNumArithIterator_ModOperation_DOUBLE",
                             ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}

void PrinterVisitor::endVisit ( const SpecificNumArithIterator<AddOperation,
                  TypeConstants::XS_DECIMAL>& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const SpecificNumArithIterator<AddOperation,
                  TypeConstants::XS_INTEGER>& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const SpecificNumArithIterator<AddOperation,
                  TypeConstants::XS_FLOAT>& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const SpecificNumArithIterator<AddOperation,
                  TypeConstants::XS_DOUBLE>& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const
SpecificNumArithIterator<SubtractOperation,
                    TypeConstants::XS_DECIMAL>& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::endVisit ( const
SpecificNumArithIterator<SubtractOperation,
                  TypeConstants::XS_INTEGER>& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const
SpecificNumArithIterator<SubtractOperation,
                  TypeConstants::XS_FLOAT>& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const
SpecificNumArithIterator<SubtractOperation,
                  TypeConstants::XS_DOUBLE>& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const
SpecificNumArithIterator<MultiplyOperation,
                  TypeConstants::XS_DECIMAL>& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const
SpecificNumArithIterator<MultiplyOperation,
                  TypeConstants::XS_INTEGER>& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::endVisit ( const
SpecificNumArithIterator<MultiplyOperation,
                  TypeConstants::XS_FLOAT>& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const
SpecificNumArithIterator<MultiplyOperation,
                  TypeConstants::XS_DOUBLE>& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const SpecificNumArithIterator<DivideOperation,
                  TypeConstants::XS_DECIMAL>& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const SpecificNumArithIterator<DivideOperation,
                  TypeConstants::XS_INTEGER>& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const SpecificNumArithIterator<DivideOperation,
                  TypeConstants::XS_FLOAT>& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::endVisit ( const SpecificNumArithIterator<DivideOperation,
                  TypeConstants::XS_DOUBLE>& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const SpecificNumArithIterator<ModOperation,
                  TypeConstants::XS_DECIMAL>& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const SpecificNumArithIterator<ModOperation,
                  TypeConstants::XS_INTEGER>& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const SpecificNumArithIterator<ModOperation,
                  TypeConstants::XS_FLOAT>& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
void PrinterVisitor::endVisit ( const SpecificNumArithIterator<ModOperation,
                  TypeConstants::XS_DOUBLE>& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisit ( const FnMinMaxIterator& a)
{
  thePrinter.startBeginVisit("FnMinMaxIterator", ++theId);
  thePrinter.addAttribute("type",
      ((a.getType() == FnMinMaxIterator::MIN) != 0 ? std::string("min") :
          std::string("max")));
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}

void PrinterVisitor::endVisit ( const FnMinMaxIterator& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisit(const ForVarIterator& a)
{
  thePrinter.startBeginVisit("ForVarIterator", ++theId);
  thePrinter.addAttribute("varname", a.getVarName()->getStringValue()->c_str());
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}

void PrinterVisitor::endVisit(const ForVarIterator& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisit(const LetVarIterator& a) 
{
  thePrinter.startBeginVisit("LetVarIterator", ++theId);

  thePrinter.addAttribute("varname", a.getVarName()->getStringValue()->c_str());

  if (a.getTargetPos() > 0)
    thePrinter.addAttribute("targetPos", a.getTargetPos());

  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}

void PrinterVisitor::endVisit(const LetVarIterator& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisitFlworWhereClause(const PlanIterator& a)
{
  thePrinter.startBeginVisit("WhereClause", ++theId);
  thePrinter.endBeginVisit(theId);
  a.accept(*this);
}


void PrinterVisitor::endVisitFlworWhereClause(const PlanIterator& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}


void PrinterVisitor::beginVisitFlworLetVariable(
    bool materialize,
    const xqpStringStore_t varName,
    const std::vector<PlanIter_t>& varRefs)
{
  thePrinter.startBeginVisit("LetVariable", ++theId);

  thePrinter.addAttribute("name", varName->str());

  thePrinter.addAttribute("materialize", materialize ? "true" : "false");

  std::ostringstream str;

  ulong numRefs = varRefs.size();
  for (ulong i = 0; i < numRefs; i++)
  {
    str << varRefs[i].getp();
    if (i < numRefs-1)
      str << " ";
  }

  if (! Properties::instance()->noTreeIds())
    thePrinter.addAttribute("referenced-by", str.str());

  thePrinter.endBeginVisit(theId);
}


void PrinterVisitor::endVisitFlworLetVariable()
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}


void PrinterVisitor::beginVisitFlworForVariable(
    const xqpStringStore_t varName,
    const std::vector<PlanIter_t>& varRefs,
    const std::vector<PlanIter_t>& posRefs)
{
  thePrinter.startBeginVisit("ForVariable", ++theId);

  thePrinter.addAttribute("name", varName->str());

  std::ostringstream str;

  ulong numRefs = varRefs.size();
  for (ulong i = 0; i < numRefs; i++)
  {
    str << varRefs[i].getp();
    if (i < numRefs-1)
      str << " ";
  }

  if (! Properties::instance()->noTreeIds())
    thePrinter.addAttribute("referenced-by", str.str());

  if (!posRefs.empty())
  {
    std::ostringstream str;

    ulong numRefs = posRefs.size();
    for (ulong i = 0; i < numRefs; i++)
    {
      str << posRefs[i].getp();
      if (i < numRefs-1)
        str << " ";
    }
    
    if (! Properties::instance()->noTreeIds())
      thePrinter.addAttribute("pos-referenced-by", str.str());
  }


  thePrinter.endBeginVisit(theId);
}


void PrinterVisitor::endVisitFlworForVariable()
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}


void PrinterVisitor::beginVisitGroupByClause()
{
  thePrinter.startBeginVisit("GroupByClause", ++theId);
  thePrinter.endBeginVisit(theId);
}


void PrinterVisitor::endVisitGroupByClause()
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}


void PrinterVisitor::beginVisitGroupBySpec()
{
  thePrinter.startBeginVisit("Spec", theId);
  thePrinter.endBeginVisit(theId);
}


void PrinterVisitor::endVisitGroupBySpec()
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}


void PrinterVisitor::beginVisitGroupByOuter()
{
  thePrinter.startBeginVisit("Spec", theId);
  thePrinter.endBeginVisit(theId);
}


void PrinterVisitor::endVisitGroupByOuter()
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}


void PrinterVisitor::beginVisitGroupVariable(const std::vector<ForVarIter_t>& varRefs)
{
  thePrinter.startBeginVisit("GroupVariable", ++theId);

  std::ostringstream str;

  ulong numRefs = varRefs.size();
  for (ulong i = 0; i < numRefs; i++)
  {
    str << varRefs[i].getp();
    if (i < numRefs-1)
      str << " ";
  }

  if (! Properties::instance()->noTreeIds())
    thePrinter.addAttribute("referenced-by", str.str());

  thePrinter.endBeginVisit(theId);
}


void PrinterVisitor::endVisitGroupVariable()
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}


void PrinterVisitor::beginVisitNonGroupVariable(const std::vector<LetVarIter_t>& varRefs)
{
  thePrinter.startBeginVisit("NonGroupVariable", ++theId);

  std::ostringstream str;

  ulong numRefs = varRefs.size();
  for (ulong i = 0; i < numRefs; i++)
  {
    str << varRefs[i].getp();
    if (i < numRefs-1)
      str << " ";
  }

  if (! Properties::instance()->noTreeIds())
    thePrinter.addAttribute("referenced-by", str.str());

  thePrinter.endBeginVisit(theId);
}


void PrinterVisitor::endVisitNonGroupVariable()
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}


void PrinterVisitor::beginVisitOrderBy(const PlanIterator& a)
{
  thePrinter.startBeginVisit("OrderByClause", ++theId);
  thePrinter.endBeginVisit(theId);
  a.accept(*this);
}


void PrinterVisitor::endVisitOrderBy(const PlanIterator& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}


void PrinterVisitor::beginVisitOrderByForVariable(
    ForVarIter_t inputVar,
    const std::vector<PlanIter_t>& varRefs)
{
  thePrinter.startBeginVisit("OrderByForVariable", theId);

  std::ostringstream str1;
  std::ostringstream str2;

  str1 << inputVar->getVarName()->getStringValue()->str() << " : " <<
      inputVar.getp();

  ulong numRefs = varRefs.size();
  for (ulong i = 0; i < numRefs; i++)
  {
    str2 << varRefs[i].getp();
    if (i < numRefs-1)
      str2 << " ";
  }

  thePrinter.addAttribute("inputVar : ", str1.str());
  if (! Properties::instance()->noTreeIds())
    thePrinter.addAttribute("referenced-by", str2.str());

  thePrinter.endBeginVisit(theId);
}


void PrinterVisitor::endVisitOrderByForVariable()
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}


void PrinterVisitor::beginVisitOrderByLetVariable(
    LetVarIter_t inputVar,
    const std::vector<PlanIter_t>& varRefs)
{
  thePrinter.startBeginVisit("OrderByLetVariable", theId);

  std::ostringstream str1;
  std::ostringstream str2;

  str1 << inputVar->getVarName()->getStringValue()->str() << " : " <<
      inputVar.getp();

  ulong numRefs = varRefs.size();
  for (ulong i = 0; i < numRefs; i++)
  {
    str2 << varRefs[i].getp();
    if (i < numRefs-1)
      str2 << " ";
  }

  thePrinter.addAttribute("inputVar : ", str1.str());
  if (! Properties::instance()->noTreeIds())
    thePrinter.addAttribute("referenced-by", str2.str());

  thePrinter.endBeginVisit(theId);
}


void PrinterVisitor::endVisitOrderByLetVariable()
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}


void PrinterVisitor::beginVisitWindowVariable(
                              const std::string& varName,
                              const std::vector<LetVarIter_t>& varRefs)
{
  thePrinter.startBeginVisit("WindowVariable", theId);

  thePrinter.addAttribute("name", varName);

  std::ostringstream str;

  ulong numRefs = varRefs.size();
  for (ulong i = 0; i < numRefs; i++)
  {
    str << varRefs[i].getp();
    if (i < numRefs-1)
      str << " ";
  }

  if (! Properties::instance()->noTreeIds())
    thePrinter.addAttribute("referenced-by", str.str());

  thePrinter.endBeginVisit(theId);
}


void PrinterVisitor::endVisitWindowVariable()
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}


void PrinterVisitor::beginVisitWinCondVariable(
    const std::string& varName,
    const std::vector<PlanIter_t>& varRefs)
{
  thePrinter.startBeginVisit("WinCondVariable", theId);

  thePrinter.addAttribute("name", varName);

  std::ostringstream str;

  ulong numRefs = varRefs.size();
  for (ulong i = 0; i < numRefs; i++)
  {
    str << varRefs[i].getp();
    if (i < numRefs-1)
      str << " ";
  }

  if (! Properties::instance()->noTreeIds())
    thePrinter.addAttribute("referenced-by", str.str());

  thePrinter.endBeginVisit(theId);
}


void PrinterVisitor::endVisitWinCondVariable()
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisitFlworReturn(const PlanIterator& a)
{
  thePrinter.startBeginVisit("ReturnClause", ++theId);
  thePrinter.endBeginVisit(theId);
  a.accept(*this);
}

void PrinterVisitor::endVisitFlworReturn(const PlanIterator& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisit(const CastIterator& a) {
  thePrinter.startBeginVisit("CastIterator", ++theId);
  std::ostringstream lStream;
  TypeOps::serialize(lStream, *a.theCastType);
  thePrinter.addAttribute("type", lStream.str());
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}

void PrinterVisitor::endVisit(const CastIterator&) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisit(const PromoteIterator& a) {
  thePrinter.startBeginVisit("PromoteIterator", ++theId);
  std::ostringstream lStream;
  TypeOps::serialize(lStream, *a.thePromoteType);
  thePrinter.addAttribute("type", lStream.str());
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
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
  thePrinter.endBeginVisit(theId);
}

void PrinterVisitor::endVisit(const CastableIterator&) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

#define TYPED_VAL_CMP( xqt )                                            \
void PrinterVisitor::beginVisit ( const TypedValueCompareIterator<TypeConstants::XS_##xqt>& a){\
    thePrinter.startBeginVisit("TypedValueCompareIterator_" #xqt, ++theId); \
    printCommons( &a, theId );                                          \
    thePrinter.endBeginVisit(theId);                                    \
}                                                                     \
                                                                        \
void PrinterVisitor::endVisit ( const TypedValueCompareIterator<TypeConstants::XS_##xqt>& a){\
    thePrinter.startEndVisit();                                         \
    thePrinter.endEndVisit();                                           \
}

  TYPED_VAL_CMP (DECIMAL)
  TYPED_VAL_CMP (INTEGER)
  TYPED_VAL_CMP (DOUBLE)
  TYPED_VAL_CMP (FLOAT)
  TYPED_VAL_CMP (STRING)

#undef TYPED_VAL_CMP

#ifdef ZORBA_WITH_TIDY
  PRINTER_VISITOR_DEFINITION(ZorbaTidyIterator);
  PRINTER_VISITOR_DEFINITION(ZorbaTDocIterator);
#endif  // ZORBA_WITH_TIDY
#ifdef ZORBA_WITH_REST
  PRINTER_VISITOR_DEFINITION(ZorbaRestGetIterator);
  PRINTER_VISITOR_DEFINITION(ZorbaRestPostIterator);
  PRINTER_VISITOR_DEFINITION(ZorbaRestPutIterator);
  PRINTER_VISITOR_DEFINITION(ZorbaRestDeleteIterator);
  PRINTER_VISITOR_DEFINITION(ZorbaRestHeadIterator);
#endif

#ifdef ZORBA_WITH_FOP
  PRINTER_VISITOR_DEFINITION(ZorbaFopIterator);
#endif // ZORBA_WITH_FOP

  PRINTER_VISITOR_DEFINITION (UDFunctionCallIterator)
  PRINTER_VISITOR_DEFINITION (StatelessExtFunctionCallIterator)
  PRINTER_VISITOR_DEFINITION (FnBooleanIterator)
  PRINTER_VISITOR_DEFINITION (LogicIterator)
  PRINTER_VISITOR_DEFINITION (CompareIterator)
  PRINTER_VISITOR_DEFINITION (ElementIterator)
  PRINTER_VISITOR_DEFINITION (AttributeIterator)
  PRINTER_VISITOR_DEFINITION (DocumentIterator)
  PRINTER_VISITOR_DEFINITION (DocumentContentIterator)
  PRINTER_VISITOR_DEFINITION (CommentIterator)
  PRINTER_VISITOR_DEFINITION (PiIterator)
  PRINTER_VISITOR_DEFINITION (EmptyIterator)
  PRINTER_VISITOR_DEFINITION (IfThenElseIterator)
  PRINTER_VISITOR_DEFINITION (NodeDistinctIterator)
  PRINTER_VISITOR_DEFINITION (InstanceOfIterator)
  PRINTER_VISITOR_DEFINITION (EitherNodesOrAtomicsIterator)
  PRINTER_VISITOR_DEFINITION (OpNumericUnaryIterator)
  PRINTER_VISITOR_DEFINITION (OpDoubleUnaryIterator)
  PRINTER_VISITOR_DEFINITION (FnIdIterator)
  PRINTER_VISITOR_DEFINITION (FnIdRefIterator)
  PRINTER_VISITOR_DEFINITION (TextIterator)
  PRINTER_VISITOR_DEFINITION (FnDateTimeConstructorIterator)
  PRINTER_VISITOR_DEFINITION (CreateTupleIterator)
  PRINTER_VISITOR_DEFINITION (GetTupleFieldIterator)
  PRINTER_VISITOR_DEFINITION (TryCatchIterator)
  PRINTER_VISITOR_DEFINITION (flwor::FLWORIterator)
  PRINTER_VISITOR_DEFINITION (flwor::TupleStreamIterator)
  PRINTER_VISITOR_DEFINITION (flwor::TupleSourceIterator)
  PRINTER_VISITOR_DEFINITION (flwor::ForIterator)
  PRINTER_VISITOR_DEFINITION (flwor::OuterForIterator)
  PRINTER_VISITOR_DEFINITION (flwor::LetIterator)
  PRINTER_VISITOR_DEFINITION (flwor::WhereIterator)
  PRINTER_VISITOR_DEFINITION (flwor::CountIterator)
  PRINTER_VISITOR_DEFINITION (flwor::GroupByIterator)
  PRINTER_VISITOR_DEFINITION (flwor::OrderByIterator)
  PRINTER_VISITOR_DEFINITION (flwor::WindowIterator)
  PRINTER_VISITOR_DEFINITION (NameCastIterator)
  PRINTER_VISITOR_DEFINITION (CtxVariableIterator)
  PRINTER_VISITOR_DEFINITION (CtxVarDeclIterator)
  PRINTER_VISITOR_DEFINITION (CtxVarAssignIterator)
  PRINTER_VISITOR_DEFINITION (CtxVarExistsIterator)
  PRINTER_VISITOR_DEFINITION(FnAdjustToTimeZoneIterator_1);
  PRINTER_VISITOR_DEFINITION(FnAdjustToTimeZoneIterator_2);
  PRINTER_VISITOR_DEFINITION(FnFormatDateTimeIterator);
  PRINTER_VISITOR_DEFINITION(InsertIterator);
  PRINTER_VISITOR_DEFINITION(DeleteIterator);
  PRINTER_VISITOR_DEFINITION(ReplaceIterator);
  PRINTER_VISITOR_DEFINITION(RenameIterator);
  PRINTER_VISITOR_DEFINITION(TransformIterator);
  PRINTER_VISITOR_DEFINITION(ApplyIterator);
  PRINTER_VISITOR_DEFINITION(DebuggerSingletonIterator);
  PRINTER_VISITOR_DEFINITION(HoistIterator);
  PRINTER_VISITOR_DEFINITION(UnhoistIterator);

  PRINTER_VISITOR_AXIS_DEFINITION (AttributeAxisIterator)
  PRINTER_VISITOR_AXIS_DEFINITION (ParentAxisIterator)
  PRINTER_VISITOR_AXIS_DEFINITION (AncestorAxisIterator)
  PRINTER_VISITOR_AXIS_DEFINITION (AncestorReverseAxisIterator)
  PRINTER_VISITOR_AXIS_DEFINITION (AncestorSelfAxisIterator)
  PRINTER_VISITOR_AXIS_DEFINITION (AncestorSelfReverseAxisIterator)
  PRINTER_VISITOR_AXIS_DEFINITION (RSiblingAxisIterator)
  PRINTER_VISITOR_AXIS_DEFINITION (LSiblingAxisIterator)
  PRINTER_VISITOR_AXIS_DEFINITION (LSiblingReverseAxisIterator)
  PRINTER_VISITOR_AXIS_DEFINITION (ChildAxisIterator)
  PRINTER_VISITOR_AXIS_DEFINITION (DescendantAxisIterator)
  PRINTER_VISITOR_AXIS_DEFINITION (DescendantSelfAxisIterator)
  PRINTER_VISITOR_AXIS_DEFINITION (PrecedingAxisIterator)
  PRINTER_VISITOR_AXIS_DEFINITION (PrecedingReverseAxisIterator)
  PRINTER_VISITOR_AXIS_DEFINITION (FollowingAxisIterator)
}

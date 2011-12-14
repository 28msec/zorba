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
#include "stdafx.h"

#include "runtime/visitors/printer_visitor.h"

#include "types/typeops.h"

#include "system/properties.h"

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
#include "runtime/core/trycatch.h"
#include "runtime/core/apply_updates.h"
#include "runtime/core/nodeid_iterators.h"
#include "runtime/core/internal_operators.h"
#include "runtime/numerics/NumericsImpl.h"
#include "runtime/core/arithmetic_impl.h"
#include "runtime/sequences/SequencesImpl.h"
#include "runtime/durations_dates_times/DurationsDatesTimesImpl.h"
#ifdef ZORBA_WITH_DEBUGGER
#include "runtime/debug/debug_iterator.h"
#endif
#include "runtime/indexing/index_ddl.h"
#include "runtime/function_item/dynamic_fncall_iterator.h"
#include "runtime/visitors/iterprinter.h"
#include "runtime/update/update.h"
#include "runtime/eval/eval.h"
#include "runtime/misc/materialize.h"
#include "runtime/scripting/scripting.h"
#include "runtime/collections/collections_impl.h"

#ifdef ZORBA_WITH_DEBUGGER
#include "debugger/debugger_commons.h"
#endif

#include "context/static_context.h"
#include "context/namespace_context.h"

namespace zorba{

#define PRINTER_VISITOR_DEFINITION(class)                \
  void PrinterVisitor::beginVisit ( const class& a )     \
  {                                                      \
    thePrinter.startBeginVisit(#class, ++theId);         \
    printCommons(  &a, theId );                          \
    thePrinter.endBeginVisit( theId);                    \
  }                                                      \
  void PrinterVisitor::endVisit ( const class& )         \
  {                                                      \
    thePrinter.startEndVisit();                          \
    thePrinter.endEndVisit();                            \
  }


#define PRINTER_VISITOR_AXIS_DEFINITION(class)           \
  void PrinterVisitor::beginVisit ( const class& a )     \
  {                                                      \
    thePrinter.startBeginVisit(#class, ++theId);         \
    printCommons(&a, theId);                             \
    printNameOrKindTest(&a);                             \
    thePrinter.endBeginVisit( theId);                    \
  }                                                      \
  void PrinterVisitor::endVisit ( const class& )         \
  {                                                      \
    thePrinter.startEndVisit();                          \
    thePrinter.endEndVisit();                            \
  }


void PrinterVisitor::beginVisit(const SingletonIterator& a)
{
  thePrinter.startBeginVisit("SingletonIterator", ++theId);
  thePrinter.addAttribute("value", a.getValue()->show().str());
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}

void PrinterVisitor::endVisit(const SingletonIterator&)
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}


void PrinterVisitor::beginVisit(const EnclosedIterator& a)
{
  thePrinter.startBeginVisit("EnclosedIterator", ++theId);
  thePrinter.addAttribute("attr_cont", (a.getAttrContent() ? "true" : "false"));
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}

void PrinterVisitor::endVisit(const EnclosedIterator&)
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}


void PrinterVisitor::beginVisit(const NodeSortIterator& a)
{
  thePrinter.startBeginVisit("NodeSortIterator", ++theId);
  printCommons(&a, theId);
  thePrinter.addAttribute("distinct", (a.getDistinct() ? "true" : "false"));
  thePrinter.addAttribute("ascending", (a.getAscending() ? "true" : "false"));
  thePrinter.endBeginVisit( theId);
}

void PrinterVisitor::endVisit(const NodeSortIterator&)
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}


void PrinterVisitor::beginVisit(const NodeDistinctIterator& a)
{
  thePrinter.startBeginVisit("NodeDistinctIterator", ++theId);
  printCommons(&a, theId);
  thePrinter.addAttribute("allow-atomics", (a.getAtomics() ? "true" : "false"));
  thePrinter.addAttribute("check-only", (a.getCheckDistinct() ? "true" : "false"));
  thePrinter.endBeginVisit( theId);
}

void PrinterVisitor::endVisit(const NodeDistinctIterator&)
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

void PrinterVisitor::beginVisit ( const TreatIterator& a )
{
  thePrinter.startBeginVisit("TreatIterator", ++theId);
  if (a.theCheckPrime)
    thePrinter.addAttribute("type", TypeOps::toString(*a.theTreatType));
  thePrinter.addAttribute("quant", TypeOps::decode_quantifier
      (a.theQuantifier));
  printCommons( &a, theId );
  thePrinter.endBeginVisit(theId);
}

void PrinterVisitor::endVisit ( const TreatIterator& )
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisit ( const NumArithIterator<AddOperation>& a )
{
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
  thePrinter.addAttribute("varname", a.getVarName()->getStringValue().c_str());
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

  thePrinter.addAttribute("varname", a.getVarName()->getStringValue().c_str());

  if (a.getTargetPos() > Integer(0))
    thePrinter.addAttribute("targetPos", a.getTargetPos().toString().c_str());

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
    const zstring& varName,
    const std::vector<PlanIter_t>& varRefs)
{
  thePrinter.startBeginVisit("LetVariable", ++theId);

  thePrinter.addAttribute("name", varName.str());

  thePrinter.addAttribute("materialize", materialize ? "true" : "false");

  std::ostringstream str;

  ulong numRefs = (ulong)varRefs.size();
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
    const zstring& varName,
    const std::vector<PlanIter_t>& varRefs,
    const std::vector<PlanIter_t>& posRefs)
{
  thePrinter.startBeginVisit("ForVariable", ++theId);

  thePrinter.addAttribute("name", varName.str());

  std::ostringstream str;

  ulong numRefs = (ulong)varRefs.size();
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

    ulong numRefs = (ulong)posRefs.size();
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


void PrinterVisitor::beginVisitOrderBySpec(const PlanIterator& a)
{
  thePrinter.startBeginVisit("OrderBySpec", ++theId);
  thePrinter.endBeginVisit(theId);
  a.accept(*this);
}


void PrinterVisitor::endVisitOrderBySpec(const PlanIterator& )
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

  str1 << inputVar->getVarName()->getStringValue() << " : " <<
      inputVar.getp();

  ulong numRefs = (ulong)varRefs.size();
  for (ulong i = 0; i < numRefs; i++)
  {
    str2 << varRefs[i].getp();
    if (i < numRefs-1)
      str2 << " ";
  }

  thePrinter.addAttribute("inputVar", str1.str());
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

  str1 << inputVar->getVarName()->getStringValue() << " : " << inputVar.getp();

  ulong numRefs = (ulong)varRefs.size();
  for (ulong i = 0; i < numRefs; i++)
  {
    str2 << varRefs[i].getp();
    if (i < numRefs-1)
      str2 << " ";
  }

  thePrinter.addAttribute("inputVar", str1.str());
  if (! Properties::instance()->noTreeIds())
    thePrinter.addAttribute("referenced-by", str2.str());

  thePrinter.endBeginVisit(theId);
}


void PrinterVisitor::endVisitOrderByLetVariable()
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}


void PrinterVisitor::beginVisitMaterializeClause()
{
  thePrinter.startBeginVisit("MaterializeClause", ++theId);
  thePrinter.endBeginVisit(theId);
}


void PrinterVisitor::endVisitMaterializeClause()
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}


void PrinterVisitor::beginVisitMaterializeVariable(
    bool forVar,
    PlanIter_t inputVar,
    const std::vector<PlanIter_t>& varRefs)
{
  std::ostringstream str1;
  std::ostringstream str2;

  if (forVar)
  {
    thePrinter.startBeginVisit("MaterializeForVariable", theId);

    ForVarIterator* iter = static_cast<ForVarIterator*>(inputVar.getp());

    str1 << iter->getVarName()->getStringValue() << " : " << iter;
  }
  else
  {
    thePrinter.startBeginVisit("MaterializeLetVariable", theId);

    LetVarIterator* iter = static_cast<LetVarIterator*>(inputVar.getp());

    str1 << iter->getVarName()->getStringValue() << " : " << iter;
  }

  ulong numRefs = (ulong)varRefs.size();
  for (ulong i = 0; i < numRefs; i++)
  {
    str2 << varRefs[i].getp();
    if (i < numRefs-1)
      str2 << " ";
  }

  thePrinter.addAttribute("inputVar", str1.str());
  if (! Properties::instance()->noTreeIds())
    thePrinter.addAttribute("referenced-by", str2.str());

  thePrinter.endBeginVisit(theId);
}


void PrinterVisitor::endVisitMaterializeVariable()
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

  ulong numRefs = (ulong)varRefs.size();
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

  ulong numRefs = (ulong)varRefs.size();
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


void PrinterVisitor::beginVisitWindowVariable(
    const std::string& varName,
    const std::vector<LetVarIter_t>& varRefs)
{
  thePrinter.startBeginVisit("WindowVariable", theId);

  thePrinter.addAttribute("name", varName);

  std::ostringstream str;

  ulong numRefs = (ulong)varRefs.size();
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

  ulong numRefs = (ulong)varRefs.size();
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


void PrinterVisitor::beginVisit(const CastIterator& a)
{
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

void PrinterVisitor::endVisit(const CastableIterator&)
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisit(const FTContainsIterator& a)
{
  thePrinter.startBeginVisit("FTContainsIterator", ++theId);
  // TODO
  thePrinter.endBeginVisit(theId);
}

void PrinterVisitor::endVisit(const FTContainsIterator&)
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisit(const flwor::OuterForIterator& a)
{
  thePrinter.startBeginVisit("flwor::OuterForIterator", ++theId);
  thePrinter.addAttribute("varname", a.getVarName()->getStringValue().str());
  printCommons(  &a, theId );
  thePrinter.endBeginVisit(theId);
}

void PrinterVisitor::endVisit(const flwor::OuterForIterator&)
{
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}


#define TYPED_VAL_CMP( xqt )                                            \
void PrinterVisitor::beginVisit(const TypedValueCompareIterator<TypeConstants::XS_##xqt>& a){\
    thePrinter.startBeginVisit("TypedValueCompareIterator_" #xqt, ++theId); \
    printCommons( &a, theId );                                          \
    thePrinter.endBeginVisit(theId);                                    \
}                                                                     \
                                                                        \
void PrinterVisitor::endVisit(const TypedValueCompareIterator<TypeConstants::XS_##xqt>& a){\
    thePrinter.startEndVisit();                                         \
    thePrinter.endEndVisit();                                           \
}

  TYPED_VAL_CMP (DECIMAL)
  TYPED_VAL_CMP (INTEGER)
  TYPED_VAL_CMP (DOUBLE)
  TYPED_VAL_CMP (FLOAT)
  TYPED_VAL_CMP (STRING)

#undef TYPED_VAL_CMP

  void PrinterVisitor::beginVisit ( const UDFunctionCallIterator& a )
  {
    thePrinter.startBeginVisit("UDFunctionCallIterator", ++theId);
    printCommons(  &a, theId );
    if (a.isCached())
    {
      thePrinter.addAttribute("cached", "true");
    }
    thePrinter.endBeginVisit( theId);
  }

  void PrinterVisitor::endVisit ( const UDFunctionCallIterator& )
  {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  PRINTER_VISITOR_DEFINITION (ExtFunctionCallIterator)
  PRINTER_VISITOR_DEFINITION (FnBooleanIterator)
  PRINTER_VISITOR_DEFINITION (OrIterator)
  PRINTER_VISITOR_DEFINITION (AndIterator)
  PRINTER_VISITOR_DEFINITION (CompareIterator)
  PRINTER_VISITOR_DEFINITION (AtomicValuesEquivalenceIterator)
  PRINTER_VISITOR_DEFINITION (ElementIterator)

  void PrinterVisitor::beginVisit(const AttributeIterator& a)
  {
    thePrinter.startBeginVisit("AttributeIterator", ++theId);
    if (a.getQName() != NULL)
    {
      thePrinter.addAttribute("qname", a.getQName()->show().str());
    }
    printCommons(&a, theId);
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit(const AttributeIterator& )
  {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  PRINTER_VISITOR_DEFINITION (DocumentIterator)
  PRINTER_VISITOR_DEFINITION (DocumentContentIterator)
  PRINTER_VISITOR_DEFINITION (CommentIterator)
  PRINTER_VISITOR_DEFINITION (PiIterator)
  PRINTER_VISITOR_DEFINITION (EmptyIterator)
  PRINTER_VISITOR_DEFINITION (IfThenElseIterator)

  PRINTER_VISITOR_DEFINITION (InstanceOfIterator)
  PRINTER_VISITOR_DEFINITION (EitherNodesOrAtomicsIterator)
  PRINTER_VISITOR_DEFINITION (OpNumericUnaryIterator)
  PRINTER_VISITOR_DEFINITION (OpDoubleUnaryIterator)
  PRINTER_VISITOR_DEFINITION (TextIterator)
  PRINTER_VISITOR_DEFINITION (FnDateTimeConstructorIterator)
  PRINTER_VISITOR_DEFINITION (TryCatchIterator)
  PRINTER_VISITOR_DEFINITION (flwor::FLWORIterator)
  PRINTER_VISITOR_DEFINITION (flwor::TupleStreamIterator)
  PRINTER_VISITOR_DEFINITION (flwor::TupleSourceIterator)
  PRINTER_VISITOR_DEFINITION (flwor::ForIterator)
  PRINTER_VISITOR_DEFINITION (flwor::LetIterator)
  PRINTER_VISITOR_DEFINITION (flwor::WhereIterator)
  PRINTER_VISITOR_DEFINITION (flwor::CountIterator)
  PRINTER_VISITOR_DEFINITION (flwor::GroupByIterator)
  PRINTER_VISITOR_DEFINITION (flwor::OrderByIterator)
  PRINTER_VISITOR_DEFINITION (flwor::WindowIterator)
  PRINTER_VISITOR_DEFINITION (NameCastIterator)

  void PrinterVisitor::beginVisit(const CtxVarDeclareIterator& a)
  {
    thePrinter.startBeginVisit("CtxVarDeclareIterator", ++theId);
    thePrinter.addAttribute("varid", a.getVarId());
    thePrinter.addAttribute("varname", a.getVarName()->getStringValue().str());
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit(const CtxVarDeclareIterator&)
  {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const CtxVarAssignIterator& a)
  {
    thePrinter.startBeginVisit("CtxVarAssignIterator", ++theId);
    thePrinter.addAttribute("varid", a.getVarId());
    thePrinter.addAttribute("varname", a.getVarName()->getStringValue().str());
    thePrinter.addAttribute("varkind", (a.isLocal() ? "local" : "global"));
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit(const CtxVarAssignIterator&)
  {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const CtxVarIsSetIterator& a)
  {
    thePrinter.startBeginVisit("CtxVarIsSetIterator", ++theId);
    thePrinter.addAttribute("varid", a.getVarId());
    thePrinter.addAttribute("varname", a.getVarName()->getStringValue().str());
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit(const CtxVarIsSetIterator&)
  {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  void PrinterVisitor::beginVisit(const CtxVarIterator& a)
  {
    thePrinter.startBeginVisit("CtxVarIterator", ++theId);
    thePrinter.addAttribute("varid", a.getVarId());
    thePrinter.addAttribute("varname", a.getVarName()->getStringValue().str());
    thePrinter.addAttribute("varkind", (a.isLocal() ? "local" : "global"));
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit(const CtxVarIterator&)
  {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  PRINTER_VISITOR_DEFINITION(FnAdjustToTimeZoneIterator_1);
  PRINTER_VISITOR_DEFINITION(FnAdjustToTimeZoneIterator_2);
  PRINTER_VISITOR_DEFINITION(FnFormatDateTimeIterator);
  PRINTER_VISITOR_DEFINITION(InsertIterator);
  PRINTER_VISITOR_DEFINITION(DeleteIterator);
  PRINTER_VISITOR_DEFINITION(ReplaceIterator);
  PRINTER_VISITOR_DEFINITION(RenameIterator);
  PRINTER_VISITOR_DEFINITION(TransformIterator);
  PRINTER_VISITOR_DEFINITION(ApplyIterator);
#ifdef ZORBA_WITH_DEBUGGER
  PRINTER_VISITOR_DEFINITION(DebuggerSingletonIterator);
#endif
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


  void PrinterVisitor::beginVisit(const CreateInternalIndexIterator& a)
  {
    thePrinter.startBeginVisit("CreateInternalIndexIterator", ++theId);
    thePrinter.addAttribute("name", a.getName()->show().str());
    printCommons( &a, theId );
    thePrinter.endBeginVisit(theId);
  }

  void PrinterVisitor::endVisit(const CreateInternalIndexIterator&)
  {
    thePrinter.startEndVisit();
    thePrinter.endEndVisit();
  }

  PRINTER_VISITOR_DEFINITION(CreateIndexIterator);
  PRINTER_VISITOR_DEFINITION(DeleteIndexIterator);
  PRINTER_VISITOR_DEFINITION(RefreshIndexIterator);
  PRINTER_VISITOR_DEFINITION(ValueIndexEntryBuilderIterator);
  PRINTER_VISITOR_DEFINITION(GeneralIndexEntryBuilderIterator);
  PRINTER_VISITOR_DEFINITION(ProbeIndexPointValueIterator);
  PRINTER_VISITOR_DEFINITION(ProbeIndexPointGeneralIterator);
  PRINTER_VISITOR_DEFINITION(ProbeIndexRangeValueIterator);
  PRINTER_VISITOR_DEFINITION(ProbeIndexRangeGeneralIterator);

  PRINTER_VISITOR_DEFINITION(DynamicFnCallIterator);

  PRINTER_VISITOR_DEFINITION(EvalIterator);

  PRINTER_VISITOR_DEFINITION(MaterializeIterator);

  PRINTER_VISITOR_DEFINITION(SequentialIterator);
  PRINTER_VISITOR_DEFINITION(ExitIterator);
  PRINTER_VISITOR_DEFINITION(ExitCatcherIterator);
  PRINTER_VISITOR_DEFINITION(LoopIterator);
  PRINTER_VISITOR_DEFINITION(FlowCtlIterator);

  PRINTER_VISITOR_DEFINITION(CountCollectionIterator);
}
/* vim:set et sw=2 ts=2: */

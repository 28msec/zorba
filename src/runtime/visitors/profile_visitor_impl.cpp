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

#include <iostream>

#ifdef ZORBA_WITH_DEBUGGER
#include "debugger/debugger_commons.h"
#endif
#include "functions/udf.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/collections/collections.h"
#include "runtime/core/apply_updates.h"
#include "runtime/core/arithmetic_impl.h"
#include "runtime/core/constructors.h"
#include "runtime/core/flwor_iterator.h"
#include "runtime/core/fncall_iterator.h"
#include "runtime/core/gflwor/count_iterator.h"
#include "runtime/core/gflwor/for_iterator.h"
#include "runtime/core/gflwor/groupby_iterator.h"
#include "runtime/core/gflwor/let_iterator.h"
#include "runtime/core/gflwor/outerfor_iterator.h"
#include "runtime/core/gflwor/tuplesource_iterator.h"
#include "runtime/core/gflwor/tuplestream_iterator.h"
#include "runtime/core/gflwor/where_iterator.h"
#include "runtime/core/gflwor/window_iterator.h"
#include "runtime/core/internal_operators.h"
#include "runtime/core/item_iterator.h"
#include "runtime/core/nodeid_iterators.h"
#include "runtime/core/path_iterators.h"
#include "runtime/core/sequencetypes.h"
#include "runtime/core/trycatch.h"
#include "runtime/core/var_iterators.h"
#ifdef ZORBA_WITH_DEBUGGER
#include "runtime/debug/debug_iterator.h"
#endif
#include "runtime/durations_dates_times/DurationsDatesTimesImpl.h"
#include "runtime/durations_dates_times/format_dateTime.h"
#include "runtime/eval/eval.h"
#ifndef ZORBA_NO_FULL_TEXT
#include "runtime/full_text/full_text.h"
#endif
#include "runtime/hof/dynamic_fncall_iterator.h"
#include "runtime/hof/function_item_iter.h"
#include "runtime/indexing/index_ddl.h"
#include "runtime/json/json_constructors.h"
#include "runtime/misc/materialize.h"
#include "runtime/numerics/NumericsImpl.h"
#include "runtime/scripting/scripting.h"
#include "runtime/sequences/SequencesImpl.h"
#include "runtime/update/update.h"
#include "runtime/visitors/profile_visitor.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

#if 0
void
get_pd( PlanIterator const &pi, PlanState &p_state ) {
  PlanIteratorState const *const pi_state =
    StateTraitsImpl<PlanIteratorState>::getState(
      p_state, pi.getStateOffset()
    );
  profile_data const &pd = pi_state->get_profile_data();
  cerr << "<iterator name=\"" << pi.getNameAsString() << "\" calls=\"" << pd.next_.call_count_ << "\" ms=\"" << pd.next_.cpu_time_ << "\"/>\n";
}
#endif

#define PROFILE_VISITOR_DEFINITION(...)                         \
  void ProfileVisitor::beginVisit( __VA_ARGS__ const &iter ) {  \
  }                                                             \
  void ProfileVisitor::endVisit( __VA_ARGS__ const& ) {         \
  }

PROFILE_VISITOR_DEFINITION( AncestorAxisIterator )
PROFILE_VISITOR_DEFINITION( AncestorReverseAxisIterator )
PROFILE_VISITOR_DEFINITION( AncestorSelfAxisIterator )
PROFILE_VISITOR_DEFINITION( AncestorSelfReverseAxisIterator )
PROFILE_VISITOR_DEFINITION( AndIterator )
PROFILE_VISITOR_DEFINITION( ApplyIterator )
PROFILE_VISITOR_DEFINITION( ArgumentPlaceholderIterator )
PROFILE_VISITOR_DEFINITION( AtomicValuesEquivalenceIterator )
PROFILE_VISITOR_DEFINITION( AttributeAxisIterator )
PROFILE_VISITOR_DEFINITION( AttributeIterator )
PROFILE_VISITOR_DEFINITION( CastableIterator )
PROFILE_VISITOR_DEFINITION( CastIterator )
PROFILE_VISITOR_DEFINITION( ChildAxisIterator )
PROFILE_VISITOR_DEFINITION( CommentIterator )
PROFILE_VISITOR_DEFINITION( CompareIterator )
PROFILE_VISITOR_DEFINITION( CreateIndexIterator )
PROFILE_VISITOR_DEFINITION( CreateInternalIndexIterator )
PROFILE_VISITOR_DEFINITION( CtxVarAssignIterator )
PROFILE_VISITOR_DEFINITION( CtxVarDeclareIterator )
PROFILE_VISITOR_DEFINITION( CtxVarIsSetIterator )
PROFILE_VISITOR_DEFINITION( CtxVarIterator )
#ifdef ZORBA_WITH_DEBUGGER
PROFILE_VISITOR_DEFINITION( DebuggerSingletonIterator )
#endif
PROFILE_VISITOR_DEFINITION( DeleteIndexIterator )
PROFILE_VISITOR_DEFINITION( DeleteIterator )
PROFILE_VISITOR_DEFINITION( DescendantAxisIterator )
PROFILE_VISITOR_DEFINITION( DescendantSelfAxisIterator )
PROFILE_VISITOR_DEFINITION( DocumentIterator )
PROFILE_VISITOR_DEFINITION( EitherNodesOrAtomicsIterator )
PROFILE_VISITOR_DEFINITION( ElementIterator )
PROFILE_VISITOR_DEFINITION( EmptyIterator )
PROFILE_VISITOR_DEFINITION( EnclosedIterator )
PROFILE_VISITOR_DEFINITION( EvalIterator )
PROFILE_VISITOR_DEFINITION( ExitCatcherIterator )
PROFILE_VISITOR_DEFINITION( ExitIterator )
PROFILE_VISITOR_DEFINITION( ExtFunctionCallIterator )
PROFILE_VISITOR_DEFINITION( FlowCtlIterator )
PROFILE_VISITOR_DEFINITION( flwor::CountIterator )
PROFILE_VISITOR_DEFINITION( flwor::FLWORIterator )
PROFILE_VISITOR_DEFINITION( flwor::ForIterator )
PROFILE_VISITOR_DEFINITION( flwor::GroupByIterator )
PROFILE_VISITOR_DEFINITION( flwor::LetIterator )
PROFILE_VISITOR_DEFINITION( flwor::OrderByIterator )
PROFILE_VISITOR_DEFINITION( flwor::OuterForIterator )
PROFILE_VISITOR_DEFINITION( flwor::TupleSourceIterator )
PROFILE_VISITOR_DEFINITION( flwor::TupleStreamIterator )
PROFILE_VISITOR_DEFINITION( flwor::WhereIterator )
PROFILE_VISITOR_DEFINITION( flwor::WindowIterator )
PROFILE_VISITOR_DEFINITION( FnAdjustToTimeZoneIterator_1 )
PROFILE_VISITOR_DEFINITION( FnAdjustToTimeZoneIterator_2 )
PROFILE_VISITOR_DEFINITION( FnBooleanIterator )
PROFILE_VISITOR_DEFINITION( FnDateTimeConstructorIterator )
PROFILE_VISITOR_DEFINITION( FnFormatDateTimeIterator )
PROFILE_VISITOR_DEFINITION( FnMinMaxIterator )
PROFILE_VISITOR_DEFINITION( FollowingAxisIterator )
PROFILE_VISITOR_DEFINITION( ForVarIterator )
#ifndef ZORBA_NO_FULL_TEXT
PROFILE_VISITOR_DEFINITION( FTContainsIterator )
#endif
PROFILE_VISITOR_DEFINITION( FunctionItemIterator )
PROFILE_VISITOR_DEFINITION( GeneralIndexEntryBuilderIterator )
PROFILE_VISITOR_DEFINITION( GenericArithIterator<AddOperation> )
PROFILE_VISITOR_DEFINITION( GenericArithIterator<DivideOperation>)
PROFILE_VISITOR_DEFINITION( GenericArithIterator<IntegerDivideOperation> )
PROFILE_VISITOR_DEFINITION( GenericArithIterator<ModOperation> )
PROFILE_VISITOR_DEFINITION( GenericArithIterator<MultiplyOperation> )
PROFILE_VISITOR_DEFINITION( GenericArithIterator<SubtractOperation> )
PROFILE_VISITOR_DEFINITION( HoistIterator )
PROFILE_VISITOR_DEFINITION( IfThenElseIterator )
PROFILE_VISITOR_DEFINITION( InsertIterator )
PROFILE_VISITOR_DEFINITION( InstanceOfIterator )
PROFILE_VISITOR_DEFINITION( JSONArrayIterator )
PROFILE_VISITOR_DEFINITION( JSONDirectObjectIterator )
PROFILE_VISITOR_DEFINITION( JSONObjectIterator )
PROFILE_VISITOR_DEFINITION( LetVarIterator )
PROFILE_VISITOR_DEFINITION( LoopIterator )
PROFILE_VISITOR_DEFINITION( LSiblingAxisIterator )
PROFILE_VISITOR_DEFINITION( LSiblingReverseAxisIterator )
PROFILE_VISITOR_DEFINITION( MaterializeIterator )
PROFILE_VISITOR_DEFINITION( MultiDynamicFnCallIterator )
PROFILE_VISITOR_DEFINITION( NameCastIterator )
PROFILE_VISITOR_DEFINITION( NamespaceIterator )
PROFILE_VISITOR_DEFINITION( NodeDistinctIterator )
PROFILE_VISITOR_DEFINITION( NodeSortIterator )
PROFILE_VISITOR_DEFINITION( NumArithIterator<AddOperation> )
PROFILE_VISITOR_DEFINITION( NumArithIterator<DivideOperation> )
PROFILE_VISITOR_DEFINITION( NumArithIterator<IntegerDivideOperation> )
PROFILE_VISITOR_DEFINITION( NumArithIterator<ModOperation> )
PROFILE_VISITOR_DEFINITION( NumArithIterator<MultiplyOperation> )
PROFILE_VISITOR_DEFINITION( NumArithIterator<SubtractOperation> )
PROFILE_VISITOR_DEFINITION( OpDoubleUnaryIterator )
PROFILE_VISITOR_DEFINITION( OpNumericUnaryIterator )
PROFILE_VISITOR_DEFINITION( OrIterator )
PROFILE_VISITOR_DEFINITION( ParentAxisIterator )
PROFILE_VISITOR_DEFINITION( PiIterator )
PROFILE_VISITOR_DEFINITION( PrecedingAxisIterator )
PROFILE_VISITOR_DEFINITION( PrecedingReverseAxisIterator )
PROFILE_VISITOR_DEFINITION( ProbeIndexPointGeneralIterator )
PROFILE_VISITOR_DEFINITION( ProbeIndexPointValueIterator )
PROFILE_VISITOR_DEFINITION( ProbeIndexRangeGeneralIterator )
PROFILE_VISITOR_DEFINITION( ProbeIndexRangeValueIterator )
PROFILE_VISITOR_DEFINITION( PromoteIterator )
PROFILE_VISITOR_DEFINITION( RefreshIndexIterator )
PROFILE_VISITOR_DEFINITION( RenameIterator )
PROFILE_VISITOR_DEFINITION( ReplaceIterator )
PROFILE_VISITOR_DEFINITION( RSiblingAxisIterator )
PROFILE_VISITOR_DEFINITION( SelfAxisIterator )
PROFILE_VISITOR_DEFINITION( SequentialIterator )
PROFILE_VISITOR_DEFINITION( SingleDynamicFnCallIterator )
PROFILE_VISITOR_DEFINITION( SingletonIterator )
PROFILE_VISITOR_DEFINITION( SpecificNumArithIterator<AddOperation,store::XS_DECIMAL>)
PROFILE_VISITOR_DEFINITION( SpecificNumArithIterator<AddOperation,store::XS_DOUBLE>)
PROFILE_VISITOR_DEFINITION( SpecificNumArithIterator<AddOperation,store::XS_FLOAT>)
PROFILE_VISITOR_DEFINITION( SpecificNumArithIterator<AddOperation,store::XS_INTEGER>)
PROFILE_VISITOR_DEFINITION( SpecificNumArithIterator<DivideOperation,store::XS_DECIMAL>)
PROFILE_VISITOR_DEFINITION( SpecificNumArithIterator<DivideOperation,store::XS_DOUBLE>)
PROFILE_VISITOR_DEFINITION( SpecificNumArithIterator<DivideOperation,store::XS_FLOAT>)
PROFILE_VISITOR_DEFINITION( SpecificNumArithIterator<DivideOperation,store::XS_INTEGER>)
PROFILE_VISITOR_DEFINITION( SpecificNumArithIterator<ModOperation,store::XS_DECIMAL>)
PROFILE_VISITOR_DEFINITION( SpecificNumArithIterator<ModOperation,store::XS_DOUBLE>)
PROFILE_VISITOR_DEFINITION( SpecificNumArithIterator<ModOperation,store::XS_FLOAT>)
PROFILE_VISITOR_DEFINITION( SpecificNumArithIterator<ModOperation,store::XS_INTEGER>)
PROFILE_VISITOR_DEFINITION( SpecificNumArithIterator<MultiplyOperation,store::XS_DECIMAL>)
PROFILE_VISITOR_DEFINITION( SpecificNumArithIterator<MultiplyOperation,store::XS_DOUBLE>)
PROFILE_VISITOR_DEFINITION( SpecificNumArithIterator<MultiplyOperation,store::XS_FLOAT>)
PROFILE_VISITOR_DEFINITION( SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>)
PROFILE_VISITOR_DEFINITION( SpecificNumArithIterator<SubtractOperation,store::XS_DECIMAL>)
PROFILE_VISITOR_DEFINITION( SpecificNumArithIterator<SubtractOperation,store::XS_DOUBLE>)
PROFILE_VISITOR_DEFINITION( SpecificNumArithIterator<SubtractOperation,store::XS_FLOAT>)
PROFILE_VISITOR_DEFINITION( SpecificNumArithIterator<SubtractOperation,store::XS_INTEGER>)
PROFILE_VISITOR_DEFINITION( TextIterator )
PROFILE_VISITOR_DEFINITION( TransformIterator )
PROFILE_VISITOR_DEFINITION( TreatIterator )
PROFILE_VISITOR_DEFINITION( TryCatchIterator )
PROFILE_VISITOR_DEFINITION( TypedValueCompareIterator<store::XS_DECIMAL> )
PROFILE_VISITOR_DEFINITION( TypedValueCompareIterator<store::XS_DOUBLE> )
PROFILE_VISITOR_DEFINITION( TypedValueCompareIterator<store::XS_FLOAT> )
PROFILE_VISITOR_DEFINITION( TypedValueCompareIterator<store::XS_INTEGER> )
PROFILE_VISITOR_DEFINITION( TypedValueCompareIterator<store::XS_STRING> )
PROFILE_VISITOR_DEFINITION( UDFunctionCallIterator )
PROFILE_VISITOR_DEFINITION( UnhoistIterator )
PROFILE_VISITOR_DEFINITION( ValueIndexEntryBuilderIterator )
PROFILE_VISITOR_DEFINITION( ZorbaApplyInsertAfterIterator )
PROFILE_VISITOR_DEFINITION( ZorbaApplyInsertBeforeIterator )
PROFILE_VISITOR_DEFINITION( ZorbaApplyInsertFirstIterator )
PROFILE_VISITOR_DEFINITION( ZorbaApplyInsertIterator )
PROFILE_VISITOR_DEFINITION( ZorbaApplyInsertLastIterator )
PROFILE_VISITOR_DEFINITION( ZorbaInsertAfterIterator )
PROFILE_VISITOR_DEFINITION( ZorbaInsertBeforeIterator )
PROFILE_VISITOR_DEFINITION( ZorbaInsertFirstIterator )
PROFILE_VISITOR_DEFINITION( ZorbaInsertIterator )
PROFILE_VISITOR_DEFINITION( ZorbaInsertLastIterator )

///////////////////////////////////////////////////////////////////////////////

void ProfileVisitor::beginVisitFlworWhereClause(const PlanIterator& a) {
}

void ProfileVisitor::endVisitFlworWhereClause(const PlanIterator& ) {
}

void ProfileVisitor::beginVisitFlworLetVariable(
    bool materialize,
    const zstring& varName,
    const std::vector<PlanIter_t>& varRefs)
{
}

void ProfileVisitor::endVisitFlworLetVariable() {
}

void ProfileVisitor::beginVisitFlworForVariable(
    const zstring& varName,
    const std::vector<PlanIter_t>& varRefs,
    const std::vector<PlanIter_t>& posRefs)
{
}

void ProfileVisitor::endVisitFlworForVariable() {
}

void ProfileVisitor::beginVisitOrderBySpec(const PlanIterator& a) {
}

void ProfileVisitor::endVisitOrderBySpec(const PlanIterator& ) {
}

void ProfileVisitor::beginVisitOrderByForVariable(
    ForVarIter_t inputVar,
    const std::vector<PlanIter_t>& varRefs)
{
}

void ProfileVisitor::endVisitOrderByForVariable() {
}

void ProfileVisitor::beginVisitOrderByLetVariable(
    LetVarIter_t inputVar,
    const std::vector<PlanIter_t>& varRefs)
{
}

void ProfileVisitor::endVisitOrderByLetVariable() {
}

void ProfileVisitor::beginVisitMaterializeClause() {
}

void ProfileVisitor::endVisitMaterializeClause() {
}

void ProfileVisitor::beginVisitMaterializeVariable(
    bool forVar,
    PlanIter_t inputVar,
    const std::vector<PlanIter_t>& varRefs)
{
}

void ProfileVisitor::endVisitMaterializeVariable() {
}

void ProfileVisitor::beginVisitGroupByClause() {
}

void ProfileVisitor::endVisitGroupByClause() {
}

void ProfileVisitor::beginVisitGroupBySpec() {
}

void ProfileVisitor::endVisitGroupBySpec() {
}

void ProfileVisitor::beginVisitGroupByOuter() {
}

void ProfileVisitor::endVisitGroupByOuter() {
}

void ProfileVisitor::beginVisitGroupVariable(const std::vector<ForVarIter_t>& varRefs) {
}

void ProfileVisitor::endVisitGroupVariable() {
}

void ProfileVisitor::beginVisitNonGroupVariable(const std::vector<LetVarIter_t>& varRefs) {
}

void ProfileVisitor::endVisitNonGroupVariable() {
}

void ProfileVisitor::beginVisitWindowVariable(
    const std::string& varName,
    const std::vector<LetVarIter_t>& varRefs)
{
}

void ProfileVisitor::endVisitWindowVariable() {
}

void ProfileVisitor::beginVisitWinCondVariable(
    const zstring& varName,
    const std::vector<PlanIter_t>& varRefs)
{
}

void ProfileVisitor::endVisitWinCondVariable() {
}

void ProfileVisitor::beginVisitFlworReturn( const PlanIterator& a) {
}

void ProfileVisitor::endVisitFlworReturn( const PlanIterator& ) {
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */

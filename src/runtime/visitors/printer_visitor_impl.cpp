/*
 * Copyright 2006-2014 The FLWOR Foundation.
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

#include <sstream>

#include <zorba/properties.h>

#include "context/namespace_context.h"
#include "context/static_context.h"
#ifdef ZORBA_WITH_DEBUGGER
#include "debugger/debugger_commons.h"
#endif /* ZORBA_WITH_DEBUGGER */
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
#endif /* ZORBA_WITH_DEBUGGER */
#include "runtime/durations_dates_times/DurationsDatesTimesImpl.h"
#include "runtime/durations_dates_times/format_dateTime.h"
#include "runtime/eval/eval.h"
#include "runtime/hof/dynamic_fncall_iterator.h"
#include "runtime/hof/function_item_iter.h"
#include "runtime/indexing/index_ddl.h"
#include "runtime/json/json_constructors.h"
#include "runtime/misc/materialize.h"
#include "runtime/numerics/NumericsImpl.h"
#include "runtime/scripting/scripting.h"
#include "runtime/sequences/SequencesImpl.h"
#include "runtime/update/update.h"
#include "runtime/visitors/iterprinter.h"
#include "runtime/visitors/printer_visitor.h"
#include "types/typeops.h"
#include "util/ascii_util.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

void PrinterVisitor::print() {
  thePrinter.start();
  theIterator->accept( *this );
  thePrinter.stop();
}

void PrinterVisitor::printCommons( PlanIterator const *pi, int id ) {
  Properties const &props = Properties::instance();
  if ( !props.getNoTreeIDs() ) {
    ostringstream oss;
    if ( props.getStableIteratorIDs() )
      oss << id;
    else
      oss << pi;
    thePrinter.addAttribute( "id", oss.str() );
  }

  if ( props.getPrintLocations() ) {
    QueryLoc const &loc = pi->getLocation();
    std::stringstream locStr;
    locStr << loc;
    thePrinter.addAttribute( "location", locStr.str() );    
  }

  if ( props.getCollectProfile() && thePlanState ) {
    PlanIteratorState const *const pi_state =
      StateTraitsImpl<PlanIteratorState>::getState(
        *thePlanState, pi->getStateOffset()
      );
    profile_data const &pd = pi_state->get_profile_data();
    thePrinter.addIntAttribute( "prof-calls", pd.data_.call_count_);
    thePrinter.addIntAttribute( "prof-next-calls", pd.data_.next_count_);
    thePrinter.addDecAttribute( "prof-cpu", pd.data_.cpu_time_);
    thePrinter.addDecAttribute( "prof-wall", pd.data_.wall_time_);
    thePrinter.addAttribute( "prof-name", pi->getNameAsString().str() );
  }
}

bool PrinterVisitor::hasToVisit(PlanIterator const *pi)
{
  if (thePlanState &&
      Properties::instance().getCollectProfile() &&
      Properties::instance().getNoUncalledIterators())
  {
    PlanIteratorState const *const pi_state =
      StateTraitsImpl<PlanIteratorState>::getState(
        *thePlanState, pi->getStateOffset()
      );
    profile_data const &pd = pi_state->get_profile_data();
    return pd.data_.next_count_;
  }
  return true;
}
void PrinterVisitor::printNameOrKindTest(const AxisIteratorHelper* a) {
  thePrinter.addAttribute("test-kind", toString(a->getTestKind()));

  if (a->getDocTestKind() != match_no_test)
    thePrinter.addAttribute("doc_test_kind", toString(a->getDocTestKind()));

  if (a->getQName() != 0)
    thePrinter.addAttribute("qname", a->getQName()->show().str());
  else
    thePrinter.addAttribute("qname", "*");

  if (a->getType() != 0)
    thePrinter.addAttribute("typename", a->getType()->toString());
  else
    thePrinter.addAttribute("typename", "*");

  thePrinter.addBoolAttribute("nill-allowed", a->nilledAllowed());

  if (a->getTargetPos() >= 0)
    thePrinter.addIntAttribute("target_position", a->getTargetPos());
}

///////////////////////////////////////////////////////////////////////////////

#define DEF_END_VISIT(...)                              \
  void PrinterVisitor::endVisit( __VA_ARGS__ const& ) { \
    thePrinter.startEndVisit();                         \
    thePrinter.endEndVisit();                           \
  }

#define DEF_VISIT(...)                                      \
  void PrinterVisitor::beginVisit( __VA_ARGS__ const &i ) { \
    thePrinter.startBeginVisit( #__VA_ARGS__, ++theId );    \
    printCommons( &i, theId );                              \
    thePrinter.endBeginVisit( theId );                      \
  }                                                         \
  DEF_END_VISIT(__VA_ARGS__)

#define DEF_NS_VISIT(NS,...)                                    \
  void PrinterVisitor::beginVisit( NS::__VA_ARGS__ const &i ) { \
    thePrinter.startBeginVisit( #__VA_ARGS__, ++theId );        \
    printCommons( &i, theId );                                  \
    thePrinter.endBeginVisit( theId );                          \
  }                                                             \
  DEF_END_VISIT(NS::__VA_ARGS__)

DEF_NS_VISIT( flwor, CountIterator )
DEF_NS_VISIT( flwor, FLWORIterator )
DEF_NS_VISIT( flwor, ForIterator )
DEF_NS_VISIT( flwor, GroupByIterator )
DEF_NS_VISIT( flwor, LetIterator )
DEF_NS_VISIT( flwor, OrderByIterator )
DEF_NS_VISIT( flwor, TupleSourceIterator )
DEF_NS_VISIT( flwor, TupleStreamIterator )
DEF_NS_VISIT( flwor, WhereIterator )
DEF_NS_VISIT( flwor, WindowIterator )

DEF_VISIT( AndIterator )
DEF_VISIT( ApplyIterator )
DEF_VISIT( ArgumentPlaceholderIterator )
DEF_VISIT( AtomicValuesEquivalenceIterator )
DEF_VISIT( CommentIterator )
DEF_VISIT( CompareIterator )
DEF_VISIT( CreateIndexIterator )
#ifdef ZORBA_WITH_DEBUGGER
DEF_VISIT( DebuggerSingletonIterator )
#endif
DEF_VISIT( DeleteIndexIterator )
DEF_VISIT( DeleteIterator )
DEF_VISIT( EitherNodesOrAtomicsIterator )
DEF_VISIT( EmptyIterator )
DEF_VISIT( EvalIterator )
DEF_VISIT( ExitCatcherIterator )
DEF_VISIT( ExitIterator )
DEF_VISIT( FlowCtlIterator )
DEF_VISIT( FnAdjustToTimeZoneIterator_1 )
DEF_VISIT( FnAdjustToTimeZoneIterator_2 )
DEF_VISIT( FnBooleanIterator )
DEF_VISIT( FnDateTimeConstructorIterator )
DEF_VISIT( FnFormatDateTimeIterator )
DEF_VISIT( GeneralIndexEntryBuilderIterator )
DEF_VISIT( HoistIterator )
DEF_VISIT( IfThenElseIterator )
DEF_VISIT( InsertIterator )
DEF_VISIT( InstanceOfIterator )
DEF_VISIT( JSONArrayIterator )
DEF_VISIT( JSONDirectObjectIterator )
DEF_VISIT( JSONObjectIterator )
DEF_VISIT( LoopIterator )
DEF_VISIT( MaterializeIterator )
DEF_VISIT( MultiDynamicFnCallIterator )
DEF_VISIT( NameCastIterator )
DEF_VISIT( NamespaceIterator )
DEF_VISIT( OpDoubleUnaryIterator )
DEF_VISIT( OpNumericUnaryIterator )
DEF_VISIT( OrIterator )
DEF_VISIT( PiIterator )
DEF_VISIT( ProbeIndexPointGeneralIterator )
DEF_VISIT( ProbeIndexRangeGeneralIterator )
DEF_VISIT( RefreshIndexIterator )
DEF_VISIT( RenameIterator )
DEF_VISIT( ReplaceIterator )
DEF_VISIT( SequentialIterator )
DEF_VISIT( SingleDynamicFnCallIterator )
DEF_VISIT( TextIterator )
DEF_VISIT( TransformIterator )
DEF_VISIT( TryCatchIterator )
DEF_VISIT( UnhoistIterator )
DEF_VISIT( ValueIndexEntryBuilderIterator )

#define DEF_AXIS_VISIT(...)                                 \
  void PrinterVisitor::beginVisit( __VA_ARGS__ const &i ) { \
    thePrinter.startBeginVisit( #__VA_ARGS__, ++theId );    \
    printCommons( &i, theId );                              \
    printNameOrKindTest( &i );                              \
    thePrinter.endBeginVisit( theId );                      \
  }                                                         \
  DEF_END_VISIT(__VA_ARGS__)

DEF_AXIS_VISIT( AncestorAxisIterator )
DEF_AXIS_VISIT( AncestorReverseAxisIterator )
DEF_AXIS_VISIT( AncestorSelfAxisIterator )
DEF_AXIS_VISIT( AncestorSelfReverseAxisIterator )
DEF_AXIS_VISIT( AttributeAxisIterator )
DEF_AXIS_VISIT( ChildAxisIterator )
DEF_AXIS_VISIT( DescendantAxisIterator )
DEF_AXIS_VISIT( DescendantSelfAxisIterator )
DEF_AXIS_VISIT( FollowingAxisIterator )
DEF_AXIS_VISIT( LSiblingAxisIterator )
DEF_AXIS_VISIT( LSiblingReverseAxisIterator )
DEF_AXIS_VISIT( ParentAxisIterator )
DEF_AXIS_VISIT( PrecedingAxisIterator )
DEF_AXIS_VISIT( PrecedingReverseAxisIterator )
DEF_AXIS_VISIT( RSiblingAxisIterator )
DEF_AXIS_VISIT( SelfAxisIterator )

#define DEF_OP_VISIT(CLASS,OP)                              \
  void PrinterVisitor::beginVisit( CLASS<OP> const &i ) {   \
    thePrinter.startBeginVisit( #CLASS "_" #OP , ++theId ); \
    printCommons( &i, theId );                              \
    thePrinter.endBeginVisit( theId );                      \
  }                                                         \
  DEF_END_VISIT(CLASS<OP>)

DEF_OP_VISIT( GenericArithIterator, AddOperation )
DEF_OP_VISIT( GenericArithIterator, DivideOperation )
DEF_OP_VISIT( GenericArithIterator, IntegerDivideOperation )
DEF_OP_VISIT( GenericArithIterator, ModOperation )
DEF_OP_VISIT( GenericArithIterator, MultiplyOperation )
DEF_OP_VISIT( GenericArithIterator, SubtractOperation )
DEF_OP_VISIT( NumArithIterator, AddOperation )
DEF_OP_VISIT( NumArithIterator, DivideOperation )
DEF_OP_VISIT( NumArithIterator, IntegerDivideOperation )
DEF_OP_VISIT( NumArithIterator, ModOperation )
DEF_OP_VISIT( NumArithIterator, MultiplyOperation )
DEF_OP_VISIT( NumArithIterator, SubtractOperation )

#define DEF_T_VISIT(CLASS,TYPE)                                         \
  void PrinterVisitor::beginVisit( CLASS<store::XS_##TYPE> const &i ) { \
    thePrinter.startBeginVisit( #CLASS "_" #TYPE , ++theId );           \
    printCommons( &i, theId );                                          \
    thePrinter.endBeginVisit( theId );                                  \
  }                                                                     \
  DEF_END_VISIT(CLASS<store::XS_##TYPE>)

DEF_T_VISIT( TypedValueCompareIterator, DECIMAL )
DEF_T_VISIT( TypedValueCompareIterator, DOUBLE )
DEF_T_VISIT( TypedValueCompareIterator, FLOAT )
DEF_T_VISIT( TypedValueCompareIterator, INTEGER )
DEF_T_VISIT( TypedValueCompareIterator, STRING )

#define DEF_OP_T_VISIT(CLASS,OP,TYPE)                                       \
  void PrinterVisitor::beginVisit( CLASS<OP,store::XS_##TYPE> const &i ) {  \
    thePrinter.startBeginVisit( #CLASS "_" #OP "_" #TYPE, ++theId );        \
    printCommons( &i, theId );                                              \
    thePrinter.endBeginVisit( theId );                                      \
  }                                                                         \
  DEF_END_VISIT(CLASS<OP,store::XS_##TYPE>)

DEF_OP_T_VISIT( SpecificNumArithIterator, AddOperation, DECIMAL )
DEF_OP_T_VISIT( SpecificNumArithIterator, AddOperation, DOUBLE )
DEF_OP_T_VISIT( SpecificNumArithIterator, AddOperation, FLOAT )
DEF_OP_T_VISIT( SpecificNumArithIterator, AddOperation, INTEGER )
DEF_OP_T_VISIT( SpecificNumArithIterator, DivideOperation, DECIMAL )
DEF_OP_T_VISIT( SpecificNumArithIterator, DivideOperation, DOUBLE )
DEF_OP_T_VISIT( SpecificNumArithIterator, DivideOperation, FLOAT )
DEF_OP_T_VISIT( SpecificNumArithIterator, DivideOperation, INTEGER )
DEF_OP_T_VISIT( SpecificNumArithIterator, ModOperation, DECIMAL )
DEF_OP_T_VISIT( SpecificNumArithIterator, ModOperation, DOUBLE )
DEF_OP_T_VISIT( SpecificNumArithIterator, ModOperation, FLOAT )
DEF_OP_T_VISIT( SpecificNumArithIterator, ModOperation, INTEGER )
DEF_OP_T_VISIT( SpecificNumArithIterator, MultiplyOperation, DECIMAL )
DEF_OP_T_VISIT( SpecificNumArithIterator, MultiplyOperation, DOUBLE )
DEF_OP_T_VISIT( SpecificNumArithIterator, MultiplyOperation, FLOAT )
DEF_OP_T_VISIT( SpecificNumArithIterator, MultiplyOperation, INTEGER )
DEF_OP_T_VISIT( SpecificNumArithIterator, SubtractOperation, DECIMAL )
DEF_OP_T_VISIT( SpecificNumArithIterator, SubtractOperation, DOUBLE )
DEF_OP_T_VISIT( SpecificNumArithIterator, SubtractOperation, FLOAT )
DEF_OP_T_VISIT( SpecificNumArithIterator, SubtractOperation, INTEGER )

#define DEF_INDEX_PROBE_VISIT(CLASS)                  \
  void PrinterVisitor::beginVisit( CLASS const &i ) { \
    thePrinter.startBeginVisit( #CLASS, ++theId );    \
    if ( i.hasSkip() )                                \
      thePrinter.addBoolAttribute( "skip", true );    \
    printCommons( &i, theId );                        \
    thePrinter.endBeginVisit( theId );                \
  }                                                   \
  DEF_END_VISIT( CLASS )

DEF_INDEX_PROBE_VISIT( ProbeIndexPointValueIterator )
DEF_INDEX_PROBE_VISIT( ProbeIndexRangeValueIterator )

#define DEF_INSERT_NODES_VISIT(CLASS)                     \
  void PrinterVisitor::beginVisit( CLASS const &i ) {     \
    thePrinter.startBeginVisit( #CLASS, ++theId );        \
    if ( i.isDynamic() )                                  \
      thePrinter.addBoolAttribute( "is-dynamic", true );  \
    if ( i.needToCopy() )                                 \
      thePrinter.addBoolAttribute( "need-to-copy", true );\
    printCommons( &i, theId );                            \
    thePrinter.endBeginVisit( theId );                    \
  }                                                       \
  DEF_END_VISIT( CLASS )

DEF_INSERT_NODES_VISIT( ZorbaApplyInsertAfterIterator )
DEF_INSERT_NODES_VISIT( ZorbaApplyInsertBeforeIterator )
DEF_INSERT_NODES_VISIT( ZorbaApplyInsertFirstIterator )
DEF_INSERT_NODES_VISIT( ZorbaApplyInsertIterator )
DEF_INSERT_NODES_VISIT( ZorbaApplyInsertLastIterator )
DEF_INSERT_NODES_VISIT( ZorbaInsertAfterIterator )
DEF_INSERT_NODES_VISIT( ZorbaInsertBeforeIterator )
DEF_INSERT_NODES_VISIT( ZorbaInsertFirstIterator )
DEF_INSERT_NODES_VISIT( ZorbaInsertIterator )
DEF_INSERT_NODES_VISIT( ZorbaInsertLastIterator )

////////// special cases //////////////////////////////////////////////////////

void PrinterVisitor::beginVisit( AttributeIterator const &i ) {
  thePrinter.startBeginVisit( "AttributeIterator", ++theId );
  if ( i.getQName() )
    thePrinter.addAttribute( "qname", i.getQName()->show().str() );
  printCommons( &i, theId );
  thePrinter.endBeginVisit( theId );
}
DEF_END_VISIT( AttributeIterator )

void PrinterVisitor::beginVisit( CastableIterator const &i ) {
  thePrinter.startBeginVisit( "CastableIterator", ++theId );
  ostringstream lStream;
  TypeOps::serialize( lStream, *i.theCastType );
  thePrinter.addAttribute( "type", lStream.str() );
  printCommons( &i, theId );
  thePrinter.endBeginVisit( theId );
}
DEF_END_VISIT( CastableIterator )

void PrinterVisitor::beginVisit( CastIterator const &i ) {
  thePrinter.startBeginVisit( "CastIterator", ++theId );
  ostringstream lStream;
  TypeOps::serialize( lStream, *i.theCastType );
  thePrinter.addAttribute( "type", lStream.str() );
  printCommons( &i, theId );
  thePrinter.endBeginVisit( theId );
}
DEF_END_VISIT( CastIterator )

void PrinterVisitor::beginVisit( CreateInternalIndexIterator const &i ) {
  thePrinter.startBeginVisit( "CreateInternalIndexIterator", ++theId );
  thePrinter.addAttribute( "name", i.getName()->show().str() );
  printCommons( &i, theId );
  thePrinter.endBeginVisit( theId );
}
DEF_END_VISIT( CreateInternalIndexIterator )

void PrinterVisitor::beginVisit( CtxVarAssignIterator const &i ) {
  thePrinter.startBeginVisit( "CtxVarAssignIterator", ++theId );
  thePrinter.addIntAttribute( "varid", i.getVarId() );
  thePrinter.addAttribute( "varname", i.getVarName()->getStringValue().str() );
  thePrinter.addAttribute( "varkind", i.isLocal() ? "local" : "global" );
  printCommons( &i, theId );
  thePrinter.endBeginVisit( theId );
}
DEF_END_VISIT( CtxVarAssignIterator )

void PrinterVisitor::beginVisit( CtxVarDeclareIterator const &i ) {
  thePrinter.startBeginVisit( "CtxVarDeclareIterator", ++theId );
  thePrinter.addIntAttribute( "varid", i.getVarId() );
  thePrinter.addAttribute( "varname", i.getVarName()->getStringValue().str() );
  printCommons( &i, theId );
  thePrinter.endBeginVisit( theId );
}
DEF_END_VISIT( CtxVarDeclareIterator )

void PrinterVisitor::beginVisit( CtxVarIsSetIterator const &i ) {
  thePrinter.startBeginVisit( "CtxVarIsSetIterator", ++theId );
  thePrinter.addIntAttribute( "varid", i.getVarId() );
  thePrinter.addAttribute( "varname", i.getVarName()->getStringValue().str() );
  printCommons( &i, theId );
  thePrinter.endBeginVisit( theId );
}
DEF_END_VISIT( CtxVarIsSetIterator )

void PrinterVisitor::beginVisit( CtxVarIterator const &i ) {
  thePrinter.startBeginVisit( "CtxVarIterator", ++theId );
  thePrinter.addIntAttribute( "varid", i.getVarId() );
  thePrinter.addAttribute( "varname", i.getVarName()->getStringValue().str() );
  thePrinter.addAttribute( "varkind", i.isLocal() ? "local" : "global" );
  printCommons( &i, theId );
  thePrinter.endBeginVisit( theId );
}
DEF_END_VISIT( CtxVarIterator )

void PrinterVisitor::beginVisit( DocumentIterator const &i ) {
  thePrinter.startBeginVisit( "DocumentIterator", ++theId );
  if ( !i.copyInputNodes() )
    thePrinter.addBoolAttribute( "copyInputNodes", false );
  printCommons( &i, theId );
  thePrinter.endBeginVisit( theId );
}
DEF_END_VISIT( DocumentIterator  )

void PrinterVisitor::beginVisit( ElementIterator const &i ) {
  thePrinter.startBeginVisit( "ElementIterator", ++theId );
  if ( !i.copyInputNodes() )
    thePrinter.addBoolAttribute( "copyInputNodes", false );
  printCommons( &i, theId );
  thePrinter.endBeginVisit( theId );
}

DEF_END_VISIT( ElementIterator )
void PrinterVisitor::beginVisit( EnclosedIterator const &i ) {
  thePrinter.startBeginVisit( "EnclosedIterator", ++theId );
  thePrinter.addBoolAttribute( "attr_cont", i.getAttrContent() ? true : false );
  printCommons( &i, theId );
  thePrinter.endBeginVisit( theId );
}
DEF_END_VISIT( EnclosedIterator )

void PrinterVisitor::beginVisit( flwor::OuterForIterator const &i ) {
  thePrinter.startBeginVisit( "OuterForIterator", ++theId );
  thePrinter.addAttribute( "varname", i.getVarName()->getStringValue().str() );
  printCommons( &i, theId );
  thePrinter.endBeginVisit( theId );
}
DEF_END_VISIT( flwor::OuterForIterator )

void PrinterVisitor::beginVisit( FnMinMaxIterator const &i ) {
  thePrinter.startBeginVisit( "FnMinMaxIterator", ++theId );
  thePrinter.addAttribute( "type",
    (i.getType() == FnMinMaxIterator::MIN) != 0 ? string("min") : string("max")
  );
  printCommons( &i, theId );
  thePrinter.endBeginVisit( theId );
}
DEF_END_VISIT( FnMinMaxIterator )

void PrinterVisitor::beginVisit( ForVarIterator const &i ) {
  thePrinter.startBeginVisit( "ForVarIterator", ++theId );
  if ( i.getVarName() )
    thePrinter.addAttribute( "varname", i.getVarName()->getStringValue().c_str() );
  printCommons( &i, theId );
  thePrinter.endBeginVisit( theId );
}
DEF_END_VISIT( ForVarIterator )

void PrinterVisitor::beginVisit( FTContainsIterator const &i ) {
  thePrinter.startBeginVisit( "FTContainsIterator", ++theId );
  // TODO
  thePrinter.endBeginVisit( theId );
}
DEF_END_VISIT( FTContainsIterator )

void PrinterVisitor::beginVisit( FunctionItemIterator const &i ) {
  thePrinter.startBeginVisit( "FunctionItemIterator", ++theId );
  if ( i.getFunctionItemInfo()->theQName.getp() )
    thePrinter.addAttribute( "function", i.getFunctionItemInfo()->theQName->getStringValue().str() );
  printCommons( &i, theId );
  thePrinter.endBeginVisit( theId );
}
DEF_END_VISIT( FunctionItemIterator )

void PrinterVisitor::beginVisit( LetVarIterator const &i ) {
  thePrinter.startBeginVisit( "LetVarIterator", ++theId );
  if ( i.getVarName() )
    thePrinter.addAttribute( "varname", i.getVarName()->getStringValue().c_str() );
  if ( i.getTargetPos() > numeric_consts<xs_integer>::zero() )
    thePrinter.addIntAttribute( "targetPos", i.getTargetPos() );
  printCommons( &i, theId );
  thePrinter.endBeginVisit( theId );
}
DEF_END_VISIT( LetVarIterator )

void PrinterVisitor::beginVisit( NodeDistinctIterator const &i ) {
  thePrinter.startBeginVisit( "NodeDistinctIterator", ++theId );
  printCommons( &i, theId );
  thePrinter.addBoolAttribute( "allow-atomics", i.getAtomics() ? true : false );
  thePrinter.addBoolAttribute( "check-only", i.getCheckDistinct() ? true : false );
  thePrinter.endBeginVisit( theId );
}
DEF_END_VISIT( NodeDistinctIterator )

void PrinterVisitor::beginVisit( NodeSortIterator const &i ) {
  thePrinter.startBeginVisit( "NodeSortIterator", ++theId );
  printCommons( &i, theId );
  thePrinter.addBoolAttribute( "distinct", i.getDistinct() ? true : false );
  thePrinter.addBoolAttribute( "ascending", i.getAscending() ? true : false );
  thePrinter.endBeginVisit( theId );
}
DEF_END_VISIT( NodeSortIterator )

#if 0
void PrinterVisitor::beginVisit( PathIterator const &i ) {
  thePrinter.startBeginVisit( "PathIterator", ++theId );
  printCommons( &i, theId );
  thePrinter.endBeginVisit( theId );
}

DEF_END_VISIT( PathIterator )
#endif

void PrinterVisitor::beginVisit( PromoteIterator const &i ) {
  thePrinter.startBeginVisit( "PromoteIterator", ++theId );
  ostringstream lStream;
  TypeOps::serialize( lStream, *i.thePromoteType );
  thePrinter.addAttribute( "type", lStream.str() );
  printCommons( &i, theId );
  thePrinter.endBeginVisit( theId );
}
DEF_END_VISIT( PromoteIterator )

void PrinterVisitor::beginVisit( SingletonIterator const &i ) {
  thePrinter.startBeginVisit( "SingletonIterator", ++theId );
  thePrinter.addAttribute( "value", i.getValue()->show().str() );
  printCommons( &i, theId );
  thePrinter.endBeginVisit( theId );
}
DEF_END_VISIT( SingletonIterator )

void PrinterVisitor::beginVisit( TreatIterator const &i ) {
  thePrinter.startBeginVisit( "TreatIterator", ++theId );
  if ( i.theCheckPrime )
    thePrinter.addAttribute( "type", i.theTreatType->toString() );
  thePrinter.addAttribute( "quant", TypeOps::decode_quantifier( i.theQuantifier ) );
  printCommons( &i, theId );
  thePrinter.endBeginVisit( theId );
}
DEF_END_VISIT( TreatIterator )

void PrinterVisitor::beginVisit( UDFunctionCallIterator const &i ) {
  thePrinter.startBeginVisit( "UDFunctionCallIterator", ++theId );
  if ( i.isCached() )
  {
    if (i.isCacheAcrossSnapshots())
      thePrinter.addBoolAttribute("cached-across-snapshots", true);
    else
      thePrinter.addBoolAttribute("cached", true);
  }
  if ( i.theUDF->getSignature().getName() )
    thePrinter.addAttribute( "function", i.theUDF->getSignature().getName()->getStringValue().str() );
  else
    thePrinter.addAttribute( "function", "inline function" );
  printCommons( &i, theId );
  thePrinter.endBeginVisit( theId );
}
DEF_END_VISIT( UDFunctionCallIterator )

void PrinterVisitor::beginVisit( ExtFunctionCallIterator const &i ) {
  thePrinter.startBeginVisit( "ExtFunctionCallIterator", ++theId );
  if ( i.isCached() )
  {
    if (i.isCacheAcrossSnapshots())
      thePrinter.addBoolAttribute("cached-across-snapshots", true);
    else
      thePrinter.addBoolAttribute("cached", true);
  }
  printCommons(  &i, theId );
  thePrinter.endBeginVisit( theId );
}
DEF_END_VISIT( ExtFunctionCallIterator )

////////// really special cases ///////////////////////////////////////////////

template<class T>
string var_refs( vector<T> const &v ) {
  typename vector<T>::size_type const n = v.size();
  ostringstream oss;
  for ( typename vector<T>::size_type i = 0; i < n; ++i ) {
    oss << v[i].getp();
    if ( i < n - 1 )
      oss << ' ';
  }
  return oss.str();
}

void PrinterVisitor::
beginVisitFlworLetVariable( bool materialize, zstring const &varName,
                            vector<PlanIter_t> const &varRefs ) {
  thePrinter.startBeginVisit( "LetVariable", ++theId );

  thePrinter.addAttribute( "name", varName.str() );
  thePrinter.addBoolAttribute( "materialize", materialize ? true : false);

  ostringstream str;
  vector<PlanIter_t>::size_type const numRefs = varRefs.size();
  for ( vector<PlanIter_t>::size_type i = 0; i < numRefs; ++i ) {
#ifndef NDEBUG
    str << varRefs[i]->getId();
#else
    str << varRefs[i].getp();
#endif
    if ( i < numRefs - 1 )
      str << ' ';
  }

  if ( !Properties::instance().getNoTreeIDs() )
    thePrinter.addAttribute( "referenced-by", str.str() );

  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisitFlworLetVariable() {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::
beginVisitFlworForVariable( zstring const &varName,
                            vector<PlanIter_t> const &varRefs,
                            vector<PlanIter_t> const &posRefs ) {
  thePrinter.startBeginVisit( "ForVariable", ++theId );
  thePrinter.addAttribute( "name", varName.str() );

  ostringstream ref_oss;
  vector<PlanIter_t>::size_type const numRefs = varRefs.size();
  for ( vector<PlanIter_t>::size_type i = 0; i < numRefs; ++i ) {
#ifndef NDEBUG
    ref_oss << varRefs[i]->getId();
#else
    ref_oss << varRefs[i].getp();
#endif
    if ( i < numRefs - 1 )
      ref_oss << ' ';
  }

  if ( !Properties::instance().getNoTreeIDs() )
    thePrinter.addAttribute( "referenced-by", ref_oss.str() );

  if ( !posRefs.empty() ) {
    string const ref_s( var_refs( posRefs ) );
    if ( !Properties::instance().getNoTreeIDs() )
      thePrinter.addAttribute( "pos-referenced-by", ref_s );
  }

  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisitFlworForVariable() {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisitFlworReturn( PlanIterator const &i ) {
  thePrinter.startBeginVisit( "ReturnClause", ++theId );
  printCommons( &i, theId );
  thePrinter.endBeginVisit( theId );
  i.accept( *this );
}

void PrinterVisitor::endVisitFlworReturn( PlanIterator const& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisitFlworWhereClause( PlanIterator const &i ) {
  thePrinter.startBeginVisit( "WhereClause", ++theId );
  printCommons( &i, theId );
  thePrinter.endBeginVisit( theId );
  i.accept( *this );
}

void PrinterVisitor::endVisitFlworWhereClause( PlanIterator const& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisitGroupByClause() {
  thePrinter.startBeginVisit( "GroupByClause", ++theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisitGroupByClause() {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisitGroupByOuter() {
  thePrinter.startBeginVisit( "Spec", theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisitGroupByOuter() {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisitGroupBySpec() {
  thePrinter.startBeginVisit( "Spec", theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisitGroupBySpec() {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::
beginVisitGroupVariable( vector<ForVarIter_t> const &varRefs ) {
  thePrinter.startBeginVisit( "GroupVariable", ++theId );
  string const ref_s( var_refs( varRefs ) );
  if ( !Properties::instance().getNoTreeIDs() )
    thePrinter.addAttribute( "referenced-by", ref_s );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisitGroupVariable() {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisitMaterializeClause() {
  thePrinter.startBeginVisit( "MaterializeClause", ++theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisitMaterializeClause() {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::
beginVisitOrderByForVariable( ForVarIter_t inputVar,
                              vector<PlanIter_t> const &varRefs ) {
  thePrinter.startBeginVisit( "OrderByForVariable", theId );

  ostringstream iv_s;
  iv_s << inputVar->getVarName()->getStringValue() << " : ";
  if ( !Properties::instance().getNoTreeIDs() )
    iv_s << inputVar.getp();

  string const ref_s( var_refs( varRefs ) );
  thePrinter.addAttribute( "inputVar", iv_s.str() );
  if ( !Properties::instance().getNoTreeIDs() )
    thePrinter.addAttribute( "referenced-by", ref_s );

  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisitOrderByForVariable() {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::
beginVisitOrderByLetVariable( LetVarIter_t inputVar,
                              vector<PlanIter_t> const &varRefs ) {
  thePrinter.startBeginVisit( "OrderByLetVariable", theId );

  ostringstream iv_s;
  iv_s << inputVar->getVarName()->getStringValue() << " : ";
  if ( !Properties::instance().getNoTreeIDs() )
    iv_s << inputVar.getp();

  string const ref_s( var_refs( varRefs ) );
  thePrinter.addAttribute( "inputVar", iv_s.str() );
  if ( !Properties::instance().getNoTreeIDs() )
    thePrinter.addAttribute( "referenced-by", ref_s );

  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisitOrderByLetVariable() {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::beginVisitOrderBySpec( PlanIterator const &i ) {
  thePrinter.startBeginVisit( "OrderBySpec", ++theId );
  thePrinter.endBeginVisit( theId );
  i.accept( *this );
}

void PrinterVisitor::endVisitOrderBySpec( PlanIterator const& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::
beginVisitMaterializeVariable( bool forVar, PlanIter_t inputVar,
                               vector<PlanIter_t> const &varRefs ) {
  ostringstream iv_s;

  if ( forVar ) {
    thePrinter.startBeginVisit( "MaterializeForVariable", theId );
    ForVarIterator *const i = static_cast<ForVarIterator*>( inputVar.getp() );
    iv_s << i->getVarName()->getStringValue() << " : ";
    if ( !Properties::instance().getNoTreeIDs() )
      iv_s <<  i;
  } else {
    thePrinter.startBeginVisit( "MaterializeLetVariable", theId );
    LetVarIterator *const i = static_cast<LetVarIterator*>( inputVar.getp() );
    iv_s << i->getVarName()->getStringValue() << " : " ;
    if ( !Properties::instance().getNoTreeIDs() )
      iv_s << i;
  }

  string const ref_s( var_refs( varRefs ) );
  thePrinter.addAttribute( "inputVar", iv_s.str() );
  if ( !Properties::instance().getNoTreeIDs() )
    thePrinter.addAttribute( "referenced-by", ref_s );

  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisitMaterializeVariable() {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::
beginVisitNonGroupVariable( vector<LetVarIter_t> const &varRefs ) {
  thePrinter.startBeginVisit( "NonGroupVariable", ++theId );

  string ref_s( var_refs( varRefs ) );
  if ( !Properties::instance().getNoTreeIDs() )
    thePrinter.addAttribute( "referenced-by", ref_s );

  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisitNonGroupVariable() {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::
beginVisitWindowVariable( string const &varName,
                          vector<LetVarIter_t> const &varRefs ) {
  thePrinter.startBeginVisit( "WindowVariable", theId );
  thePrinter.addAttribute( "name", varName );

  string const ref_s( var_refs( varRefs ) );
  if ( !Properties::instance().getNoTreeIDs() )
    thePrinter.addAttribute( "referenced-by", ref_s );

  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisitWindowVariable() {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

void PrinterVisitor::
beginVisitWinCondVariable( zstring const &varName,
                           vector<PlanIter_t> const &varRefs ) {
  thePrinter.startBeginVisit( "WinCondVariable", theId );
  thePrinter.addAttribute( "name", varName.str() );

  string const ref_s( var_refs( varRefs ) );
  if ( !Properties::instance().getNoTreeIDs() )
    thePrinter.addAttribute( "referenced-by", ref_s );

  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisitWinCondVariable() {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */

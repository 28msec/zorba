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
#pragma once

//
// This file is included inside <BUILD_DIR>/src/runtime/visitors/printer_visitor.h.
// That file defines the PrinterVisitor class as a subclass of PlanIterVisitor.
//

#define DECLARE_VISITOR(...)      \
  void beginVisit( __VA_ARGS__ const& );  \
  void endVisit( __VA_ARGS__ const& )

DECLARE_VISITOR( AncestorAxisIterator );
DECLARE_VISITOR( AncestorReverseAxisIterator );
DECLARE_VISITOR( AncestorSelfAxisIterator );
DECLARE_VISITOR( AncestorSelfReverseAxisIterator );
DECLARE_VISITOR( AndIterator );
DECLARE_VISITOR( ApplyIterator );
DECLARE_VISITOR( ArgumentPlaceholderIterator );
DECLARE_VISITOR( AtomicValuesEquivalenceIterator );
DECLARE_VISITOR( AttributeAxisIterator );
DECLARE_VISITOR( AttributeIterator );
DECLARE_VISITOR( CastableIterator );
DECLARE_VISITOR( CastIterator );
DECLARE_VISITOR( ChildAxisIterator );
DECLARE_VISITOR( CommentIterator );
DECLARE_VISITOR( CompareIterator );
DECLARE_VISITOR( CreateIndexIterator );
DECLARE_VISITOR( CreateInternalIndexIterator );
DECLARE_VISITOR( CtxVarAssignIterator );
DECLARE_VISITOR( CtxVarDeclareIterator );
DECLARE_VISITOR( CtxVarIsSetIterator );
DECLARE_VISITOR( CtxVarIterator );
#ifdef ZORBA_WITH_DEBUGGER
DECLARE_VISITOR( DebuggerSingletonIterator );
#endif
DECLARE_VISITOR( DeleteIndexIterator );
DECLARE_VISITOR( DeleteIterator );
DECLARE_VISITOR( DescendantAxisIterator );
DECLARE_VISITOR( DescendantSelfAxisIterator );
DECLARE_VISITOR( DocumentIterator );
DECLARE_VISITOR( EitherNodesOrAtomicsIterator );
DECLARE_VISITOR( ElementIterator );
DECLARE_VISITOR( EmptyIterator );
DECLARE_VISITOR( EnclosedIterator );
DECLARE_VISITOR( EvalIterator );
DECLARE_VISITOR( ExitCatcherIterator );
DECLARE_VISITOR( ExitIterator );
DECLARE_VISITOR( ExtFunctionCallIterator );
DECLARE_VISITOR( FlowCtlIterator );
DECLARE_VISITOR( flwor::CountIterator );
DECLARE_VISITOR( flwor::FLWORIterator );
DECLARE_VISITOR( flwor::ForIterator );
DECLARE_VISITOR( flwor::GroupByIterator );
DECLARE_VISITOR( flwor::LetIterator );
DECLARE_VISITOR( flwor::OrderByIterator );
DECLARE_VISITOR( flwor::OuterForIterator );
DECLARE_VISITOR( flwor::TupleSourceIterator );
DECLARE_VISITOR( flwor::TupleStreamIterator );
DECLARE_VISITOR( flwor::WhereIterator );
DECLARE_VISITOR( flwor::WindowIterator );
DECLARE_VISITOR( FnAdjustToTimeZoneIterator_1 );
DECLARE_VISITOR( FnAdjustToTimeZoneIterator_2 );
DECLARE_VISITOR( FnBooleanIterator );
DECLARE_VISITOR( FnDateTimeConstructorIterator );
DECLARE_VISITOR( FnFormatDateTimeIterator );
DECLARE_VISITOR( FnMinMaxIterator );
DECLARE_VISITOR( FollowingAxisIterator );
DECLARE_VISITOR( ForVarIterator );
DECLARE_VISITOR( FTContainsIterator );
DECLARE_VISITOR( FunctionItemIterator );
DECLARE_VISITOR( GeneralIndexEntryBuilderIterator );
DECLARE_VISITOR( GenericArithIterator<AddOperation> );
DECLARE_VISITOR( GenericArithIterator<DivideOperation> );
DECLARE_VISITOR( GenericArithIterator<IntegerDivideOperation> );
DECLARE_VISITOR( GenericArithIterator<ModOperation> );
DECLARE_VISITOR( GenericArithIterator<MultiplyOperation> );
DECLARE_VISITOR( GenericArithIterator<SubtractOperation> );
DECLARE_VISITOR( HoistIterator );
DECLARE_VISITOR( IfThenElseIterator );
DECLARE_VISITOR( InsertIterator );
DECLARE_VISITOR( InstanceOfIterator );
DECLARE_VISITOR( JSONArrayIterator );
DECLARE_VISITOR( JSONDirectObjectIterator );
DECLARE_VISITOR( JSONObjectIterator );
DECLARE_VISITOR( LetVarIterator );
DECLARE_VISITOR( LoopIterator );
DECLARE_VISITOR( LSiblingAxisIterator );
DECLARE_VISITOR( LSiblingReverseAxisIterator );
DECLARE_VISITOR( MaterializeIterator );
DECLARE_VISITOR( MultiDynamicFnCallIterator );
DECLARE_VISITOR( NameCastIterator );
DECLARE_VISITOR( NamespaceIterator );
DECLARE_VISITOR( NodeDistinctIterator );
DECLARE_VISITOR( NodeSortIterator );
DECLARE_VISITOR( NumArithIterator<AddOperation> );
DECLARE_VISITOR( NumArithIterator<DivideOperation> );
DECLARE_VISITOR( NumArithIterator<IntegerDivideOperation> );
DECLARE_VISITOR( NumArithIterator<ModOperation> );
DECLARE_VISITOR( NumArithIterator<MultiplyOperation> );
DECLARE_VISITOR( NumArithIterator<SubtractOperation> );
DECLARE_VISITOR( OpDoubleUnaryIterator );
DECLARE_VISITOR( OpNumericUnaryIterator );
DECLARE_VISITOR( OrIterator );
DECLARE_VISITOR( ParentAxisIterator );
DECLARE_VISITOR( PiIterator );
DECLARE_VISITOR( PlanIterator );
DECLARE_VISITOR( PrecedingAxisIterator );
DECLARE_VISITOR( PrecedingReverseAxisIterator );
DECLARE_VISITOR( ProbeIndexPointGeneralIterator );
DECLARE_VISITOR( ProbeIndexPointValueIterator );
DECLARE_VISITOR( ProbeIndexRangeGeneralIterator );
DECLARE_VISITOR( ProbeIndexRangeValueIterator );
DECLARE_VISITOR( PromoteIterator );
DECLARE_VISITOR( RefreshIndexIterator );
DECLARE_VISITOR( RenameIterator );
DECLARE_VISITOR( ReplaceIterator );
DECLARE_VISITOR( RSiblingAxisIterator );
DECLARE_VISITOR( SelfAxisIterator );
DECLARE_VISITOR( SequentialIterator );
DECLARE_VISITOR( SingleDynamicFnCallIterator );
DECLARE_VISITOR( SingletonIterator );
DECLARE_VISITOR( SpecificNumArithIterator<AddOperation,store::XS_DECIMAL> );
DECLARE_VISITOR( SpecificNumArithIterator<AddOperation,store::XS_DOUBLE> );
DECLARE_VISITOR( SpecificNumArithIterator<AddOperation,store::XS_FLOAT> );
DECLARE_VISITOR( SpecificNumArithIterator<AddOperation,store::XS_INTEGER> );
DECLARE_VISITOR( SpecificNumArithIterator<DivideOperation,store::XS_DECIMAL> );
DECLARE_VISITOR( SpecificNumArithIterator<DivideOperation,store::XS_DOUBLE> );
DECLARE_VISITOR( SpecificNumArithIterator<DivideOperation,store::XS_FLOAT> );
DECLARE_VISITOR( SpecificNumArithIterator<DivideOperation,store::XS_INTEGER> );
DECLARE_VISITOR( SpecificNumArithIterator<ModOperation,store::XS_DECIMAL> );
DECLARE_VISITOR( SpecificNumArithIterator<ModOperation,store::XS_DOUBLE> );
DECLARE_VISITOR( SpecificNumArithIterator<ModOperation,store::XS_FLOAT> );
DECLARE_VISITOR( SpecificNumArithIterator<ModOperation,store::XS_INTEGER> );
DECLARE_VISITOR( SpecificNumArithIterator<MultiplyOperation,store::XS_DECIMAL> );
DECLARE_VISITOR( SpecificNumArithIterator<MultiplyOperation,store::XS_DOUBLE> );
DECLARE_VISITOR( SpecificNumArithIterator<MultiplyOperation,store::XS_FLOAT> );
DECLARE_VISITOR( SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER> );
DECLARE_VISITOR( SpecificNumArithIterator<SubtractOperation,store::XS_DECIMAL> );
DECLARE_VISITOR( SpecificNumArithIterator<SubtractOperation,store::XS_DOUBLE> );
DECLARE_VISITOR( SpecificNumArithIterator<SubtractOperation,store::XS_FLOAT> );
DECLARE_VISITOR( SpecificNumArithIterator<SubtractOperation,store::XS_INTEGER> );
DECLARE_VISITOR( TextIterator );
DECLARE_VISITOR( TransformIterator );
DECLARE_VISITOR( TreatIterator );
DECLARE_VISITOR( TryCatchIterator );
DECLARE_VISITOR( TypedValueCompareIterator<store::XS_DECIMAL> );
DECLARE_VISITOR( TypedValueCompareIterator<store::XS_DOUBLE> );
DECLARE_VISITOR( TypedValueCompareIterator<store::XS_FLOAT> );
DECLARE_VISITOR( TypedValueCompareIterator<store::XS_INTEGER> );
DECLARE_VISITOR( TypedValueCompareIterator<store::XS_STRING> );
DECLARE_VISITOR( UDFunctionCallIterator );
DECLARE_VISITOR( UnhoistIterator );
DECLARE_VISITOR( ValueIndexEntryBuilderIterator );

void beginVisitFlworReturn(const PlanIterator& a);
void endVisitFlworReturn  (const PlanIterator& );

void beginVisitFlworWhereClause(const PlanIterator& );
void endVisitFlworWhereClause(const PlanIterator& );

void beginVisitFlworLetVariable( bool, const zstring&,
                                 const std::vector<PlanIter_t>& );
void endVisitFlworLetVariable();

void beginVisitFlworForVariable( const zstring&, const std::vector<PlanIter_t>&,
                                 const std::vector<PlanIter_t>& );
void endVisitFlworForVariable();

void beginVisitMaterializeClause();
void endVisitMaterializeClause();

void beginVisitMaterializeVariable( bool, PlanIter_t,
                                    const std::vector<PlanIter_t>& );
void endVisitMaterializeVariable();

void beginVisitGroupByClause();
void endVisitGroupByClause();

void beginVisitGroupBySpec();
void endVisitGroupBySpec();

void beginVisitGroupByOuter();
void endVisitGroupByOuter();

void beginVisitGroupVariable( const std::vector<ForVarIter_t>& );
void endVisitGroupVariable();

void beginVisitNonGroupVariable( const std::vector<LetVarIter_t>& );
void endVisitNonGroupVariable();

void beginVisitOrderBySpec( const PlanIterator& );
void endVisitOrderBySpec( const PlanIterator& );

void beginVisitOrderByForVariable( ForVarIter_t, const std::vector<PlanIter_t>& );
void endVisitOrderByForVariable();

void beginVisitOrderByLetVariable( LetVarIter_t , const std::vector<PlanIter_t>& );
void endVisitOrderByLetVariable();

void beginVisitWindowVariable( const std::string&,
                               const std::vector<LetVarIter_t>& );
void endVisitWindowVariable();

void beginVisitWinCondVariable( const zstring&,
                                const std::vector<PlanIter_t>& );
void endVisitWinCondVariable();

void printNameOrKindTest( const AxisIteratorHelper* );

/* vim:set et sw=2 ts=2: */

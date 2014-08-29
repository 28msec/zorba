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

// PlanIterVisitor *Visit() member-function declarations
#define PIV_VISIT_DECL(...)      \
  void beginVisit( __VA_ARGS__ const& );  \
  void endVisit( __VA_ARGS__ const& )

PIV_VISIT_DECL( AncestorAxisIterator );
PIV_VISIT_DECL( AncestorReverseAxisIterator );
PIV_VISIT_DECL( AncestorSelfAxisIterator );
PIV_VISIT_DECL( AncestorSelfReverseAxisIterator );
PIV_VISIT_DECL( AndIterator );
PIV_VISIT_DECL( ApplyIterator );
PIV_VISIT_DECL( ArgumentPlaceholderIterator );
PIV_VISIT_DECL( AtomicValuesEquivalenceIterator );
PIV_VISIT_DECL( AttributeAxisIterator );
PIV_VISIT_DECL( AttributeIterator );
PIV_VISIT_DECL( CastableIterator );
PIV_VISIT_DECL( CastIterator );
PIV_VISIT_DECL( ChildAxisIterator );
PIV_VISIT_DECL( CommentIterator );
PIV_VISIT_DECL( CompareIterator );
PIV_VISIT_DECL( CreateIndexIterator );
PIV_VISIT_DECL( CreateInternalIndexIterator );
PIV_VISIT_DECL( CtxVarAssignIterator );
PIV_VISIT_DECL( CtxVarDeclareIterator );
PIV_VISIT_DECL( CtxVarIsSetIterator );
PIV_VISIT_DECL( CtxVarIterator );
#ifdef ZORBA_WITH_DEBUGGER
PIV_VISIT_DECL( DebuggerSingletonIterator );
#endif
PIV_VISIT_DECL( DeleteIndexIterator );
PIV_VISIT_DECL( DeleteIterator );
PIV_VISIT_DECL( DescendantAxisIterator );
PIV_VISIT_DECL( DescendantSelfAxisIterator );
PIV_VISIT_DECL( DocumentIterator );
PIV_VISIT_DECL( EitherNodesOrAtomicsIterator );
PIV_VISIT_DECL( ElementIterator );
PIV_VISIT_DECL( EmptyIterator );
PIV_VISIT_DECL( EnclosedIterator );
PIV_VISIT_DECL( EvalIterator );
PIV_VISIT_DECL( ExitCatcherIterator );
PIV_VISIT_DECL( ExitIterator );
PIV_VISIT_DECL( ExtFunctionCallIterator );
PIV_VISIT_DECL( FlowCtlIterator );
PIV_VISIT_DECL( flwor::CountIterator );
PIV_VISIT_DECL( flwor::FLWORIterator );
PIV_VISIT_DECL( flwor::ForIterator );
PIV_VISIT_DECL( flwor::GroupByIterator );
PIV_VISIT_DECL( flwor::LetIterator );
PIV_VISIT_DECL( flwor::OrderByIterator );
PIV_VISIT_DECL( flwor::OuterForIterator );
PIV_VISIT_DECL( flwor::TupleSourceIterator );
PIV_VISIT_DECL( flwor::TupleStreamIterator );
PIV_VISIT_DECL( flwor::WhereIterator );
PIV_VISIT_DECL( flwor::WindowIterator );
PIV_VISIT_DECL( FnAdjustToTimeZoneIterator_1 );
PIV_VISIT_DECL( FnAdjustToTimeZoneIterator_2 );
PIV_VISIT_DECL( FnBooleanIterator );
PIV_VISIT_DECL( FnDateTimeConstructorIterator );
PIV_VISIT_DECL( FnFormatDateTimeIterator );
PIV_VISIT_DECL( FnMinMaxIterator );
PIV_VISIT_DECL( FollowingAxisIterator );
PIV_VISIT_DECL( ForVarIterator );
PIV_VISIT_DECL( FTContainsIterator );
PIV_VISIT_DECL( FunctionItemIterator );
PIV_VISIT_DECL( GeneralIndexEntryBuilderIterator );
PIV_VISIT_DECL( GenericArithIterator<AddOperation> );
PIV_VISIT_DECL( GenericArithIterator<DivideOperation> );
PIV_VISIT_DECL( GenericArithIterator<IntegerDivideOperation> );
PIV_VISIT_DECL( GenericArithIterator<ModOperation> );
PIV_VISIT_DECL( GenericArithIterator<MultiplyOperation> );
PIV_VISIT_DECL( GenericArithIterator<SubtractOperation> );
PIV_VISIT_DECL( HoistIterator );
PIV_VISIT_DECL( IfThenElseIterator );
PIV_VISIT_DECL( InsertIterator );
PIV_VISIT_DECL( InstanceOfIterator );
PIV_VISIT_DECL( JSONArrayIterator );
PIV_VISIT_DECL( JSONDirectObjectIterator );
PIV_VISIT_DECL( JSONObjectIterator );
PIV_VISIT_DECL( LetVarIterator );
PIV_VISIT_DECL( LoopIterator );
PIV_VISIT_DECL( LSiblingAxisIterator );
PIV_VISIT_DECL( LSiblingReverseAxisIterator );
PIV_VISIT_DECL( MaterializeIterator );
PIV_VISIT_DECL( MultiDynamicFnCallIterator );
PIV_VISIT_DECL( NameCastIterator );
PIV_VISIT_DECL( NamespaceIterator );
PIV_VISIT_DECL( NodeDistinctIterator );
PIV_VISIT_DECL( NodeSortIterator );
PIV_VISIT_DECL( NumArithIterator<AddOperation> );
PIV_VISIT_DECL( NumArithIterator<DivideOperation> );
PIV_VISIT_DECL( NumArithIterator<IntegerDivideOperation> );
PIV_VISIT_DECL( NumArithIterator<ModOperation> );
PIV_VISIT_DECL( NumArithIterator<MultiplyOperation> );
PIV_VISIT_DECL( NumArithIterator<SubtractOperation> );
PIV_VISIT_DECL( OpDoubleUnaryIterator );
PIV_VISIT_DECL( OpNumericUnaryIterator );
PIV_VISIT_DECL( OrIterator );
PIV_VISIT_DECL( ParentAxisIterator );
PIV_VISIT_DECL( PiIterator );
PIV_VISIT_DECL( PlanIterator );
PIV_VISIT_DECL( PrecedingAxisIterator );
PIV_VISIT_DECL( PrecedingReverseAxisIterator );
PIV_VISIT_DECL( ProbeIndexPointGeneralIterator );
PIV_VISIT_DECL( ProbeIndexPointValueIterator );
PIV_VISIT_DECL( ProbeIndexRangeGeneralIterator );
PIV_VISIT_DECL( ProbeIndexRangeValueIterator );
PIV_VISIT_DECL( PromoteIterator );
PIV_VISIT_DECL( RefreshIndexIterator );
PIV_VISIT_DECL( RenameIterator );
PIV_VISIT_DECL( ReplaceIterator );
PIV_VISIT_DECL( RSiblingAxisIterator );
PIV_VISIT_DECL( SelfAxisIterator );
PIV_VISIT_DECL( SequentialIterator );
PIV_VISIT_DECL( SingleDynamicFnCallIterator );
PIV_VISIT_DECL( SingletonIterator );
PIV_VISIT_DECL( SpecificNumArithIterator<AddOperation,store::XS_DECIMAL> );
PIV_VISIT_DECL( SpecificNumArithIterator<AddOperation,store::XS_DOUBLE> );
PIV_VISIT_DECL( SpecificNumArithIterator<AddOperation,store::XS_FLOAT> );
PIV_VISIT_DECL( SpecificNumArithIterator<AddOperation,store::XS_INTEGER> );
PIV_VISIT_DECL( SpecificNumArithIterator<DivideOperation,store::XS_DECIMAL> );
PIV_VISIT_DECL( SpecificNumArithIterator<DivideOperation,store::XS_DOUBLE> );
PIV_VISIT_DECL( SpecificNumArithIterator<DivideOperation,store::XS_FLOAT> );
PIV_VISIT_DECL( SpecificNumArithIterator<DivideOperation,store::XS_INTEGER> );
PIV_VISIT_DECL( SpecificNumArithIterator<ModOperation,store::XS_DECIMAL> );
PIV_VISIT_DECL( SpecificNumArithIterator<ModOperation,store::XS_DOUBLE> );
PIV_VISIT_DECL( SpecificNumArithIterator<ModOperation,store::XS_FLOAT> );
PIV_VISIT_DECL( SpecificNumArithIterator<ModOperation,store::XS_INTEGER> );
PIV_VISIT_DECL( SpecificNumArithIterator<MultiplyOperation,store::XS_DECIMAL> );
PIV_VISIT_DECL( SpecificNumArithIterator<MultiplyOperation,store::XS_DOUBLE> );
PIV_VISIT_DECL( SpecificNumArithIterator<MultiplyOperation,store::XS_FLOAT> );
PIV_VISIT_DECL( SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER> );
PIV_VISIT_DECL( SpecificNumArithIterator<SubtractOperation,store::XS_DECIMAL> );
PIV_VISIT_DECL( SpecificNumArithIterator<SubtractOperation,store::XS_DOUBLE> );
PIV_VISIT_DECL( SpecificNumArithIterator<SubtractOperation,store::XS_FLOAT> );
PIV_VISIT_DECL( SpecificNumArithIterator<SubtractOperation,store::XS_INTEGER> );
PIV_VISIT_DECL( TextIterator );
PIV_VISIT_DECL( TransformIterator );
PIV_VISIT_DECL( TreatIterator );
PIV_VISIT_DECL( TryCatchIterator );
PIV_VISIT_DECL( TypedValueCompareIterator<store::XS_DECIMAL> );
PIV_VISIT_DECL( TypedValueCompareIterator<store::XS_DOUBLE> );
PIV_VISIT_DECL( TypedValueCompareIterator<store::XS_FLOAT> );
PIV_VISIT_DECL( TypedValueCompareIterator<store::XS_INTEGER> );
PIV_VISIT_DECL( TypedValueCompareIterator<store::XS_STRING> );
PIV_VISIT_DECL( UDFunctionCallIterator );
PIV_VISIT_DECL( UnhoistIterator );
PIV_VISIT_DECL( ValueIndexEntryBuilderIterator );

#undef PIV_VISIT_DECL

void visitFlworReturn(const PlanIterator&);
void visitFlworWhereClause(const PlanIterator&);
void visitOrderBySpec(const PlanIterator&);

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

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

#define DECLARE_VISITOR(class)          \
  void beginVisit(const class& a);      \
  void endVisit(const class& );

void printNameOrKindTest(const AxisIteratorHelper* a);

void beginVisit(const SingletonIterator& a);
void endVisit(const SingletonIterator& a);

void beginVisit(const EnclosedIterator& a);
void endVisit(const EnclosedIterator& a);

void beginVisit(const NodeSortIterator& a);
void endVisit(const NodeSortIterator& a);

void beginVisit(const SelfAxisIterator& a);
void endVisit(const SelfAxisIterator& a);

void beginVisit(const TreatIterator& a );
void endVisit(const TreatIterator& );

void beginVisit(const NumArithIterator<AddOperation>& a);
void endVisit(const NumArithIterator<AddOperation>& );

void beginVisit(const NumArithIterator<SubtractOperation>& a);
void endVisit(const NumArithIterator<SubtractOperation>&);

void beginVisit(const NumArithIterator<MultiplyOperation>& a);
void endVisit(const NumArithIterator<MultiplyOperation>& a);

void beginVisit(const NumArithIterator<DivideOperation>& a);
void endVisit(const NumArithIterator<DivideOperation>& a);

void beginVisit(const NumArithIterator<IntegerDivideOperation>& a);
void endVisit(const NumArithIterator<IntegerDivideOperation>& a);

void beginVisit(const NumArithIterator<ModOperation>& a);
void endVisit(const NumArithIterator<ModOperation>& a);

void beginVisit(const GenericArithIterator<AddOperation>& a );
void beginVisit(const GenericArithIterator<SubtractOperation>& a );
void beginVisit(const GenericArithIterator<MultiplyOperation>& a );
void beginVisit(const GenericArithIterator<DivideOperation>& a );
void beginVisit(const GenericArithIterator<IntegerDivideOperation>& a );
void beginVisit(const GenericArithIterator<ModOperation>& a );
void endVisit  (const GenericArithIterator<AddOperation>& );
void endVisit  (const GenericArithIterator<SubtractOperation>& );
void endVisit  (const GenericArithIterator<MultiplyOperation>& );
void endVisit  (const GenericArithIterator<DivideOperation>& );
void endVisit  (const GenericArithIterator<IntegerDivideOperation>& );
void endVisit  (const GenericArithIterator<ModOperation>& );

void beginVisit( const SpecificNumArithIterator<AddOperation, store::XS_DECIMAL>& a);
void beginVisit( const SpecificNumArithIterator<AddOperation, store::XS_INTEGER>& a);
void beginVisit( const SpecificNumArithIterator<AddOperation, store::XS_FLOAT>& a);
void beginVisit( const SpecificNumArithIterator<AddOperation, store::XS_DOUBLE>& a);
void beginVisit( const SpecificNumArithIterator<SubtractOperation, store::XS_DECIMAL>& a);
void beginVisit( const SpecificNumArithIterator<SubtractOperation, store::XS_INTEGER>& a);
void beginVisit( const SpecificNumArithIterator<SubtractOperation, store::XS_FLOAT>& a);
void beginVisit( const SpecificNumArithIterator<SubtractOperation, store::XS_DOUBLE>& a);
void beginVisit( const SpecificNumArithIterator<MultiplyOperation, store::XS_DECIMAL>& a);
void beginVisit( const SpecificNumArithIterator<MultiplyOperation, store::XS_INTEGER>& a);
void beginVisit( const SpecificNumArithIterator<MultiplyOperation, store::XS_FLOAT>& a);
void beginVisit( const SpecificNumArithIterator<MultiplyOperation, store::XS_DOUBLE>& a);
void beginVisit( const SpecificNumArithIterator<DivideOperation, store::XS_DECIMAL>& a);
void beginVisit( const SpecificNumArithIterator<DivideOperation, store::XS_INTEGER>& a);
void beginVisit(const SpecificNumArithIterator<DivideOperation, store::XS_FLOAT>& a);
void beginVisit(const SpecificNumArithIterator<DivideOperation, store::XS_DOUBLE>& a);
void beginVisit(const SpecificNumArithIterator<ModOperation, store::XS_DECIMAL>& a);
void beginVisit(const SpecificNumArithIterator<ModOperation, store::XS_INTEGER>& a);
void beginVisit(const SpecificNumArithIterator<ModOperation, store::XS_FLOAT>& a);
void beginVisit(const SpecificNumArithIterator<ModOperation, store::XS_DOUBLE>& a);
void endVisit(const SpecificNumArithIterator<AddOperation, store::XS_DECIMAL>& );
void endVisit(const SpecificNumArithIterator<AddOperation, store::XS_INTEGER>& );
void endVisit(const SpecificNumArithIterator<AddOperation, store::XS_FLOAT>& );
void endVisit(const SpecificNumArithIterator<AddOperation, store::XS_DOUBLE>& );
void endVisit(const SpecificNumArithIterator<SubtractOperation, store::XS_DECIMAL>& );
void endVisit(const SpecificNumArithIterator<SubtractOperation, store::XS_INTEGER>& );
void endVisit(const SpecificNumArithIterator<SubtractOperation, store::XS_FLOAT>& );
void endVisit(const SpecificNumArithIterator<SubtractOperation, store::XS_DOUBLE>& );
void endVisit(const SpecificNumArithIterator<MultiplyOperation, store::XS_DECIMAL>& );
void endVisit(const SpecificNumArithIterator<MultiplyOperation, store::XS_INTEGER>& );
void endVisit(const SpecificNumArithIterator<MultiplyOperation, store::XS_FLOAT>& );
void endVisit(const SpecificNumArithIterator<MultiplyOperation, store::XS_DOUBLE>& );
void endVisit(const SpecificNumArithIterator<DivideOperation, store::XS_DECIMAL>& );
void endVisit(const SpecificNumArithIterator<DivideOperation, store::XS_INTEGER>& );
void endVisit(const SpecificNumArithIterator<DivideOperation, store::XS_FLOAT>& );
void endVisit(const SpecificNumArithIterator<DivideOperation, store::XS_DOUBLE>& );
void endVisit(const SpecificNumArithIterator<ModOperation, store::XS_DECIMAL>& );
void endVisit(const SpecificNumArithIterator<ModOperation, store::XS_INTEGER>& );
void endVisit(const SpecificNumArithIterator<ModOperation, store::XS_FLOAT>& );
void endVisit(const SpecificNumArithIterator<ModOperation, store::XS_DOUBLE>& );

void beginVisit ( const FnMinMaxIterator& a);
void endVisit   ( const FnMinMaxIterator& );

void beginVisit(const FTContainsIterator& a);
void endVisit  (const FTContainsIterator& );

void beginVisit(const ForVarIterator& a);
void endVisit(const ForVarIterator& );

void beginVisit(const LetVarIterator& a);
void endVisit(const LetVarIterator& );

void beginVisitFlworWhereClause(const PlanIterator& a);
void endVisitFlworWhereClause(const PlanIterator& );

void beginVisitFlworLetVariable(
        bool materialize,
        const zstring& varName,
        const std::vector<PlanIter_t>& varRefs);

void endVisitFlworLetVariable();

void beginVisitFlworForVariable(
        const zstring& varName,
        const std::vector<PlanIter_t>& varRefs,
        const std::vector<PlanIter_t>& posRefs);

void endVisitFlworForVariable();

void beginVisitMaterializeClause();

void endVisitMaterializeClause();

void beginVisitMaterializeVariable(
      bool isForVar,
      PlanIter_t inputVar,
      const std::vector<PlanIter_t>& varRefs);

void endVisitMaterializeVariable();

void beginVisitGroupByClause();

void endVisitGroupByClause();

void beginVisitGroupBySpec();

void endVisitGroupBySpec();

void beginVisitGroupByOuter();

void endVisitGroupByOuter();

void beginVisitGroupVariable(const std::vector<ForVarIter_t>& varRefs);

void endVisitGroupVariable();

void beginVisitNonGroupVariable(const std::vector<LetVarIter_t>& varRefs);

void endVisitNonGroupVariable();

void beginVisitOrderBySpec(const PlanIterator& a);

void endVisitOrderBySpec(const PlanIterator& );

void beginVisitOrderByForVariable(
        ForVarIter_t inputVar,
        const std::vector<PlanIter_t>& varRefs);

void endVisitOrderByForVariable();

void beginVisitOrderByLetVariable(
        LetVarIter_t inputVar,
        const std::vector<PlanIter_t>& varRefs);

void endVisitOrderByLetVariable();

void beginVisitWindowVariable(
        const std::string& varName,
        const std::vector<LetVarIter_t>& varRefs);

void endVisitWindowVariable();

    void beginVisitWinCondVariable(
        const zstring& varName,
        const std::vector<PlanIter_t>& varRefs);

    void endVisitWinCondVariable();

    void beginVisitFlworReturn(const PlanIterator& a);

    void endVisitFlworReturn  (const PlanIterator& );
    void beginVisit(const CastIterator& a);
    void endVisit  (const CastIterator&);
    void beginVisit(const PromoteIterator& a);
    void endVisit  (const PromoteIterator& );
    void beginVisit(const CastableIterator& a);
    void endVisit  (const CastableIterator& );
    void beginVisit ( const TypedValueCompareIterator<store::XS_DECIMAL>& a);
    void beginVisit ( const TypedValueCompareIterator<store::XS_INTEGER>& a);
    void beginVisit ( const TypedValueCompareIterator<store::XS_DOUBLE>& a);
    void beginVisit ( const TypedValueCompareIterator<store::XS_FLOAT>& a);
    void beginVisit ( const TypedValueCompareIterator<store::XS_STRING>& a);
    void endVisit ( const TypedValueCompareIterator<store::XS_DECIMAL>& a);
    void endVisit ( const TypedValueCompareIterator<store::XS_INTEGER>& a);
    void endVisit ( const TypedValueCompareIterator<store::XS_DOUBLE>& a);
    void endVisit ( const TypedValueCompareIterator<store::XS_FLOAT>& a);
    void endVisit ( const TypedValueCompareIterator<store::XS_STRING>& a);

  DECLARE_VISITOR (UDFunctionCallIterator)
  DECLARE_VISITOR (ExtFunctionCallIterator)
  DECLARE_VISITOR (FnBooleanIterator)
  DECLARE_VISITOR (OrIterator)
  DECLARE_VISITOR (AndIterator)
  DECLARE_VISITOR (CompareIterator)
  DECLARE_VISITOR (AtomicValuesEquivalenceIterator)
  DECLARE_VISITOR (ElementIterator)
  DECLARE_VISITOR (AttributeIterator)
  DECLARE_VISITOR (DocumentIterator)
  DECLARE_VISITOR (CommentIterator)
  DECLARE_VISITOR (PiIterator)
  DECLARE_VISITOR (EmptyIterator)
  DECLARE_VISITOR (IfThenElseIterator)
  DECLARE_VISITOR (NodeDistinctIterator)
  DECLARE_VISITOR (InstanceOfIterator)
  DECLARE_VISITOR (EitherNodesOrAtomicsIterator)
  DECLARE_VISITOR (OpNumericUnaryIterator)
  DECLARE_VISITOR (OpDoubleUnaryIterator)
  DECLARE_VISITOR (TextIterator)
  DECLARE_VISITOR (FnDateTimeConstructorIterator)
  DECLARE_VISITOR (TryCatchIterator)
  DECLARE_VISITOR (flwor::FLWORIterator)
  DECLARE_VISITOR (flwor::TupleStreamIterator)
  DECLARE_VISITOR (flwor::TupleSourceIterator)
  DECLARE_VISITOR (flwor::ForIterator)
  DECLARE_VISITOR (flwor::OuterForIterator)
  DECLARE_VISITOR (flwor::LetIterator)
  DECLARE_VISITOR (flwor::WhereIterator)
  DECLARE_VISITOR (flwor::CountIterator)
  DECLARE_VISITOR (flwor::GroupByIterator)
  DECLARE_VISITOR (flwor::OrderByIterator)
  DECLARE_VISITOR (flwor::WindowIterator)
  DECLARE_VISITOR (NameCastIterator)
  DECLARE_VISITOR (CtxVarIterator)
  DECLARE_VISITOR (CtxVarDeclareIterator)
  DECLARE_VISITOR (CtxVarAssignIterator)
  DECLARE_VISITOR (CtxVarIsSetIterator)
  DECLARE_VISITOR (FnAdjustToTimeZoneIterator_1);
  DECLARE_VISITOR (FnAdjustToTimeZoneIterator_2);
  DECLARE_VISITOR (FnFormatDateTimeIterator);
  DECLARE_VISITOR (InsertIterator);
  DECLARE_VISITOR (DeleteIterator);
  DECLARE_VISITOR (ReplaceIterator);
  DECLARE_VISITOR (RenameIterator);
  DECLARE_VISITOR (TransformIterator);
  DECLARE_VISITOR (ApplyIterator);
#ifdef ZORBA_WITH_DEBUGGER
  DECLARE_VISITOR (DebuggerSingletonIterator);
#endif
  DECLARE_VISITOR (HoistIterator);
  DECLARE_VISITOR (UnhoistIterator);

  DECLARE_VISITOR (AttributeAxisIterator)
  DECLARE_VISITOR (ParentAxisIterator)
  DECLARE_VISITOR (AncestorAxisIterator)
  DECLARE_VISITOR (AncestorReverseAxisIterator)
  DECLARE_VISITOR (AncestorSelfAxisIterator)
  DECLARE_VISITOR (AncestorSelfReverseAxisIterator)
  DECLARE_VISITOR (RSiblingAxisIterator)
  DECLARE_VISITOR (LSiblingAxisIterator)
  DECLARE_VISITOR (LSiblingReverseAxisIterator)
  DECLARE_VISITOR (ChildAxisIterator)
  DECLARE_VISITOR (DescendantAxisIterator)
  DECLARE_VISITOR (DescendantSelfAxisIterator)
  DECLARE_VISITOR (PrecedingAxisIterator)
  DECLARE_VISITOR (PrecedingReverseAxisIterator)
  DECLARE_VISITOR (FollowingAxisIterator)
  DECLARE_VISITOR(ProbeIndexPointValueIterator);
  DECLARE_VISITOR(ProbeIndexPointGeneralIterator);
  DECLARE_VISITOR(ProbeIndexRangeValueIterator);
  DECLARE_VISITOR(ProbeIndexRangeGeneralIterator);
  DECLARE_VISITOR(ValueIndexEntryBuilderIterator);
  DECLARE_VISITOR(GeneralIndexEntryBuilderIterator);
  DECLARE_VISITOR(RefreshIndexIterator);
  DECLARE_VISITOR(CreateIndexIterator);
  DECLARE_VISITOR(CreateInternalIndexIterator);
  DECLARE_VISITOR(DeleteIndexIterator);

  DECLARE_VISITOR(DynamicFnCallIterator);

  DECLARE_VISITOR(EvalIterator);

  DECLARE_VISITOR(MaterializeIterator);

  DECLARE_VISITOR(SequentialIterator);
  DECLARE_VISITOR(ExitIterator);
  DECLARE_VISITOR(ExitCatcherIterator);
  DECLARE_VISITOR(LoopIterator);
  DECLARE_VISITOR(FlowCtlIterator);

  DECLARE_VISITOR(CountCollectionIterator);

/* vim:set et sw=2 ts=2: */

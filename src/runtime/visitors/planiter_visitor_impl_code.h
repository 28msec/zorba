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

PLAN_ITER_VISITOR (FnBooleanIterator);

PLAN_ITER_VISITOR (OrIterator);

PLAN_ITER_VISITOR (AndIterator);

  PLAN_ITER_VISITOR (CompareIterator);

  PLAN_ITER_VISITOR (AtomicValuesEquivalenceIterator);

  PLAN_ITER_VISITOR (ElementIterator);

  PLAN_ITER_VISITOR (AttributeIterator );

  PLAN_ITER_VISITOR (DocumentIterator);

  PLAN_ITER_VISITOR (DocumentContentIterator);

  PLAN_ITER_VISITOR (UDFunctionCallIterator);

  PLAN_ITER_VISITOR (ExtFunctionCallIterator);

  PLAN_ITER_VISITOR (CommentIterator);

  PLAN_ITER_VISITOR (PiIterator);

  PLAN_ITER_VISITOR (SingletonIterator);

  PLAN_ITER_VISITOR (EmptyIterator);

  PLAN_ITER_VISITOR (ForVarIterator);

  PLAN_ITER_VISITOR (LetVarIterator);

  PLAN_ITER_VISITOR (EnclosedIterator);

  PLAN_ITER_VISITOR (IfThenElseIterator);

  PLAN_ITER_VISITOR (TryCatchIterator);

  PLAN_ITER_VISITOR (NodeDistinctIterator);

  PLAN_ITER_VISITOR (NodeSortIterator);

  //PLAN_ITER_VISITOR (PathIterator);

  PLAN_ITER_VISITOR (SelfAxisIterator);

  PLAN_ITER_VISITOR (AttributeAxisIterator);

  PLAN_ITER_VISITOR (ParentAxisIterator);

  PLAN_ITER_VISITOR (AncestorAxisIterator);

  PLAN_ITER_VISITOR (AncestorReverseAxisIterator);

  PLAN_ITER_VISITOR (AncestorSelfAxisIterator);

  PLAN_ITER_VISITOR (AncestorSelfReverseAxisIterator);

  PLAN_ITER_VISITOR (RSiblingAxisIterator);

  PLAN_ITER_VISITOR (LSiblingAxisIterator);

  PLAN_ITER_VISITOR (LSiblingReverseAxisIterator);

  PLAN_ITER_VISITOR (ChildAxisIterator);

  PLAN_ITER_VISITOR (DescendantAxisIterator);

  PLAN_ITER_VISITOR (DescendantSelfAxisIterator);

  PLAN_ITER_VISITOR (PrecedingAxisIterator);

  PLAN_ITER_VISITOR (PrecedingReverseAxisIterator);

  PLAN_ITER_VISITOR (FollowingAxisIterator);

  PLAN_ITER_VISITOR (InstanceOfIterator);

  PLAN_ITER_VISITOR (TreatIterator);

  PLAN_ITER_VISITOR (EitherNodesOrAtomicsIterator);

  virtual void beginVisit ( const NumArithIterator<AddOperation>& ) = 0;
  virtual void beginVisit ( const NumArithIterator<SubtractOperation>& ) = 0;
  virtual void beginVisit ( const NumArithIterator<MultiplyOperation>& ) = 0;
  virtual void beginVisit ( const NumArithIterator<DivideOperation>& ) = 0;
  virtual void beginVisit ( const NumArithIterator<IntegerDivideOperation>& ) = 0;
  virtual void beginVisit ( const NumArithIterator<ModOperation>& ) = 0;
  virtual void endVisit ( const NumArithIterator<AddOperation>& ) = 0;
  virtual void endVisit ( const NumArithIterator<SubtractOperation>& ) = 0;
  virtual void endVisit ( const NumArithIterator<MultiplyOperation>& ) = 0;
  virtual void endVisit ( const NumArithIterator<DivideOperation>& ) = 0;
  virtual void endVisit ( const NumArithIterator<IntegerDivideOperation>& ) = 0;
  virtual void endVisit ( const NumArithIterator<ModOperation>& ) = 0;

  virtual void beginVisit ( const GenericArithIterator<AddOperation>& ) = 0;
  virtual void beginVisit ( const GenericArithIterator<SubtractOperation>& ) = 0;
  virtual void beginVisit ( const GenericArithIterator<MultiplyOperation>& ) = 0;
  virtual void beginVisit ( const GenericArithIterator<DivideOperation>& ) = 0;
  virtual void beginVisit ( const GenericArithIterator<IntegerDivideOperation>& ) = 0;
  virtual void beginVisit ( const GenericArithIterator<ModOperation>& ) = 0;
  virtual void endVisit ( const GenericArithIterator<AddOperation>& ) = 0;
  virtual void endVisit ( const GenericArithIterator<SubtractOperation>& ) = 0;
  virtual void endVisit ( const GenericArithIterator<MultiplyOperation>& ) = 0;
  virtual void endVisit ( const GenericArithIterator<DivideOperation>& ) = 0;
  virtual void endVisit ( const GenericArithIterator<IntegerDivideOperation>& ) = 0;
  virtual void endVisit ( const GenericArithIterator<ModOperation>& ) = 0;

  virtual void beginVisit ( const SpecificNumArithIterator<AddOperation, TypeConstants::XS_DECIMAL>& ) = 0;
  virtual void beginVisit ( const SpecificNumArithIterator<AddOperation, TypeConstants::XS_INTEGER>& ) = 0;
  virtual void beginVisit ( const SpecificNumArithIterator<AddOperation, TypeConstants::XS_FLOAT>& ) = 0;
  virtual void beginVisit ( const SpecificNumArithIterator<AddOperation, TypeConstants::XS_DOUBLE>& ) = 0;
  virtual void beginVisit ( const SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_DECIMAL>& ) = 0;
  virtual void beginVisit ( const SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_INTEGER>& ) = 0;
  virtual void beginVisit ( const SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_FLOAT>& ) = 0;
  virtual void beginVisit ( const SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_DOUBLE>& ) = 0;
  virtual void beginVisit ( const SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_DECIMAL>& ) = 0;
  virtual void beginVisit ( const SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_INTEGER>& ) = 0;
  virtual void beginVisit ( const SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_FLOAT>& ) = 0;
  virtual void beginVisit ( const SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_DOUBLE>& ) = 0;
  virtual void beginVisit ( const SpecificNumArithIterator<DivideOperation, TypeConstants::XS_DECIMAL>& ) = 0;
  virtual void beginVisit ( const SpecificNumArithIterator<DivideOperation, TypeConstants::XS_INTEGER>& ) = 0;
  virtual void beginVisit ( const SpecificNumArithIterator<DivideOperation, TypeConstants::XS_FLOAT>& ) = 0;
  virtual void beginVisit ( const SpecificNumArithIterator<DivideOperation, TypeConstants::XS_DOUBLE>& ) = 0;
  virtual void beginVisit ( const SpecificNumArithIterator<ModOperation, TypeConstants::XS_DECIMAL>& ) = 0;
  virtual void beginVisit ( const SpecificNumArithIterator<ModOperation, TypeConstants::XS_INTEGER>& ) = 0;
  virtual void beginVisit ( const SpecificNumArithIterator<ModOperation, TypeConstants::XS_FLOAT>& ) = 0;
  virtual void beginVisit ( const SpecificNumArithIterator<ModOperation, TypeConstants::XS_DOUBLE>& ) = 0;
  virtual void endVisit ( const SpecificNumArithIterator<AddOperation, TypeConstants::XS_DECIMAL>& ) = 0;
  virtual void endVisit ( const SpecificNumArithIterator<AddOperation, TypeConstants::XS_INTEGER>& ) = 0;
  virtual void endVisit ( const SpecificNumArithIterator<AddOperation, TypeConstants::XS_FLOAT>& ) = 0;
  virtual void endVisit ( const SpecificNumArithIterator<AddOperation, TypeConstants::XS_DOUBLE>& ) = 0;
  virtual void endVisit ( const SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_DECIMAL>& ) = 0;
  virtual void endVisit ( const SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_INTEGER>& ) = 0;
  virtual void endVisit ( const SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_FLOAT>& ) = 0;
  virtual void endVisit ( const SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_DOUBLE>& ) = 0;
  virtual void endVisit ( const SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_DECIMAL>& ) = 0;
  virtual void endVisit ( const SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_INTEGER>& ) = 0;
  virtual void endVisit ( const SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_FLOAT>& ) = 0;
  virtual void endVisit ( const SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_DOUBLE>& ) = 0;
  virtual void endVisit ( const SpecificNumArithIterator<DivideOperation, TypeConstants::XS_DECIMAL>& ) = 0;
  virtual void endVisit ( const SpecificNumArithIterator<DivideOperation, TypeConstants::XS_INTEGER>& ) = 0;
  virtual void endVisit ( const SpecificNumArithIterator<DivideOperation, TypeConstants::XS_FLOAT>& ) = 0;
  virtual void endVisit ( const SpecificNumArithIterator<DivideOperation, TypeConstants::XS_DOUBLE>& ) = 0;
  virtual void endVisit ( const SpecificNumArithIterator<ModOperation, TypeConstants::XS_DECIMAL>& ) = 0;
  virtual void endVisit ( const SpecificNumArithIterator<ModOperation, TypeConstants::XS_INTEGER>& ) = 0;
  virtual void endVisit ( const SpecificNumArithIterator<ModOperation, TypeConstants::XS_FLOAT>& ) = 0;
  virtual void endVisit ( const SpecificNumArithIterator<ModOperation, TypeConstants::XS_DOUBLE>& ) = 0;

  virtual void beginVisit ( const TypedValueCompareIterator<TypeConstants::XS_DOUBLE>& ) = 0;
  virtual void endVisit ( const TypedValueCompareIterator<TypeConstants::XS_DOUBLE>& ) = 0;
  virtual void beginVisit ( const TypedValueCompareIterator<TypeConstants::XS_FLOAT>& ) = 0;
  virtual void endVisit ( const TypedValueCompareIterator<TypeConstants::XS_FLOAT>& ) = 0;
  virtual void beginVisit ( const TypedValueCompareIterator<TypeConstants::XS_DECIMAL>& ) = 0;
  virtual void endVisit ( const TypedValueCompareIterator<TypeConstants::XS_DECIMAL>& ) = 0;
  virtual void beginVisit ( const TypedValueCompareIterator<TypeConstants::XS_INTEGER>& ) = 0;
  virtual void endVisit ( const TypedValueCompareIterator<TypeConstants::XS_INTEGER>& ) = 0;
  virtual void beginVisit ( const TypedValueCompareIterator<TypeConstants::XS_STRING>& ) = 0;
  virtual void endVisit ( const TypedValueCompareIterator<TypeConstants::XS_STRING>& ) = 0;

  PLAN_ITER_VISITOR (OpNumericUnaryIterator);

  PLAN_ITER_VISITOR (OpDoubleUnaryIterator);

  PLAN_ITER_VISITOR (FnMinMaxIterator);

  PLAN_ITER_VISITOR (TextIterator);

  PLAN_ITER_VISITOR (flwor::FLWORIterator);

  PLAN_ITER_VISITOR (flwor::TupleStreamIterator);

  PLAN_ITER_VISITOR (flwor::TupleSourceIterator);

  PLAN_ITER_VISITOR (flwor::ForIterator);

  PLAN_ITER_VISITOR (flwor::OuterForIterator);

  PLAN_ITER_VISITOR (flwor::LetIterator);

  PLAN_ITER_VISITOR (flwor::GroupByIterator);

  PLAN_ITER_VISITOR (flwor::OrderByIterator);

  PLAN_ITER_VISITOR (flwor::WhereIterator);

  PLAN_ITER_VISITOR (flwor::CountIterator);

  PLAN_ITER_VISITOR (flwor::WindowIterator);

  virtual void beginVisitFlworWhereClause(const PlanIterator&) = 0;

  virtual void endVisitFlworWhereClause(const PlanIterator&) = 0;

  virtual void beginVisitFlworLetVariable(
        bool,
        const zstring&,
        const std::vector<PlanIter_t>&) = 0;

  virtual void endVisitFlworLetVariable() = 0;

  virtual void beginVisitFlworForVariable(
       const zstring&,
       const std::vector<PlanIter_t>&,
       const std::vector<PlanIter_t>&) = 0;

  virtual void endVisitFlworForVariable() = 0;

  virtual void beginVisitMaterializeClause() = 0;

  virtual void endVisitMaterializeClause() = 0;

  virtual void beginVisitMaterializeVariable(
      bool isForVar,
      PlanIter_t inputVar,
      const std::vector<PlanIter_t>& varRefs) = 0;

  virtual void endVisitMaterializeVariable() = 0;

  virtual void beginVisitGroupByClause() = 0;

  virtual void endVisitGroupByClause() = 0;

  virtual void beginVisitGroupBySpec() = 0;

  virtual void endVisitGroupBySpec() = 0;

  virtual void beginVisitGroupByOuter() = 0;

  virtual void endVisitGroupByOuter() = 0;

  virtual void beginVisitGroupVariable(const std::vector<ForVarIter_t>&) = 0;

  virtual void endVisitGroupVariable() = 0;

  virtual void beginVisitNonGroupVariable(const std::vector<LetVarIter_t>&) = 0;

  virtual void endVisitNonGroupVariable() = 0;

  virtual void beginVisitOrderBySpec(const PlanIterator&) = 0;

  virtual void endVisitOrderBySpec(const PlanIterator&) = 0;

  virtual void beginVisitOrderByForVariable(
        ForVarIter_t inputVar,
        const std::vector<PlanIter_t>& varRefs) = 0;

  virtual void endVisitOrderByForVariable() = 0;

  virtual void beginVisitOrderByLetVariable(
        LetVarIter_t inputVar,
        const std::vector<PlanIter_t>& varRefs) = 0;

  virtual void endVisitOrderByLetVariable() = 0;

  virtual void beginVisitWindowVariable(
        const std::string& varName,
        const std::vector<LetVarIter_t>& varRefs) = 0;

  virtual void endVisitWindowVariable() = 0;

  virtual void beginVisitWinCondVariable(
        const std::string& varName,
        const std::vector<PlanIter_t>& varRefs) = 0;

  virtual void endVisitWinCondVariable() = 0;

  virtual void beginVisitFlworReturn(const PlanIterator&) = 0;

  virtual void endVisitFlworReturn(const PlanIterator&) = 0;

  PLAN_ITER_VISITOR (CastIterator);

  PLAN_ITER_VISITOR (NameCastIterator);

  PLAN_ITER_VISITOR (PromoteIterator);

  PLAN_ITER_VISITOR (CastableIterator);

  PLAN_ITER_VISITOR (FnDateTimeConstructorIterator);

  PLAN_ITER_VISITOR (CtxVarIterator);

  PLAN_ITER_VISITOR (CtxVarDeclareIterator);

  PLAN_ITER_VISITOR (CtxVarAssignIterator);

  PLAN_ITER_VISITOR (CtxVarIsSetIterator);

  PLAN_ITER_VISITOR(FnAdjustToTimeZoneIterator_1);

  PLAN_ITER_VISITOR(FnAdjustToTimeZoneIterator_2);

  PLAN_ITER_VISITOR(FnFormatDateTimeIterator);

  PLAN_ITER_VISITOR(InsertIterator);

  PLAN_ITER_VISITOR(DeleteIterator);

  PLAN_ITER_VISITOR(ReplaceIterator);

  PLAN_ITER_VISITOR(RenameIterator);

  PLAN_ITER_VISITOR(TransformIterator);

  PLAN_ITER_VISITOR(ApplyIterator);

  PLAN_ITER_VISITOR(FTContainsIterator);

#ifdef ZORBA_WITH_DEBUGGER
  PLAN_ITER_VISITOR ( DebuggerSingletonIterator );
#endif

  PLAN_ITER_VISITOR(HoistIterator);
  PLAN_ITER_VISITOR(UnhoistIterator);

  PLAN_ITER_VISITOR(ProbeIndexPointValueIterator);
  PLAN_ITER_VISITOR(ProbeIndexPointGeneralIterator);
  PLAN_ITER_VISITOR(ProbeIndexRangeValueIterator);
  PLAN_ITER_VISITOR(ProbeIndexRangeGeneralIterator);
  PLAN_ITER_VISITOR(ValueIndexEntryBuilderIterator);
  PLAN_ITER_VISITOR(GeneralIndexEntryBuilderIterator);
  PLAN_ITER_VISITOR(RefreshIndexIterator);
  PLAN_ITER_VISITOR(CreateIndexIterator);
  PLAN_ITER_VISITOR(CreateInternalIndexIterator);
  PLAN_ITER_VISITOR(DeleteIndexIterator);

  PLAN_ITER_VISITOR(DynamicFnCallIterator);

  PLAN_ITER_VISITOR(EvalIterator);

  PLAN_ITER_VISITOR(MaterializeIterator);

PLAN_ITER_VISITOR(SequentialIterator);
PLAN_ITER_VISITOR(LoopIterator);
PLAN_ITER_VISITOR(ExitIterator);
PLAN_ITER_VISITOR(ExitCatcherIterator);
PLAN_ITER_VISITOR(FlowCtlIterator);

PLAN_ITER_VISITOR(CountCollectionIterator);
/* vim:set et sw=2 ts=2: */

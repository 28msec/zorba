  PLAN_ITER_VISITOR (FnBooleanIterator);

  PLAN_ITER_VISITOR (LogicIterator);
       
  PLAN_ITER_VISITOR (CompareIterator);
       
  PLAN_ITER_VISITOR (ElementIterator);
       
  PLAN_ITER_VISITOR (AttributeIterator );
      
  PLAN_ITER_VISITOR (DocumentIterator);
      
  PLAN_ITER_VISITOR (DocumentContentIterator);
       
  PLAN_ITER_VISITOR (UDFunctionCallIterator);
       
  PLAN_ITER_VISITOR (StatelessExtFunctionCallIterator);
       
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

  PLAN_ITER_VISITOR (CreateInternalIndexIterator);
  PLAN_ITER_VISITOR (RebuildIndexIterator);
  PLAN_ITER_VISITOR (IndexEntryBuilderIterator);
  PLAN_ITER_VISITOR (IndexPointProbeIterator);
  PLAN_ITER_VISITOR (IndexRangeProbeIterator);
  PLAN_ITER_VISITOR (IsAvailableIndexIterator);
  PLAN_ITER_VISITOR (AvailableIndexesIterator);
  PLAN_ITER_VISITOR (IsDeclaredIndexIterator);
  PLAN_ITER_VISITOR (DeclaredIndexesIterator);
  
  PLAN_ITER_VISITOR (OpNumericUnaryIterator);
    
  PLAN_ITER_VISITOR (FnIdIterator);

  PLAN_ITER_VISITOR (FnIdRefIterator);

  PLAN_ITER_VISITOR (FnMinMaxIterator);

  PLAN_ITER_VISITOR (TextIterator);

  PLAN_ITER_VISITOR (CreateTupleIterator);

  PLAN_ITER_VISITOR (GetTupleFieldIterator);
            
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
        const xqpStringStore_t,
        const std::vector<LetVarIter_t>&) = 0;

  virtual void endVisitFlworLetVariable() = 0;
    
  virtual void beginVisitFlworForVariable(
       const xqpStringStore_t,
       const std::vector<ForVarIter_t>&,
       const std::vector<ForVarIter_t>&) = 0;

  virtual void endVisitFlworForVariable() = 0;
    
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
    
  virtual void beginVisitOrderBy(const PlanIterator&) = 0;

  virtual void endVisitOrderBy(const PlanIterator&) = 0;
    
  virtual void beginVisitOrderByForVariable(
        ForVarIter_t inputVar,
        const std::vector<ForVarIter_t>& varRefs) = 0;

  virtual void endVisitOrderByForVariable() = 0;

  virtual void beginVisitOrderByLetVariable(
        LetVarIter_t inputVar,
        const std::vector<LetVarIter_t>& varRefs) = 0;

  virtual void endVisitOrderByLetVariable() = 0;

  virtual void beginVisitWindowVariable(
        const std::string& varName,
        const std::vector<LetVarIter_t>& varRefs) = 0;

  virtual void endVisitWindowVariable() = 0;

  virtual void beginVisitWinCondVariable(
        const std::string& varName,
        const std::vector<ForVarIter_t>& varRefs) = 0;

  virtual void endVisitWinCondVariable() = 0;

  virtual void beginVisitFlworReturn(const PlanIterator&) = 0;

  virtual void endVisitFlworReturn(const PlanIterator&) = 0;
      
  PLAN_ITER_VISITOR (CastIterator);

  PLAN_ITER_VISITOR (NameCastIterator);

  PLAN_ITER_VISITOR (PromoteIterator);

  PLAN_ITER_VISITOR (CastableIterator);

  PLAN_ITER_VISITOR (FnDateTimeConstructorIterator);

  PLAN_ITER_VISITOR (CtxVariableIterator);

  PLAN_ITER_VISITOR (CtxVarDeclIterator);

  PLAN_ITER_VISITOR (CtxVarAssignIterator);

  PLAN_ITER_VISITOR (CtxVarExistsIterator);

  PLAN_ITER_VISITOR(FnAdjustToTimeZoneIterator_1);

  PLAN_ITER_VISITOR(FnAdjustToTimeZoneIterator_2);

  PLAN_ITER_VISITOR(FnFormatDateTimeIterator);

  PLAN_ITER_VISITOR(InsertIterator);

  PLAN_ITER_VISITOR(DeleteIterator);

  PLAN_ITER_VISITOR(ReplaceIterator);

  PLAN_ITER_VISITOR(RenameIterator);

  PLAN_ITER_VISITOR(TransformIterator);

  PLAN_ITER_VISITOR(ApplyIterator);

#ifdef ZORBA_WITH_TIDY
  PLAN_ITER_VISITOR(ZorbaTidyIterator);
  PLAN_ITER_VISITOR(ZorbaTDocIterator);
#endif
#ifdef ZORBA_WITH_FOP
	PLAN_ITER_VISITOR(ZorbaFopIterator);
#endif // ZORBA_WITH_FOP

  PLAN_ITER_VISITOR ( ZorbaDebugIterator );
  PLAN_ITER_VISITOR ( DebuggerSingletonIterator );

#ifdef ZORBA_WITH_REST
  PLAN_ITER_VISITOR(ZorbaRestGetIterator);
  PLAN_ITER_VISITOR(ZorbaRestPostIterator);
  PLAN_ITER_VISITOR(ZorbaRestPutIterator);
  PLAN_ITER_VISITOR(ZorbaRestDeleteIterator);
  PLAN_ITER_VISITOR(ZorbaRestHeadIterator);
#endif

  PLAN_ITER_VISITOR(HoistIterator);
  PLAN_ITER_VISITOR(UnhoistIterator);

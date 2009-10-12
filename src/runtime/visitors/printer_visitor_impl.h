#define DECLARE_VISITOR(class)          \
  void beginVisit ( const class& a );   \
  void endVisit   ( const class& );  

    void printNameOrKindTest(const AxisIteratorHelper* a);
    void beginVisit( const SingletonIterator& a);
    void endVisit  ( const SingletonIterator& );
    void beginVisit( const EnclosedIterator& a );
    void endVisit  ( const EnclosedIterator& );
    void beginVisit( const NodeSortIterator& a );
    void endVisit  ( const NodeSortIterator& );
    void beginVisit( const SelfAxisIterator& a );
    void endVisit  ( const SelfAxisIterator&);
    void beginVisit( const TreatIterator& a );
    void endVisit  ( const TreatIterator& );
    void beginVisit( const NumArithIterator<AddOperation>& a );
    void beginVisit( const NumArithIterator<SubtractOperation>& a );
    void beginVisit( const NumArithIterator<MultiplyOperation>& a );
    void beginVisit( const NumArithIterator<DivideOperation>& a );
    void beginVisit( const NumArithIterator<IntegerDivideOperation>& a );
    void beginVisit( const NumArithIterator<ModOperation>& a );
    void endVisit  ( const NumArithIterator<AddOperation>& );
    void endVisit  ( const NumArithIterator<SubtractOperation>&);
    void endVisit  ( const NumArithIterator<MultiplyOperation>& );
    void endVisit  ( const NumArithIterator<DivideOperation>&);
    void endVisit  ( const NumArithIterator<IntegerDivideOperation>& );
    void endVisit  ( const NumArithIterator<ModOperation>& );
    void beginVisit( const GenericArithIterator<AddOperation>& a );
    void beginVisit( const GenericArithIterator<SubtractOperation>& a );
    void beginVisit( const GenericArithIterator<MultiplyOperation>& a );
    void beginVisit( const GenericArithIterator<DivideOperation>& a );
    void beginVisit( const GenericArithIterator<IntegerDivideOperation>& a );
    void beginVisit( const GenericArithIterator<ModOperation>& a );
    void endVisit  ( const GenericArithIterator<AddOperation>& );
    void endVisit  ( const GenericArithIterator<SubtractOperation>& );
    void endVisit  ( const GenericArithIterator<MultiplyOperation>& );
    void endVisit  ( const GenericArithIterator<DivideOperation>& );
    void endVisit  ( const GenericArithIterator<IntegerDivideOperation>& );
    void endVisit  ( const GenericArithIterator<ModOperation>& );
    void beginVisit( const SpecificNumArithIterator<AddOperation, TypeConstants::XS_DECIMAL>& a);
    void beginVisit( const SpecificNumArithIterator<AddOperation, TypeConstants::XS_INTEGER>& a);
    void beginVisit( const SpecificNumArithIterator<AddOperation, TypeConstants::XS_FLOAT>& a);
    void beginVisit( const SpecificNumArithIterator<AddOperation, TypeConstants::XS_DOUBLE>& a);
    void beginVisit( const SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_DECIMAL>& a);
    void beginVisit( const SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_INTEGER>& a);
    void beginVisit( const SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_FLOAT>& a);
    void beginVisit( const SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_DOUBLE>& a);
    void beginVisit( const SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_DECIMAL>& a);
    void beginVisit( const SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_INTEGER>& a);
    void beginVisit( const SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_FLOAT>& a);
    void beginVisit( const SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_DOUBLE>& a);
    void beginVisit( const SpecificNumArithIterator<DivideOperation, TypeConstants::XS_DECIMAL>& a);
    void beginVisit( const SpecificNumArithIterator<DivideOperation, TypeConstants::XS_INTEGER>& a);
    void beginVisit( const SpecificNumArithIterator<DivideOperation, TypeConstants::XS_FLOAT>& a);
    void beginVisit( const SpecificNumArithIterator<DivideOperation, TypeConstants::XS_DOUBLE>& a);
    void beginVisit( const SpecificNumArithIterator<ModOperation, TypeConstants::XS_DECIMAL>& a);
    void beginVisit( const SpecificNumArithIterator<ModOperation, TypeConstants::XS_INTEGER>& a);
    void beginVisit( const SpecificNumArithIterator<ModOperation, TypeConstants::XS_FLOAT>& a);
    void beginVisit( const SpecificNumArithIterator<ModOperation, TypeConstants::XS_DOUBLE>& a);
    void endVisit ( const SpecificNumArithIterator<AddOperation, TypeConstants::XS_DECIMAL>& );
    void endVisit ( const SpecificNumArithIterator<AddOperation, TypeConstants::XS_INTEGER>& );
    void endVisit ( const SpecificNumArithIterator<AddOperation, TypeConstants::XS_FLOAT>& );
    void endVisit ( const SpecificNumArithIterator<AddOperation, TypeConstants::XS_DOUBLE>& );
    void endVisit ( const SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_DECIMAL>& );
    void endVisit ( const SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_INTEGER>& );
    void endVisit ( const SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_FLOAT>& );
    void endVisit ( const SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_DOUBLE>& );
    void endVisit ( const SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_DECIMAL>& );
    void endVisit ( const SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_INTEGER>& );
    void endVisit ( const SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_FLOAT>& );
    void endVisit ( const SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_DOUBLE>& );
    void endVisit ( const SpecificNumArithIterator<DivideOperation, TypeConstants::XS_DECIMAL>& );
    void endVisit ( const SpecificNumArithIterator<DivideOperation, TypeConstants::XS_INTEGER>& );
    void endVisit ( const SpecificNumArithIterator<DivideOperation, TypeConstants::XS_FLOAT>& );
    void endVisit ( const SpecificNumArithIterator<DivideOperation, TypeConstants::XS_DOUBLE>& );
    void endVisit ( const SpecificNumArithIterator<ModOperation, TypeConstants::XS_DECIMAL>& );
    void endVisit ( const SpecificNumArithIterator<ModOperation, TypeConstants::XS_INTEGER>& );
    void endVisit ( const SpecificNumArithIterator<ModOperation, TypeConstants::XS_FLOAT>& );
    void endVisit ( const SpecificNumArithIterator<ModOperation, TypeConstants::XS_DOUBLE>& );
    void beginVisit ( const FnMinMaxIterator& a);
    void endVisit   ( const FnMinMaxIterator& );
    void beginVisit(const ForVarIterator& a);
    void endVisit  (const ForVarIterator& );
    void beginVisit(const LetVarIterator& a);
    void endVisit  (const LetVarIterator& );
    void beginVisitFlworWhereClause(const PlanIterator& a);
    void endVisitFlworWhereClause (const PlanIterator& );
    void beginVisitFlworLetVariable(bool materialize,const xqpStringStore_t varName,const std::vector<LetVarIter_t>& varRefs);
    void endVisitFlworLetVariable();
    void beginVisitFlworForVariable(const xqpStringStore_t varName, const std::vector<ForVarIter_t>& varRefs,const std::vector<ForVarIter_t>& posRefs);
    void endVisitFlworForVariable  ();
    void beginVisitGroupByClause();
    void endVisitGroupByClause  ();
    void beginVisitGroupBySpec();
    void endVisitGroupBySpec  ();
    void beginVisitGroupByOuter();
    void endVisitGroupByOuter  ();
    void beginVisitGroupVariable(const std::vector<ForVarIter_t>& varRefs);
    void endVisitGroupVariable  ();
    void beginVisitNonGroupVariable(const std::vector<LetVarIter_t>& varRefs);
    void endVisitNonGroupVariable  ();
    void beginVisitOrderBy(const PlanIterator& a);
    void endVisitOrderBy  (const PlanIterator& );
    void beginVisitOrderByForVariable(ForVarIter_t inputVar,const std::vector<ForVarIter_t>& varRefs);
    void endVisitOrderByForVariable ();
    void beginVisitOrderByLetVariable(LetVarIter_t inputVar,const std::vector<LetVarIter_t>& varRefs);
    void endVisitOrderByLetVariable();
    void beginVisitWindowVariable(const std::string& varName,const std::vector<LetVarIter_t>& varRefs);
    void endVisitWindowVariable();
    void beginVisitWinCondVariable(const std::string& varName,const std::vector<ForVarIter_t>& varRefs);
    void endVisitWinCondVariable();
    void beginVisitFlworReturn(const PlanIterator& a);
    void endVisitFlworReturn  (const PlanIterator& );
    void beginVisit(const CastIterator& a);
    void endVisit  (const CastIterator&);
    void beginVisit(const PromoteIterator& a);
    void endVisit  (const PromoteIterator& );
    void beginVisit(const CastableIterator& a);
    void endVisit  (const CastableIterator& );
    void beginVisit ( const TypedValueCompareIterator<TypeConstants::XS_DECIMAL>& a);
    void beginVisit ( const TypedValueCompareIterator<TypeConstants::XS_INTEGER>& a);
    void beginVisit ( const TypedValueCompareIterator<TypeConstants::XS_DOUBLE>& a);
    void beginVisit ( const TypedValueCompareIterator<TypeConstants::XS_FLOAT>& a);
    void beginVisit ( const TypedValueCompareIterator<TypeConstants::XS_STRING>& a);
    void endVisit ( const TypedValueCompareIterator<TypeConstants::XS_DECIMAL>& a);
    void endVisit ( const TypedValueCompareIterator<TypeConstants::XS_INTEGER>& a);
    void endVisit ( const TypedValueCompareIterator<TypeConstants::XS_DOUBLE>& a);
    void endVisit ( const TypedValueCompareIterator<TypeConstants::XS_FLOAT>& a);
    void endVisit ( const TypedValueCompareIterator<TypeConstants::XS_STRING>& a);

  DECLARE_VISITOR (NodeReferenceIterator)
  DECLARE_VISITOR (NodeByReferenceIterator)
  DECLARE_VISITOR (FnDataIterator)
  DECLARE_VISITOR (SequentialIterator)
  DECLARE_VISITOR (FlowCtlIterator)
  DECLARE_VISITOR (LoopIterator)
  DECLARE_VISITOR (FnRootIterator)
  DECLARE_VISITOR (FnNodeNameIterator)
  DECLARE_VISITOR (FnNilledIterator)
  DECLARE_VISITOR (FnBaseUriIterator)
  DECLARE_VISITOR (FnDocumentUriIterator)
  DECLARE_VISITOR (FnErrorIterator)
  DECLARE_VISITOR (FnResolveUriIterator)
  DECLARE_VISITOR (UDFunctionCallIterator)
  DECLARE_VISITOR (StatelessExtFunctionCallIterator)
  DECLARE_VISITOR (FnStringIterator)
  DECLARE_VISITOR (FnLocalNameIterator)
  DECLARE_VISITOR (FnNamespaceUriIterator)
  DECLARE_VISITOR (FnLangIterator)
  DECLARE_VISITOR (FnCollectionIterator)
  DECLARE_VISITOR (FnBooleanIterator)
  DECLARE_VISITOR (LogicIterator)
  DECLARE_VISITOR (CompareIterator)
  DECLARE_VISITOR (ElementIterator)
  DECLARE_VISITOR (AttributeIterator)
  DECLARE_VISITOR (DocumentIterator)
  DECLARE_VISITOR (DocumentContentIterator)
  DECLARE_VISITOR (CommentIterator)
  DECLARE_VISITOR (PiIterator)
  DECLARE_VISITOR (EmptyIterator)
  DECLARE_VISITOR (IfThenElseIterator)
  DECLARE_VISITOR (NodeDistinctIterator)
  DECLARE_VISITOR (InstanceOfIterator)
  DECLARE_VISITOR (EitherNodesOrAtomicsIterator)
  DECLARE_VISITOR (OpNumericUnaryIterator)
  DECLARE_VISITOR (FnAbsIterator)
  DECLARE_VISITOR (FnCeilingIterator)
  DECLARE_VISITOR (FnFloorIterator)
  DECLARE_VISITOR (FnRoundIterator)
  DECLARE_VISITOR (FnSQRTIterator)
  DECLARE_VISITOR (FnExpIterator)
  DECLARE_VISITOR (FnLogIterator)
  DECLARE_VISITOR (FnSinIterator)
  DECLARE_VISITOR (FnCosIterator)
  DECLARE_VISITOR (FnTanIterator)
  DECLARE_VISITOR (FnArcSinIterator)
  DECLARE_VISITOR (FnArcCosIterator)
  DECLARE_VISITOR (FnArcTanIterator)
  DECLARE_VISITOR (FnRoundHalfToEvenIterator)
  DECLARE_VISITOR (FnIdIterator)
  DECLARE_VISITOR (FnIdRefIterator)
  DECLARE_VISITOR (FnDistinctValuesIterator)
  DECLARE_VISITOR (FnTraceIterator)
  DECLARE_VISITOR (FnReadStringIterator)
  DECLARE_VISITOR (FnPrintIterator)
  DECLARE_VISITOR (ResolveQNameIterator)
  DECLARE_VISITOR (QNameIterator)
  DECLARE_VISITOR (QNameEqualIterator)
  DECLARE_VISITOR (PrefixFromQNameIterator)
  DECLARE_VISITOR (LocalNameFromQNameIterator)
  DECLARE_VISITOR (NamespaceUriFromQNameIterator)
  DECLARE_VISITOR (NamespaceUriForPrefixIterator)
  DECLARE_VISITOR (InScopePrefixesIterator)
  DECLARE_VISITOR (CodepointsToStringIterator)
  DECLARE_VISITOR (StringToCodepointsIterator)
  DECLARE_VISITOR (CompareStrIterator)
  DECLARE_VISITOR (CodepointEqualIterator)
  DECLARE_VISITOR (ConcatStrIterator)
  DECLARE_VISITOR (StringJoinIterator)
  DECLARE_VISITOR (SubstringIterator)
  DECLARE_VISITOR (StringLengthIterator)
  DECLARE_VISITOR (NormalizeSpaceIterator)
  DECLARE_VISITOR (NormalizeUnicodeIterator)
  DECLARE_VISITOR (UpperCaseIterator)
  DECLARE_VISITOR (LowerCaseIterator)
  DECLARE_VISITOR (TranslateIterator)
  DECLARE_VISITOR (EncodeForUriIterator)
  DECLARE_VISITOR (IriToUriIterator)
  DECLARE_VISITOR (EscapeHtmlUriIterator)
  DECLARE_VISITOR (ContainsIterator)
  DECLARE_VISITOR (StartsWithIterator)
  DECLARE_VISITOR (EndsWithIterator)
  DECLARE_VISITOR (SubstringBeforeIterator)
  DECLARE_VISITOR (SubstringAfterIterator)
  DECLARE_VISITOR (FnMatchesIterator)
  DECLARE_VISITOR (FnReplaceIterator)
  DECLARE_VISITOR (FnTokenizeIterator)
  DECLARE_VISITOR (ZorNumGen)
  DECLARE_VISITOR (TextIterator)
  DECLARE_VISITOR (FnDateTimeConstructorIterator)
  DECLARE_VISITOR (FnYearsFromDurationIterator)
  DECLARE_VISITOR (FnMonthsFromDurationIterator)
  DECLARE_VISITOR (FnDaysFromDurationIterator)
  DECLARE_VISITOR (FnHoursFromDurationIterator)
  DECLARE_VISITOR (FnMinutesFromDurationIterator)
  DECLARE_VISITOR (FnSecondsFromDurationIterator)
  DECLARE_VISITOR (FnYearFromDatetimeIterator)
  DECLARE_VISITOR (FnMonthFromDatetimeIterator)
  DECLARE_VISITOR (FnDayFromDatetimeIterator)
  DECLARE_VISITOR (FnHoursFromDatetimeIterator)
  DECLARE_VISITOR (FnMinutesFromDatetimeIterator)
  DECLARE_VISITOR (FnSecondsFromDatetimeIterator)
  DECLARE_VISITOR (FnTimezoneFromDatetimeIterator)
  DECLARE_VISITOR (FnYearFromDateIterator)
  DECLARE_VISITOR (FnMonthFromDateIterator)
  DECLARE_VISITOR (FnDayFromDateIterator)
  DECLARE_VISITOR (FnTimezoneFromDateIterator)
  DECLARE_VISITOR (FnHoursFromTimeIterator)
  DECLARE_VISITOR (FnMinutesFromTimeIterator)
  DECLARE_VISITOR (FnSecondsFromTimeIterator)
  DECLARE_VISITOR (FnTimezoneFromTimeIterator)
  DECLARE_VISITOR (CreateTupleIterator)
  DECLARE_VISITOR (GetTupleFieldIterator)
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
  DECLARE_VISITOR (CtxVariableIterator)
  DECLARE_VISITOR (CtxVarDeclIterator)
  DECLARE_VISITOR (CtxVarAssignIterator)
  DECLARE_VISITOR (CtxVarExistsIterator)
  DECLARE_VISITOR (EvalIterator)
  DECLARE_VISITOR (OpIsSameNodeIterator)
  DECLARE_VISITOR (OpNodeBeforeIterator)
  DECLARE_VISITOR (OpNodeAfterIterator)
  DECLARE_VISITOR (FnCurrentDateTimeIterator)
  DECLARE_VISITOR (FnCurrentDateIterator)
  DECLARE_VISITOR (FnCurrentTimeIterator)
  DECLARE_VISITOR (FnImplicitTimezoneIterator)
  DECLARE_VISITOR (FnDefaultCollationIterator)
  DECLARE_VISITOR (FnAdjustToTimeZoneIterator_1);
  DECLARE_VISITOR (FnAdjustToTimeZoneIterator_2);
  DECLARE_VISITOR (FnFormatDateTimeIterator);
  DECLARE_VISITOR (InsertIterator);
  DECLARE_VISITOR (DeleteIterator);
  DECLARE_VISITOR (ReplaceIterator);
  DECLARE_VISITOR (RenameIterator);
  DECLARE_VISITOR (TransformIterator);
  DECLARE_VISITOR (ApplyIterator);
  DECLARE_VISITOR (FnFormatNumberIterator);
  DECLARE_VISITOR (ZorbaCollectionExistsIterator);
  DECLARE_VISITOR (ZorbaImportXmlIterator);
  DECLARE_VISITOR (ZorbaImportCatalogIterator);
  DECLARE_VISITOR (ZorbaImportFolderIterator);
  DECLARE_VISITOR (ZorbaListCollectionsIterator);
  DECLARE_VISITOR (ZorbaCreateCollectionIterator);
  DECLARE_VISITOR (ZorbaDeleteCollectionIterator);
  DECLARE_VISITOR (ZorbaDeleteAllCollectionsIterator);
  DECLARE_VISITOR (ZorbaInsertNodeFirstIterator);
  DECLARE_VISITOR (ZorbaInsertNodeLastIterator);
  DECLARE_VISITOR (ZorbaInsertNodeBeforeIterator);
  DECLARE_VISITOR (ZorbaInsertNodeAfterIterator);
  DECLARE_VISITOR (ZorbaInsertNodeAtIterator);
  DECLARE_VISITOR (ZorbaRemoveNodeIterator);
  DECLARE_VISITOR (ZorbaRemoveNodeAtIterator);
  DECLARE_VISITOR (ZorbaNodeCountIterator);
  DECLARE_VISITOR (ZorbaNodeAtIterator);
  DECLARE_VISITOR (ZorbaIndexOfIterator);
  DECLARE_VISITOR (ZorbaExportXmlIterator);
  DECLARE_VISITOR (CreateInternalIndexIterator);
  DECLARE_VISITOR (CreateIndexIterator);
  DECLARE_VISITOR (RefreshIndexIterator);
  DECLARE_VISITOR (DropIndexIterator);
  DECLARE_VISITOR (IndexEntryBuilderIterator);
  DECLARE_VISITOR (IndexPointProbeIterator);
  DECLARE_VISITOR (IndexRangeProbeIterator);
  DECLARE_VISITOR (ZorbaSchemaTypeIterator);
  DECLARE_VISITOR (ZorbaBase64EncodeIterator);
  DECLARE_VISITOR (ZorbaBase64DecodeIterator);
  DECLARE_VISITOR (XQDocIterator);
  DECLARE_VISITOR (ZorbaTimestampIterator);
  DECLARE_VISITOR (ZorbaDebugIterator);
  DECLARE_VISITOR (DebuggerSingletonIterator);
  DECLARE_VISITOR (HoistIterator);
  DECLARE_VISITOR (UnhoistIterator);
  DECLARE_VISITOR (ZorbaJsonParseIterator);
  DECLARE_VISITOR (ZorbaJsonSerializeIterator);
  DECLARE_VISITOR (ZorbaJsonMLParseIterator);
  DECLARE_VISITOR (ZorbaJsonMLSerializeIterator);

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

#ifndef ZORBA_NO_XMLSCHEMA
  DECLARE_VISITOR (ValidateIterator)
#endif
#ifdef ZORBA_WITH_TIDY
  DECLARE_VISITOR (ZorbaTidyIterator);
  DECLARE_VISITOR (ZorbaTDocIterator);
#endif  // ZORBA_WITH_TIDY
  DECLARE_VISITOR (ZorbaRandomIterator);
  DECLARE_VISITOR (ZorbaUUIDIterator);
#ifdef ZORBA_WITH_EMAIL
  DECLARE_VISITOR (ZorbaMailIterator);
#endif  // ZORBA_WITH_EMAIL

#ifdef ZORBA_WITH_REST
  DECLARE_VISITOR (ZorbaRestGetIterator);
  DECLARE_VISITOR (ZorbaRestPostIterator);
  DECLARE_VISITOR (ZorbaRestPutIterator);
  DECLARE_VISITOR (ZorbaRestDeleteIterator);
  DECLARE_VISITOR (ZorbaRestHeadIterator);
#endif

#ifdef ZORBA_WITH_FOP
  DECLARE_VISITOR (ZorbaFopIterator);
#endif // ZORBA_WITH_FOP
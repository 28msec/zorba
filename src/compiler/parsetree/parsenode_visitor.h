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

#ifndef ZORBA_PARSENODE_VISITOR_H
#define ZORBA_PARSENODE_VISITOR_H

#include "common/shared_types.h"

// Any file that includes parsenode_visitor.h will need to access the
// actual parsendoe classes.
#include "compiler/parsetree/parsenodes.h"

namespace zorba 
{

/*______________________________________________________________________
|  
|	 Design note: Visitor pattern.  See, for example:
|	 "Modern C++ Design" by Andrei Alexandrescu, Addison Wesley (2001),
|	 Chapter 10.
|_______________________________________________________________________*/

class parsenode_visitor
{
public:	
	virtual ~parsenode_visitor() {}

public:

  static void *no_state;

#define DECL_PARSENODE_VISIT_METHODS( node )                  \
  virtual void *begin_visit (node const &) = 0;               \
	virtual void end_visit(node const&, void *visit_state) = 0;
  
 /*..........................................
 	:  begin visit                            :
 	:.........................................*/
	DECL_PARSENODE_VISIT_METHODS (AbbrevForwardStep);
	DECL_PARSENODE_VISIT_METHODS (AnyKindTest);
	DECL_PARSENODE_VISIT_METHODS (AposAttrContentList);
	DECL_PARSENODE_VISIT_METHODS (AposAttrValueContent);
	DECL_PARSENODE_VISIT_METHODS (ArgList);
	DECL_PARSENODE_VISIT_METHODS (AtomicType);
	DECL_PARSENODE_VISIT_METHODS (AttributeTest);
	DECL_PARSENODE_VISIT_METHODS (BaseURIDecl);
	DECL_PARSENODE_VISIT_METHODS (BoundarySpaceDecl);
	DECL_PARSENODE_VISIT_METHODS (CaseClause);
	DECL_PARSENODE_VISIT_METHODS (CaseClauseList);
	DECL_PARSENODE_VISIT_METHODS (CommentTest);
	DECL_PARSENODE_VISIT_METHODS (ConstructionDecl);
	DECL_PARSENODE_VISIT_METHODS (CopyNamespacesDecl);
	DECL_PARSENODE_VISIT_METHODS (DefaultCollationDecl);
	DECL_PARSENODE_VISIT_METHODS (DefaultNamespaceDecl);
	DECL_PARSENODE_VISIT_METHODS (DirAttr);
	DECL_PARSENODE_VISIT_METHODS (DirAttributeList);
	DECL_PARSENODE_VISIT_METHODS (DirAttributeValue);
	DECL_PARSENODE_VISIT_METHODS (DirElemContentList);
	DECL_PARSENODE_VISIT_METHODS (DocumentTest);
	DECL_PARSENODE_VISIT_METHODS (ElementTest);
	DECL_PARSENODE_VISIT_METHODS (EmptyOrderDecl);
	DECL_PARSENODE_VISIT_METHODS (ForClause);
	DECL_PARSENODE_VISIT_METHODS (FLWORClauseList);
	DECL_PARSENODE_VISIT_METHODS (ForwardAxis);
	DECL_PARSENODE_VISIT_METHODS (ForwardStep);
	DECL_PARSENODE_VISIT_METHODS (FunctionDecl);
	DECL_PARSENODE_VISIT_METHODS (GeneralComp);
	DECL_PARSENODE_VISIT_METHODS (ItemType);
	DECL_PARSENODE_VISIT_METHODS (LetClause);
	DECL_PARSENODE_VISIT_METHODS (LibraryModule);
	DECL_PARSENODE_VISIT_METHODS (MainModule );
	DECL_PARSENODE_VISIT_METHODS (Module);
	DECL_PARSENODE_VISIT_METHODS (ModuleDecl);
	DECL_PARSENODE_VISIT_METHODS (ModuleImport);
	DECL_PARSENODE_VISIT_METHODS (NameTest);
	DECL_PARSENODE_VISIT_METHODS (NamespaceDecl);
	DECL_PARSENODE_VISIT_METHODS (NodeComp);
	DECL_PARSENODE_VISIT_METHODS (OccurrenceIndicator);
	DECL_PARSENODE_VISIT_METHODS (OptionDecl);
  DECL_PARSENODE_VISIT_METHODS (GroupByClause);
  DECL_PARSENODE_VISIT_METHODS (GroupSpecList);
  DECL_PARSENODE_VISIT_METHODS (GroupSpec);
  DECL_PARSENODE_VISIT_METHODS (GroupCollationSpec);
	DECL_PARSENODE_VISIT_METHODS (OrderByClause);
	DECL_PARSENODE_VISIT_METHODS (OrderCollationSpec);
	DECL_PARSENODE_VISIT_METHODS (OrderDirSpec);
	DECL_PARSENODE_VISIT_METHODS (OrderEmptySpec);
	DECL_PARSENODE_VISIT_METHODS (OrderModifier);
	DECL_PARSENODE_VISIT_METHODS (OrderSpec);
	DECL_PARSENODE_VISIT_METHODS (OrderSpecList);
	DECL_PARSENODE_VISIT_METHODS (OrderingModeDecl);
	DECL_PARSENODE_VISIT_METHODS (PITest);
	DECL_PARSENODE_VISIT_METHODS (Param);
	DECL_PARSENODE_VISIT_METHODS (ParamList);
	DECL_PARSENODE_VISIT_METHODS (PositionalVar);
	DECL_PARSENODE_VISIT_METHODS (Pragma);
	DECL_PARSENODE_VISIT_METHODS (PragmaList);
	DECL_PARSENODE_VISIT_METHODS (PredicateList);
	DECL_PARSENODE_VISIT_METHODS (Prolog);
	DECL_PARSENODE_VISIT_METHODS (QVarInDecl);
	DECL_PARSENODE_VISIT_METHODS (QVarInDeclList);
	DECL_PARSENODE_VISIT_METHODS (QuoteAttrValueContent);
	DECL_PARSENODE_VISIT_METHODS (QuoteAttrContentList);
	DECL_PARSENODE_VISIT_METHODS (ReverseAxis);
	DECL_PARSENODE_VISIT_METHODS (ReverseStep);
	DECL_PARSENODE_VISIT_METHODS (SIND_DeclList);
	DECL_PARSENODE_VISIT_METHODS (SchemaAttributeTest);
	DECL_PARSENODE_VISIT_METHODS (SchemaElementTest);
	DECL_PARSENODE_VISIT_METHODS (SchemaImport);
	DECL_PARSENODE_VISIT_METHODS (SchemaPrefix);
	DECL_PARSENODE_VISIT_METHODS (SequenceType);
	DECL_PARSENODE_VISIT_METHODS (SignList);
	DECL_PARSENODE_VISIT_METHODS (SingleType);
	DECL_PARSENODE_VISIT_METHODS (TextTest);
	DECL_PARSENODE_VISIT_METHODS (TypeName);
	DECL_PARSENODE_VISIT_METHODS (URILiteralList);
	DECL_PARSENODE_VISIT_METHODS (ValueComp);
	DECL_PARSENODE_VISIT_METHODS (CtxItemDecl);
	DECL_PARSENODE_VISIT_METHODS (IndexDecl);
	DECL_PARSENODE_VISIT_METHODS (IndexKeySpec);
	DECL_PARSENODE_VISIT_METHODS (IndexKeyList);
	DECL_PARSENODE_VISIT_METHODS (VarDecl);
	DECL_PARSENODE_VISIT_METHODS (VarGetsDecl);
	DECL_PARSENODE_VISIT_METHODS (VarGetsDeclList);
	DECL_PARSENODE_VISIT_METHODS (VarInDecl);
	DECL_PARSENODE_VISIT_METHODS (VarInDeclList);
	DECL_PARSENODE_VISIT_METHODS (VersionDecl);
	DECL_PARSENODE_VISIT_METHODS (VFO_DeclList);
	DECL_PARSENODE_VISIT_METHODS (WhereClause);
	DECL_PARSENODE_VISIT_METHODS (CountClause);
	DECL_PARSENODE_VISIT_METHODS (Wildcard);
  DECL_PARSENODE_VISIT_METHODS (QName);
  DECL_PARSENODE_VISIT_METHODS (DecimalFormatNode);

/* expressions */
	DECL_PARSENODE_VISIT_METHODS (AdditiveExpr);
	DECL_PARSENODE_VISIT_METHODS (AndExpr);
	DECL_PARSENODE_VISIT_METHODS (AxisStep);
	DECL_PARSENODE_VISIT_METHODS (CDataSection);
	DECL_PARSENODE_VISIT_METHODS (CastExpr);
	DECL_PARSENODE_VISIT_METHODS (CastableExpr);
	DECL_PARSENODE_VISIT_METHODS (CommonContent);
	DECL_PARSENODE_VISIT_METHODS (ComparisonExpr);
	DECL_PARSENODE_VISIT_METHODS (CompAttrConstructor);
	DECL_PARSENODE_VISIT_METHODS (CompCommentConstructor);
	DECL_PARSENODE_VISIT_METHODS (CompDocConstructor);
	DECL_PARSENODE_VISIT_METHODS (CompElemConstructor);
	DECL_PARSENODE_VISIT_METHODS (CompPIConstructor);
	DECL_PARSENODE_VISIT_METHODS (CompTextConstructor);
	DECL_PARSENODE_VISIT_METHODS (ContextItemExpr);
	DECL_PARSENODE_VISIT_METHODS (DirCommentConstructor);
	DECL_PARSENODE_VISIT_METHODS (DirElemConstructor);
	DECL_PARSENODE_VISIT_METHODS (DirElemContent);
	DECL_PARSENODE_VISIT_METHODS (DirPIConstructor);
	DECL_PARSENODE_VISIT_METHODS (EnclosedExpr);
	DECL_PARSENODE_VISIT_METHODS (BlockBody);
	DECL_PARSENODE_VISIT_METHODS (Expr);
	DECL_PARSENODE_VISIT_METHODS (ExtensionExpr);
	DECL_PARSENODE_VISIT_METHODS (FLWORExpr);
	DECL_PARSENODE_VISIT_METHODS (WindowClause);
	DECL_PARSENODE_VISIT_METHODS (WindowVarDecl);
	DECL_PARSENODE_VISIT_METHODS (FLWORWinCond);
	DECL_PARSENODE_VISIT_METHODS (WindowVars);
	DECL_PARSENODE_VISIT_METHODS (FilterExpr);
	DECL_PARSENODE_VISIT_METHODS (FunctionCall);
	DECL_PARSENODE_VISIT_METHODS (IfExpr);
	DECL_PARSENODE_VISIT_METHODS (InstanceofExpr);
	DECL_PARSENODE_VISIT_METHODS (IntersectExceptExpr);
	DECL_PARSENODE_VISIT_METHODS (MultiplicativeExpr);
	DECL_PARSENODE_VISIT_METHODS (NumericLiteral);
	DECL_PARSENODE_VISIT_METHODS (OrExpr);
	DECL_PARSENODE_VISIT_METHODS (OrderedExpr);
	DECL_PARSENODE_VISIT_METHODS (ParenthesizedExpr);
	DECL_PARSENODE_VISIT_METHODS (PathExpr);
	DECL_PARSENODE_VISIT_METHODS (QuantifiedExpr);
	DECL_PARSENODE_VISIT_METHODS (QueryBody);
	DECL_PARSENODE_VISIT_METHODS (RangeExpr);
	DECL_PARSENODE_VISIT_METHODS (RelativePathExpr);
	DECL_PARSENODE_VISIT_METHODS (StringLiteral);
	DECL_PARSENODE_VISIT_METHODS (TreatExpr);
	DECL_PARSENODE_VISIT_METHODS (TypeswitchExpr);
	DECL_PARSENODE_VISIT_METHODS (UnaryExpr);
	DECL_PARSENODE_VISIT_METHODS (UnionExpr);
	DECL_PARSENODE_VISIT_METHODS (UnorderedExpr);
	DECL_PARSENODE_VISIT_METHODS (ValidateExpr);
	DECL_PARSENODE_VISIT_METHODS (VarRef);

/* update-related */
	DECL_PARSENODE_VISIT_METHODS (DeleteExpr);
	DECL_PARSENODE_VISIT_METHODS (InsertExpr);
	DECL_PARSENODE_VISIT_METHODS (RenameExpr);
	DECL_PARSENODE_VISIT_METHODS (ReplaceExpr);
	DECL_PARSENODE_VISIT_METHODS (RevalidationDecl);
	DECL_PARSENODE_VISIT_METHODS (TransformExpr);
	DECL_PARSENODE_VISIT_METHODS (CopyVarList);
  DECL_PARSENODE_VISIT_METHODS (VarBinding);

/* try-catch-related */
  DECL_PARSENODE_VISIT_METHODS (TryExpr);
  DECL_PARSENODE_VISIT_METHODS (CatchListExpr);
  DECL_PARSENODE_VISIT_METHODS (CatchExpr);

  // eval
  DECL_PARSENODE_VISIT_METHODS (EvalExpr);

/* full-text-related */
	DECL_PARSENODE_VISIT_METHODS (FTAnd);
	DECL_PARSENODE_VISIT_METHODS (FTAnyallOption);
	DECL_PARSENODE_VISIT_METHODS (FTBigUnit);
	DECL_PARSENODE_VISIT_METHODS (FTCaseOption);
	DECL_PARSENODE_VISIT_METHODS (FTContainsExpr);
	DECL_PARSENODE_VISIT_METHODS (FTContent);
	DECL_PARSENODE_VISIT_METHODS (FTDiacriticsOption);
	DECL_PARSENODE_VISIT_METHODS (FTDistance);
	DECL_PARSENODE_VISIT_METHODS (FTIgnoreOption);
	DECL_PARSENODE_VISIT_METHODS (FTInclExclStringLiteral);
	DECL_PARSENODE_VISIT_METHODS (FTInclExclStringLiteralList);
	DECL_PARSENODE_VISIT_METHODS (FTLanguageOption);
	DECL_PARSENODE_VISIT_METHODS (FTMatchOption);
	DECL_PARSENODE_VISIT_METHODS (FTMatchOptionProximityList);
	DECL_PARSENODE_VISIT_METHODS (FTMildnot);
	DECL_PARSENODE_VISIT_METHODS (FTOptionDecl);
	DECL_PARSENODE_VISIT_METHODS (FTOr);
	DECL_PARSENODE_VISIT_METHODS (FTOrderedIndicator);
	DECL_PARSENODE_VISIT_METHODS (FTProximity);
	DECL_PARSENODE_VISIT_METHODS (FTRange);
	DECL_PARSENODE_VISIT_METHODS (FTRefOrList);
	DECL_PARSENODE_VISIT_METHODS (FTScope);
	DECL_PARSENODE_VISIT_METHODS (FTScoreVar);
	DECL_PARSENODE_VISIT_METHODS (FTSelection);
	DECL_PARSENODE_VISIT_METHODS (FTStemOption);
	DECL_PARSENODE_VISIT_METHODS (FTStopwordOption);
	DECL_PARSENODE_VISIT_METHODS (FTStringLiteralList);
	DECL_PARSENODE_VISIT_METHODS (FTThesaurusID);
	DECL_PARSENODE_VISIT_METHODS (FTThesaurusList);
	DECL_PARSENODE_VISIT_METHODS (FTThesaurusOption);
	DECL_PARSENODE_VISIT_METHODS (FTTimes);
	DECL_PARSENODE_VISIT_METHODS (FTUnaryNot);
	DECL_PARSENODE_VISIT_METHODS (FTUnit);
	DECL_PARSENODE_VISIT_METHODS (FTWildcardOption);
	DECL_PARSENODE_VISIT_METHODS (FTWindow);
	DECL_PARSENODE_VISIT_METHODS (FTWords);
	DECL_PARSENODE_VISIT_METHODS (FTWordsSelection);
	DECL_PARSENODE_VISIT_METHODS (FTWordsValue);
	DECL_PARSENODE_VISIT_METHODS (FTMatchOptionProximity);

  DECL_PARSENODE_VISIT_METHODS (AssignExpr);
  DECL_PARSENODE_VISIT_METHODS (ExitExpr);
  DECL_PARSENODE_VISIT_METHODS (WhileExpr);
  DECL_PARSENODE_VISIT_METHODS (FlowCtlStatement);

  DECL_PARSENODE_VISIT_METHODS (ParseErrorNode);

    /* Methods that deviate from the visitor pattern that are
     * needed in various situations.
     */

	virtual void intermediate_visit(RelativePathExpr const&, void* /*visit_state*/) { }
  virtual void post_primary_visit(FilterExpr const&, void * /*visit_state*/) { }
  virtual void post_axis_visit(AxisStep const&, void * /*visit_state*/) { }
  virtual void pre_predicate_visit(PredicateList const&, void* /*visit_state*/) { }
  virtual void post_predicate_visit(PredicateList const&, void* /*visit_state*/) { }

  virtual void intermediate_visit(WindowClause const&, void* /*visit_state*/) { }

  /**
   * Methods are used in the translator to check if a DirElemContent is boundary whitespace.
   */
  virtual void begin_check_boundary_whitespace() {}
  virtual void check_boundary_whitespace(const DirElemContent&) {}
  virtual void end_check_boundary_whitespace() {}

  virtual bool is_root_rpe(const RelativePathExpr*) { return true; }

#undef DECL_PARSENODE_VISIT_METHODS

};

} /* namespace zorba */
#endif /* ZORBA_PARSENODE_VISITOR_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */

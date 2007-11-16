/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: translator.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_NORMALIZE_VISITOR_H
#define XQP_NORMALIZE_VISITOR_H

#include "compiler/parsetree/parsenode_visitor.h"
#include "compiler/expression/expr.h"
// #include "store/data_manager.h"

#include <stack>

/*______________________________________________________________________
|  
|	 Design note: Visitor pattern.  See, for example:
|	 "Modern C++ Design" by Andrei Alexandrescu, Addison Wesley (2001),
|	 Chapter 10.
|_______________________________________________________________________*/

namespace xqp {

class zorba;

class translator : public parsenode_visitor
{
public:
	typedef rchandle<expr> expr_t;

protected:
	zorba* zorp;
  static_context *sctx_p;
//daniel	dynamic_context* dctx_p;
// 	rchandle<data_manager> dmgr_h;

	std::stack<expr_t> nodestack;
// 	std::stack<expr_t> argstack;
	std::stack<expr_t> pstack;	// predicates stack

public:
	translator();
	~translator() {}

public:
	expr_t pop_nodestack()
	{
		Assert (! nodestack.empty());
		rchandle<expr> e_h = nodestack.top();
		nodestack.pop();
		return e_h;
	}
// 	void clear_argstack()
// 	{
// 		while (!argstack.empty()) argstack.pop();
// 	}
	void clear_pstack()
	{
		while (!pstack.empty()) pstack.pop();
	}

  void push_scope ()
  { sctx_p = new static_context (sctx_p); }
  void pop_scope (int n = 1)
  { 
    while (n-- > 0) {
      static_context *parent = (static_context *) sctx_p->get_parent ();
      delete sctx_p;
      sctx_p = parent;
    }
  }


public:

 /*..........................................
 	:  begin visit                            :
 	:.........................................*/
	void *begin_visit(parsenode const&);
	void *begin_visit(AbbrevForwardStep const&);
	void *begin_visit(AnyKindTest const&);
	void *begin_visit(AposAttrContentList const&);
	void *begin_visit(AposAttrValueContent const&);
	void *begin_visit(ArgList const&);
	void *begin_visit(AtomicType const&);
	void *begin_visit(AttributeTest const&);
	void *begin_visit(BaseURIDecl const&);
	void *begin_visit(BoundarySpaceDecl const&);
	void *begin_visit(CaseClause const&);
	void *begin_visit(CaseClauseList const&);
	void *begin_visit(CommentTest const&);
	void *begin_visit(ConstructionDecl const&);
	void *begin_visit(CopyNamespacesDecl const&);
	void *begin_visit(DefaultCollationDecl const&);
	void *begin_visit(DefaultNamespaceDecl const&);
	void *begin_visit(DirAttr const&);
	void *begin_visit(DirAttributeList const&);
	void *begin_visit(DirAttributeValue const&);
	void *begin_visit(DirElemContentList const&);
	void *begin_visit(DocumentTest const&);
	void *begin_visit(ElementTest const&);
	void *begin_visit(EmptyOrderDecl const&);
	void *begin_visit(ForClause const&);
	void *begin_visit(ForLetClauseList const&);
	void *begin_visit(ForwardAxis const&);
	void *begin_visit(ForwardStep const&);
	void *begin_visit(FunctionDecl const&);
	void *begin_visit(GeneralComp const&);
	void *begin_visit(ItemType const&);
	void *begin_visit(LetClause const&);
	void *begin_visit(LibraryModule const&);
	void *begin_visit(MainModule  const&);
	void *begin_visit(Module const&);
	void *begin_visit(ModuleDecl const&);
	void *begin_visit(ModuleImport const&);
	void *begin_visit(NameTest const&);
	void *begin_visit(NamespaceDecl const&);
	void *begin_visit(NodeComp const&);
	void *begin_visit(OccurrenceIndicator const&);
	void *begin_visit(OptionDecl const&);
	void *begin_visit(OrderByClause const&);
	void *begin_visit(OrderCollationSpec const&);
	void *begin_visit(OrderDirSpec const&);
	void *begin_visit(OrderEmptySpec const&);
	void *begin_visit(OrderModifier const&);
	void *begin_visit(OrderSpec const&);
	void *begin_visit(OrderSpecList const&);
	void *begin_visit(OrderingModeDecl const&);
	void *begin_visit(PITest const&);
	void *begin_visit(Param const&);
	void *begin_visit(ParamList const&);
	void *begin_visit(PositionalVar const&);
	void *begin_visit(Pragma const&);
	void *begin_visit(PragmaList const&);
	void *begin_visit(PredicateList const&);
	void *begin_visit(Prolog const&);
	void *begin_visit(QVarInDecl const&);
	void *begin_visit(QVarInDeclList const&);
	void *begin_visit(QuoteAttrValueContent const&);
	void *begin_visit(QuoteAttrContentList const&);
	void *begin_visit(ReverseAxis const&);
	void *begin_visit(ReverseStep const&);
	void *begin_visit(SIND_DeclList const&);
	void *begin_visit(SchemaAttributeTest const&);
	void *begin_visit(SchemaElementTest const&);
	void *begin_visit(SchemaImport const&);
	void *begin_visit(SchemaPrefix const&);
	void *begin_visit(SequenceType const&);
	void *begin_visit(SignList const&);
	void *begin_visit(SingleType const&);
	void *begin_visit(TextTest const&);
	void *begin_visit(TypeDeclaration const&);
	void *begin_visit(TypeName const&);
	void *begin_visit(URILiteralList const&);
	void *begin_visit(ValueComp const&);
	void *begin_visit(VarDecl const&);
	void *begin_visit(VarGetsDecl const&);
	void *begin_visit(VarGetsDeclList const&);
	void *begin_visit(VarInDecl const&);
	void *begin_visit(VarInDeclList const&);
	void *begin_visit(VersionDecl const&);
	void *begin_visit(VFO_DeclList const&);
	void *begin_visit(WhereClause const&);
	void *begin_visit(Wildcard const&);

	void *begin_visit(exprnode const&);
	void *begin_visit(AdditiveExpr const&);
	void *begin_visit(AndExpr const&);
	void *begin_visit(AxisStep const&);
	void *begin_visit(CDataSection const&);
	void *begin_visit(CastExpr const&);
	void *begin_visit(CastableExpr const&);
	void *begin_visit(CommonContent const&);
	void *begin_visit(ComparisonExpr const&);
	void *begin_visit(CompAttrConstructor const&);
	void *begin_visit(CompCommentConstructor const&);
	void *begin_visit(CompDocConstructor const&);
	void *begin_visit(CompElemConstructor const&);
	void *begin_visit(CompPIConstructor const&);
	void *begin_visit(CompTextConstructor const&);
	void *begin_visit(ContextItemExpr const&);
	void *begin_visit(DirCommentConstructor const&);
	void *begin_visit(DirElemConstructor const&);
	void *begin_visit(DirElemContent const&);
	void *begin_visit(DirPIConstructor const&);
	void *begin_visit(EnclosedExpr const&);
	void *begin_visit(Expr const&);
    // void *begin_visit(ExprSingle const&);
	void *begin_visit(ExtensionExpr const&);
	void *begin_visit(FLWORExpr const&);
	void *begin_visit(FilterExpr const&);
	void *begin_visit(FunctionCall const&);
	void *begin_visit(IfExpr const&);
	void *begin_visit(InstanceofExpr const&);
	void *begin_visit(IntersectExceptExpr const&);
	void *begin_visit(MultiplicativeExpr const&);
	void *begin_visit(NumericLiteral const&);
	void *begin_visit(OrExpr const&);
	void *begin_visit(OrderedExpr const&);
	void *begin_visit(ParenthesizedExpr const&);
	void *begin_visit(PathExpr const&);
	void *begin_visit(QuantifiedExpr const&);
	void *begin_visit(QueryBody const&);
	void *begin_visit(RangeExpr const&);
	void *begin_visit(RelativePathExpr const&);
	void *begin_visit(StringLiteral const&);
	void *begin_visit(TreatExpr const&);
	void *begin_visit(TypeswitchExpr const&);
	void *begin_visit(UnaryExpr const&);
	void *begin_visit(UnionExpr const&);
	void *begin_visit(UnorderedExpr const&);
	void *begin_visit(ValidateExpr const&);
	void *begin_visit(VarRef const&);

/* update-related */
	void *begin_visit(DeleteExpr const&);
	void *begin_visit(InsertExpr const&);
	void *begin_visit(RenameExpr const&);
	void *begin_visit(ReplaceExpr const&);
	void *begin_visit(RevalidationDecl const&);
	void *begin_visit(TransformExpr const&);
	void *begin_visit(VarNameList const&);

/* full-text-related */
	void *begin_visit(FTAnd const&);
	void *begin_visit(FTAnyallOption const&);
	void *begin_visit(FTBigUnit const&);
	void *begin_visit(FTCaseOption const&);
	void *begin_visit(FTContainsExpr const&);
	void *begin_visit(FTContent const&);
	void *begin_visit(FTDiacriticsOption const&);
	void *begin_visit(FTDistance const&);
	void *begin_visit(FTIgnoreOption const&);
	void *begin_visit(FTInclExclStringLiteral const&);
	void *begin_visit(FTInclExclStringLiteralList const&);
	void *begin_visit(FTLanguageOption const&);
	void *begin_visit(FTMatchOption const&);
	void *begin_visit(FTMatchOptionProximityList const&);
	void *begin_visit(FTMildnot const&);
	void *begin_visit(FTOptionDecl const&);
	void *begin_visit(FTOr const&);
	void *begin_visit(FTOrderedIndicator const&);
	void *begin_visit(FTProximity const&);
	void *begin_visit(FTRange const&);
	void *begin_visit(FTRefOrList const&);
	void *begin_visit(FTScope const&);
	void *begin_visit(FTScoreVar const&);
	void *begin_visit(FTSelection const&);
	void *begin_visit(FTStemOption const&);
	void *begin_visit(FTStopwordOption const&);
	void *begin_visit(FTStringLiteralList const&);
	void *begin_visit(FTThesaurusID const&);
	void *begin_visit(FTThesaurusList const&);
	void *begin_visit(FTThesaurusOption const&);
	void *begin_visit(FTTimes const&);
	void *begin_visit(FTUnaryNot const&);
	void *begin_visit(FTUnit const&);
	void *begin_visit(FTWildcardOption const&);
	void *begin_visit(FTWindow const&);
	void *begin_visit(FTWords const&);
	void *begin_visit(FTWordsSelection const&);
	void *begin_visit(FTWordsValue const&);

 /*..........................................
 	:  end visit                              :
 	:.........................................*/
	void end_visit (parsenode const&, void *);
	void end_visit (AbbrevForwardStep const&, void *);
	void end_visit (AnyKindTest const&, void *);
	void end_visit (AposAttrContentList const&, void *);
	void end_visit (AposAttrValueContent const&, void *);
	void end_visit (ArgList const&, void *);
	void end_visit (AtomicType const&, void *);
	void end_visit (AttributeTest const&, void *);
	void end_visit (BaseURIDecl const&, void *);
	void end_visit (BoundarySpaceDecl const&, void *);
	void end_visit (CaseClause const&, void *);
	void end_visit (CaseClauseList const&, void *);
	void end_visit (CommentTest const&, void *);
	void end_visit (ConstructionDecl const&, void *);
	void end_visit (CopyNamespacesDecl const&, void *);
	void end_visit (DefaultCollationDecl const&, void *);
	void end_visit (DefaultNamespaceDecl const&, void *);
	void end_visit (DirAttr const&, void *);
	void end_visit (DirAttributeList const&, void *);
	void end_visit (DirAttributeValue const&, void *);
	void end_visit (DirElemContentList const&, void *);
	void end_visit (DocumentTest const&, void *);
	void end_visit (ElementTest const&, void *);
	void end_visit (EmptyOrderDecl const&, void *);
	void end_visit (ForClause const&, void *);
    // void end_visit (ForLetClause const&, void *);
	void end_visit (ForLetClauseList const&, void *);
	void end_visit (ForwardAxis const&, void *);
	void end_visit (ForwardStep const&, void *);
	void end_visit (FunctionDecl const&, void *);
	void end_visit (GeneralComp const&, void *);
	void end_visit (ItemType const&, void *);
	void end_visit (LetClause const&, void *);
	void end_visit (LibraryModule const&, void *);
	void end_visit (MainModule  const&, void *);
	void end_visit (Module const&, void *);
	void end_visit (ModuleDecl const&, void *);
	void end_visit (ModuleImport const&, void *);
	void end_visit (NameTest const&, void *);
	void end_visit (NamespaceDecl const&, void *);
	void end_visit (NodeComp const&, void *);
	void end_visit (OccurrenceIndicator const&, void *);
	void end_visit (OptionDecl const&, void *);
	void end_visit (OrderByClause const&, void *);
	void end_visit (OrderCollationSpec const&, void *);
	void end_visit (OrderDirSpec const&, void *);
	void end_visit (OrderEmptySpec const&, void *);
	void end_visit (OrderModifier const&, void *);
	void end_visit (OrderSpec const&, void *);
	void end_visit (OrderSpecList const&, void *);
	void end_visit (OrderingModeDecl const&, void *);
	void end_visit (PITest const&, void *);
	void end_visit (Param const&, void *);
	void end_visit (ParamList const&, void *);
	void end_visit (PositionalVar const&, void *);
	void end_visit (Pragma const&, void *);
	void end_visit (PragmaList const&, void *);
	void end_visit (PredicateList const&, void *);
	void end_visit (Prolog const&, void *);
	void end_visit (QVarInDecl const&, void *);
	void end_visit (QVarInDeclList const&, void *);
	void end_visit (QuoteAttrValueContent const&, void *);
	void end_visit (QuoteAttrContentList const&, void *);
	void end_visit (ReverseAxis const&, void *);
	void end_visit (ReverseStep const&, void *);
	void end_visit (SIND_DeclList const&, void *);
	void end_visit (SchemaAttributeTest const&, void *);
	void end_visit (SchemaElementTest const&, void *);
	void end_visit (SchemaImport const&, void *);
	void end_visit (SchemaPrefix const&, void *);
	void end_visit (SequenceType const&, void *);
	void end_visit (SignList const&, void *);
	void end_visit (SingleType const&, void *);
	void end_visit (TextTest const&, void *);
	void end_visit (TypeDeclaration const&, void *);
	void end_visit (TypeName const&, void *);
	void end_visit (URILiteralList const&, void *);
	void end_visit (ValueComp const&, void *);
	void end_visit (VarDecl const&, void *);
	void end_visit (VarGetsDecl const&, void *);
	void end_visit (VarGetsDeclList const&, void *);
	void end_visit (VarInDecl const&, void *);
	void end_visit (VarInDeclList const&, void *);
	void end_visit (VersionDecl const&, void *);
	void end_visit (VFO_DeclList const&, void *);
	void end_visit (WhereClause const&, void *);
	void end_visit (Wildcard const&, void *);

	void end_visit (exprnode const&, void *);
	void end_visit (AdditiveExpr const&, void *);
	void end_visit (AndExpr const&, void *);
	void end_visit (AxisStep const&, void *);
	void end_visit (CDataSection const&, void *);
	void end_visit (CastExpr const&, void *);
	void end_visit (CastableExpr const&, void *);
	void end_visit (CommonContent const&, void *);
	void end_visit (ComparisonExpr const&, void *);
	void end_visit (CompAttrConstructor const&, void *);
	void end_visit (CompCommentConstructor const&, void *);
	void end_visit (CompDocConstructor const&, void *);
	void end_visit (CompElemConstructor const&, void *);
	void end_visit (CompPIConstructor const&, void *);
	void end_visit (CompTextConstructor const&, void *);
	void end_visit (ContextItemExpr const&, void *);
	void end_visit (DirCommentConstructor const&, void *);
	void end_visit (DirElemConstructor const&, void *);
	void end_visit (DirElemContent const&, void *);
	void end_visit (DirPIConstructor const&, void *);
	void end_visit (EnclosedExpr const&, void *);
	void end_visit (Expr const&, void *);
    // void end_visit (ExprSingle const&, void *);
	void end_visit (ExtensionExpr const&, void *);
	void end_visit (FLWORExpr const&, void *);
	void end_visit (FilterExpr const&, void *);
	void end_visit (FunctionCall const&, void *);
	void end_visit (IfExpr const&, void *);
	void end_visit (InstanceofExpr const&, void *);
	void end_visit (IntersectExceptExpr const&, void *);
	void end_visit (MultiplicativeExpr const&, void *);
	void end_visit (NumericLiteral const&, void *);
	void end_visit (OrExpr const&, void *);
	void end_visit (OrderedExpr const&, void *);
	void end_visit (ParenthesizedExpr const&, void *);
	void end_visit (PathExpr const&, void *);
	void end_visit (QuantifiedExpr const&, void *);
	void end_visit (QueryBody const&, void *);
	void end_visit (RangeExpr const&, void *);
	void end_visit (RelativePathExpr const&, void *);
	void end_visit (StringLiteral const&, void *);
	void end_visit (TreatExpr const&, void *);
	void end_visit (TypeswitchExpr const&, void *);
	void end_visit (UnaryExpr const&, void *);
	void end_visit (UnionExpr const&, void *);
	void end_visit (UnorderedExpr const&, void *);
	void end_visit (ValidateExpr const&, void *);
	void end_visit (VarRef const&, void *);

/* update-related */
	void end_visit (DeleteExpr const&, void *);
	void end_visit (InsertExpr const&, void *);
	void end_visit (RenameExpr const&, void *);
	void end_visit (ReplaceExpr const&, void *);
	void end_visit (RevalidationDecl const&, void *);
	void end_visit (TransformExpr const&, void *);
	void end_visit (VarNameList const&, void *);

/* full-text-related */
	void end_visit (FTAnd const&, void *);
	void end_visit (FTAnyallOption const&, void *);
	void end_visit (FTBigUnit const&, void *);
	void end_visit (FTCaseOption const&, void *);
	void end_visit (FTContainsExpr const&, void *);
	void end_visit (FTContent const&, void *);
	void end_visit (FTDiacriticsOption const&, void *);
	void end_visit (FTDistance const&, void *);
	void end_visit (FTIgnoreOption const&, void *);
	void end_visit (FTInclExclStringLiteral const&, void *);
	void end_visit (FTInclExclStringLiteralList const&, void *);
	void end_visit (FTLanguageOption const&, void *);
	void end_visit (FTMatchOption const&, void *);
	void end_visit (FTMatchOptionProximityList const&, void *);
	void end_visit (FTMildnot const&, void *);
	void end_visit (FTOptionDecl const&, void *);
	void end_visit (FTOr const&, void *);
	void end_visit (FTOrderedIndicator const&, void *);
	void end_visit (FTProximity const&, void *);
	void end_visit (FTRange const&, void *);
	void end_visit (FTRefOrList const&, void *);
	void end_visit (FTScope const&, void *);
	void end_visit (FTScoreVar const&, void *);
	void end_visit (FTSelection const&, void *);
	void end_visit (FTStemOption const&, void *);
	void end_visit (FTStopwordOption const&, void *);
	void end_visit (FTStringLiteralList const&, void *);
	void end_visit (FTThesaurusID const&, void *);
	void end_visit (FTThesaurusList const&, void *);
	void end_visit (FTThesaurusOption const&, void *);
	void end_visit (FTTimes const&, void *);
	void end_visit (FTUnaryNot const&, void *);
	void end_visit (FTUnit const&, void *);
	void end_visit (FTWildcardOption const&, void *);
	void end_visit (FTWindow const&, void *);
	void end_visit (FTWords const&, void *);
	void end_visit (FTWordsSelection const&, void *);
	void end_visit (FTWordsValue const&, void *);
	
};


} /* namespace xqp */
#endif /* XQP_NORMALIZE_VISITOR_H */

/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: normalize_visitor.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_NORMALIZE_VISITOR_H
#define XQP_NORMALIZE_VISITOR_H

#include "parsenode_visitor.h"
#include "expr.h"
#include "store/data_manager.h"

#include <stack>

/*______________________________________________________________________
|  
|	 Design note: Visitor pattern.  See, for example:
|	 "Modern C++ Design" by Andrei Alexandrescu, Addison Wesley (2001),
|	 Chapter 10.
|_______________________________________________________________________*/

namespace xqp {

class zorba;

class normalize_visitor : public parsenode_visitor
{
public:
	typedef rchandle<expr> expr_t;

protected:
	zorba* zorp;
	dynamic_context* dctx_p;
	rchandle<data_manager> dmgr_h;

	std::stack<expr_t> nodestack;
	std::stack<expr_t> argstack;
	std::stack<expr_t> pstack;	// predicates stack

public:
	normalize_visitor(zorba*);
	~normalize_visitor() {}

public:
	expr_t pop_nodestack()
	{
		if (nodestack.empty()) return NULL;
		rchandle<expr> e_h = nodestack.top();
		nodestack.pop();
		return e_h;
	}
	void clear_argstack()
	{
		while (!argstack.empty()) argstack.pop();
	}
	void clear_pstack()
	{
		while (!pstack.empty()) pstack.pop();
	}


public:

 /*..........................................
 	:  begin visit                            :
 	:.........................................*/
	bool begin_visit(parsenode const&);
	bool begin_visit(AbbrevForwardStep const&);
	bool begin_visit(AnyKindTest const&);
	bool begin_visit(AposAttrContentList const&);
	bool begin_visit(AposAttrValueContent const&);
	bool begin_visit(ArgList const&);
	bool begin_visit(AtomicType const&);
	bool begin_visit(AttributeTest const&);
	bool begin_visit(BaseURIDecl const&);
	bool begin_visit(BoundarySpaceDecl const&);
	bool begin_visit(CaseClause const&);
	bool begin_visit(CaseClauseList const&);
	bool begin_visit(CommentTest const&);
	bool begin_visit(ConstructionDecl const&);
	bool begin_visit(CopyNamespacesDecl const&);
	bool begin_visit(DefaultCollationDecl const&);
	bool begin_visit(DefaultNamespaceDecl const&);
	bool begin_visit(DirAttr const&);
	bool begin_visit(DirAttributeList const&);
	bool begin_visit(DirAttributeValue const&);
	bool begin_visit(DirElemContentList const&);
	bool begin_visit(DocumentTest const&);
	bool begin_visit(ElementTest const&);
	bool begin_visit(EmptyOrderDecl const&);
	bool begin_visit(ForClause const&);
	bool begin_visit(ForLetClause const&);
	bool begin_visit(ForLetClauseList const&);
	bool begin_visit(ForwardAxis const&);
	bool begin_visit(ForwardStep const&);
	bool begin_visit(FunctionDecl const&);
	bool begin_visit(GeneralComp const&);
	bool begin_visit(ItemType const&);
	bool begin_visit(LetClause const&);
	bool begin_visit(LibraryModule const&);
	bool begin_visit(MainModule  const&);
	bool begin_visit(Module const&);
	bool begin_visit(ModuleDecl const&);
	bool begin_visit(ModuleImport const&);
	bool begin_visit(NameTest const&);
	bool begin_visit(NamespaceDecl const&);
	bool begin_visit(NodeComp const&);
	bool begin_visit(OccurrenceIndicator const&);
	bool begin_visit(OptionDecl const&);
	bool begin_visit(OrderByClause const&);
	bool begin_visit(OrderCollationSpec const&);
	bool begin_visit(OrderDirSpec const&);
	bool begin_visit(OrderEmptySpec const&);
	bool begin_visit(OrderModifier const&);
	bool begin_visit(OrderSpec const&);
	bool begin_visit(OrderSpecList const&);
	bool begin_visit(OrderingModeDecl const&);
	bool begin_visit(PITest const&);
	bool begin_visit(Param const&);
	bool begin_visit(ParamList const&);
	bool begin_visit(PositionalVar const&);
	bool begin_visit(Pragma const&);
	bool begin_visit(PragmaList const&);
	bool begin_visit(PredicateList const&);
	bool begin_visit(Prolog const&);
	bool begin_visit(QVarInDecl const&);
	bool begin_visit(QVarInDeclList const&);
	bool begin_visit(QuoteAttrValueContent const&);
	bool begin_visit(QuoteAttrContentList const&);
	bool begin_visit(ReverseAxis const&);
	bool begin_visit(ReverseStep const&);
	bool begin_visit(SIND_DeclList const&);
	bool begin_visit(SchemaAttributeTest const&);
	bool begin_visit(SchemaElementTest const&);
	bool begin_visit(SchemaImport const&);
	bool begin_visit(SchemaPrefix const&);
	bool begin_visit(SequenceType const&);
	bool begin_visit(SignList const&);
	bool begin_visit(SingleType const&);
	bool begin_visit(TextTest const&);
	bool begin_visit(TypeDeclaration const&);
	bool begin_visit(TypeName const&);
	bool begin_visit(URILiteralList const&);
	bool begin_visit(ValueComp const&);
	bool begin_visit(VarDecl const&);
	bool begin_visit(VarGetsDecl const&);
	bool begin_visit(VarGetsDeclList const&);
	bool begin_visit(VarInDecl const&);
	bool begin_visit(VarInDeclList const&);
	bool begin_visit(VersionDecl const&);
	bool begin_visit(VFO_DeclList const&);
	bool begin_visit(WhereClause const&);
	bool begin_visit(Wildcard const&);

	bool begin_visit(exprnode const&);
	bool begin_visit(AdditiveExpr const&);
	bool begin_visit(AndExpr const&);
	bool begin_visit(AxisStep const&);
	bool begin_visit(CDataSection const&);
	bool begin_visit(CastExpr const&);
	bool begin_visit(CastableExpr const&);
	bool begin_visit(CommonContent const&);
	bool begin_visit(ComparisonExpr const&);
	bool begin_visit(CompAttrConstructor const&);
	bool begin_visit(CompCommentConstructor const&);
	bool begin_visit(CompDocConstructor const&);
	bool begin_visit(CompElemConstructor const&);
	bool begin_visit(CompPIConstructor const&);
	bool begin_visit(CompTextConstructor const&);
	bool begin_visit(ContextItemExpr const&);
	bool begin_visit(DirCommentConstructor const&);
	bool begin_visit(DirElemConstructor const&);
	bool begin_visit(DirElemContent const&);
	bool begin_visit(DirPIConstructor const&);
	bool begin_visit(EnclosedExpr const&);
	bool begin_visit(Expr const&);
	bool begin_visit(ExprSingle const&);
	bool begin_visit(ExtensionExpr const&);
	bool begin_visit(FLWORExpr const&);
	bool begin_visit(FilterExpr const&);
	bool begin_visit(FunctionCall const&);
	bool begin_visit(IfExpr const&);
	bool begin_visit(InstanceofExpr const&);
	bool begin_visit(IntersectExceptExpr const&);
	bool begin_visit(MultiplicativeExpr const&);
	bool begin_visit(NumericLiteral const&);
	bool begin_visit(OrExpr const&);
	bool begin_visit(OrderedExpr const&);
	bool begin_visit(ParenthesizedExpr const&);
	bool begin_visit(PathExpr const&);
	bool begin_visit(QuantifiedExpr const&);
	bool begin_visit(QueryBody const&);
	bool begin_visit(RangeExpr const&);
	bool begin_visit(RelativePathExpr const&);
	bool begin_visit(StringLiteral const&);
	bool begin_visit(TreatExpr const&);
	bool begin_visit(TypeswitchExpr const&);
	bool begin_visit(UnaryExpr const&);
	bool begin_visit(UnionExpr const&);
	bool begin_visit(UnorderedExpr const&);
	bool begin_visit(ValidateExpr const&);
	bool begin_visit(VarRef const&);

/* update-related */
	bool begin_visit(DeleteExpr const&);
	bool begin_visit(InsertExpr const&);
	bool begin_visit(RenameExpr const&);
	bool begin_visit(ReplaceExpr const&);
	bool begin_visit(RevalidationDecl const&);
	bool begin_visit(TransformExpr const&);
	bool begin_visit(VarNameList const&);

/* full-text-related */
	bool begin_visit(FTAnd const&);
	bool begin_visit(FTAnyallOption const&);
	bool begin_visit(FTBigUnit const&);
	bool begin_visit(FTCaseOption const&);
	bool begin_visit(FTContainsExpr const&);
	bool begin_visit(FTContent const&);
	bool begin_visit(FTDiacriticsOption const&);
	bool begin_visit(FTDistance const&);
	bool begin_visit(FTIgnoreOption const&);
	bool begin_visit(FTInclExclStringLiteral const&);
	bool begin_visit(FTInclExclStringLiteralList const&);
	bool begin_visit(FTLanguageOption const&);
	bool begin_visit(FTMatchOption const&);
	bool begin_visit(FTMatchOptionProximityList const&);
	bool begin_visit(FTMildnot const&);
	bool begin_visit(FTOptionDecl const&);
	bool begin_visit(FTOr const&);
	bool begin_visit(FTOrderedIndicator const&);
	bool begin_visit(FTProximity const&);
	bool begin_visit(FTRange const&);
	bool begin_visit(FTRefOrList const&);
	bool begin_visit(FTScope const&);
	bool begin_visit(FTScoreVar const&);
	bool begin_visit(FTSelection const&);
	bool begin_visit(FTStemOption const&);
	bool begin_visit(FTStopwordOption const&);
	bool begin_visit(FTStringLiteralList const&);
	bool begin_visit(FTThesaurusID const&);
	bool begin_visit(FTThesaurusList const&);
	bool begin_visit(FTThesaurusOption const&);
	bool begin_visit(FTTimes const&);
	bool begin_visit(FTUnaryNot const&);
	bool begin_visit(FTUnit const&);
	bool begin_visit(FTWildcardOption const&);
	bool begin_visit(FTWindow const&);
	bool begin_visit(FTWords const&);
	bool begin_visit(FTWordsSelection const&);
	bool begin_visit(FTWordsValue const&);

 /*..........................................
 	:  end visit                              :
 	:.........................................*/
	void end_visit(parsenode const&);
	void end_visit(AbbrevForwardStep const&);
	void end_visit(AnyKindTest const&);
	void end_visit(AposAttrContentList const&);
	void end_visit(AposAttrValueContent const&);
	void end_visit(ArgList const&);
	void end_visit(AtomicType const&);
	void end_visit(AttributeTest const&);
	void end_visit(BaseURIDecl const&);
	void end_visit(BoundarySpaceDecl const&);
	void end_visit(CaseClause const&);
	void end_visit(CaseClauseList const&);
	void end_visit(CommentTest const&);
	void end_visit(ConstructionDecl const&);
	void end_visit(CopyNamespacesDecl const&);
	void end_visit(DefaultCollationDecl const&);
	void end_visit(DefaultNamespaceDecl const&);
	void end_visit(DirAttr const&);
	void end_visit(DirAttributeList const&);
	void end_visit(DirAttributeValue const&);
	void end_visit(DirElemContentList const&);
	void end_visit(DocumentTest const&);
	void end_visit(ElementTest const&);
	void end_visit(EmptyOrderDecl const&);
	void end_visit(ForClause const&);
	void end_visit(ForLetClause const&);
	void end_visit(ForLetClauseList const&);
	void end_visit(ForwardAxis const&);
	void end_visit(ForwardStep const&);
	void end_visit(FunctionDecl const&);
	void end_visit(GeneralComp const&);
	void end_visit(ItemType const&);
	void end_visit(LetClause const&);
	void end_visit(LibraryModule const&);
	void end_visit(MainModule  const&);
	void end_visit(Module const&);
	void end_visit(ModuleDecl const&);
	void end_visit(ModuleImport const&);
	void end_visit(NameTest const&);
	void end_visit(NamespaceDecl const&);
	void end_visit(NodeComp const&);
	void end_visit(OccurrenceIndicator const&);
	void end_visit(OptionDecl const&);
	void end_visit(OrderByClause const&);
	void end_visit(OrderCollationSpec const&);
	void end_visit(OrderDirSpec const&);
	void end_visit(OrderEmptySpec const&);
	void end_visit(OrderModifier const&);
	void end_visit(OrderSpec const&);
	void end_visit(OrderSpecList const&);
	void end_visit(OrderingModeDecl const&);
	void end_visit(PITest const&);
	void end_visit(Param const&);
	void end_visit(ParamList const&);
	void end_visit(PositionalVar const&);
	void end_visit(Pragma const&);
	void end_visit(PragmaList const&);
	void end_visit(PredicateList const&);
	void end_visit(Prolog const&);
	void end_visit(QVarInDecl const&);
	void end_visit(QVarInDeclList const&);
	void end_visit(QuoteAttrValueContent const&);
	void end_visit(QuoteAttrContentList const&);
	void end_visit(ReverseAxis const&);
	void end_visit(ReverseStep const&);
	void end_visit(SIND_DeclList const&);
	void end_visit(SchemaAttributeTest const&);
	void end_visit(SchemaElementTest const&);
	void end_visit(SchemaImport const&);
	void end_visit(SchemaPrefix const&);
	void end_visit(SequenceType const&);
	void end_visit(SignList const&);
	void end_visit(SingleType const&);
	void end_visit(TextTest const&);
	void end_visit(TypeDeclaration const&);
	void end_visit(TypeName const&);
	void end_visit(URILiteralList const&);
	void end_visit(ValueComp const&);
	void end_visit(VarDecl const&);
	void end_visit(VarGetsDecl const&);
	void end_visit(VarGetsDeclList const&);
	void end_visit(VarInDecl const&);
	void end_visit(VarInDeclList const&);
	void end_visit(VersionDecl const&);
	void end_visit(VFO_DeclList const&);
	void end_visit(WhereClause const&);
	void end_visit(Wildcard const&);

	void end_visit(exprnode const&);
	void end_visit(AdditiveExpr const&);
	void end_visit(AndExpr const&);
	void end_visit(AxisStep const&);
	void end_visit(CDataSection const&);
	void end_visit(CastExpr const&);
	void end_visit(CastableExpr const&);
	void end_visit(CommonContent const&);
	void end_visit(ComparisonExpr const&);
	void end_visit(CompAttrConstructor const&);
	void end_visit(CompCommentConstructor const&);
	void end_visit(CompDocConstructor const&);
	void end_visit(CompElemConstructor const&);
	void end_visit(CompPIConstructor const&);
	void end_visit(CompTextConstructor const&);
	void end_visit(ContextItemExpr const&);
	void end_visit(DirCommentConstructor const&);
	void end_visit(DirElemConstructor const&);
	void end_visit(DirElemContent const&);
	void end_visit(DirPIConstructor const&);
	void end_visit(EnclosedExpr const&);
	void end_visit(Expr const&);
	void end_visit(ExprSingle const&);
	void end_visit(ExtensionExpr const&);
	void end_visit(FLWORExpr const&);
	void end_visit(FilterExpr const&);
	void end_visit(FunctionCall const&);
	void end_visit(IfExpr const&);
	void end_visit(InstanceofExpr const&);
	void end_visit(IntersectExceptExpr const&);
	void end_visit(MultiplicativeExpr const&);
	void end_visit(NumericLiteral const&);
	void end_visit(OrExpr const&);
	void end_visit(OrderedExpr const&);
	void end_visit(ParenthesizedExpr const&);
	void end_visit(PathExpr const&);
	void end_visit(QuantifiedExpr const&);
	void end_visit(QueryBody const&);
	void end_visit(RangeExpr const&);
	void end_visit(RelativePathExpr const&);
	void end_visit(StringLiteral const&);
	void end_visit(TreatExpr const&);
	void end_visit(TypeswitchExpr const&);
	void end_visit(UnaryExpr const&);
	void end_visit(UnionExpr const&);
	void end_visit(UnorderedExpr const&);
	void end_visit(ValidateExpr const&);
	void end_visit(VarRef const&);

/* update-related */
	void end_visit(DeleteExpr const&);
	void end_visit(InsertExpr const&);
	void end_visit(RenameExpr const&);
	void end_visit(ReplaceExpr const&);
	void end_visit(RevalidationDecl const&);
	void end_visit(TransformExpr const&);
	void end_visit(VarNameList const&);

/* full-text-related */
	void end_visit(FTAnd const&);
	void end_visit(FTAnyallOption const&);
	void end_visit(FTBigUnit const&);
	void end_visit(FTCaseOption const&);
	void end_visit(FTContainsExpr const&);
	void end_visit(FTContent const&);
	void end_visit(FTDiacriticsOption const&);
	void end_visit(FTDistance const&);
	void end_visit(FTIgnoreOption const&);
	void end_visit(FTInclExclStringLiteral const&);
	void end_visit(FTInclExclStringLiteralList const&);
	void end_visit(FTLanguageOption const&);
	void end_visit(FTMatchOption const&);
	void end_visit(FTMatchOptionProximityList const&);
	void end_visit(FTMildnot const&);
	void end_visit(FTOptionDecl const&);
	void end_visit(FTOr const&);
	void end_visit(FTOrderedIndicator const&);
	void end_visit(FTProximity const&);
	void end_visit(FTRange const&);
	void end_visit(FTRefOrList const&);
	void end_visit(FTScope const&);
	void end_visit(FTScoreVar const&);
	void end_visit(FTSelection const&);
	void end_visit(FTStemOption const&);
	void end_visit(FTStopwordOption const&);
	void end_visit(FTStringLiteralList const&);
	void end_visit(FTThesaurusID const&);
	void end_visit(FTThesaurusList const&);
	void end_visit(FTThesaurusOption const&);
	void end_visit(FTTimes const&);
	void end_visit(FTUnaryNot const&);
	void end_visit(FTUnit const&);
	void end_visit(FTWildcardOption const&);
	void end_visit(FTWindow const&);
	void end_visit(FTWords const&);
	void end_visit(FTWordsSelection const&);
	void end_visit(FTWordsValue const&);

};


} /* namespace xqp */
#endif /* XQP_NORMALIZE_VISITOR_H */

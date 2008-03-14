/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: parsenode_visitor.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef ZORBA_PARSENODE_VISITOR_H
#define ZORBA_PARSENODE_VISITOR_H

#include "common/shared_types.h"

/*______________________________________________________________________
|  
|	 Design note: Visitor pattern.  See, for example:
|	 "Modern C++ Design" by Andrei Alexandrescu,
|  Addison Wesley (2001), Chapter 10.
|_______________________________________________________________________*/

namespace zorba 
{

class parsenode_visitor
{
public:	
	virtual ~parsenode_visitor() {}

public:

  static void *no_state;

 /*..........................................
 	:  begin visit                            :
 	:.........................................*/
	virtual void *begin_visit(parsenode const&) = 0;
	virtual void *begin_visit(exprnode const&) = 0;
	virtual void *begin_visit(AbbrevForwardStep const&) = 0;
	virtual void *begin_visit(AnyKindTest const&) = 0;
	virtual void *begin_visit(AposAttrContentList const&) = 0;
	virtual void *begin_visit(AposAttrValueContent const&) = 0;
	virtual void *begin_visit(ArgList const&) = 0;
	virtual void *begin_visit(AtomicType const&) = 0;
	virtual void *begin_visit(AttributeTest const&) = 0;
	virtual void *begin_visit(BaseURIDecl const&) = 0;
	virtual void *begin_visit(BoundarySpaceDecl const&) = 0;
	virtual void *begin_visit(CaseClause const&) = 0;
	virtual void *begin_visit(CaseClauseList const&) = 0;
	virtual void *begin_visit(CommentTest const&) = 0;
	virtual void *begin_visit(ConstructionDecl const&) = 0;
	virtual void *begin_visit(CopyNamespacesDecl const&) = 0;
	virtual void *begin_visit(DefaultCollationDecl const&) = 0;
	virtual void *begin_visit(DefaultNamespaceDecl const&) = 0;
	virtual void *begin_visit(DirAttr const&) = 0;
	virtual void *begin_visit(DirAttributeList const&) = 0;
	virtual void *begin_visit(DirAttributeValue const&) = 0;
	virtual void *begin_visit(DirElemContentList const&) = 0;
	virtual void *begin_visit(DocumentTest const&) = 0;
	virtual void *begin_visit(ElementTest const&) = 0;
	virtual void *begin_visit(EmptyOrderDecl const&) = 0;
	virtual void *begin_visit(ForClause const&) = 0;
    // virtual void *begin_visit(ForLetClause const&) = 0;
	virtual void *begin_visit(ForLetClauseList const&) = 0;
	virtual void *begin_visit(ForwardAxis const&) = 0;
	virtual void *begin_visit(ForwardStep const&) = 0;
	virtual void *begin_visit(FunctionDecl const&) = 0;
	virtual void *begin_visit(GeneralComp const&) = 0;
	virtual void *begin_visit(ItemType const&) = 0;
	virtual void *begin_visit(LetClause const&) = 0;
	virtual void *begin_visit(LibraryModule const&) = 0;
	virtual void *begin_visit(MainModule  const&) = 0;
	virtual void *begin_visit(Module const&) = 0;
	virtual void *begin_visit(ModuleDecl const&) = 0;
	virtual void *begin_visit(ModuleImport const&) = 0;
	virtual void *begin_visit(NameTest const&) = 0;
	virtual void *begin_visit(NamespaceDecl const&) = 0;
	virtual void *begin_visit(NodeComp const&) = 0;
	virtual void *begin_visit(OccurrenceIndicator const&) = 0;
	virtual void *begin_visit(OptionDecl const&) = 0;
	virtual void *begin_visit(OrderByClause const&) = 0;
	virtual void *begin_visit(OrderCollationSpec const&) = 0;
	virtual void *begin_visit(OrderDirSpec const&) = 0;
	virtual void *begin_visit(OrderEmptySpec const&) = 0;
	virtual void *begin_visit(OrderModifier const&) = 0;
	virtual void *begin_visit(OrderSpec const&) = 0;
	virtual void *begin_visit(OrderSpecList const&) = 0;
	virtual void *begin_visit(OrderingModeDecl const&) = 0;
	virtual void *begin_visit(PITest const&) = 0;
	virtual void *begin_visit(Param const&) = 0;
	virtual void *begin_visit(ParamList const&) = 0;
	virtual void *begin_visit(PositionalVar const&) = 0;
	virtual void *begin_visit(Pragma const&) = 0;
	virtual void *begin_visit(PragmaList const&) = 0;
	virtual void *begin_visit(PredicateList const&) = 0;
	virtual void *begin_visit(Prolog const&) = 0;
	virtual void *begin_visit(QVarInDecl const&) = 0;
	virtual void *begin_visit(QVarInDeclList const&) = 0;
	virtual void *begin_visit(QuoteAttrValueContent const&) = 0;
	virtual void *begin_visit(QuoteAttrContentList const&) = 0;
	virtual void *begin_visit(ReverseAxis const&) = 0;
	virtual void *begin_visit(ReverseStep const&) = 0;
	virtual void *begin_visit(SIND_DeclList const&) = 0;
	virtual void *begin_visit(SchemaAttributeTest const&) = 0;
	virtual void *begin_visit(SchemaElementTest const&) = 0;
	virtual void *begin_visit(SchemaImport const&) = 0;
	virtual void *begin_visit(SchemaPrefix const&) = 0;
	virtual void *begin_visit(SequenceType const&) = 0;
	virtual void *begin_visit(SignList const&) = 0;
	virtual void *begin_visit(SingleType const&) = 0;
	virtual void *begin_visit(TextTest const&) = 0;
	virtual void *begin_visit(TypeDeclaration const&) = 0;
	virtual void *begin_visit(TypeName const&) = 0;
	virtual void *begin_visit(URILiteralList const&) = 0;
	virtual void *begin_visit(ValueComp const&) = 0;
	virtual void *begin_visit(VarDecl const&) = 0;
	virtual void *begin_visit(VarGetsDecl const&) = 0;
	virtual void *begin_visit(VarGetsDeclList const&) = 0;
	virtual void *begin_visit(VarInDecl const&) = 0;
	virtual void *begin_visit(VarInDeclList const&) = 0;
	virtual void *begin_visit(VersionDecl const&) = 0;
	virtual void *begin_visit(VFO_DeclList const&) = 0;
	virtual void *begin_visit(WhereClause const&) = 0;
	virtual void *begin_visit(Wildcard const&) = 0;
  virtual void *begin_visit(QName const&) = 0;

/* expressions */
	virtual void *begin_visit(AdditiveExpr const&) = 0;
	virtual void *begin_visit(AndExpr const&) = 0;
	virtual void *begin_visit(AxisStep const&) = 0;
	virtual void *begin_visit(CDataSection const&) = 0;
	virtual void *begin_visit(CastExpr const&) = 0;
	virtual void *begin_visit(CastableExpr const&) = 0;
	virtual void *begin_visit(CommonContent const&) = 0;
	virtual void *begin_visit(ComparisonExpr const&) = 0;
	virtual void *begin_visit(CompAttrConstructor const&) = 0;
	virtual void *begin_visit(CompCommentConstructor const&) = 0;
	virtual void *begin_visit(CompDocConstructor const&) = 0;
	virtual void *begin_visit(CompElemConstructor const&) = 0;
	virtual void *begin_visit(CompPIConstructor const&) = 0;
	virtual void *begin_visit(CompTextConstructor const&) = 0;
	virtual void *begin_visit(ContextItemExpr const&) = 0;
	virtual void *begin_visit(DirCommentConstructor const&) = 0;
	virtual void *begin_visit(DirElemConstructor const&) = 0;
	virtual void *begin_visit(DirElemContent const&) = 0;
	virtual void *begin_visit(DirPIConstructor const&) = 0;
	virtual void *begin_visit(EnclosedExpr const&) = 0;
	virtual void *begin_visit(Expr const&) = 0;
    // virtual void *begin_visit(ExprSingle const&) = 0;
	virtual void *begin_visit(ExtensionExpr const&) = 0;
	virtual void *begin_visit(FLWORExpr const&) = 0;
	virtual void *begin_visit(FilterExpr const&) = 0;
	virtual void *begin_visit(FunctionCall const&) = 0;
	virtual void *begin_visit(IfExpr const&) = 0;
	virtual void *begin_visit(InstanceofExpr const&) = 0;
	virtual void *begin_visit(IntersectExceptExpr const&) = 0;
	virtual void *begin_visit(MultiplicativeExpr const&) = 0;
	virtual void *begin_visit(NumericLiteral const&) = 0;
	virtual void *begin_visit(OrExpr const&) = 0;
	virtual void *begin_visit(OrderedExpr const&) = 0;
	virtual void *begin_visit(ParenthesizedExpr const&) = 0;
	virtual void *begin_visit(PathExpr const&) = 0;
	virtual void *begin_visit(QuantifiedExpr const&) = 0;
	virtual void *begin_visit(QueryBody const&) = 0;
	virtual void *begin_visit(RangeExpr const&) = 0;
	virtual void *begin_visit(RelativePathExpr const&) = 0;
	virtual void *begin_visit(StringLiteral const&) = 0;
	virtual void *begin_visit(TreatExpr const&) = 0;
	virtual void *begin_visit(TypeswitchExpr const&) = 0;
	virtual void *begin_visit(UnaryExpr const&) = 0;
	virtual void *begin_visit(UnionExpr const&) = 0;
	virtual void *begin_visit(UnorderedExpr const&) = 0;
	virtual void *begin_visit(ValidateExpr const&) = 0;
	virtual void *begin_visit(VarRef const&) = 0;

/* update-related */
	virtual void *begin_visit(DeleteExpr const&) = 0;
	virtual void *begin_visit(InsertExpr const&) = 0;
	virtual void *begin_visit(RenameExpr const&) = 0;
	virtual void *begin_visit(ReplaceExpr const&) = 0;
	virtual void *begin_visit(RevalidationDecl const&) = 0;
	virtual void *begin_visit(TransformExpr const&) = 0;
	virtual void *begin_visit(VarNameList const&) = 0;
  virtual void *begin_visit(VarBinding const&) = 0;

/* try-catch-related */
  virtual void *begin_visit(TryExpr const&) = 0;
  virtual void *begin_visit(CatchListExpr const&) = 0;
  virtual void *begin_visit(CatchExpr const &) = 0;

/* full-text-related */
	virtual void *begin_visit(FTAnd const&) = 0;
	virtual void *begin_visit(FTAnyallOption const&) = 0;
	virtual void *begin_visit(FTBigUnit const&) = 0;
	virtual void *begin_visit(FTCaseOption const&) = 0;
	virtual void *begin_visit(FTContainsExpr const&) = 0;
	virtual void *begin_visit(FTContent const&) = 0;
	virtual void *begin_visit(FTDiacriticsOption const&) = 0;
	virtual void *begin_visit(FTDistance const&) = 0;
	virtual void *begin_visit(FTIgnoreOption const&) = 0;
	virtual void *begin_visit(FTInclExclStringLiteral const&) = 0;
	virtual void *begin_visit(FTInclExclStringLiteralList const&) = 0;
	virtual void *begin_visit(FTLanguageOption const&) = 0;
	virtual void *begin_visit(FTMatchOption const&) = 0;
	virtual void *begin_visit(FTMatchOptionProximityList const&) = 0;
	virtual void *begin_visit(FTMildnot const&) = 0;
	virtual void *begin_visit(FTOptionDecl const&) = 0;
	virtual void *begin_visit(FTOr const&) = 0;
	virtual void *begin_visit(FTOrderedIndicator const&) = 0;
	virtual void *begin_visit(FTProximity const&) = 0;
	virtual void *begin_visit(FTRange const&) = 0;
	virtual void *begin_visit(FTRefOrList const&) = 0;
	virtual void *begin_visit(FTScope const&) = 0;
	virtual void *begin_visit(FTScoreVar const&) = 0;
	virtual void *begin_visit(FTSelection const&) = 0;
	virtual void *begin_visit(FTStemOption const&) = 0;
	virtual void *begin_visit(FTStopwordOption const&) = 0;
	virtual void *begin_visit(FTStringLiteralList const&) = 0;
	virtual void *begin_visit(FTThesaurusID const&) = 0;
	virtual void *begin_visit(FTThesaurusList const&) = 0;
	virtual void *begin_visit(FTThesaurusOption const&) = 0;
	virtual void *begin_visit(FTTimes const&) = 0;
	virtual void *begin_visit(FTUnaryNot const&) = 0;
	virtual void *begin_visit(FTUnit const&) = 0;
	virtual void *begin_visit(FTWildcardOption const&) = 0;
	virtual void *begin_visit(FTWindow const&) = 0;
	virtual void *begin_visit(FTWords const&) = 0;
	virtual void *begin_visit(FTWordsSelection const&) = 0;
	virtual void *begin_visit(FTWordsValue const&) = 0;


 /*..........................................
 	:  end visit                              :
 	:.........................................*/
	virtual void end_visit(parsenode const&, void *visit_state) = 0;
	virtual void end_visit(exprnode const&, void *visit_state) = 0;
	virtual void end_visit(AbbrevForwardStep const&, void *visit_state) = 0;
	virtual void end_visit(AnyKindTest const&, void *visit_state) = 0;
	virtual void end_visit(AposAttrContentList const&, void *visit_state) = 0;
	virtual void end_visit(AposAttrValueContent const&, void *visit_state) = 0;
	virtual void end_visit(ArgList const&, void *visit_state) = 0;
	virtual void end_visit(AtomicType const&, void *visit_state) = 0;
	virtual void end_visit(AttributeTest const&, void *visit_state) = 0;
	virtual void end_visit(BaseURIDecl const&, void *visit_state) = 0;
	virtual void end_visit(BoundarySpaceDecl const&, void *visit_state) = 0;
	virtual void end_visit(CaseClause const&, void *visit_state) = 0;
	virtual void end_visit(CaseClauseList const&, void *visit_state) = 0;
	virtual void end_visit(CommentTest const&, void *visit_state) = 0;
	virtual void end_visit(ConstructionDecl const&, void *visit_state) = 0;
	virtual void end_visit(CopyNamespacesDecl const&, void *visit_state) = 0;
	virtual void end_visit(DefaultCollationDecl const&, void *visit_state) = 0;
	virtual void end_visit(DefaultNamespaceDecl const&, void *visit_state) = 0;
	virtual void end_visit(DirAttr const&, void *visit_state) = 0;
	virtual void end_visit(DirAttributeList const&, void *visit_state) = 0;
	virtual void end_visit(DirAttributeValue const&, void *visit_state) = 0;
	virtual void end_visit(DirElemContentList const&, void *visit_state) = 0;
	virtual void end_visit(DocumentTest const&, void *visit_state) = 0;
	virtual void end_visit(ElementTest const&, void *visit_state) = 0;
	virtual void end_visit(EmptyOrderDecl const&, void *visit_state) = 0;
	virtual void end_visit(ForClause const&, void *visit_state) = 0;
    // virtual void end_visit(ForLetClause const&, void *visit_state) = 0;
	virtual void end_visit(ForLetClauseList const&, void *visit_state) = 0;
	virtual void end_visit(ForwardAxis const&, void *visit_state) = 0;
	virtual void end_visit(ForwardStep const&, void *visit_state) = 0;
	virtual void end_visit(FunctionDecl const&, void *visit_state) = 0;
	virtual void end_visit(GeneralComp const&, void *visit_state) = 0;
	virtual void end_visit(ItemType const&, void *visit_state) = 0;
	virtual void end_visit(LetClause const&, void *visit_state) = 0;
	virtual void end_visit(LibraryModule const&, void *visit_state) = 0;
	virtual void end_visit(MainModule  const&, void *visit_state) = 0;
	virtual void end_visit(Module const&, void *visit_state) = 0;
	virtual void end_visit(ModuleDecl const&, void *visit_state) = 0;
	virtual void end_visit(ModuleImport const&, void *visit_state) = 0;
	virtual void end_visit(NameTest const&, void *visit_state) = 0;
	virtual void end_visit(NamespaceDecl const&, void *visit_state) = 0;
	virtual void end_visit(NodeComp const&, void *visit_state) = 0;
	virtual void end_visit(OccurrenceIndicator const&, void *visit_state) = 0;
	virtual void end_visit(OptionDecl const&, void *visit_state) = 0;
	virtual void end_visit(OrderByClause const&, void *visit_state) = 0;
	virtual void end_visit(OrderCollationSpec const&, void *visit_state) = 0;
	virtual void end_visit(OrderDirSpec const&, void *visit_state) = 0;
	virtual void end_visit(OrderEmptySpec const&, void *visit_state) = 0;
	virtual void end_visit(OrderModifier const&, void *visit_state) = 0;
	virtual void end_visit(OrderSpec const&, void *visit_state) = 0;
	virtual void end_visit(OrderSpecList const&, void *visit_state) = 0;
	virtual void end_visit(OrderingModeDecl const&, void *visit_state) = 0;
	virtual void end_visit(PITest const&, void *visit_state) = 0;
	virtual void end_visit(Param const&, void *visit_state) = 0;
	virtual void end_visit(ParamList const&, void *visit_state) = 0;
	virtual void end_visit(PositionalVar const&, void *visit_state) = 0;
	virtual void end_visit(Pragma const&, void *visit_state) = 0;
	virtual void end_visit(PragmaList const&, void *visit_state) = 0;
	virtual void end_visit(PredicateList const&, void *visit_state) = 0;
	virtual void end_visit(Prolog const&, void *visit_state) = 0;
	virtual void end_visit(QVarInDecl const&, void *visit_state) = 0;
	virtual void end_visit(QVarInDeclList const&, void *visit_state) = 0;
	virtual void end_visit(QuoteAttrValueContent const&, void *visit_state) = 0;
	virtual void end_visit(QuoteAttrContentList const&, void *visit_state) = 0;
	virtual void end_visit(ReverseAxis const&, void *visit_state) = 0;
	virtual void end_visit(ReverseStep const&, void *visit_state) = 0;
	virtual void end_visit(SIND_DeclList const&, void *visit_state) = 0;
	virtual void end_visit(SchemaAttributeTest const&, void *visit_state) = 0;
	virtual void end_visit(SchemaElementTest const&, void *visit_state) = 0;
	virtual void end_visit(SchemaImport const&, void *visit_state) = 0;
	virtual void end_visit(SchemaPrefix const&, void *visit_state) = 0;
	virtual void end_visit(SequenceType const&, void *visit_state) = 0;
	virtual void end_visit(SignList const&, void *visit_state) = 0;
	virtual void end_visit(SingleType const&, void *visit_state) = 0;
	virtual void end_visit(TextTest const&, void *visit_state) = 0;
	virtual void end_visit(TypeDeclaration const&, void *visit_state) = 0;
	virtual void end_visit(TypeName const&, void *visit_state) = 0;
	virtual void end_visit(URILiteralList const&, void *visit_state) = 0;
	virtual void end_visit(ValueComp const&, void *visit_state) = 0;
	virtual void end_visit(VarDecl const&, void *visit_state) = 0;
	virtual void end_visit(VarGetsDecl const&, void *visit_state) = 0;
	virtual void end_visit(VarGetsDeclList const&, void *visit_state) = 0;
	virtual void end_visit(VarInDecl const&, void *visit_state) = 0;
	virtual void end_visit(VarInDeclList const&, void *visit_state) = 0;
	virtual void end_visit(VersionDecl const&, void *visit_state) = 0;
	virtual void end_visit(VFO_DeclList const&, void *visit_state) = 0;
	virtual void end_visit(WhereClause const&, void *visit_state) = 0;
	virtual void end_visit(Wildcard const&, void *visit_state) = 0;
  virtual void end_visit(QName const&, void *visit_state) = 0;

/* expressions */
	virtual void end_visit(AdditiveExpr const&, void *visit_state) = 0;
	virtual void end_visit(AndExpr const&, void *visit_state) = 0;
	virtual void end_visit(AxisStep const&, void *visit_state) = 0;
	virtual void end_visit(CDataSection const&, void *visit_state) = 0;
	virtual void end_visit(CastExpr const&, void *visit_state) = 0;
	virtual void end_visit(CastableExpr const&, void *visit_state) = 0;
	virtual void end_visit(CommonContent const&, void *visit_state) = 0;
	virtual void end_visit(ComparisonExpr const&, void *visit_state) = 0;
	virtual void end_visit(CompAttrConstructor const&, void *visit_state) = 0;
	virtual void end_visit(CompCommentConstructor const&, void *visit_state) = 0;
	virtual void end_visit(CompDocConstructor const&, void *visit_state) = 0;
	virtual void end_visit(CompElemConstructor const&, void *visit_state) = 0;
	virtual void end_visit(CompPIConstructor const&, void *visit_state) = 0;
	virtual void end_visit(CompTextConstructor const&, void *visit_state) = 0;
	virtual void end_visit(ContextItemExpr const&, void *visit_state) = 0;
	virtual void end_visit(DirCommentConstructor const&, void *visit_state) = 0;
	virtual void end_visit(DirElemConstructor const&, void *visit_state) = 0;
	virtual void end_visit(DirElemContent const&, void *visit_state) = 0;
	virtual void end_visit(DirPIConstructor const&, void *visit_state) = 0;
	virtual void end_visit(EnclosedExpr const&, void *visit_state) = 0;
	virtual void end_visit(Expr const&, void *visit_state) = 0;
    // virtual void end_visit(ExprSingle const&, void *visit_state) = 0;
	virtual void end_visit(ExtensionExpr const&, void *visit_state) = 0;
	virtual void end_visit(FLWORExpr const&, void *visit_state) = 0;
	virtual void end_visit(FilterExpr const&, void *visit_state) = 0;
	virtual void end_visit(FunctionCall const&, void *visit_state) = 0;
	virtual void end_visit(IfExpr const&, void *visit_state) = 0;
	virtual void end_visit(InstanceofExpr const&, void *visit_state) = 0;
	virtual void end_visit(IntersectExceptExpr const&, void *visit_state) = 0;
	virtual void end_visit(MultiplicativeExpr const&, void *visit_state) = 0;
	virtual void end_visit(NumericLiteral const&, void *visit_state) = 0;
	virtual void end_visit(OrExpr const&, void *visit_state) = 0;
	virtual void end_visit(OrderedExpr const&, void *visit_state) = 0;
	virtual void end_visit(ParenthesizedExpr const&, void *visit_state) = 0;
	virtual void end_visit(PathExpr const&, void *visit_state) = 0;
	virtual void end_visit(QuantifiedExpr const&, void *visit_state) = 0;
	virtual void end_visit(QueryBody const&, void *visit_state) = 0;
	virtual void end_visit(RangeExpr const&, void *visit_state) = 0;
	virtual void end_visit(RelativePathExpr const&, void *visit_state) = 0;
	virtual void end_visit(StringLiteral const&, void *visit_state) = 0;
	virtual void end_visit(TreatExpr const&, void *visit_state) = 0;
	virtual void end_visit(TypeswitchExpr const&, void *visit_state) = 0;
	virtual void end_visit(UnaryExpr const&, void *visit_state) = 0;
	virtual void end_visit(UnionExpr const&, void *visit_state) = 0;
	virtual void end_visit(UnorderedExpr const&, void *visit_state) = 0;
	virtual void end_visit(ValidateExpr const&, void *visit_state) = 0;
	virtual void end_visit(VarRef const&, void *visit_state) = 0;

/* update-related */
	virtual void end_visit(DeleteExpr const&, void *visit_state) = 0;
	virtual void end_visit(InsertExpr const&, void *visit_state) = 0;
	virtual void end_visit(RenameExpr const&, void *visit_state) = 0;
	virtual void end_visit(ReplaceExpr const&, void *visit_state) = 0;
	virtual void end_visit(RevalidationDecl const&, void *visit_state) = 0;
	virtual void end_visit(TransformExpr const&, void *visit_state) = 0;
	virtual void end_visit(VarNameList const&, void *visit_state) = 0;
  virtual void end_visit(VarBinding const&, void *visit_state) = 0;

/* try-catch-related */
  virtual void end_visit(TryExpr const&, void *visit_state) = 0;
  virtual void end_visit(CatchListExpr const&, void *visit_state) = 0;
  virtual void end_visit(CatchExpr const&, void *visit_state) = 0;

/* full-text-related */
	virtual void end_visit(FTAnd const&, void *visit_state) = 0;
	virtual void end_visit(FTAnyallOption const&, void *visit_state) = 0;
	virtual void end_visit(FTBigUnit const&, void *visit_state) = 0;
	virtual void end_visit(FTCaseOption const&, void *visit_state) = 0;
	virtual void end_visit(FTContainsExpr const&, void *visit_state) = 0;
	virtual void end_visit(FTContent const&, void *visit_state) = 0;
	virtual void end_visit(FTDiacriticsOption const&, void *visit_state) = 0;
	virtual void end_visit(FTDistance const&, void *visit_state) = 0;
	virtual void end_visit(FTIgnoreOption const&, void *visit_state) = 0;
	virtual void end_visit(FTInclExclStringLiteral const&, void *visit_state) = 0;
	virtual void end_visit(FTInclExclStringLiteralList const&, void *visit_state) = 0;
	virtual void end_visit(FTLanguageOption const&, void *visit_state) = 0;
	virtual void end_visit(FTMatchOption const&, void *visit_state) = 0;
	virtual void end_visit(FTMatchOptionProximityList const&, void *visit_state) = 0;
	virtual void end_visit(FTMildnot const&, void *visit_state) = 0;
	virtual void end_visit(FTOptionDecl const&, void *visit_state) = 0;
	virtual void end_visit(FTOr const&, void *visit_state) = 0;
	virtual void end_visit(FTOrderedIndicator const&, void *visit_state) = 0;
	virtual void end_visit(FTProximity const&, void *visit_state) = 0;
	virtual void end_visit(FTRange const&, void *visit_state) = 0;
	virtual void end_visit(FTRefOrList const&, void *visit_state) = 0;
	virtual void end_visit(FTScope const&, void *visit_state) = 0;
	virtual void end_visit(FTScoreVar const&, void *visit_state) = 0;
	virtual void end_visit(FTSelection const&, void *visit_state) = 0;
	virtual void end_visit(FTStemOption const&, void *visit_state) = 0;
	virtual void end_visit(FTStopwordOption const&, void *visit_state) = 0;
	virtual void end_visit(FTStringLiteralList const&, void *visit_state) = 0;
	virtual void end_visit(FTThesaurusID const&, void *visit_state) = 0;
	virtual void end_visit(FTThesaurusList const&, void *visit_state) = 0;
	virtual void end_visit(FTThesaurusOption const&, void *visit_state) = 0;
	virtual void end_visit(FTTimes const&, void *visit_state) = 0;
	virtual void end_visit(FTUnaryNot const&, void *visit_state) = 0;
	virtual void end_visit(FTUnit const&, void *visit_state) = 0;
	virtual void end_visit(FTWildcardOption const&, void *visit_state) = 0;
	virtual void end_visit(FTWindow const&, void *visit_state) = 0;
	virtual void end_visit(FTWords const&, void *visit_state) = 0;
	virtual void end_visit(FTWordsSelection const&, void *visit_state) = 0;
	virtual void end_visit(FTWordsValue const&, void *visit_state) = 0;

    /* Methods that deviate from the visitor pattern that are
     * needed in various situations.
     */

	virtual void intermediate_visit(RelativePathExpr const&, void* /*visit_state*/) { }
  virtual void post_step_visit(AxisStep const&, void * /*visit_state*/) { }
  virtual void pre_predicate_visit(PredicateList const&, void* /*visit_state*/) { }
  virtual void post_predicate_visit(PredicateList const&, void* /*visit_state*/) { }

  /**
   * Methods are used in the translator to check if a DirElemContent is boundary whitespace.
   */
  virtual void begin_check_boundary_whitespace() {}
  virtual void check_boundary_whitespace(const DirElemContent&) {}
  virtual void end_check_boundary_whitespace() {}

  virtual bool is_root_rpe(const RelativePathExpr*) { return true; }
};

} /* namespace zorba */
#endif /* ZORBA_PARSENODE_VISITOR_H */

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

#include "../exprtree/expr.h"

/*______________________________________________________________________
|  
|	 Design note: Visitor pattern.  See, for example:
|	 "Modern C++ Design" by Andrei Alexandrescu, Addison Wesley (2001),
|	 Chapter 10.
|_______________________________________________________________________*/

namespace xqp 
{

class normalize_visitor
{
protected:

public:	
	virtual ~normalize_visitor() {}

public:
	virtual void visit(AbbrevForwardStep&) = 0;
	virtual void visit(AnyKindTest&) = 0;
	virtual void visit(AposAttrContentList&) = 0;
	virtual void visit(AposAttrValueContent&) = 0;
	virtual void visit(ArgList&) = 0;
	virtual void visit(AtomicType&) = 0;
	virtual void visit(AttribNameOrWildcard&) = 0;
	virtual void visit(AttributeDeclaration&) = 0;
	virtual void visit(AttributeName&) = 0;
	virtual void visit(AttributeTest&) = 0;
	virtual void visit(BaseURIDecl&) = 0;
	virtual void visit(BoundarySpaceDecl&) = 0;
	virtual void visit(CaseClause&) = 0;
	virtual void visit(CaseClauseList&) = 0;
	virtual void visit(CommentTest&) = 0;
	virtual void visit(ConstructionDecl&) = 0;
	virtual void visit(CopyNamespacesDecl&) = 0;
	virtual void visit(DefaultCollationDecl&) = 0;
	virtual void visit(DefaultNamespaceDecl&) = 0;
	virtual void visit(DirAttr&) = 0;
	virtual void visit(DirAttributeList&) = 0;
	virtual void visit(DirAttributeValue&) = 0;
	virtual void visit(DirElemContentList&) = 0;
	virtual void visit(DocumentTest&) = 0;
	virtual void visit(ElementDeclaration&) = 0;
	virtual void visit(ElementName&) = 0;
	virtual void visit(ElementNameOrWildcard&) = 0;
	virtual void visit(ElementTest&) = 0;
	virtual void visit(EmptyOrderDecl&) = 0;
	virtual void visit(ForClause&) = 0;
	virtual void visit(ForLetClause&) = 0;
	virtual void visit(ForLetClauseList&) = 0;
	virtual void visit(ForwardAxis&) = 0;
	virtual void visit(ForwardStep&) = 0;
	virtual void visit(FunctionDecl&) = 0;
	virtual void visit(GeneralComp&) = 0;
	virtual void visit(Import&) = 0;
	virtual void visit(InheritMode&) = 0;
	virtual void visit(ItemType&) = 0;
	virtual void visit(KindTest&) = 0;
	virtual void visit(LetClause&) = 0;
	virtual void visit(LibraryModule&) = 0;
	virtual void visit(MainModule &) = 0;
	virtual void visit(Module&) = 0;
	virtual void visit(ModuleDecl&) = 0;
	virtual void visit(ModuleImport&) = 0;
	virtual void visit(NameTest&) = 0;
	virtual void visit(NamespaceDecl&) = 0;
	virtual void visit(NodeComp&) = 0;
	virtual void visit(NodeTest&) = 0;
	virtual void visit(OccurrenceIndicator&) = 0;
	virtual void visit(OptionDecl&) = 0;
	virtual void visit(OrderByClause&) = 0;
	virtual void visit(OrderCollationSpec&) = 0;
	virtual void visit(OrderDirSpec&) = 0;
	virtual void visit(OrderEmptySpec&) = 0;
	virtual void visit(OrderModifier&) = 0;
	virtual void visit(OrderSpec&) = 0;
	virtual void visit(OrderSpecList&) = 0;
	virtual void visit(OrderingModeDecl&) = 0;
	virtual void visit(PITest&) = 0;
	virtual void visit(Param&) = 0;
	virtual void visit(ParamList&) = 0;
	virtual void visit(PositionalVar&) = 0;
	virtual void visit(Pragma&) = 0;
	virtual void visit(PragmaList&) = 0;
	virtual void visit(PredicateList&) = 0;
	virtual void visit(PreserveMode&) = 0;
	virtual void visit(Prolog&) = 0;
	virtual void visit(QVarInDecl&) = 0;
	virtual void visit(QVarInDeclList&) = 0;
	virtual void visit(QuoteAttrValueContent&) = 0;
	virtual void visit(QuoteAttrContentList&) = 0;
	virtual void visit(ReverseAxis&) = 0;
	virtual void visit(ReverseStep&) = 0;
	virtual void visit(SIND_Decl&) = 0;
	virtual void visit(SIND_DeclList&) = 0;
	virtual void visit(SchemaAttributeTest&) = 0;
	virtual void visit(SchemaElementTest&) = 0;
	virtual void visit(SchemaImport&) = 0;
	virtual void visit(SchemaPrefix&) = 0;
	virtual void visit(SequenceType&) = 0;
	virtual void visit(Setter&) = 0;
	virtual void visit(SignList&) = 0;
	virtual void visit(SingleType&) = 0;
	virtual void visit(TextTest&) = 0;
	virtual void visit(TypeDeclaration&) = 0;
	virtual void visit(TypeName&) = 0;
	virtual void visit(URILiteralList&) = 0;
	virtual void visit(ValueComp&) = 0;
	virtual void visit(VarDecl&) = 0;
	virtual void visit(VarGetsDecl&) = 0;
	virtual void visit(VarGetsDeclList&) = 0;
	virtual void visit(VarInDecl&) = 0;
	virtual void visit(VarInDeclList&) = 0;
	virtual void visit(VersionDecl&) = 0;
	virtual void visit(VFO_Decl&) = 0;
	virtual void visit(VFO_DeclList&) = 0;
	virtual void visit(WhereClause&) = 0;
	virtual void visit(Wildcard&) = 0;

/* left-hand sides: expressions */
/* ---------------------------- */
	virtual void visit(AdditiveExpr&) = 0;
	virtual void visit(AndExpr&) = 0;
	virtual void visit(AxisStep&) = 0;
	virtual void visit(CDataSection&) = 0;
	virtual void visit(CastExpr&) = 0;
	virtual void visit(CastableExpr&) = 0;
	virtual void visit(CommonContent&) = 0;
	virtual void visit(ComparisonExpr&) = 0;
	virtual void visit(CompAttrConstructor&) = 0;
	virtual void visit(CompCommentConstructor&) = 0;
	virtual void visit(CompDocConstructor&) = 0;
	virtual void visit(CompElemConstructor&) = 0;
	virtual void visit(CompPIConstructor&) = 0;
	virtual void visit(CompTextConstructor&) = 0;
	virtual void visit(ComputedConstructor&) = 0;
	virtual void visit(Constructor&) = 0;
	virtual void visit(ContextItemExpr&) = 0;
	virtual void visit(DirCommentConstructor&) = 0;
	virtual void visit(DirElemConstructor&) = 0;
	virtual void visit(DirElemContent&) = 0;
	virtual void visit(DirPIConstructor&) = 0;
	virtual void visit(DirectConstructor&) = 0;
	virtual void visit(EnclosedExpr&) = 0;
	virtual void visit(Expr&) = 0;
	virtual void visit(ExprSingle&) = 0;
	virtual void visit(ExtensionExpr&) = 0;
	virtual void visit(FLWORExpr&) = 0;
	virtual void visit(FilterExpr&) = 0;
	virtual void visit(FunctionCall&) = 0;
	virtual void visit(IfExpr&) = 0;
	virtual void visit(InstanceofExpr&) = 0;
	virtual void visit(IntersectExceptExpr&) = 0;
	virtual void visit(Literal&) = 0;
	virtual void visit(MultiplicativeExpr&) = 0;
	virtual void visit(NumericLiteral&) = 0;
	virtual void visit(OrExpr&) = 0;
	virtual void visit(OrderedExpr&) = 0;
	virtual void visit(ParenthesizedExpr&) = 0;
	virtual void visit(PathExpr&) = 0;
	virtual void visit(Predicate&) = 0;
	virtual void visit(PrimaryExpr&) = 0;
	virtual void visit(QuantifiedExpr&) = 0;
	virtual void visit(QueryBody&) = 0;
	virtual void visit(RangeExpr&) = 0;
	virtual void visit(RelativePathExpr&) = 0;
	virtual void visit(StepExpr&) = 0;
	virtual void visit(StringLiteral&) = 0;
	virtual void visit(TreatExpr&) = 0;
	virtual void visit(TypeswitchExpr&) = 0;
	virtual void visit(UnaryExpr&) = 0;
	virtual void visit(UnionExpr&) = 0;
	virtual void visit(UnorderedExpr&) = 0;
	virtual void visit(ValidateExpr&) = 0;
	virtual void visit(ValueExpr&) = 0;
	virtual void visit(VarRef&) = 0;

/* update-related */
/* -------------- */
	virtual void visit(DeleteExpr&) = 0;
	virtual void visit(InsertExpr&) = 0;
	virtual void visit(RenameExpr&) = 0;
	virtual void visit(ReplaceExpr&) = 0;
	virtual void visit(RevalidationDecl&) = 0;
	virtual void visit(TransformExpr&) = 0;
	virtual void visit(VarNameList&) = 0;

/* full-text-related */
/* ----------------- */
	virtual void visit(FTAnd&) = 0;
	virtual void visit(FTAnyallOption&) = 0;
	virtual void visit(FTBigUnit&) = 0;
	virtual void visit(FTCaseOption&) = 0;
	virtual void visit(FTContainsExpr&) = 0;
	virtual void visit(FTContent&) = 0;
	virtual void visit(FTDiacriticsOption&) = 0;
	virtual void visit(FTDistance&) = 0;
	virtual void visit(FTIgnoreOption&) = 0;
	virtual void visit(FTInclExclStringLiteral&) = 0;
	virtual void visit(FTInclExclStringLiteralList&) = 0;
	virtual void visit(FTLanguageOption&) = 0;
	virtual void visit(FTMatchOption&) = 0;
	virtual void visit(FTMatchOptionProximityList&) = 0;
	virtual void visit(FTMildnot&) = 0;
	virtual void visit(FTOptionDecl&) = 0;
	virtual void visit(FTOr&) = 0;
	virtual void visit(FTOrderedIndicator&) = 0;
	virtual void visit(FTProximity&) = 0;
	virtual void visit(FTRange&) = 0;
	virtual void visit(FTRefOrList&) = 0;
	virtual void visit(FTScope&) = 0;
	virtual void visit(FTScoreVar&) = 0;
	virtual void visit(FTSelection&) = 0;
	virtual void visit(FTStemOption&) = 0;
	virtual void visit(FTStopwordOption&) = 0;
	virtual void visit(FTStringLiteralList&) = 0;
	virtual void visit(FTThesaurusID&) = 0;
	virtual void visit(FTThesaurusList&) = 0;
	virtual void visit(FTThesaurusOption&) = 0;
	virtual void visit(FTTimes&) = 0;
	virtual void visit(FTUnaryNot&) = 0;
	virtual void visit(FTUnit&) = 0;
	virtual void visit(FTWildcardOption&) = 0;
	virtual void visit(FTWindow&) = 0;
	virtual void visit(FTWords&) = 0;
	virtual void visit(FTWordsSelection&) = 0;
	virtual void visit(FTWordsValue&) = 0;

};


} /* namespace xqp */
#endif /* XQP_NORMALIZER_H */

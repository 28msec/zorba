/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: parsenode_visitor.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_PARSENODE_VISITOR_H
#define XQP_PARSENODE_VISITOR_H

/*______________________________________________________________________
|  
|	 Design note: Visitor pattern.  See, for example:
|	 "Modern C++ Design" by Andrei Alexandrescu,
|  Addison Wesley (2001), Chapter 10.
|_______________________________________________________________________*/

namespace xqp 
{

class parsenode;
class AbbrevForwardStep; class AnyKindTest; class AposAttrContentList;
class AposAttrValueContent; class ArgList; class AtomicType; class AttributeTest;
class BaseURIDecl; class BoundarySpaceDecl; class CaseClause; class CaseClauseList;
class CommentTest; class ConstructionDecl; class CopyNamespacesDecl;
class DefaultCollationDecl; class DefaultNamespaceDecl; class DirAttr;
class DirAttributeList; class DirAttributeValue; class DirElemContentList;
class DocumentTest; class ElementTest; class EmptyOrderDecl; class ForClause;
//class ForLetClause; 
class ForLetClauseList; class ForwardAxis; class ForwardStep;
class FunctionDecl; class GeneralComp; 
class ItemType; class LetClause; class LibraryModule;
class MainModule ; class Module; class ModuleDecl; class ModuleImport;
class NameTest; class NamespaceDecl; class NodeComp; 
class OccurrenceIndicator; class OptionDecl; class OrderByClause; 
class OrderCollationSpec; class OrderDirSpec; class OrderEmptySpec; 
class OrderModifier; class OrderSpec; class OrderSpecList; class OrderingModeDecl;
class PITest; class Param; class ParamList; class PositionalVar;
class Pragma; class PragmaList; class PredicateList; 
class Prolog; class QVarInDecl; class QVarInDeclList; class QuoteAttrValueContent; 
class QuoteAttrContentList; class ReverseAxis; class ReverseStep;
class SIND_DeclList; class SchemaAttributeTest; class SchemaElementTest; 
class SchemaImport; class SchemaPrefix; class SequenceType;
class SignList; class SingleType; class TextTest; class TypeDeclaration;
class TypeName; class URILiteralList; class ValueComp; class VarDecl;
class VarGetsDecl; class VarGetsDeclList; class VarInDecl; class VarInDeclList;
class VersionDecl; class VFO_DeclList; class WhereClause;
class Wildcard; 


class exprnode;
class AdditiveExpr; class AndExpr; class AxisStep; class CDataSection;
class CastExpr; class CastableExpr; class CommonContent; class ComparisonExpr;
class CompAttrConstructor; class CompCommentConstructor; class CompDocConstructor;
class CompElemConstructor; class CompPIConstructor; class CompTextConstructor;
class ComputedConstructor; class ContextItemExpr;
class DirCommentConstructor; class DirElemConstructor; class DirElemContent;
class DirPIConstructor; class EnclosedExpr;
class Expr; 
//class ExprSingle;
class ExtensionExpr; class FLWORExpr;
class FilterExpr; class FunctionCall; class IfExpr; class InstanceofExpr;
class IntersectExceptExpr; class MultiplicativeExpr;
class NumericLiteral; class OrExpr; class OrderedExpr; class ParenthesizedExpr;
class PathExpr; class QuantifiedExpr;
class QueryBody; class RangeExpr; class RelativePathExpr; 
class StringLiteral; class TreatExpr; class TypeswitchExpr; class UnaryExpr;
class UnionExpr; class UnorderedExpr; class ValidateExpr; 
class VarRef;

/* update-related */
class DeleteExpr; class InsertExpr; class RenameExpr; class ReplaceExpr;
class RevalidationDecl; class TransformExpr; class VarNameList;

/* full-text-related */
class FTAnd; class FTAnyallOption; class FTBigUnit; class FTCaseOption;
class FTContainsExpr; class FTContent; class FTDiacriticsOption; class FTDistance;
class FTIgnoreOption; class FTInclExclStringLiteral;
class FTInclExclStringLiteralList; class FTLanguageOption;
class FTMatchOption; class FTMatchOptionProximityList; class FTMildnot;
class FTOptionDecl; class FTOr; class FTOrderedIndicator; class FTProximity;
class FTRange; class FTRefOrList; class FTScope; class FTScoreVar;
class FTSelection; class FTStemOption; class FTStopwordOption;
class FTStringLiteralList; class FTThesaurusID; class FTThesaurusList;
class FTThesaurusOption; class FTTimes; class FTUnaryNot; class FTUnit;
class FTWildcardOption; class FTWindow; class FTWords; class FTWordsSelection;
class FTWordsValue;


class parsenode_visitor
{
public:	
	virtual ~parsenode_visitor() {}

public:

 /*..........................................
 	:  begin visit                            :
 	:.........................................*/
	virtual bool begin_visit(parsenode const&) = 0;
	virtual bool begin_visit(exprnode const&) = 0;
	virtual bool begin_visit(AbbrevForwardStep const&) = 0;
	virtual bool begin_visit(AnyKindTest const&) = 0;
	virtual bool begin_visit(AposAttrContentList const&) = 0;
	virtual bool begin_visit(AposAttrValueContent const&) = 0;
	virtual bool begin_visit(ArgList const&) = 0;
	virtual bool begin_visit(AtomicType const&) = 0;
	virtual bool begin_visit(AttributeTest const&) = 0;
	virtual bool begin_visit(BaseURIDecl const&) = 0;
	virtual bool begin_visit(BoundarySpaceDecl const&) = 0;
	virtual bool begin_visit(CaseClause const&) = 0;
	virtual bool begin_visit(CaseClauseList const&) = 0;
	virtual bool begin_visit(CommentTest const&) = 0;
	virtual bool begin_visit(ConstructionDecl const&) = 0;
	virtual bool begin_visit(CopyNamespacesDecl const&) = 0;
	virtual bool begin_visit(DefaultCollationDecl const&) = 0;
	virtual bool begin_visit(DefaultNamespaceDecl const&) = 0;
	virtual bool begin_visit(DirAttr const&) = 0;
	virtual bool begin_visit(DirAttributeList const&) = 0;
	virtual bool begin_visit(DirAttributeValue const&) = 0;
	virtual bool begin_visit(DirElemContentList const&) = 0;
	virtual bool begin_visit(DocumentTest const&) = 0;
	virtual bool begin_visit(ElementTest const&) = 0;
	virtual bool begin_visit(EmptyOrderDecl const&) = 0;
	virtual bool begin_visit(ForClause const&) = 0;
    // virtual bool begin_visit(ForLetClause const&) = 0;
	virtual bool begin_visit(ForLetClauseList const&) = 0;
	virtual bool begin_visit(ForwardAxis const&) = 0;
	virtual bool begin_visit(ForwardStep const&) = 0;
	virtual bool begin_visit(FunctionDecl const&) = 0;
	virtual bool begin_visit(GeneralComp const&) = 0;
	virtual bool begin_visit(ItemType const&) = 0;
	virtual bool begin_visit(LetClause const&) = 0;
	virtual bool begin_visit(LibraryModule const&) = 0;
	virtual bool begin_visit(MainModule  const&) = 0;
	virtual bool begin_visit(Module const&) = 0;
	virtual bool begin_visit(ModuleDecl const&) = 0;
	virtual bool begin_visit(ModuleImport const&) = 0;
	virtual bool begin_visit(NameTest const&) = 0;
	virtual bool begin_visit(NamespaceDecl const&) = 0;
	virtual bool begin_visit(NodeComp const&) = 0;
	virtual bool begin_visit(OccurrenceIndicator const&) = 0;
	virtual bool begin_visit(OptionDecl const&) = 0;
	virtual bool begin_visit(OrderByClause const&) = 0;
	virtual bool begin_visit(OrderCollationSpec const&) = 0;
	virtual bool begin_visit(OrderDirSpec const&) = 0;
	virtual bool begin_visit(OrderEmptySpec const&) = 0;
	virtual bool begin_visit(OrderModifier const&) = 0;
	virtual bool begin_visit(OrderSpec const&) = 0;
	virtual bool begin_visit(OrderSpecList const&) = 0;
	virtual bool begin_visit(OrderingModeDecl const&) = 0;
	virtual bool begin_visit(PITest const&) = 0;
	virtual bool begin_visit(Param const&) = 0;
	virtual bool begin_visit(ParamList const&) = 0;
	virtual bool begin_visit(PositionalVar const&) = 0;
	virtual bool begin_visit(Pragma const&) = 0;
	virtual bool begin_visit(PragmaList const&) = 0;
	virtual bool begin_visit(PredicateList const&) = 0;
	virtual bool begin_visit(Prolog const&) = 0;
	virtual bool begin_visit(QVarInDecl const&) = 0;
	virtual bool begin_visit(QVarInDeclList const&) = 0;
	virtual bool begin_visit(QuoteAttrValueContent const&) = 0;
	virtual bool begin_visit(QuoteAttrContentList const&) = 0;
	virtual bool begin_visit(ReverseAxis const&) = 0;
	virtual bool begin_visit(ReverseStep const&) = 0;
	virtual bool begin_visit(SIND_DeclList const&) = 0;
	virtual bool begin_visit(SchemaAttributeTest const&) = 0;
	virtual bool begin_visit(SchemaElementTest const&) = 0;
	virtual bool begin_visit(SchemaImport const&) = 0;
	virtual bool begin_visit(SchemaPrefix const&) = 0;
	virtual bool begin_visit(SequenceType const&) = 0;
	virtual bool begin_visit(SignList const&) = 0;
	virtual bool begin_visit(SingleType const&) = 0;
	virtual bool begin_visit(TextTest const&) = 0;
	virtual bool begin_visit(TypeDeclaration const&) = 0;
	virtual bool begin_visit(TypeName const&) = 0;
	virtual bool begin_visit(URILiteralList const&) = 0;
	virtual bool begin_visit(ValueComp const&) = 0;
	virtual bool begin_visit(VarDecl const&) = 0;
	virtual bool begin_visit(VarGetsDecl const&) = 0;
	virtual bool begin_visit(VarGetsDeclList const&) = 0;
	virtual bool begin_visit(VarInDecl const&) = 0;
	virtual bool begin_visit(VarInDeclList const&) = 0;
	virtual bool begin_visit(VersionDecl const&) = 0;
	virtual bool begin_visit(VFO_DeclList const&) = 0;
	virtual bool begin_visit(WhereClause const&) = 0;
	virtual bool begin_visit(Wildcard const&) = 0;

/* expressions */
	virtual bool begin_visit(AdditiveExpr const&) = 0;
	virtual bool begin_visit(AndExpr const&) = 0;
	virtual bool begin_visit(AxisStep const&) = 0;
	virtual bool begin_visit(CDataSection const&) = 0;
	virtual bool begin_visit(CastExpr const&) = 0;
	virtual bool begin_visit(CastableExpr const&) = 0;
	virtual bool begin_visit(CommonContent const&) = 0;
	virtual bool begin_visit(ComparisonExpr const&) = 0;
	virtual bool begin_visit(CompAttrConstructor const&) = 0;
	virtual bool begin_visit(CompCommentConstructor const&) = 0;
	virtual bool begin_visit(CompDocConstructor const&) = 0;
	virtual bool begin_visit(CompElemConstructor const&) = 0;
	virtual bool begin_visit(CompPIConstructor const&) = 0;
	virtual bool begin_visit(CompTextConstructor const&) = 0;
	virtual bool begin_visit(ContextItemExpr const&) = 0;
	virtual bool begin_visit(DirCommentConstructor const&) = 0;
	virtual bool begin_visit(DirElemConstructor const&) = 0;
	virtual bool begin_visit(DirElemContent const&) = 0;
	virtual bool begin_visit(DirPIConstructor const&) = 0;
	virtual bool begin_visit(EnclosedExpr const&) = 0;
	virtual bool begin_visit(Expr const&) = 0;
    // virtual bool begin_visit(ExprSingle const&) = 0;
	virtual bool begin_visit(ExtensionExpr const&) = 0;
	virtual bool begin_visit(FLWORExpr const&) = 0;
	virtual bool begin_visit(FilterExpr const&) = 0;
	virtual bool begin_visit(FunctionCall const&) = 0;
	virtual bool begin_visit(IfExpr const&) = 0;
	virtual bool begin_visit(InstanceofExpr const&) = 0;
	virtual bool begin_visit(IntersectExceptExpr const&) = 0;
	virtual bool begin_visit(MultiplicativeExpr const&) = 0;
	virtual bool begin_visit(NumericLiteral const&) = 0;
	virtual bool begin_visit(OrExpr const&) = 0;
	virtual bool begin_visit(OrderedExpr const&) = 0;
	virtual bool begin_visit(ParenthesizedExpr const&) = 0;
	virtual bool begin_visit(PathExpr const&) = 0;
	virtual bool begin_visit(QuantifiedExpr const&) = 0;
	virtual bool begin_visit(QueryBody const&) = 0;
	virtual bool begin_visit(RangeExpr const&) = 0;
	virtual bool begin_visit(RelativePathExpr const&) = 0;
	virtual bool begin_visit(StringLiteral const&) = 0;
	virtual bool begin_visit(TreatExpr const&) = 0;
	virtual bool begin_visit(TypeswitchExpr const&) = 0;
	virtual bool begin_visit(UnaryExpr const&) = 0;
	virtual bool begin_visit(UnionExpr const&) = 0;
	virtual bool begin_visit(UnorderedExpr const&) = 0;
	virtual bool begin_visit(ValidateExpr const&) = 0;
	virtual bool begin_visit(VarRef const&) = 0;

/* update-related */
	virtual bool begin_visit(DeleteExpr const&) = 0;
	virtual bool begin_visit(InsertExpr const&) = 0;
	virtual bool begin_visit(RenameExpr const&) = 0;
	virtual bool begin_visit(ReplaceExpr const&) = 0;
	virtual bool begin_visit(RevalidationDecl const&) = 0;
	virtual bool begin_visit(TransformExpr const&) = 0;
	virtual bool begin_visit(VarNameList const&) = 0;

/* full-text-related */
	virtual bool begin_visit(FTAnd const&) = 0;
	virtual bool begin_visit(FTAnyallOption const&) = 0;
	virtual bool begin_visit(FTBigUnit const&) = 0;
	virtual bool begin_visit(FTCaseOption const&) = 0;
	virtual bool begin_visit(FTContainsExpr const&) = 0;
	virtual bool begin_visit(FTContent const&) = 0;
	virtual bool begin_visit(FTDiacriticsOption const&) = 0;
	virtual bool begin_visit(FTDistance const&) = 0;
	virtual bool begin_visit(FTIgnoreOption const&) = 0;
	virtual bool begin_visit(FTInclExclStringLiteral const&) = 0;
	virtual bool begin_visit(FTInclExclStringLiteralList const&) = 0;
	virtual bool begin_visit(FTLanguageOption const&) = 0;
	virtual bool begin_visit(FTMatchOption const&) = 0;
	virtual bool begin_visit(FTMatchOptionProximityList const&) = 0;
	virtual bool begin_visit(FTMildnot const&) = 0;
	virtual bool begin_visit(FTOptionDecl const&) = 0;
	virtual bool begin_visit(FTOr const&) = 0;
	virtual bool begin_visit(FTOrderedIndicator const&) = 0;
	virtual bool begin_visit(FTProximity const&) = 0;
	virtual bool begin_visit(FTRange const&) = 0;
	virtual bool begin_visit(FTRefOrList const&) = 0;
	virtual bool begin_visit(FTScope const&) = 0;
	virtual bool begin_visit(FTScoreVar const&) = 0;
	virtual bool begin_visit(FTSelection const&) = 0;
	virtual bool begin_visit(FTStemOption const&) = 0;
	virtual bool begin_visit(FTStopwordOption const&) = 0;
	virtual bool begin_visit(FTStringLiteralList const&) = 0;
	virtual bool begin_visit(FTThesaurusID const&) = 0;
	virtual bool begin_visit(FTThesaurusList const&) = 0;
	virtual bool begin_visit(FTThesaurusOption const&) = 0;
	virtual bool begin_visit(FTTimes const&) = 0;
	virtual bool begin_visit(FTUnaryNot const&) = 0;
	virtual bool begin_visit(FTUnit const&) = 0;
	virtual bool begin_visit(FTWildcardOption const&) = 0;
	virtual bool begin_visit(FTWindow const&) = 0;
	virtual bool begin_visit(FTWords const&) = 0;
	virtual bool begin_visit(FTWordsSelection const&) = 0;
	virtual bool begin_visit(FTWordsValue const&) = 0;


 /*..........................................
 	:  end visit                              :
 	:.........................................*/
	virtual void end_visit(parsenode const&) = 0;
	virtual void end_visit(exprnode const&) = 0;
	virtual void end_visit(AbbrevForwardStep const&) = 0;
	virtual void end_visit(AnyKindTest const&) = 0;
	virtual void end_visit(AposAttrContentList const&) = 0;
	virtual void end_visit(AposAttrValueContent const&) = 0;
	virtual void end_visit(ArgList const&) = 0;
	virtual void end_visit(AtomicType const&) = 0;
	virtual void end_visit(AttributeTest const&) = 0;
	virtual void end_visit(BaseURIDecl const&) = 0;
	virtual void end_visit(BoundarySpaceDecl const&) = 0;
	virtual void end_visit(CaseClause const&) = 0;
	virtual void end_visit(CaseClauseList const&) = 0;
	virtual void end_visit(CommentTest const&) = 0;
	virtual void end_visit(ConstructionDecl const&) = 0;
	virtual void end_visit(CopyNamespacesDecl const&) = 0;
	virtual void end_visit(DefaultCollationDecl const&) = 0;
	virtual void end_visit(DefaultNamespaceDecl const&) = 0;
	virtual void end_visit(DirAttr const&) = 0;
	virtual void end_visit(DirAttributeList const&) = 0;
	virtual void end_visit(DirAttributeValue const&) = 0;
	virtual void end_visit(DirElemContentList const&) = 0;
	virtual void end_visit(DocumentTest const&) = 0;
	virtual void end_visit(ElementTest const&) = 0;
	virtual void end_visit(EmptyOrderDecl const&) = 0;
	virtual void end_visit(ForClause const&) = 0;
    // virtual void end_visit(ForLetClause const&) = 0;
	virtual void end_visit(ForLetClauseList const&) = 0;
	virtual void end_visit(ForwardAxis const&) = 0;
	virtual void end_visit(ForwardStep const&) = 0;
	virtual void end_visit(FunctionDecl const&) = 0;
	virtual void end_visit(GeneralComp const&) = 0;
	virtual void end_visit(ItemType const&) = 0;
	virtual void end_visit(LetClause const&) = 0;
	virtual void end_visit(LibraryModule const&) = 0;
	virtual void end_visit(MainModule  const&) = 0;
	virtual void end_visit(Module const&) = 0;
	virtual void end_visit(ModuleDecl const&) = 0;
	virtual void end_visit(ModuleImport const&) = 0;
	virtual void end_visit(NameTest const&) = 0;
	virtual void end_visit(NamespaceDecl const&) = 0;
	virtual void end_visit(NodeComp const&) = 0;
	virtual void end_visit(OccurrenceIndicator const&) = 0;
	virtual void end_visit(OptionDecl const&) = 0;
	virtual void end_visit(OrderByClause const&) = 0;
	virtual void end_visit(OrderCollationSpec const&) = 0;
	virtual void end_visit(OrderDirSpec const&) = 0;
	virtual void end_visit(OrderEmptySpec const&) = 0;
	virtual void end_visit(OrderModifier const&) = 0;
	virtual void end_visit(OrderSpec const&) = 0;
	virtual void end_visit(OrderSpecList const&) = 0;
	virtual void end_visit(OrderingModeDecl const&) = 0;
	virtual void end_visit(PITest const&) = 0;
	virtual void end_visit(Param const&) = 0;
	virtual void end_visit(ParamList const&) = 0;
	virtual void end_visit(PositionalVar const&) = 0;
	virtual void end_visit(Pragma const&) = 0;
	virtual void end_visit(PragmaList const&) = 0;
	virtual void end_visit(PredicateList const&) = 0;
	virtual void end_visit(Prolog const&) = 0;
	virtual void end_visit(QVarInDecl const&) = 0;
	virtual void end_visit(QVarInDeclList const&) = 0;
	virtual void end_visit(QuoteAttrValueContent const&) = 0;
	virtual void end_visit(QuoteAttrContentList const&) = 0;
	virtual void end_visit(ReverseAxis const&) = 0;
	virtual void end_visit(ReverseStep const&) = 0;
	virtual void end_visit(SIND_DeclList const&) = 0;
	virtual void end_visit(SchemaAttributeTest const&) = 0;
	virtual void end_visit(SchemaElementTest const&) = 0;
	virtual void end_visit(SchemaImport const&) = 0;
	virtual void end_visit(SchemaPrefix const&) = 0;
	virtual void end_visit(SequenceType const&) = 0;
	virtual void end_visit(SignList const&) = 0;
	virtual void end_visit(SingleType const&) = 0;
	virtual void end_visit(TextTest const&) = 0;
	virtual void end_visit(TypeDeclaration const&) = 0;
	virtual void end_visit(TypeName const&) = 0;
	virtual void end_visit(URILiteralList const&) = 0;
	virtual void end_visit(ValueComp const&) = 0;
	virtual void end_visit(VarDecl const&) = 0;
	virtual void end_visit(VarGetsDecl const&) = 0;
	virtual void end_visit(VarGetsDeclList const&) = 0;
	virtual void end_visit(VarInDecl const&) = 0;
	virtual void end_visit(VarInDeclList const&) = 0;
	virtual void end_visit(VersionDecl const&) = 0;
	virtual void end_visit(VFO_DeclList const&) = 0;
	virtual void end_visit(WhereClause const&) = 0;
	virtual void end_visit(Wildcard const&) = 0;

/* expressions */
	virtual void end_visit(AdditiveExpr const&) = 0;
	virtual void end_visit(AndExpr const&) = 0;
	virtual void end_visit(AxisStep const&) = 0;
	virtual void end_visit(CDataSection const&) = 0;
	virtual void end_visit(CastExpr const&) = 0;
	virtual void end_visit(CastableExpr const&) = 0;
	virtual void end_visit(CommonContent const&) = 0;
	virtual void end_visit(ComparisonExpr const&) = 0;
	virtual void end_visit(CompAttrConstructor const&) = 0;
	virtual void end_visit(CompCommentConstructor const&) = 0;
	virtual void end_visit(CompDocConstructor const&) = 0;
	virtual void end_visit(CompElemConstructor const&) = 0;
	virtual void end_visit(CompPIConstructor const&) = 0;
	virtual void end_visit(CompTextConstructor const&) = 0;
	virtual void end_visit(ContextItemExpr const&) = 0;
	virtual void end_visit(DirCommentConstructor const&) = 0;
	virtual void end_visit(DirElemConstructor const&) = 0;
	virtual void end_visit(DirElemContent const&) = 0;
	virtual void end_visit(DirPIConstructor const&) = 0;
	virtual void end_visit(EnclosedExpr const&) = 0;
	virtual void end_visit(Expr const&) = 0;
    // virtual void end_visit(ExprSingle const&) = 0;
	virtual void end_visit(ExtensionExpr const&) = 0;
	virtual void end_visit(FLWORExpr const&) = 0;
	virtual void end_visit(FilterExpr const&) = 0;
	virtual void end_visit(FunctionCall const&) = 0;
	virtual void end_visit(IfExpr const&) = 0;
	virtual void end_visit(InstanceofExpr const&) = 0;
	virtual void end_visit(IntersectExceptExpr const&) = 0;
	virtual void end_visit(MultiplicativeExpr const&) = 0;
	virtual void end_visit(NumericLiteral const&) = 0;
	virtual void end_visit(OrExpr const&) = 0;
	virtual void end_visit(OrderedExpr const&) = 0;
	virtual void end_visit(ParenthesizedExpr const&) = 0;
	virtual void end_visit(PathExpr const&) = 0;
	virtual void end_visit(QuantifiedExpr const&) = 0;
	virtual void end_visit(QueryBody const&) = 0;
	virtual void end_visit(RangeExpr const&) = 0;
	virtual void end_visit(RelativePathExpr const&) = 0;
	virtual void end_visit(StringLiteral const&) = 0;
	virtual void end_visit(TreatExpr const&) = 0;
	virtual void end_visit(TypeswitchExpr const&) = 0;
	virtual void end_visit(UnaryExpr const&) = 0;
	virtual void end_visit(UnionExpr const&) = 0;
	virtual void end_visit(UnorderedExpr const&) = 0;
	virtual void end_visit(ValidateExpr const&) = 0;
	virtual void end_visit(VarRef const&) = 0;

/* update-related */
	virtual void end_visit(DeleteExpr const&) = 0;
	virtual void end_visit(InsertExpr const&) = 0;
	virtual void end_visit(RenameExpr const&) = 0;
	virtual void end_visit(ReplaceExpr const&) = 0;
	virtual void end_visit(RevalidationDecl const&) = 0;
	virtual void end_visit(TransformExpr const&) = 0;
	virtual void end_visit(VarNameList const&) = 0;

/* full-text-related */
	virtual void end_visit(FTAnd const&) = 0;
	virtual void end_visit(FTAnyallOption const&) = 0;
	virtual void end_visit(FTBigUnit const&) = 0;
	virtual void end_visit(FTCaseOption const&) = 0;
	virtual void end_visit(FTContainsExpr const&) = 0;
	virtual void end_visit(FTContent const&) = 0;
	virtual void end_visit(FTDiacriticsOption const&) = 0;
	virtual void end_visit(FTDistance const&) = 0;
	virtual void end_visit(FTIgnoreOption const&) = 0;
	virtual void end_visit(FTInclExclStringLiteral const&) = 0;
	virtual void end_visit(FTInclExclStringLiteralList const&) = 0;
	virtual void end_visit(FTLanguageOption const&) = 0;
	virtual void end_visit(FTMatchOption const&) = 0;
	virtual void end_visit(FTMatchOptionProximityList const&) = 0;
	virtual void end_visit(FTMildnot const&) = 0;
	virtual void end_visit(FTOptionDecl const&) = 0;
	virtual void end_visit(FTOr const&) = 0;
	virtual void end_visit(FTOrderedIndicator const&) = 0;
	virtual void end_visit(FTProximity const&) = 0;
	virtual void end_visit(FTRange const&) = 0;
	virtual void end_visit(FTRefOrList const&) = 0;
	virtual void end_visit(FTScope const&) = 0;
	virtual void end_visit(FTScoreVar const&) = 0;
	virtual void end_visit(FTSelection const&) = 0;
	virtual void end_visit(FTStemOption const&) = 0;
	virtual void end_visit(FTStopwordOption const&) = 0;
	virtual void end_visit(FTStringLiteralList const&) = 0;
	virtual void end_visit(FTThesaurusID const&) = 0;
	virtual void end_visit(FTThesaurusList const&) = 0;
	virtual void end_visit(FTThesaurusOption const&) = 0;
	virtual void end_visit(FTTimes const&) = 0;
	virtual void end_visit(FTUnaryNot const&) = 0;
	virtual void end_visit(FTUnit const&) = 0;
	virtual void end_visit(FTWildcardOption const&) = 0;
	virtual void end_visit(FTWindow const&) = 0;
	virtual void end_visit(FTWords const&) = 0;
	virtual void end_visit(FTWordsSelection const&) = 0;
	virtual void end_visit(FTWordsValue const&) = 0;
	
};

} /* namespace xqp */
#endif /* XQP_PARSENODE_VISITOR_H */

#ifndef XQP_PARSENODE_PRINT_XML_VISITOR_H
#define XQP_PARSENODE_PRINT_XML_VISITOR_H

#include "parsenode_visitor.h"

#include <iostream>
#include <ostream>
/*______________________________________________________________________
|  
|	 Design note: Visitor pattern.  See, for example:
|	 "Modern C++ Design" by Andrei Alexandrescu, Addison Wesley (const 2001),
|	 Chapter 10.
|_______________________________________________________________________*/

namespace xqp {

class ParseNodePrintXMLVisitor : public parsenode_visitor
{
    
#define INDENT  os << std::string(theIndent, ' ')
#define INDENT_INC  theIndent += 2
#define INDENT_DEC  theIndent -= 2
#define NL  os << std::endl


protected:
    int theIndent;
    std::ostream& os;

public:
    ParseNodePrintXMLVisitor(std::ostream &);

public:
    /*..........................................
 	:  begin visit                            :
 	:.........................................*/
	bool begin_visit(const parsenode &);
	bool begin_visit(const AbbrevForwardStep &);
	bool begin_visit(const AnyKindTest &);
	bool begin_visit(const AposAttrContentList &);
	bool begin_visit(const AposAttrValueContent &);
	bool begin_visit(const ArgList &);
	bool begin_visit(const AtomicType &);
	bool begin_visit(const AttributeTest &);
	bool begin_visit(const BaseURIDecl &);
	bool begin_visit(const BoundarySpaceDecl &);
	bool begin_visit(const CaseClause &);
	bool begin_visit(const CaseClauseList &);
	bool begin_visit(const CommentTest &);
	bool begin_visit(const ConstructionDecl &);
	bool begin_visit(const CopyNamespacesDecl &);
	bool begin_visit(const DefaultCollationDecl &);
	bool begin_visit(const DefaultNamespaceDecl &);
	bool begin_visit(const DirAttr &);
	bool begin_visit(const DirAttributeList &);
	bool begin_visit(const DirAttributeValue &);
	bool begin_visit(const DirElemContentList &);
	bool begin_visit(const DocumentTest &);
	bool begin_visit(const ElementTest &);
	bool begin_visit(const EmptyOrderDecl &);
	bool begin_visit(const ForClause &);
//	bool begin_visit(const ForLetClause &);
	bool begin_visit(const ForLetClauseList &);
	bool begin_visit(const ForwardAxis &);
	bool begin_visit(const ForwardStep &);
	bool begin_visit(const FunctionDecl &);
	bool begin_visit(const GeneralComp &);
	bool begin_visit(const ItemType &);
	bool begin_visit(const LetClause &);
	bool begin_visit(const LibraryModule &);
	bool begin_visit(const MainModule  &);
	bool begin_visit(const Module &);
	bool begin_visit(const ModuleDecl &);
	bool begin_visit(const ModuleImport &);
	bool begin_visit(const NameTest &);
	bool begin_visit(const NamespaceDecl &);
	bool begin_visit(const NodeComp &);
	bool begin_visit(const OccurrenceIndicator &);
	bool begin_visit(const OptionDecl &);
	bool begin_visit(const OrderByClause &);
	bool begin_visit(const OrderCollationSpec &);
	bool begin_visit(const OrderDirSpec &);
	bool begin_visit(const OrderEmptySpec &);
	bool begin_visit(const OrderModifier &);
	bool begin_visit(const OrderSpec &);
	bool begin_visit(const OrderSpecList &);
	bool begin_visit(const OrderingModeDecl &);
	bool begin_visit(const PITest &);
	bool begin_visit(const Param &);
	bool begin_visit(const ParamList &);
	bool begin_visit(const PositionalVar &);
	bool begin_visit(const Pragma &);
	bool begin_visit(const PragmaList &);
	bool begin_visit(const PredicateList &);
	bool begin_visit(const Prolog &);
	bool begin_visit(const QVarInDecl &);
	bool begin_visit(const QVarInDeclList &);
	bool begin_visit(const QuoteAttrValueContent &);
	bool begin_visit(const QuoteAttrContentList &);
	bool begin_visit(const ReverseAxis &);
	bool begin_visit(const ReverseStep &);
	bool begin_visit(const SIND_DeclList &);
	bool begin_visit(const SchemaAttributeTest &);
	bool begin_visit(const SchemaElementTest &);
	bool begin_visit(const SchemaImport &);
	bool begin_visit(const SchemaPrefix &);
	bool begin_visit(const SequenceType &);
	bool begin_visit(const SignList &);
	bool begin_visit(const SingleType &);
	bool begin_visit(const TextTest &);
	bool begin_visit(const TypeDeclaration &);
	bool begin_visit(const TypeName &);
	bool begin_visit(const URILiteralList &);
	bool begin_visit(const ValueComp &);
	bool begin_visit(const VarDecl &);
	bool begin_visit(const VarGetsDecl &);
	bool begin_visit(const VarGetsDeclList &);
	bool begin_visit(const VarInDecl &);
	bool begin_visit(const VarInDeclList &);
	bool begin_visit(const VersionDecl &);
	bool begin_visit(const VFO_DeclList &);
	bool begin_visit(const WhereClause &);
	bool begin_visit(const Wildcard &);

	bool begin_visit(const exprnode &);
	bool begin_visit(const AdditiveExpr &);
	bool begin_visit(const AndExpr &);
	bool begin_visit(const AxisStep &);
	bool begin_visit(const CDataSection &);
	bool begin_visit(const CastExpr &);
	bool begin_visit(const CastableExpr &);
	bool begin_visit(const CommonContent &);
	bool begin_visit(const ComparisonExpr &);
	bool begin_visit(const CompAttrConstructor &);
	bool begin_visit(const CompCommentConstructor &);
	bool begin_visit(const CompDocConstructor &);
	bool begin_visit(const CompElemConstructor &);
	bool begin_visit(const CompPIConstructor &);
	bool begin_visit(const CompTextConstructor &);
	bool begin_visit(const ContextItemExpr &);
	bool begin_visit(const DirCommentConstructor &);
	bool begin_visit(const DirElemConstructor &);
	bool begin_visit(const DirElemContent &);
	bool begin_visit(const DirPIConstructor &);
	bool begin_visit(const EnclosedExpr &);
	bool begin_visit(const Expr &);
    // bool begin_visit(const ExprSingle &);
	bool begin_visit(const ExtensionExpr &);
	bool begin_visit(const FLWORExpr &);
	bool begin_visit(const FilterExpr &);
	bool begin_visit(const FunctionCall &);
	bool begin_visit(const IfExpr &);
	bool begin_visit(const InstanceofExpr &);
	bool begin_visit(const IntersectExceptExpr &);
	bool begin_visit(const MultiplicativeExpr &);
	bool begin_visit(const NumericLiteral &);
	bool begin_visit(const OrExpr &);
	bool begin_visit(const OrderedExpr &);
	bool begin_visit(const ParenthesizedExpr &);
	bool begin_visit(const PathExpr &);
	bool begin_visit(const QuantifiedExpr &);
	bool begin_visit(const QueryBody &);
	bool begin_visit(const RangeExpr &);
	bool begin_visit(const RelativePathExpr &);
	bool begin_visit(const StringLiteral &);
	bool begin_visit(const TreatExpr &);
	bool begin_visit(const TypeswitchExpr &);
	bool begin_visit(const UnaryExpr &);
	bool begin_visit(const UnionExpr &);
	bool begin_visit(const UnorderedExpr &);
	bool begin_visit(const ValidateExpr &);
	bool begin_visit(const VarRef &);

/* update-related */
	bool begin_visit(const DeleteExpr &);
	bool begin_visit(const InsertExpr &);
	bool begin_visit(const RenameExpr &);
	bool begin_visit(const ReplaceExpr &);
	bool begin_visit(const RevalidationDecl &);
	bool begin_visit(const TransformExpr &);
	bool begin_visit(const VarNameList &);

/* full-text-related */
	bool begin_visit(const FTAnd &);
	bool begin_visit(const FTAnyallOption &);
	bool begin_visit(const FTBigUnit &);
	bool begin_visit(const FTCaseOption &);
	bool begin_visit(const FTContainsExpr &);
	bool begin_visit(const FTContent &);
	bool begin_visit(const FTDiacriticsOption &);
	bool begin_visit(const FTDistance &);
	bool begin_visit(const FTIgnoreOption &);
	bool begin_visit(const FTInclExclStringLiteral &);
	bool begin_visit(const FTInclExclStringLiteralList &);
	bool begin_visit(const FTLanguageOption &);
	bool begin_visit(const FTMatchOption &);
	bool begin_visit(const FTMatchOptionProximityList &);
	bool begin_visit(const FTMildnot &);
	bool begin_visit(const FTOptionDecl &);
	bool begin_visit(const FTOr &);
	bool begin_visit(const FTOrderedIndicator &);
	bool begin_visit(const FTProximity &);
	bool begin_visit(const FTRange &);
	bool begin_visit(const FTRefOrList &);
	bool begin_visit(const FTScope &);
	bool begin_visit(const FTScoreVar &);
	bool begin_visit(const FTSelection &);
	bool begin_visit(const FTStemOption &);
	bool begin_visit(const FTStopwordOption &);
	bool begin_visit(const FTStringLiteralList &);
	bool begin_visit(const FTThesaurusID &);
	bool begin_visit(const FTThesaurusList &);
	bool begin_visit(const FTThesaurusOption &);
	bool begin_visit(const FTTimes &);
	bool begin_visit(const FTUnaryNot &);
	bool begin_visit(const FTUnit &);
	bool begin_visit(const FTWildcardOption &);
	bool begin_visit(const FTWindow &);
	bool begin_visit(const FTWords &);
	bool begin_visit(const FTWordsSelection &);
	bool begin_visit(const FTWordsValue &);

 /*..........................................
 	:  end visit                              :
 	:.........................................*/
	void end_visit(const parsenode &);
	void end_visit(const AbbrevForwardStep &);
	void end_visit(const AnyKindTest &);
	void end_visit(const AposAttrContentList &);
	void end_visit(const AposAttrValueContent &);
	void end_visit(const ArgList &);
	void end_visit(const AtomicType &);
	void end_visit(const AttributeTest &);
	void end_visit(const BaseURIDecl &);
	void end_visit(const BoundarySpaceDecl &);
	void end_visit(const CaseClause &);
	void end_visit(const CaseClauseList &);
	void end_visit(const CommentTest &);
	void end_visit(const ConstructionDecl &);
	void end_visit(const CopyNamespacesDecl &);
	void end_visit(const DefaultCollationDecl &);
	void end_visit(const DefaultNamespaceDecl &);
	void end_visit(const DirAttr &);
	void end_visit(const DirAttributeList &);
	void end_visit(const DirAttributeValue &);
	void end_visit(const DirElemContentList &);
	void end_visit(const DocumentTest &);
	void end_visit(const ElementTest &);
	void end_visit(const EmptyOrderDecl &);
	void end_visit(const ForClause &);
    // void end_visit(const ForLetClause &);
	void end_visit(const ForLetClauseList &);
	void end_visit(const ForwardAxis &);
	void end_visit(const ForwardStep &);
	void end_visit(const FunctionDecl &);
	void end_visit(const GeneralComp &);
	void end_visit(const ItemType &);
	void end_visit(const LetClause &);
	void end_visit(const LibraryModule &);
	void end_visit(const MainModule  &);
	void end_visit(const Module &);
	void end_visit(const ModuleDecl &);
	void end_visit(const ModuleImport &);
	void end_visit(const NameTest &);
	void end_visit(const NamespaceDecl &);
	void end_visit(const NodeComp &);
	void end_visit(const OccurrenceIndicator &);
	void end_visit(const OptionDecl &);
	void end_visit(const OrderByClause &);
	void end_visit(const OrderCollationSpec &);
	void end_visit(const OrderDirSpec &);
	void end_visit(const OrderEmptySpec &);
	void end_visit(const OrderModifier &);
	void end_visit(const OrderSpec &);
	void end_visit(const OrderSpecList &);
	void end_visit(const OrderingModeDecl &);
	void end_visit(const PITest &);
	void end_visit(const Param &);
	void end_visit(const ParamList &);
	void end_visit(const PositionalVar &);
	void end_visit(const Pragma &);
	void end_visit(const PragmaList &);
	void end_visit(const PredicateList &);
	void end_visit(const Prolog &);
	void end_visit(const QVarInDecl &);
	void end_visit(const QVarInDeclList &);
	void end_visit(const QuoteAttrValueContent &);
	void end_visit(const QuoteAttrContentList &);
	void end_visit(const ReverseAxis &);
	void end_visit(const ReverseStep &);
	void end_visit(const SIND_DeclList &);
	void end_visit(const SchemaAttributeTest &);
	void end_visit(const SchemaElementTest &);
	void end_visit(const SchemaImport &);
	void end_visit(const SchemaPrefix &);
	void end_visit(const SequenceType &);
	void end_visit(const SignList &);
	void end_visit(const SingleType &);
	void end_visit(const TextTest &);
	void end_visit(const TypeDeclaration &);
	void end_visit(const TypeName &);
	void end_visit(const URILiteralList &);
	void end_visit(const ValueComp &);
	void end_visit(const VarDecl &);
	void end_visit(const VarGetsDecl &);
	void end_visit(const VarGetsDeclList &);
	void end_visit(const VarInDecl &);
	void end_visit(const VarInDeclList &);
	void end_visit(const VersionDecl &);
	void end_visit(const VFO_DeclList &);
	void end_visit(const WhereClause &);
	void end_visit(const Wildcard &);

	void end_visit(const exprnode &);
	void end_visit(const AdditiveExpr &);
	void end_visit(const AndExpr &);
	void end_visit(const AxisStep &);
	void end_visit(const CDataSection &);
	void end_visit(const CastExpr &);
	void end_visit(const CastableExpr &);
	void end_visit(const CommonContent &);
	void end_visit(const ComparisonExpr &);
	void end_visit(const CompAttrConstructor &);
	void end_visit(const CompCommentConstructor &);
	void end_visit(const CompDocConstructor &);
	void end_visit(const CompElemConstructor &);
	void end_visit(const CompPIConstructor &);
	void end_visit(const CompTextConstructor &);
	void end_visit(const ContextItemExpr &);
	void end_visit(const DirCommentConstructor &);
	void end_visit(const DirElemConstructor &);
	void end_visit(const DirElemContent &);
	void end_visit(const DirPIConstructor &);
	void end_visit(const EnclosedExpr &);
	void end_visit(const Expr &);
    // void end_visit(const ExprSingle &);
	void end_visit(const ExtensionExpr &);
	void end_visit(const FLWORExpr &);
	void end_visit(const FilterExpr &);
	void end_visit(const FunctionCall &);
	void end_visit(const IfExpr &);
	void end_visit(const InstanceofExpr &);
	void end_visit(const IntersectExceptExpr &);
	void end_visit(const MultiplicativeExpr &);
	void end_visit(const NumericLiteral &);
	void end_visit(const OrExpr &);
	void end_visit(const OrderedExpr &);
	void end_visit(const ParenthesizedExpr &);
	void end_visit(const PathExpr &);
	void end_visit(const QuantifiedExpr &);
	void end_visit(const QueryBody &);
	void end_visit(const RangeExpr &);
	void end_visit(const RelativePathExpr &);
	void end_visit(const StringLiteral &);
	void end_visit(const TreatExpr &);
	void end_visit(const TypeswitchExpr &);
	void end_visit(const UnaryExpr &);
	void end_visit(const UnionExpr &);
	void end_visit(const UnorderedExpr &);
	void end_visit(const ValidateExpr &);
	void end_visit(const VarRef &);

/* update-related */
	void end_visit(const DeleteExpr &);
	void end_visit(const InsertExpr &);
	void end_visit(const RenameExpr &);
	void end_visit(const ReplaceExpr &);
	void end_visit(const RevalidationDecl &);
	void end_visit(const TransformExpr &);
	void end_visit(const VarNameList &);

/* full-text-related */
	void end_visit(const FTAnd &);
	void end_visit(const FTAnyallOption &);
	void end_visit(const FTBigUnit &);
	void end_visit(const FTCaseOption &);
	void end_visit(const FTContainsExpr &);
	void end_visit(const FTContent &);
	void end_visit(const FTDiacriticsOption &);
	void end_visit(const FTDistance &);
	void end_visit(const FTIgnoreOption &);
	void end_visit(const FTInclExclStringLiteral &);
	void end_visit(const FTInclExclStringLiteralList &);
	void end_visit(const FTLanguageOption &);
	void end_visit(const FTMatchOption &);
	void end_visit(const FTMatchOptionProximityList &);
	void end_visit(const FTMildnot &);
	void end_visit(const FTOptionDecl &);
	void end_visit(const FTOr &);
	void end_visit(const FTOrderedIndicator &);
	void end_visit(const FTProximity &);
	void end_visit(const FTRange &);
	void end_visit(const FTRefOrList &);
	void end_visit(const FTScope &);
	void end_visit(const FTScoreVar &);
	void end_visit(const FTSelection &);
	void end_visit(const FTStemOption &);
	void end_visit(const FTStopwordOption &);
	void end_visit(const FTStringLiteralList &);
	void end_visit(const FTThesaurusID &);
	void end_visit(const FTThesaurusList &);
	void end_visit(const FTThesaurusOption &);
	void end_visit(const FTTimes &);
	void end_visit(const FTUnaryNot &);
	void end_visit(const FTUnit &);
	void end_visit(const FTWildcardOption &);
	void end_visit(const FTWindow &);
	void end_visit(const FTWords &);
	void end_visit(const FTWordsSelection &);
	void end_visit(const FTWordsValue &);
    
};

} // namespace

#endif
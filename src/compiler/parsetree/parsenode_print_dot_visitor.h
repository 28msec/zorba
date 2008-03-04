#ifndef XQP_PARSENODE_PRINT_DOT_VISITOR_H
#define XQP_PARSENODE_PRINT_DOT_VISITOR_H

#include "compiler/parsetree/parsenode_visitor.h"

#include <iostream>
#include <ostream>
/*______________________________________________________________________
|  
|	 Design note: Visitor pattern.  See, for example:
|	 "Modern C++ Design" by Andrei Alexandrescu, Addison Wesley (const 2001),
|	 Chapter 10.
|_______________________________________________________________________*/

namespace xqp {

class ParseNodePrintDOTVisitor : public parsenode_visitor
{
    
#define INDENT  os << std::string(theIndent, ' ')
#define INDENT_INC  theIndent += 2
#define INDENT_DEC  theIndent -= 2
#define NL  os << std::endl


protected:
    int theIndent;
    std::ostream& os;

public:
    ParseNodePrintDOTVisitor(std::ostream &);
    void print(parsenode*);

public:
    /*..........................................
 	:  begin visit                            :
 	:.........................................*/
	void *begin_visit(const parsenode &);
	void *begin_visit(const AbbrevForwardStep &);
	void *begin_visit(const AnyKindTest &);
	void *begin_visit(const AposAttrContentList &);
	void *begin_visit(const AposAttrValueContent &);
	void *begin_visit(const ArgList &);
	void *begin_visit(const AtomicType &);
	void *begin_visit(const AttributeTest &);
	void *begin_visit(const BaseURIDecl &);
	void *begin_visit(const BoundarySpaceDecl &);
	void *begin_visit(const CaseClause &);
	void *begin_visit(const CaseClauseList &);
	void *begin_visit(const CommentTest &);
	void *begin_visit(const ConstructionDecl &);
	void *begin_visit(const CopyNamespacesDecl &);
	void *begin_visit(const DefaultCollationDecl &);
	void *begin_visit(const DefaultNamespaceDecl &);
	void *begin_visit(const DirAttr &);
	void *begin_visit(const DirAttributeList &);
	void *begin_visit(const DirAttributeValue &);
	void *begin_visit(const DirElemContentList &);
	void *begin_visit(const DocumentTest &);
	void *begin_visit(const ElementTest &);
	void *begin_visit(const EmptyOrderDecl &);
	void *begin_visit(const ForClause &);
//	void *begin_visit(const ForLetClause &);
	void *begin_visit(const ForLetClauseList &);
	void *begin_visit(const ForwardAxis &);
	void *begin_visit(const ForwardStep &);
	void *begin_visit(const FunctionDecl &);
	void *begin_visit(const GeneralComp &);
	void *begin_visit(const ItemType &);
	void *begin_visit(const LetClause &);
	void *begin_visit(const LibraryModule &);
	void *begin_visit(const MainModule  &);
	void *begin_visit(const Module &);
	void *begin_visit(const ModuleDecl &);
	void *begin_visit(const ModuleImport &);
	void *begin_visit(const NameTest &);
	void *begin_visit(const NamespaceDecl &);
	void *begin_visit(const NodeComp &);
	void *begin_visit(const OccurrenceIndicator &);
	void *begin_visit(const OptionDecl &);
	void *begin_visit(const OrderByClause &);
	void *begin_visit(const OrderCollationSpec &);
	void *begin_visit(const OrderDirSpec &);
	void *begin_visit(const OrderEmptySpec &);
	void *begin_visit(const OrderModifier &);
	void *begin_visit(const OrderSpec &);
	void *begin_visit(const OrderSpecList &);
	void *begin_visit(const OrderingModeDecl &);
	void *begin_visit(const PITest &);
	void *begin_visit(const Param &);
	void *begin_visit(const ParamList &);
	void *begin_visit(const PositionalVar &);
	void *begin_visit(const Pragma &);
	void *begin_visit(const PragmaList &);
	void *begin_visit(const PredicateList &);
	void *begin_visit(const Prolog &);
	void *begin_visit(const QVarInDecl &);
	void *begin_visit(const QVarInDeclList &);
	void *begin_visit(const QuoteAttrValueContent &);
	void *begin_visit(const QuoteAttrContentList &);
	void *begin_visit(const ReverseAxis &);
	void *begin_visit(const ReverseStep &);
	void *begin_visit(const SIND_DeclList &);
	void *begin_visit(const SchemaAttributeTest &);
	void *begin_visit(const SchemaElementTest &);
	void *begin_visit(const SchemaImport &);
	void *begin_visit(const SchemaPrefix &);
	void *begin_visit(const SequenceType &);
	void *begin_visit(const SignList &);
	void *begin_visit(const SingleType &);
	void *begin_visit(const TextTest &);
	void *begin_visit(const TypeDeclaration &);
	void *begin_visit(const TypeName &);
	void *begin_visit(const URILiteralList &);
	void *begin_visit(const ValueComp &);
	void *begin_visit(const VarDecl &);
	void *begin_visit(const VarGetsDecl &);
	void *begin_visit(const VarGetsDeclList &);
	void *begin_visit(const VarInDecl &);
	void *begin_visit(const VarInDeclList &);
	void *begin_visit(const VersionDecl &);
	void *begin_visit(const VFO_DeclList &);
	void *begin_visit(const WhereClause &);
	void *begin_visit(const Wildcard &);
  void *begin_visit(const QName &);

	void *begin_visit(const exprnode &);
	void *begin_visit(const AdditiveExpr &);
	void *begin_visit(const AndExpr &);
	void *begin_visit(const AxisStep &);
	void *begin_visit(const CDataSection &);
	void *begin_visit(const CastExpr &);
	void *begin_visit(const CastableExpr &);
	void *begin_visit(const CommonContent &);
	void *begin_visit(const ComparisonExpr &);
	void *begin_visit(const CompAttrConstructor &);
	void *begin_visit(const CompCommentConstructor &);
	void *begin_visit(const CompDocConstructor &);
	void *begin_visit(const CompElemConstructor &);
	void *begin_visit(const CompPIConstructor &);
	void *begin_visit(const CompTextConstructor &);
	void *begin_visit(const ContextItemExpr &);
	void *begin_visit(const DirCommentConstructor &);
	void *begin_visit(const DirElemConstructor &);
	void *begin_visit(const DirElemContent &);
	void *begin_visit(const DirPIConstructor &);
	void *begin_visit(const EnclosedExpr &);
	void *begin_visit(const Expr &);
    // void *begin_visit(const ExprSingle &);
	void *begin_visit(const ExtensionExpr &);
	void *begin_visit(const FLWORExpr &);
	void *begin_visit(const FilterExpr &);
	void *begin_visit(const FunctionCall &);
	void *begin_visit(const IfExpr &);
	void *begin_visit(const InstanceofExpr &);
	void *begin_visit(const IntersectExceptExpr &);
	void *begin_visit(const MultiplicativeExpr &);
	void *begin_visit(const NumericLiteral &);
	void *begin_visit(const OrExpr &);
	void *begin_visit(const OrderedExpr &);
	void *begin_visit(const ParenthesizedExpr &);
	void *begin_visit(const PathExpr &);
	void *begin_visit(const QuantifiedExpr &);
	void *begin_visit(const QueryBody &);
	void *begin_visit(const RangeExpr &);
	void *begin_visit(const RelativePathExpr &);
	void *begin_visit(const StringLiteral &);
	void *begin_visit(const TreatExpr &);
	void *begin_visit(const TypeswitchExpr &);
	void *begin_visit(const UnaryExpr &);
	void *begin_visit(const UnionExpr &);
	void *begin_visit(const UnorderedExpr &);
	void *begin_visit(const ValidateExpr &);
	void *begin_visit(const VarRef &);

/* update-related */
	void *begin_visit(const DeleteExpr &);
	void *begin_visit(const InsertExpr &);
	void *begin_visit(const RenameExpr &);
	void *begin_visit(const ReplaceExpr &);
	void *begin_visit(const RevalidationDecl &);
	void *begin_visit(const TransformExpr &);
	void *begin_visit(const VarNameList &);

/* try-catch-related */
  void *begin_visit(const TryExpr &);
  void *begin_visit(const CatchListExpr &);
  void *begin_visit(const CatchExpr &);

/* full-text-related */
	void *begin_visit(const FTAnd &);
	void *begin_visit(const FTAnyallOption &);
	void *begin_visit(const FTBigUnit &);
	void *begin_visit(const FTCaseOption &);
	void *begin_visit(const FTContainsExpr &);
	void *begin_visit(const FTContent &);
	void *begin_visit(const FTDiacriticsOption &);
	void *begin_visit(const FTDistance &);
	void *begin_visit(const FTIgnoreOption &);
	void *begin_visit(const FTInclExclStringLiteral &);
	void *begin_visit(const FTInclExclStringLiteralList &);
	void *begin_visit(const FTLanguageOption &);
	void *begin_visit(const FTMatchOption &);
	void *begin_visit(const FTMatchOptionProximityList &);
	void *begin_visit(const FTMildnot &);
	void *begin_visit(const FTOptionDecl &);
	void *begin_visit(const FTOr &);
	void *begin_visit(const FTOrderedIndicator &);
	void *begin_visit(const FTProximity &);
	void *begin_visit(const FTRange &);
	void *begin_visit(const FTRefOrList &);
	void *begin_visit(const FTScope &);
	void *begin_visit(const FTScoreVar &);
	void *begin_visit(const FTSelection &);
	void *begin_visit(const FTStemOption &);
	void *begin_visit(const FTStopwordOption &);
	void *begin_visit(const FTStringLiteralList &);
	void *begin_visit(const FTThesaurusID &);
	void *begin_visit(const FTThesaurusList &);
	void *begin_visit(const FTThesaurusOption &);
	void *begin_visit(const FTTimes &);
	void *begin_visit(const FTUnaryNot &);
	void *begin_visit(const FTUnit &);
	void *begin_visit(const FTWildcardOption &);
	void *begin_visit(const FTWindow &);
	void *begin_visit(const FTWords &);
	void *begin_visit(const FTWordsSelection &);
	void *begin_visit(const FTWordsValue &);

 /*..........................................
 	:  end visit                              :
 	:.........................................*/
	void end_visit(const parsenode &, void *visit_state);
	void end_visit(const AbbrevForwardStep &, void *visit_state);
	void end_visit(const AnyKindTest &, void *visit_state);
	void end_visit(const AposAttrContentList &, void *visit_state);
	void end_visit(const AposAttrValueContent &, void *visit_state);
	void end_visit(const ArgList &, void *visit_state);
	void end_visit(const AtomicType &, void *visit_state);
	void end_visit(const AttributeTest &, void *visit_state);
	void end_visit(const BaseURIDecl &, void *visit_state);
	void end_visit(const BoundarySpaceDecl &, void *visit_state);
	void end_visit(const CaseClause &, void *visit_state);
	void end_visit(const CaseClauseList &, void *visit_state);
	void end_visit(const CommentTest &, void *visit_state);
	void end_visit(const ConstructionDecl &, void *visit_state);
	void end_visit(const CopyNamespacesDecl &, void *visit_state);
	void end_visit(const DefaultCollationDecl &, void *visit_state);
	void end_visit(const DefaultNamespaceDecl &, void *visit_state);
	void end_visit(const DirAttr &, void *visit_state);
	void end_visit(const DirAttributeList &, void *visit_state);
	void end_visit(const DirAttributeValue &, void *visit_state);
	void end_visit(const DirElemContentList &, void *visit_state);
	void end_visit(const DocumentTest &, void *visit_state);
	void end_visit(const ElementTest &, void *visit_state);
	void end_visit(const EmptyOrderDecl &, void *visit_state);
	void end_visit(const ForClause &, void *visit_state);
    // void end_visit(const ForLetClause &, void *visit_state);
	void end_visit(const ForLetClauseList &, void *visit_state);
	void end_visit(const ForwardAxis &, void *visit_state);
	void end_visit(const ForwardStep &, void *visit_state);
	void end_visit(const FunctionDecl &, void *visit_state);
	void end_visit(const GeneralComp &, void *visit_state);
	void end_visit(const ItemType &, void *visit_state);
	void end_visit(const LetClause &, void *visit_state);
	void end_visit(const LibraryModule &, void *visit_state);
	void end_visit(const MainModule  &, void *visit_state);
	void end_visit(const Module &, void *visit_state);
	void end_visit(const ModuleDecl &, void *visit_state);
	void end_visit(const ModuleImport &, void *visit_state);
	void end_visit(const NameTest &, void *visit_state);
	void end_visit(const NamespaceDecl &, void *visit_state);
	void end_visit(const NodeComp &, void *visit_state);
	void end_visit(const OccurrenceIndicator &, void *visit_state);
	void end_visit(const OptionDecl &, void *visit_state);
	void end_visit(const OrderByClause &, void *visit_state);
	void end_visit(const OrderCollationSpec &, void *visit_state);
	void end_visit(const OrderDirSpec &, void *visit_state);
	void end_visit(const OrderEmptySpec &, void *visit_state);
	void end_visit(const OrderModifier &, void *visit_state);
	void end_visit(const OrderSpec &, void *visit_state);
	void end_visit(const OrderSpecList &, void *visit_state);
	void end_visit(const OrderingModeDecl &, void *visit_state);
	void end_visit(const PITest &, void *visit_state);
	void end_visit(const Param &, void *visit_state);
	void end_visit(const ParamList &, void *visit_state);
	void end_visit(const PositionalVar &, void *visit_state);
	void end_visit(const Pragma &, void *visit_state);
	void end_visit(const PragmaList &, void *visit_state);
	void end_visit(const PredicateList &, void *visit_state);
	void end_visit(const Prolog &, void *visit_state);
	void end_visit(const QVarInDecl &, void *visit_state);
	void end_visit(const QVarInDeclList &, void *visit_state);
	void end_visit(const QuoteAttrValueContent &, void *visit_state);
	void end_visit(const QuoteAttrContentList &, void *visit_state);
	void end_visit(const ReverseAxis &, void *visit_state);
	void end_visit(const ReverseStep &, void *visit_state);
	void end_visit(const SIND_DeclList &, void *visit_state);
	void end_visit(const SchemaAttributeTest &, void *visit_state);
	void end_visit(const SchemaElementTest &, void *visit_state);
	void end_visit(const SchemaImport &, void *visit_state);
	void end_visit(const SchemaPrefix &, void *visit_state);
	void end_visit(const SequenceType &, void *visit_state);
	void end_visit(const SignList &, void *visit_state);
	void end_visit(const SingleType &, void *visit_state);
	void end_visit(const TextTest &, void *visit_state);
	void end_visit(const TypeDeclaration &, void *visit_state);
	void end_visit(const TypeName &, void *visit_state);
	void end_visit(const URILiteralList &, void *visit_state);
	void end_visit(const ValueComp &, void *visit_state);
	void end_visit(const VarDecl &, void *visit_state);
	void end_visit(const VarGetsDecl &, void *visit_state);
	void end_visit(const VarGetsDeclList &, void *visit_state);
	void end_visit(const VarInDecl &, void *visit_state);
	void end_visit(const VarInDeclList &, void *visit_state);
	void end_visit(const VersionDecl &, void *visit_state);
	void end_visit(const VFO_DeclList &, void *visit_state);
	void end_visit(const WhereClause &, void *visit_state);
	void end_visit(const Wildcard &, void *visit_state);
  void end_visit(const QName &, void *visit_state);

	void end_visit(const exprnode &, void *visit_state);
	void end_visit(const AdditiveExpr &, void *visit_state);
	void end_visit(const AndExpr &, void *visit_state);
	void end_visit(const AxisStep &, void *visit_state);
	void end_visit(const CDataSection &, void *visit_state);
	void end_visit(const CastExpr &, void *visit_state);
	void end_visit(const CastableExpr &, void *visit_state);
	void end_visit(const CommonContent &, void *visit_state);
	void end_visit(const ComparisonExpr &, void *visit_state);
	void end_visit(const CompAttrConstructor &, void *visit_state);
	void end_visit(const CompCommentConstructor &, void *visit_state);
	void end_visit(const CompDocConstructor &, void *visit_state);
	void end_visit(const CompElemConstructor &, void *visit_state);
	void end_visit(const CompPIConstructor &, void *visit_state);
	void end_visit(const CompTextConstructor &, void *visit_state);
	void end_visit(const ContextItemExpr &, void *visit_state);
	void end_visit(const DirCommentConstructor &, void *visit_state);
	void end_visit(const DirElemConstructor &, void *visit_state);
	void end_visit(const DirElemContent &, void *visit_state);
	void end_visit(const DirPIConstructor &, void *visit_state);
	void end_visit(const EnclosedExpr &, void *visit_state);
	void end_visit(const Expr &, void *visit_state);
    // void end_visit(const ExprSingle &, void *visit_state);
	void end_visit(const ExtensionExpr &, void *visit_state);
	void end_visit(const FLWORExpr &, void *visit_state);
	void end_visit(const FilterExpr &, void *visit_state);
	void end_visit(const FunctionCall &, void *visit_state);
	void end_visit(const IfExpr &, void *visit_state);
	void end_visit(const InstanceofExpr &, void *visit_state);
	void end_visit(const IntersectExceptExpr &, void *visit_state);
	void end_visit(const MultiplicativeExpr &, void *visit_state);
	void end_visit(const NumericLiteral &, void *visit_state);
	void end_visit(const OrExpr &, void *visit_state);
	void end_visit(const OrderedExpr &, void *visit_state);
	void end_visit(const ParenthesizedExpr &, void *visit_state);
	void end_visit(const PathExpr &, void *visit_state);
	void end_visit(const QuantifiedExpr &, void *visit_state);
	void end_visit(const QueryBody &, void *visit_state);
	void end_visit(const RangeExpr &, void *visit_state);
	void end_visit(const RelativePathExpr &, void *visit_state);
	void end_visit(const StringLiteral &, void *visit_state);
	void end_visit(const TreatExpr &, void *visit_state);
	void end_visit(const TypeswitchExpr &, void *visit_state);
	void end_visit(const UnaryExpr &, void *visit_state);
	void end_visit(const UnionExpr &, void *visit_state);
	void end_visit(const UnorderedExpr &, void *visit_state);
	void end_visit(const ValidateExpr &, void *visit_state);
	void end_visit(const VarRef &, void *visit_state);

/* update-related */
	void end_visit(const DeleteExpr &, void *visit_state);
	void end_visit(const InsertExpr &, void *visit_state);
	void end_visit(const RenameExpr &, void *visit_state);
	void end_visit(const ReplaceExpr &, void *visit_state);
	void end_visit(const RevalidationDecl &, void *visit_state);
	void end_visit(const TransformExpr &, void *visit_state);
	void end_visit(const VarNameList &, void *visit_state);

/* try-catch-related */
  void end_visit(const TryExpr &, void *visit_state);
  void end_visit(const CatchListExpr &, void *visit_state);
  void end_visit(const CatchExpr &, void *visit_state);

/* full-text-related */
	void end_visit(const FTAnd &, void *visit_state);
	void end_visit(const FTAnyallOption &, void *visit_state);
	void end_visit(const FTBigUnit &, void *visit_state);
	void end_visit(const FTCaseOption &, void *visit_state);
	void end_visit(const FTContainsExpr &, void *visit_state);
	void end_visit(const FTContent &, void *visit_state);
	void end_visit(const FTDiacriticsOption &, void *visit_state);
	void end_visit(const FTDistance &, void *visit_state);
	void end_visit(const FTIgnoreOption &, void *visit_state);
	void end_visit(const FTInclExclStringLiteral &, void *visit_state);
	void end_visit(const FTInclExclStringLiteralList &, void *visit_state);
	void end_visit(const FTLanguageOption &, void *visit_state);
	void end_visit(const FTMatchOption &, void *visit_state);
	void end_visit(const FTMatchOptionProximityList &, void *visit_state);
	void end_visit(const FTMildnot &, void *visit_state);
	void end_visit(const FTOptionDecl &, void *visit_state);
	void end_visit(const FTOr &, void *visit_state);
	void end_visit(const FTOrderedIndicator &, void *visit_state);
	void end_visit(const FTProximity &, void *visit_state);
	void end_visit(const FTRange &, void *visit_state);
	void end_visit(const FTRefOrList &, void *visit_state);
	void end_visit(const FTScope &, void *visit_state);
	void end_visit(const FTScoreVar &, void *visit_state);
	void end_visit(const FTSelection &, void *visit_state);
	void end_visit(const FTStemOption &, void *visit_state);
	void end_visit(const FTStopwordOption &, void *visit_state);
	void end_visit(const FTStringLiteralList &, void *visit_state);
	void end_visit(const FTThesaurusID &, void *visit_state);
	void end_visit(const FTThesaurusList &, void *visit_state);
	void end_visit(const FTThesaurusOption &, void *visit_state);
	void end_visit(const FTTimes &, void *visit_state);
	void end_visit(const FTUnaryNot &, void *visit_state);
	void end_visit(const FTUnit &, void *visit_state);
	void end_visit(const FTWildcardOption &, void *visit_state);
	void end_visit(const FTWindow &, void *visit_state);
	void end_visit(const FTWords &, void *visit_state);
	void end_visit(const FTWordsSelection &, void *visit_state);
	void end_visit(const FTWordsValue &, void *visit_state);
    
};

} // namespace

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */

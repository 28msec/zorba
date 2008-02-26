#ifndef XQP_SHARED_TYPES_H
#define XQP_SHARED_TYPES_H

#include <zorba/config/platform.h>
#include <zorba/common/api_shared_types.h>

namespace xqp {

class QueryLoc;
class XQType;
class namespace_context;
class function;
class user_function;
class PlanIterator;
class SimpleCollection;
class XmlTree;
class AnyUriItem;
class NodeItem;
class TempSeq;
class PUL;
class ItemFactory;
class Collection;
class StringPool;
class QNamePool;
class PlanState;
class XQueryCompiler;
class XQueryCompilerSubsystem;
class Rewriter;
class RewriterContext;

class context;
class static_context;
class dynamic_context;

// Parsenodes

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
class Wildcard; class QName;


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


// Expression nodes
class expr; class var_expr; class order_modifier; class flwor_expr;
class case_clause; class promote_expr; class typeswitch_expr;
class if_expr; class fo_expr; class ft_select_expr; class ft_contains_expr;
class instanceof_expr; class treat_expr; class castable_expr; class cast_expr;
class validate_expr; class extension_expr; class relpath_expr;
class axis_step_expr; class match_expr; class primary_expr; class const_expr;
class order_expr; class funcall_expr; class elem_expr; class doc_expr;
class attr_expr; class text_expr; class pi_expr; class function_def_expr;


typedef rchandle<expr> expr_t;
typedef rchandle<XQType> xqtref_t;
typedef rchandle<namespace_context> NamespaceContext_t;
typedef rchandle<PlanIterator> PlanIter_t;
typedef rchandle<SimpleCollection> SimpleCollection_t;
typedef rchandle<XmlTree> XmlTree_t;
typedef rchandle<AnyUriItem> AnyUriItem_t;
typedef rchandle<NodeItem> NodeItem_t;
typedef rchandle<TempSeq> TempSeq_t;
typedef rchandle<PUL> PUL_t;
typedef rchandle<Collection> Collection_t;

}

#endif /* XQP_SHARED_TYPES_H */
/* vim:set ts=2 sw=2: */

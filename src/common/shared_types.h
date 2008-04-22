#ifndef ZORBA_SHARED_TYPES_H
#define ZORBA_SHARED_TYPES_H

#include "common/config/platform.h"

#include "util/rchandle.h"

namespace zorba {
  namespace error {
    class ErrorManager;
    class ZorbaError;
  }
  
  namespace store {
    class CopyMode;
    class Item;
    typedef rchandle<Item> Item_t;
    class ItemIterator;
    typedef rchandle<ItemIterator> ItemIterator_t;
    class NodeItem;
    typedef rchandle<NodeItem> NodeItem_t;
    class TempSeq;
    typedef rchandle<TempSeq> TempSeq_t;
    class PUL;
    typedef rchandle<PUL> PUL_t;
    class ItemFactory;
    class Collection;
    typedef rchandle<Collection> Collection_t;
    class StringPool;
    class QNamePool;
    class SimpleCollection;
    typedef rchandle<SimpleCollection> SimpleCollection_t;
    class AnyUriItem;
    typedef rchandle<AnyUriItem> AnyUriItem_t;
    class XmlTree;
    typedef rchandle<XmlTree> XmlTree_t;
    class XmlNode;
    typedef rchandle<class XmlNode> XmlNode_t;
    class Store;
    class Timetravel;
    class Requester;
    class XmlLoader;
    class QueryContextContainer;
    class QueryContext;
    class BasicItemFactory;
    class XmlDataManager_Impl;
    class ElementNode;
    typedef rchandle<ElementNode> ElementNode_t;
    class AttributeNode;
    class NsBindingsContext;
    typedef rchandle<NsBindingsContext> NsBindingsContext_t;
    class QNameItemImpl;
    typedef rchandle<QNameItemImpl> QNameItem_t;
    class ConstrNodeVector;
    class NsBindingsContext;
    typedef rchandle<NsBindingsContext> NsBindingsContext_t;
    class ResultIteratorChainer;
    typedef rchandle<ResultIteratorChainer> ResultIteratorChainer_t;
    class Iterator;
    typedef rchandle<Iterator> Iterator_t;
  }

  namespace types {
    class TypeIdentifier; 
  };

class TypeManager;
class CollationCache;

class QueryLoc;
class XQType;
class namespace_context;
class function;
class user_function;
class PlanIterator;
class PlanState;
class XQueryCompiler;
class XQueryCompilerSubsystem;
class Rewriter;
class RewriterContext;
class NodeNameTest;

class context;
class static_context;
class dynamic_context;
class CompilerCB;
class PlanWrapper;

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
class TryExpr; class CatchListExpr; class CatchExpr;


class exprnode;
class AdditiveExpr; class AndExpr; class AxisStep; class FilterExpr; 
class CDataSection;
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
class case_clause; class promote_expr; class trycatch_expr; class eval_expr; class typeswitch_expr;
class if_expr; class fo_expr; class ft_select_expr; class ft_contains_expr;
class instanceof_expr; class treat_expr; class castable_expr; class cast_expr; class name_cast_expr;
class validate_expr; class extension_expr; class relpath_expr;
class axis_step_expr; class match_expr; class primary_expr; class const_expr;
class order_expr; class funcall_expr; class elem_expr; class doc_expr;
class attr_expr; class text_expr; class pi_expr; class function_def_expr;
class insert_expr; class delete_expr; class replace_expr; class rename_expr;
class transform_expr;

class XQPCollator;
class ItemVariableIterator;
typedef rchandle<ItemVariableIterator> ItemVariableIterator_t;

typedef rchandle<parsenode> parsenode_t;
typedef rchandle<expr> expr_t;
typedef const_rchandle<XQType> xqtref_t;
typedef rchandle<namespace_context> NamespaceContext_t;
typedef rchandle<PlanIterator> PlanIter_t;

typedef rchandle<NodeNameTest> NodeNameTest_t;
typedef rchandle<static_context> static_context_t;
typedef rchandle<CompilerCB> CompilerCB_t;
typedef rchandle<PlanWrapper> PlanWrapper_t;


/* datetime stuff */
class DateTime;
class Date;
class DayTimeDuration;
class Decimal;
class Duration;
class Time;
class TimeZone;
class YearMonthDuration;
class GYearMonth;
class GYear;
class GMonthDay;
class GDay;
class GMonth;
class xqpString;
class xqpStringStore;
typedef rchandle<xqpStringStore> xqpStringStore_t;
typedef rchandle<DateTime> DateTime_t;
typedef rchandle<Date> Date_t;
typedef rchandle<Time> Time_t;
typedef rchandle<TimeZone> TimeZone_t;
typedef rchandle<DayTimeDuration> DayTimeDuration_t;
typedef rchandle<YearMonthDuration> YearMonthDuration_t;
typedef rchandle<Duration> Duration_t;
typedef rchandle<GYearMonth> GYearMonth_t;
typedef rchandle<GYear> GYear_t;
typedef rchandle<GMonthDay> GMonthDay_t;
typedef rchandle<GDay> GDay_t;
typedef rchandle<GMonth> GMonth_t;


/* numerics */
template <class Object> class FloatImpl;
class Integer;

/* numerics */
typedef FloatImpl<double> Double;
typedef FloatImpl<float>  Float;

/* runtime */
class RuntimeCB;
class ForVarIterator;
typedef rchandle<ForVarIterator> ForVarIter_t;

class LetVarIterator;
typedef rchandle<LetVarIterator> LetVarIter_t;

/* api */
class serializer;

}

#endif /* ZORBA_SHARED_TYPES_H */
/* vim:set ts=2 sw=2: */

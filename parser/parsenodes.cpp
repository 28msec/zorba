/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: parsenodes.cpp,v 1.1.1.1 2006/11/06 08:42:18 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR FOundation.
 *
 */

#include "parsenodes.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <vector>
#include <assert.h>

#include "../util/rchandle.h"

using namespace std;
namespace xqp {



// [1] Module
// ----------
Module::Module()
{
}

Module::~Module()
{
}




// [2] VersionDecl
// ---------------
VersionDecl::VersionDecl()
{
}

VersionDecl::~VersionDecl()
{
}




// [3] MainModule
// --------------
MainModule::MainModule()
{
}

MainModule::~MainModule()
{
}




// [4] LibraryModule
// -----------------
LibraryModule::LibraryModule()
{
}

LibraryModule::~LibraryModule()
{
}




// [5] ModuleDecl
// --------------
ModuleDecl::ModuleDecl()
{
}

ModuleDecl::~ModuleDecl()
{
}




// [6] Prolog
// ----------
Prolog::Prolog()
{
}

Prolog::~Prolog()
{
}




// [6a] SIDN_DeclList
// ------------------
SIND_DeclList::SIND_DeclList()
{
}

SIND_DeclList::SIND_DeclList(
	SIND_Decl* sind_p)
{
	sind_p_vec.push_back(sind_p);
}

SIND_DeclList::~SIND_DeclList()
{
}




// [6b] VFO_DeclList
// -----------------
VFO_DeclList::VFO_DeclList()
{
}

VFO_DeclList::VFO_DeclList(
	VFO_Decl* vfo_p)
{
	vfo_p_vec.push_back(vfo_p);
}

VFO_DeclList::~VFO_DeclList()
{
}




// [6c] SIND_Decl
// --------------
SIND_Decl::SIND_Decl()
{
}

SIND_Decl::~SIND_Decl()
{
}




// [6d] VFO_Decl
// -------------
VFO_Decl::VFO_Decl()
{
}

VFO_Decl::~VFO_Decl()
{
}




// [7] Setter
// ----------
Setter::Setter()
{
}

Setter::~Setter()
{
}




// [8] Import
// ----------
Import::Import()
{
}

Import::~Import()
{
}




// [9] Separator
// -------------
// (Lexical rule)




// [10] NamespaceDecl
// ------------------
NamespaceDecl::NamespaceDecl()
:
	prefix(""),
	uri("")
{
}

NamespaceDecl::NamespaceDecl(
	string const& _prefix,
	string const& _uri)
:
	prefix(_prefix),
	uri(_uri)
{
}

NamespaceDecl::~NamespaceDecl()
{
}




// [11] BoundarySpaceDecl
// ----------------------
BoundarySpaceDecl::BoundarySpaceDecl()
{
}

BoundarySpaceDecl::BoundarySpaceDecl(
	boundaryspace_mode _mode)
:
	mode(_mode)
{
}

BoundarySpaceDecl::~BoundarySpaceDecl()
{
}




// [12] DefaultNamespaceDecl
// -------------------------
DefaultNamespaceDecl::DefaultNamespaceDecl()
:
	default_element_namespace_p(NULL),
	default_function_namespace_p(NULL)
{
}

DefaultNamespaceDecl::DefaultNamespaceDecl(
	string const* _default_element_namespace_p,
	string const* _default_function_namespace_p)
:
	default_element_namespace_p(_default_element_namespace_p),
	default_function_namespace_p(_default_function_namespace_p)
{
}

DefaultNamespaceDecl::~DefaultNamespaceDecl()
{
}




// [13] OptionDecl
// ---------------
OptionDecl::OptionDecl()
:
	name_p(NULL),
	val("")
{
}

OptionDecl::OptionDecl(
	QName const* _name_p,
	string const& _val)
:
	name_p(_name_p),
	val(_val)
{
}

OptionDecl::~OptionDecl()
{
}




// [14] OrderingModeDecl
// ---------------------
OrderingModeDecl::OrderingModeDecl()
:
	mode(unordered)
{
}

OrderingModeDecl::OrderingModeDecl(
	ordering_mode _mode)
:
	mode(_mode)
{
}

OrderingModeDecl::~OrderingModeDecl()
{
}
	



// [15] EmptyOrderDecl
// -------------------
EmptyOrderDecl::EmptyOrderDecl()
:
	mode(empty_least)
{
}
		
EmptyOrderDecl::EmptyOrderDecl(
	emptyorder_mode _mode)
:
	mode(_mode)
{
}

EmptyOrderDecl::~EmptyOrderDecl()
{
}
	



// [16] CopyNamespacesDecl
// -----------------------
CopyNamespacesDecl::CopyNamespacesDecl()
{
}

CopyNamespacesDecl::~CopyNamespacesDecl()
{
}




// [17] PreserveMode
// -----------------
PreserveMode::PreserveMode()
{
}

PreserveMode::~PreserveMode()
{
}




// [18] InheritMode
// ----------------
InheritMode::InheritMode()
{
}

InheritMode::~InheritMode()
{
}




// [19] DefaultCollationDecl
// -------------------------
DefaultCollationDecl::DefaultCollationDecl()
{
}

DefaultCollationDecl::~DefaultCollationDecl()
{
}




// [20] BaseURIDecl
// ----------------
BaseURIDecl::BaseURIDecl()
{
}

BaseURIDecl::~BaseURIDecl()
{
}




// [21] SchemaImport
// -----------------
SchemaImport::SchemaImport()
{
}

SchemaImport::~SchemaImport()
{
}




// [21a] URLLiteralList
// --------------------
URI_LITERALList::URI_LITERALList()
{
}

URI_LITERALList::~URI_LITERALList()
{
}




// [22] SchemaPrefix
// -----------------
SchemaPrefix::SchemaPrefix()
{
}

SchemaPrefix::~SchemaPrefix()
{
}




// [23] ModuleImport
// -----------------
ModuleImport::ModuleImport()
{
}

ModuleImport::~ModuleImport()
{
}




// [24] VarDecl
// ------------
VarDecl::VarDecl()
{
}

VarDecl::~VarDecl()
{
}




// [25] ConstructionDecl
// ---------------------
ConstructionDecl::ConstructionDecl()
{
}

ConstructionDecl::~ConstructionDecl()
{
}




// [26] FunctionDecl
// -----------------
FunctionDecl::FunctionDecl()
{
}

FunctionDecl::~FunctionDecl()
{
}




// [27] ParamList
// --------------
ParamList::ParamList()
{
}

ParamList::~ParamList()
{
}




// [28] Param
// ----------
Param::Param()
{
}

Param::~Param()
{
}




// [29] EnclosedExpr
// -----------------
EnclosedExpr::EnclosedExpr()
{
}

EnclosedExpr::~EnclosedExpr()
{
}




// [30] QueryBody
// --------------
QueryBody::QueryBody()
{
}

QueryBody::~QueryBody()
{
}




// [31] Expr
// ---------
Expr::Expr()
{
}

Expr::~Expr()
{
}




// [32] ExprSingle
// ---------------
ExprSingle::ExprSingle()
{
}

ExprSingle::~ExprSingle()
{
}




// [33] FLWORExpr
// --------------
FLWORExpr::FLWORExpr()
{
}

FLWORExpr::~FLWORExpr()
{
}




// [33a] ForLetClauseList
// ----------------------
ForLetClauseList::ForLetClauseList()
{
}

ForLetClauseList::~ForLetClauseList()
{
}




// [33b] ForLetClause
// ------------------
ForLetClause::ForLetClause()
{
}

ForLetClause::~ForLetClause()
{
}




// [34] ForClause
// --------------
ForClause::ForClause()
{
}

ForClause::~ForClause()
{
}




// [34a] VarInDeclList
// -------------------
VarInDeclList::VarInDeclList()
{
}

VarInDeclList::~VarInDeclList()
{
}




// [34b] VarInDecl
// ---------------
VarInDecl::VarInDecl()
{
}

VarInDecl::~VarInDecl()
{
}




// [35] PositionalVar
// ------------------
PositionalVar::PositionalVar()
{
}

PositionalVar::~PositionalVar()
{
}




// [36] LetClause
// --------------
LetClause::LetClause()
{
}

LetClause::~LetClause()
{
}




// [36a] VarGetsDeclList
// ---------------------
VarGetsDeclList::VarGetsDeclList()
{
}

VarGetsDeclList::~VarGetsDeclList()
{
}




// [36b] VarGetsDecl
// ------------------
VarGetsDecl::VarGetsDecl()
{
}

VarGetsDecl::~VarGetsDecl()
{
}




// [37] WhereClause
// ----------------
WhereClause::WhereClause()
{
}

WhereClause::~WhereClause()
{
}




// [38] OrderByClause
// ------------------
OrderByClause::OrderByClause()
{
}

OrderByClause::~OrderByClause()
{
}




// [39] OrderSpecList
// ------------------
OrderSpecList::OrderSpecList()
{
}

OrderSpecList::~OrderSpecList()
{
}




// [40] OrderSpec
// --------------
OrderSpec::OrderSpec()
{
}

OrderSpec::~OrderSpec()
{
}




// [41] OrderModifier
// ------------------
OrderModifier::OrderModifier()
{
}

OrderModifier::~OrderModifier()
{
}




// [41a] OrderDirSpec
// ------------------
OrderDirSpec::OrderDirSpec()
{
}

OrderDirSpec::~OrderDirSpec()
{
}

	


// [41b] OrderEmptySpec
// --------------------
OrderEmptySpec::OrderEmptySpec()
{
}

OrderEmptySpec::~OrderEmptySpec()
{
}




// [41c] OrderCollationSpec
// ------------------------
OrderCollationSpec::OrderCollationSpec()
{
}

OrderCollationSpec::~OrderCollationSpec()
{
}




// [42] QuantifiedExpr 	   
// -------------------
QuantifiedExpr::QuantifiedExpr()
{
}

QuantifiedExpr::~QuantifiedExpr()
{
}




// [42a] QVarInDeclList
// --------------------
QVarInDeclList::QVarInDeclList()
{
}

QVarInDeclList::~QVarInDeclList()
{
}




// [42b] QVarInDecl
// ----------------
QVarInDecl::QVarInDecl()
{
}

QVarInDecl::~QVarInDecl()
{
}




// [43] TypeswitchExpr
// -------------------
TypeswitchExpr::TypeswitchExpr()
{
}

TypeswitchExpr::~TypeswitchExpr()
{
}




// [43a] CaseClauseList
// --------------------
CaseClauseList::CaseClauseList()
{
}

CaseClauseList::~CaseClauseList()
{
}




// [44] CaseClause
// ---------------
CaseClause::CaseClause()
{
}

CaseClause::~CaseClause()
{
}




// [45] IfExpr
// -----------
IfExpr::IfExpr()
{
}

IfExpr::~IfExpr()
{
}




// [46] OrExpr
// -----------
OrExpr::OrExpr()
{
}

OrExpr::~OrExpr()
{
}




// [47] AndExpr
// ------------
AndExpr::AndExpr()
{
}

AndExpr::~AndExpr()
{
}




// [48] ComparisonExpr
// -------------------
ComparisonExpr::ComparisonExpr()
{
}

ComparisonExpr::~ComparisonExpr()
{
}




// [48a] ValueCompExpr
// -------------------
ValueCompExpr::ValueCompExpr()
{
}

ValueCompExpr::~ValueCompExpr()
{
}




// [48b] GeneralCompExpr
// ---------------------
GeneralCompExpr::GeneralCompExpr()
{
}

GeneralCompExpr::~GeneralCompExpr()
{
}




// [48c] NodeComp
// --------------
NodeCompExpr::NodeCompExpr()
{
}

NodeCompExpr::~NodeCompExpr()
{
}




// [49] RangeExpr
// --------------
RangeExpr::RangeExpr()
{
}

RangeExpr::~RangeExpr()
{
}




// [50] AdditiveExpr
// -----------------
AdditiveExpr::AdditiveExpr()
{
}

AdditiveExpr::~AdditiveExpr()
{
}




// [51] MultiplicativeExpr
// -----------------------
MultiplicativeExpr::MultiplicativeExpr()
{
}

MultiplicativeExpr::~MultiplicativeExpr()
{
}




// [52] UnionExpr
// --------------
UnionExpr::UnionExpr()
{
}

UnionExpr::~UnionExpr()
{
}




// [53] IntersectExceptExpr
// ------------------------
IntersectExceptExpr::IntersectExceptExpr()
{
}

IntersectExceptExpr::~IntersectExceptExpr()
{
}




// [54] InstanceofExpr
// -------------------
InstanceofExpr::InstanceofExpr()
{
}

InstanceofExpr::~InstanceofExpr()
{
}




// [55] TreatExpr
// --------------
TreatExpr::TreatExpr()
{
}

TreatExpr::~TreatExpr()
{
}




// [56] CastableExpr
// -----------------
CastableExpr::CastableExpr()
{
}

CastableExpr::~CastableExpr()
{
}




// [57] CastExpr 	   
// -------------
CastExpr::CastExpr()
{
}

CastExpr::~CastExpr()
{
}




// [58] UnaryExpr
// --------------
UnaryExpr::UnaryExpr()
{
}

UnaryExpr::~UnaryExpr()
{
}




// [58a] SignList
// --------------
SignList::SignList()
{
}

SignList::~SignList()
{
}




// [59] ValueExpr
// --------------
ValueExpr::ValueExpr()
{
}

ValueExpr::~ValueExpr()
{
}





// [60] GeneralComp
// ----------------
/* folded into [48b] */

// [61] ValueComp
// --------------
/* folded into [48a] */

// [62] NodeComp
// -------------
/* folded into [48c] */



// [63] ValidateExpr
// -----------------
ValidateExpr::ValidateExpr()
{
}

ValidateExpr::~ValidateExpr()
{
}




// [64] ExtensionExpr
// ------------------
ExtensionExpr::ExtensionExpr()
{
}

ExtensionExpr::~ExtensionExpr()
{
}




// [64a] PragmaList
// ----------------
PragmaList::PragmaList()
{
}

PragmaList::~PragmaList()
{
}




// [65] Pragma
// -----------
Pragma::Pragma()
{
}

Pragma::~Pragma()
{
}




// [66] PragmaContents
// -------------------
/* folded into [65] */



// [67] PathExpr
// -------------
PathExpr::PathExpr()
{
}

PathExpr::~PathExpr()
{
}




// [68] RelativePathExpr
// ---------------------
RelativePathExpr::RelativePathExpr()
{
}

RelativePathExpr::~RelativePathExpr()
{
}




// [69] StepExpr
// -------------
StepExpr::StepExpr()
{
}

StepExpr::~StepExpr()
{
}




// [70] AxisStep
// -------------
AxisStep::AxisStep()
{
}

AxisStep::~AxisStep()
{
}




// [71] ForwardStep
// ----------------
ForwardStep::ForwardStep()
{
}

ForwardStep::~ForwardStep()
{
}




// [72] ForwardAxis
// ----------------
ForwardAxis::ForwardAxis()
{
}

ForwardAxis::~ForwardAxis()
{
}




// [73] AbbrevForwardStep
// ----------------------
AbbrevForwardStep::AbbrevForwardStep()
{
}

AbbrevForwardStep::~AbbrevForwardStep()
{
}




// [74] ReverseStep
// ----------------
ReverseStep::ReverseStep()
{
}

ReverseStep::~ReverseStep()
{
}




// [75] ReverseAxis
// ----------------
ReverseAxis::ReverseAxis()
{
}

ReverseAxis::~ReverseAxis()
{
}




// [76] AbbrevReverseStep
// ----------------------
/* folded into [74] */


// [77] NodeTest
// -------------
NodeTest::NodeTest()
{
}

NodeTest::~NodeTest()
{
}


 

// [78] NameTest
// -------------
NameTest::NameTest()
{
}

NameTest::~NameTest()
{
}




// [79] Wildcard
// -------------
Wildcard::Wildcard()
{
}

Wildcard::~Wildcard()
{
}




// [80] FilterExpr
// ---------------
FilterExpr::FilterExpr()
{
}

FilterExpr::~FilterExpr()
{
}




// [81] PredicateList
// ------------------
PredicateList::PredicateList()
{
}

PredicateList::~PredicateList()
{
}




// [82] Predicate
// --------------
Predicate::Predicate()
{
}

Predicate::~Predicate()
{
}





// [83] PrimaryExpr
// ----------------
PrimaryExpr::PrimaryExpr()
{
}

PrimaryExpr::~PrimaryExpr()
{
}




// [84] Literal
// ------------
Literal::Literal()
{
}

Literal::~Literal()
{
}




// [85] NumericLiteral
// -------------------
NumericLiteral::NumericLiteral()
{
}

NumericLiteral::~NumericLiteral()
{
}




// [86] VarRef
// -----------
VarRef::VarRef()
{
}

VarRef::~VarRef()
{
}




// [87] ParenthesizedExpr
// ----------------------
ParenthesizedExpr::ParenthesizedExpr()
{
}

ParenthesizedExpr::~ParenthesizedExpr()
{
}




// [88] ContextItemExpr
// --------------------
ContextItemExpr::ContextItemExpr()
{
}

ContextItemExpr::~ContextItemExpr()
{
}




// [89] OrderedExpr
// ----------------
OrderedExpr::OrderedExpr()
{
}

OrderedExpr::~OrderedExpr()
{
}




// [90] UnorderedExpr
// ------------------
UnorderedExpr::UnorderedExpr()
{
}

UnorderedExpr::~UnorderedExpr()
{
}




// [91] FunctionCall
// -----------------
FunctionCall::FunctionCall()
{
}

FunctionCall::~FunctionCall()
{
}




// [91a] ArgList
// -------------
ArgList::ArgList()
{
}

ArgList::~ArgList()
{
}




// [92] Constructor
// ----------------
Constructor::Constructor()
{
}

Constructor::~Constructor()
{
}




// [93] DirectConstructor
// ----------------------
DirectConstructor::DirectConstructor()
{
}

DirectConstructor::~DirectConstructor()
{
}



 
// [94] DirElemConstructor
// -----------------------
DirElemConstructor::DirElemConstructor()
{
}

DirElemConstructor::~DirElemConstructor()
{
}




// [94a] DirElemContentList
// ------------------------
DirElemContentList::DirElemContentList()
{
}

DirElemContentList::~DirElemContentList()
{
}




// [95] DirAttributeList
// ---------------------
DirAttributeList::DirAttributeList()
{
}

DirAttributeList::~DirAttributeList()
{
}




// [95a] DirAttr
// -------------
DirAttr::DirAttr()
{
}

DirAttr::~DirAttr()
{
}




// [96] DirAttributeValue
// ----------------------
DirAttributeValue::DirAttributeValue()
{
}

DirAttributeValue::~DirAttributeValue()
{
}




// [96a] QuoteAttrContentList
// --------------------------
QuoteAttrContentList::QuoteAttrContentList()
{
}

QuoteAttrContentList::~QuoteAttrContentList()
{
}




// [96b] AposAttrContentList
// -------------------------
AposAttrContentList::AposAttrContentList()
{
}

AposAttrContentList::~AposAttrContentList()
{
}




// [97] QuotAttrValueContent
// -------------------------
QuoteAttrValueContent::QuoteAttrValueContent()
{
}

QuoteAttrValueContent::~QuoteAttrValueContent()
{
}




// [98] AposAttrValueContent
// -------------------------
AposAttrValueContent::AposAttrValueContent()
{
}

AposAttrValueContent::~AposAttrValueContent()
{
}




// [99] DirElemContent
// -------------------
DirElemContent::DirElemContent()
{
}

DirElemContent::~DirElemContent()
{
}




// [100] CommonContent
// -------------------
CommonContent::CommonContent()
{
}

CommonContent::~CommonContent()
{
}




// [101] DirCommentConstructor
// ---------------------------
DirCommentConstructor::DirCommentConstructor()
{
}

DirCommentConstructor::~DirCommentConstructor()
{
}




// [102] DirCommentContents
// ------------------------
/* lexical rule */


// [103] DirPIConstructor
// ----------------------
DirPIConstructor::DirPIConstructor()
{
}

DirPIConstructor::~DirPIConstructor()
{
}




// [104] DirPIContents
// -------------------
/* lexical rule */


// [105] CDataSection
// ------------------
CDataSection::CDataSection()
{
}

CDataSection::~CDataSection()
{
}




// [106] CDataSectionContents
// --------------------------
/* lexical rule */


// [107] ComputedConstructor
// -------------------------
ComputedConstructor::ComputedConstructor()
{
}

ComputedConstructor::~ComputedConstructor()
{
}




// [108] CompDocConstructor
// ------------------------
CompDocConstructor::CompDocConstructor()
{
}

CompDocConstructor::~CompDocConstructor()
{
}




// [109] CompElemConstructor
// -------------------------
CompElemConstructor::CompElemConstructor()
{
}

CompElemConstructor::~CompElemConstructor()
{
}




// [110] ContentExpr
// -----------------
ContentExpr::ContentExpr()
{
}

ContentExpr::~ContentExpr()
{
}




// [111] CompAttrConstructor
// -------------------------
CompAttrConstructor::CompAttrConstructor()
{
}

CompAttrConstructor::~CompAttrConstructor()
{
}




// [112] CompTextConstructor
// -------------------------
CompTextConstructor::CompTextConstructor()
{
}

CompTextConstructor::~CompTextConstructor()
{
}




// [113] CompCommentConstructor
// ----------------------------
CompCommentConstructor::CompCommentConstructor()
{
}

CompCommentConstructor::~CompCommentConstructor()
{
}




// [114] CompPIConstructor
// -----------------------
CompPIConstructor::CompPIConstructor()
{
}

CompPIConstructor::~CompPIConstructor()
{
}




// [115] SingleType
// ----------------
SingleType::SingleType()
{
}

SingleType::~SingleType()
{
}




// [116] TypeDeclaration
// ---------------------
TypeDeclaration::TypeDeclaration()
{
}

TypeDeclaration::~TypeDeclaration()
{
}




// [117] SequenceType : public parsenode
// ------------------
SequenceType::SequenceType()
{
}

SequenceType::~SequenceType()
{
}




// [118] OccurrenceIndicator
// -------------------------
OccurrenceIndicator::OccurrenceIndicator()
{
}

OccurrenceIndicator::~OccurrenceIndicator()
{
}




// [119] ItemType
// --------------
ItemType::ItemType()
{
}

ItemType::~ItemType()
{
}




// [120] AtomicType
// ----------------
AtomicType::AtomicType()
{
}

AtomicType::~AtomicType()
{
}




// [121] KindTest
// --------------
KindTest::KindTest()
{
}

KindTest::~KindTest()
{
}




// [122] AnyKindTest
// -----------------
AnyKindTest::AnyKindTest()
{
}

AnyKindTest::~AnyKindTest()
{
}


 

// [123] DocumentTest
// ------------------
DocumentTest::DocumentTest()
{
}

DocumentTest::~DocumentTest()
{
}




// [124] TextTest
// --------------
TextTest::TextTest()
{
}

TextTest::~TextTest()
{
}




// [125] CommentTest
// -----------------
CommentTest::CommentTest()
{
}

CommentTest::~CommentTest()
{
}


 

// [126] PITest
// ------------
PITest::PITest()
{
}

PITest::~PITest()
{
}




// [127] AttributeTest
// -------------------
AttributeTest::AttributeTest()
{
}

AttributeTest::~AttributeTest()
{
}




// [128] AttribNameOrWildcard
// --------------------------
AttribNameOrWildcard::AttribNameOrWildcard()
{
}

AttribNameOrWildcard::~AttribNameOrWildcard()
{
}




// [129] SchemaAttributeTest
// -------------------------
SchemaAttributeTest::SchemaAttributeTest()
{
}

SchemaAttributeTest::~SchemaAttributeTest()
{
}




// [130] AttributeDeclaration
// --------------------------
AttributeDeclaration::AttributeDeclaration()
{
}

AttributeDeclaration::~AttributeDeclaration()
{
}




// [131] ElementTest
// -----------------
ElementTest::ElementTest()
{
}

ElementTest::~ElementTest()
{
}




// [132] ElementNameOrWildcard
// ---------------------------
ElementNameOrWildcard::ElementNameOrWildcard()
{
}

ElementNameOrWildcard::~ElementNameOrWildcard()
{
}




// [133] SchemaElementTest
// -----------------------
SchemaElementTest::SchemaElementTest()
{
}

SchemaElementTest::~SchemaElementTest()
{
}




// [134] ElementDeclaration
// ------------------------
ElementDeclaration::ElementDeclaration()
{
}

ElementDeclaration::~ElementDeclaration()
{
}




// [135] AttributeName
// -------------------
AttributeName::AttributeName()
{
}

AttributeName::~AttributeName()
{
}




// [136] ElementName
// -----------------
ElementName::ElementName()
{
}

ElementName::~ElementName()
{
}




// [137] TypeName
// --------------
TypeName::TypeName()
{
}

TypeName::~TypeName()
{
}




/* lexical rules, see xquery.l */
/* --------------------------- */

// [138] IntegerLiteral
// [139] DecimalLiteral
// [140] DoubleLiteral
// [141] URILiteral 
// [142] StringLiteral
// [143] PITarget
// [144] VarName
// [145] ValidationMode
// [146] Digits
// [147] PredefinedEntityRef
// [148] CharRef
// [149] EscapeQuot
// [150] EscapeApos
// [151] ElementContentChar
// [152] QuotAttrContentChar
// [153] AposAttrContentChar
// [154] Comment
// [155] CommentContents

// [156] QName
// -----------
QName::QName()
{
}

QName::~QName()
{
}




// [157] NCName
// [158] S  (WS)
// [159] Char


}	/* namespace xqp */

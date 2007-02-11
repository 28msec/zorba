/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: normalize.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "parsenodes.h"
#include "../runtime/normalize_visitor.h"

using namespace std;
namespace xqp {

void AbbrevForwardStep::accept(normalize_visitor& v) { v.visit(*this); } 
void AnyKindTest::accept(normalize_visitor& v) { v.visit(*this); } 
void AposAttrContentList::accept(normalize_visitor& v) { v.visit(*this); } 
void AposAttrValueContent::accept(normalize_visitor& v) { v.visit(*this); } 
void ArgList::accept(normalize_visitor& v) { v.visit(*this); } 
void AtomicType::accept(normalize_visitor& v) { v.visit(*this); } 
void AttribNameOrWildcard::accept(normalize_visitor& v) { v.visit(*this); } 
void AttributeDeclaration::accept(normalize_visitor& v) { v.visit(*this); } 
void AttributeName::accept(normalize_visitor& v) { v.visit(*this); } 
void AttributeTest::accept(normalize_visitor& v) { v.visit(*this); } 
void BaseURIDecl::accept(normalize_visitor& v) { v.visit(*this); } 
void BoundarySpaceDecl::accept(normalize_visitor& v) { v.visit(*this); } 
void CaseClause::accept(normalize_visitor& v) { v.visit(*this); } 
void CaseClauseList::accept(normalize_visitor& v) { v.visit(*this); } 
void CommentTest::accept(normalize_visitor& v) { v.visit(*this); } 
void ConstructionDecl::accept(normalize_visitor& v) { v.visit(*this); } 
void CopyNamespacesDecl::accept(normalize_visitor& v) { v.visit(*this); } 
void DefaultCollationDecl::accept(normalize_visitor& v) { v.visit(*this); } 
void DefaultNamespaceDecl::accept(normalize_visitor& v) { v.visit(*this); } 
void DirAttr::accept(normalize_visitor& v) { v.visit(*this); } 
void DirAttributeList::accept(normalize_visitor& v) { v.visit(*this); } 
void DirAttributeValue::accept(normalize_visitor& v) { v.visit(*this); } 
void DirElemContentList::accept(normalize_visitor& v) { v.visit(*this); } 
void DocumentTest::accept(normalize_visitor& v) { v.visit(*this); } 
void ElementDeclaration::accept(normalize_visitor& v) { v.visit(*this); } 
void ElementName::accept(normalize_visitor& v) { v.visit(*this); } 
void ElementNameOrWildcard::accept(normalize_visitor& v) { v.visit(*this); } 
void ElementTest::accept(normalize_visitor& v) { v.visit(*this); } 
void EmptyOrderDecl::accept(normalize_visitor& v) { v.visit(*this); } 
void ForClause::accept(normalize_visitor& v) { v.visit(*this); } 
void ForLetClause::accept(normalize_visitor& v) { v.visit(*this); } 
void ForLetClauseList::accept(normalize_visitor& v) { v.visit(*this); } 
void ForwardAxis::accept(normalize_visitor& v) { v.visit(*this); } 
void ForwardStep::accept(normalize_visitor& v) { v.visit(*this); } 
void FunctionDecl::accept(normalize_visitor& v) { v.visit(*this); } 
void GeneralComp::accept(normalize_visitor& v) { v.visit(*this); } 
void Import::accept(normalize_visitor& v) { v.visit(*this); } 
void InheritMode::accept(normalize_visitor& v) { v.visit(*this); } 
void ItemType::accept(normalize_visitor& v) { v.visit(*this); } 
void KindTest::accept(normalize_visitor& v) { v.visit(*this); } 
void LetClause::accept(normalize_visitor& v) { v.visit(*this); } 
void LibraryModule::accept(normalize_visitor& v) { v.visit(*this); } 
void MainModule ::accept(normalize_visitor& v) { v.visit(*this); } 
void Module::accept(normalize_visitor& v) { v.visit(*this); } 
void ModuleDecl::accept(normalize_visitor& v) { v.visit(*this); } 
void ModuleImport::accept(normalize_visitor& v) { v.visit(*this); } 
void NameTest::accept(normalize_visitor& v) { v.visit(*this); } 
void NamespaceDecl::accept(normalize_visitor& v) { v.visit(*this); } 
void NodeComp::accept(normalize_visitor& v) { v.visit(*this); } 
void NodeTest::accept(normalize_visitor& v) { v.visit(*this); } 
void OccurrenceIndicator::accept(normalize_visitor& v) { v.visit(*this); } 
void OptionDecl::accept(normalize_visitor& v) { v.visit(*this); } 
void OrderByClause::accept(normalize_visitor& v) { v.visit(*this); } 
void OrderCollationSpec::accept(normalize_visitor& v) { v.visit(*this); } 
void OrderDirSpec::accept(normalize_visitor& v) { v.visit(*this); } 
void OrderEmptySpec::accept(normalize_visitor& v) { v.visit(*this); } 
void OrderModifier::accept(normalize_visitor& v) { v.visit(*this); } 
void OrderSpec::accept(normalize_visitor& v) { v.visit(*this); } 
void OrderSpecList::accept(normalize_visitor& v) { v.visit(*this); } 
void OrderingModeDecl::accept(normalize_visitor& v) { v.visit(*this); } 
void PITest::accept(normalize_visitor& v) { v.visit(*this); } 
void Param::accept(normalize_visitor& v) { v.visit(*this); } 
void ParamList::accept(normalize_visitor& v) { v.visit(*this); } 
void PositionalVar::accept(normalize_visitor& v) { v.visit(*this); } 
void Pragma::accept(normalize_visitor& v) { v.visit(*this); } 
void PragmaList::accept(normalize_visitor& v) { v.visit(*this); } 
void PredicateList::accept(normalize_visitor& v) { v.visit(*this); } 
void PreserveMode::accept(normalize_visitor& v) { v.visit(*this); } 
void Prolog::accept(normalize_visitor& v) { v.visit(*this); } 
void QVarInDecl::accept(normalize_visitor& v) { v.visit(*this); } 
void QVarInDeclList::accept(normalize_visitor& v) { v.visit(*this); } 
void QuoteAttrValueContent::accept(normalize_visitor& v) { v.visit(*this); } 
void QuoteAttrContentList::accept(normalize_visitor& v) { v.visit(*this); } 
void ReverseAxis::accept(normalize_visitor& v) { v.visit(*this); } 
void ReverseStep::accept(normalize_visitor& v) { v.visit(*this); } 
void SIND_Decl::accept(normalize_visitor& v) { v.visit(*this); } 
void SIND_DeclList::accept(normalize_visitor& v) { v.visit(*this); } 
void SchemaAttributeTest::accept(normalize_visitor& v) { v.visit(*this); } 
void SchemaElementTest::accept(normalize_visitor& v) { v.visit(*this); } 
void SchemaImport::accept(normalize_visitor& v) { v.visit(*this); } 
void SchemaPrefix::accept(normalize_visitor& v) { v.visit(*this); } 
void SequenceType::accept(normalize_visitor& v) { v.visit(*this); } 
void Setter::accept(normalize_visitor& v) { v.visit(*this); } 
void SignList::accept(normalize_visitor& v) { v.visit(*this); } 
void SingleType::accept(normalize_visitor& v) { v.visit(*this); } 
void TextTest::accept(normalize_visitor& v) { v.visit(*this); } 
void TypeDeclaration::accept(normalize_visitor& v) { v.visit(*this); } 
void TypeName::accept(normalize_visitor& v) { v.visit(*this); } 
void URILiteralList::accept(normalize_visitor& v) { v.visit(*this); } 
void ValueComp::accept(normalize_visitor& v) { v.visit(*this); } 
void VarDecl::accept(normalize_visitor& v) { v.visit(*this); } 
void VarGetsDecl::accept(normalize_visitor& v) { v.visit(*this); } 
void VarGetsDeclList::accept(normalize_visitor& v) { v.visit(*this); } 
void VarInDecl::accept(normalize_visitor& v) { v.visit(*this); } 
void VarInDeclList::accept(normalize_visitor& v) { v.visit(*this); } 
void VersionDecl::accept(normalize_visitor& v) { v.visit(*this); } 
void VFO_Decl::accept(normalize_visitor& v) { v.visit(*this); } 
void VFO_DeclList::accept(normalize_visitor& v) { v.visit(*this); } 
void WhereClause::accept(normalize_visitor& v) { v.visit(*this); } 
void Wildcard::accept(normalize_visitor& v) { v.visit(*this); } 


/* left-hand sides: expressions */
/* ---------------------------- */
void AdditiveExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void AndExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void AxisStep::accept(normalize_visitor& v) { v.visit(*this); } 
void CDataSection::accept(normalize_visitor& v) { v.visit(*this); } 
void CastExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void CastableExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void CommonContent::accept(normalize_visitor& v) { v.visit(*this); } 
void ComparisonExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void CompAttrConstructor::accept(normalize_visitor& v) { v.visit(*this); } 
void CompCommentConstructor::accept(normalize_visitor& v) { v.visit(*this); } 
void CompDocConstructor::accept(normalize_visitor& v) { v.visit(*this); } 
void CompElemConstructor::accept(normalize_visitor& v) { v.visit(*this); } 
void CompPIConstructor::accept(normalize_visitor& v) { v.visit(*this); } 
void CompTextConstructor::accept(normalize_visitor& v) { v.visit(*this); } 
void ComputedConstructor::accept(normalize_visitor& v) { v.visit(*this); } 
void Constructor::accept(normalize_visitor& v) { v.visit(*this); } 
void ContextItemExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void DirCommentConstructor::accept(normalize_visitor& v) { v.visit(*this); } 
void DirElemConstructor::accept(normalize_visitor& v) { v.visit(*this); } 
void DirElemContent::accept(normalize_visitor& v) { v.visit(*this); } 
void DirPIConstructor::accept(normalize_visitor& v) { v.visit(*this); } 
void DirectConstructor::accept(normalize_visitor& v) { v.visit(*this); } 
void EnclosedExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void Expr::accept(normalize_visitor& v) { v.visit(*this); } 
void ExprSingle::accept(normalize_visitor& v) { v.visit(*this); } 
void ExtensionExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void FLWORExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void FilterExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void FunctionCall::accept(normalize_visitor& v) { v.visit(*this); } 
void IfExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void InstanceofExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void IntersectExceptExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void Literal::accept(normalize_visitor& v) { v.visit(*this); } 
void MultiplicativeExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void NumericLiteral::accept(normalize_visitor& v) { v.visit(*this); } 
void OrExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void OrderedExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void ParenthesizedExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void PathExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void Predicate::accept(normalize_visitor& v) { v.visit(*this); } 
void PrimaryExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void QuantifiedExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void QueryBody::accept(normalize_visitor& v) { v.visit(*this); } 
void RangeExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void RelativePathExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void StepExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void StringLiteral::accept(normalize_visitor& v) { v.visit(*this); } 
void TreatExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void TypeswitchExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void UnaryExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void UnionExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void UnorderedExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void ValidateExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void ValueExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void VarRef::accept(normalize_visitor& v) { v.visit(*this); } 



/* update-related */
/* -------------- */
void DeleteExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void InsertExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void RenameExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void ReplaceExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void RevalidationDecl::accept(normalize_visitor& v) { v.visit(*this); } 
void TransformExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void VarNameList::accept(normalize_visitor& v) { v.visit(*this); } 



/* full-text-related */
/* ----------------- */
void FTAnd::accept(normalize_visitor& v) { v.visit(*this); } 
void FTAnyallOption::accept(normalize_visitor& v) { v.visit(*this); } 
void FTBigUnit::accept(normalize_visitor& v) { v.visit(*this); } 
void FTCaseOption::accept(normalize_visitor& v) { v.visit(*this); } 
void FTContainsExpr::accept(normalize_visitor& v) { v.visit(*this); } 
void FTContent::accept(normalize_visitor& v) { v.visit(*this); } 
void FTDiacriticsOption::accept(normalize_visitor& v) { v.visit(*this); } 
void FTDistance::accept(normalize_visitor& v) { v.visit(*this); } 
void FTIgnoreOption::accept(normalize_visitor& v) { v.visit(*this); } 
void FTInclExclStringLiteral::accept(normalize_visitor& v) { v.visit(*this); } 
void FTInclExclStringLiteralList::accept(normalize_visitor& v) { v.visit(*this); } 
void FTLanguageOption::accept(normalize_visitor& v) { v.visit(*this); } 
void FTMatchOption::accept(normalize_visitor& v) { v.visit(*this); } 
void FTMatchOptionProximityList::accept(normalize_visitor& v) { v.visit(*this); } 
void FTMildnot::accept(normalize_visitor& v) { v.visit(*this); } 
void FTOptionDecl::accept(normalize_visitor& v) { v.visit(*this); } 
void FTOr::accept(normalize_visitor& v) { v.visit(*this); } 
void FTOrderedIndicator::accept(normalize_visitor& v) { v.visit(*this); } 
void FTProximity::accept(normalize_visitor& v) { v.visit(*this); } 
void FTRange::accept(normalize_visitor& v) { v.visit(*this); } 
void FTRefOrList::accept(normalize_visitor& v) { v.visit(*this); } 
void FTScope::accept(normalize_visitor& v) { v.visit(*this); } 
void FTScoreVar::accept(normalize_visitor& v) { v.visit(*this); } 
void FTSelection::accept(normalize_visitor& v) { v.visit(*this); } 
void FTStemOption::accept(normalize_visitor& v) { v.visit(*this); } 
void FTStopwordOption::accept(normalize_visitor& v) { v.visit(*this); } 
void FTStringLiteralList::accept(normalize_visitor& v) { v.visit(*this); } 
void FTThesaurusID::accept(normalize_visitor& v) { v.visit(*this); } 
void FTThesaurusList::accept(normalize_visitor& v) { v.visit(*this); } 
void FTThesaurusOption::accept(normalize_visitor& v) { v.visit(*this); } 
void FTTimes::accept(normalize_visitor& v) { v.visit(*this); } 
void FTUnaryNot::accept(normalize_visitor& v) { v.visit(*this); } 
void FTUnit::accept(normalize_visitor& v) { v.visit(*this); } 
void FTWildcardOption::accept(normalize_visitor& v) { v.visit(*this); } 
void FTWindow::accept(normalize_visitor& v) { v.visit(*this); } 
void FTWords::accept(normalize_visitor& v) { v.visit(*this); } 
void FTWordsSelection::accept(normalize_visitor& v) { v.visit(*this); } 
void FTWordsValue::accept(normalize_visitor& v) { v.visit(*this); } 


} /* namespace xqp */


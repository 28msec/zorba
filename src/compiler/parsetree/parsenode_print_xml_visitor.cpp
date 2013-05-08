/*
 * Copyright 2006-2008 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "stdafx.h"

#include <ostream>

#include "types/typemanager.h"
#include "zorbatypes/integer.h"

#include "parsenode_print_xml_visitor.h"
#include "parsenode_visitor.h"

using namespace std;

namespace zorba {

#define INDENT  os << std::string(theIndent, ' ')
#define INDENT_INC  theIndent += 2
#define INDENT_DEC  theIndent -= 2
#define NL  os << std::endl

class ParseNodePrintXMLVisitor : public parsenode_visitor
{
protected:
  int            theIndent;
  std::ostream & os;

public:

ParseNodePrintXMLVisitor(std::ostream &aStream)
  :
  theIndent(0),
  os(aStream)
{
}


void print(const parsenode* p)
{
  os << "<?xml version='1.0' ?>" << std::endl;
  os << "<ParseNodeTree>" << std::endl;
  p->accept(*this);
  os << "</ParseNodeTree>" << std::endl;
}

#define IDS \
  " pos='" << n.get_location() << "' ptr='" << &n << "'"

#define BEGIN_TAG( cls )                        \
  void *begin_visit (const cls &n) {            \
    INDENT;                                     \
    os << "<" #cls << IDS << ">";               \
    INDENT_INC; NL;                             \
    return no_state;                            \
  }


#define NO_END_TAG( cls )                                     \
  void end_visit(const cls& /*n*/, void* /*visit_state*/) {}

#define END_TAG( cls ) \
  void end_visit(const cls& /*n*/, void* /*visit_state*/) {  \
    INDENT_DEC; INDENT;                                      \
    os << "</" #cls ">";                                     \
    NL;                                                      \
  }

#define BEGIN_END_TAG( cls )                    \
  BEGIN_TAG (cls)                               \
  END_TAG (cls)

void *begin_visit(const AbbrevForwardStep &n)
{
  INDENT;

  os << "<AbbrevForwardStep" << IDS;
  if (n.get_attr_bit ()) os << " attr='true'";
  os << ">";

  INDENT_INC; NL;
  return no_state;
}


void *begin_visit(const CaseClause &n)
{
  INDENT;

  os << "<CaseClause" << IDS << " var='" << n.get_varname () << "'";

  os << ">";

  INDENT_INC; NL;
  return no_state;
}


void *begin_visit(const DefaultNamespaceDecl &n)
{
    INDENT;

    os << "<DefaultNamespaceDecl mode='"
       << (n.get_mode () == ParseConstants::ns_element_default ? "element" : "function")
       << "' uri='" << n.get_default_namespace () << "'" << IDS;

    os << "/>";

    NL;
    return no_state;
}

NO_END_TAG (NamespaceDecl)

NO_END_TAG (DefaultNamespaceDecl)

void *begin_visit(const DirAttr &n)
{
    INDENT;

    os << "<DirAttr pos='" << n.get_location() << "' name='"
       << n.get_name()->get_qname() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC; NL;
    return no_state;
}

void *begin_visit(const ForwardAxis &n)
{
    INDENT;

    os << "<ForwardAxis" << IDS;
    os << " axis='" << ParseConstants::decode_axis_kind(n.get_axis()) << "'";
    os << ">";

    INDENT_INC; NL;
    return no_state;
}

void *begin_visit(const FunctionDecl &n)
{
    INDENT;

    os << "<FunctionDecl name='" << n.get_name()->get_qname() << "'" << IDS;

    os << ">";

    INDENT_INC; NL;
    return no_state;
}

void *begin_visit(const GeneralComp &n)
{
    INDENT;

    os << "<GeneralComp" << IDS;

    os << "/>";

    NL;

    return no_state;
}

NO_END_TAG (GeneralComp)

void *begin_visit(const MainModule  &n)
{
    INDENT;

    os << "<MainModule" << IDS;

    os << ">";

    INDENT_INC; NL;

    return no_state;
}

void *begin_visit(const ModuleDecl &n)
{
  INDENT;

  os << "<ModuleDecl" << IDS;
  os << " prefix='" << n.get_prefix() << "' "
     << "target_namespace='" << n.get_target_namespace() << "'";
  os << ">";

  INDENT_INC; NL;
  return no_state;
}

void *begin_visit(const ModuleImport &n)
{
  INDENT;

  os << "<ModuleImport" << IDS;
  os << " prefix='" << n.get_prefix() << "' "
     << "target_namespace='" << n.get_uri() << "'";
  os << ">";

  INDENT_INC; NL;
  return no_state;
}

void *begin_visit(const NameTest &n)
{
    INDENT;

    os << "<NameTest" << IDS;

    os << ">";

    INDENT_INC; NL;

    // Hack: visitor is broken, QName is never visited.
    // However fixing this would impact the translator.
    // So we "visit" here.
    if (n.getQName () != NULL) n.getQName ()->accept (*this);

    return no_state;
}

void *begin_visit(const NamespaceDecl &n)
{
    INDENT;

    os << "<NamespaceDecl prefix='" << n.get_prefix () << "' uri='" << n.get_uri () << "'" << IDS;

    os << "/>";

    INDENT_INC; NL;
    return no_state;
}

void *begin_visit(const NodeComp &n)
{
    INDENT;

    os << "<NodeComp" << IDS;

    os << "/>";

    NL;
    return no_state;
}

NO_END_TAG (NodeComp)

void *begin_visit(GroupByClause const& n)
{
    INDENT;

    os << "<GroupByClause" << IDS;

    os << ">";

    INDENT_INC; NL;
    return no_state;
}

void *begin_visit(GroupSpecList const& n)
{
    INDENT;

    os << "<GroupSpecList" << IDS;

    os << ">";

    INDENT_INC; NL;
    return no_state;
}

void *begin_visit(GroupSpec const& n)
{
    INDENT;

    os << "<GroupSpec" << IDS;

    os << ">";

    INDENT_INC; NL;
    return no_state;
}

void *begin_visit(GroupCollationSpec const& n)
{
    INDENT;

    os << "<GroupCollationSpec" << IDS;

    os << ">";

    INDENT_INC; NL;
    return no_state;
}


void *begin_visit(const Param &n)
{
    INDENT;

    os << "<Param name='" << n.get_name () << "'" << IDS;

    os << "/>";

    NL;
    return no_state;
}

NO_END_TAG (Param)

void *begin_visit(const SchemaImport &n)
{
#ifndef ZORBA_NO_XMLSCHEMA
    INDENT;

    os << "<SchemaImport" << IDS;

    os << ">";

    INDENT_INC; NL;
    return no_state;
#else
  throw XQUERY_EXCEPTION(err::XQST0009);
#endif
}

void *begin_visit (const URILiteralList &n)
{
  INDENT;

  os << "<URILiteralList" << IDS;

  os << ">";

  INDENT_INC; NL;

  for (ulong i = 0; i < n.size(); i++)
  {
    INDENT;
    os << "<URI>" << n [i] << "</URI>" << "\n";
  }

  return no_state;
}

void *begin_visit(const ValueComp &n)
{
    INDENT;

    os << "<ValueComp" << IDS;

    os << "/>";

    NL;
    return no_state;
}

NO_END_TAG (ValueComp)

void* begin_visit(const GlobalVarDecl &n)
{
    INDENT;

    os << "<VarDecl pos='" << n.get_location() << "' var='"
       << n.get_var_name()->get_qname() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC; NL;
    return no_state;
}


void* begin_visit(const LocalVarDecl &n)
{
    INDENT;

    os << "<LocalVarDecl pos='" << n.get_location() << "' var='"
       << n.get_var_name()->get_qname() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC; NL;
    return no_state;
}


void *begin_visit(const VarGetsDecl &n)
{
    INDENT;

    os << "<VarGetsDecl pos='" << n.get_location() << "' var='"
       << n.get_var_name()->get_qname() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC; NL;
    return no_state;
}

void *begin_visit(const VarInDecl &n)
{
    INDENT;

    os << "<VarInDecl pos='" << n.get_location() << "' var='"
       << n.get_var_name()->get_qname() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC; NL;
    return no_state;
}

void *begin_visit(const VersionDecl &n)
{
    INDENT;

    os << "<VersionDecl" << IDS;
    os << "version='" << n.get_version() << "' "
       << "encoding='" << n.get_encoding() << "' ";

    os << ">";

    INDENT_INC; NL;
    return no_state;
}

void *begin_visit(const QName &n)
{
  INDENT;

  os << "<QName name='" << n.get_qname () << "'" << IDS;

  os << "/>";

  NL;

  return no_state;
}

NO_END_TAG (QName)

void *begin_visit(const CommonContent &n)
{
    INDENT;

    os << "<CommonContent" << IDS;

    os << ">";

    NL;
    INDENT_INC;
    INDENT;
    os << "<Type>";
    switch (n.get_type())
    {
      case ParseConstants::cont_entity:
      {
        os << "entity";
        break;
      }
      case ParseConstants::cont_charref:
      {
        os << "charref";
        break;
      }
    	case ParseConstants::cont_escape_lbrace:
    	{
        os << "escaped lbrace";
        break;
    	}
    	case ParseConstants::cont_escape_rbrace:
  	  {
        os << "escaped rbrace";
        break;
  	  }
    	case ParseConstants::cont_expr:
    	{
        os << "expr";
        break;
    	}
    }
    os << "</Type>";
    INDENT_DEC;
    INDENT;

    INDENT_INC; NL;
    return no_state;
}

void *begin_visit(const ComparisonExpr &n)
{
    INDENT;

    os << "<ComparisonExpr" << IDS;

    os << ">";

    INDENT_INC; NL;

    // Hack: visitor does not visit

    return no_state;
}

void *begin_visit(const NumericLiteral &n)
{
    INDENT;

    os << "<NumericLiteral" << IDS << " type='"
       << ParseConstants::decode_numeric_type (n.get_type ()) << "' val='" << n.toString () << "'";

    os << "/>";

    NL;
    return no_state;
}

NO_END_TAG (NumericLiteral)

void *begin_visit(const PathExpr &n)
{
    INDENT;

    os << "<PathExpr type='" << ParseConstants::decode_pathtype_t(n.get_type()) << "' pos='" << n.get_location() << "'  "  << "ptr='" << &n << "'";

    os << ">";

    INDENT_INC; NL;
    return no_state;
}

void *begin_visit(const RelativePathExpr &n)
{
  INDENT;

  os << "<RelativePathExpr step_type='" << ParseConstants::decode_steptype_t(n.get_step_type()) << "' pos='" << n.get_location() << "'  "  << "ptr='" << &n << "'";

  os << ">";

  INDENT_INC; NL;
  return no_state;
}

END_TAG(RelativePathExpr)

void *begin_visit(const SimpleMapExpr &n)
{
  INDENT;

  os << "<SimpleMapExpr pos='" << n.get_location() << "'  "  << "ptr='" << &n << "'";

  os << ">";

  INDENT_INC; NL;
  return no_state;
}

END_TAG(SimpleMapExpr)

void *begin_visit(const TypeswitchExpr &n)
{
    INDENT;

    os << "<TypeswitchExpr" << IDS << " default-var='" << n.get_default_varname() << "'";

    os << ">";

    INDENT_INC; NL;
    return no_state;
}

void *begin_visit(const VarRef &n)
{
    INDENT;

    os << "<VarRef" << IDS << " var='" << n.get_name()->get_qname() << "'";

    os << "/>";

    NL;
    return no_state;
}

NO_END_TAG (VarRef)

void *begin_visit(const VarBinding &n)
{
    INDENT;

    os << "<VarBinding varname='" << n.get_varname()
       << "' npos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC; NL;
    return no_state;
}


void* begin_visit(const LiteralFunctionItem& n)
{
  INDENT;
  os << "<LiteralFunctionItem " << "arity=\"" << n.getArity() << "\" ";
  os << "' npos='" << n.get_location() << "' ptr='" << &n << "'";
  os << ">";
  INDENT_INC; NL;
  return no_state;
}

END_TAG(LiteralFunctionItem)

void* begin_visit(const InlineFunction& n)
{
  INDENT;
  os << "<InlineFunction ";
  os << "' npos='" << n.get_location() << "' ptr='" << &n << "'";
  os << ">";
  INDENT_INC; NL;
  return no_state;
}

END_TAG(InlineFunction)

void* begin_visit(const AnyFunctionTest& n)
{
  INDENT;
  os << "<AnyFunctionTest pos='" << n.get_location() << "'/>";
  NL;
  return 0;
}

void end_visit(const AnyFunctionTest& /*n*/, void* /*visit_state*/){}

void* begin_visit(const TypeList& n)
{
  INDENT;
  os << "<TypeList ";
  os << "pos='" << n.get_location() << "' ptr='" << &n << "'";
  os << ">";
  INDENT_INC; NL;
  return no_state;
}

END_TAG(TypeList)

void *begin_visit(const TypedFunctionTest& n)
{
  INDENT;
  os << "<TypedFunctionTest ";
  os << "pos='" << n.get_location() << "' ptr='" << &n << "'";
  os << ">";
  INDENT_INC; NL;
  return no_state;
}

END_TAG(TypedFunctionTest)


void *begin_visit(const DynamicFunctionInvocation& n)
{
  INDENT;
  os << "<DynamicFunctionInvocation ";
  os << "pos='" << n.get_location() << "' ptr='" << &n << "'";
  os << ">";
  INDENT_INC; NL;
  return no_state;
}

END_TAG(DynamicFunctionInvocation)


END_TAG (AbbrevForwardStep)
BEGIN_END_TAG (AdditiveExpr)
BEGIN_END_TAG (AndExpr)
BEGIN_END_TAG (AnnotationParsenode)
BEGIN_END_TAG (AnnotationListParsenode)
BEGIN_END_TAG (AnnotationLiteralListParsenode)
BEGIN_END_TAG (AnyKindTest)
BEGIN_END_TAG (AposAttrContentList)
BEGIN_END_TAG (AposAttrValueContent)
BEGIN_END_TAG (ArgList)
BEGIN_END_TAG (ArgumentPlaceholder)
BEGIN_END_TAG (GeneralizedAtomicType)
BEGIN_END_TAG (SimpleType)
BEGIN_END_TAG (AttributeTest)
BEGIN_END_TAG (AxisStep)
BEGIN_END_TAG (BaseURIDecl)
BEGIN_END_TAG (BlockBody)
BEGIN_END_TAG (ApplyExpr)
BEGIN_END_TAG (BoundarySpaceDecl)
END_TAG (CaseClause)
BEGIN_END_TAG (CaseClauseList)
BEGIN_END_TAG (CastableExpr)
BEGIN_END_TAG (CastExpr)
BEGIN_END_TAG (CatchExpr)
BEGIN_END_TAG (CatchListExpr)
BEGIN_END_TAG (CDataSection)
BEGIN_END_TAG (CommentTest)
END_TAG (CommonContent)
END_TAG (ComparisonExpr)
BEGIN_END_TAG (CompAttrConstructor)
BEGIN_END_TAG (CompCommentConstructor)
BEGIN_END_TAG (CompDocConstructor)
BEGIN_END_TAG (CompElemConstructor)
BEGIN_END_TAG (CompPIConstructor)
BEGIN_END_TAG (CompNamespaceConstructor)
BEGIN_END_TAG (CompTextConstructor)
BEGIN_END_TAG (ConstructionDecl)
BEGIN_END_TAG (ContextItemExpr)
BEGIN_END_TAG (CopyNamespacesDecl)
BEGIN_END_TAG (CountClause)
BEGIN_END_TAG (DefaultCollationDecl)
BEGIN_END_TAG (DeleteExpr)
END_TAG (DirAttr)
BEGIN_END_TAG (DirAttributeList)
BEGIN_END_TAG (DirAttributeValue)
BEGIN_END_TAG (DirCommentConstructor)
BEGIN_END_TAG (DirElemConstructor)
BEGIN_END_TAG (DirElemContent)
BEGIN_END_TAG (DirElemContentList)
BEGIN_END_TAG (DirPIConstructor)
BEGIN_END_TAG (DocumentTest)
BEGIN_END_TAG (ElementTest)
BEGIN_END_TAG (EmptyOrderDecl)
BEGIN_END_TAG (EnclosedExpr)
BEGIN_END_TAG (AssignExpr)
BEGIN_END_TAG (ExitExpr)
BEGIN_END_TAG (Expr)
BEGIN_TAG (exprnode)
BEGIN_END_TAG (ExtensionExpr)
BEGIN_END_TAG (FilterExpr)
BEGIN_END_TAG (FlowCtlStatement)
BEGIN_END_TAG (FLWORClauseList)
BEGIN_END_TAG (FLWORExpr)
BEGIN_END_TAG (FLWORWinCond)
BEGIN_END_TAG (ForClause)
END_TAG (ForwardAxis)
BEGIN_END_TAG (ForwardStep)
BEGIN_END_TAG (FunctionCall)
END_TAG (FunctionDecl)
END_TAG (GroupByClause)
END_TAG (GroupCollationSpec)
END_TAG (GroupSpec)
END_TAG (GroupSpecList)
BEGIN_END_TAG (IfExpr)
BEGIN_END_TAG (InsertExpr)
BEGIN_END_TAG (InstanceofExpr)
BEGIN_END_TAG (IntersectExceptExpr)
BEGIN_END_TAG (ItemType)
BEGIN_END_TAG (StructuredItemType)
BEGIN_END_TAG (LetClause)
BEGIN_END_TAG (LibraryModule)
BEGIN_END_TAG (Literal)
END_TAG (MainModule )
END_TAG (ModuleDecl)
END_TAG (ModuleImport)
BEGIN_END_TAG (MultiplicativeExpr)
END_TAG (NameTest)
BEGIN_END_TAG (OccurrenceIndicator)
BEGIN_END_TAG (OptionDecl)
BEGIN_END_TAG (OrderByClause)
BEGIN_END_TAG (OrderCollationSpec)
BEGIN_END_TAG (OrderDirSpec)
BEGIN_END_TAG (OrderedExpr)
BEGIN_END_TAG (OrderEmptySpec)
BEGIN_END_TAG (OrderingModeDecl)
BEGIN_END_TAG (OrderModifierPN)
BEGIN_END_TAG (OrderSpec)
BEGIN_END_TAG (OrderSpecList)
BEGIN_END_TAG (OrExpr)
BEGIN_END_TAG (ParamList)
BEGIN_END_TAG (ParenthesizedExpr)
BEGIN_END_TAG (ParseErrorNode)
BEGIN_TAG (parsenode)
END_TAG (PathExpr)
BEGIN_END_TAG (PITest)
BEGIN_END_TAG (PositionalVar)
BEGIN_END_TAG (Pragma)
BEGIN_END_TAG (PragmaList)
BEGIN_END_TAG (PredicateList)
BEGIN_END_TAG (Prolog)
BEGIN_END_TAG (QuantifiedExpr)
BEGIN_END_TAG (QueryBody)
BEGIN_END_TAG (QuoteAttrContentList)
BEGIN_END_TAG (QuoteAttrValueContent)
BEGIN_END_TAG (QVarInDecl)
BEGIN_END_TAG (QVarInDeclList)
BEGIN_END_TAG (RangeExpr)
BEGIN_END_TAG (RenameExpr)
BEGIN_END_TAG (ReplaceExpr)
BEGIN_END_TAG (RevalidationDecl)
BEGIN_END_TAG (ReverseAxis)
BEGIN_END_TAG (ReverseStep)
BEGIN_END_TAG (SchemaAttributeTest)
BEGIN_END_TAG (SchemaElementTest)
END_TAG (SchemaImport)
BEGIN_END_TAG (SchemaPrefix)
BEGIN_END_TAG (SequenceType)
BEGIN_END_TAG (SignList)
BEGIN_END_TAG (SIND_DeclList)
BEGIN_END_TAG (DecimalFormatNode)
BEGIN_END_TAG (SingleType)
BEGIN_END_TAG (StringLiteral)
BEGIN_END_TAG (BooleanLiteral)
BEGIN_END_TAG (NullLiteral)
BEGIN_END_TAG (StringConcatExpr)
BEGIN_END_TAG (TextTest)
BEGIN_END_TAG (NamespaceTest)
BEGIN_END_TAG (TransformExpr)
BEGIN_END_TAG (TreatExpr)
BEGIN_END_TAG (TryExpr)
BEGIN_END_TAG (TypeName)
BEGIN_END_TAG (SwitchExpr)
BEGIN_END_TAG (SwitchCaseClause)
BEGIN_END_TAG (SwitchCaseClauseList)
BEGIN_END_TAG (SwitchCaseOperandList)
END_TAG (TypeswitchExpr)
BEGIN_END_TAG (UnaryExpr)
BEGIN_END_TAG (UnionExpr)
BEGIN_END_TAG (UnorderedExpr)
END_TAG (URILiteralList)
BEGIN_END_TAG (ValidateExpr)
END_TAG (VarBinding)
BEGIN_END_TAG (CtxItemDecl)
BEGIN_END_TAG (CollectionDecl)
BEGIN_END_TAG (AST_IndexDecl)
BEGIN_END_TAG (IndexKeySpec)
BEGIN_END_TAG (IndexKeyList)
BEGIN_END_TAG (IntegrityConstraintDecl)
END_TAG (GlobalVarDecl)
END_TAG (LocalVarDecl)
END_TAG (VarGetsDecl)
BEGIN_END_TAG (VarGetsDeclList)
END_TAG (VarInDecl)
BEGIN_END_TAG (VarInDeclList)
BEGIN_END_TAG (CopyVarList)
END_TAG (VersionDecl)
BEGIN_END_TAG (VFO_DeclList)
BEGIN_END_TAG (WhereClause)
BEGIN_END_TAG (WhileExpr)
BEGIN_END_TAG (Wildcard)
BEGIN_END_TAG (WindowClause)
BEGIN_END_TAG (WindowVarDecl)
BEGIN_END_TAG (WindowVars)


////////// Full-text //////////////////////////////////////////////////////////

BEGIN_END_TAG( FTAnd )

void* begin_visit( FTAnyallOption const &n ) {
  INDENT;
  os  << "<FTAnyallOption" << IDS
      << " mode='" << ft_anyall_mode::string_of[ n.get_option() ] << "'"
      << "/>";
  NL;
  return no_state;
}
NO_END_TAG( FTAnyallOption )

void* begin_visit( FTBigUnit const &n ) {
  INDENT;
  os  << "<FTBigUnit" << IDS
      << " unit='" << ft_big_unit::string_of[ n.get_unit() ] << "'"
      << "/>";
  NL;
  return no_state;
}
NO_END_TAG( FTBigUnit )

void* begin_visit( FTCaseOption const &n ) {
  INDENT;
  os  << "<FTCaseOption" << IDS
      << " mode='" << ft_case_mode::string_of[ n.get_mode() ] << "'"
      << "/>";
  NL;
  return no_state;
}
NO_END_TAG( FTCaseOption )

BEGIN_END_TAG(FTContainsExpr)

void* begin_visit( FTContent const &n ) {
  INDENT;
  os  << "<FTContent" << IDS
      << " mode='" << ft_content_mode::string_of[ n.get_mode() ] << "'"
      << "/>";
  NL;
  return no_state;
}
NO_END_TAG( FTContent )

void* begin_visit( FTDiacriticsOption const &n ) {
  INDENT;
  os  << "<FTDiacriticsOption" << IDS
      << " mode='" << ft_diacritics_mode::string_of[ n.get_mode() ] << "'"
      << "/>";
  NL;
  return no_state;
}
NO_END_TAG( FTDiacriticsOption )

BEGIN_END_TAG( FTDistance )
BEGIN_END_TAG( FTExtensionOption )
BEGIN_END_TAG( FTExtensionSelection )
BEGIN_END_TAG( FTIgnoreOption )

void* begin_visit( FTLanguageOption const &n ) {
  INDENT;
  os  << "<FTLanguageOption" << IDS
      << " lang='" << n.get_language() << "'"
      << "/>";
  NL;
  return no_state;
}
NO_END_TAG(FTLanguageOption)

BEGIN_END_TAG( FTMatchOptions )
BEGIN_END_TAG( FTMildNot )
BEGIN_END_TAG( FTOptionDecl )
BEGIN_END_TAG( FTOr )
BEGIN_END_TAG( FTOrder )
BEGIN_END_TAG( FTPrimaryWithOptions )

void* begin_visit( FTRange const &n ) {
  INDENT;
  os  << "<FTRange" << IDS
      << " mode='" << ft_range_mode::string_of[ n.get_mode() ] << "'"
      << ">";
  INDENT_INC; NL;
  return no_state;
}
END_TAG( FTRange )

void* begin_visit( FTScope const &n ) {
  INDENT;
  os  << "<FTScope" << IDS
      << " scope='" << ft_scope::string_of[ n.get_scope() ] << "'"
      << ">";
  INDENT_INC; NL;
  return no_state;
}
END_TAG( FTScope )

void* begin_visit( FTScoreVar const &n ) {
  INDENT;
  os  << "<FTScoreVar" << IDS
      << " varname='" << n.get_var_name() << "'"
      << "/>";
  NL;
  return no_state;
}
NO_END_TAG( FTScoreVar )

BEGIN_END_TAG( FTSelection )

void* begin_visit( FTStemOption const &n ) {
  INDENT;
  os  << "<FTStemOption" << IDS
      << " mode='" << ft_stem_mode::string_of[ n.get_mode() ] << "'"
      << "/>";
  NL;
  return no_state;
}
NO_END_TAG( FTStemOption )

void* begin_visit( FTStopWordOption const &n ) {
  INDENT;
  os  << "<FTStopWordOption" << IDS
      << " mode='" << ft_stop_words_mode::string_of[ n.get_mode() ] << "'"
      << "/>";
  NL;
  return no_state;
}
NO_END_TAG( FTStopWordOption )

void* begin_visit( FTStopWords const &n ) {
  INDENT;
  os  << "<FTStopWords" << IDS
      << " uri='" << n.get_uri() << "'"
      << ">";
  INDENT_INC; NL;
  return no_state;
}
END_TAG( FTStopWords )

void* begin_visit( FTStopWordsInclExcl const &n ) {
  INDENT;
  os  << "<FTStopWordsInclExcl" << IDS
      << " mode='" << ft_stop_words_unex::string_of[ n.get_mode() ] << "'"
      << ">";
  INDENT_INC; NL;
  return no_state;
}
END_TAG( FTStopWordsInclExcl )

void* begin_visit( FTThesaurusID const &n ) {
  INDENT;
  os  << "<FTThesaurusID" << IDS
      << " uri='" << n.get_uri() << "'"
      << " relationship='" << n.get_relationship() << "'"
      << ">";
  INDENT_INC; NL;
  return no_state;
}
END_TAG( FTThesaurusID )

void* begin_visit( FTThesaurusOption const &n ) {
  INDENT;
  os  << "<FTThesaurusOption" << IDS
      << " includes-default='" << (n.includes_default() ? 'T' : 'F') << "'"
      << " no-thesaurus='" << (n.no_thesaurus() ? 'T' : 'F') << "'"
      << ">";
  INDENT_INC; NL;
  return no_state;
}
END_TAG( FTThesaurusOption )

BEGIN_END_TAG( FTTimes )
BEGIN_END_TAG( FTUnaryNot )

void* begin_visit( FTUnit const &n ) {
  INDENT;
  os  << "<FTUnit" << IDS
      << " unit='" << ft_unit::string_of[ n.get_unit() ] << "'"
      << "/>";
  NL;
  return no_state;
}
NO_END_TAG( FTUnit )

BEGIN_END_TAG( FTWeight )

void* begin_visit( FTWildCardOption const &n ) {
  INDENT;
  os  << "<FTWildCardOption" << IDS
      << " mode='" << ft_wild_card_mode::string_of[ n.get_mode() ] << "'"
      << "/>";
  NL;
  return no_state;
}
NO_END_TAG( FTWildCardOption )

BEGIN_END_TAG( FTWindow )
BEGIN_END_TAG( FTWords )
BEGIN_END_TAG( FTWordsTimes )
BEGIN_END_TAG( FTWordsValue )

////////// JSON ///////////////////////////////////////////////////////////////
BEGIN_END_TAG(JSONObjectLookup)

BEGIN_END_TAG(JSONArrayConstructor)

BEGIN_END_TAG(JSONObjectConstructor)

BEGIN_END_TAG(JSONDirectObjectConstructor)

BEGIN_END_TAG(JSONPairList)

BEGIN_END_TAG(JSONPairConstructor)

BEGIN_END_TAG(JSONObjectInsertExpr)

BEGIN_END_TAG(JSONArrayInsertExpr)

BEGIN_END_TAG(JSONArrayAppendExpr)

BEGIN_END_TAG(JSONDeleteExpr)

BEGIN_END_TAG(JSONReplaceExpr)

BEGIN_END_TAG(JSONRenameExpr)

void* begin_visit(const JSON_Test& n)
{
  INDENT;
  os << "<JSON_Test type=\"" << store::StoreConsts::toString(n.get_kind()) << "\"/>";
  INDENT_INC; NL;
  return no_state;
}

END_TAG(JSON_Test)

};



void print_parsetree_xml(ostream& os, const parsenode* p)
{
  ParseNodePrintXMLVisitor v (os);
  v.print (p);
}

} // end namespace
/* vim:set et sw=2 ts=2: */

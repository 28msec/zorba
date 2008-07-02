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
#include <ostream>
#include "compiler/parsetree/parsenode_print_xml_visitor.h"
#include "compiler/parsetree/parsenode_visitor.h"
#include "types/typemanager.h"

using namespace std;

namespace zorba {

#define INDENT  os << std::string(theIndent, ' ')
#define INDENT_INC  theIndent += 2
#define INDENT_DEC  theIndent -= 2
#define NL  os << std::endl


class ParseNodePrintXMLVisitor : public parsenode_visitor {

protected:
    int theIndent;
    std::ostream& os;

public:

ParseNodePrintXMLVisitor(std::ostream &aStream)
  : theIndent(0),
    os(aStream)
{
}


void print(const parsenode* p)
{
    os << "<?xml version='1.0'>" << std::endl;
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

BEGIN_TAG (parsenode)

void *begin_visit(const AbbrevForwardStep &n)
{
    INDENT;

    os << "<AbbrevForwardStep" << IDS;
    if (n.get_attr_bit ()) os << " attr='true'";
    os << ">";

    INDENT_INC; NL;
    return no_state;
}

BEGIN_TAG (AnyKindTest)

BEGIN_TAG (AposAttrContentList)

BEGIN_TAG (AposAttrValueContent)

BEGIN_TAG (ArgList)

BEGIN_TAG (AtomicType)

BEGIN_TAG (AttributeTest)

BEGIN_TAG (BaseURIDecl)

BEGIN_TAG (BoundarySpaceDecl)

void *begin_visit(const CaseClause &n)
{
    INDENT;

    os << "<CaseClause" << IDS << " var='" << n.get_varname () << "'";

    os << ">";

    INDENT_INC; NL;
    return no_state;
}

BEGIN_TAG (CaseClauseList)

BEGIN_TAG (CommentTest)

BEGIN_TAG (ConstructionDecl)

BEGIN_TAG (CopyNamespacesDecl)

BEGIN_TAG (DefaultCollationDecl)

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

BEGIN_TAG (DirAttributeList)

BEGIN_TAG (DirAttributeValue)

BEGIN_TAG (DirElemContentList)

BEGIN_TAG (DocumentTest)

BEGIN_TAG (ElementTest)

BEGIN_TAG (EmptyOrderDecl)

BEGIN_TAG (ForClause)

BEGIN_TAG (ForLetClauseList)

void *begin_visit(const ForwardAxis &n)
{
    INDENT;

    os << "<ForwardAxis" << IDS;
    os << " axis='" << ParseConstants::decode_fwd_axis (n.get_axis ()) << "'";
    os << ">";

    INDENT_INC; NL;
    return no_state;
}

BEGIN_TAG (ForwardStep)

void *begin_visit(const FunctionDecl &n)
{
    INDENT;

    os << "<FunctionDecl name='" << n.get_name ()->get_qname () << "'" << IDS;

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

BEGIN_TAG (ItemType)

BEGIN_TAG (LetClause)

BEGIN_TAG (LibraryModule)

void *begin_visit(const MainModule  &n)
{
    INDENT;

    os << "<MainModule" << IDS;

    os << ">";

    INDENT_INC; NL;

    return no_state;
}

BEGIN_TAG (Module)

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

END_TAG (NameTest)

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

BEGIN_TAG (OccurrenceIndicator)

BEGIN_TAG (OptionDecl)

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

void *begin_visit(LetClauseList const& n)
{
    INDENT;

    os << "<LetClauseList" << IDS;

    os << ">";

    INDENT_INC; NL;
    return no_state;
}

BEGIN_TAG (OrderByClause)

BEGIN_TAG (OrderCollationSpec)

BEGIN_TAG (OrderDirSpec)

BEGIN_TAG (OrderEmptySpec)

BEGIN_TAG (OrderModifier)

BEGIN_TAG (OrderSpec)

BEGIN_TAG (OrderSpecList)

BEGIN_TAG (OrderingModeDecl)

BEGIN_TAG (PITest)

void *begin_visit(const Param &n)
{
    INDENT;

    os << "<Param name='" << n.get_name () << "'" << IDS;

    os << "/>";

    NL;
    return no_state;
}

NO_END_TAG (Param)

BEGIN_TAG (ParamList)

BEGIN_TAG (PositionalVar)

BEGIN_TAG (Pragma)

BEGIN_TAG (PragmaList)

BEGIN_TAG (PredicateList)

BEGIN_TAG (Prolog)

BEGIN_TAG (QVarInDecl)

BEGIN_TAG (QVarInDeclList)

BEGIN_TAG (QuoteAttrValueContent)

BEGIN_TAG (QuoteAttrContentList)

BEGIN_TAG (ReverseAxis)

BEGIN_TAG (ReverseStep)

BEGIN_TAG (SIND_DeclList)

BEGIN_TAG (SchemaAttributeTest)

BEGIN_TAG (SchemaElementTest)

void *begin_visit(const SchemaImport &n)
{
#ifndef ZORBA_NO_XMLSCHEMA
    INDENT;

    os << "<SchemaImport" << IDS;

    os << ">";

    INDENT_INC; NL;
    return no_state;
#else
  ZORBA_ERROR(XQST0009);
  return no_state;
#endif
}

BEGIN_TAG (SchemaPrefix)

BEGIN_TAG (SequenceType)

BEGIN_TAG (SignList)

BEGIN_TAG (SingleType)

BEGIN_TAG (TextTest)

BEGIN_TAG (TypeDeclaration)

BEGIN_TAG (TypeName)

void *begin_visit (const URILiteralList &n)
{
    INDENT;

    os << "<URILiteralList" << IDS;

    os << ">";

    INDENT_INC; NL;
    
    for (int i = 0; i < n.size (); i++) {
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

void *begin_visit(const VarDecl &n)
{
    INDENT;

    os << "<VarDecl pos='" << n.get_location() << "' var='" << n.get_varname () << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC; NL;
    return no_state;
}

void *begin_visit(const VarGetsDecl &n)
{
    INDENT;

    os << "<VarGetsDecl pos='" << n.get_location() << "' var='" << n.get_varname () << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC; NL;
    return no_state;
}

BEGIN_TAG (VarGetsDeclList)

void *begin_visit(const VarInDecl &n)
{
    INDENT;

    os << "<VarInDecl pos='" << n.get_location() << "' var='" << n.get_varname () << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC; NL;
    return no_state;
}

BEGIN_TAG (VarInDeclList)

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

BEGIN_TAG (VFO_DeclList)

BEGIN_TAG (WhereClause)

void *begin_visit(const QName &n)
{
  INDENT;

  os << "<QName name='" << n.get_qname () << "'" << IDS;

  os << "/>";

  NL;

  return no_state;
}

NO_END_TAG (QName)

BEGIN_TAG (Wildcard)

BEGIN_TAG (exprnode)

BEGIN_TAG (AdditiveExpr)

BEGIN_TAG (AndExpr)

BEGIN_TAG (AxisStep)

BEGIN_TAG (CDataSection)

BEGIN_TAG (CastExpr)

BEGIN_TAG (CastableExpr)

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

BEGIN_TAG (CompAttrConstructor)

BEGIN_TAG (CompCommentConstructor)

BEGIN_TAG (CompDocConstructor)

BEGIN_TAG (CompElemConstructor)

BEGIN_TAG (CompPIConstructor)

BEGIN_TAG (CompTextConstructor)

BEGIN_TAG (ContextItemExpr)

BEGIN_TAG (DirCommentConstructor)

BEGIN_TAG (DirElemConstructor)

BEGIN_TAG (DirElemContent)

BEGIN_TAG (DirPIConstructor)

BEGIN_TAG (EnclosedExpr)

BEGIN_TAG (BlockBody)

BEGIN_TAG (Expr)

BEGIN_TAG (ExtensionExpr)

BEGIN_TAG (FLWORExpr)

BEGIN_TAG (FilterExpr)

BEGIN_TAG (FunctionCall)

BEGIN_TAG (IfExpr)

BEGIN_TAG (InstanceofExpr)

BEGIN_TAG (IntersectExceptExpr)

BEGIN_TAG (MultiplicativeExpr)

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

BEGIN_TAG (OrExpr)

BEGIN_TAG (OrderedExpr)

BEGIN_TAG (ParenthesizedExpr)

void *begin_visit(const PathExpr &n)
{
    INDENT;

    os << "<PathExpr pos='" << n.get_location() << "'  "  << "ptr='" << &n << "'";

    os << ">";

    INDENT_INC; NL;
    return no_state;
}

BEGIN_TAG (QuantifiedExpr)

BEGIN_TAG (QueryBody)

BEGIN_TAG (RangeExpr)

BEGIN_TAG (RelativePathExpr)

BEGIN_TAG (StringLiteral)

BEGIN_TAG (TreatExpr)

void *begin_visit(const TypeswitchExpr &n)
{
    INDENT;

    os << "<TypeswitchExpr" << IDS << " default-var='" << n.get_default_varname() << "'";

    os << ">";

    INDENT_INC; NL;
    return no_state;
}

BEGIN_TAG (UnaryExpr)

BEGIN_TAG (UnionExpr)

BEGIN_TAG (UnorderedExpr)

BEGIN_TAG (ValidateExpr)

void *begin_visit(const VarRef &n)
{
    INDENT;

    os << "<VarRef" << IDS << " var='" << n.get_varname () << "'";

    os << "/>";

    NL;
    return no_state;
}

NO_END_TAG (VarRef)

BEGIN_TAG (DeleteExpr)

BEGIN_TAG (InsertExpr)

BEGIN_TAG (RenameExpr)

BEGIN_TAG (ReplaceExpr)

BEGIN_TAG (RevalidationDecl)

BEGIN_TAG (TransformExpr)

BEGIN_TAG (VarNameList)

void *begin_visit(const VarBinding &n)
{
    INDENT;

    os << "<VarBinding varname='" << n.get_varname() 
       << "' npos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC; NL;
    return no_state;
}

BEGIN_TAG (TryExpr)

BEGIN_TAG (CatchListExpr)

BEGIN_TAG (CatchExpr)

BEGIN_TAG (EvalExpr)

BEGIN_TAG (FTAnd)

BEGIN_TAG (FTAnyallOption)

BEGIN_TAG (FTBigUnit)

BEGIN_TAG (FTCaseOption)

BEGIN_TAG (FTContainsExpr)

BEGIN_TAG (FTContent)

BEGIN_TAG (FTDiacriticsOption)

BEGIN_TAG (FTDistance)

BEGIN_TAG (FTIgnoreOption)

BEGIN_TAG (FTInclExclStringLiteral)

BEGIN_TAG (FTInclExclStringLiteralList)

BEGIN_TAG (FTLanguageOption)

BEGIN_TAG (FTMatchOption)

BEGIN_TAG (FTMatchOptionProximityList)

BEGIN_TAG (FTMildnot)

BEGIN_TAG (FTOptionDecl)

BEGIN_TAG (FTOr)

BEGIN_TAG (FTOrderedIndicator)

BEGIN_TAG (FTProximity)

BEGIN_TAG (FTRange)

BEGIN_TAG (FTRefOrList)

BEGIN_TAG (FTScope)

BEGIN_TAG (FTScoreVar)

BEGIN_TAG (FTSelection)

BEGIN_TAG (FTStemOption)

BEGIN_TAG (FTStopwordOption)

BEGIN_TAG (FTStringLiteralList)

BEGIN_TAG (FTThesaurusID)

BEGIN_TAG (FTThesaurusList)

BEGIN_TAG (FTThesaurusOption)

BEGIN_TAG (FTTimes)

BEGIN_TAG (FTUnaryNot)

BEGIN_TAG (FTUnit)

BEGIN_TAG (FTWildcardOption)

BEGIN_TAG (FTWindow)

BEGIN_TAG (FTWords)

BEGIN_TAG (FTWordsSelection)

BEGIN_TAG (FTWordsValue)

END_TAG (parsenode)

END_TAG (AbbrevForwardStep)

END_TAG (AnyKindTest)

END_TAG (AposAttrContentList)

END_TAG (AposAttrValueContent)

END_TAG (ArgList)

END_TAG (AtomicType)

END_TAG (AttributeTest)

END_TAG (BaseURIDecl)

END_TAG (BoundarySpaceDecl)

END_TAG (CaseClause)

END_TAG (CaseClauseList)

END_TAG (CommentTest)

END_TAG (ConstructionDecl)

END_TAG (CopyNamespacesDecl)

END_TAG (DefaultCollationDecl)

END_TAG (DirAttr)

END_TAG (DirAttributeList)

END_TAG (DirAttributeValue)

END_TAG (DirElemContentList)

END_TAG (DocumentTest)

END_TAG (ElementTest)

END_TAG (EmptyOrderDecl)

END_TAG (ForClause)

END_TAG (ForLetClauseList)

END_TAG (ForwardAxis)

END_TAG (ForwardStep)

END_TAG (FunctionDecl)

END_TAG (ItemType)

END_TAG (LetClause)

END_TAG (LibraryModule)

END_TAG (MainModule )

END_TAG (Module)

END_TAG (ModuleDecl)

END_TAG (ModuleImport)

END_TAG (OccurrenceIndicator)

END_TAG (OptionDecl)

END_TAG (GroupByClause )

END_TAG (GroupSpecList )

END_TAG (GroupSpec )

END_TAG (GroupCollationSpec )

END_TAG (LetClauseList )

END_TAG (OrderByClause)

END_TAG (OrderCollationSpec)

END_TAG (OrderDirSpec)

END_TAG (OrderEmptySpec)

END_TAG (OrderModifier)

END_TAG (OrderSpec)

END_TAG (OrderSpecList)

END_TAG (OrderingModeDecl)

END_TAG (PITest)

END_TAG (ParamList)

END_TAG (PositionalVar)

END_TAG (Pragma)

END_TAG (PragmaList)

END_TAG (PredicateList)

END_TAG (Prolog)

END_TAG (QVarInDecl)

END_TAG (QVarInDeclList)

END_TAG (QuoteAttrValueContent)

END_TAG (QuoteAttrContentList)

END_TAG (ReverseAxis)

END_TAG (ReverseStep)

END_TAG (SIND_DeclList)

END_TAG (SchemaAttributeTest)

END_TAG (SchemaElementTest)

END_TAG (SchemaImport)

END_TAG (SchemaPrefix)

END_TAG (SequenceType)

END_TAG (SignList)

END_TAG (SingleType)

END_TAG (TextTest)

END_TAG (TypeDeclaration)

END_TAG (TypeName)

END_TAG (URILiteralList)

END_TAG (VarDecl)

END_TAG (VarGetsDecl)

END_TAG (VarGetsDeclList)

END_TAG (VarInDecl)

END_TAG (VarInDeclList)

END_TAG (VersionDecl)

END_TAG (VFO_DeclList)

END_TAG (WhereClause)

END_TAG (Wildcard)

END_TAG (exprnode)

END_TAG (AdditiveExpr)

END_TAG (AndExpr)

END_TAG (AxisStep)

END_TAG (CDataSection)

END_TAG (CastExpr)

END_TAG (CastableExpr)

END_TAG (CommonContent)

END_TAG (ComparisonExpr)

END_TAG (CompAttrConstructor)

END_TAG (CompCommentConstructor)

END_TAG (CompDocConstructor)

END_TAG (CompElemConstructor)

END_TAG (CompPIConstructor)

END_TAG (CompTextConstructor)

END_TAG (ContextItemExpr)

END_TAG (DirCommentConstructor)

END_TAG (DirElemConstructor)

END_TAG (DirElemContent)

END_TAG (DirPIConstructor)

END_TAG (EnclosedExpr)

END_TAG (BlockBody)

END_TAG (Expr)

END_TAG (ExtensionExpr)

END_TAG (FLWORExpr)

END_TAG (FilterExpr)

END_TAG (FunctionCall)

END_TAG (IfExpr)

END_TAG (InstanceofExpr)

END_TAG (IntersectExceptExpr)

END_TAG (MultiplicativeExpr)

END_TAG (OrExpr)

END_TAG (OrderedExpr)

END_TAG (ParenthesizedExpr)

END_TAG (PathExpr)

END_TAG (QuantifiedExpr)

END_TAG (QueryBody)

END_TAG (RangeExpr)

END_TAG (RelativePathExpr)

END_TAG (StringLiteral)

END_TAG (TreatExpr)

END_TAG (TypeswitchExpr)

END_TAG (UnaryExpr)

END_TAG (UnionExpr)

END_TAG (UnorderedExpr)

END_TAG (ValidateExpr)

END_TAG (DeleteExpr)

END_TAG (InsertExpr)

END_TAG (RenameExpr)

END_TAG (ReplaceExpr)

END_TAG (RevalidationDecl)

END_TAG (TransformExpr)

END_TAG (VarNameList)

END_TAG (VarBinding)

END_TAG (TryExpr)

END_TAG (CatchListExpr)

END_TAG (CatchExpr)

END_TAG (EvalExpr)

END_TAG (FTAnd)

END_TAG (FTAnyallOption)

END_TAG (FTBigUnit)

END_TAG (FTCaseOption)

END_TAG (FTContainsExpr)

END_TAG (FTContent)

END_TAG (FTDiacriticsOption)

END_TAG (FTDistance)

END_TAG (FTIgnoreOption)

END_TAG (FTInclExclStringLiteral)

END_TAG (FTInclExclStringLiteralList)

END_TAG (FTLanguageOption)

END_TAG (FTMatchOption)

END_TAG (FTMatchOptionProximityList)

END_TAG (FTMildnot)

END_TAG (FTOptionDecl)

END_TAG (FTOr)

END_TAG (FTOrderedIndicator)

END_TAG (FTProximity)

END_TAG (FTRange)

END_TAG (FTRefOrList)

END_TAG (FTScope)

END_TAG (FTScoreVar)

END_TAG (FTSelection)

END_TAG (FTStemOption)

END_TAG (FTStopwordOption)

END_TAG (FTStringLiteralList)

END_TAG (FTThesaurusID)

END_TAG (FTThesaurusList)

END_TAG (FTThesaurusOption)

END_TAG (FTTimes)

END_TAG (FTUnaryNot)

END_TAG (FTUnit)

END_TAG (FTWildcardOption)

END_TAG (FTWindow)

END_TAG (FTWords)

END_TAG (FTWordsSelection)

END_TAG (FTWordsValue)

BEGIN_TAG (ExitExpr)
END_TAG (ExitExpr)

BEGIN_TAG (ParseErrorNode)
END_TAG (ParseErrorNode)

};

void print_parsetree_xml (ostream &os, const parsenode *p) {
  ParseNodePrintXMLVisitor v (os);
  v.print (p);
}

} // end namespace

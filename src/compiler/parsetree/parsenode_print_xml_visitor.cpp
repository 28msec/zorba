#include <ostream>
#include "compiler/parsetree/parsenodes.h"
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


void print(parsenode* p)
{
    os << "<?xml version='1.0'>" << std::endl;
    os << "<ParseNodeTree>" << std::endl;
    p->accept(*this);
    os << "</ParseNodeTree>" << std::endl;
}


void *begin_visit(const parsenode &n)
{
    INDENT;

    os << "<ParseNode pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const AbbrevForwardStep &n)
{
    INDENT;

    os << "<AbbrevForwardStep pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const AnyKindTest &n)
{
    INDENT;

    os << "<AnyKindTest pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const AposAttrContentList &n)
{
    INDENT;

    os << "<AposAttrContentList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const AposAttrValueContent &n)
{
    INDENT;

    os << "<AposAttrValueContent pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const ArgList &n)
{
    INDENT;

    os << "<ArgList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const AtomicType &n)
{
    INDENT;

    os << "<AtomicType pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const AttributeTest &n)
{
    INDENT;

    os << "<AttributeTest pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const BaseURIDecl &n)
{
    INDENT;

    os << "<BaseURIDecl pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const BoundarySpaceDecl &n)
{
    INDENT;

    os << "<BoundarySpaceDecl pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const CaseClause &n)
{
    INDENT;

    os << "<CaseClause pos='" << n.get_location() << "' ptr='" << &n << "' var='" << n.get_varname () << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const CaseClauseList &n)
{
    INDENT;

    os << "<CaseClauseList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const CommentTest &n)
{
    INDENT;

    os << "<CommentTest pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const ConstructionDecl &n)
{
    INDENT;

    os << "<ConstructionDecl pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const CopyNamespacesDecl &n)
{
    INDENT;

    os << "<CopyNamespacesDecl pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const DefaultCollationDecl &n)
{
    INDENT;

    os << "<DefaultCollationDecl pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const DefaultNamespaceDecl &n)
{
    INDENT;

    os << "<DefaultNamespaceDecl mode='" << n.get_mode () << "' uri='" << n.get_default_namespace () << "' pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << "/>";

    NL;
    return no_state;
}

void end_visit(const NamespaceDecl& /*n*/, void* /*visit_state*/)
{
}


void end_visit(const DefaultNamespaceDecl& /*n*/, void* /*visit_state*/)
{
}


void *begin_visit(const DirAttr &n)
{
    INDENT;

    os << "<DirAttr pos='" << n.get_location() << "' name='" 
       << n.get_name()->get_qname() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const DirAttributeList &n)
{
    INDENT;

    os << "<DirAttributeList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const DirAttributeValue &n)
{
    INDENT;

    os << "<DirAttributeValue pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const DirElemContentList &n)
{
    INDENT;

    os << "<DirElemContentList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const DocumentTest &n)
{
    INDENT;

    os << "<DocumentTest pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const ElementTest &n)
{
    INDENT;

    os << "<ElementTest pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const EmptyOrderDecl &n)
{
    INDENT;

    os << "<EmptyOrderDecl pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const ForClause &n)
{
    INDENT;

    os << "<ForClause pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


// bool
// begin_visit(const ForLetClause &n)
// {
//     INDENT;
//
//     os << "<MainModule pos='" << n.get_location() << "' ptr='" << &n << "'";
//
//     os << ">";
//
//     INDENT_INC;
//     NL;
//     return no_state;
// }


void *begin_visit(const ForLetClauseList &n)
{
    INDENT;

    os << "<ForLetClauseList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const ForwardAxis &n)
{
    INDENT;

    os << "<ForwardAxis pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const ForwardStep &n)
{
    INDENT;

    os << "<ForwardStep pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FunctionDecl &n)
{
    INDENT;

    os << "<FunctionDecl name='" << n.get_name ()->get_qname () << "' pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const GeneralComp &n)
{
    INDENT;

    os << "<GeneralComp pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << "/>";
    
    NL;

    return no_state;
}

void end_visit(const GeneralComp& /*n*/, void* /*visit_state*/)
{
}


void *begin_visit(const ItemType &n)
{
    INDENT;

    os << "<ItemType pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const LetClause &n)
{
    INDENT;

    os << "<LetClause pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const LibraryModule &n)
{
    INDENT;

    os << "<LibraryModule pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const MainModule  &n)
{
    INDENT;

    os << "<MainModule pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;

    return no_state;
}


void *begin_visit(const Module &n)
{
    INDENT;

    os << "<Module pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const ModuleDecl &n)
{
    INDENT;

    os << "<ModuleDecl pos='" << n.get_location() << "' ptr='" << &n << "'";
    os << " prefix='" << n.get_prefix() << "' "
       << "target_namespace='" << n.get_target_namespace() << "' ptr='" << &n << "'";
    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const ModuleImport &n)
{
    INDENT;

    os << "<ModuleImport pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const NameTest &n)
{
    INDENT;

    os << "<NameTest pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;

    // Hack: visitor is broken, QName is never visited.
    // However fixing this would impact the translator.
    // So we "visit" here.
    if (n.getQName () != NULL) n.getQName ()->accept (*this);
    
    return no_state;
}

void end_visit(const NameTest& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</NameTest>";
    NL;
}


void *begin_visit(const NamespaceDecl &n)
{
    INDENT;

    os << "<NamespaceDecl prefix='" << n.get_prefix () << "' uri='" << n.get_uri () << "' pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << "/>";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const NodeComp &n)
{
    INDENT;

    os << "<NodeComp pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << "/>";

    NL;
    return no_state;
}

void end_visit(const NodeComp& /*n*/, void* /*visit_state*/)
{
}


void *begin_visit(const OccurrenceIndicator &n)
{
    INDENT;

    os << "<OccurrenceIndicator pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const OptionDecl &n)
{
    INDENT;

    os << "<OptionDecl pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(GroupByClause const& n)
{
    INDENT;

    os << "<GroupByClause pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}

void *begin_visit(GroupSpecList const& n)
{
    INDENT;

    os << "<GroupSpecList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}

void *begin_visit(GroupSpec const& n)
{
    INDENT;

    os << "<GroupSpec pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}

void *begin_visit(GroupCollationSpec const& n)
{
    INDENT;

    os << "<GroupCollationSpec pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}

void *begin_visit(LetClauseList const& n)
{
    INDENT;

    os << "<LetClauseList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const OrderByClause &n)
{
    INDENT;

    os << "<OrderByClause pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const OrderCollationSpec &n)
{
    INDENT;

    os << "<OrderCollationSpec pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const OrderDirSpec &n)
{
    INDENT;

    os << "<OrderDirSpec pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const OrderEmptySpec &n)
{
    INDENT;

    os << "<OrderEmptySpec pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const OrderModifier &n)
{
    INDENT;

    os << "<OrderModifier pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const OrderSpec &n)
{
    INDENT;

    os << "<OrderSpec pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const OrderSpecList &n)
{
    INDENT;

    os << "<OrderSpecList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const OrderingModeDecl &n)
{
    INDENT;

    os << "<OrderingModeDecl pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const PITest &n)
{
    INDENT;

    os << "<PITest pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const Param &n)
{
    INDENT;

    os << "<Param name='" << n.get_name () << "' pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << "/>";

    NL;
    return no_state;
}


void end_visit(const Param& /*n*/, void* /*visit_state*/)
{
}


void *begin_visit(const ParamList &n)
{
    INDENT;

    os << "<ParamList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const PositionalVar &n)
{
    INDENT;

    os << "<PositionalVar pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const Pragma &n)
{
    INDENT;

    os << "<Pragma pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const PragmaList &n)
{
    INDENT;

    os << "<PragmaList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const PredicateList &n)
{
    INDENT;

    os << "<PredicateList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const Prolog &n)
{
    INDENT;

    os << "<Prolog pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const QVarInDecl &n)
{
    INDENT;

    os << "<QVarInDecl pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const QVarInDeclList &n)
{
    INDENT;

    os << "<QVarInDeclList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const QuoteAttrValueContent &n)
{
    INDENT;

    os << "<QuoteAttrValueContent pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const QuoteAttrContentList &n)
{
    INDENT;

    os << "<QuoteAttrContentList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const ReverseAxis &n)
{
    INDENT;

    os << "<ReverseAxis pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const ReverseStep &n)
{
    INDENT;

    os << "<ReverseStep pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const SIND_DeclList &n)
{
    INDENT;

    os << "<SIND_DeclList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const SchemaAttributeTest &n)
{
    INDENT;

    os << "<SchemaAttributeTest pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const SchemaElementTest &n)
{
    INDENT;

    os << "<SchemaElementTest pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const SchemaImport &n)
{
    INDENT;

    os << "<SchemaImport pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const SchemaPrefix &n)
{
    INDENT;

    os << "<SchemaPrefix pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const SequenceType &n)
{
    INDENT;

    os << "<SequenceType pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const SignList &n)
{
    INDENT;

    os << "<SignList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const SingleType &n)
{
    INDENT;

    os << "<SingleType pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const TextTest &n)
{
    INDENT;

    os << "<TextTest pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const TypeDeclaration &n)
{
    INDENT;

    os << "<TypeDeclaration pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const TypeName &n)
{
    INDENT;

    os << "<TypeName pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const URILiteralList &n)
{
    INDENT;

    os << "<URILiteralList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const ValueComp &n)
{
    INDENT;

    os << "<ValueComp pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << "/>";

    NL;
    return no_state;
}

void end_visit(const ValueComp& /*n*/, void* /*visit_state*/)
{
}


void *begin_visit(const VarDecl &n)
{
    INDENT;

    os << "<VarDecl pos='" << n.get_location() << "' var='" << n.get_varname () << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const VarGetsDecl &n)
{
    INDENT;

    os << "<VarGetsDecl pos='" << n.get_location() << "' var='" << n.get_varname () << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const VarGetsDeclList &n)
{
    INDENT;

    os << "<VarGetsDeclList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const VarInDecl &n)
{
    INDENT;

    os << "<VarInDecl pos='" << n.get_location() << "' var='" << n.get_varname () << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const VarInDeclList &n)
{
    INDENT;

    os << "<VarInDeclList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const VersionDecl &n)
{
    INDENT;

    os << "<VersionDecl pos='" << n.get_location() << "' ptr='" << &n << "'";
    os << "version='" << n.get_version() << "' "
       << "encoding='" << n.get_encoding() << "' ";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const VFO_DeclList &n)
{
    INDENT;

    os << "<VFO_DeclList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const WhereClause &n)
{
    INDENT;

    os << "<WhereClause pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const QName &n)
{
  INDENT;

  os << "<QName name='" << n.get_qname () << "' pos='" << n.get_location() << "' ptr='" << &n << "'";

  os << "/>";

  NL;

  return no_state;
}

void end_visit(const QName& /*n*/, void* /*visit_state*/)
{
}


void *begin_visit(const Wildcard &n)
{
    INDENT;

    os << "<Wildcard pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const exprnode &n)
{
    INDENT;

    os << "<exprnode pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const AdditiveExpr &n)
{
    INDENT;

    os << "<AdditiveExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const AndExpr &n)
{
    INDENT;

    os << "<AndExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const AxisStep &n)
{
    INDENT;

    os << "<AxisStep pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const CDataSection &n)
{
    INDENT;

    os << "<CDataSection pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const CastExpr &n)
{
    INDENT;

    os << "<CastExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const CastableExpr &n)
{
    INDENT;

    os << "<CastableExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const CommonContent &n)
{
    INDENT;

    os << "<CommonContent pos='" << n.get_location() << "' ptr='" << &n << "'";

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

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const ComparisonExpr &n)
{
    INDENT;

    os << "<ComparisonExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;

    // Hack: visitor does not visit

    return no_state;
}


void *begin_visit(const CompAttrConstructor &n)
{
    INDENT;

    os << "<CompAttrConstructor pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const CompCommentConstructor &n)
{
    INDENT;

    os << "<CompCommentConstructor pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const CompDocConstructor &n)
{
    INDENT;

    os << "<CompDocConstructor pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const CompElemConstructor &n)
{
    INDENT;

    os << "<CompElemConstructor pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const CompPIConstructor &n)
{
    INDENT;

    os << "<CompPIConstructor pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const CompTextConstructor &n)
{
    INDENT;

    os << "<CompTextConstructor pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const ContextItemExpr &n)
{
    INDENT;

    os << "<ContextItemExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const DirCommentConstructor &n)
{
    INDENT;

    os << "<DirCommentConstructor pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const DirElemConstructor &n)
{
    INDENT;

    os << "<DirElemConstructor pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const DirElemContent &n)
{
    INDENT;

    os << "<DirElemContent pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const DirPIConstructor &n)
{
    INDENT;

    os << "<DirPIConstructor pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const EnclosedExpr &n)
{
    INDENT;

    os << "<EnclosedExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const Expr &n)
{
    INDENT;

    os << "<Expr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


// bool
// begin_visit(const ExprSingle &n)
// {
//     INDENT;
//
//     os << "<MainModule pos='" << n.get_location() << "' ptr='" << &n << "'";
//
//     os << ">";
//
//     INDENT_INC;
//     NL;
//     return no_state;
// }


void *begin_visit(const ExtensionExpr &n)
{
    INDENT;

    os << "<ExtensionExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FLWORExpr &n)
{
    INDENT;

    os << "<FLWORExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FilterExpr &n)
{
    INDENT;

    os << "<FilterExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FunctionCall &n)
{
    INDENT;

    os << "<FunctionCall pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const IfExpr &n)
{
    INDENT;

    os << "<IfExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const InstanceofExpr &n)
{
    INDENT;

    os << "<InstanceofExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const IntersectExceptExpr &n)
{
    INDENT;

    os << "<IntersectExceptExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const MultiplicativeExpr &n)
{
    INDENT;

    os << "<MultiplicativeExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const NumericLiteral &n)
{
    INDENT;

    os << "<NumericLiteral pos='" << n.get_location() << "' ptr='" << &n << " type='" 
       << ParseConstants::decode_numeric_type (n.get_type ()) << "' val='" << n.toString () << "'";

    os << "/>";

    NL;
    return no_state;
}

void end_visit(const NumericLiteral& /*n*/, void* /*visit_state*/)
{
}


void *begin_visit(const OrExpr &n)
{
    INDENT;

    os << "<OrExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const OrderedExpr &n)
{
    INDENT;

    os << "<OrderedExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const ParenthesizedExpr &n)
{
    INDENT;

    os << "<ParenthesizedExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const PathExpr &n)
{
    INDENT;

    os << "<PathExpr pos='" << n.get_location() << "'  "  << "ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const QuantifiedExpr &n)
{
    INDENT;

    os << "<QuantifiedExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const QueryBody &n)
{
    INDENT;

    os << "<QueryBody pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const RangeExpr &n)
{
    INDENT;

    os << "<RangeExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const RelativePathExpr &n)
{
    INDENT;

    os << "<RelativePathExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const StringLiteral &n)
{
    INDENT;

    os << "<StringLiteral pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const TreatExpr &n)
{
    INDENT;

    os << "<TreatExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const TypeswitchExpr &n)
{
    INDENT;

    os << "<TypeswitchExpr pos='" << n.get_location() << "' ptr='" << &n << " default-var='" << n.get_default_varname() << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const UnaryExpr &n)
{
    INDENT;

    os << "<UnaryExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const UnionExpr &n)
{
    INDENT;

    os << "<UnionExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const UnorderedExpr &n)
{
    INDENT;

    os << "<UnorderedExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const ValidateExpr &n)
{
    INDENT;

    os << "<ValidateExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const VarRef &n)
{
    INDENT;

    os << "<VarRef pos='" << n.get_location() << "' ptr='" << &n << "' var='" << n.get_varname () << "'";

    os << "/>";

    NL;
    return no_state;
}


void end_visit(const VarRef& /*n*/, void* /*visit_state*/)
{
}


void *begin_visit(const DeleteExpr &n)
{
    INDENT;

    os << "<DeleteExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const InsertExpr &n)
{
    INDENT;

    os << "<InsertExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const RenameExpr &n)
{
    INDENT;

    os << "<RenameExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const ReplaceExpr &n)
{
    INDENT;

    os << "<ReplaceExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const RevalidationDecl &n)
{
    INDENT;

    os << "<RevalidationDecl pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const TransformExpr &n)
{
    INDENT;

    os << "<TransformExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const VarNameList &n)
{
    INDENT;

    os << "<VarNameList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const VarBinding &n)
{
    INDENT;

    os << "<VarBinding pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const TryExpr &n)
{
    INDENT;

    os << "<TryExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}

void *begin_visit(const CatchListExpr &n)
{
    INDENT;

    os << "<CatchListExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}

void *begin_visit(const CatchExpr &n)
{
    INDENT;

    os << "<CatchExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}

void *begin_visit(const FTAnd &n)
{
    INDENT;

    os << "<FTAnd pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTAnyallOption &n)
{
    INDENT;

    os << "<FTAnyallOption pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTBigUnit &n)
{
    INDENT;

    os << "<FTBigUnit pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTCaseOption &n)
{
    INDENT;

    os << "<FTCaseOption pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTContainsExpr &n)
{
    INDENT;

    os << "<FTContainsExpr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTContent &n)
{
    INDENT;

    os << "<FTContent pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTDiacriticsOption &n)
{
    INDENT;

    os << "<FTDiacriticsOption pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTDistance &n)
{
    INDENT;

    os << "<FTDistance pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTIgnoreOption &n)
{
    INDENT;

    os << "<FTIgnoreOption pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTInclExclStringLiteral &n)
{
    INDENT;

    os << "<FTInclExclStringLiteral pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTInclExclStringLiteralList &n)
{
    INDENT;

    os << "<FTInclExclStringLiteralList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTLanguageOption &n)
{
    INDENT;

    os << "<FTLanguageOption pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTMatchOption &n)
{
    INDENT;

    os << "<FTMatchOption pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTMatchOptionProximityList &n)
{
    INDENT;

    os << "<FTMatchOptionProximityList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTMildnot &n)
{
    INDENT;

    os << "<FTMildnot pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTOptionDecl &n)
{
    INDENT;

    os << "<FTOptionDecl pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTOr &n)
{
    INDENT;

    os << "<FTOr pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTOrderedIndicator &n)
{
    INDENT;

    os << "<FTOrderedIndicator pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTProximity &n)
{
    INDENT;

    os << "<FTProximity pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTRange &n)
{
    INDENT;

    os << "<FTRange pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTRefOrList &n)
{
    INDENT;

    os << "<FTRefOrList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTScope &n)
{
    INDENT;

    os << "<FTScope pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTScoreVar &n)
{
    INDENT;

    os << "<FTScoreVar pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTSelection &n)
{
    INDENT;

    os << "<FTSelection pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTStemOption &n)
{
    INDENT;

    os << "<FTStemOption pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTStopwordOption &n)
{
    INDENT;

    os << "<FTStopwordOption pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTStringLiteralList &n)
{
    INDENT;

    os << "<FTStringLiteralList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTThesaurusID &n)
{
    INDENT;

    os << "<FTThesaurusID pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTThesaurusList &n)
{
    INDENT;

    os << "<FTThesaurusList pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTThesaurusOption &n)
{
    INDENT;

    os << "<FTThesaurusOption pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTTimes &n)
{
    INDENT;

    os << "<FTTimes pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTUnaryNot &n)
{
    INDENT;

    os << "<FTUnaryNot pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTUnit &n)
{
    INDENT;

    os << "<FTUnit pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTWildcardOption &n)
{
    INDENT;

    os << "<FTWildcardOption pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTWindow &n)
{
    INDENT;

    os << "<FTWindow pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTWords &n)
{
    INDENT;

    os << "<FTWords pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTWordsSelection &n)
{
    INDENT;

    os << "<FTWordsSelection pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *begin_visit(const FTWordsValue &n)
{
    INDENT;

    os << "<FTWordsValue pos='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void end_visit(const parsenode& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</ParseNode>";
    NL;
}


void end_visit(const AbbrevForwardStep& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</AbbrevForwardStep>";
    NL;
}


void end_visit(const AnyKindTest& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</AnyKindTest>";
    NL;
}


void end_visit(const AposAttrContentList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</AposAttrContentList>";
    NL;
}


void end_visit(const AposAttrValueContent& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</AposAttrValueContent>";
    NL;
}


void end_visit(const ArgList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</ArgList>";
    NL;
}


void end_visit(const AtomicType& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</AtomicType>";
    NL;
}


void end_visit(const AttributeTest& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</AttributeTest>";
    NL;
}


void end_visit(const BaseURIDecl& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</BaseURIDecl>";
    NL;
}


void end_visit(const BoundarySpaceDecl& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</BoundarySpaceDecl>";
    NL;
}


void end_visit(const CaseClause& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</CaseClause>";
    NL;
}


void end_visit(const CaseClauseList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</CaseClauseList>";
    NL;
}


void end_visit(const CommentTest& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</CommentTest>";
    NL;
}


void end_visit(const ConstructionDecl& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</ConstructionDecl>";
    NL;
}


void end_visit(const CopyNamespacesDecl& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</CopyNamespacesDecl>";
    NL;
}


void end_visit(const DefaultCollationDecl& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</DefaultCollationDecl>";
    NL;
}


void end_visit(const DirAttr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</DirAttr>";
    NL;
}


void end_visit(const DirAttributeList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</DirAttributeList>";
    NL;
}


void end_visit(const DirAttributeValue& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</DirAttributeValue>";
    NL;
}


void end_visit(const DirElemContentList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</DirElemContentList>";
    NL;
}


void end_visit(const DocumentTest& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</DocumentTest>";
    NL;
}


void end_visit(const ElementTest& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</ElementTest>";
    NL;
}


void end_visit(const EmptyOrderDecl& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</EmptyOrderDecl>";
    NL;
}


void end_visit(const ForClause& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</ForClause>";
    NL;
}


// void
// end_visit(const ForLetClause& /*n*/, void* /*visit_state*/)
// {
//     INDENT_DEC;
//
//     INDENT;
//     os << "</MainModule>";
//     NL;
// }


void end_visit(const ForLetClauseList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</ForLetClauseList>";
    NL;
}


void end_visit(const ForwardAxis& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</ForwardAxis>";
    NL;
}


void end_visit(const ForwardStep& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</ForwardStep>";
    NL;
}


void end_visit(const FunctionDecl& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FunctionDecl>";
    NL;
}


void end_visit(const ItemType& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</ItemType>";
    NL;
}


void end_visit(const LetClause& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</LetClause>";
    NL;
}


void end_visit(const LibraryModule& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</LibraryModule>";
    NL;
}


void end_visit(const MainModule & /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</MainModule>";
    NL;
}


void end_visit(const Module& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</Module>";
    NL;
}


void end_visit(const ModuleDecl& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</ModuleDecl>";
    NL;
}


void end_visit(const ModuleImport& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</ModuleImport>";
    NL;
}


void end_visit(const OccurrenceIndicator& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</OccurrenceIndicator>";
    NL;
}


void end_visit(const OptionDecl& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</OptionDecl>";
    NL;
}

void end_visit(GroupByClause const&, void*)
{
    INDENT_DEC;

    INDENT;
    os << "</GroupByClause>";
    NL;
}

void end_visit(GroupSpecList const&, void*)
{
    INDENT_DEC;

    INDENT;
    os << "</GroupSpecList>";
    NL;
}

void end_visit(GroupSpec const&, void*)
{
    INDENT_DEC;

    INDENT;
    os << "</GroupSpec>";
    NL;
}

void end_visit(GroupCollationSpec const&, void*)
{
    INDENT_DEC;

    INDENT;
    os << "</GroupCollationSpec>";
    NL;
}

void end_visit(LetClauseList const&, void*)
{
    INDENT_DEC;

    INDENT;
    os << "</LetClauseList>";
    NL;
}


void end_visit(const OrderByClause& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</OrderByClause>";
    NL;
}


void end_visit(const OrderCollationSpec& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</OrderCollationSpec>";
    NL;
}


void end_visit(const OrderDirSpec& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</OrderDirSpec>";
    NL;
}


void end_visit(const OrderEmptySpec& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</OrderEmptySpec>";
    NL;
}


void end_visit(const OrderModifier& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</OrderModifier>";
    NL;
}


void end_visit(const OrderSpec& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</OrderSpec>";
    NL;
}


void end_visit(const OrderSpecList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</OrderSpecList>";
    NL;
}


void end_visit(const OrderingModeDecl& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</OrderingModeDecl>";
    NL;
}


void end_visit(const PITest& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</PITest>";
    NL;
}


void end_visit(const ParamList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</ParamList>";
    NL;
}


void end_visit(const PositionalVar& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</PositionalVar>";
    NL;
}


void end_visit(const Pragma& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</Pragma>";
    NL;
}


void end_visit(const PragmaList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</PragmaList>";
    NL;
}


void end_visit(const PredicateList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</PredicateList>";
    NL;
}


void end_visit(const Prolog& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</Prolog>";
    NL;
}


void end_visit(const QVarInDecl& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</QVarInDecl>";
    NL;
}


void end_visit(const QVarInDeclList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</QVarInDeclList>";
    NL;
}


void end_visit(const QuoteAttrValueContent& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</QuoteAttrValueContent>";
    NL;
}


void end_visit(const QuoteAttrContentList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</QuoteAttrContentList>";
    NL;
}


void end_visit(const ReverseAxis& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</ReverseAxis>";
    NL;
}


void end_visit(const ReverseStep& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</ReverseStep>";
    NL;
}


void end_visit(const SIND_DeclList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</SIND_DeclList>";
    NL;
}


void end_visit(const SchemaAttributeTest& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</SchemaAttributeTest>";
    NL;
}


void end_visit(const SchemaElementTest& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</SchemaElementTest>";
    NL;
}


void end_visit(const SchemaImport& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</SchemaImport>";
    NL;
}


void end_visit(const SchemaPrefix& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</SchemaPrefix>";
    NL;
}


void end_visit(const SequenceType& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</SequenceType>";
    NL;
}


void end_visit(const SignList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</SignList>";
    NL;
}


void end_visit(const SingleType& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</SingleType>";
    NL;
}


void end_visit(const TextTest& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</TextTest>";
    NL;
}


void end_visit(const TypeDeclaration& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</TypeDeclaration>";
    NL;
}


void end_visit(const TypeName& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</TypeName>";
    NL;
}


void end_visit(const URILiteralList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</URILiteralList>";
    NL;
}


void end_visit(const VarDecl& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</VarDecl>";
    NL;
}


void end_visit(const VarGetsDecl& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</VarGetsDecl>";
    NL;
}


void end_visit(const VarGetsDeclList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</VarGetsDeclList>";
    NL;
}


void end_visit(const VarInDecl& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</VarInDecl>";
    NL;
}


void end_visit(const VarInDeclList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</VarInDeclList>";
    NL;
}


void end_visit(const VersionDecl& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</VersionDecl>";
    NL;
}


void end_visit(const VFO_DeclList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</VFO_DeclList>";
    NL;
}


void end_visit(const WhereClause& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</WhereClause>";
    NL;
}


void end_visit(const Wildcard& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</Wildcard>";
    NL;
}


void end_visit(const exprnode& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</exprnode>";
    NL;
}


void end_visit(const AdditiveExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</AdditiveExpr>";
    NL;
}


void end_visit(const AndExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</AndExpr>";
    NL;
}


void end_visit(const AxisStep& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</AxisStep>";
    NL;
}


void end_visit(const CDataSection& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</CDataSection>";
    NL;
}


void end_visit(const CastExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</CastExpr>";
    NL;
}


void end_visit(const CastableExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</CastableExpr>";
    NL;
}


void end_visit(const CommonContent& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</CommonContent>";
    NL;
}


void end_visit(const ComparisonExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</ComparisonExpr>";
    NL;
}


void end_visit(const CompAttrConstructor& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</CompAttrConstructor>";
    NL;
}


void end_visit(const CompCommentConstructor& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</CompCommentConstructor>";
    NL;
}


void end_visit(const CompDocConstructor& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</CompDocConstructor>";
    NL;
}


void end_visit(const CompElemConstructor& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</CompElemConstructor>";
    NL;
}


void end_visit(const CompPIConstructor& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</CompPIConstructor>";
    NL;
}


void end_visit(const CompTextConstructor& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</CompTextConstructor>";
    NL;
}


void end_visit(const ContextItemExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</ContextItemExpr>";
    NL;
}


void end_visit(const DirCommentConstructor& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</DirCommentConstructor>";
    NL;
}


void end_visit(const DirElemConstructor& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</DirElemConstructor>";
    NL;
}


void end_visit(const DirElemContent& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</DirElemContent>";
    NL;
}


void end_visit(const DirPIConstructor& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</DirPIConstructor>";
    NL;
}


void end_visit(const EnclosedExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</EnclosedExpr>";
    NL;
}


void end_visit(const Expr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</Expr>";
    NL;
}


// void
// end_visit(const ExprSingle& /*n*/, void* /*visit_state*/)
// {
//     INDENT_DEC;
//
//     INDENT;
//     os << "</MainModule>";
//     NL;
// }


void end_visit(const ExtensionExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</ExtensionExpr>";
    NL;
}


void end_visit(const FLWORExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FLWORExpr>";
    NL;
}


void end_visit(const FilterExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FilterExpr>";
    NL;
}


void end_visit(const FunctionCall& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FunctionCall>";
    NL;
}


void end_visit(const IfExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</IfExpr>";
    NL;
}


void end_visit(const InstanceofExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</InstanceofExpr>";
    NL;
}


void end_visit(const IntersectExceptExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</IntersectExceptExpr>";
    NL;
}


void end_visit(const MultiplicativeExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</MultiplicativeExpr>";
    NL;
}


void end_visit(const OrExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</OrExpr>";
    NL;
}


void end_visit(const OrderedExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</OrderedExpr>";
    NL;
}


void end_visit(const ParenthesizedExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</ParenthesizedExpr>";
    NL;
}


void end_visit(const PathExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</PathExpr>";
    NL;
}


void end_visit(const QuantifiedExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</QuantifiedExpr>";
    NL;
}


void end_visit(const QueryBody& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</QueryBody>";
    NL;
}


void end_visit(const RangeExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</RangeExpr>";
    NL;
}


void end_visit(const RelativePathExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</RelativePathExpr>";
    NL;
}


void end_visit(const StringLiteral& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</StringLiteral>";
    NL;
}


void end_visit(const TreatExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</TreatExpr>";
    NL;
}


void end_visit(const TypeswitchExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</TypeswitchExpr>";
    NL;
}


void end_visit(const UnaryExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</UnaryExpr>";
    NL;
}


void end_visit(const UnionExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</UnionExpr>";
    NL;
}


void end_visit(const UnorderedExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</UnorderedExpr>";
    NL;
}


void end_visit(const ValidateExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</ValidateExpr>";
    NL;
}


void end_visit(const DeleteExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</DeleteExpr>";
    NL;
}


void end_visit(const InsertExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</InsertExpr>";
    NL;
}


void end_visit(const RenameExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</RenameExpr>";
    NL;
}


void end_visit(const ReplaceExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</ReplaceExpr>";
    NL;
}


void end_visit(const RevalidationDecl& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</RevalidationDecl>";
    NL;
}


void end_visit(const TransformExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</TransformExpr>";
    NL;
}


void end_visit(const VarNameList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</VarNameList>";
    NL;
}


void end_visit(const VarBinding& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</VarBinding>";
    NL;
}


void end_visit(const TryExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</TryExpr>";
    NL;
}

void end_visit(const CatchListExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</CatchListExpr>";
    NL;
}

void end_visit(const CatchExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</CatchExpr>";
    NL;
}


void end_visit(const FTAnd& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTAnd>";
    NL;
}


void end_visit(const FTAnyallOption& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTAnyallOption>";
    NL;
}


void end_visit(const FTBigUnit& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTBigUnit>";
    NL;
}


void end_visit(const FTCaseOption& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTCaseOption>";
    NL;
}


void end_visit(const FTContainsExpr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTContainsExpr>";
    NL;
}


void end_visit(const FTContent& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTContent>";
    NL;
}


void end_visit(const FTDiacriticsOption& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTDiacriticsOption>";
    NL;
}


void end_visit(const FTDistance& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTDistance>";
    NL;
}


void end_visit(const FTIgnoreOption& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTIgnoreOption>";
    NL;
}


void end_visit(const FTInclExclStringLiteral& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTInclExclStringLiteral>";
    NL;
}


void end_visit(const FTInclExclStringLiteralList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTInclExclStringLiteralList>";
    NL;
}


void end_visit(const FTLanguageOption& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTLanguageOption>";
    NL;
}


void end_visit(const FTMatchOption& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTMatchOption>";
    NL;
}


void end_visit(const FTMatchOptionProximityList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTMatchOptionProximityList>";
    NL;
}


void end_visit(const FTMildnot& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTMildnot>";
    NL;
}


void end_visit(const FTOptionDecl& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTOptionDecl>";
    NL;
}


void end_visit(const FTOr& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTOr>";
    NL;
}


void end_visit(const FTOrderedIndicator& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTOrderedIndicator>";
    NL;
}


void end_visit(const FTProximity& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTProximity>";
    NL;
}


void end_visit(const FTRange& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTRange>";
    NL;
}


void end_visit(const FTRefOrList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTRefOrList>";
    NL;
}


void end_visit(const FTScope& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTScope>";
    NL;
}


void end_visit(const FTScoreVar& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTScoreVar>";
    NL;
}


void end_visit(const FTSelection& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTSelection>";
    NL;
}


void end_visit(const FTStemOption& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTStemOption>";
    NL;
}


void end_visit(const FTStopwordOption& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTStopwordOption>";
    NL;
}


void end_visit(const FTStringLiteralList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTStringLiteralList>";
    NL;
}


void end_visit(const FTThesaurusID& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTThesaurusID>";
    NL;
}


void end_visit(const FTThesaurusList& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTThesaurusList>";
    NL;
}


void end_visit(const FTThesaurusOption& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTThesaurusOption>";
    NL;
}


void end_visit(const FTTimes& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTTimes>";
    NL;
}


void end_visit(const FTUnaryNot& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTUnaryNot>";
    NL;
}


void end_visit(const FTUnit& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTUnit>";
    NL;
}


void end_visit(const FTWildcardOption& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTWildcardOption>";
    NL;
}


void end_visit(const FTWindow& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTWindow>";
    NL;
}


void end_visit(const FTWords& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTWords>";
    NL;
}


void end_visit(const FTWordsSelection& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTWordsSelection>";
    NL;
}


void end_visit(const FTWordsValue& /*n*/, void* /*visit_state*/)
{
    INDENT_DEC;

    INDENT;
    os << "</FTWordsValue>";
    NL;
}

};

void print_parsetree_xml (ostream &os, parsenode *p) {
  ParseNodePrintXMLVisitor v (os);
  v.print (p);
}

} // end namespace

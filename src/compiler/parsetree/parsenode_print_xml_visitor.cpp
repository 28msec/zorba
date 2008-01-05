#include <ostream>
#include "compiler/parsetree/parsenodes.h"
#include "compiler/parsetree/parsenode_print_xml_visitor.h"

namespace xqp {

static void *no_state = (void *) new int;

ParseNodePrintXMLVisitor::ParseNodePrintXMLVisitor(std::ostream &aStream)
  : theIndent(0),
    os(aStream)
{
}


void ParseNodePrintXMLVisitor::print(parsenode* p)
{
    os << "<?xml version='1.0'>" << std::endl;
    os << "<ParseNodeTree>" << std::endl;
    p->accept(*this);
    os << "</ParseNodeTree>" << std::endl;
}


void *ParseNodePrintXMLVisitor::begin_visit(const parsenode &n)
{
    INDENT;

    os << "<ParseNode position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const AbbrevForwardStep &n)
{
    INDENT;

    os << "<AbbrevForwardStep position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const AnyKindTest &n)
{
    INDENT;

    os << "<AnyKindTest position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const AposAttrContentList &n)
{
    INDENT;

    os << "<AposAttrContentList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const AposAttrValueContent &n)
{
    INDENT;

    os << "<AposAttrValueContent position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const ArgList &n)
{
    INDENT;

    os << "<ArgList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const AtomicType &n)
{
    INDENT;

    os << "<AtomicType position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const AttributeTest &n)
{
    INDENT;

    os << "<AttributeTest position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const BaseURIDecl &n)
{
    INDENT;

    os << "<BaseURIDecl position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const BoundarySpaceDecl &n)
{
    INDENT;

    os << "<BoundarySpaceDecl position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const CaseClause &n)
{
    INDENT;

    os << "<CaseClause position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const CaseClauseList &n)
{
    INDENT;

    os << "<CaseClauseList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const CommentTest &n)
{
    INDENT;

    os << "<CommentTest position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const ConstructionDecl &n)
{
    INDENT;

    os << "<ConstructionDecl position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const CopyNamespacesDecl &n)
{
    INDENT;

    os << "<CopyNamespacesDecl position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const DefaultCollationDecl &n)
{
    INDENT;

    os << "<DefaultCollationDecl position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const DefaultNamespaceDecl &n)
{
    INDENT;

    os << "<DefaultNamespaceDecl position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const DirAttr &n)
{
    INDENT;

    os << "<DirAttr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const DirAttributeList &n)
{
    INDENT;

    os << "<DirAttributeList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const DirAttributeValue &n)
{
    INDENT;

    os << "<DirAttributeValue position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const DirElemContentList &n)
{
    INDENT;

    os << "<DirElemContentList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const DocumentTest &n)
{
    INDENT;

    os << "<DocumentTest position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const ElementTest &n)
{
    INDENT;

    os << "<ElementTest position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const EmptyOrderDecl &n)
{
    INDENT;

    os << "<EmptyOrderDecl position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const ForClause &n)
{
    INDENT;

    os << "<ForClause position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


// bool
// ParseNodePrintXMLVisitor::begin_visit(const ForLetClause &n)
// {
//     INDENT;
//
//     os << "<MainModule position='" << n.get_location() << "' ptr='" << &n << "'";
//
//     os << ">";
//
//     INDENT_INC;
//     NL;
//     return no_state;
// }


void *ParseNodePrintXMLVisitor::begin_visit(const ForLetClauseList &n)
{
    INDENT;

    os << "<ForLetClauseList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const ForwardAxis &n)
{
    INDENT;

    os << "<ForwardAxis position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const ForwardStep &n)
{
    INDENT;

    os << "<ForwardStep position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FunctionDecl &n)
{
    INDENT;

    os << "<FunctionDecl position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const GeneralComp &n)
{
    INDENT;

    os << "<GeneralComp position='" << n.get_location() << "' ptr='" << &n << "'";

    os << "/>";
    
    NL;

    return no_state;
}

void ParseNodePrintXMLVisitor::end_visit(const GeneralComp &n, void *visit_state)
{
}


void *ParseNodePrintXMLVisitor::begin_visit(const ItemType &n)
{
    INDENT;

    os << "<ItemType position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const LetClause &n)
{
    INDENT;

    os << "<LetClause position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const LibraryModule &n)
{
    INDENT;

    os << "<LibraryModule position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const MainModule  &n)
{
    INDENT;

    os << "<MainModule position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;

    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const Module &n)
{
    INDENT;

    os << "<Module position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const ModuleDecl &n)
{
    INDENT;

    os << "<ModuleDecl position='" << n.get_location() << "' ptr='" << &n << "'";
    os << " prefix='" << n.get_prefix() << "' "
       << "target_namespace='" << n.get_target_namespace() << "' ptr='" << &n << "'";
    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const ModuleImport &n)
{
    INDENT;

    os << "<ModuleImport position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const NameTest &n)
{
    INDENT;

    os << "<NameTest position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;

    // Hack: visitor is broken, QName is never visited.
    // However fixing this would impact the translator.
    // So we "visit" here.
    if (n.getQName () != NULL) n.getQName ()->accept (*this);
    
    return no_state;
}

void ParseNodePrintXMLVisitor::end_visit(const NameTest &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</NameTest>";
    NL;
}


void *ParseNodePrintXMLVisitor::begin_visit(const NamespaceDecl &n)
{
    INDENT;

    os << "<NamespaceDecl position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const NodeComp &n)
{
    INDENT;

    os << "<NodeComp position='" << n.get_location() << "' ptr='" << &n << "'";

    os << "/>";

    NL;
    return no_state;
}

void ParseNodePrintXMLVisitor::end_visit(const NodeComp &n, void *visit_state)
{
}


void *ParseNodePrintXMLVisitor::begin_visit(const OccurrenceIndicator &n)
{
    INDENT;

    os << "<OccurrenceIndicator position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const OptionDecl &n)
{
    INDENT;

    os << "<OptionDecl position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const OrderByClause &n)
{
    INDENT;

    os << "<OrderByClause position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const OrderCollationSpec &n)
{
    INDENT;

    os << "<OrderCollationSpec position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const OrderDirSpec &n)
{
    INDENT;

    os << "<OrderDirSpec position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const OrderEmptySpec &n)
{
    INDENT;

    os << "<OrderEmptySpec position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const OrderModifier &n)
{
    INDENT;

    os << "<OrderModifier position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const OrderSpec &n)
{
    INDENT;

    os << "<OrderSpec position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const OrderSpecList &n)
{
    INDENT;

    os << "<OrderSpecList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const OrderingModeDecl &n)
{
    INDENT;

    os << "<OrderingModeDecl position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const PITest &n)
{
    INDENT;

    os << "<PITest position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const Param &n)
{
    INDENT;

    os << "<Param position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const ParamList &n)
{
    INDENT;

    os << "<ParamList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const PositionalVar &n)
{
    INDENT;

    os << "<PositionalVar position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const Pragma &n)
{
    INDENT;

    os << "<Pragma position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const PragmaList &n)
{
    INDENT;

    os << "<PragmaList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const PredicateList &n)
{
    INDENT;

    os << "<PredicateList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const Prolog &n)
{
    INDENT;

    os << "<Prolog position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const QVarInDecl &n)
{
    INDENT;

    os << "<QVarInDecl position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const QVarInDeclList &n)
{
    INDENT;

    os << "<QVarInDeclList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const QuoteAttrValueContent &n)
{
    INDENT;

    os << "<QuoteAttrValueContent position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const QuoteAttrContentList &n)
{
    INDENT;

    os << "<QuoteAttrContentList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const ReverseAxis &n)
{
    INDENT;

    os << "<ReverseAxis position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const ReverseStep &n)
{
    INDENT;

    os << "<ReverseStep position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const SIND_DeclList &n)
{
    INDENT;

    os << "<SIND_DeclList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const SchemaAttributeTest &n)
{
    INDENT;

    os << "<SchemaAttributeTest position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const SchemaElementTest &n)
{
    INDENT;

    os << "<SchemaElementTest position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const SchemaImport &n)
{
    INDENT;

    os << "<SchemaImport position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const SchemaPrefix &n)
{
    INDENT;

    os << "<SchemaPrefix position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const SequenceType &n)
{
    INDENT;

    os << "<SequenceType position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const SignList &n)
{
    INDENT;

    os << "<SignList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const SingleType &n)
{
    INDENT;

    os << "<SingleType position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const TextTest &n)
{
    INDENT;

    os << "<TextTest position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const TypeDeclaration &n)
{
    INDENT;

    os << "<TypeDeclaration position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const TypeName &n)
{
    INDENT;

    os << "<TypeName position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const URILiteralList &n)
{
    INDENT;

    os << "<URILiteralList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const ValueComp &n)
{
    INDENT;

    os << "<ValueComp position='" << n.get_location() << "' ptr='" << &n << "'";

    os << "/>";

    NL;
    return no_state;
}

void ParseNodePrintXMLVisitor::end_visit(const ValueComp &n, void *visit_state)
{
}


void *ParseNodePrintXMLVisitor::begin_visit(const VarDecl &n)
{
    INDENT;

    os << "<VarDecl position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const VarGetsDecl &n)
{
    INDENT;

    os << "<VarGetsDecl position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const VarGetsDeclList &n)
{
    INDENT;

    os << "<VarGetsDeclList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const VarInDecl &n)
{
    INDENT;

    os << "<VarInDecl position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const VarInDeclList &n)
{
    INDENT;

    os << "<VarInDeclList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const VersionDecl &n)
{
    INDENT;

    os << "<VersionDecl position='" << n.get_location() << "' ptr='" << &n << "'";
    os << "version='" << n.get_version() << "' "
       << "encoding='" << n.get_encoding() << "' ";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const VFO_DeclList &n)
{
    INDENT;

    os << "<VFO_DeclList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const WhereClause &n)
{
    INDENT;

    os << "<WhereClause position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const QName &n)
{
  INDENT;

  os << "<QName name='" << n.get_qname () << "' position='" << n.get_location() << "' ptr='" << &n << "'";

  os << "/>";

  NL;

  return no_state;
}

void ParseNodePrintXMLVisitor::end_visit(const QName &n, void *visit_state)
{
}


void *ParseNodePrintXMLVisitor::begin_visit(const Wildcard &n)
{
    INDENT;

    os << "<Wildcard position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const exprnode &n)
{
    INDENT;

    os << "<exprnode position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const AdditiveExpr &n)
{
    INDENT;

    os << "<AdditiveExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const AndExpr &n)
{
    INDENT;

    os << "<AndExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const AxisStep &n)
{
    INDENT;

    os << "<AxisStep position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const CDataSection &n)
{
    INDENT;

    os << "<CDataSection position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const CastExpr &n)
{
    INDENT;

    os << "<CastExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const CastableExpr &n)
{
    INDENT;

    os << "<CastableExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const CommonContent &n)
{
    INDENT;

    os << "<CommonContent position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    NL;
    INDENT_INC;
    INDENT;
    os << "<Type>";
    switch (n.get_type())
    {
      case cont_entity:
      {
        os << "entity";
        break;
      }
      case cont_charref:
      {
        os << "charref";
        break;
      }
    	case cont_escape_lbrace:
    	{
        os << "escaped lbrace";
        break;
    	}
    	case cont_escape_rbrace:
  	  {
        os << "escaped rbrace";
        break;
  	  }
    	case cont_expr:
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


void *ParseNodePrintXMLVisitor::begin_visit(const ComparisonExpr &n)
{
    INDENT;

    os << "<ComparisonExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;

    // Hack: visitor does not visit

    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const CompAttrConstructor &n)
{
    INDENT;

    os << "<CompAttrConstructor position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const CompCommentConstructor &n)
{
    INDENT;

    os << "<CompCommentConstructor position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const CompDocConstructor &n)
{
    INDENT;

    os << "<CompDocConstructor position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const CompElemConstructor &n)
{
    INDENT;

    os << "<CompElemConstructor position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const CompPIConstructor &n)
{
    INDENT;

    os << "<CompPIConstructor position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const CompTextConstructor &n)
{
    INDENT;

    os << "<CompTextConstructor position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const ContextItemExpr &n)
{
    INDENT;

    os << "<ContextItemExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const DirCommentConstructor &n)
{
    INDENT;

    os << "<DirCommentConstructor position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const DirElemConstructor &n)
{
    INDENT;

    os << "<DirElemConstructor position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const DirElemContent &n)
{
    INDENT;

    os << "<DirElemContent position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const DirPIConstructor &n)
{
    INDENT;

    os << "<DirPIConstructor position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const EnclosedExpr &n)
{
    INDENT;

    os << "<EnclosedExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const Expr &n)
{
    INDENT;

    os << "<Expr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


// bool
// ParseNodePrintXMLVisitor::begin_visit(const ExprSingle &n)
// {
//     INDENT;
//
//     os << "<MainModule position='" << n.get_location() << "' ptr='" << &n << "'";
//
//     os << ">";
//
//     INDENT_INC;
//     NL;
//     return no_state;
// }


void *ParseNodePrintXMLVisitor::begin_visit(const ExtensionExpr &n)
{
    INDENT;

    os << "<ExtensionExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FLWORExpr &n)
{
    INDENT;

    os << "<FLWORExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FilterExpr &n)
{
    INDENT;

    os << "<FilterExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FunctionCall &n)
{
    INDENT;

    os << "<FunctionCall position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const IfExpr &n)
{
    INDENT;

    os << "<IfExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const InstanceofExpr &n)
{
    INDENT;

    os << "<InstanceofExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const IntersectExceptExpr &n)
{
    INDENT;

    os << "<IntersectExceptExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const MultiplicativeExpr &n)
{
    INDENT;

    os << "<MultiplicativeExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const NumericLiteral &n)
{
    INDENT;

    os << "<NumericLiteral position='" << n.get_location() << "' ptr='" << &n << "'";

    os << "/>";

    NL;
    return no_state;
}

void ParseNodePrintXMLVisitor::end_visit(const NumericLiteral &n, void *visit_state)
{
}


void *ParseNodePrintXMLVisitor::begin_visit(const OrExpr &n)
{
    INDENT;

    os << "<OrExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const OrderedExpr &n)
{
    INDENT;

    os << "<OrderedExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const ParenthesizedExpr &n)
{
    INDENT;

    os << "<ParenthesizedExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const PathExpr &n)
{
    INDENT;

    os << "<PathExpr position='" << n.get_location() << "'  "  << "ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const QuantifiedExpr &n)
{
    INDENT;

    os << "<QuantifiedExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const QueryBody &n)
{
    INDENT;

    os << "<QueryBody position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const RangeExpr &n)
{
    INDENT;

    os << "<RangeExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const RelativePathExpr &n)
{
    INDENT;

    os << "<RelativePathExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const StringLiteral &n)
{
    INDENT;

    os << "<StringLiteral position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const TreatExpr &n)
{
    INDENT;

    os << "<TreatExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const TypeswitchExpr &n)
{
    INDENT;

    os << "<TypeswitchExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const UnaryExpr &n)
{
    INDENT;

    os << "<UnaryExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const UnionExpr &n)
{
    INDENT;

    os << "<UnionExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const UnorderedExpr &n)
{
    INDENT;

    os << "<UnorderedExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const ValidateExpr &n)
{
    INDENT;

    os << "<ValidateExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const VarRef &n)
{
    INDENT;

    os << "<VarRef position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const DeleteExpr &n)
{
    INDENT;

    os << "<DeleteExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const InsertExpr &n)
{
    INDENT;

    os << "<InsertExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const RenameExpr &n)
{
    INDENT;

    os << "<RenameExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const ReplaceExpr &n)
{
    INDENT;

    os << "<ReplaceExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const RevalidationDecl &n)
{
    INDENT;

    os << "<RevalidationDecl position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const TransformExpr &n)
{
    INDENT;

    os << "<TransformExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const VarNameList &n)
{
    INDENT;

    os << "<VarNameList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTAnd &n)
{
    INDENT;

    os << "<FTAnd position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTAnyallOption &n)
{
    INDENT;

    os << "<FTAnyallOption position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTBigUnit &n)
{
    INDENT;

    os << "<FTBigUnit position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTCaseOption &n)
{
    INDENT;

    os << "<FTCaseOption position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTContainsExpr &n)
{
    INDENT;

    os << "<FTContainsExpr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTContent &n)
{
    INDENT;

    os << "<FTContent position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTDiacriticsOption &n)
{
    INDENT;

    os << "<FTDiacriticsOption position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTDistance &n)
{
    INDENT;

    os << "<FTDistance position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTIgnoreOption &n)
{
    INDENT;

    os << "<FTIgnoreOption position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTInclExclStringLiteral &n)
{
    INDENT;

    os << "<FTInclExclStringLiteral position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTInclExclStringLiteralList &n)
{
    INDENT;

    os << "<FTInclExclStringLiteralList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTLanguageOption &n)
{
    INDENT;

    os << "<FTLanguageOption position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTMatchOption &n)
{
    INDENT;

    os << "<FTMatchOption position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTMatchOptionProximityList &n)
{
    INDENT;

    os << "<FTMatchOptionProximityList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTMildnot &n)
{
    INDENT;

    os << "<FTMildnot position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTOptionDecl &n)
{
    INDENT;

    os << "<FTOptionDecl position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTOr &n)
{
    INDENT;

    os << "<FTOr position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTOrderedIndicator &n)
{
    INDENT;

    os << "<FTOrderedIndicator position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTProximity &n)
{
    INDENT;

    os << "<FTProximity position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTRange &n)
{
    INDENT;

    os << "<FTRange position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTRefOrList &n)
{
    INDENT;

    os << "<FTRefOrList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTScope &n)
{
    INDENT;

    os << "<FTScope position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTScoreVar &n)
{
    INDENT;

    os << "<FTScoreVar position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTSelection &n)
{
    INDENT;

    os << "<FTSelection position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTStemOption &n)
{
    INDENT;

    os << "<FTStemOption position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTStopwordOption &n)
{
    INDENT;

    os << "<FTStopwordOption position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTStringLiteralList &n)
{
    INDENT;

    os << "<FTStringLiteralList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTThesaurusID &n)
{
    INDENT;

    os << "<FTThesaurusID position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTThesaurusList &n)
{
    INDENT;

    os << "<FTThesaurusList position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTThesaurusOption &n)
{
    INDENT;

    os << "<FTThesaurusOption position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTTimes &n)
{
    INDENT;

    os << "<FTTimes position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTUnaryNot &n)
{
    INDENT;

    os << "<FTUnaryNot position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTUnit &n)
{
    INDENT;

    os << "<FTUnit position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTWildcardOption &n)
{
    INDENT;

    os << "<FTWildcardOption position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTWindow &n)
{
    INDENT;

    os << "<FTWindow position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTWords &n)
{
    INDENT;

    os << "<FTWords position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTWordsSelection &n)
{
    INDENT;

    os << "<FTWordsSelection position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void *ParseNodePrintXMLVisitor::begin_visit(const FTWordsValue &n)
{
    INDENT;

    os << "<FTWordsValue position='" << n.get_location() << "' ptr='" << &n << "'";

    os << ">";

    INDENT_INC;
    NL;
    return no_state;
}


void ParseNodePrintXMLVisitor::end_visit(const parsenode &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</ParseNode>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const AbbrevForwardStep &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</AbbrevForwardStep>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const AnyKindTest &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</AnyKindTest>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const AposAttrContentList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</AposAttrContentList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const AposAttrValueContent &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</AposAttrValueContent>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const ArgList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</ArgList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const AtomicType &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</AtomicType>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const AttributeTest &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</AttributeTest>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const BaseURIDecl &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</BaseURIDecl>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const BoundarySpaceDecl &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</BoundarySpaceDecl>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const CaseClause &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</CaseClause>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const CaseClauseList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</CaseClauseList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const CommentTest &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</CommentTest>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const ConstructionDecl &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</ConstructionDecl>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const CopyNamespacesDecl &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</CopyNamespacesDecl>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const DefaultCollationDecl &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</DefaultCollationDecl>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const DefaultNamespaceDecl &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</DefaultNamespaceDecl>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const DirAttr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</DirAttr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const DirAttributeList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</DirAttributeList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const DirAttributeValue &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</DirAttributeValue>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const DirElemContentList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</DirElemContentList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const DocumentTest &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</DocumentTest>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const ElementTest &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</ElementTest>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const EmptyOrderDecl &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</EmptyOrderDecl>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const ForClause &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</ForClause>";
    NL;
}


// void
// ParseNodePrintXMLVisitor::end_visit(const ForLetClause &n, void *visit_state)
// {
//     INDENT_DEC;
//
//     INDENT;
//     os << "</MainModule>";
//     NL;
// }


void ParseNodePrintXMLVisitor::end_visit(const ForLetClauseList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</ForLetClauseList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const ForwardAxis &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</ForwardAxis>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const ForwardStep &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</ForwardStep>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FunctionDecl &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FunctionDecl>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const ItemType &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</ItemType>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const LetClause &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</LetClause>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const LibraryModule &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</LibraryModule>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const MainModule  &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</MainModule>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const Module &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</Module>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const ModuleDecl &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</ModuleDecl>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const ModuleImport &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</ModuleImport>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const NamespaceDecl &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</NamespaceDecl>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const OccurrenceIndicator &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</OccurrenceIndicator>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const OptionDecl &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</OptionDecl>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const OrderByClause &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</OrderByClause>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const OrderCollationSpec &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</OrderCollationSpec>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const OrderDirSpec &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</OrderDirSpec>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const OrderEmptySpec &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</OrderEmptySpec>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const OrderModifier &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</OrderModifier>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const OrderSpec &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</OrderSpec>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const OrderSpecList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</OrderSpecList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const OrderingModeDecl &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</OrderingModeDecl>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const PITest &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</PITest>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const Param &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</Param>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const ParamList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</ParamList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const PositionalVar &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</PositionalVar>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const Pragma &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</Pragma>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const PragmaList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</PragmaList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const PredicateList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</PredicateList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const Prolog &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</Prolog>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const QVarInDecl &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</QVarInDecl>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const QVarInDeclList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</QVarInDeclList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const QuoteAttrValueContent &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</QuoteAttrValueContent>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const QuoteAttrContentList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</QuoteAttrContentList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const ReverseAxis &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</ReverseAxis>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const ReverseStep &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</ReverseStep>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const SIND_DeclList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</SIND_DeclList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const SchemaAttributeTest &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</SchemaAttributeTest>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const SchemaElementTest &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</SchemaElementTest>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const SchemaImport &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</SchemaImport>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const SchemaPrefix &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</SchemaPrefix>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const SequenceType &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</SequenceType>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const SignList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</SignList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const SingleType &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</SingleType>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const TextTest &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</TextTest>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const TypeDeclaration &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</TypeDeclaration>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const TypeName &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</TypeName>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const URILiteralList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</URILiteralList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const VarDecl &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</VarDecl>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const VarGetsDecl &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</VarGetsDecl>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const VarGetsDeclList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</VarGetsDeclList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const VarInDecl &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</VarInDecl>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const VarInDeclList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</VarInDeclList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const VersionDecl &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</VersionDecl>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const VFO_DeclList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</VFO_DeclList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const WhereClause &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</WhereClause>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const Wildcard &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</Wildcard>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const exprnode &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</exprnode>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const AdditiveExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</AdditiveExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const AndExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</AndExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const AxisStep &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</AxisStep>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const CDataSection &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</CDataSection>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const CastExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</CastExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const CastableExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</CastableExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const CommonContent &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</CommonContent>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const ComparisonExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</ComparisonExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const CompAttrConstructor &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</CompAttrConstructor>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const CompCommentConstructor &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</CompCommentConstructor>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const CompDocConstructor &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</CompDocConstructor>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const CompElemConstructor &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</CompElemConstructor>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const CompPIConstructor &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</CompPIConstructor>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const CompTextConstructor &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</CompTextConstructor>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const ContextItemExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</ContextItemExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const DirCommentConstructor &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</DirCommentConstructor>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const DirElemConstructor &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</DirElemConstructor>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const DirElemContent &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</DirElemContent>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const DirPIConstructor &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</DirPIConstructor>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const EnclosedExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</EnclosedExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const Expr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</Expr>";
    NL;
}


// void
// ParseNodePrintXMLVisitor::end_visit(const ExprSingle &n, void *visit_state)
// {
//     INDENT_DEC;
//
//     INDENT;
//     os << "</MainModule>";
//     NL;
// }


void ParseNodePrintXMLVisitor::end_visit(const ExtensionExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</ExtensionExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FLWORExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FLWORExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FilterExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FilterExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FunctionCall &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FunctionCall>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const IfExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</IfExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const InstanceofExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</InstanceofExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const IntersectExceptExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</IntersectExceptExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const MultiplicativeExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</MultiplicativeExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const OrExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</OrExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const OrderedExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</OrderedExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const ParenthesizedExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</ParenthesizedExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const PathExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</PathExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const QuantifiedExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</QuantifiedExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const QueryBody &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</QueryBody>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const RangeExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</RangeExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const RelativePathExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</RelativePathExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const StringLiteral &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</StringLiteral>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const TreatExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</TreatExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const TypeswitchExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</TypeswitchExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const UnaryExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</UnaryExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const UnionExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</UnionExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const UnorderedExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</UnorderedExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const ValidateExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</ValidateExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const VarRef &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</VarRef>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const DeleteExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</DeleteExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const InsertExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</InsertExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const RenameExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</RenameExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const ReplaceExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</ReplaceExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const RevalidationDecl &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</RevalidationDecl>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const TransformExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</TransformExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const VarNameList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</VarNameList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTAnd &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTAnd>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTAnyallOption &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTAnyallOption>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTBigUnit &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTBigUnit>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTCaseOption &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTCaseOption>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTContainsExpr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTContainsExpr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTContent &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTContent>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTDiacriticsOption &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTDiacriticsOption>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTDistance &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTDistance>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTIgnoreOption &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTIgnoreOption>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTInclExclStringLiteral &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTInclExclStringLiteral>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTInclExclStringLiteralList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTInclExclStringLiteralList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTLanguageOption &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTLanguageOption>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTMatchOption &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTMatchOption>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTMatchOptionProximityList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTMatchOptionProximityList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTMildnot &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTMildnot>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTOptionDecl &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTOptionDecl>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTOr &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTOr>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTOrderedIndicator &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTOrderedIndicator>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTProximity &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTProximity>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTRange &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTRange>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTRefOrList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTRefOrList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTScope &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTScope>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTScoreVar &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTScoreVar>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTSelection &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTSelection>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTStemOption &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTStemOption>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTStopwordOption &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTStopwordOption>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTStringLiteralList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTStringLiteralList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTThesaurusID &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTThesaurusID>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTThesaurusList &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTThesaurusList>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTThesaurusOption &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTThesaurusOption>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTTimes &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTTimes>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTUnaryNot &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTUnaryNot>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTUnit &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTUnit>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTWildcardOption &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTWildcardOption>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTWindow &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTWindow>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTWords &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTWords>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTWordsSelection &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTWordsSelection>";
    NL;
}


void ParseNodePrintXMLVisitor::end_visit(const FTWordsValue &n, void *visit_state)
{
    INDENT_DEC;

    INDENT;
    os << "</FTWordsValue>";
    NL;
}


} // end namespace


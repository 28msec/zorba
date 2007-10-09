#include "parsenode_print_dot_visitor.h"

#include <ostream>

#include "compiler/parsetree/parsenodes.h"

namespace xqp {


ParseNodePrintDOTVisitor::ParseNodePrintDOTVisitor(std::ostream &aStream)
  : theIndent(0),
    os(aStream)
{
}

void
ParseNodePrintDOTVisitor::print(parsenode* n)
{
    os << "digraph query {" << std::endl;
    n->accept(*this);
    os << "}" << std::endl;
}
 
bool
ParseNodePrintDOTVisitor::begin_visit(const parsenode &n)
{    
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ParseNode\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
 
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const AbbrevForwardStep &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"AbbrevForwardStep\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const AnyKindTest &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"AnyKindTest\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const AposAttrContentList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"AposAttrContentList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const AposAttrValueContent &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"AposAttrValueContent\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const ArgList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ArgList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const AtomicType &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"AtomicType\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const AttributeTest &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"AttributeTest\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const BaseURIDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"BaseURIDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const BoundarySpaceDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"BoundarySpaceDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const CaseClause &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CaseClause\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const CaseClauseList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CaseClauseList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const CommentTest &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CommentTest\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const ConstructionDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ConstructionDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const CopyNamespacesDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CopyNamespacesDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const DefaultCollationDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DefaultCollationDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const DefaultNamespaceDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DefaultNamespaceDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const DirAttr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DirAttr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const DirAttributeList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DirAttributeList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const DirAttributeValue &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DirAttributeValue\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const DirElemContentList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DirElemContentList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const DocumentTest &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DocumentTest\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const ElementTest &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ElementTest\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const EmptyOrderDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"EmptyOrderDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const ForClause &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ForClause\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


// bool
// ParseNodePrintDOTVisitor::begin_visit(const ForLetClause &n)
// {
//     INDENT;
//     
//     os << "<MainModule position='" << n.get_location() << "'";
// 
//     os << ">";
//     
//     INDENT_INC;
//     NL;
//     return true;
// }


bool
ParseNodePrintDOTVisitor::begin_visit(const ForLetClauseList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ForLetClauseList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const ForwardAxis &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ForwardAxis\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const ForwardStep &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ForwardStep\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FunctionDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FunctionDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const GeneralComp &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"GeneralComp\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const ItemType &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ItemType\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const LetClause &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"LetClause\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const LibraryModule &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"LibraryModule\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const MainModule  &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"MainModule\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;

    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const Module &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"Module\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const ModuleDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ModuleDecl position='" << n.get_location() << "'";
    os << " prefix='" << n.get_prefix() << "' " 
       << "target_namespace='" << n.get_target_namespace() << "'";
    os << ">";
    
    INDENT_INC;
    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const ModuleImport &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ModuleImport\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const NameTest &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"NameTest\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const NamespaceDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"NamespaceDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const NodeComp &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"NodeComp\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const OccurrenceIndicator &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OccurrenceIndicator\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const OptionDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OptionDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const OrderByClause &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OrderByClause\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const OrderCollationSpec &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OrderCollationSpec\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const OrderDirSpec &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OrderDirSpec\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const OrderEmptySpec &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OrderEmptySpec\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const OrderModifier &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OrderModifier\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const OrderSpec &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OrderSpec\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const OrderSpecList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OrderSpecList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const OrderingModeDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OrderingModeDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const PITest &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"PITest\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const Param &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"Param\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const ParamList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ParamList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const PositionalVar &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"PositionalVar\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const Pragma &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"Pragma\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const PragmaList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"PragmaList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const PredicateList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"PredicateList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const Prolog &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"Prolog\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const QVarInDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"QVarInDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const QVarInDeclList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"QVarInDeclList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const QuoteAttrValueContent &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"QuoteAttrValueContent\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const QuoteAttrContentList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"QuoteAttrContentList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const ReverseAxis &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ReverseAxis\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const ReverseStep &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ReverseStep\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const SIND_DeclList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"SIND_DeclList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const SchemaAttributeTest &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"SchemaAttributeTest\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const SchemaElementTest &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"SchemaElementTest\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const SchemaImport &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"SchemaImport\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const SchemaPrefix &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"SchemaPrefix\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const SequenceType &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"SequenceType\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const SignList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"SignList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const SingleType &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"SingleType\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const TextTest &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"TextTest\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const TypeDeclaration &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"TypeDeclaration\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const TypeName &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"TypeName\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const URILiteralList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"URILiteralList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const ValueComp &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ValueComp\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const VarDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"VarDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const VarGetsDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"VarGetsDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const VarGetsDeclList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"VarGetsDeclList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const VarInDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"VarInDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const VarInDeclList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"VarInDeclList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const VersionDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"VersionDecl position='" << n.get_location() << "'";
    os << "version='" << n.get_version() << "' " 
       << "encoding='" << n.get_encoding() << "' ";

    os << ">";
    
    INDENT_INC;
    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const VFO_DeclList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"VFO_DeclList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const WhereClause &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"WhereClause\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const Wildcard &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"Wildcard\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}



bool
ParseNodePrintDOTVisitor::begin_visit(const exprnode &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"exprnode\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const AdditiveExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"AdditiveExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const AndExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"AndExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const AxisStep &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"AxisStep\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const CDataSection &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CDataSection\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const CastExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CastExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const CastableExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CastableExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const CommonContent &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CommonContent\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const ComparisonExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ComparisonExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const CompAttrConstructor &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CompAttrConstructor\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const CompCommentConstructor &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CompCommentConstructor\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const CompDocConstructor &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CompDocConstructor\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const CompElemConstructor &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CompElemConstructor\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const CompPIConstructor &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CompPIConstructor\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const CompTextConstructor &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CompTextConstructor\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const ContextItemExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ContextItemExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const DirCommentConstructor &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DirCommentConstructor\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const DirElemConstructor &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DirElemConstructor\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const DirElemContent &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DirElemContent\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const DirPIConstructor &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DirPIConstructor\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const EnclosedExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"EnclosedExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const Expr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"Expr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


// bool
// ParseNodePrintDOTVisitor::begin_visit(const ExprSingle &n)
// {
//     INDENT;
//     
//     os << "<MainModule position='" << n.get_location() << "'";
// 
//     os << ">";
//     
//     INDENT_INC;
//     NL;
//     return true;
// }


bool
ParseNodePrintDOTVisitor::begin_visit(const ExtensionExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ExtensionExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FLWORExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FLWORExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FilterExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FilterExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FunctionCall &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FunctionCall\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const IfExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"IfExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const InstanceofExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"InstanceofExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const IntersectExceptExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"IntersectExceptExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const MultiplicativeExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"MultiplicativeExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const NumericLiteral &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"NumericLiteral\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const OrExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OrExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const OrderedExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OrderedExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const ParenthesizedExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ParenthesizedExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const PathExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"PathExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const QuantifiedExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"QuantifiedExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const QueryBody &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"QueryBody\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const RangeExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"RangeExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const RelativePathExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"RelativePathExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const StringLiteral &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"StringLiteral\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const TreatExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"TreatExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const TypeswitchExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"TypeswitchExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const UnaryExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"UnaryExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const UnionExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"UnionExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const UnorderedExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"UnorderedExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const ValidateExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ValidateExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const VarRef &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"VarRef\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}



bool
ParseNodePrintDOTVisitor::begin_visit(const DeleteExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DeleteExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const InsertExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"InsertExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const RenameExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"RenameExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const ReplaceExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ReplaceExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const RevalidationDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"RevalidationDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const TransformExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"TransformExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const VarNameList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"VarNameList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}



bool
ParseNodePrintDOTVisitor::begin_visit(const FTAnd &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTAnd\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTAnyallOption &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTAnyallOption\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTBigUnit &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTBigUnit\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTCaseOption &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTCaseOption\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTContainsExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTContainsExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTContent &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTContent\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTDiacriticsOption &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTDiacriticsOption\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTDistance &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTDistance\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTIgnoreOption &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTIgnoreOption\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTInclExclStringLiteral &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTInclExclStringLiteral\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTInclExclStringLiteralList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTInclExclStringLiteralList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTLanguageOption &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTLanguageOption\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTMatchOption &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTMatchOption\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTMatchOptionProximityList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTMatchOptionProximityList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTMildnot &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTMildnot\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTOptionDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTOptionDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTOr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTOr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTOrderedIndicator &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTOrderedIndicator\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTProximity &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTProximity\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTRange &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTRange\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTRefOrList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTRefOrList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTScope &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTScope\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTScoreVar &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTScoreVar\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTSelection &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTSelection\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTStemOption &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTStemOption\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTStopwordOption &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTStopwordOption\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTStringLiteralList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTStringLiteralList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTThesaurusID &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTThesaurusID\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTThesaurusList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTThesaurusList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTThesaurusOption &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTThesaurusOption\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTTimes &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTTimes\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTUnaryNot &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTUnaryNot\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTUnit &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTUnit\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTWildcardOption &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTWildcardOption\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTWindow &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTWindow\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTWords &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTWords\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTWordsSelection &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTWordsSelection\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


bool
ParseNodePrintDOTVisitor::begin_visit(const FTWordsValue &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTWordsValue\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return true;
}


void
ParseNodePrintDOTVisitor::end_visit(const parsenode &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const AbbrevForwardStep &n)
{
    if (n.get_node_test() != NULL)
      os << reinterpret_cast<intptr_t>(&n) << " -> " 
         << reinterpret_cast<intptr_t>(&*n.get_node_test()) << std::endl;    
}

void
ParseNodePrintDOTVisitor::end_visit(const AnyKindTest &n)
{
}

void
ParseNodePrintDOTVisitor::end_visit(const AposAttrContentList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const AposAttrValueContent &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const ArgList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const AtomicType &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const AttributeTest &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const BaseURIDecl &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const BoundarySpaceDecl &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const CaseClause &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const CaseClauseList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const CommentTest &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const ConstructionDecl &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const CopyNamespacesDecl &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const DefaultCollationDecl &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const DefaultNamespaceDecl &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const DirAttr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const DirAttributeList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const DirAttributeValue &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const DirElemContentList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const DocumentTest &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const ElementTest &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const EmptyOrderDecl &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const ForClause &n)
{
}


// void
// ParseNodePrintDOTVisitor::end_visit(const ForLetClause &n)
// {
//     INDENT_DEC;
//     
//     INDENT;
//     os << "</MainModule>";
//     NL;
// }


void
ParseNodePrintDOTVisitor::end_visit(const ForLetClauseList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const ForwardAxis &n)
{

}


void
ParseNodePrintDOTVisitor::end_visit(const ForwardStep &n)
{
    if (n.get_forward_axis() != NULL)
      os << reinterpret_cast<intptr_t>(&n) << " -> " 
         << reinterpret_cast<intptr_t>(&*n.get_forward_axis()) << std::endl;

    if (n.get_node_test() != NULL)
      os << reinterpret_cast<intptr_t>(&n) << " -> " 
         << reinterpret_cast<intptr_t>(&*n.get_node_test()) << std::endl;               

    if (n.get_abbrev_step() != NULL)
      os << reinterpret_cast<intptr_t>(&n) << " -> " 
         << reinterpret_cast<intptr_t>(&*n.get_abbrev_step()) << std::endl;    

}


void
ParseNodePrintDOTVisitor::end_visit(const FunctionDecl &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const GeneralComp &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const ItemType &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const LetClause &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const LibraryModule &n)
{
    os << reinterpret_cast<intptr_t>(&n) << " -> " 
          << reinterpret_cast<intptr_t>(&*n.get_decl());

       os << reinterpret_cast<intptr_t>(&n) << " -> " 
          << reinterpret_cast<intptr_t>(&*n.get_prolog());
    NL;
}


void
ParseNodePrintDOTVisitor::end_visit(const MainModule  &n)
{
    if (n.get_prolog() != NULL)
        os << reinterpret_cast<intptr_t>(&n) << " -> " 
           << reinterpret_cast<intptr_t>(&*n.get_prolog()) << std::endl;
  
    if (n.get_query_body() != NULL)
        os << reinterpret_cast<intptr_t>(&n) << " -> " 
           << reinterpret_cast<intptr_t>(&*n.get_query_body()) << std::endl;
}


void
ParseNodePrintDOTVisitor::end_visit(const Module &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const ModuleDecl &n)
{
    
    os << reinterpret_cast<intptr_t>(&n) << " -> " 
         << reinterpret_cast<intptr_t>(&n);

    NL;
}


void
ParseNodePrintDOTVisitor::end_visit(const ModuleImport &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const NameTest &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const NamespaceDecl &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const NodeComp &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const OccurrenceIndicator &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const OptionDecl &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const OrderByClause &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const OrderCollationSpec &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const OrderDirSpec &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const OrderEmptySpec &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const OrderModifier &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const OrderSpec &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const OrderSpecList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const OrderingModeDecl &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const PITest &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const Param &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const ParamList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const PositionalVar &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const Pragma &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const PragmaList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const PredicateList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const Prolog &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const QVarInDecl &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const QVarInDeclList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const QuoteAttrValueContent &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const QuoteAttrContentList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const ReverseAxis &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const ReverseStep &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const SIND_DeclList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const SchemaAttributeTest &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const SchemaElementTest &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const SchemaImport &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const SchemaPrefix &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const SequenceType &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const SignList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const SingleType &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const TextTest &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const TypeDeclaration &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const TypeName &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const URILiteralList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const ValueComp &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const VarDecl &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const VarGetsDecl &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const VarGetsDeclList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const VarInDecl &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const VarInDeclList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const VersionDecl &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const VFO_DeclList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const WhereClause &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const Wildcard &n)
{
}



void
ParseNodePrintDOTVisitor::end_visit(const exprnode &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const AdditiveExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const AndExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const AxisStep &n)
{
    if (n.get_forward_step() != NULL)
        os << reinterpret_cast<intptr_t>(&n) << " -> " 
           << reinterpret_cast<intptr_t>(&*n.get_forward_step()) << std::endl;

   if (n.get_reverse_step() != NULL)
       os << reinterpret_cast<intptr_t>(&n) << " -> " 
          << reinterpret_cast<intptr_t>(&*n.get_reverse_step()) << std::endl;

  if (n.get_predicate_list() != NULL)
      os << reinterpret_cast<intptr_t>(&n) << " -> " 
         << reinterpret_cast<intptr_t>(&*n.get_predicate_list()) << std::endl;
}


void
ParseNodePrintDOTVisitor::end_visit(const CDataSection &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const CastExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const CastableExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const CommonContent &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const ComparisonExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const CompAttrConstructor &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const CompCommentConstructor &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const CompDocConstructor &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const CompElemConstructor &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const CompPIConstructor &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const CompTextConstructor &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const ContextItemExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const DirCommentConstructor &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const DirElemConstructor &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const DirElemContent &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const DirPIConstructor &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const EnclosedExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const Expr &n)
{
   for (int i = 0; i < n.numberOfChildren(); ++i)
   {
        os << reinterpret_cast<intptr_t>(&n) << " -> " 
           << reinterpret_cast<intptr_t>(&*(n[i])) << std::endl;
   }
}


// void
// ParseNodePrintDOTVisitor::end_visit(const ExprSingle &n)
// {
//     INDENT_DEC;
//     
//     INDENT;
//     os << "</MainModule>";
//     NL;
// }


void
ParseNodePrintDOTVisitor::end_visit(const ExtensionExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FLWORExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FilterExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FunctionCall &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const IfExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const InstanceofExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const IntersectExceptExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const MultiplicativeExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const NumericLiteral &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const OrExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const OrderedExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const ParenthesizedExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const PathExpr &n)
{
    if (n.get_relpath_expr() != NULL)
        os << reinterpret_cast<intptr_t>(&n) << " -> " 
           << reinterpret_cast<intptr_t>(&*n.get_relpath_expr()) << std::endl;    
}


void
ParseNodePrintDOTVisitor::end_visit(const QuantifiedExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const QueryBody &n)
{
    if (n.get_expr() != NULL)
        os << reinterpret_cast<intptr_t>(&n) << " -> " 
           << reinterpret_cast<intptr_t>(&*n.get_expr()) << std::endl;    
}


void
ParseNodePrintDOTVisitor::end_visit(const RangeExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const RelativePathExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const StringLiteral &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const TreatExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const TypeswitchExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const UnaryExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const UnionExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const UnorderedExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const ValidateExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const VarRef &n)
{
}

void
ParseNodePrintDOTVisitor::end_visit(const DeleteExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const InsertExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const RenameExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const ReplaceExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const RevalidationDecl &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const TransformExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const VarNameList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTAnd &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTAnyallOption &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTBigUnit &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTCaseOption &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTContainsExpr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTContent &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTDiacriticsOption &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTDistance &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTIgnoreOption &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTInclExclStringLiteral &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTInclExclStringLiteralList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTLanguageOption &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTMatchOption &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTMatchOptionProximityList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTMildnot &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTOptionDecl &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTOr &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTOrderedIndicator &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTProximity &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTRange &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTRefOrList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTScope &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTScoreVar &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTSelection &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTStemOption &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTStopwordOption &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTStringLiteralList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTThesaurusID &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTThesaurusList &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTThesaurusOption &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTTimes &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTUnaryNot &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTUnit &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTWildcardOption &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTWindow &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTWords &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTWordsSelection &n)
{
}


void
ParseNodePrintDOTVisitor::end_visit(const FTWordsValue &n)
{
}




} // end namespace


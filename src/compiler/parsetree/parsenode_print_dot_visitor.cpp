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
#include "parsenode_print_dot_visitor.h"
#include "types/typemanager.h"

namespace zorba {

ParseNodePrintDOTVisitor::ParseNodePrintDOTVisitor(std::ostream &aStream)
  : theIndent(0),
    os(aStream)
{
}

void ParseNodePrintDOTVisitor::print(parsenode* n)
{
    os << "digraph query {" << std::endl;
    n->accept(*this);
    os << "}" << std::endl;
}
 

void *ParseNodePrintDOTVisitor::begin_visit(const parsenode &n)
{    
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ParseNode\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
 
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const AbbrevForwardStep &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"AbbrevForwardStep\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const AnyKindTest &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"AnyKindTest\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const AposAttrContentList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"AposAttrContentList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const AposAttrValueContent &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"AposAttrValueContent\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const ArgList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ArgList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const AtomicType &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"AtomicType\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const AttributeTest &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"AttributeTest\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const BaseURIDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"BaseURIDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const BoundarySpaceDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"BoundarySpaceDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const CaseClause &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CaseClause\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const CaseClauseList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CaseClauseList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const CommentTest &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CommentTest\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const ConstructionDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ConstructionDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const CopyNamespacesDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CopyNamespacesDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const DefaultCollationDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DefaultCollationDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const DefaultNamespaceDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DefaultNamespaceDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const DirAttr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DirAttr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const DirAttributeList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DirAttributeList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const DirAttributeValue &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DirAttributeValue\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const DirElemContentList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DirElemContentList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const DocumentTest &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DocumentTest\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const ElementTest &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ElementTest\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const EmptyOrderDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"EmptyOrderDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const ForClause &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ForClause\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
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
//     return no_state;
// }



void *ParseNodePrintDOTVisitor::begin_visit(const ForLetClauseList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ForLetClauseList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const ForwardAxis &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ForwardAxis\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const ForwardStep &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ForwardStep\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FunctionDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FunctionDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const GeneralComp &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"GeneralComp\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const ItemType &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ItemType\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const LetClause &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"LetClause\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const LibraryModule &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"LibraryModule\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const MainModule  &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"MainModule\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;

    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const Module &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"Module\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const ModuleDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ModuleDecl position='" << n.get_location() << "'";
    os << " prefix='" << n.get_prefix() << "' " 
       << "target_namespace='" << n.get_target_namespace() << "'";
    os << ">";
    
    INDENT_INC;
    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const ModuleImport &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ModuleImport\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const NameTest &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"NameTest\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const NamespaceDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"NamespaceDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const NodeComp &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"NodeComp\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const OccurrenceIndicator &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OccurrenceIndicator\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const OptionDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OptionDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}


void *ParseNodePrintDOTVisitor::begin_visit(const GroupByClause &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"GroupByClause\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}

void *ParseNodePrintDOTVisitor::begin_visit(const GroupSpecList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"GroupSpecList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}

void *ParseNodePrintDOTVisitor::begin_visit(const GroupSpec &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"GroupSpec\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}

void *ParseNodePrintDOTVisitor::begin_visit(const GroupCollationSpec &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"GroupCollationSpec\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}

void *ParseNodePrintDOTVisitor::begin_visit(const LetClauseList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"LetClauseList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}


void *ParseNodePrintDOTVisitor::begin_visit(const OrderByClause &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OrderByClause\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const OrderCollationSpec &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OrderCollationSpec\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const OrderDirSpec &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OrderDirSpec\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const OrderEmptySpec &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OrderEmptySpec\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const OrderModifier &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OrderModifier\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const OrderSpec &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OrderSpec\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const OrderSpecList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OrderSpecList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const OrderingModeDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OrderingModeDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const PITest &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"PITest\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const Param &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"Param\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const ParamList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ParamList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const PositionalVar &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"PositionalVar\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const Pragma &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"Pragma\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const PragmaList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"PragmaList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const PredicateList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"PredicateList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const Prolog &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"Prolog\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const QVarInDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"QVarInDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const QVarInDeclList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"QVarInDeclList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const QuoteAttrValueContent &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"QuoteAttrValueContent\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const QuoteAttrContentList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"QuoteAttrContentList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const ReverseAxis &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ReverseAxis\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const ReverseStep &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ReverseStep\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const SIND_DeclList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"SIND_DeclList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const SchemaAttributeTest &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"SchemaAttributeTest\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const SchemaElementTest &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"SchemaElementTest\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const SchemaImport &n)
{
#ifndef ZORBA_NO_XMLSCHEMA
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"SchemaImport\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;
  
    NL;
    return no_state;
#else
  throw XQUERY_EXCEPTION(err::XQST0009);//xml schema not supported
#endif
}



void *ParseNodePrintDOTVisitor::begin_visit(const SchemaPrefix &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"SchemaPrefix\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const SequenceType &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"SequenceType\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const SignList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"SignList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const SingleType &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"SingleType\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const TextTest &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"TextTest\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const TypeDeclaration &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"TypeDeclaration\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const TypeName &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"TypeName\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const URILiteralList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"URILiteralList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const ValueComp &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ValueComp\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const VarDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"VarDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const VarGetsDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"VarGetsDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const VarGetsDeclList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"VarGetsDeclList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const VarInDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"VarInDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const VarInDeclList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"VarInDeclList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const VersionDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"VersionDecl position='" << n.get_location() << "'";
    os << "version='" << n.get_version() << "' " 
       << "encoding='" << n.get_encoding() << "' ";

    os << ">";
    
    INDENT_INC;
    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const VFO_DeclList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"VFO_DeclList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const WhereClause &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"WhereClause\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const Wildcard &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"Wildcard\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const QName &n)
{
  os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
      << "label=\"QName\\n[" 
      << n.get_location() << "]" << "\"]" << std::endl;

  NL;
  return no_state;
}




void *ParseNodePrintDOTVisitor::begin_visit(const exprnode &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"exprnode\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const AdditiveExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"AdditiveExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const AndExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"AndExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const AxisStep &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"AxisStep\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const CDataSection &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CDataSection\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const CastExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CastExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const CastableExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CastableExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const CommonContent &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CommonContent\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const ComparisonExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ComparisonExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const CompAttrConstructor &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CompAttrConstructor\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const CompCommentConstructor &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CompCommentConstructor\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const CompDocConstructor &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CompDocConstructor\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const CompElemConstructor &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CompElemConstructor\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const CompPIConstructor &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CompPIConstructor\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const CompTextConstructor &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CompTextConstructor\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const ContextItemExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ContextItemExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const DirCommentConstructor &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DirCommentConstructor\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const DirElemConstructor &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DirElemConstructor\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const DirElemContent &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DirElemContent\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const DirPIConstructor &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DirPIConstructor\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const EnclosedExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"EnclosedExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const Expr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"Expr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
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
//     return no_state;
// }



void *ParseNodePrintDOTVisitor::begin_visit(const ExtensionExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ExtensionExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FLWORExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FLWORExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FilterExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FilterExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FunctionCall &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FunctionCall\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const IfExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"IfExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const InstanceofExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"InstanceofExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const IntersectExceptExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"IntersectExceptExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const MultiplicativeExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"MultiplicativeExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const NumericLiteral &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"NumericLiteral\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const OrExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OrExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const OrderedExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"OrderedExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const ParenthesizedExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ParenthesizedExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const PathExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"PathExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const QuantifiedExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"QuantifiedExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const QueryBody &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"QueryBody\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const RangeExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"RangeExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const RelativePathExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"RelativePathExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const StringLiteral &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"StringLiteral\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}

void *ParseNodePrintDOTVisitor::begin_visit(const StringConcatExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"StringConcatExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}

void *ParseNodePrintDOTVisitor::begin_visit(const TreatExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"TreatExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const TypeswitchExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"TypeswitchExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const UnaryExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"UnaryExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const UnionExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"UnionExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const UnorderedExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"UnorderedExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const ValidateExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ValidateExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const VarRef &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"VarRef\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}




void *ParseNodePrintDOTVisitor::begin_visit(const DeleteExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"DeleteExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const InsertExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"InsertExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const RenameExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"RenameExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const ReplaceExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"ReplaceExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const RevalidationDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"RevalidationDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const TransformExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"TransformExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const VarNameList &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"VarNameList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}

void *ParseNodePrintDOTVisitor::begin_visit(const VarBinding &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"VarNameList\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}

void *ParseNodePrintDOTVisitor::begin_visit(const TryExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"TryExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}

void *ParseNodePrintDOTVisitor::begin_visit(const CatchListExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CatchListExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}

void *ParseNodePrintDOTVisitor::begin_visit(const CatchExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"CatchExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}

void *ParseNodePrintDOTVisitor::begin_visit(const FTAnd &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTAnd\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTAnyallOption &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTAnyallOption\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTBigUnit &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTBigUnit\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTCaseOption &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTCaseOption\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTContainsExpr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTContainsExpr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTContent &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTContent\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTDiacriticsOption &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTDiacriticsOption\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTDistance &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTDistance\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}


void *ParseNodePrintDOTVisitor::begin_visit(const FTExtensionOption &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTExtensionOption\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}


void *ParseNodePrintDOTVisitor::begin_visit(const FTExtensionSelection &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTExtensionSelection\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}


void *ParseNodePrintDOTVisitor::begin_visit(const FTIgnoreOption &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTIgnoreOption\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTLanguageOption &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTLanguageOption\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTMatchOptions &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTMatchOptions\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTMildNot &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTMildNot\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTOptionDecl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTOptionDecl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTOr &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTOr\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTOrder &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTOrder\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTPrimaryWithOptions &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTPrimaryWithOptions\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTRange &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTRange\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTScope &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTScope\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTScoreVar &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTScoreVar\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTSelection &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTSelection\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTStemOption &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTStemOption\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTStopWordOption &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTStopWordOption\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}


void *ParseNodePrintDOTVisitor::begin_visit(const FTStopWords &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTStopWords\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}


void *ParseNodePrintDOTVisitor::begin_visit(const FTStopWordsInclExcl &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTStopWordsInclExcl\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTThesaurusID &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTThesaurusID\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTThesaurusOption &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTThesaurusOption\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTTimes &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTTimes\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTUnaryNot &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTUnaryNot\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTUnit &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTUnit\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTWeight &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTWeight\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTWildCardOption &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTWildCardOption\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTWindow &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTWindow\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTWords &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTWords\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void *ParseNodePrintDOTVisitor::begin_visit(const FTWordsTimes &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTWordsTimes\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}


void *ParseNodePrintDOTVisitor::begin_visit(const FTWordsValue &n)
{
    os << reinterpret_cast<intptr_t>(&n) << "[" << std::endl
          << "label=\"FTWordsValue\\n[" 
          << n.get_location() << "]" << "\"]" << std::endl;

    NL;
    return no_state;
}



void ParseNodePrintDOTVisitor::end_visit(const parsenode&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const AbbrevForwardStep &n, void*)
{
    if (n.get_node_test() != NULL)
      os << reinterpret_cast<intptr_t>(&n) << " -> " 
         << reinterpret_cast<intptr_t>(&*n.get_node_test()) << std::endl;    
}


void ParseNodePrintDOTVisitor::end_visit(const AnyKindTest&, void*)
{
}


void ParseNodePrintDOTVisitor::end_visit(const AposAttrContentList&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const AposAttrValueContent&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const ArgList&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const AtomicType&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const AttributeTest&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const BaseURIDecl&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const BoundarySpaceDecl&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const CaseClause&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const CaseClauseList&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const CommentTest&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const ConstructionDecl&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const CopyNamespacesDecl&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const DefaultCollationDecl&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const DefaultNamespaceDecl&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const DirAttr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const DirAttributeList&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const DirAttributeValue&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const DirElemContentList&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const DocumentTest&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const ElementTest&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const EmptyOrderDecl&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const ForClause&, void*)
{
}


// void
// ParseNodePrintDOTVisitor::end_visit(const ForLetClause &n, void *visit_state)
// {
//     INDENT_DEC;
//     
//     INDENT;
//     os << "</MainModule>";
//     NL;
// }



void ParseNodePrintDOTVisitor::end_visit(const ForLetClauseList&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const ForwardAxis&, void*)
{

}



void ParseNodePrintDOTVisitor::end_visit(const ForwardStep &n, void*)
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



void ParseNodePrintDOTVisitor::end_visit(const FunctionDecl&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const GeneralComp&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const ItemType&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const LetClause&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const LibraryModule &n, void*)
{
    os << reinterpret_cast<intptr_t>(&n) << " -> " 
          << reinterpret_cast<intptr_t>(&*n.get_decl());

       os << reinterpret_cast<intptr_t>(&n) << " -> " 
          << reinterpret_cast<intptr_t>(&*n.get_prolog());
    NL;
}



void ParseNodePrintDOTVisitor::end_visit(const MainModule  &n, void*)
{
    if (n.get_prolog() != NULL)
        os << reinterpret_cast<intptr_t>(&n) << " -> " 
           << reinterpret_cast<intptr_t>(&*n.get_prolog()) << std::endl;
  
    if (n.get_query_body() != NULL)
        os << reinterpret_cast<intptr_t>(&n) << " -> " 
           << reinterpret_cast<intptr_t>(&*n.get_query_body()) << std::endl;
}



void ParseNodePrintDOTVisitor::end_visit(const Module&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const ModuleDecl &n, void*)
{
    
    os << reinterpret_cast<intptr_t>(&n) << " -> " 
         << reinterpret_cast<intptr_t>(&n);

    NL;
}



void ParseNodePrintDOTVisitor::end_visit(const ModuleImport&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const NameTest&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const NamespaceDecl&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const NodeComp&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const OccurrenceIndicator&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const OptionDecl&, void*)
{
}


void ParseNodePrintDOTVisitor::end_visit(const GroupByClause&, void*)
{}

void ParseNodePrintDOTVisitor::end_visit(const GroupSpecList&, void*)
{}

void ParseNodePrintDOTVisitor::end_visit(const GroupSpec&, void*)
{}

void ParseNodePrintDOTVisitor::end_visit(const GroupCollationSpec&, void*)
{}

void ParseNodePrintDOTVisitor::end_visit(const LetClauseList&, void*)
{}


void ParseNodePrintDOTVisitor::end_visit(const OrderByClause&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const OrderCollationSpec&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const OrderDirSpec&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const OrderEmptySpec&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const OrderModifier&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const OrderSpec&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const OrderSpecList&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const OrderingModeDecl&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const PITest&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const Param&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const ParamList&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const PositionalVar&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const Pragma&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const PragmaList&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const PredicateList&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const Prolog&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const QVarInDecl&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const QVarInDeclList&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const QuoteAttrValueContent&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const QuoteAttrContentList&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const ReverseAxis&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const ReverseStep&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const SIND_DeclList&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const SchemaAttributeTest&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const SchemaElementTest&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const SchemaImport&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const SchemaPrefix&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const SequenceType&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const SignList&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const SingleType&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const TextTest&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const TypeDeclaration&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const TypeName&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const URILiteralList&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const ValueComp&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const VarDecl&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const VarGetsDecl&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const VarGetsDeclList&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const VarInDecl&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const VarInDeclList&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const VersionDecl&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const VFO_DeclList&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const WhereClause&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const Wildcard&, void*)
{
}


void ParseNodePrintDOTVisitor::end_visit(const QName&, void*)
{
}


void ParseNodePrintDOTVisitor::end_visit(const exprnode&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const AdditiveExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const AndExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const AxisStep &n, void*)
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



void ParseNodePrintDOTVisitor::end_visit(const CDataSection&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const CastExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const CastableExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const CommonContent&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const ComparisonExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const CompAttrConstructor&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const CompCommentConstructor&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const CompDocConstructor&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const CompElemConstructor&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const CompPIConstructor&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const CompTextConstructor&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const ContextItemExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const DirCommentConstructor&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const DirElemConstructor&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const DirElemContent&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const DirPIConstructor&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const EnclosedExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const Expr &n, void*)
{
   for (int i = 0; i < n.numberOfChildren(); ++i)
   {
        os << reinterpret_cast<intptr_t>(&n) << " -> " 
           << reinterpret_cast<intptr_t>(&*(n[i])) << std::endl;
   }
}


// void
// ParseNodePrintDOTVisitor::end_visit(const ExprSingle &n, void *visit_state)
// {
//     INDENT_DEC;
//     
//     INDENT;
//     os << "</MainModule>";
//     NL;
// }



void ParseNodePrintDOTVisitor::end_visit(const ExtensionExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FLWORExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FilterExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FunctionCall&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const IfExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const InstanceofExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const IntersectExceptExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const MultiplicativeExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const NumericLiteral&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const OrExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const OrderedExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const ParenthesizedExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const PathExpr &n, void*)
{
    if (n.get_relpath_expr() != NULL)
        os << reinterpret_cast<intptr_t>(&n) << " -> " 
           << reinterpret_cast<intptr_t>(&*n.get_relpath_expr()) << std::endl;    
}



void ParseNodePrintDOTVisitor::end_visit(const QuantifiedExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const QueryBody &n, void*)
{
    if (n.get_expr() != NULL)
        os << reinterpret_cast<intptr_t>(&n) << " -> " 
           << reinterpret_cast<intptr_t>(&*n.get_expr()) << std::endl;    
}



void ParseNodePrintDOTVisitor::end_visit(const RangeExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const RelativePathExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const StringLiteral&, void*)
{
}

void ParseNodePrintDOTVisitor::end_visit(const StringConcatExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const TreatExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const TypeswitchExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const UnaryExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const UnionExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const UnorderedExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const ValidateExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const VarRef&, void*)
{
}


void ParseNodePrintDOTVisitor::end_visit(const DeleteExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const InsertExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const RenameExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const ReplaceExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const RevalidationDecl&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const TransformExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const VarNameList&, void*)
{
}


void ParseNodePrintDOTVisitor::end_visit(const VarBinding&, void*)
{
}


void ParseNodePrintDOTVisitor::end_visit(const TryExpr&, void*)
{
}


void ParseNodePrintDOTVisitor::end_visit(const CatchListExpr&, void*)
{
}


void ParseNodePrintDOTVisitor::end_visit(const CatchExpr&, void*)
{
}


void ParseNodePrintDOTVisitor::end_visit(const FTAnd&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTAnyallOption&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTBigUnit&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTCaseOption&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTContainsExpr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTContent&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTDiacriticsOption&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTDistance&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTIgnoreOption&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTStopWordsInclExcl&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTLanguageOption&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTMildNot&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTOptionDecl&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTOr&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTRange&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTScope&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTScoreVar&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTSelection&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTStemOption&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTStopWordOption&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTStringLiteralList&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTThesaurusID&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTThesaurusList&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTThesaurusOption&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTTimes&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTUnaryNot&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTUnit&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTWildcardOption&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTWindow&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTWords&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTWordsSelection&, void*)
{
}



void ParseNodePrintDOTVisitor::end_visit(const FTWordsValue&, void*)
{
}




} // end namespace
/* vim:set et sw=2 ts=2: */

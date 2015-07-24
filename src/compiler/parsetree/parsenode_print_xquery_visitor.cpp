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

#include "compiler/parsetree/parsenode_print_xquery_visitor.h"

#include <ostream>
#include <string>
#include <map>
#include <stack>

#include "compiler/parsetree/parsenode_visitor.h"

#include "store/api/update_consts.h"

#include "diagnostics/assert.h"


#define DEFAULT_BEGIN_VISIT(type)                    \
  void* begin_visit(const type&){ return no_state; }

#define DEFAULT_END_VISIT(type)                      \
  void end_visit(const type&, void*){}

#define DEFAULT_VISIT(type)                          \
  DEFAULT_BEGIN_VISIT(type)                          \
  DEFAULT_END_VISIT(type)                            \

using namespace std;

namespace zorba {

class ParseNodePrintXQueryVisitor: public parsenode_visitor
{
private:
  std::ostream& os;
  FunctionIndex theFunctionIndex;

public:

ParseNodePrintXQueryVisitor(std::ostream& aStream): os(aStream)
{
}


FunctionIndex& getFunctionIndex()
{
  return theFunctionIndex;
}


ParseNodePrintXQueryVisitor* print(const parsenode* p)
{
  p->accept(*this);
  return this;
}


void* begin_visit(const AbbrevForwardStep& n)
{
  if(n.get_attr_bit())
  {
    os << '@';
  }
  return no_state;
}


DEFAULT_END_VISIT(AbbrevForwardStep)

DEFAULT_VISIT (AnnotationParsenode)

DEFAULT_VISIT (AnnotationListParsenode)

DEFAULT_VISIT (AnnotationLiteralListParsenode)

DEFAULT_BEGIN_VISIT (AnyKindTest)


void end_visit(const AnyKindTest& n, void* state)
{
  os << "node()";
}


DEFAULT_VISIT (AposAttrContentList)


void* begin_visit(const AposAttrValueContent& n)
{
  if(!n.get_apos_atcontent().empty())
  {
    os << n.get_apos_atcontent();
  }
  else
  {
    n.get_common_content()->accept(*this);
  }
  return 0;
}


DEFAULT_END_VISIT (AposAttrValueContent)


void * begin_visit(const ArgumentPlaceholder& n)
{
  os << "?";
  return 0;
}


DEFAULT_END_VISIT (ArgumentPlaceholder)

void* begin_visit(const ArgList& n)
{
  for (int i=0; i<(int)n.size(); ++i) {
    if(i > 0)
    {
      os << ", ";
    }
    const exprnode* e_p = &*(n[i]);
    e_p->accept(*this);
  }
  return 0;
}


DEFAULT_END_VISIT(ArgList)


DEFAULT_BEGIN_VISIT(GeneralizedAtomicType)


void end_visit(const GeneralizedAtomicType& n, void* state)
{
  os << n.get_qname()->get_qname();
}


DEFAULT_BEGIN_VISIT(SimpleType)


void end_visit(const SimpleType& n, void* state)
{
  os << n.get_qname()->get_qname();
}


void* begin_visit(const AttributeTest& n)
{
  os << "attribute(";
  return no_state;
}


void end_visit(const AttributeTest& n, void*)
{
  os << ")";
}


void* begin_visit(const BaseURIDecl& n)
{
  os << "declare base-uri \"" << n.get_base_uri() << "\";";
  return no_state;
}


DEFAULT_END_VISIT (BaseURIDecl);


void* begin_visit(const BoundarySpaceDecl& n)
{
  os << "declare boundary-space ";
  switch(n.get_boundary_space_mode())
  {
  case StaticContextConsts::preserve_space:
    os << "preserve";
    break;
  case StaticContextConsts::strip_space:
    os << "strip";
    break;
  default:
    ZORBA_ASSERT(false);
  }
  os << ';';
  return no_state;
}

DEFAULT_END_VISIT (BoundarySpaceDecl)


void* begin_visit(const CaseClause& n)
{
  os << "case ";

  if (n.get_varname())
  {
    os << "$" << n.get_varname()->get_qname() << " as ";
  }

  csize numTypes = n.num_types();
  for (csize i = 0; i < numTypes; ++i)
    n.get_type(i)->accept(*this);

  os << "return ";
  n.get_expr()->accept(*this);

  return no_state;
}


DEFAULT_END_VISIT (CaseClause)


DEFAULT_VISIT (CaseClauseList) //@checked


void* begin_visit(const CommentTest& n)
{
  os << "comment()";
  return no_state;
}


DEFAULT_END_VISIT (CommentTest);

void* begin_visit(const ConstructionDecl& n)
{
  os << "declare construction ";
  switch(n.get_mode())
  {
  case StaticContextConsts::cons_preserve:
    os << "preserve";
    break;
  case StaticContextConsts::cons_strip:
    os << "strip";
    break;
  default:
    ZORBA_ASSERT(false);
  }
  os << ';';
  return no_state;
}

DEFAULT_END_VISIT (ConstructionDecl)

void* begin_visit(const CopyNamespacesDecl& n)
{
  os << "declare copy-namespaces ";

  if (n.preserve_ns())
    os << "preserve,";
  else
    os << "no-preserve,";

  if (n.inherit_ns())
    os << "inherit";
  else
    os << "no-inherit";

  return 0;
}

DEFAULT_END_VISIT (CopyNamespacesDecl)

void* begin_visit(const DefaultCollationDecl& n)
{
  os << "declare default collation " << n.get_collation();
  return 0;
}

DEFAULT_END_VISIT (DefaultCollationDecl)

void* begin_visit(const DefaultNamespaceDecl& n)
{
  os << "declare default ";
  switch(n.get_mode())
  {
  case ParseConstants::ns_element_default:
    os << "element ";
    break;
  case ParseConstants::ns_function_default:
    os << "function ";
    break;
  }
  os << "namespace ";
  os << n.get_default_namespace();
  return 0;
}

DEFAULT_END_VISIT (DefaultNamespaceDecl)

    void* begin_visit(const DirAttr& n)
    {
      n.get_name()->accept(*this);
      os << '=';
      n.get_value()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (DirAttr)

    DEFAULT_VISIT (DirAttributeList) //@checked

    void* begin_visit(const DirAttributeValue& n)
    {
      if(n.get_quot_attr_content())
      {
        os << '"';
        n.get_quot_attr_content()->accept(*this);
        os << '"';
      } else {
        os << '\'';
        n.get_apos_attr_content()->accept(*this);
        os << '\'';
      }
      return 0;
    }
    DEFAULT_END_VISIT (DirAttributeValue)

    DEFAULT_VISIT (DirElemContentList) //@checked

    void* begin_visit(const DocumentTest& n)
    {
      os << "document(";
      return no_state;
    }
    void end_visit(const DocumentTest& n, void*)
    {
      os << ')';
    }

    void* begin_visit(const ElementTest& n)
    {
      os << "element(";
      if(n.isWildcard())
      {
        os << '*';
      } else {
        os << n.getElementName()->get_qname();
      }
      if(n.getTypeName() != 0)
      {
        os << "," << n.getTypeName()->get_name()->get_qname();
      }
      os << ")";
      return no_state;
    }
    DEFAULT_END_VISIT (ElementTest)

void* begin_visit(const EmptyOrderDecl& n)
{
  os << "declare default order empty ";
  switch(n.get_mode())
  {
  case StaticContextConsts::empty_greatest:
    os << "greatest";
    break;
  case StaticContextConsts::empty_least:
    os << "least";
    break;
  default:
    ZORBA_ASSERT(false);
  }
  return 0;
}


DEFAULT_END_VISIT (EmptyOrderDecl)

void* begin_visit(const ForClause& n)
{
  os << "for $";
  n.get_vardecl_list()->accept(*this);
  return 0;
}
DEFAULT_END_VISIT (ForClause)

DEFAULT_VISIT (FLWORClauseList) //@checked


void* begin_visit(const ForwardAxis& n)
{
  os << ParseConstants::decode_axis_kind(n.get_axis());
  os << "::";
  return no_state;
}

DEFAULT_END_VISIT (ForwardAxis)


DEFAULT_VISIT (ForwardStep)//@checked


void* begin_visit(const FunctionDecl& n)
{
  Parameters lParameters;
  os << "declare ";

  if (n.is_updating())
    os << "updating ";

  AnnotationListParsenode* lAnns = n.get_annotations();
  if (lAnns) {

    for (size_t i = 0; i < lAnns->size(); ++i)
    {
      AnnotationParsenode* lAnn = (*lAnns)[i];

      AnnotationLiteralListParsenode* lLits = lAnn->get_literals().getp();

      std::ostringstream lAttrValue;
      if (lLits)
      {
        for (size_t j = 0; j < lLits->size(); ++j)
        {
          if (j > 0)
            lAttrValue << " ";

          exprnode* lLit = (*lLits)[j].getp();
          StringLiteral* l = dynamic_cast<StringLiteral*>(lLit);
          if (l)
          {
            lAttrValue << l->get_strval();
          }
          else
          {
            NumericLiteral* n = dynamic_cast<NumericLiteral*>(lLit);
            assert(n);
            lAttrValue << n->toString();
          }
        }
      }

      os << "%";
      if(lAnn->get_qname()->is_eqname())
      {
        os << '"' << lAnn->get_qname()->get_namespace() << '"' << ":";
      }
      else
      {
        if(!lAnn->get_qname()->get_prefix().empty())
        {
          os << lAnn->get_qname()->get_prefix() << ":";
        }
      }
      os << lAnn->get_qname()->get_localname();
      if (!lAttrValue.str().empty())
      {
        os << "(" << lAttrValue.str() << ")";
      }
      os << " ";
    }
  }

  os << "function ";

  n.get_name()->accept(*this);

  os << '(';
  if(n.get_paramlist()) {
    n.get_paramlist()->accept(*this);
  }
  os << ')';

  if(n.get_return_type()) {
    os << " as ";
    stringstream lReturnType;
    print_parsetree_xquery(lReturnType, n.get_return_type().getp());
    //n.get_return_type()->accept(*this);
    os << lReturnType.str();
    lParameters.push(lReturnType.str());
  }

  if(n.get_body())
  {
    os << '{';
    n.get_body()->accept(*this);
    os << '}';
  }
  else if(n.is_external())
  {
    os << " external";
  }

  if(n.get_paramlist())
  {
    const rchandle<ParamList> paramList = n.get_paramlist();
    for (vector<rchandle<Param> >::const_iterator it = paramList->begin();
         it != paramList->end();
         ++it)
    {
      const Param* param = &**it;
      stringstream lParamString;
      print_parsetree_xquery(lParamString, param);
      lParameters.push(lParamString.str());
    }
  }
  theFunctionIndex.insert(make_pair(n.get_name()->get_qname(), lParameters));
  return 0;
}


DEFAULT_END_VISIT (FunctionDecl)


void* begin_visit(const GeneralComp& n)
{
  switch(n.get_type())
  {
  case ParseConstants::op_eq:
    os << '=';
    break;
  case ParseConstants::op_ne:
    os << "!=";
    break;
  case ParseConstants::op_lt:
    os << '<';
    break;
  case ParseConstants::op_le:
    os << "<=";
    break;
  case ParseConstants::op_gt:
    os << '>';
    break;
  case ParseConstants::op_ge:
    os << ">=";
    break;
  }
  return no_state;
}

DEFAULT_END_VISIT (GeneralComp)


void* begin_visit(const ItemType& n)
{
  os << "item()";
  return no_state;
}

DEFAULT_END_VISIT (ItemType)


void* begin_visit(const StructuredItemType& n)
{
  os << "structured-item()";
  return no_state;
}

DEFAULT_END_VISIT(StructuredItemType)


    void* begin_visit(const LetClause& n)
    {
      os << "let ";
      switch(n.for_or_let())
      {
        case ForOrLetClause::for_clause:
          os << "score ";
          break;
        case ForOrLetClause::let_clause:
          break;
      }
      return no_state;
    }
DEFAULT_END_VISIT (LetClause)

DEFAULT_VISIT (LibraryModule) //@checked

DEFAULT_VISIT (Literal)

DEFAULT_VISIT (MainModule) //@checked

void* begin_visit(const ModuleDecl& n)
{
  os << "module namespace " << n.get_prefix() << "=" << n.get_target_namespace() << ';';
  return 0;
}
DEFAULT_END_VISIT (ModuleDecl)


void* begin_visit(const ModuleImport& n)
{
  os << "import module ";
  if(!n.get_prefix().empty())
  {
    os << "namespace " << n.get_prefix() << '=';
  }
  os << n.get_uri();
  if(n.get_at_list())
  {
    n.get_at_list()->accept(*this);
  }
  return 0;
}
DEFAULT_END_VISIT (ModuleImport)


void* begin_visit(const NameTest& n)
{
  if(n.getQName() != 0)
  {
    os << n.getQName()->get_qname();
  } else {
    n.getWildcard()->accept(*this);
  }
  return no_state;
}
DEFAULT_END_VISIT (NameTest)

DEFAULT_VISIT (NamespaceDecl)

void* begin_visit(const NodeComp& n)
{
  switch(n.get_type())
  {
    case ParseConstants::op_is:
      os << "is";
      break;
    case ParseConstants::op_precedes:
      os << "<<";
      break;
    case ParseConstants::op_follows:
      os << ">>";
      break;
  }
  return no_state;
}
DEFAULT_END_VISIT (NodeComp)

void* begin_visit(const OccurrenceIndicator& n)
{
  switch(n.get_type())
  {
    case ParseConstants::occurs_never:
      break;
    case ParseConstants::occurs_exactly_one:
      break;
    case ParseConstants::occurs_optionally:
      os << '?';
      break;
    case ParseConstants::occurs_zero_or_more:
      os << '*';
      break;
    case ParseConstants::occurs_one_or_more:
      os << '+';
      break;
  }
  return no_state;
}
DEFAULT_END_VISIT (OccurrenceIndicator)

void* begin_visit(const OptionDecl& n)
{
  os << "declare option " << n.get_qname()->get_qname() << ' ' << n.get_val() << ';';
  return 0;
}
DEFAULT_END_VISIT (OptionDecl)

void* begin_visit(const GroupByClause& n)
{
  os << "group by ";
  return no_state;
}
DEFAULT_END_VISIT (GroupByClause)

    void* begin_visit(const GroupSpecList& n)
    {
      for (unsigned int i=0; i<n.size(); ++i)
      {
        const GroupSpec *e_p = &*n[i];
        e_p->accept(*this);
      }
      return 0;
    }
    DEFAULT_END_VISIT (GroupSpecList)

    void* begin_visit(const GroupSpec& n)
    {
      os << "$" << n.get_var_name();
      n.get_collation_spec()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (GroupSpec)

    DEFAULT_VISIT (GroupCollationSpec)

    void* begin_visit(const OrderByClause& n)
    {
      if(n.get_stable_bit())
      {
        os << "stable ";
      }
      os << "order by ";
      n.get_spec_list()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (OrderByClause)

    void* begin_visit(const OrderCollationSpec& n)
    {
      os << "collation " << n.get_uri();
      return 0;
    }
    DEFAULT_END_VISIT (OrderCollationSpec)


    void* begin_visit(const OrderDirSpec& n)
    {
      switch(n.getValue())
      {
        case ParseConstants::dir_ascending:
          os << "ascending ";
          break;
        case ParseConstants::dir_descending:
          os << "descending ";
          break;
      }
      return 0;
    }
    DEFAULT_END_VISIT (OrderDirSpec)


void* begin_visit(const OrderEmptySpec& n)
{
  os << "empty ";
  switch(n.getValue())
  {
  case StaticContextConsts::empty_greatest:
    os << "greatest ";
    break;
  case StaticContextConsts::empty_least:
    os << "least ";
    break;
  default:
    ZORBA_ASSERT(false);
  }
  return 0;
}

DEFAULT_END_VISIT (OrderEmptySpec)

DEFAULT_VISIT (OrderModifierPN)//@checked

DEFAULT_VISIT (OrderSpec) //@checked

    void* begin_visit(const OrderSpecList& n)
    {
      for(unsigned int i=0; i<n.size(); i++)
      {
        if(i>0)
        {
          os << ',';
        }
        const parsenode *e_p = &*(n[i]);
        e_p->accept(*this);
      }
      return 0;
    }
    DEFAULT_END_VISIT (OrderSpecList)

    void* begin_visit(const PITest& n)
    {
      os << "processing-instruction(";
      os << n.get_target();
      os << ")";
      return no_state;
    }
    DEFAULT_END_VISIT (PITest);

void* begin_visit(const OrderingModeDecl& n)
{
  os << "declare ordering";
  switch(n.get_mode())
  {
  case StaticContextConsts::ordered:
    os << "ordered ";
    break;
  case StaticContextConsts::unordered:
    os << "unordered ";
    break;
  default:
    ZORBA_ASSERT(false);
  }
  return 0;
}


DEFAULT_END_VISIT (OrderingModeDecl)


void* begin_visit(const Param& n)
{
  os << '$';
  os << n.get_name()->get_qname();

  if(n.get_typedecl())
  {
    os << " as ";
  }

  return no_state;
}


DEFAULT_END_VISIT (Param)



void* begin_visit(const ParamList& n)
{
  for (vector<rchandle<Param> >::const_iterator it = n.begin();
       it != n.end();
       ++it)
  {
    if(it != n.begin())
    {
      os << ", ";
    }
    const parsenode *e_p = &**it;
    if(e_p)
    {
      e_p->accept(*this);
    }
  }
  return 0;
}


DEFAULT_END_VISIT (ParamList)

    void* begin_visit(const PositionalVar& n)
    {
      os << "at $" << n.get_name()->get_qname();
      return 0;
    }
    DEFAULT_END_VISIT (PositionalVar)

    void* begin_visit(const Pragma& n)
    {
      os << "(#" << n.get_name()->get_qname() << ' ' << n.get_pragma_lit();
      return 0;
    }
    DEFAULT_END_VISIT (Pragma)

    DEFAULT_VISIT (PragmaList) //@checked
    DEFAULT_VISIT (PredicateList)//@checked
    DEFAULT_VISIT (Prolog)//@checked

    void* begin_visit(const QVarInDecl& n)
    {
      os << n.get_name();
      n.get_typedecl()->accept(*this);
      os << " in ";
      n.get_val()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (QVarInDecl)

    void* begin_visit(const QVarInDeclList& n)
    {
      for(int i=0; i<(int)n.size(); ++i)
      {
        if(i)
        {
          os << ',';
        }
        os << '$';
        const QVarInDecl* node = &*n[i];
        node->accept(*this);
      }
      return 0;
    }
    DEFAULT_END_VISIT (QVarInDeclList)

    DEFAULT_VISIT (QuoteAttrValueContent)

    DEFAULT_VISIT (QuoteAttrContentList)


void* begin_visit(const ReverseAxis& n)
{
  os << ParseConstants::decode_axis_kind(n.get_axis());
  os << "::";
  return no_state;
}
DEFAULT_END_VISIT (ReverseAxis);


    DEFAULT_VISIT (ReverseStep)
    DEFAULT_VISIT (SIND_DeclList)

    void* begin_visit(const SchemaAttributeTest& n)
    {
      os << "schema-attribute(" << n.get_attr()->get_qname() << ")";
      return 0;
    }
    DEFAULT_END_VISIT (SchemaAttributeTest);

    void* begin_visit(const SchemaElementTest& n)
    {
      os << "schema-element(" << n.get_elem()->get_qname() << ")";
      return 0;
    }
    DEFAULT_END_VISIT (SchemaElementTest)

    void* begin_visit(const SchemaPrefix& n)
    {
      if(n.get_default_bit())
      {
        os << "default element namespace ";
      } else {
        os << "namespace " << n.get_prefix() << '=';
      }
      return 0;
    }
    DEFAULT_END_VISIT (SchemaPrefix)

    void* begin_visit(const SchemaImport& n)
    {
      os << "import schema ";
      if(n.get_prefix())
      {
        n.get_prefix()->accept(*this);;
      }
      os << n.get_uri() << " at ";
      n.get_at_list()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (SchemaImport)

    void* begin_visit(const SequenceTypeAST& n)
    {
      if(n.get_itemtype() == 0)
      {
        os << "empty-sequence()";
      }
      return no_state;
    }
    DEFAULT_END_VISIT (SequenceTypeAST)

    void* begin_visit(const SignList& n)
    {
      if(n.get_sign())
      {
        os << '-';
      } else {
        os << '+';
      }
      return 0;
    }
    DEFAULT_END_VISIT (SignList)

    DEFAULT_BEGIN_VISIT (SingleType)
    void end_visit(const SingleType& n, void*)
    {
      if(n.get_hook_bit())
      {
        os << '?';
      }
    }

  void* begin_visit(const NamespaceTest& n)
  {
    os << "namespace-node()";
    return 0;
  }
  DEFAULT_END_VISIT (NamespaceTest)

  void* begin_visit(const TextTest& n)
  {
    os << "text()";
    return 0;
  }
  DEFAULT_END_VISIT (TextTest)

  void* begin_visit(const TypeName& n)
  {
    os << n.get_name()->get_qname();
    return 0;
  }
  DEFAULT_END_VISIT (TypeName)

    void* begin_visit(const URILiteralList& n)
    {
      for(ulong i = 0; i < n.size(); i++)
      {
        if(i!=0)
        {
          os << ',';
        }
        os << n[i];
      }
      return 0;
    }
    DEFAULT_END_VISIT (URILiteralList)

    void* begin_visit(const ValueComp& n)
    {
      switch(n.get_type())
      {
        case ParseConstants::op_val_eq:
          os << "eq";
          break;
        case ParseConstants::op_val_ne:
          os << "ne";
          break;
        case ParseConstants::op_val_lt:
          os << "lt";
          break;
        case ParseConstants::op_val_le:
          os << "le";
          break;
        case ParseConstants::op_val_gt:
          os << "gt";
          break;
        case ParseConstants::op_val_ge:
          os << "ge";
          break;
        case ParseConstants::op_val_not:
          os << "not";
          break;
      }
      return 0;
    }
    DEFAULT_END_VISIT (ValueComp)

    void* begin_visit(const CtxItemDecl& n)
    {
      os << "declare context item ";
      if(n.get_type())
      {
        os << "as ";
        n.get_type()->accept(*this);
      }
      if(n.is_external())
      {
        os << "external ";
      }
      if(n.get_expr())
      {
        os << ":= ";
        n.get_expr()->accept(*this);
      }
      return 0;
    }
    DEFAULT_END_VISIT (CtxItemDecl);

    DEFAULT_VISIT (CollectionDecl)
    DEFAULT_VISIT (AST_IndexDecl)
    DEFAULT_VISIT (IndexKeySpec)
    DEFAULT_VISIT (IndexKeyList)
    DEFAULT_VISIT (IntegrityConstraintDecl)

    void* begin_visit(const GlobalVarDecl& n)
    {
      os << "declare variable $" << n.get_var_name()->get_qname();

      if (n.get_var_type())
      {
        n.get_var_type()->accept(*this);
      }

      if (n.is_extern())
      {
        os << "external";
      }

      if (n.get_binding_expr())
      {
        os << ":=";
        n.get_binding_expr()->accept(*this);
      }
      return 0;
    }

    DEFAULT_END_VISIT (GlobalVarDecl)

    void* begin_visit(const LocalVarDecl& n)
    {
      os << "variable $" << n.get_var_name()->get_qname();

      if (n.get_var_type())
      {
        n.get_var_type()->accept(*this);
      }

      if (n.get_binding_expr())
      {
        os << ":=";
        n.get_binding_expr()->accept(*this);
      }
      return 0;
    }

    DEFAULT_END_VISIT (LocalVarDecl)


    void* begin_visit(const VarGetsDecl& n)
    {
      os << "$" << n.get_var_name()->get_qname() << " ";
      if(n.get_var_type())
      {
        os << "as ";
        n.get_var_type()->accept(*this);
      }
      if(n.get_binding_expr())
      {
        os << " := ";
        n.get_binding_expr()->accept(*this);
      }
      return 0;
    }
    DEFAULT_END_VISIT (VarGetsDecl);

    void* begin_visit(const VarGetsDeclList& n)
    {
      for(unsigned int i=0; i<n.size(); ++i)
      {
        if(i)
        {
          os << ", ";
        }
        const parsenode *e_p = &*(n[i]);
        e_p->accept(*this);
      }
      return 0;
    }
    DEFAULT_END_VISIT (VarGetsDeclList)

    void* begin_visit(const VarInDecl& n)
    {
      os << n.get_var_name()->get_qname() << ' ';
      if(n.get_var_type())
      {
        os << "as ";
        n.get_var_type()->accept(*this);
      }
      if(n.get_posvar())
      {
        n.get_posvar()->accept(*this);
      }
      if(n.get_ftscorevar())
      {
        n.get_ftscorevar()->accept(*this);
      }
      os << "in ";
      n.get_binding_expr()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (VarInDecl)

    void* begin_visit(const VarInDeclList& n)
    {
      for(unsigned int i=0; i < n.size(); ++i)
      {
        if(i)
        {
          os << ", ";
        }
        os << '$';
        (&*(n[i]))->accept(*this);
      }
      return 0;
    }
    DEFAULT_END_VISIT (VarInDeclList)

    void* begin_visit(const VersionDecl& n)
    {
      os << "xquery version" << n.get_version();
      if(!n.get_encoding().empty())
      {
        os << " encoding " << n.get_encoding();
      }
      os << ";";
      return 0;
    }
    DEFAULT_END_VISIT (VersionDecl)

    DEFAULT_VISIT (VFO_DeclList)

    void* begin_visit(const WhereClause& n)
    {
      os << "where ";
      n.get_predicate()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (WhereClause)

    void* begin_visit(const CountClause& n)
    {
      os << "count $" << n.get_varname();
      return 0;
    }
    DEFAULT_END_VISIT (CountClause)

    void* begin_visit(const Wildcard& n)
    {
      switch(n.getKind())
      {
        case ParseConstants::wild_all:
          os << '*';
          break;
        case ParseConstants::wild_elem:
          if (n.isEQnameMatch())
            os << "\"" << n.getNsOrPrefix() << "\":*";
          else
            os << n.getNsOrPrefix() << ":*";
          break;
         case ParseConstants::wild_prefix:
          os << "*:" << n.getLocalName();
          break;
      }
      return 0;
    }
    DEFAULT_END_VISIT (Wildcard)

    void* begin_visit(const QName& n)
    {
      os << n.get_qname();
      return 0;
    }
    DEFAULT_END_VISIT (QName)

    DEFAULT_VISIT (DecimalFormatNode);

    /* expressions */
    void* begin_visit(const AdditiveExpr& n)
    {
      n.get_add_expr()->accept(*this);
      switch(n.get_add_op())
      {
        case ParseConstants::op_plus:
          os << '+';
          break;
        case ParseConstants::op_minus:
          os << '-';
          break;
      }
      n.get_mult_expr()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (AdditiveExpr)

    void* begin_visit(const AndExpr& n)
    {
      n.get_and_expr()->accept(*this);
      os << " and ";
      n.get_comp_expr();
      return 0;
    }
    DEFAULT_END_VISIT (AndExpr)

    DEFAULT_VISIT (AxisStep)

    void* begin_visit(const CDataSection& n)
    {
      os << "<![CDATA[" << n.get_cdata_content() << "]]>";
      return 0;
    }
    DEFAULT_END_VISIT (CDataSection)

    void* begin_visit(const CastExpr& n)
    {
      n.get_unary_expr()->accept(*this);
      if(n.get_singletype())
      {
        os << " cast as ";
      }
      n.get_singletype()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (CastExpr)

    void* begin_visit(const CastableExpr& n)
    {
      n.cast_expr()->accept(*this);
      if(n.singletype())
      {
        os << " castable as ";
        n.singletype()->accept(*this);
      }
      return 0;
    }
    DEFAULT_END_VISIT (CastableExpr)

    void* begin_visit(const CommonContent& n)
    {
      switch(n.get_type())
      {
        case ParseConstants::cont_escape_lbrace:
          os << "{{";
          break;
        case ParseConstants::cont_escape_rbrace:
          os << "}}";
          break;
        case ParseConstants::cont_charref:
          os << n.get_ref();
          break;
        default:
          n.get_expr()->accept(*this);
      }
      return 0;
    }
    DEFAULT_END_VISIT (CommonContent)

    DEFAULT_VISIT (ComparisonExpr)

    void* begin_visit(const CompAttrConstructor& n)
    {
      os << "attribute" ;
      if(dynamic_cast<QName*>(n.get_qname_expr().getp()) != 0)
      {
        n.get_qname_expr()->accept(*this);
        os << '{';
        if(n.get_val_expr())
        {
          n.get_val_expr()->accept(*this);
        }
        os << '}';
      } else {
        os << '{';
        n.get_qname_expr()->accept(*this);
        os << '}';
        os << '{';
        if(n.get_val_expr())
        {
          n.get_val_expr()->accept(*this);
        }
        os << '}';
      }
      return 0;
    }
    DEFAULT_END_VISIT (CompAttrConstructor)

    void* begin_visit(const CompCommentConstructor& n)
    {
      os << "comment {";
      n.get_comment_expr()->accept(*this);
      os << '}';
      return 0;
    }
    DEFAULT_END_VISIT (CompCommentConstructor)

    void* begin_visit(const CompDocConstructor& n)
    {
      os << "document{ ";
      n.get_expr()->accept(*this);
      os << '}';
      return 0;
    }
    DEFAULT_END_VISIT (CompDocConstructor)

    void* begin_visit(const CompElemConstructor& n)
    {
      os << "element";
      if(dynamic_cast<QName*>(n.get_qname_expr().getp()) != 0)
      {
        n.get_qname_expr()->accept(*this);
        os << '{';
        if(n.get_content_expr())
        {
          n.get_content_expr()->accept(*this);
        }
        os << '}';
      } else {
        os << '{';
        n.get_qname_expr()->accept(*this);
        os << "}{";
        if(n.get_content_expr())
        {
          n.get_content_expr()->accept(*this);
        }
        os << '}';
      }
      return 0;
    }
    DEFAULT_END_VISIT (CompElemConstructor)

    void* begin_visit(const CompPIConstructor& n)
    {
      os << "processing-instruction";
      if(!n.get_target().empty())
      {
        os << n.get_target();
      } else {
        os << '{';
        n.get_target_expr()->accept(*this);
        os << '}';
      }
      os << '{';
      if(n.get_content_expr())
      {
        n.get_content_expr()->accept(*this);
      }
      os << '}';
      return 0;
    }
    DEFAULT_END_VISIT (CompPIConstructor)


    void* begin_visit(const CompNamespaceConstructor& n)
    {
      os << "namespace";

      if (!n.get_prefix().empty())
      {
        os << n.get_prefix();
      }
      else
      {
        os << '{';
        n.get_prefix_expr()->accept(*this);
        os << '}';
      }

      os << '{';
      n.get_uri_expr()->accept(*this);
      os << '}';
      return 0;
    }
    DEFAULT_END_VISIT(CompNamespaceConstructor)


    void* begin_visit(const CompTextConstructor& n)
    {
      os << "text {";
      n.get_text_expr()->accept(*this);
      os << '}';
      return 0;
    }
    DEFAULT_END_VISIT (CompTextConstructor)

    void* begin_visit(const ContextItemExpr& n)
    {
      os << '.';
      return 0;
    }
    DEFAULT_END_VISIT (ContextItemExpr)

    void* begin_visit(const DirCommentConstructor& n)
    {
      os << "<!-- " << n.get_comment() << " -->";
      return 0;
    }
    DEFAULT_END_VISIT (DirCommentConstructor);

    void* begin_visit(const DirElemConstructor& n)
    {
      os << '<';
      n.get_elem_name()->accept(*this);
      if(n.get_attr_list() != 0)
      {
        n.get_attr_list()->accept(*this);
      }
      if(n.get_dir_content_list() != 0)
      {
        os << '>';
        n.get_dir_content_list()->accept(*this);
        os << "</";
        n.get_end_name()->accept(*this);
        os << '>';
      } else {
        os << "/>";
      }
      return 0;
    }
    DEFAULT_END_VISIT (DirElemConstructor)

    DEFAULT_VISIT (DirElemContent)

    void* begin_visit(const DirPIConstructor& n)
    {
      os << "<? " << n.get_pi_target() << " " << n.get_pi_content() << " ?>";
      return 0;
    }
    DEFAULT_END_VISIT (DirPIConstructor)

    void* begin_visit(const EnclosedExpr& n)
    {
      os << '{';
      n.get_expr()->accept(*this);
      os << '}';
      return 0;
    }
    DEFAULT_END_VISIT (EnclosedExpr);

    DEFAULT_VISIT (BlockBody)
    DEFAULT_VISIT (ApplyExpr)
    DEFAULT_VISIT (Expr)

    void* begin_visit(const ExtensionExpr& n)
    {
      n.get_pragma_list()->accept(*this);
      os << "{ ";
      n.get_expr()->accept(*this);
      os << " }";
      return 0;
    }
    DEFAULT_END_VISIT (ExtensionExpr)

    void* begin_visit(const FLWORExpr& n)
    {
      n.get_clause_list()->accept(*this);
      os << "return ";
      n.get_return_val()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (FLWORExpr)


    DEFAULT_VISIT (WindowClause)
    DEFAULT_VISIT (WindowVarDecl)
    DEFAULT_VISIT (FLWORWinCond)
    DEFAULT_VISIT (WindowVars)
    DEFAULT_VISIT (FilterExpr) //@checked

    void* begin_visit(const FunctionCall& n)
    {
      n.get_fname()->accept(*this);
      os << '(';
      if(n.get_arg_list())
      {
        n.get_arg_list()->accept(*this);
      }
      os << ')';
      return 0;
    }
    DEFAULT_END_VISIT (FunctionCall)

    void* begin_visit(const IfExpr& n)
    {
      os << "if(";
      n.get_cond_expr()->accept(*this);
      os << ") then ";
      n.get_then_expr()->accept(*this);
      os << " else ";
      n.get_else_expr()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (IfExpr)

    void* begin_visit(const InstanceofExpr& n)
    {
      n.get_treat_expr()->accept(*this);
      if(n.get_seqtype())
      {
        os << " instanceof ";
        n.get_seqtype()->accept(*this);
      }
      return 0;
    }
    DEFAULT_END_VISIT (InstanceofExpr)

    DEFAULT_VISIT (IntersectExceptExpr)

    void* begin_visit(const MultiplicativeExpr& n)
    {
      n.get_mult_expr()->accept(*this);
      switch(n.get_mult_op())
      {
        case ParseConstants::op_mul:
          os << '*';
          break;
        case ParseConstants::op_div:
          os << " div ";
          break;
        case ParseConstants::op_idiv:
          os << " idiv ";
          break;
        case ParseConstants::op_mod:
          os << " mod ";
          break;
      }
      n.get_union_expr()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (MultiplicativeExpr)

    void* begin_visit(const NumericLiteral& n)
    {
      os << n.toString();
      return 0;
    }
    DEFAULT_END_VISIT (NumericLiteral)

    void* begin_visit(const OrExpr& n)
    {
      n.get_or_expr()->accept(*this);
      os << " or ";
      n.get_and_expr()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (OrExpr)

    void* begin_visit(const OrderedExpr& n)
    {
      os << "ordered { ";
      n.get_expr()->accept(*this);
      os << " } ";
      return 0;
    }
    DEFAULT_END_VISIT (OrderedExpr);

    void* begin_visit(const ParenthesizedExpr& n)
    {
      os << ')';
      return no_state;
    }

    void end_visit(const ParenthesizedExpr& n, void*)
    {
      os << ')';
    }

    void* begin_visit(const PathExpr& n)
    {
      switch(n.get_type())
      {
        case ParseConstants::path_leading_lone_slash:
          os << '/';
          break;
        case ParseConstants::path_leading_slash:
          os << '/';
          break;
        case ParseConstants::path_leading_slashslash:
          os << "//";
          break;
        case ParseConstants::path_relative:
          break;
      }
      return no_state;
    }
    DEFAULT_END_VISIT (PathExpr)

    void* begin_visit(const QuantifiedExpr& n)
    {
      switch(n.get_qmode())
      {
        case ParseConstants::quant_some:
          os << " some $";
          break;
        case ParseConstants::quant_every:
          os << " every $";
      }
      n.get_decl_list()->accept(*this);
      os << " in ";
      n.get_expr()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (QuantifiedExpr)

    DEFAULT_VISIT (QueryBody) //@checked

    void* begin_visit(const RangeExpr& n)
    {
      n.get_from_expr()->accept(*this);
      if(n.get_to_expr())
      {
        os << " to ";
        n.get_to_expr()->accept(*this);
      }
      return 0;
    }
    DEFAULT_END_VISIT (RangeExpr)

    void* begin_visit(const RelativePathExpr& n)
    {
      n.get_step_expr()->accept(*this);
      switch(n.get_step_type())
      {
        case ParseConstants::st_step:
          return 0;
        case ParseConstants::st_slash:
          os << '/';
          break;
        case ParseConstants::st_slashslash:
          os << "//";
          break;
      }
      n.get_relpath_expr()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (RelativePathExpr)

    void* begin_visit(const SimpleMapExpr& n)
    {
      n.get_left_expr()->accept(*this);
      os << "!";
      n.get_right_expr()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (SimpleMapExpr)


    void* begin_visit(const StringLiteral& n)
    {
      os << "\"" << n.get_strval() << '"';
      return 0;
    }
    DEFAULT_END_VISIT (StringLiteral);


    void* begin_visit(const BooleanLiteral& n)
    {
      os << "\"" << n.get_boolval() << '"';
      return 0;
    }
    DEFAULT_END_VISIT (BooleanLiteral);


    void* begin_visit(const NullLiteral& n)
    {
      os << "\"null\"";
      return 0;
    }
    DEFAULT_END_VISIT (NullLiteral);


    void* begin_visit(const StringConcatExpr& n)
    {
      n.get_left_expr()->accept(*this);
      os << " || ";
      n.get_right_expr()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT(StringConcatExpr);

    void* begin_visit(const TreatExpr& n)
    {
      n.get_castable_expr()->accept(*this);
      if(n.get_seqtype())
      {
        os << " treat as";
        n.get_seqtype()->accept(*this);
      }
      return 0;
    }
    DEFAULT_END_VISIT (TreatExpr)

    void* begin_visit(const SwitchExpr& n)
    {
      os << "switch(";
      n.get_switch_expr()->accept(*this);
      os << ')';
      n.get_clause_list()->accept(*this);
      os << " default return";
      n.get_default_expr()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (SwitchExpr)

    void* begin_visit(const SwitchCaseClause& n)
    {
      n.get_operand_list()->accept(*this);
      os << " return";
      n.get_return_expr()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (SwitchCaseClause)

    DEFAULT_VISIT (SwitchCaseClauseList)

    DEFAULT_VISIT (SwitchCaseOperandList)


    void* begin_visit(const TypeswitchExpr& n)
    {
      os << "typeswitch(";
      n.get_switch_expr()->accept(*this);
      os << ')';
      n.get_clause_list()->accept(*this);
      os << " default";
      if(n.get_default_varname())
      {
        os << " $" << n.get_default_varname()->get_qname();
      }
      os << " return";
      n.get_default_clause()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (TypeswitchExpr)

    DEFAULT_VISIT (UnaryExpr) //@checked

    void* begin_visit(const UnionExpr& n)
    {
      if(n.union_expr())
      {
        n.union_expr()->accept(*this);
        os << " union";
      }
      n.intex_expr()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (UnionExpr)

    void* begin_visit(const UnorderedExpr& n)
    {
      os << " unodered{ ";
      n.get_expr()->accept(*this);
      os << " }";
      return 0;
    }
    DEFAULT_END_VISIT (UnorderedExpr)

    void* begin_visit(const ValidateExpr& n)
    {
      os << " validate";
      switch(n.get_valmode())
      {
        case ParseConstants::val_strict:
          os << " strict";
          break;
        case ParseConstants::val_lax:
          os << " lax";
          break;
        default: break;
      }
      os << " {";
      n.get_expr()->accept(*this);
      os << " }";
      return 0;
    }
    DEFAULT_END_VISIT (ValidateExpr)

    void* begin_visit(const VarRef& n)
    {
      os << '$';
      os << n.get_name()->get_qname();
      return 0;
    }
    DEFAULT_END_VISIT (VarRef)

    /* update-related */
    void* begin_visit(const DeleteExpr& n)
    {
      os << "delete node ";
      n.getTargetExpr()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (DeleteExpr);

    void* begin_visit(const InsertExpr& n)
    {
      os << "insert nodes ";
      n.getSourceExpr()->accept(*this);
      switch(n.getType())
      {
        case store::UpdateConsts::INTO:
          os << "into ";
          break;
        case store::UpdateConsts::AS_FIRST_INTO:
          os << "as first into ";
          break;
        case store::UpdateConsts::AS_LAST_INTO:
          os << "as last into ";
          break;
        case store::UpdateConsts::AFTER:
          os << "after ";
          break;
        case store::UpdateConsts::BEFORE:
          os << "before ";
          break;
      }
      return 0;
    }
    DEFAULT_END_VISIT (InsertExpr)

    void* begin_visit(const RenameExpr& n)
    {
      os << "insert nodes ";
      n.getTargetExpr()->accept(*this);
      os << "as ";
      n.getNameExpr()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (RenameExpr)

    void* begin_visit(const ReplaceExpr& n)
    {
      os << "replace ";
      switch(n.getType())
      {
        case store::UpdateConsts::VALUE_OF_NODE:
          os << "value of node ";
          break;
        case store::UpdateConsts::NODE:
          os << "node ";
          break;
      }
      n.getTargetExpr()->accept(*this);
      os << "with ";
      n.getReplaceExpr()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (ReplaceExpr)

    void* begin_visit(const RevalidationDecl& n)
    {
      os << "declare revalidation ";
      switch(n.get_mode())
      {
        case StaticContextConsts::strict_validation:
          os << "strict ";
          break;
        case StaticContextConsts::lax_validation:
          os << "lax ";
          break;
        case StaticContextConsts::skip_validation:
          os << "skip ";
          break;
      default:
        ZORBA_ASSERT(false);
      }
      return 0;
    }
    DEFAULT_END_VISIT (RevalidationDecl)

    void* begin_visit(const TransformExpr& n)
    {
      os << "copy $";
      n.get_var_list()->accept(*this);
      os << "modify ";
      n.get_modify_expr()->accept(*this);
      os << "return ";
      n.get_return_expr()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (TransformExpr)

    DEFAULT_VISIT (CopyVarList) //@checked

    void* begin_visit(const VarBinding& n)
    {
      os << "$" << n.get_varname();
      os << " := ";
      n.get_expr()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (VarBinding)

    /* try-catch-related */
    void* begin_visit(const TryExpr& n)
    {
      os << "try {";
      n.getExprSingle()->accept(*this);
      os << "}";
      n.getCatchListExpr()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (TryExpr);

    DEFAULT_VISIT (CatchListExpr); //@checked

    void* begin_visit(const CatchExpr& n)
    {
      os << "catch ";
      for(CatchExpr::NameTestList::const_iterator i = n.getNameTests().begin();
          i != n.getNameTests().end(); ++i)
      {
        (*i)->accept(*this);
      }

      os << "{";
      n.getExprSingle()->accept(*this);
      os << "}";
      return 0;
    }
    DEFAULT_END_VISIT (CatchExpr);

    void* begin_visit(const AnyFunctionTest& n)
    {
      os << "function (*)";
      return 0;
    }
    DEFAULT_END_VISIT (AnyFunctionTest);

    void* begin_visit(const TypedFunctionTest& n)
    {
      os << "function (";
      n.getArgumentTypes()->accept(*this);
      os << ") as ";
      n.getReturnType()->accept(*this);
      return 0;
    }
    DEFAULT_END_VISIT (TypedFunctionTest);

    void* begin_visit(const TypeList& n)
    {
      for (size_t i = 0; i < n.size(); ++i)
      {
        if (i > 0)
        {
          os << ", ";
        }
        const SequenceTypeAST* e_p = n[i];
        e_p->accept(*this);
      }
      return 0;
    }
    DEFAULT_END_VISIT (TypeList);

  /* full-text-related */
  DEFAULT_VISIT (FTAnd);
  DEFAULT_VISIT (FTAnyallOption);
  DEFAULT_VISIT (FTBigUnit);
  DEFAULT_VISIT (FTCaseOption);
  DEFAULT_VISIT (FTContainsExpr);
  DEFAULT_VISIT (FTContent);
  DEFAULT_VISIT (FTDiacriticsOption);
  DEFAULT_VISIT (FTDistance);
  DEFAULT_VISIT (FTExtensionOption);
  DEFAULT_VISIT (FTExtensionSelection);
  DEFAULT_VISIT (FTIgnoreOption);
  DEFAULT_VISIT (FTLanguageOption);
  DEFAULT_VISIT (FTMatchOptions);
  DEFAULT_VISIT (FTMildNot);
  DEFAULT_VISIT (FTOptionDecl);
  DEFAULT_VISIT (FTOr);
  DEFAULT_VISIT (FTOrder);
  DEFAULT_VISIT (FTPrimaryWithOptions);
  DEFAULT_VISIT (FTRange);
  DEFAULT_VISIT (FTScope);
  DEFAULT_VISIT (FTScoreVar);
  DEFAULT_VISIT (FTSelection);
  DEFAULT_VISIT (FTStemOption);
  DEFAULT_VISIT (FTStopWordOption);
  DEFAULT_VISIT (FTStopWords);
  DEFAULT_VISIT (FTStopWordsInclExcl);
  DEFAULT_VISIT (FTThesaurusID);
  DEFAULT_VISIT (FTThesaurusOption);
  DEFAULT_VISIT (FTTimes);
  DEFAULT_VISIT (FTUnaryNot);
  DEFAULT_VISIT (FTUnit);
  DEFAULT_VISIT (FTWeight);
  DEFAULT_VISIT (FTWildCardOption);
  DEFAULT_VISIT (FTWindow);
  DEFAULT_VISIT (FTWords);
  DEFAULT_VISIT (FTWordsTimes);
  DEFAULT_VISIT (FTWordsValue);

  /* JSON-related */
  DEFAULT_VISIT (JSONObjectLookup);

  DEFAULT_VISIT (JSONArrayUnboxing);

  DEFAULT_VISIT (JSONArrayConstructor);

  DEFAULT_VISIT (JSONObjectConstructor);

  DEFAULT_VISIT (JSONDirectObjectConstructor);

  DEFAULT_VISIT (JSONPairList);

  DEFAULT_VISIT (JSONPairConstructor);

  DEFAULT_VISIT (JSONObjectInsertExpr);

  DEFAULT_VISIT (JSONArrayInsertExpr);

  DEFAULT_VISIT (JSONArrayAppendExpr);

  DEFAULT_VISIT (JSONDeleteExpr);

  DEFAULT_VISIT (JSONReplaceExpr);

  DEFAULT_VISIT (JSONRenameExpr);

  void* begin_visit(const JSON_Test& n)
  {
    os << n.get_kind() << "()";
    return no_state;
  }
  DEFAULT_END_VISIT (JSON_Test);

  DEFAULT_VISIT (AssignExpr);
  DEFAULT_VISIT (ExitExpr);
  DEFAULT_VISIT (WhileExpr);
  DEFAULT_VISIT (FlowCtlStatement);

  DEFAULT_VISIT (LiteralFunctionItem);
  DEFAULT_VISIT (InlineFunction);
  DEFAULT_VISIT (DynamicFunctionInvocation);

  DEFAULT_VISIT (ParseErrorNode);
};

FunctionIndex print_parsetree_xquery(ostream& os, const parsenode* p)
{
  ParseNodePrintXQueryVisitor v(os);
  return v.print(p)->getFunctionIndex();
}
}//end of namespace
/* vim:set et sw=2 ts=2: */

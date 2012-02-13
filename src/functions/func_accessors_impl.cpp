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

#include <vector>

#include "runtime/accessors/accessors.h"

#include "compiler/expression/expr_base.h"
#include "compiler/expression/fo_expr.h"

#include "functions/func_accessors_impl.h"
#include "functions/func_accessors.h"
#include "functions/function_impl.h"

#include "types/typeops.h"

#include "system/globalenv.h"
#include "zorbamisc/ns_consts.h"


namespace zorba
{

/*******************************************************************************

********************************************************************************/
PlanIter_t fn_string::codegen(
      CompilerCB* /*cb*/,
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& argv,
      AnnotationHolder& ann) const
{
  return new FnStringIterator(sctx, loc, argv, true);
}


/*******************************************************************************
  
********************************************************************************/
BoolAnnotationValue fn_data::ignoresSortedNodes(expr* fo, csize input) const
{
  return fo->getIgnoresSortedNodes();
}


BoolAnnotationValue fn_data::ignoresDuplicateNodes(expr* fo, csize input) const
{
  return fo->getIgnoresDuplicateNodes();
}


bool fn_data::mustCopyInputNodes(expr* fo, csize input) const
{
  static_context* sctx = fo->get_sctx();

  return (sctx->construction_mode() != StaticContextConsts::cons_preserve);
}


xqtref_t fn_data::getReturnType(const fo_expr* caller) const
{
  const QueryLoc& loc = caller->get_loc();

  TypeManager* tm = caller->get_type_manager();
  RootTypeManager& RTM = GENV_TYPESYSTEM;

  xqtref_t argType = caller->get_arg(0)->get_return_type();

  if (TypeOps::is_subtype(tm, *argType, *RTM.ANY_ATOMIC_TYPE_STAR, loc))
    return argType; // includes () case

  TypeConstants::quantifier_t q = TypeOps::quantifier(*argType);

  if (argType->type_kind() == XQType::NODE_TYPE_KIND)
  {
    const NodeXQType& nType = static_cast<const NodeXQType&>(*argType);

    store::StoreConsts::NodeKind nodeKind = nType.get_node_kind();

    if (nodeKind == store::StoreConsts::piNode ||
        nodeKind == store::StoreConsts::commentNode)
    {
      return tm->create_builtin_atomic_type(store::XS_STRING, q);
    }

    if (nodeKind == store::StoreConsts::documentNode ||
        nodeKind == store::StoreConsts::textNode)
    {
      return tm->create_builtin_atomic_type(store::XS_UNTYPED_ATOMIC, q);
    }

    xqtref_t cType = nType.get_content_type();
    if (cType != NULL)
    {
      if (cType->isList())
      {
        const XQType* itemType = static_cast<const UserDefinedXQType*>(cType.getp())->
                                 getListItemType();
        return tm->create_type(*itemType, TypeConstants::QUANT_STAR);
      }
      else if (TypeOps::is_equal(tm, *cType, *RTM.UNTYPED_TYPE))
      {
        return tm->create_builtin_atomic_type(store::XS_UNTYPED_ATOMIC, q);
      }
      else if (TypeOps::is_subtype(tm, *cType, *RTM.ANY_ATOMIC_TYPE_STAR, loc))
      {
        return tm->create_type(*cType, q);
      }
    }
  }

  return RTM.ANY_ATOMIC_TYPE_STAR;
}


/*******************************************************************************
  fn_data_3_0 is converted to fn_data during translation
********************************************************************************/
class fn_data_3_0 : public function
{
public:
  fn_data_3_0(const signature& sig, FunctionConsts::FunctionKind kind)
    :
    function(sig, kind) 
  {
    theXQueryVersion = StaticContextConsts::xquery_version_3_0;
  }

  CODEGEN_DECL();
};


PlanIter_t fn_data_3_0::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  ZORBA_ASSERT(false);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t fn_name_func::codegen(
    CompilerCB* /*cb*/,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    AnnotationHolder& ann) const
{
  PlanIter_t nnIter = new NodeNameIterator(sctx, loc, argv);
  std::vector<PlanIter_t> lVec;
  lVec.push_back(nnIter);
  return new FnStringIterator(sctx, loc, lVec, true);
}


/*******************************************************************************

********************************************************************************/
void populate_context_accessors_impl(static_context* sctx)
{
  DECL(sctx, fn_name_func,
       (createQName(static_context::W3C_FN_NS, "", "name"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE));

  DECL(sctx, fn_name_func,
       (createQName(static_context::W3C_FN_NS, "", "name"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
        GENV_TYPESYSTEM.STRING_TYPE_ONE));

  DECL_WITH_KIND(sctx, fn_data_3_0,
                 (createQName("http://www.w3.org/2005/xpath-functions","","data"), 
                  GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR),
                  FunctionConsts::FN_DATA_0);
}



} /* namespace zorba */
/* vim:set et sw=2 ts=2: */

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
 
#include <typeinfo>
 
#include "functions/func_nodes.h"
 
#include "system/globalenv.h"
 
#include "compiler/expression/expr.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/expression/path_expr.h"
 
#include "types/typeops.h"
 
namespace zorba
{
 
 
/*******************************************************************************
 
********************************************************************************/
xqtref_t fn_zorba_node_copy::getReturnType(const fo_expr* caller) const
{
  return caller->get_arg(0)->get_return_type();
}
 
 
/*******************************************************************************
 
********************************************************************************/
bool fn_zorba_node_copy::mustCopyInputNodes(expr* fo, csize input) const
{
  static_context* lSctx = fo->get_sctx();
  return
    lSctx->preserve_mode() == StaticContextConsts::no_preserve_ns ||
    lSctx->construction_mode() == StaticContextConsts::cons_strip;
}
 
} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
 

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

#include "functions/func_schema.h"

#include "compiler/expression/expr_base.h"

#include "context/static_context.h"

namespace zorba
{


/*******************************************************************************

********************************************************************************/
bool fn_zorba_schema_schema_type::mustCopyInputNodes(expr* fo, csize producer) const 
{
  return (fo->get_sctx()->construction_mode() == StaticContextConsts::cons_strip);
}


/*******************************************************************************

********************************************************************************/
bool fn_zorba_schema_is_validated::mustCopyInputNodes(expr* fo, csize producer) const 
{
  return (fo->get_sctx()->construction_mode() == StaticContextConsts::cons_strip);
}


}

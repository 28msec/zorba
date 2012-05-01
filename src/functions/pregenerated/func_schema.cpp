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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************


#include "stdafx.h"
#include "runtime/schema/schema.h"
#include "functions/func_schema.h"


namespace zorba{



PlanIter_t fn_zorba_schema_validate_in_place::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new ZorbaValidateInPlaceIterator(sctx, loc, argv[0]);
}

PlanIter_t fn_zorba_util_schema_type::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new ZorbaSchemaTypeIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_schema_schema_type::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new ZorbaSchemaTypeIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_schema_is_validated::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new ZorbaIsValidatedIterator(sctx, loc, argv);
}

void populate_context_schema(static_context* sctx)
{
  {
    

    DECL_WITH_KIND(sctx, fn_zorba_schema_validate_in_place,
        (createQName("http://www.zorba-xquery.com/modules/schema","","validate-in-place"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::FN_ZORBA_SCHEMA_VALIDATE_IN_PLACE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_util_schema_type,
        (createQName("http://www.zorba-xquery.com/zorba/util-functions","","schema-type"), 
        GENV_TYPESYSTEM.ITEM_TYPE_ONE, 
        GENV_TYPESYSTEM.QNAME_TYPE_QUESTION),
        FunctionConsts::FN_ZORBA_UTIL_SCHEMA_TYPE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_schema_schema_type,
        (createQName("http://www.zorba-xquery.com/modules/schema","","schema-type"), 
        GENV_TYPESYSTEM.ITEM_TYPE_ONE, 
        GENV_TYPESYSTEM.QNAME_TYPE_QUESTION),
        FunctionConsts::FN_ZORBA_SCHEMA_SCHEMA_TYPE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_schema_is_validated,
        (createQName("http://www.zorba-xquery.com/modules/schema","","is-validated"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_SCHEMA_IS_VALIDATED_1);

  }

}


}




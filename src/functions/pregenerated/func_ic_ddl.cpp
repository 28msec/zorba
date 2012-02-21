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
#include "runtime/indexing/ic_ddl.h"
#include "functions/func_ic_ddl.h"


namespace zorba{



PlanIter_t zorba_store_integrity_constraints_static_ddl_activate::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new ActivateICIterator(sctx, loc, argv[0]);
}

PlanIter_t zorba_store_integrity_constraints_static_ddl_deactivate::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new DeactivateICIterator(sctx, loc, argv[0]);
}

PlanIter_t zorba_store_integrity_constraints_static_dml_check_integrity_constraint::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new CheckICIterator(sctx, loc, argv[0]);
}

void populate_context_ic_ddl(static_context* sctx)
{
  {
    

    DECL_WITH_KIND(sctx, zorba_store_integrity_constraints_static_ddl_activate,
        (createQName("http://www.zorba-xquery.com/modules/store/static/integrity_constraints/ddl","","activate"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_INTEGRITY_CONSTRAINTS_STATIC_DDL_ACTIVATE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_integrity_constraints_static_ddl_deactivate,
        (createQName("http://www.zorba-xquery.com/modules/store/static/integrity_constraints/ddl","","deactivate"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_INTEGRITY_CONSTRAINTS_STATIC_DDL_DEACTIVATE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_integrity_constraints_static_dml_check_integrity_constraint,
        (createQName("http://www.zorba-xquery.com/modules/store/static/integrity_constraints/dml","","check-integrity-constraint"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::ZORBA_STORE_INTEGRITY_CONSTRAINTS_STATIC_DML_CHECK_INTEGRITY_CONSTRAINT_1);

  }

}


}




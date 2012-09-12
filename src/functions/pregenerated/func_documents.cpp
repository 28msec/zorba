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
#include "runtime/store/documents.h"
#include "functions/func_documents.h"


namespace zorba{



PlanIter_t zorba_store_documents_put::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new PutDocumentIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_documents_remove::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new RemoveDocumentIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_documents_document::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new RetrieveDocumentIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_documents_available_documents::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new AvailableDocumentsIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_documents_is_available_document::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new IsAvailableDocumentIterator(sctx, loc, argv);
}

void populate_context_documents(static_context* sctx)
{


      {
    DECL_WITH_KIND(sctx, zorba_store_documents_put,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/documents","","put"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.DOCUMENT_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_DOCUMENTS_PUT_2);

  }




      {
    DECL_WITH_KIND(sctx, zorba_store_documents_remove,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/documents","","remove"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::ZORBA_STORE_DOCUMENTS_REMOVE_1);

  }




      {
    DECL_WITH_KIND(sctx, zorba_store_documents_document,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/documents","","document"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.DOCUMENT_TYPE_ONE),
        FunctionConsts::ZORBA_STORE_DOCUMENTS_DOCUMENT_1);

  }




      {
    DECL_WITH_KIND(sctx, zorba_store_documents_available_documents,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/documents","","available-documents"), 
        GENV_TYPESYSTEM.STRING_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_DOCUMENTS_AVAILABLE_DOCUMENTS_0);

  }




      {
    DECL_WITH_KIND(sctx, zorba_store_documents_is_available_document,
        (createQName("http://www.zorba-xquery.com/modules/store/dynamic/documents","","is-available-document"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::ZORBA_STORE_DOCUMENTS_IS_AVAILABLE_DOCUMENT_1);

  }

}


}




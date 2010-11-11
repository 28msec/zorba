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
#include <vector>

#include "functions/function_impl.h"
#include "functions/Alexis.h"

#include "runtime/util/UtilImpl.h"

using namespace std;

namespace zorba 
{

#ifdef ZORBA_WITH_TIDY
/*******************************************************************************
  zorba:tidy
********************************************************************************/
typedef function_impl<ZorbaTidyIterator> zorba_tidy;


/*******************************************************************************
  zorba:tdoc
********************************************************************************/
class zorba_tdoc : public function 
{
public:
  zorba_tdoc(const signature& sig) : function(sig) {}

  bool isSource() const { return true; }

  bool accessesDynCtx() const { return true; }

  DEFAULT_NARY_CODEGEN(ZorbaTDocIterator);
};

#endif/* ZORBA_WITH_TIDY */


void populateContext_Alexis(static_context* sctx)
{
  const char* util_ns = static_context::ZORBA_UTIL_FN_NS.c_str();
  const char* tidy_ns = static_context::ZORBA_TIDY_FN_NS.c_str();

#ifdef ZORBA_WITH_TIDY
  DECL(sctx, zorba_tidy,
       (createQName(util_ns, "", "tidy"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.ITEM_TYPE_ONE));

  DECL(sctx, zorba_tidy,
       (createQName(util_ns, "", "tidy"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
        GENV_TYPESYSTEM.ITEM_TYPE_ONE));

  DECL(sctx, zorba_tdoc,
       (createQName(util_ns, "", "tdoc"),
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
        GENV_TYPESYSTEM.DOCUMENT_TYPE_QUESTION));

  DECL(sctx, zorba_tdoc,
       (createQName(util_ns, "", "tdoc"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
        GENV_TYPESYSTEM.DOCUMENT_TYPE_QUESTION));

  DECL(sctx, zorba_tidy,
       (createQName(tidy_ns, "", "tidy"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.DOCUMENT_TYPE_ONE));

  DECL(sctx, zorba_tidy,
       (createQName(tidy_ns, "", "tidy"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
        GENV_TYPESYSTEM.DOCUMENT_TYPE_ONE));
#endif

}


}
/* vim:set ts=2 sw=2: */

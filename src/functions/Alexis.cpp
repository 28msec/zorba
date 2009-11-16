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

  bool requires_dyn_ctx() const { return true; }

  ZORBA_NOT_PROPAGATES_I2O;

  DEFAULT_NARY_CODEGEN(ZorbaTDocIterator);
};

#endif/* ZORBA_WITH_TIDY */


class zorba_timestamp : public function
{
public:
  zorba_timestamp(const signature& sig) : function(sig) {}

  bool requires_dyn_ctx() const { return true; }

  DEFAULT_NARY_CODEGEN(ZorbaTimestampIterator);
};


void populateContext_Alexis(static_context* sctx)
{
#ifdef ZORBA_WITH_TIDY
  DECL(sctx, zorba_tidy,
       (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "tidy"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.ITEM_TYPE_ONE));

  DECL(sctx, zorba_tidy,
       (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "tidy"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
        GENV_TYPESYSTEM.ITEM_TYPE_ONE));

  DECL(sctx, zorba_tdoc,
       (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "tdoc"),
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
        GENV_TYPESYSTEM.DOCUMENT_TYPE_QUESTION));

  DECL(sctx, zorba_tdoc,
       (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "tdoc"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
        GENV_TYPESYSTEM.DOCUMENT_TYPE_QUESTION));
#endif

  DECL(sctx, zorba_timestamp,
       (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "timestamp"),
        GENV_TYPESYSTEM.LONG_TYPE_ONE));
}


}
/* vim:set ts=2 sw=2: */

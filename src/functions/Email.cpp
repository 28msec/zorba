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
#include "functions/Email.h"
#include "functions/function_impl.h"

#include "runtime/email/EmailImpl.h"


namespace zorba 
{

class zorba_mail : public function
{
public:
  zorba_mail(const signature& sig): function(sig){}

  DEFAULT_NARY_CODEGEN(ZorbaMailIterator);
};


void populateContext_Email(static_context* sctx)
{
#ifdef ZORBA_WITH_EMAIL
  DECL(sctx, zorba_mail,
       (createQName(ZORBA_EMAIL_FN_NS, "fn-zorba-email", "mail"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.NONE_TYPE));

  DECL(sctx, zorba_mail,
       (createQName(ZORBA_EMAIL_FN_NS, "fn-zorba-email", "mail"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
        GENV_TYPESYSTEM.NONE_TYPE));
#endif
}

}
/* vim:set ts=2 sw=2: */

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

#include "functions/XQDocFunctions.h"
#include "functions/function_impl.h"

#include "runtime/util/UtilImpl.h"

namespace zorba 
{

class XQDocFunction: public function
{
public:
  XQDocFunction(const signature& sig): function(sig){}

  DEFAULT_NARY_CODEGEN(XQDocIterator);
};


void populateContext_XQDOC(static_context* sctx)
{
  DECL(sctx, XQDocFunction,
       (createQName(ZORBA_XQDOC_FN_NS, "xqdoc", "xqdoc"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE, GENV_TYPESYSTEM.ITEM_TYPE_STAR));
}


}

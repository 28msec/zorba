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
#include "functions/tuple_functions.h"
#include "functions/function_impl.h"

#include "runtime/core/tuple_iterators.h"

namespace zorba 
{

class zop_createtuple : public function 
{
public:
  zop_createtuple(const signature& sig) : function(sig) { }

  DEFAULT_NARY_CODEGEN(CreateTupleIterator);
};


class zop_gettuplefield : public function 
{
public:
  zop_gettuplefield(const signature& sig) : function(sig) { }

  DEFAULT_NARY_CODEGEN(GetTupleFieldIterator);
};


void populateContext_Tuples(static_context* sctx)
{
  DECL(sctx, zop_createtuple,
       (createQName(ZORBA_OPEXTENSIONS_NS,"op-extensions", "create-tuple"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        true,
        GENV_TYPESYSTEM.ITEM_TYPE_ONE));

  DECL(sctx, zop_gettuplefield,
       (createQName(ZORBA_OPEXTENSIONS_NS,"op-extensions", "get-tuple-field"),
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));
}

}
/* vim:set ts=2 sw=2: */

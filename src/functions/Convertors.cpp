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
#include "functions/Convertors.h"
#include "functions/function_impl.h"

#include "runtime/convertors/ConvertorsImpl.h"

namespace zorba 
{

//Json
class zorba_json_parse : public function
{
public:
  zorba_json_parse(const signature& sig): function(sig){}

  DEFAULT_NARY_CODEGEN(ZorbaJsonParseIterator);
};


class zorba_json_serialize : public function
{
public:
  zorba_json_serialize(const signature& sig): function(sig){}

  DEFAULT_NARY_CODEGEN(ZorbaJsonSerializeIterator);
};


//Json ML
class zorba_json_ml_parse : public function
{
public:
  zorba_json_ml_parse(const signature& sig): function(sig){}

  DEFAULT_NARY_CODEGEN(ZorbaJsonMLParseIterator);
};


class zorba_json_ml_serialize : public function
{
public:
  zorba_json_ml_serialize(const signature& sig): function(sig){}

  DEFAULT_NARY_CODEGEN(ZorbaJsonMLSerializeIterator);
};


void populateContext_JSON(static_context* sctx)
{
  DECL(sctx, zorba_json_parse,
       (createQName(ZORBA_JSON_FN_NS, "fn-zorba-json", "parse"),
        GENV_TYPESYSTEM.STRING_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(sctx, zorba_json_serialize,
       (createQName(ZORBA_JSON_FN_NS, "fn-zorba-json", "serialize"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
        GENV_TYPESYSTEM.STRING_TYPE_STAR));

  DECL(sctx, zorba_json_ml_parse,
       (createQName(ZORBA_JSON_ML_FN_NS, "fn-zorba-json-ml", "parse"),
        GENV_TYPESYSTEM.STRING_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(sctx, zorba_json_ml_serialize,
       (createQName(ZORBA_JSON_ML_FN_NS, "fn-zorba-json-ml", "serialize"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
        GENV_TYPESYSTEM.STRING_TYPE_STAR));
}


}
/* vim:set ts=2 sw=2: */

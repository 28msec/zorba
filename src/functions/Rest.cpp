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
#include "functions/Rest.h"
#include "functions/function_impl.h"

#include "system/globalenv.h"

#include "runtime/rest/rest.h"

namespace zorba {

class rest_get : public function
{
public:
  rest_get(const signature& sig) : function(sig) {}

  bool isPureFunction () const { return false; }

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const
  {
    return new ZorbaRestGetIterator(sctx, loc, argv, false);
  }
};


class rest_get_tidy : public function
{
public:
  rest_get_tidy(const signature& sig) : function(sig) {}

  bool isPureFunction () const { return false; }

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const
  {
    return new ZorbaRestGetIterator(sctx, loc, argv, true);
  }
};


class rest_post : public function
{
public:
  rest_post(const signature& sig) : function(sig) {}

  xqtref_t return_type(const std::vector<xqtref_t>& arg_types) const
  {
    return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
  }

  bool isPureFunction () const { return false; }

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const
  {
    return new ZorbaRestPostIterator(sctx, loc, argv, false);
  }
};


class rest_post_tidy : public function
{
public:
  rest_post_tidy(const signature& sig) : function(sig) {}

  xqtref_t return_type(const std::vector<xqtref_t>& arg_types) const
  {
    return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
  }

  bool isPureFunction () const { return false; }

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const
  {
    return new ZorbaRestPostIterator(sctx, loc, argv, true);
  }
};


class rest_put : public function
{
public:
  rest_put(const signature& sig) : function(sig) {}

  xqtref_t return_type (const std::vector<xqtref_t>& arg_types) const
  {
    return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
  }

  bool isPureFunction () const { return false; }

  DEFAULT_NARY_CODEGEN(ZorbaRestPutIterator);
};


class rest_delete : public function
{
public:
  rest_delete(const signature& sig) : function(sig) {}

  xqtref_t return_type(const std::vector<xqtref_t>& arg_types) const
  {
    return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
  }

  bool isPureFunction () const { return false; }

  DEFAULT_NARY_CODEGEN(ZorbaRestDeleteIterator);
};


class rest_head : public function
{
public:
  rest_head(const signature& sig) : function(sig) {}

  xqtref_t return_type(const std::vector<xqtref_t>& arg_types) const
  {
    return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
  }

  bool isPureFunction () const { return false; }

  DEFAULT_NARY_CODEGEN(ZorbaRestHeadIterator);
};



void populateContext_Rest(static_context* sctx)
{
// zorba-rest:get with an URI
DECL(sctx, rest_get,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "get"),
     GENV_TYPESYSTEM.STRING_TYPE_ONE,
     GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:get with an URI and a payload
DECL(sctx, rest_get,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "get"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:get with an URI, a payload and custom headers
DECL(sctx, rest_get,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "get"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

#ifdef ZORBA_WITH_TIDY
// zorba-rest:get with an URI
DECL(sctx, rest_get_tidy,
      (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "getTidy"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE, //$tidyOptions
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:get with an URI and a payload
DECL(sctx, rest_get_tidy,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "getTidy"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE, //$tidyOptions
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:get with an URI, a payload and custom headers
DECL(sctx, rest_get_tidy,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "getTidy"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE, //$tidyOptions
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));
#endif

// zorba-rest:post with an URI
DECL(sctx, rest_post,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "post"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:post with an URI and a payload
DECL(sctx, rest_post,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "post"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:post with an URI, a payload and custom headers
DECL(sctx, rest_post,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "post"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:postTidy with an URI, a payload, custom headers and tidy options
DECL(sctx, rest_post_tidy,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "postTidy"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE, //$tidyOptions
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:put with an URI
DECL(sctx, rest_put,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "put"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:put with an URI and a payload
DECL(sctx, rest_put,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "put"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:put with an URI, a payload and custom headers
DECL(sctx, rest_put,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "put"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));
      
      
// zorba-rest:delete with an URI
DECL(sctx, rest_delete,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "delete"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:delete with an URI and a payload
DECL(sctx, rest_delete,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "delete"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:delete with an URI, a payload and custom headers
DECL(sctx, rest_delete,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "delete"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));


// zorba-rest:head with an URI
DECL(sctx, rest_head,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "head"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:head with an URI and a payload
DECL(sctx, rest_head,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "head"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

// zorba-rest:head with an URI, a payload and custom headers
DECL(sctx, rest_head,
     (createQName(ZORBA_REST_FN_NS, "fn-zorba-rest", "head"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));
}


} /* namespace zorba */

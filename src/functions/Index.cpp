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
#include "functions/Index.h"
#include "functions/function_impl.h"

#include "runtime/indexing/value_index_builder.h"
#include "runtime/indexing/value_index_probe.h"


namespace zorba
{


/******************************************************************************
  create-index($indexUri as xs:uri) as ()

  Creates the index container in the store but does not populate it. Also creates
  in the dynamic context an entry that maps the index uri and an index object that
  is returned by the store to act as a handle to the index. The specification for
  the index to create is taken from the static context, which stores a mapping
  from the index uri to ValueIndex obj (defined in indexing/value_index.h).
********************************************************************************/
class zop_createindex : public function 
{
public:
  zop_createindex(const signature& sig) : function(sig) { }

  virtual bool requires_dyn_ctx () const { return true; }

  DEFAULT_UNARY_CODEGEN(CreateValueIndex);
};


/******************************************************************************
  drop-index($indexUri as xs:uri) as ()

  Destroys the index container in the store and removes the index entry from
  the dynamic context. 
********************************************************************************/
class zop_dropindex : public function 
{
public:
  zop_dropindex(const signature& sig) : function(sig) { }

  virtual bool requires_dyn_ctx () const { return true; }

  DEFAULT_UNARY_CODEGEN(DropValueIndex);
};


/*******************************************************************************
  build-index($indexUri as xs:uri) as ()

  Populates the index with the given uri. This function is re-writen by the
  optimizer (see compiler/rewriter/rules/expand_index_rule.cpp) into the 
  following sequential expr:

    index-session-opener(uriExpr);

    for $$dot at $$pos in domainExpr
    return index-builder(uriExpr, $$dot, fieldExpr1, ..., fieldExprN);

    index-session-closer(uriExpr);

  The functions index-session-opener, index-builder, and index-session-closer
  are defined below.
********************************************************************************/
class zop_buildindex : public function 
{
public:
  zop_buildindex(const signature& sig) : function(sig) { }

  virtual bool requires_dyn_ctx() const { return true; }

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const
  {
    ZORBA_ASSERT(false);
  }
};


/*******************************************************************************
  index-session-opener($indexUri as xs:uri) as ()

  It notifies the store that an index bulkload is about to take place. This
  allows the store to create a context for the bulkload and any associated
  data structs that may make the bulkload more efficient. For example, the
  store may decide to store all the subsequent index entries in a temporary
  table, then sort them and finally inserted them in the index in sorted order.

  During runtime, the store index object is retrieved from the dynamic context
  and an insert-session obj is requested from it. The insert-session obj is
  stored in the dynamic context together with the store index object.
********************************************************************************/
class zop_index_session_opener : public function 
{
public:
  zop_index_session_opener(const signature& sig) : function(sig) { }

  virtual bool requires_dyn_ctx() const { return true; }

  DEFAULT_UNARY_CODEGEN(ValueIndexInsertSessionOpener);
};


/*******************************************************************************
  index-session-closer($indexUri as xs:uri) as ()

  Notifies the store that the index bulkload session is finished, i.e., there are
  no more entries to insert in the index during this session. The notification is
  done via the insert-session obj, which is retrieved from the dynamic context.
********************************************************************************/
class zop_index_session_closer : public function 
{
public:
  zop_index_session_closer(const signature& sig) : function(sig) { }

  virtual bool requires_dyn_ctx() const { return true; }

  DEFAULT_UNARY_CODEGEN(ValueIndexInsertSessionCloser);
};


/*******************************************************************************
  index-builder($indexUri as xs:uri, 
                $domainValue as item(),
                $field1 as item(),
                ...,
                $fieldN as item()) as ()
********************************************************************************/
class zop_index_builder : public function 
{
public:
  zop_index_builder(const signature& sig) : function(sig) { }

  virtual bool requires_dyn_ctx () const { return true; }

  DEFAULT_NARY_CODEGEN(ValueIndexBuilder);
};


/***************************************************************************//**
  item* probe-index-point(uriExpr     as xs:uri,
                          column1Expr as anyAtomic?,
                          ...,
                          columnNExpr as anyAtomic?)
********************************************************************************/
class zop_probeindexpoint : public function 
{
public:
  zop_probeindexpoint(const signature& sig) : function(sig) { }

  virtual bool requires_dyn_ctx () const { return true; }

  DEFAULT_NARY_CODEGEN(ValueIndexPointProbe);
};


/*******************************************************************************
  item* probe-index-range(uriExpr                  as xs:uri,
                          range1LowerBoundExpr     as anyAtomic?,
                          range1UpperBoundExpr     as anyAtomic?,
                          range1HaveLowerBound     as anyAtomic?,
                          range1HaveupperBound     as anyAtomic?,
                          range1LowerBoundIncluded as anyAtomic?,
                          range1upperBoundIncluded as anyAtomic?,
                          ....,
                          rangeNLowerBoundExpr     as anyAtomic?,
                          rangeNUpperBoundExpr     as anyAtomic?,
                          rangeNHaveLowerBound     as anyAtomic?,
                          rangeNHaveupperBound     as anyAtomic?,
                          rangeNLowerBoundIncluded as anyAtomic?,
                          rangeNupperBoundIncluded as anyAtomic?,
********************************************************************************/
class zop_probeindexrange : public function 
{
public:
  zop_probeindexrange(const signature& sig) : function(sig) { }

  virtual bool requires_dyn_ctx () const { return true; }

  DEFAULT_NARY_CODEGEN(ValueIndexRangeProbe);
};



void populateContext_Index(static_context* sctx)
{
  DECL(sctx, zop_createindex,
       (createQName(ZORBA_OPEXTENSIONS_NS,"op-extensions", "create-index"),
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE,
        GENV_TYPESYSTEM.EMPTY_TYPE));

  DECL(sctx, zop_dropindex,
       (createQName(ZORBA_OPEXTENSIONS_NS,"op-extensions", "drop-index"),
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE,
        GENV_TYPESYSTEM.EMPTY_TYPE));

  DECL(sctx, zop_buildindex,
       (createQName(ZORBA_OPEXTENSIONS_NS,"op-extensions", "build-index"),
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE,
        GENV_TYPESYSTEM.EMPTY_TYPE));

  DECL(sctx, zop_index_session_opener,
       (createQName(XQUERY_FN_NS,"fn", ":index-session-opener"),
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE,
        GENV_TYPESYSTEM.EMPTY_TYPE));
  
  DECL(sctx, zop_index_session_closer,
       (createQName(XQUERY_FN_NS,"fn", ":index-session-closer"),
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE,
        GENV_TYPESYSTEM.EMPTY_TYPE));
  
  DECL(sctx, zop_index_builder,
       (createQName(XQUERY_FN_NS,"fn", ":index-builder"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        true,
        GENV_TYPESYSTEM.EMPTY_TYPE));

  DECL(sctx, zop_probeindexpoint,
       (createQName(ZORBA_OPEXTENSIONS_NS,"op-extensions", "probe-index-point"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
        true,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, zop_probeindexrange,
       (createQName(ZORBA_OPEXTENSIONS_NS,"op-extensions", "probe-index-range"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
        true,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));
}


}
/* vim:set ts=2 sw=2: */

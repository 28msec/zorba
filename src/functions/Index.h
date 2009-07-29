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
#ifndef ZORBA_FUNCTIONS_INDEX
#define ZORBA_FUNCTIONS_INDEX

#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba 
{

/******************************************************************************

********************************************************************************/
class zop_createindex : public function 
{
public:
  zop_createindex(const signature&);

  PlanIter_t codegen(CompilerCB* cb,
                      short sctx, const QueryLoc&, std::vector<PlanIter_t>&, AnnotationHolder&) const;

  virtual bool requires_dyn_ctx () const { return true; }
};


/******************************************************************************

********************************************************************************/
class zop_dropindex : public function 
{
public:
  zop_dropindex(const signature&);

  PlanIter_t codegen(CompilerCB* cb,
                      short sctx, const QueryLoc&, std::vector<PlanIter_t>&, AnnotationHolder&) const;

  virtual bool requires_dyn_ctx () const { return true; }
};


/*******************************************************************************

********************************************************************************/
class zop_buildindex : public function 
{
public:
  zop_buildindex(const signature&);

  PlanIter_t codegen(CompilerCB* cb,
                      short sctx, const QueryLoc&, std::vector<PlanIter_t>&, AnnotationHolder&) const;

  virtual bool requires_dyn_ctx () const { return true; }
};


/*******************************************************************************

********************************************************************************/
class zop_index_session_opener : public function 
{
public:
  zop_index_session_opener(const signature&);

  PlanIter_t codegen(CompilerCB* cb,
                      short sctx, const QueryLoc&, std::vector<PlanIter_t>&, AnnotationHolder&) const;

  virtual bool requires_dyn_ctx () const { return true; }
};


/*******************************************************************************

********************************************************************************/
class zop_index_session_closer : public function 
{
public:
  zop_index_session_closer(const signature&);

  PlanIter_t codegen(CompilerCB* cb,
                      short sctx, const QueryLoc&, std::vector<PlanIter_t>&, AnnotationHolder&) const;

  virtual bool requires_dyn_ctx () const { return true; }
};


/*******************************************************************************

********************************************************************************/
class zop_index_builder : public function 
{
public:
  zop_index_builder(const signature&);

  PlanIter_t codegen (CompilerCB* cb,
                      short sctx, const QueryLoc&, std::vector<PlanIter_t>&, AnnotationHolder&) const;

  virtual bool requires_dyn_ctx () const { return true; }
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
  zop_probeindexpoint(const signature&);

  PlanIter_t codegen(CompilerCB* cb,
                      short sctx, const QueryLoc&, std::vector<PlanIter_t>&, AnnotationHolder&) const;

  virtual bool requires_dyn_ctx () const { return true; }
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
  zop_probeindexrange(const signature&);

  PlanIter_t codegen(CompilerCB* cb,
                      short sctx, const QueryLoc&, std::vector<PlanIter_t>&, AnnotationHolder&) const;

  virtual bool requires_dyn_ctx () const { return true; }
};


}

#endif /* ZORBA_INTERNAL_OPERATORS_H */
/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */

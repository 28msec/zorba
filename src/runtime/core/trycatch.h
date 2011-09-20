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
#pragma once
#ifndef ZORBA_RUNTIME_TRYCATCH
#define ZORBA_RUNTIME_TRYCATCH

#include <vector>

#include "common/shared_types.h"

#include "runtime/base/unarybase.h"

namespace zorba
{

class TryCatchIteratorState : public  PlanIteratorState 
{
public:
  TryCatchIteratorState();
  ~TryCatchIteratorState();
      
  void init(PlanState&);
  void reset(PlanState&);

  // used for evaluating the target expression eagerly
  store::TempSeq_t  theTargetSequence;
  store::Iterator_t theTempIterator;
  PlanIter_t theCatchIterator;

  std::vector<store::Iterator_t> theErrorIters;
};


class TryCatchIterator : public UnaryBaseIterator<TryCatchIterator,
                                                  TryCatchIteratorState> 
{
public:
  class CatchClause : public ::zorba::serialization::SerializeBaseClass
  {
  public:
    enum var_type
    {
      err_code = 0,
      err_desc,
      err_value,
      err_module,
      err_line_no,
      err_column_no,
      zerr_stack_trace
    };

  public:
    std::vector<NodeNameTest_t> node_names;
    PlanIter_t     catch_expr;
    typedef std::map<int, std::vector<LetVarIter_t> > VarMap_t;
    VarMap_t vars;

  public:
    SERIALIZABLE_CLASS(CatchClause);

    SERIALIZABLE_CLASS_CONSTRUCTOR(CatchClause);

    void serialize(::zorba::serialization::Archiver &ar)
    {
      ar & node_names;
      ar & catch_expr;
      ar & vars;
    }

    CatchClause() {}

    ~CatchClause();
  };

protected:
  std::vector<CatchClause> theCatchClauses;

public:
  SERIALIZABLE_CLASS(TryCatchIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  TryCatchIterator,
  UnaryBaseIterator<TryCatchIterator, TryCatchIteratorState>);

  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, 
    (UnaryBaseIterator<TryCatchIterator, TryCatchIteratorState>*)this);

    ar & theCatchClauses;
  }


public:  
  TryCatchIterator(
        static_context* sctx,
        const QueryLoc& loc,
        PlanIter_t& aBlock,
        std::vector<CatchClause>& aCatchClauses);

  virtual ~TryCatchIterator();
  
  void openImpl(PlanState& planState, uint32_t& offset);
  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
  void resetImpl(PlanState& planState) const;
  void closeImpl(PlanState& planState);

  virtual void accept(PlanIterVisitor& v) const;
  virtual uint32_t getStateSizeOfSubtree() const;

protected:
  bool matchedCatch(ZorbaException const& e, TryCatchIteratorState* state, PlanState&) const;

  void bindErrorVars(ZorbaException const& e, const CatchClause* state, PlanState&) const;

  store::Item_t getStackTrace(const XQueryStackTrace&) const;
};
  


} /* namespace zorba */

#endif /* ZORBA_TRYCATCH_H */
/* vim:set et sw=2 ts=2: */

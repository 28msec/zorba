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
#ifndef ZORBA_RUNTIME_GFLWOR_ORDERBY
#define ZORBA_RUNTIME_GFLWOR_ORDERBY

#include "zorbautils/checked_vector.h"

#include "common/shared_types.h"

#include "runtime/base/plan_iterator.h"
#include "runtime/core/gflwor/common.h"

#include "store/api/temp_seq.h" //FIXME not sure why this is needed here

namespace zorba 
{
namespace flwor 
{

class OrderByIterator;

class OrderValue;
    

class OrderValue 
{
  friend class OrderByIterator;

protected:
  std::vector<store::Item_t > theItems;
  std::vector<store::TempSeq_t > theSequences;
  
public:
  OrderValue(
        std::vector<store::Item_t >& aItems,
        std::vector<store::TempSeq_t >& aSequences)
    :
    theItems ( aItems ),
    theSequences ( aSequences ) {}
};


typedef std::multimap<std::vector<store::Item_t >, OrderValue, OrderKeyCmp> order_map_t;


class OrderByState : public PlanIteratorState 
{
  friend class OrderByIterator;
protected:
  order_map_t theOrderMap;
  order_map_t::const_iterator  theCurOrderPos;

public:
  ~OrderByState();
  OrderByState();
  void init ( PlanState& aState, std::vector<OrderSpec>* orderSpecs );
  void reset ( PlanState& );
};

    
class OrderByIterator : public Batcher<OrderByIterator> 
{
private:
  PlanIter_t theTupleIter;
  std::vector<OrderSpec> theOrderSpecs;
  std::vector<ForVarIter_t> theForVariableInput;
  std::vector<LetVarIter_t> theLetVariableInput;
  std::vector< std::vector< ForVarIter_t > > theForVariableOutput;
  std::vector< std::vector< LetVarIter_t > > theLetVariableOutput;
  
public:
  OrderByIterator ( const QueryLoc& aLoc,
                    PlanIter_t aTupleIterator,
                    std::vector<OrderSpec>& aOrderSpecs,
                    std::vector<ForVarIter_t>& aForVariableInput,
                    std::vector<LetVarIter_t>& aLetVariableInput,
                    std::vector< std::vector< ForVarIter_t > >& aForVariableOutput,
                    std::vector< std::vector< LetVarIter_t > >& aLetVariableOutput );
  
  ~OrderByIterator();

  void openImpl ( PlanState& planState, uint32_t& offset );
  bool nextImpl ( store::Item_t& result, PlanState& planState ) const;
  void resetImpl ( PlanState& planState ) const;
  void closeImpl ( PlanState& planState );
  
  virtual uint32_t getStateSize() const;
  virtual uint32_t getStateSizeOfSubtree() const;

  virtual void accept ( PlanIterVisitor& ) const;

private:
  void matVarsAndOrderBy ( OrderByState* aOrderByState,
                           PlanState& aPlanState ) const;

  void bindOrderBy ( order_map_t::const_iterator& aOrderMapIter,
                     PlanState& aPlanState ) const;
};


}//namespace gflwor
} //namespace zorba


#endif  /* ZORBA_RUNTIME_GFLWOR_ORDERBY */

/*
 * Local variables:
 * mode: c++
 * End:
 */

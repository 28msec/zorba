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
#ifndef ZORBA_RUNTIME_GFLWOR_COMMON
#define ZORBA_RUNTIME_GFLWOR_COMMON

#include "zorba/api_shared_types.h"
#include "zorbautils/checked_vector.h"
#include "runtime/core/var_iterators.h"
#include "system/globalenv.h"
#include "store/api/store.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "store/api/temp_seq.h"

namespace zorba 
{

namespace flwor
{

/***************************************************************************//**
  Wrapper for a OrderSpec.
  http://www.w3.org/TR/xquery-11/#id-group-by

  GroupingSpec ::= "$" VarName ("collation" URILiteral)?
********************************************************************************/
class GroupingSpec
{
  friend class FLWORIterator;
  friend class PrinterVisitor;
  friend class GroupByIterator;
  friend class GroupByClause;//Just for older gcc's
  
protected:
  PlanIter_t                theInput;
  std::vector<ForVarIter_t> theInnerVars;
  xqpString                 theCollation;
  
public:
  GroupingSpec(
        PlanIter_t aInput,
        std::vector<ForVarIter_t> aInnerVars,
        xqpString aCollation );

  void accept ( PlanIterVisitor& ) const;

  uint32_t getStateSizeOfSubtree() const; 

  void open ( PlanState& planState, uint32_t& offset );
  void close ( PlanState& planState );
  void reset ( PlanState& planState ) const;
};


class GroupingOuterVar
{
  friend class FLWORIterator;
  friend class GroupByIterator;
  friend class PrinterVisitor;
  friend class GroupByClause; //Just for older gcc's
  
protected:
  PlanIter_t                theInput;
  std::vector<LetVarIter_t> theOuterVars;
  
public:
  GroupingOuterVar(PlanIter_t aInput, std::vector<LetVarIter_t> aOuterVars);

  void accept ( PlanIterVisitor& ) const;

  uint32_t getStateSizeOfSubtree() const; 

  void open ( PlanState& planState, uint32_t& offset );
  void reset ( PlanState& planState ) const;
  void close ( PlanState& planState );
};


/***************************************************************************//**
  Wrapper for a OrderSpec.
  http://www.w3.org/TR/xquery-11/#id-order-by-clause

  OrderSpec ::= ExprSingle OrderModifier

  OrderModifier ::= ("ascending" | "descending")?
                    ("empty" ("greatest" | "least"))?
                    ("collation" URILiteral)?
********************************************************************************/
class OrderSpec
{
  friend class FLWORIterator;
  friend class OrderByIterator;
  friend class OrderKeyCmp;

protected:
  PlanIter_t             theOrderByIter;
  bool                   theEmptyLeast;
  bool                   theDescending;
  xqpString              theCollation;
  mutable XQPCollator  * theCollator; // TODO hack

public:
  OrderSpec(
        PlanIter_t orderByIter,
        bool empty_least,
        bool descending);

  OrderSpec(
        PlanIter_t orderByIter,
        bool empty_least,
        bool descending,
        const xqpString& collation);

  void accept(PlanIterVisitor&) const;

  uint32_t getStateSizeOfSubtree() const;

  void open(PlanState& aPlanState, uint32_t& offset) const;
  void reset(PlanState& aPlanState) const;
  void close(PlanState& aPlanState) const;
};


/***************************************************************************//**
  Class to pass to the MultiMap to do the comparison according to the OrderByClause. 
  Luckily the MultiMap is stable already :-)
********************************************************************************/
class OrderKeyCmp
{
private:
  std::vector<OrderSpec> * theOrderSpecs;
  TypeManager            * theTypeManager;
  long                     theTimezone;

public:
  OrderKeyCmp() : theOrderSpecs(0), theTypeManager(0), theTimezone(0) {}

  OrderKeyCmp(RuntimeCB* rcb, std::vector<OrderSpec>* aOrderSpecs);

  bool operator() (
        const std::vector<store::Item_t>& s1,
        const std::vector<store::Item_t>& s2 ) const;
          
  inline long compare(
        const store::Item_t& s1,
        const store::Item_t& s2,
        bool asc,
        bool emptyLeast,
        XQPCollator* collator) const;
    
  inline long descAsc(long result, bool asc) const;
};



/***************************************************************************//**
  Utility function -- is this item null or a NaN?
********************************************************************************/
inline bool empty_item (store::Item_t s)
{
  return (s == 0) || (s->isNaN());
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Standard Iterator Tasks                                                    //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////
    

template <class T> inline void callAcceptVector(
    const std::vector<T >& aVector,
    PlanIterVisitor& aVisitor)
{
  typename std::vector<T >::const_iterator lIter;
  for ( lIter = aVector.begin();
        lIter != aVector.end();
        ++lIter )
  {
    lIter->accept(aVisitor);
  }
 }
 
 
template <class T> inline void callAcceptVectorPtr(
    const std::vector<T >& aVector,
    PlanIterVisitor& aVisitor)
{
  typename std::vector<T >::const_iterator lIter;
  for ( lIter = aVector.begin();
        lIter != aVector.end();
        ++lIter )
  {
    (*lIter)->accept(aVisitor);
  }
}
 
 
    
template <class T> inline void resetVector(
    const std::vector<T >& aVector,
    PlanState& aPlanState)
{
  typename std::vector<T >::const_iterator lIter;
  for ( lIter = aVector.begin();
        lIter != aVector.end();
        ++lIter )
  {
    lIter->reset(aPlanState);
  }
}
  

template <class T> inline void closeVector(
    std::vector<T >& aVector,
    PlanState& aPlanState)
{
  typename std::vector<T >::const_iterator lIter;
  for (lIter = aVector.begin();
       lIter != aVector.end();
       ++lIter )
  {
    lIter->close(aPlanState);
  }
}
  
  
template <class T> inline void openVector(
    std::vector<T >& aVector,
    PlanState& aPlanState,
    uint32_t& aOffset)
{
  typename std::vector<T >::iterator lIter;
  for (lIter = aVector.begin();
       lIter != aVector.end();
       ++lIter )
  {
    lIter->open(aPlanState, aOffset);
  }
}
  
  
template <class T> int32_t getStateSizeOfSubtreeVector(const std::vector<T >& aVector)
{
  int32_t lSize=0;
  typename std::vector<T >::const_iterator lIter;
  for (lIter = aVector.begin();
       lIter != aVector.end();
       ++lIter )
  {
    lSize += lIter->getStateSizeOfSubtree();
  }
  return lSize;
}
  
  
template <class T> void resetVectorPtr(const std::vector<T >& aVector, PlanState& aPlanState)
{
  typename std::vector<T >::const_iterator lIter;
  for ( lIter = aVector.begin();
        lIter != aVector.end();
        ++lIter )
  {
    (*lIter)->reset(aPlanState);
  }
}
  
  
template <class T> void closeVectorPtr(std::vector<T >& aVector, PlanState& aPlanState)
{
  typename std::vector<T >::const_iterator lIter;
  for (lIter = aVector.begin();
       lIter != aVector.end();
       ++lIter )
  {
    (*lIter)->close(aPlanState);
  }
}
  
  
template <class T> inline void openVectorPtr(std::vector<T >& aVector, PlanState& aPlanState, uint32_t& aOffset)
{
  typename std::vector<T >::iterator lIter;
  for (lIter = aVector.begin();
       lIter != aVector.end();
       ++lIter )
  {
    (*lIter)->open(aPlanState, aOffset);
  }
}
  
  
template <class T> inline int32_t getStateSizeOfSubtreeVectorPtr(const std::vector<T >& aVector)
{
  int32_t lSize=0;
  typename std::vector<T >::const_iterator lIter;
  for (lIter = aVector.begin();
       lIter != aVector.end();
       ++lIter )
  {
    lSize += (*lIter)->getStateSizeOfSubtree();
  }
  return lSize;
}
  
  
    
/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Static Binding Functions                                                   //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

inline void bindVariables (
    const store::Item_t& aItem,
    const std::vector<ForVarIter_t>& aForVariables,
    PlanState& aPlanState ) 
{
  std::vector<ForVarIter_t>::const_iterator forIter;
  for ( forIter = aForVariables.begin();
        forIter != aForVariables.end();
        ++forIter ) {
    const ForVarIter_t& variable = ( *forIter );
    variable->bind ( aItem.getp(), aPlanState );
  }
}
  

inline void bindVariables (
    const store::TempSeq_t& aTmpSeq,
    const std::vector<LetVarIter_t>& aLetVariables,
    PlanState& aPlanState ) 
{
  std::vector<LetVarIter_t>::const_iterator letIter;
  for ( letIter = aLetVariables.begin();
        letIter != aLetVariables.end();
        ++letIter ) {
    store::Iterator_t iter = aTmpSeq->getIterator();
    iter->open();
    ( *letIter )->bind ( iter, aPlanState );
  }
}
  

inline void createTempSeq(
    store::TempSeq_t& aTempSeqResult,
    const PlanIter_t& aInput,
    PlanState& aPlanState,
    const bool aLazyEval)
{
  store::Iterator_t iterWrapper = new PlanIteratorWrapper ( aInput, aPlanState );
  aTempSeqResult = GENV_STORE.createTempSeq ( iterWrapper, false, aLazyEval );
}
    

inline void bindVariables (
    const PlanIter_t& aInput,
    const std::vector<LetVarIter_t>& aLetVariables,
    PlanState& aPlanState,
    const bool aNeedsMaterialization) 
{
  if ( aNeedsMaterialization ) {
    store::TempSeq_t lTempSeq;
    createTempSeq(lTempSeq, aInput, aPlanState, true);
    bindVariables ( lTempSeq, aLetVariables, aPlanState );
  } else {
    store::Iterator_t iterWrapper = new PlanIteratorWrapper ( aInput, aPlanState );
    std::vector<LetVarIter_t>::const_iterator letIter;
    for ( letIter = aLetVariables.begin();
          letIter != aLetVariables.end();
          ++letIter ) {
      ( *letIter )->bind ( iterWrapper, aPlanState );
    }
  }
}
  
    
/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Other Helper Functions                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

inline bool evalToBool ( const PlanIter_t& checkIter, PlanState& planState )
{
  store::Item_t boolValue;
  if (!PlanIterator::consumeNext ( boolValue, checkIter.getp(), planState )){
    checkIter->reset ( planState );
    return false;
  }
  bool value = boolValue->getBooleanValue();
  checkIter->reset ( planState );
  return value;
}



}/* namespace gflwor */
} /* namespace zorba */
#endif  /* ZORBA_RUNTIME_GFLWOR_COMMON */


/*
 * Local variables:
 * mode: c++
 * End:
 */

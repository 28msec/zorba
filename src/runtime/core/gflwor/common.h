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
#include "zorbautils/hashmap.h"

#include "system/globalenv.h"

#include "runtime/core/var_iterators.h"
#include "runtime/api/plan_iterator_wrapper.h"

#include "store/api/store.h"
#include "store/api/temp_seq.h"

namespace zorba 
{

namespace flwor
{


/*******************************************************************************
  Holds the value of a tuple in the flwor tuple stream.

  theItems     : The values of the FOR vars in the tuple
  theSequences : The values of the LET vars in the tuple
********************************************************************************/
class StreamTuple
{
  friend class OrderByIterator;

protected:
  std::vector<store::Item_t >    theItems;
  std::vector<store::TempSeq_t > theSequences;
  
public:
  StreamTuple() {}

  StreamTuple(
        std::vector<store::Item_t >& items,
        std::vector<store::TempSeq_t >& sequences)
    :
    theItems(items),
    theSequences(sequences) 
  {
  }
};


/***************************************************************************//**
  Wrapper for a GroupingSpec.

  - Syntax:

  GroupingSpec ::= "$" VarName ("collation" URILiteral)?

  - Data Members:

  theInput     : A ForVarIter or LetVarIter referencing the FOR/LET variable
                 corresponding to this grouping variable in the input tuple 
                 stream.
  theInnerVars : All references of this grouping variable in the output tuple
                 stream.
  theCollation : The collation to use when comparing values of this grouping
                 var (if the values are of type xs:string or subtype).
  theCollator  : Pointer to the collator obj corresponding to theCollation.
                 The pointer is assigned by the OrderByClause::open() method.
                 Note: no need to delete theCollator in ~OrderSpec() because
                 the obj is managed by the collation cache.
********************************************************************************/
class GroupingSpec
{
  friend class FLWORIterator;
  friend class PrinterVisitor;
  friend class GroupTupleCmp;
  friend class GroupByIterator;
  friend class GroupByClause;//Just for older gcc's
  
protected:
  PlanIter_t                theInput;
  std::vector<ForVarIter_t> theInnerVars;
  std::string               theCollation;
  XQPCollator             * theCollator;

public:
  GroupingSpec(
        PlanIter_t inputVar,
        const std::vector<PlanIter_t>& outputVarRefs,
        const std::string& aCollation);

  void accept ( PlanIterVisitor& ) const;

  uint32_t getStateSizeOfSubtree() const; 

  void open ( PlanState& planState, uint32_t& offset );
  void close ( PlanState& planState );
  void reset ( PlanState& planState ) const;
};


/***************************************************************************//**
  Wrapper for a GroupingOuterVar.

  - Data Members:

  theInput     : A ForVarIter or LetVarIter referencing the FOR/LET variable
                 corresponding to this non-grouping variable in the input tuple
                 stream.
  theOuterVars : All references to this non-grouping variable in the output
                 tuple stream.
********************************************************************************/
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
  GroupingOuterVar(
        PlanIter_t inputVar,
        const std::vector<PlanIter_t>& outputVarRefs);

  void accept(PlanIterVisitor& v) const;

  uint32_t getStateSizeOfSubtree() const; 

  void open ( PlanState& planState, uint32_t& offset );
  void reset ( PlanState& planState ) const;
  void close ( PlanState& planState );
};


/***************************************************************************//**
  Each tuple it in the input tuple stream is assigned to a group based on the
  typed values of the items to which the grouping variables are bound in it.

  For each such group G, there is a GroupTuple T, which stores the typed values
  that define the group. Let itg be the 1st tuple in the input tuple stream that
  is assigned to G. Then T also stores the items to which the grouping variables
  are bound in itg. These items are needed because if otg is the tuple 
  corresponding to G in the output tuple stream, the grouping variables in otg
  will be bound to these items.

  theItems       : The values of the grouping variables in itg and otg.
  theTypedValues : The typed values of theItems.
********************************************************************************/
class GroupTuple
{
public:
  std::vector<store::Item_t> theItems;
  std::vector<store::Item_t> theTypedValues;    
};


/***************************************************************************//**
  Class acting as a comparison function between to groupby tuples. An instance
  of this class is passed to the GroupHashMap that we use to do the grouping.
********************************************************************************/
class GroupTupleCmp
{
private:
  std::vector<GroupingSpec> * theGroupingSpecs;
  TypeManager               * theTypeManager;
  long                        theTimezone;

public:
  GroupTupleCmp() : theGroupingSpecs(0), theTypeManager(0), theTimezone(0) {}

  GroupTupleCmp(RuntimeCB* rcb, std::vector<GroupingSpec>* groupSpecs);

  uint32_t hash(GroupTuple* t) const;

  bool equal(const GroupTuple* t1, const GroupTuple* t2) const;
};


/***************************************************************************//**
  The hash map used to do the grouping. For each GroupTuple T, it stores
  the tuple itself and one temp sequence for each non-grouping variable. The
  temp seq for a non-grouping var v stores the concatenation of all the values
  that v was bound to in each input tuple it that matched with T. These sequences
  are the values to which the non-grouping vars will be bound in tuple otg.
********************************************************************************/
typedef zorba::HashMap<GroupTuple*,
                       std::vector<store::TempSeq_t>*,
                       GroupTupleCmp> GroupHashMap;


/***************************************************************************//**
  Utility function -- is this item null or a NaN?
********************************************************************************/
inline bool empty_item (const store::Item* s)
{
  return (s == 0) || (s->isNaN());
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Standard Iterator Tasks                                                    //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////
    

template <class T> inline void castIterVector(
    std::vector<rchandle<T> >& destVector,
    const std::vector<PlanIter_t>& sourceVector)
{
  ulong numIters = sourceVector.size();
  destVector.resize(numIters);

  for (ulong i = 0; i < numIters; ++i)
    destVector[i] = reinterpret_cast<T*>(sourceVector[i].getp());
 }


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
       ++lIter)
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
  std::vector<ForVarIter_t>::const_iterator forIter = aForVariables.begin();
  std::vector<ForVarIter_t>::const_iterator forEnd = aForVariables.end();
  for (; forIter != forEnd; ++forIter) 
  {
    const ForVarIter_t& variable = ( *forIter );
    variable->bind ( aItem.getp(), aPlanState );
  }
}
  

inline void bindVariables (
    const store::TempSeq_t& aTmpSeq,
    const std::vector<LetVarIter_t>& aLetVariables,
    PlanState& aPlanState ) 
{
  std::vector<LetVarIter_t>::const_iterator letIter = aLetVariables.begin();
  std::vector<LetVarIter_t>::const_iterator letEnd = aLetVariables.end();
  for (; letIter != letEnd; ++letIter) 
  {
    store::Iterator_t iter = aTmpSeq->getIterator();
    iter->open();
    ( *letIter )->bind(iter, aPlanState);
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

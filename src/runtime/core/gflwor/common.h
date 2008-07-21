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

using namespace zorba;

namespace zorba {
  namespace gflwor {
    
    
    
      // Utility function -- is this item null or a NaN?
    inline bool empty_item (RuntimeCB* aRuntimeCB, store::Item_t s)
    {
      return (s == 0) || (s->isNaN());
    }

    
    template <class T> inline void resetVector(const std::vector<T >& aVector, PlanState& aPlanState)
    {
      typename std::vector<T >::const_iterator lIter;
      for ( lIter = aVector.begin();
           lIter != aVector.end();
           ++lIter )
      {
        lIter->reset(aPlanState);
      }
    }
    
    template <class T> inline void closeVector(std::vector<T >& aVector, PlanState& aPlanState)
    {
      typename std::vector<T >::const_iterator lIter;
      for (lIter = aVector.begin();
           lIter != aVector.end();
           ++lIter )
      {
        lIter->close(aPlanState);
      }
    }

    template <class T> inline void openVector(std::vector<T >& aVector, PlanState& aPlanState, uint32_t& aOffset)
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

    inline void bindVariables ( store::Item_t& aItem,
                                const std::vector<ForVarIter_t>& aForVariables,
                                PlanState& aPlanState ) {
      std::vector<ForVarIter_t>::const_iterator forIter;
      for ( forIter = aForVariables.begin();
            forIter != aForVariables.end();
            ++forIter ) {
        const ForVarIter_t& variable = ( *forIter );
        variable->bind ( aItem.getp(), aPlanState );
      }
    }

    inline void bindVariables ( store::TempSeq_t& aTmpSeq,
                                const std::vector<LetVarIter_t>& aLetVariables,
                                PlanState& aPlanState ) {
      std::vector<LetVarIter_t>::const_iterator letIter;
      for ( letIter = aLetVariables.begin();
            letIter != aLetVariables.end();
            ++letIter ) {
        store::Iterator_t iter = aTmpSeq->getIterator();
        iter->open();
        ( *letIter )->bind ( iter, aPlanState );
      }
    }

    inline void bindVariables ( const PlanIter_t& aInput,
                                const std::vector<LetVarIter_t>& aLetVariables,
                                PlanState& aPlanState,
                                const bool aNeedsMaterialization ) {
      store::Iterator_t iterWrapper = new PlanIteratorWrapper ( aInput, aPlanState );
      if ( aNeedsMaterialization ) {
        store::TempSeq_t tmpSeq = GENV_STORE.createTempSeq ( iterWrapper, false, true );
        bindVariables ( tmpSeq, aLetVariables, aPlanState );
      } else {
        std::vector<LetVarIter_t>::const_iterator letIter;
        for ( letIter = aLetVariables.begin();
              letIter != aLetVariables.end();
              ++letIter ) {
          ( *letIter )->bind ( iterWrapper, aPlanState );
        }
      }
    }
    
    inline bool evalToBool ( const PlanIter_t& checkIter, PlanState& planState )
    {
      store::Item_t boolValue;
      if (!PlanIterator::consumeNext ( boolValue, checkIter.getp(), planState ))
        return false;

      bool value = boolValue->getBooleanValue();
      checkIter->reset ( planState );
      return value;
    }




  }/* namespace gflwor */
} /* namespace zorba */
#endif  /* ZORBA_RUNTIME_GFLWOR_COMMON */

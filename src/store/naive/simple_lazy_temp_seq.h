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
#ifndef ZORBA_STORE_SIMPLE_LAZY_TEMP_SEQ_H
#define ZORBA_STORE_SIMPLE_LAZY_TEMP_SEQ_H

#include <vector>

#include "store/api/iterator.h"
#include "store/api/temp_seq.h"
#include "store/api/copymode.h"

namespace zorba {
  namespace simplestore {

    /**
       * Very simple implementation of Temp Sequence. It saves the resulting items
       * of an iterator eager in a vector.
     */
    typedef rchandle<class SimpleLazyTempSeq> SimpleLazyTempSeq_t;

    
    class SimpleLazyTempSeq : public store::TempSeq {
      private:
        std::vector<store::Item_t> theItems;
        store::Iterator_t theIterator;
        bool theCopy;
        bool theMatFinished;
        uint32_t thePurgedUpTo;
      public:
        static const uint32_t MAX_POSITION;

      public:
        SimpleLazyTempSeq() { }

        SimpleLazyTempSeq ( store::Iterator_t iter, bool copy = false );

        virtual ~SimpleLazyTempSeq();

        bool empty();

        void append ( store::Iterator_t iter, bool copy );

        store::Item_t getItem ( int32_t position );

        bool getItem ( store::Item_t& result, int32_t position ){
          if ( this->containsItem ( position ) ) {
            result = theItems[position - thePurgedUpTo - 1];
            return true;
          } else {
            result = NULL;
            return false;
          }
        }

        inline bool containsItem ( int32_t position ) {
          uint32_t maxPos = position - thePurgedUpTo;
          assert(maxPos > 0); //Otherwise we have a serious problem
          while ( !theMatFinished && theItems.size() < maxPos ) { //Need to fix size type
            matNextItem();
          }
          return int32_t ( theItems.size() ) >= maxPos;
        }

        store::Iterator_t getIterator();

        store::Iterator_t getIterator (int32_t startPos, int32_t endPos, bool streaming = false );

        store::Iterator_t getIterator (int32_t startPos, store::Iterator_t function, const std::vector<store::Iterator_t>& var, bool streaming = false );

        store::Iterator_t getIterator (const std::vector<int32_t>& positions, bool streaming = false );

        store::Iterator_t getIterator ( store::Iterator_t positions, bool streaming = false );
        
        void purge();
        void purgeUpTo ( int32_t upTo );
        void purgeItem ( const std::vector<int32_t>& positions );
        void purgeItem ( int32_t position );

      private:
        inline void matNextItem() {
          theItems.push_back ( NULL );
          store::Item_t& lLocation = theItems.back();
          if ( theIterator->next ( lLocation ) ) {
            if ( theCopy && lLocation->isNode() ) {
              store::CopyMode lCopyMode;
              lLocation = lLocation->copy ( NULL, 0, lCopyMode );
            }
          } else {
            //We do not want to have an empty item materialized.
            theItems.pop_back();
            theMatFinished = true;
          }
        }
    }; /* class SimpleLazyTempSeq */


    class SimpleLazyTempSeqIter : public store::Iterator {
      private:
        SimpleLazyTempSeq_t        theTempSeq;

        uint32_t                    theCurPos;
        uint32_t                    theStartPos;
        uint32_t                    theEndPos;

      public:
        SimpleLazyTempSeqIter (SimpleLazyTempSeq_t aTempSeq, uint32_t aStartPos, uint32_t aEndPos );
        virtual ~SimpleLazyTempSeqIter();
        void open();
        bool next ( store::Item_t& result );
        void reset();
        void close();
    };


  } // namespace store
} // namespace zorba

#endif /* ZORBA_STORE_SIMPLE_LAZY_TEMP_SEQ_H */

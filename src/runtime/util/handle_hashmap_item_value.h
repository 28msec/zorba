#ifndef ZORBA_STORE_HANDLE_HAHSET_ITEM_VALUE_H
#define ZORBA_STORE_HANDLE_HAHSET_ITEM_VALUE_H

#include "util/hashfun.h"

#include "store/util/hashmap.h"
#include "runtime/booleans/BooleanImpl.h"


namespace zorba
{
  namespace store
  {

    class GroupCompareParam
    {
      public:
        GroupCompareParam ( RuntimeCB* aRuntimeCB,  std::vector<XQPCollator*> aCollators )
            : theRuntimeCB ( aRuntimeCB ), theCollators(aCollators) {}
        RuntimeCB* theRuntimeCB;
        std::vector<XQPCollator*> theCollators;
        
    };


    template <class T, class E>
        class Externals<T, E, GroupCompareParam>
        {
          public:
            static bool equal(const T& t1, const T& t2, GroupCompareParam* aCompareParam)
            {
              return E::equal(t1, t2, aCompareParam);
            }
            static uint32_t hash(const T& t1, GroupCompareParam* aCompareParam)
            {
              return E::hash(t1, aCompareParam);
            }
        };


    template <class V>
    class ItemValuesCollHandleHashMap : public HashMap<std::vector<Item_t>*, V,
          ItemValuesCollHandleHashMap<V>,
          GroupCompareParam>
    {
      public:
        ItemValuesCollHandleHashMap (
            GroupCompareParam* aCompareParam,
            long size = 1024 )
            :
          HashMap<std::vector<Item_t>*, V, ItemValuesCollHandleHashMap, GroupCompareParam> ( aCompareParam, size )
        {}

        static bool equal ( const std::vector<Item_t>* t1, const std::vector<Item_t>* t2, GroupCompareParam* aCompareParam )
        {
          assert(aCompareParam->theCollators.size() == t1->size());
          assert(t2->size() == t1->size());
          std::vector<Item_t>::const_iterator iter1 = t1->begin();
          std::vector<Item_t>::const_iterator iter2 = t2->begin();
          std::vector<XQPCollator*>::iterator lCollIter = aCompareParam->theCollators.begin();
          while(iter1 != t1->end()){
            if(CompareIterator::valueEqual ( aCompareParam->theRuntimeCB,
               *iter1, *iter2,
               ( *lCollIter ) ) != 0){
              return false;                                 
            }
            ++lCollIter;
            ++iter1;
            ++iter2;
          }
          return true;
        }

        static uint32_t hash (std::vector<Item_t>* t, GroupCompareParam* aCompareParam )
        {
          uint32_t hash=0;
          assert(aCompareParam->theCollators.size() == t->size());
          std::vector<Item_t>::iterator lItemIter = t->begin();
          std::vector<XQPCollator*>::iterator lCollIter = aCompareParam->theCollators.begin();
          while(lItemIter != t->end()){
            hash += (*lItemIter)->hash ( aCompareParam->theRuntimeCB, *lCollIter );
            ++lCollIter;
            ++lItemIter;
          }
          return hash;
        }


    };


  } // namespace store
} // namespace zorba

#endif

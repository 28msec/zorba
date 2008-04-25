#ifndef ZORBA_STORE_HANDLE_HAHSET_ITEM_VALUE_H
#define ZORBA_STORE_HANDLE_HAHSET_ITEM_VALUE_H

#include "util/hashfun.h"

#include "store/util/hashmap.h"
#include "runtime/booleans/BooleanImpl.h"


namespace zorba
{
  namespace store
  {
    
    //TODO Do this nice when refactoring the FLWOR
    class GroupKey{
      public:
        std::vector<Item_t> theKey;
        std::vector<Item_t> theTypedKey;    
    };

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
        class ItemValuesCollHandleHashMap : public HashMap<GroupKey*, V,
          ItemValuesCollHandleHashMap<V>,
          GroupCompareParam>
    {
      public:
        ItemValuesCollHandleHashMap (
            GroupCompareParam* aCompareParam,
            long size = 1024 )
            :
          HashMap<GroupKey*, V, ItemValuesCollHandleHashMap, GroupCompareParam> ( aCompareParam, size )
        {}

        static bool equal ( const GroupKey* t1, const GroupKey* t2, GroupCompareParam* aCompareParam )
        {
          assert(aCompareParam->theCollators.size() == t1->theTypedKey.size());
          assert(t2->theTypedKey.size() == t1->theTypedKey.size());
          std::vector<Item_t>::const_iterator iter1 = t1->theTypedKey.begin();
          std::vector<Item_t>::const_iterator iter2 = t2->theTypedKey.begin();
          std::vector<XQPCollator*>::iterator lCollIter = aCompareParam->theCollators.begin();
          while(iter1 != t1->theTypedKey.end()){
            std::cout << "Comparing: " << (*iter1)->show() << ":" << (*iter2)->show() << std::endl;
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

        static uint32_t hash (GroupKey* t, GroupCompareParam* aCompareParam )
        {
          uint32_t hash=0;
          assert(aCompareParam->theCollators.size() == t->theTypedKey.size());
          std::vector<Item_t>::iterator lItemIter = t->theTypedKey.begin();
          std::vector<XQPCollator*>::iterator lCollIter = aCompareParam->theCollators.begin();
          while(lItemIter != t->theTypedKey.end()){
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

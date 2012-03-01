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

#include "collection.h"

#include "store/api/item.h"
#include "store/api/ic.h"

#include "node_items.h"
#include "simple_store.h"
#include "simple_index.h"

namespace zorba {

  namespace simplestore {

    void Collection::getIndexes(
        const store::Item* name,
        std::vector<store::Index*>& indexes)
    {
      const IndexSet& availableIndexes = GET_STORE().getIndices();
    
      IndexSet::iterator idxIte = availableIndexes.begin();
      IndexSet::iterator idxEnd = availableIndexes.end();
    
      for (; idxIte != idxEnd; ++idxIte)
      {
        IndexImpl* index = static_cast<IndexImpl*>((*idxIte).second.getp());
        const store::IndexSpecification& indexSpec = index->getSpecification();
    
        const std::vector<store::Item_t>& indexSources = indexSpec.theSources;
        ulong numIndexSources = indexSources.size();
    
        for (ulong i = 0; i < numIndexSources; ++i)
        {
          if (indexSources[i]->equals(name))
          {
            indexes.push_back(index);
            break;
          }
        }
      }
    }

    /**
     * Returns active integrity constraints referencing this collection.
     */
    void Collection::getActiveICs(
        const store::Item* name,
        std::vector<store::IC*>& ics)
    {
      store::Iterator_t activeICNames = GET_STORE().listActiveICNames();
    
      store::Item_t activeICName;
      activeICNames->open();
    
      while ( activeICNames->next(activeICName) )
      {
    
        store::IC* activeIC = GET_STORE().getIC(activeICName);
    
        switch( activeIC->getICKind() )
        {
        case store::IC::ic_collection:
          if ( activeIC->getCollectionName()->equals(name) )
            ics.push_back(activeIC);
          break;
    
        case store::IC::ic_foreignkey:
          if ( activeIC->getToCollectionName()->equals(name) )
            ics.push_back(activeIC);
    
          if ( activeIC->getFromCollectionName()->equals(name) )
            ics.push_back(activeIC);
          break;
    
        default:
          ZORBA_ASSERT(false);
        }
      }
    
      activeICNames->close();
    }

    /*******************************************************************************
    
    *******************************************************************************/
    void Collection::getActiveICs(std::vector<store::IC*>& ics)
    {
      store::Iterator_t activeICNames = GET_STORE().listActiveICNames();
    
      store::Item_t activeICName;
      activeICNames->open();
    
      while ( activeICNames->next(activeICName) )
      {
    
        store::IC* activeIC = GET_STORE().getIC(activeICName);
    
        switch( activeIC->getICKind() )
        {
        case store::IC::ic_collection:
          if ( activeIC->getCollectionName()->equals(getName()) )
            ics.push_back(activeIC);
          break;
    
        case store::IC::ic_foreignkey:
          if ( activeIC->getToCollectionName()->equals(getName()) )
            ics.push_back(activeIC);
    
          if ( activeIC->getFromCollectionName()->equals(getName()) )
            ics.push_back(activeIC);
          break;
    
        default:
          ZORBA_ASSERT(false);
        }
      }
    
      activeICNames->close();
    }


    /*******************************************************************************
    
    ********************************************************************************/
    void Collection::getIndexes(std::vector<store::Index*>& indexes)
    {
      const IndexSet& availableIndexes = GET_STORE().getIndices();
    
      IndexSet::iterator idxIte = availableIndexes.begin();
      IndexSet::iterator idxEnd = availableIndexes.end();
    
      for (; idxIte != idxEnd; ++idxIte)
      {
        IndexImpl* index = static_cast<IndexImpl*>((*idxIte).second.getp());
        const store::IndexSpecification& indexSpec = index->getSpecification();
    
        const std::vector<store::Item_t>& indexSources = indexSpec.theSources;
        uint64_t numIndexSources = (uint64_t)indexSources.size();
    
        for (std::size_t i = 0; i < numIndexSources; ++i)
        {
          if (indexSources[i]->equals(getName()))
          {
            indexes.push_back(index);
            break;
          }
        }
      }
    }


  } /* namespace simplestore */

} /* namespace zorba */
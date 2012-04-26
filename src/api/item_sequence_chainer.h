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
#ifndef ZORBA_ITERATOR_ITEM_SEQUENCE_CHAINER_H
#define ZORBA_ITERATOR_ITEM_SEQUENCE_CHAINER_H

#include <vector>
#include <set>
#include <assert.h>

#include <zorba/config.h>
#include <zorba/item_sequence.h>
#include <zorba/iterator.h>
#include <zorba/item.h>
#include <zorba/zorba_string.h>

namespace zorba { 

  /** \brief 
   *
   * See ItemSequence
   */
  class ZORBA_DLL_PUBLIC ItemSequenceChainer : public ItemSequence
  {
    public:
      /**
       */
      ItemSequenceChainer(
          const std::vector<ItemSequence_t>& aSequences,
          bool aDoDupElim = false);

      /** \brief Destructor
       */
      virtual ~ItemSequenceChainer();

      /** \brief get the Iterator over the items
       * @return an iterator over the items
      */
      virtual Iterator_t  getIterator();

    protected:
      std::vector<ItemSequence_t> theSequences;
      bool                        theDoDupElim;

    protected:
      class Iterator : public zorba::Iterator
      {
        public:
          Iterator(
              const std::vector<ItemSequence_t>& aSequences,
              bool aDoDupElim);

          virtual ~Iterator();

          virtual void 
          open();

          virtual bool
          next(Item& aItem);
          
          virtual void 
          close();

          virtual bool
          isOpen() const;

        protected:
          std::vector<ItemSequence_t>           theSequences;
          std::vector<ItemSequence_t>::iterator theSeqIter;
          zorba::Iterator_t                     theIter;
          bool                                  theIsOpen;
          bool                                  theDoDupElim;
  
          struct Comparator {
            bool operator()(const Item& i1, const Item& i2) const
            {
              assert(i1.getType().getLocalName() == "QName");
              assert(i2.getType().getLocalName() == "QName");
	      if (i1.getNamespace().compare(i2.getNamespace()) < 0)
		{
		  return true;
		}
	      if (i1.getNamespace().compare(i2.getNamespace()) > 0)
		{
		  return false;
		} 
	      // Namespaces are equal, comparing local names.
              return (i1.getLocalName().compare(i2.getLocalName()) < 0);
            }
          };

          std::set<Item, Comparator>             theDupElimSet;
      };
  }; /* class ItemSequenceChainer */

} // namespace zorba
#endif



/* vim:set et sw=2 ts=2: */

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
#include "stdafx.h"

#include <zorba/iterator.h>
#include "api/item_sequence_chainer.h"
#include <cassert>

namespace zorba { 

ItemSequenceChainer::ItemSequenceChainer(
    const std::vector<ItemSequence_t>& aSequences,
    bool aDoDupElim)
 : theSequences(aSequences),
   theDoDupElim(aDoDupElim)
{
}

ItemSequenceChainer::~ItemSequenceChainer()
{
}

Iterator_t ItemSequenceChainer::getIterator()
{
  return new ItemSequenceChainer::Iterator(theSequences, theDoDupElim);
}

ItemSequenceChainer::Iterator::Iterator(
    const std::vector<ItemSequence_t>& aSequences,
    bool aDoDupElim)
  : theSequences(aSequences),
    theDoDupElim(aDoDupElim)
{
}

ItemSequenceChainer::Iterator::~Iterator() 
{
}

void
ItemSequenceChainer::Iterator::open() 
{
  theSeqIter = theSequences.begin(); 
  if (theSeqIter != theSequences.end()) {
    theIter = (*theSeqIter)->getIterator();
    theIter->open();
  }
  theIsOpen = true;
}

bool
ItemSequenceChainer::Iterator::next(Item& aItem) 
{
  assert(theIsOpen);
  while (true) {
    if (theIter->next(aItem)) {
      if (theDoDupElim) {
        if (theDupElimSet.find(aItem) != theDupElimSet.end()) {
          continue;
        }
        theDupElimSet.insert(aItem);
      }
      return true;
    } else {
      if (++theSeqIter != theSequences.end()) {
        theIter = (*theSeqIter)->getIterator();
        theIter->open();
      } else {
        return false;
      }
    }
  }
}

void
ItemSequenceChainer::Iterator::close() 
{
  if (theIsOpen) {
    theIter = 0;
    theSeqIter = theSequences.end();
    theDupElimSet.clear();
  }
  theIsOpen = false;
}

bool
ItemSequenceChainer::Iterator::isOpen() const
{
  return theIsOpen;
}

} // namespace zorba


/* vim:set et sw=2 ts=2: */

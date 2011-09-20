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

#include <zorba/singleton_item_sequence.h>
#include <zorba/item.h>
#include "diagnostics/assert.h"

namespace zorba { 

SingletonItemSequence::SingletonItemSequence(
  const Item& aItem)
  : theItem(aItem)
{
}

Iterator_t SingletonItemSequence::getIterator()
{
  return new InternalIterator(this);
}

SingletonItemSequence::InternalIterator::InternalIterator(SingletonItemSequence *item_sequence) : theItemSequence(item_sequence)
{
  is_open = false;
  theDone = false;
}

void SingletonItemSequence::InternalIterator::open()
{
  is_open = true;
  theDone = false;
}

void SingletonItemSequence::InternalIterator::close()
{
  is_open = false;
}

bool SingletonItemSequence::InternalIterator::isOpen() const
{
  return is_open;
}

bool SingletonItemSequence::InternalIterator::next(Item& aItem)
{
  ZORBA_ASSERT(is_open);
  if(theDone)
    return false;
  aItem = theItemSequence->theItem;
  theDone = true;
  return !theItemSequence->theItem.isNull();
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */

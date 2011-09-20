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

#include "capi/error.h"
#include "capi/single_item_sequence.h"
#include <zorba/item_sequence.h>
#include "diagnostics/assert.h"

using namespace zorba;

namespace zorbac {

SingleItemSequence::SingleItemSequence(Item aItem)
  : theItem(aItem)
{
}

Iterator_t SingleItemSequence::getIterator()
{
  return new InternalIterator(this);
}

SingleItemSequence::InternalIterator::InternalIterator(SingleItemSequence *item_sequence) : theItemSequence(item_sequence)
{
  is_open = false;
  theDone = false;
}

void SingleItemSequence::InternalIterator::open()
{
  is_open = true;
  theDone = false;
}

void SingleItemSequence::InternalIterator::close()
{
  is_open = false;
}

bool SingleItemSequence::InternalIterator::isOpen() const
{
  return is_open;
}

bool SingleItemSequence::InternalIterator::next(Item& aItem)
{
  ZORBA_ASSERT(is_open);
  if(theDone)
    return false;
  aItem = theItemSequence->theItem;
  theDone = true;
  return true;
}

} /* namespace zorbac */
/* vim:set et sw=2 ts=2: */

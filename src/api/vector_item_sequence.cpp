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

#include <zorba/vector_item_sequence.h>

#include <zorba/item.h>
#include "diagnostics/assert.h"

namespace zorba { 

VectorItemSequence::VectorItemSequence(
  const std::vector<Item>& aSequence)
    : theSequence(aSequence)
{ }


Iterator_t VectorItemSequence::getIterator()
{
  return new InternalIterator(this);
}

VectorItemSequence::InternalIterator::InternalIterator(VectorItemSequence *item_sequence) : theItemSequence(item_sequence)
{
  is_open = false;
}

void VectorItemSequence::InternalIterator::open()
{
  is_open = true;
  theIterator = theItemSequence->theSequence.begin();
  theEnd = theItemSequence->theSequence.end();
}

void VectorItemSequence::InternalIterator::close()
{
  is_open = false;
}

bool VectorItemSequence::InternalIterator::isOpen() const
{
  return is_open;
}

bool
VectorItemSequence::InternalIterator::next(Item& val)
{
  ZORBA_ASSERT(is_open);
  if (theIterator == theEnd) {
      return false;
  }
  val = *theIterator;
  ++theIterator;
  return true;
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */

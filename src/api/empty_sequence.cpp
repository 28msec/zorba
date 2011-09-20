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
#include <zorba/empty_sequence.h>
#include "diagnostics/assert.h"

namespace zorba { 

Iterator_t EmptySequence::getIterator()
{
  return new InternalIterator(this);
}

EmptySequence::InternalIterator::InternalIterator(ItemSequence *item_sequence) : theItemSequence(item_sequence)
{
  is_open = false;
}

void EmptySequence::InternalIterator::open()
{
  is_open = true;
}

void EmptySequence::InternalIterator::close()
{
  is_open = false;
}

bool EmptySequence::InternalIterator::isOpen() const
{
  return is_open;
}

bool EmptySequence::InternalIterator::next(Item& aItem)
{
  ZORBA_ASSERT(is_open);
  return false;
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */

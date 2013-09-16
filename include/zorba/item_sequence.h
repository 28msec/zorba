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
#ifndef ZORBA_ITEM_SEQUENCE_API_H
#define ZORBA_ITEM_SEQUENCE_API_H

#include <zorba/config.h>
#include <zorba/api_shared_types.h>

namespace zorba
{ 

/** 
 * \brief ItemSequence represents an ordered sequence of items. The sequence
 * may contain any mix of atomic items, function items, nodes, JSON objects,
 * or JSON arrays.
 */
class ZORBA_DLL_PUBLIC ItemSequence : virtual public SmartObject
{
 public:
  /**
   * \brief Destructor
   */
  virtual ~ItemSequence() { }

  /**
   * \brief Create an iterator over the items of this sequence. The life time
   * of the iterator shouldnot exceed the life time of this item sequence.
   *
   * @return an iterator over the items
   * @throw Throws zerr::ZAPI0039 if the implementation of the associated
   *        ItemSequence does not allow more than one iterator to be created. 
   */
  virtual Iterator_t getIterator() = 0;

}; /* class ItemSequence */

} // namespace zorba
#endif
/* vim:set et sw=2 ts=2: */

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
#ifndef ZORBA_ITERATOR_H
#define ZORBA_ITERATOR_H

#include "zorbamisc/config/platform.h"
#include "store/api/item.h"

namespace zorba { namespace store {

/**
 * General iterator interface. Used to program iterators which return a
 * sequence of items, wrapped into a rchandle object for garbage collection
 */
class Iterator : virtual public SimpleRCObject
{
 public:
  Iterator() {}

  Iterator(const Iterator&) : SimpleRCObject() {}

  virtual ~Iterator() {}

  virtual void
  open() = 0;

  virtual bool
  next(store::Item_t&) = 0;

  virtual void
  reset() = 0;

  virtual void
  close() = 0;
};


/**
 * This iterator is used to iterate over the children of a document or element
 * node. It implements the interface of a generic iterator, but also offers the
 * following additional methods:
 *
 * - An init method that takes as input a document or element node and
 *   initializes the iterator so that it will start returning the children of
 *   this node.
 * - A next method that returns pointers to the children instead of rchandles.
 *   These pointers should not be used beyond the lifetime of the ChildrenIterator
 *   object. 
 */
class ChildrenIterator : public Iterator
{
public:
 ChildrenIterator() { }

  virtual void
  init(Item_t& parent) = 0;

  virtual Item*
  next() = 0;

  virtual void
  open() = 0;
  
  virtual bool
  next(Item_t& result) = 0;

  virtual void
  reset() = 0;

  virtual void
  close() = 0;
};


/**
 * This iterator is used to iterate over the attributes of an element node.
 * It implements the interface of a generic iterator, but also offers the
 * following additional methods:
 *
 * - An init method that takes as input an element node and initializes the
 *   iterator so that it will start returning the attributes of this node.
 * - A next method that returns pointers to the attributes instead of rchandles.
 *   These pointers should not be used beyond the lifetime of the AttributesIterator
 *   object. 
 */
class AttributesIterator : public Iterator
{
public:
 AttributesIterator() { }

  virtual void
  init(Item_t& parent) = 0;

  virtual Item*
  next() = 0;

  virtual void
  open() = 0;
  
  virtual bool
  next(Item_t& result) = 0;

  virtual void
  reset() = 0;

  virtual void
  close() = 0;
};


} /* namespace store */
} /* namespace zorba */
#endif

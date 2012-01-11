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
#ifndef ZORBA_STORE_ITERATOR_H
#define ZORBA_STORE_ITERATOR_H

#include "zorbamisc/config/platform.h"

#include "store/api/shared_types.h"
#include "store/api/item.h"


namespace zorba 
{ 

namespace store 
{

/**
 * General iterator interface. Used to program iterators which return a
 * sequence of items, wrapped into a rchandle object for garbage collection
 */
class Iterator : virtual public SimpleRCObject
{
 public:
  SERIALIZABLE_ABSTRACT_CLASS(Iterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(Iterator, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver &ar)
  {
  }

 public:
  Iterator() {}

  virtual ~Iterator() {}

  virtual void open() = 0;

  virtual bool next(store::Item_t&) = 0;

  virtual void reset() = 0;

  virtual void close() = 0;
};


/**
 * This iterator is used to iterate over the children of a document or element
 * node in document order. It implements the interface of a generic iterator, 
 * but also offers the following additional methods:
 *
 * - An init method that takes as input a document or element node and
 *   initializes the iterator so that it will start returning the children of
 *   this node. The method also takes an optional child parameter; if a child
 *   is given, the iterator will position itself on that child, so that the next
 *   next() call will return the right sibling of that child.
 * - A next method that returns pointers to the children instead of rchandles.
 *   These pointers should not be used beyond the lifetime of the ChildrenIterator
 *   object. 
 */
class ChildrenIterator : public Iterator
{
public:
  virtual ~ChildrenIterator() {}

  virtual void init(Item_t& parent, const Item* child = NULL) = 0;

  virtual void init(const Item* parent, const Item* child = NULL) = 0;
  
  virtual void open() = 0;

  virtual Item* next() = 0;
  
  virtual bool next(Item_t& result) = 0;
  
  virtual void reset() = 0;
  
  virtual void close() = 0;
};


/**
 * This iterator is used to iterate over the children of a document or element
 * node in reverse document order. It implements the interface of a generic
 * iterator, but also offers the following additional methods:
 *
 * - An init method that takes as input a document or element node and
 *   initializes the iterator so that it will start returning the children of
 *   this node. The method also takes an optional child parameter; if a child
 *   is given, the iterator will position itself on that child, so that the next
 *   next() call will return the left sibling of that child.
 * - A next method that returns pointers to the children instead of rchandles.
 *   These pointers should not be used beyond the lifetime of the ChildrenIterator
 *   object. 
 */
class ChildrenReverseIterator : public Iterator
{
public:
  virtual ~ChildrenReverseIterator() {}

  virtual void init(Item_t& parent, const Item* child = NULL) = 0;

  virtual void init(const Item* parent, const Item* child = NULL) = 0;
  
  virtual void open() = 0;

  virtual Item* next() = 0;
  
  virtual bool next(Item_t& result) = 0;
  
  virtual void reset() = 0;
  
  virtual void close() = 0;
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
  virtual ~AttributesIterator() { }

  virtual void init(Item_t& parent) = 0;

  virtual void init(const Item* parent) = 0;

  virtual void open() = 0;

  virtual Item* next() = 0;
  
  virtual bool next(Item_t& result) = 0;

  virtual void reset() = 0;

  virtual void close() = 0;
};


/**
 * This iterator is used to iterate over the result of an index probe. The
 * target index is specified when the iterator is created (see iterator_factory.h)
 * The IndexProbeIterator implements the interface of a generic iterator, but
 * also offers the following additional method:
 *
 * - An init method that takes as input an index condition, so that the iterator
 *   will return the items from the value set of each index key that satisfies 
 *   this condition.
 *
 *   NOTE: The method takes as input a reference to a condition. It will not
 *   necessarily make a copy of the referenced condition object. As a result,
 *   the condition object must remain alive at least until the iterator is 
 *   closed, or its init() method is called again with a different condition.
 */
class IndexProbeIterator : public Iterator
{
public:
  virtual ~IndexProbeIterator() { }

  virtual void init(const IndexCondition_t& cond) = 0;

  virtual void open() = 0;
  
  virtual bool next(Item_t& result) = 0;
  
  virtual void reset() = 0;
  
  virtual void close() = 0;
};


/**
 * This iterator is used to iterate over the items of a temporary sequence.
 * It implements the interface of a generic iterator, but also offers the
 * following additional methods:
 *
 * - An init method that takes as input a temp sequence and initializes the
 *   iterator so that it will start returning the items of this sequence.
 * - A next method that returns pointers to the items instead of rchandles.
 *   These pointers should not be used beyond the lifetime of the TempSeqIterator
 *   object. 
 */
class TempSeqIterator : public Iterator
{
public:
  virtual ~TempSeqIterator() { }

  virtual void init(const TempSeq_t& seq) = 0;
  
  virtual void open() = 0;
  
  virtual Item* next() = 0;
  
  virtual bool next(Item_t& result) = 0;
  
  virtual void reset() = 0;
  
  virtual void close() = 0;
};

} /* namespace store */
} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */

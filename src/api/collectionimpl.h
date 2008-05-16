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
#ifndef ZORBA_COLLECTIONIMPL_H
#define ZORBA_COLLECTIONIMPL_H

#include "common/shared_types.h"
#include <zorba/collection.h>

namespace zorba {

class CollectionImpl : public Collection
{
 public:
  CollectionImpl(const store::Collection_t& aCollection, ErrorHandler* aErrorHandler);
  
  virtual ~CollectionImpl();

  Item
  getUri();

  bool
  addItem(const Item& aItem);

  bool
  deleteItem(const Item& aItem);

  bool
  addItems(const ResultIterator* aResultIterator);

  bool
  addDocument(std::istream& lInStream);

 protected:
  friend class Unmarshaller;

  store::Collection_t   theCollection;
  ErrorHandler        * theErrorHandler;

  }; /* class CollectionImpl */

} /* namespace zorba */

#endif

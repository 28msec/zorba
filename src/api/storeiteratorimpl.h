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
#ifndef ZORBA_STOREITERATORIMPL_H
#define ZORBA_STOREITERATORIMPL_H

#include <zorba/iterator.h>
#include "common/shared_types.h"

namespace zorba {

class DiagnosticHandler;

/*******************************************************************************
  Iterator used for iterating over an internal store::Iterator_t.
********************************************************************************/
class StoreIteratorImpl : public Iterator
{
  friend class Unmarshaller;
  friend class Item;
  friend class DynamicContextImpl;
  friend class StaticContextImpl;
  friend class XQueryImpl;

protected:
  store::Iterator_t  theIterator; 
  DiagnosticHandler* theDiagnosticHandler;
  bool               theOwnDiagnosticHandler;
  bool               theIsOpen;     
  bool               theHaveLock;
    
  StoreIteratorImpl(store::Iterator_t, DiagnosticHandler*);

public:
  virtual ~StoreIteratorImpl();
    
  virtual void open();
    
  virtual bool next(Item&);
    
  virtual void close();

  bool isOpen() const { return theIsOpen; }
};
  
} /* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */

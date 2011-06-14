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
#ifndef ZORBA_SCTX_MAP_ITERATOR_H
#define ZORBA_SCTX_MAP_ITERATOR_H

#include "store/api/iterator.h"

namespace zorba 
{

class static_context;
template< typename T> class serializable_ItemPointerHashMap;

template < typename T >
class SctxMapIterator : public store::Iterator
{
private:
  const static_context                                           * theSctx;
  const static_context                                           * theCurSctx;
  serializable_ItemPointerHashMap<rchandle<T> >*                   theItems;
  typename serializable_ItemPointerHashMap<rchandle<T> >::iterator theIterator;
  bool                                                             theIsClosed;
  
  // function pointer for retrieving the map in question
  serializable_ItemPointerHashMap<rchandle<T> >* (static_context::*theMapGetter)() const;
  
public:
  SctxMapIterator(
        const static_context* aSctx,
        serializable_ItemPointerHashMap<rchandle<T> >*
        (static_context::*aMapGetter)() const);
  
  virtual ~SctxMapIterator();
  
  /**
   * get the map out of theCurSctx
   * and set theIterator to the beginning of the map
   * @return true if the map exists, false otherwise
   */
  virtual bool resetIterator();
  
  virtual void open();
  
  virtual bool next(store::Item_t& aResult);
  
  virtual void reset();
  
  virtual void close();
};

} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */

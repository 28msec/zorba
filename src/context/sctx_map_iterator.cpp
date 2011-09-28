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

#include "context/sctx_map_iterator.h"

#include "context/static_context.h"

// required for explicit template instantiation
#include "compiler/xqddf/collection_decl.h"
#include "compiler/xqddf/value_index.h"
#include "compiler/xqddf/value_ic.h"

#include "types/typeimpl.h"

#define ZORBA_UTILS_HASHMAP_WITH_SERIALIZATION
#include "zorbautils/hashmap_itemp.h"
#undef  ZORBA_UTILS_HASHMAP_WITH_SERIALIZATION

namespace zorba {

template <typename T>
SctxMapIterator<T>::SctxMapIterator(
    const static_context* aSctx,
    serializable_ItemPointerHashMap<rchandle<T> >*
    (static_context::*aMapGetter)() const)
  :
  theSctx(aSctx),
  theCurSctx(theSctx),
  theItems(0),
  theIsClosed(true),
  theMapGetter(aMapGetter)
{
}

  
template < typename T >
SctxMapIterator<T>::~SctxMapIterator()
{ 
  close();
}
  
  
template <typename T>
bool
SctxMapIterator<T>::resetIterator()
{
  while (theCurSctx) {
    theItems = (theCurSctx->*theMapGetter)();
    if (theItems) {
      theIterator = theItems->begin();
      return true;
    } else {
      theCurSctx = static_cast<const static_context*>(theCurSctx->get_parent());
    }
  }
  return false;
}
  

template <typename T>
void
SctxMapIterator<T>::open()
{
  resetIterator();
  theIsClosed = false;
}
  
  
template <typename T>
bool
SctxMapIterator<T>::next(store::Item_t& aResult)
{
  while (theCurSctx) {
    if (theIterator == theItems->end()) {
      // end in theCurSctx reached => check parent static context
      theCurSctx = static_cast<const static_context*>(theCurSctx->get_parent());
      if (theCurSctx) {
        if (resetIterator()) {
          continue;
        }
      } 
    } else {
      aResult = (*theIterator).first;
      ++theIterator;
      return true;
    }
  }
  return false;
}

  
template <typename T>
void
SctxMapIterator<T>::reset()
{
  // go back to initial sctx
  theCurSctx = theSctx; 
  resetIterator();
  theIsClosed = false;
}
  

template <typename T>
void
SctxMapIterator<T>::close()
{
  if (!theIsClosed) {
    theIsClosed = true;
  }
}


template class SctxMapIterator<StaticallyKnownCollection>;
template class SctxMapIterator<IndexDecl>;
template class SctxMapIterator<ValueIC>;
  
} /* namespace zorba */
/* vim:set et sw=2 ts=2: */

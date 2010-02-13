#include "context/sctx_map_iterator.h"

#include "context/static_context.h"

// required for explicit template instantiation
#include "context/statically_known_collection.h"
#include "compiler/indexing/value_index.h"
#include "compiler/indexing/value_ic.h"

#include "types/typeimpl.h"

#define ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP_WITH_SERIALIZATION
#include "zorbautils/hashmap_itemp.h"
#undef ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP_WITH_SERIALIZATION

namespace zorba {

  template <typename T>
  SctxMapIterator<T>::SctxMapIterator(
      const static_context* aSctx,
      ItemPointerHashMap<rchandle<T> >*
      (static_context::*aMapGetter)() const
  )
    : theSctx(aSctx),
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
    theItems = (theCurSctx->*theMapGetter)();
    if (theItems) {
      theIterator = theItems->begin();
      return true;
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
    while (theItems) {
      if (theIterator == theItems->end()) {
        // end in theCurSctx reached => check parent static context
        theCurSctx = static_cast<const static_context*>(theCurSctx->get_parent());
        if (theCurSctx) {
          if (resetIterator()) {
            continue;
          }
        } else {
          // root sctx reached => that's it
          theItems = 0;
          break;
        }
      } else {
        // more collections in theCurSctx
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
  template class SctxMapIterator<ValueIndex>;
  template class SctxMapIterator<ValueIC>;

} /* namespace zorba */

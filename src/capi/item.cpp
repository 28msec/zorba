#include "capi/item.h"

#include <cassert>
#include <zorba/zorba.h>

using namespace zorba;

namespace zorbac {

  XQUERY_ERROR
  Item::string_value(XQC_Item item, XQC_String str)
  {
    try {
      zorba::Item* lInnerItem = static_cast<zorba::Item*>(item->data);
      String* lInnerString = static_cast<String*>(str->data);

      *lInnerString = lInnerItem->getStringValue();

      return XQ_SUCCESS;
    } catch (ZorbaException &e) {
      return e.getErrorCode();
    } catch (...) {
      return XQP0019_INTERNAL_ERROR;
    }
  }

  void
  Item::free(XQC_Item item)
  {
    try {
      zorba::Item* lInnerItem = static_cast<zorba::Item*>(item->data);
      delete lInnerItem;
      delete item;
    } catch (ZorbaException &e) {
      assert(false);
    } catch (...) {
      assert(false);
    }

  }

} /* namespace zorbac */

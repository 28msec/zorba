#include "capi/item.h"

#include <cassert>
#include <zorba/zorba.h>

using namespace zorba;

#define ITEM_TRY  try {

#define ITEM_CATCH  \
      return XQ_SUCCESS; \
    } catch (ZorbaException &e) { \
      return e.getErrorCode(); \
    } catch (...) { \
      return XQP0019_INTERNAL_ERROR; \
    }

namespace zorbac {

  XQUERY_ERROR
  Item::string_value(XQC_Item item, XQC_String str)
  {
    ITEM_TRY
      zorba::Item* lInnerItem = static_cast<zorba::Item*>(item->data);
      String* lInnerString = static_cast<String*>(str->data);

      *lInnerString = lInnerItem->getStringValue();
    ITEM_CATCH
  }

  XQUERY_ERROR
  Item::prefix(XQC_Item item, XQC_String str)
  {
    ITEM_TRY
      zorba::Item* lInnerItem = static_cast<zorba::Item*>(item->data);
      String* lInnerString = static_cast<String*>(str->data);

      *lInnerString = lInnerItem->getPrefix();
    ITEM_CATCH
  }

  XQUERY_ERROR
  Item::ns(XQC_Item item, XQC_String str)
  {
    ITEM_TRY
      zorba::Item* lInnerItem = static_cast<zorba::Item*>(item->data);
      String* lInnerString = static_cast<String*>(str->data);

      *lInnerString = lInnerItem->getNamespace();
    ITEM_CATCH
  }

  XQUERY_ERROR
  Item::localname(XQC_Item item, XQC_String str)
  {
    ITEM_TRY
      zorba::Item* lInnerItem = static_cast<zorba::Item*>(item->data);
      String* lInnerString = static_cast<String*>(str->data);

      *lInnerString = lInnerItem->getLocalName();
    ITEM_CATCH
  }

  XQUERY_ERROR
  Item::boolean_value(XQC_Item item, int* res)
  {
    ITEM_TRY
      zorba::Item* lInnerItem = static_cast<zorba::Item*>(item->data);

      (*res) = lInnerItem->getBooleanValue()?1:0;
    ITEM_CATCH
  }

  XQUERY_ERROR
  Item::nan(XQC_Item item, int* res)
  {
    ITEM_TRY
      zorba::Item* lInnerItem = static_cast<zorba::Item*>(item->data);
      (*res) = lInnerItem->isNaN()?1:0;
    ITEM_CATCH
  }

  XQUERY_ERROR
  Item::pos_or_neg_inf(XQC_Item item, int* res)
  {
    ITEM_TRY
      zorba::Item* lInnerItem = static_cast<zorba::Item*>(item->data);
      (*res) = lInnerItem->isPosOrNegInf()?1:0;
    ITEM_CATCH
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

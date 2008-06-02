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
#include "capi/item.h"

#include <cassert>
#include <zorba/zorba.h>

using namespace zorba;

#define ITEM_TRY  try {

#define ITEM_CATCH  \
      return XQ_NO_ERROR; \
    } catch (ZorbaException &e) { \
      return e.getErrorCode(); \
    } catch (...) { \
      return XQP0019_INTERNAL_ERROR; \
    }

namespace zorbac {

  XQUERY_ERROR
  Item::string_value(XQC_Item item, const char** str)
  {
    ITEM_TRY
      zorbac::Item* lItem = static_cast<zorbac::Item*>(item->data);

      zorba::String lString = lItem->theItem.getStringValue();
      lItem->theStrings.push_back(lString);

      (*str) = lString.c_str();

    ITEM_CATCH
  }

  XQUERY_ERROR
  Item::prefix(XQC_Item item, const char** str)
  {
    ITEM_TRY
      zorbac::Item* lItem = static_cast<zorbac::Item*>(item->data);

      zorba::String lString = lItem->theItem.getPrefix();
      lItem->theStrings.push_back(lString);

      (*str) = lString.c_str();
    ITEM_CATCH
  }

  XQUERY_ERROR
  Item::ns(XQC_Item item, const char** str)
  {
    ITEM_TRY
      zorbac::Item* lItem = static_cast<zorbac::Item*>(item->data);

      zorba::String lString = lItem->theItem.getNamespace();
      lItem->theStrings.push_back(lString);

      (*str) = lString.c_str();
    ITEM_CATCH
  }

  XQUERY_ERROR
  Item::localname(XQC_Item item, const char** str)
  {
    ITEM_TRY
      zorbac::Item* lItem = static_cast<zorbac::Item*>(item->data);

      zorba::String lString = lItem->theItem.getLocalName();
      lItem->theStrings.push_back(lString);

      (*str) = lString.c_str();
    ITEM_CATCH
  }

  XQUERY_ERROR
  Item::boolean_value(XQC_Item item, int* res)
  {
    ITEM_TRY
      zorbac::Item* lItem = static_cast<zorbac::Item*>(item->data);

      (*res) = lItem->theItem.getBooleanValue()?1:0;
    ITEM_CATCH
  }

  XQUERY_ERROR
  Item::nan(XQC_Item item, int* res)
  {
    ITEM_TRY
      zorbac::Item* lItem = static_cast<zorbac::Item*>(item->data);
      (*res) = lItem->theItem.isNaN()?1:0;
    ITEM_CATCH
  }

  XQUERY_ERROR
  Item::pos_or_neg_inf(XQC_Item item, int* res)
  {
    ITEM_TRY
      zorbac::Item* lItem = static_cast<zorbac::Item*>(item->data);
      (*res) = lItem->theItem.isPosOrNegInf()?1:0;
    ITEM_CATCH
  }

  void
  Item::free(XQC_Item item)
  {
    try {
      zorbac::Item* lItem = static_cast<zorbac::Item*>(item->data);
      delete lItem;
      delete item;
    } catch (ZorbaException &e) {
      assert(false);
    } catch (...) {
      assert(false);
    }

  }

  void
  Item::assign_functions(XQC_Item item)
  {
    item->string_value   = Item::string_value;
    item->prefix         = Item::prefix;
    item->ns             = Item::ns;
    item->localname      = Item::localname;
    item->boolean_value  = Item::boolean_value;
    item->nan            = Item::nan;
    item->pos_or_neg_inf = Item::pos_or_neg_inf;
    item->free           = Item::free;
  }

} /* namespace zorbac */

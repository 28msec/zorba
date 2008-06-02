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
#include "capi/item_factory.h"
#include "capi/item.h"
#include <zorba/zorba.h>
#include "zorbaerrors/error_manager.h"

using namespace zorba;

#define ITEMFACTORY_TRY try {
#define ITEMFACTORY_CATCH \
    return XQ_NO_ERROR;              \
  } catch (ZorbaException &e) {     \
    return e.getErrorCode();        \
  } catch (...) {                   \
    return XQP0019_INTERNAL_ERROR;  \
  }
 
#define FF static_cast<zorba::ItemFactory*>(factory->data)

namespace zorbac {

  XQUERY_ERROR
  ItemFactory::create_string(XQC_ItemFactory factory, const char* str, XQC_Item_Ref item)
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createString(str);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
 
  XQUERY_ERROR
  ItemFactory::create_anyuri(XQC_ItemFactory factory, const char* str, XQC_Item_Ref item)
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createAnyURI(str);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
 
  XQUERY_ERROR
  ItemFactory::create_qname2(XQC_ItemFactory factory, 
                             const char* uri, 
                             const char* localname, 
                             XQC_Item_Ref item)
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createQName(uri, localname);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_qname3(XQC_ItemFactory factory,
                             const char* uri, 
                             const char* prefix, 
                             const char* localname, 
                             XQC_Item_Ref item)
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createQName(uri, prefix, localname);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }
 
  XQUERY_ERROR
  ItemFactory::create_boolean(XQC_ItemFactory factory, int boolean, XQC_Item_Ref item) 
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      lInnerItem->theItem = FF->createBoolean(boolean != 0);
      if (lInnerItem->theItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

    ITEMFACTORY_CATCH
  }

  void
  ItemFactory::free(XQC_ItemFactory factory)
  {
    delete factory;
  }

  void
  ItemFactory::assign_functions(XQC_ItemFactory factory)
  {
    factory->create_string    = zorbac::ItemFactory::create_string;
    factory->create_anyuri    = zorbac::ItemFactory::create_anyuri;
    factory->create_qname2    = zorbac::ItemFactory::create_qname2;
    factory->create_qname3    = zorbac::ItemFactory::create_qname3;
    factory->create_boolean   = zorbac::ItemFactory::create_boolean;
    factory->free             = zorbac::ItemFactory::free;
  }


} /* namespace zorbac */

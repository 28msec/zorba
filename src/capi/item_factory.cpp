#include "capi/item_factory.h"
#include "capi/item.h"
#include <zorba/zorba.h>
#include "errors/error_manager.h"

using namespace zorba;

#define ITEMFACTORY_TRY try {
#define ITEMFACTORY_CATCH \
    return XQ_SUCCESS;              \
  } catch (ZorbaException &e) {     \
    return e.getErrorCode();        \
  } catch (...) {                   \
    return XQP0019_INTERNAL_ERROR;  \
  }
 
#define FF static_cast<zorba::ItemFactory*>(factory->data)

#define ASSIGN_FUNCTIONS \
 lItem->string_value = zorbac::Item::string_value;  \
 lItem->prefix = zorbac::Item::prefix;  \
 lItem->ns = zorbac::Item::ns;  \
 lItem->localname = zorbac::Item::localname;  \
 lItem->boolean_value = zorbac::Item::boolean_value;  \
 lItem->nan = zorbac::Item::nan;  \
 lItem->pos_or_neg_inf = zorbac::Item::pos_or_neg_inf;  \
 lItem->free         = zorbac::Item::free;

namespace zorbac {

  XQUERY_ERROR
  ItemFactory::create_string(XQC_ItemFactory factory, XQC_String str, XQC_Item_Ref item)
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());

      String* lStringWrapper = static_cast<String*>(str->data);
      zorba::Item lInnerItem = FF->createString(*lStringWrapper);
      if (lInnerItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      ASSIGN_FUNCTIONS

      (*item) = lItem.release();
      (*item)->data = new zorba::Item(lInnerItem);

    ITEMFACTORY_CATCH
  }
 
  XQUERY_ERROR
  ItemFactory::create_anyuri(XQC_ItemFactory factory, XQC_String str, XQC_Item_Ref item)
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());

      String* lStringWrapper = static_cast<String*>(str->data);
      zorba::Item lInnerItem = FF->createAnyURI(*lStringWrapper);
      if (lInnerItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      ASSIGN_FUNCTIONS

      (*item) = lItem.release();
      (*item)->data = new zorba::Item(lInnerItem);

    ITEMFACTORY_CATCH
  }
 
  XQUERY_ERROR
  ItemFactory::create_qname2(XQC_ItemFactory factory, 
                             XQC_String uri, 
                             XQC_String localname, 
                             XQC_Item_Ref item)
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());

      String* lUriWrapper = static_cast<String*>(uri->data);
      String* lLocalnameWrapper = static_cast<String*>(localname->data);

      zorba::Item lInnerItem = FF->createQName(*lUriWrapper, *lLocalnameWrapper);
      if (lInnerItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      ASSIGN_FUNCTIONS

      (*item) = lItem.release();
      (*item)->data = new zorba::Item(lInnerItem);

    ITEMFACTORY_CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_qname3(XQC_ItemFactory factory,
                             XQC_String uri, 
                             XQC_String prefix, 
                             XQC_String localname, 
                             XQC_Item_Ref item)
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());

      String* lUriWrapper = static_cast<String*>(uri->data);
      String* lPrefixWrapper = static_cast<String*>(prefix->data);
      String* lLocalnameWrapper = static_cast<String*>(localname->data);

      zorba::Item lInnerItem = FF->createQName(*lUriWrapper, *lPrefixWrapper, *lLocalnameWrapper);
      if (lInnerItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      ASSIGN_FUNCTIONS

      (*item) = lItem.release();
      (*item)->data = new zorba::Item(lInnerItem);

    ITEMFACTORY_CATCH
  }
 
  XQUERY_ERROR
  ItemFactory::create_boolean(XQC_ItemFactory factory, int boolean, XQC_Item_Ref item) 
  {
    ITEMFACTORY_TRY
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      zorba::Item lInnerItem = FF->createBoolean(boolean != 0);
      if (lInnerItem.isNull()) ZORBA_ERROR(XQP0025_COULD_NOT_CREATE_ITEM);

      ASSIGN_FUNCTIONS

      (*item) = lItem.release();
      (*item)->data = new zorba::Item(lInnerItem);

    ITEMFACTORY_CATCH
  }

  void
  ItemFactory::free(XQC_ItemFactory factory)
  {
    delete factory;
  }

} /* namespace zorbac */

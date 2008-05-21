#include "capi/item_factory.h"
#include "capi/item.h"
#include <zorba/zorba.h>

using namespace zorba;

#define TRY try {
#define CATCH \
    return XQ_SUCCESS;              \
  } catch (ZorbaException &e) {     \
    return e.getErrorCode();        \
  } catch (...) {                   \
    return XQP0019_INTERNAL_ERROR;  \
  }
 
#define FF static_cast<zorba::ItemFactory*>(factory->data)

#define ASSIGN_FUNCTIONS \
 (*item)->string_value = zorbac::Item::string_value;  \
 (*item)->free         = zorbac::Item::free;
    

namespace zorbac {

  XQUERY_ERROR
  ItemFactory::create_string(XQC_ItemFactory factory, XQC_String str, XQC_Item_Ref item)
  {
    String* lStringWrapper = static_cast<String*>(str->data);
    TRY
      zorba::Item lItem = FF->createString(*lStringWrapper);
      *item = new XQC_Item_s();
      (*item)->data = new zorba::Item(lItem);

      ASSIGN_FUNCTIONS
    CATCH
  }
 
  XQUERY_ERROR
  ItemFactory::create_anyuri(XQC_ItemFactory factory, XQC_String str, XQC_Item_Ref item)
  {
    String* lStringWrapper = static_cast<String*>(str->data);
    TRY
      zorba::Item lItem = FF->createAnyURI(*lStringWrapper);
      *item = new XQC_Item_s();
      (*item)->data = new zorba::Item(lItem);

      ASSIGN_FUNCTIONS
    CATCH
  }
 
  XQUERY_ERROR
  ItemFactory::create_qname2(XQC_ItemFactory factory, 
                             XQC_String uri, 
                             XQC_String localname, 
                             XQC_Item_Ref item)
  {
    String* lUriWrapper = static_cast<String*>(uri->data);
    String* lLocalnameWrapper = static_cast<String*>(localname->data);
    TRY
      zorba::Item lItem = FF->createQName(*lUriWrapper, *lLocalnameWrapper);
      *item = new XQC_Item_s();
      (*item)->data = new zorba::Item(lItem);

      ASSIGN_FUNCTIONS
    CATCH
  }
  
  XQUERY_ERROR
  ItemFactory::create_qname3(XQC_ItemFactory factory,
                             XQC_String uri, 
                             XQC_String prefix, 
                             XQC_String localname, 
                             XQC_Item_Ref item)
  {
    String* lUriWrapper = static_cast<String*>(uri->data);
    String* lPrefixWrapper = static_cast<String*>(prefix->data);
    String* lLocalnameWrapper = static_cast<String*>(localname->data);
    TRY
      zorba::Item lItem = FF->createQName(*lUriWrapper, *lPrefixWrapper, *lLocalnameWrapper);
      *item = new XQC_Item_s();
      (*item)->data = new zorba::Item(lItem);

      ASSIGN_FUNCTIONS
    CATCH
  }
 
  XQUERY_ERROR
  ItemFactory::create_boolean(XQC_ItemFactory factory, int boolean, XQC_Item_Ref item) 
  {
  }

  void
  ItemFactory::free(XQC_ItemFactory factory)
  {
    delete factory;
  }

} /* namespace zorbac */

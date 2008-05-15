#include <zorba/zorbac.h>
#include <zorba/zorba.h>
#include <zorba/api_shared_types.h>
#include "store/api/item.h"
#include "capi/shared_wrapper.h"

using namespace zorba;

#define TRY try {
#define CATCH \
    return XQ_SUCCESS;              \
  } catch (ZorbaException &e) {     \
    return e.getErrorCode();        \
  } catch (...) {                   \
    return XQP0019_INTERNAL_ERROR;  \
  }
 
#define FF Zorba::getInstance()->getItemFactory()

XQUERY_ERROR
zorba_item_create_string(XQUERY_STRING aString, XQUERY_ITEM_REF aItem)
{
  String* lStringWrapper = static_cast<String*>(aString);
  TRY
    Item lItem = FF->createString(*lStringWrapper);
    *aItem = static_cast<XQUERY_ITEM>(new Item(lItem));
  CATCH
}

XQUERY_ERROR
zorba_item_create_anyuri(XQUERY_STRING aString, XQUERY_ITEM_REF aItem)
{
  String* lStringWrapper = static_cast<String*>(aString);
  TRY
    Item lItem = FF->createAnyURI(*lStringWrapper);
    *aItem = static_cast<XQUERY_ITEM>(new Item(lItem));
  CATCH
}

XQUERY_ERROR
zorba_item_create_qname2(XQUERY_STRING aNamespace, XQUERY_STRING aLocalname, XQUERY_ITEM_REF aItem)
{
  TRY
  CATCH
}

XQUERY_ERROR
zorba_item_create_qname3(XQUERY_STRING aNamespace, XQUERY_STRING aPrefix, 
                         XQUERY_STRING aLocalname, XQUERY_ITEM_REF aItem)
{
  TRY
  CATCH
}

XQUERY_ERROR
zorba_item_create_boolean(int aBool, XQUERY_ITEM_REF aItem)
{
  TRY
  CATCH
}

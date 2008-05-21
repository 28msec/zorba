#ifndef ZORBAC_ITEM_FACTORY_H
#define ZORBAC_ITEM_FACTORY_H

#include <zorba/zorbac.h>

namespace zorbac {

  class ItemFactory {
    public:
      static XQUERY_ERROR
      create_string(XQC_ItemFactory factory, XQC_String str, XQC_Item_Ref item); 

      static XQUERY_ERROR
      create_anyuri(XQC_ItemFactory factory, XQC_String str, XQC_Item_Ref item); 

      static XQUERY_ERROR
      create_qname2(XQC_ItemFactory factory, XQC_String uri, XQC_String localname, XQC_Item_Ref item); 
      
      static XQUERY_ERROR
      create_qname3(XQC_ItemFactory factory, 
                    XQC_String uri, XQC_String prefix,
                    XQC_String localname, XQC_Item_Ref item); 

      static XQUERY_ERROR
      create_boolean(XQC_ItemFactory factory, int boolean, XQC_Item_Ref item); 

      static void
      free(XQC_ItemFactory factory);

  }; /* class ItemFactory */

} /* namespace zorbac */

#endif


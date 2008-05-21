#ifndef ZORBAC_ITEM_H
#define ZORBAC_ITEM_H

#include <zorba/zorbac.h>

namespace zorbac {

  class Item {
    public:
      static XQUERY_ERROR
      create(XQC_Item_Ref item);

      static XQUERY_ERROR
      string_value(XQC_Item item, XQC_String);

      static XQUERY_ERROR
      prefix(XQC_Item item, XQC_String);

      static XQUERY_ERROR
      ns(XQC_Item item, XQC_String);

      static XQUERY_ERROR
      localname(XQC_Item item, XQC_String);

      static XQUERY_ERROR
      boolean_value(XQC_Item item, int*);

      static XQUERY_ERROR
      nan(XQC_Item item, int*);

      static XQUERY_ERROR
      pos_or_neg_inf(XQC_Item item, int*);

      static void
      free(XQC_Item item);

  }; /* class Item */

} /* namespace zorbac */

#endif

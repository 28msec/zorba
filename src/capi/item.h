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

      static void
      free(XQC_Item item);

  }; /* class Item */

} /* namespace zorbac */

#endif

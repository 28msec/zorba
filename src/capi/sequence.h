#ifndef ZORBAC_SEQUENCE_H
#define ZORBAC_SEQUENCE_H

#include <zorba/zorbac.h>

namespace zorbac {

  class Sequence {
    public:
      static XQUERY_ERROR
      next(XQC_Sequence sequence, XQC_Item item);

	    static XQUERY_ERROR 
      free(XQC_Sequence sequence);

  }; /* class Sequence */

} /* namespace zorbac */

#endif

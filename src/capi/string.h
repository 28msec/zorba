#ifndef ZORBAC_STRING_H
#define ZORBAC_STRING_H

#include <zorba/zorbac.h>

namespace zorbac {

  class String {
    public:
      static XQUERY_ERROR
      create(XQC_String_Ref str);

      static XQUERY_ERROR
      to_char(XQC_String str, const char** res);

      static void
      free(XQC_String str);

  }; /* class String */

} /* namespace zorbac */

#endif


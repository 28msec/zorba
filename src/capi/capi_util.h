#ifndef ZORBAC_CAPI_UTIL_H
#define ZORBAC_CAPI_UTIL_H

#include <iostream>

namespace zorbac {

  class CAPIUtil {
    public:

      static void 
      getIStream(FILE* input, std::iostream& aStream) throw()
      {
        char lBuf[1024];
        size_t lSize;

        // TODO error checking
        while ((lSize = fread(lBuf, 1, 1024, input)) > 0) {
            aStream.write(lBuf, lSize);
        }
      }

  }; /* class CAPIUtil */

} /* namespace zorbac */
#endif

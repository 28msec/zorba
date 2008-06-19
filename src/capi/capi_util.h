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

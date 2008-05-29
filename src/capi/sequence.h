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
#ifndef ZORBAC_SEQUENCE_H
#define ZORBAC_SEQUENCE_H

#include <zorba/zorbac.h>

namespace zorbac {

  class Sequence {
    public:
      static XQUERY_ERROR
      next(XQC_Sequence sequence, XQC_Item item);

      static XQUERY_ERROR
      reset(XQC_Sequence sequence);

      static void
      free(XQC_Sequence sequence);

      static void
      assign_functions(XQC_Sequence sequence);

  }; /* class Sequence */

} /* namespace zorbac */

#endif

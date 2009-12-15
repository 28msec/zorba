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
#include <zorba/result_iterator.h>
#include <zorba/item.h>

namespace zorbac {

  class Sequence {
    public:
      static XQC_Error
      next(XQC_Sequence* sequence);

      static XQC_Error
      item_type(const XQC_Sequence* sequence, XQC_ItemType* type);

      static XQC_Error
      string_value(const XQC_Sequence* sequence, const char** string_value);

      static XQC_Error
      integer_value(const XQC_Sequence* sequence, int* int_value);

      static XQC_Error
      double_value(const XQC_Sequence* sequence, double* double_value);

      static XQC_Error
      node_name(const XQC_Sequence* sequence, const char** uri,
      const char** name);

      static void
      free(XQC_Sequence* sequence);

      static void
      assign_functions(XQC_Sequence* sequence);

      // buffer to store strings that we return
      // they are valid until next() is called
      std::vector<zorba::String> theStrings;
      zorba::Item             theItem;
      zorba::ResultIterator_t theSequence;
      zorba::ItemSequence*    theItemSequence;
      XQC_ErrorHandler*       theErrorHandler;
  }; /* class Sequence */

} /* namespace zorbac */

#endif

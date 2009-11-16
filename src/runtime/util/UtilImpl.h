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

#ifndef ZORBA_UTIL_IMPL_H
#define ZORBA_UTIL_IMPL_H

#include "runtime/base/narybase.h"

namespace zorba {

  NARY_ITER (ZorbaBase64DecodeIterator);
  NARY_ITER (ZorbaBase64EncodeIterator);

  NARY_ITER(XQDocIterator);

#ifdef ZORBA_WITH_TIDY
  NARY_ITER(ZorbaTidyIterator);
  NARY_ITER(ZorbaTDocIterator);
#endif  /* ZORBA_WITH_TIDY */

  NARY_ITER (ZorbaTimestampIterator);

}/*namespace zorba*/

#endif /* ZORBA_UTIL_IMPL_H */

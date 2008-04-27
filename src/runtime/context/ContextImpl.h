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
#ifndef ZORBA_CONTEXT_IMPL_H
#define ZORBA_CONTEXT_IMPL_H

#include "common/shared_types.h"
#include "runtime/base/narybase.h"

namespace zorba
{

/*______________________________________________________________________
 *
 * 16 Context Functions
 *_______________________________________________________________________*/

 /*
  * 16.3 fn:current-dateTime
  *-----------------------*/
  NARY_ITER(FnCurrentDateTimeIterator);

 /*
  * 16.4 fn:current-date
  *-----------------------*/
  NARY_ITER(FnCurrentDateIterator);

 /*
  * 16.5 fn:current-time
  *-----------------------*/
  NARY_ITER(FnCurrentTimeIterator);

 /*
  * 16.6 fn:implicit-timezone
  *-----------------------*/
  NARY_ITER(FnImplicitTimezoneIterator);

 /*
  * 16.7 fn:default-collation
  *-----------------------*/
  NARY_ITER(FnDefaultCollationIterator);

} /* namespace zorba */
#endif /*ZORBA_CONTEXT_IMPL_H*/

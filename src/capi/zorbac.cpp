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

#include <zorba/zorba.h>
#include <zorba/zorbac.h> 

#include "capi/implementation.h"

XQUERY_ERROR
zorba_implementation(XQC_Implementation_Ref impl)
{
  try {
    std::auto_ptr<XQC_Implementation_s> lImpl(new XQC_Implementation_s());

    zorba::Zorba* lZorba = zorba::Zorba::getInstance();

    zorbac::Implementation::assign_functions(lImpl.get());

    (*impl) = lImpl.release();
    (*impl)->data =  lZorba;
    return XQ_NO_ERROR;
  } catch (zorba::ZorbaException &e) {
    return e.getErrorCode();
  } catch (...) {
    return XQP0019_INTERNAL_ERROR;
  }
}


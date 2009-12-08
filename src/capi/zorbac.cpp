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
#include "capi/error.h"

#include "store/api/store.h"


XQC_Error
zorba_implementation(XQC_Implementation** impl, void* store)
{
  try {
    std::auto_ptr<XQC_Implementation_s> lImpl(new XQC_Implementation_s());

    zorba::Zorba* lZorba = 
      zorba::Zorba::getInstance(static_cast<zorba::store::Store*>(store));

    zorbac::Implementation::assign_functions(lImpl.get());

    (*impl) = lImpl.release();
    (*impl)->data =  lZorba;
    return XQC_NO_ERROR;
  } catch (zorba::ZorbaException &e) {
    return zorbac::Error::convert_xquery_error(e.getErrorCode());
  } catch (...) {
    return XQC_INTERNAL_ERROR;
  }
}


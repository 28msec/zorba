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
#include "stdafx.h"

#include <zorba/zorba.h>
#include <zorba/zorbac.h> 

#include "capi/cimplementation.h"
#include "capi/error.h"

#include "store/api/store.h"

using namespace zorbac;

XQC_Error
zorba_implementation(XQC_Implementation** impl, void* store)
{
  try {
    Zorba* lZorba =
      Zorba::getInstance(static_cast<zorba::store::Store*>(store));

    std::auto_ptr<CImplementation> lImpl(new CImplementation(lZorba));

    // Don't call anything that might throw an exception after this point
    (*impl) = lImpl.release()->getXQC();
    return XQC_NO_ERROR;
  } catch (ZorbaException const &e) {
    return zorbac::Error::convert_xquery_error(e.diagnostic());
  } catch (...) {
    return XQC_INTERNAL_ERROR;
  }
}

/* vim:set et sw=2 ts=2: */

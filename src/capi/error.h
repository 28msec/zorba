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
#pragma once
#ifndef ZORBAC_ERROR_CAPI_H
#define ZORBAC_ERROR_CAPI_H

#include <xqc.h>
#include <zorba/zorbac.h>
#include <zorba/xquery_exception.h>

#if defined(_MSC_VER)
#include <BaseTsd.h>
#define ssize_t SSIZE_T
#endif

/**
 * Useful #defines for most C API methods. Provides a consistent
 * quasi-OO approach by declaring "me" to be the C API class instance
 * associated with an XQC variable. Catches QueryExceptions and passes
 * them to the appropriate handler, and otherwise handles returning
 * consistent return codes.
 */

// Can be further customized per-class
#define CAPI_TRY(class,xqc)                        \
  class* me = class::get(xqc);                     \
  try

#define CAPI_CATCH                                                      \
  catch (XQueryException const &qe) {                                   \
    return Error::handle_and_convert_queryexception(me->theErrorHandler, qe); \
  }                                                                     \
  catch (ZorbaException const &e) {                                     \
    return Error::convert_xquery_error(e.diagnostic());                 \
  } catch (...) {                                                       \
    return XQC_INTERNAL_ERROR;                                          \
  }                                                                     \
  return XQC_NO_ERROR;

#define CLASS_OFFSET(class, impl) (((ssize_t)&(((class*)1000)->impl)) - 1000)

namespace zorbac {

class Error {
public:
  static XQC_Error convert_xquery_error(zorba::Error const& error);

  static XQC_Error handle_and_convert_queryexception
  (XQC_ErrorHandler* handler, zorba::XQueryException const &qe);
};

} /* namespace zorbac */
#endif
/* vim:set et sw=2 ts=2: */

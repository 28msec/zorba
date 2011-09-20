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

#include <zorba/diagnostic_list.h>

#include "capi/error.h"

using namespace zorba;

namespace zorbac {

XQC_Error Error::convert_xquery_error( zorba::Error const &error ) {
  using namespace zorba::diagnostic;
  using namespace zorba::err;
  using namespace zorba::zerr;

  if ( error == ZXQP0000_NO_ERROR )
    return XQC_NO_ERROR;

  ////////// Special-cases ////////////////////////////////////////////////////

  if ( error == FOCA0001 // Input value too large for decimal
    || error == FOCA0002 // Invalid lexical value
    || error == FOCA0003 // Input value too large for integer.
    || error == FOCA0005 // NaN supplied as float/double value.
    || error == FOCA0006 // ... too many digits of precision.
    || error == FOCH0001 // Code-point not valid.
    || error == FOCH0002 // Unsupported collation.
    || error == FOCH0003 // Unsupported normalization form.
    || error == FOCH0004 // Collation does not support collation units.
    || error == FODC0004 // Invalid argument to fn:collection.
    || error == FODC0005 // Invalid argument to fn:doc or fn:doc-available.
    || error == FODT0003 // Invalid timezone value.
    || error == FONS0004 // No namespace found for prefix.
    || error == FONS0005 // Base-uri not defined in the static context.
    || error == FORG0001 // Invalid value for cast/constructor.
    || error == FORG0002 // Invalid argument to fn:resolve-uri().
    || error == FORG0003 // fn:zero-or-one called ... > 1 item.
    || error == FORG0004 // fn:one-or-more called ... 0 items.
    || error == FORG0005 // fn:exactly-one called ... 0 or > 1 item.
    || error == FORG0006 // Invalid argument type.
    || error == FORG0008 // Both arguments to fn:dateTime have a timezone.
    || error == FORG0009 // Error in resolving a relative URI ....
    || error == FORX0001 // Invalid regular expression flags.
    || error == FORX0002 // Invalid regular expression.
    || error == FORX0003 // Regular expression matches zero-length string.
    || error == FORX0004 // Invalid replacement string.
    || error == FOTY0012 // Argument node does not have a typed value.
  )
    return XQC_INVALID_ARGUMENT;

  if ( error == FODC0001 /* No context document. */ )
    return XQC_NO_CURRENT_ITEM;

  if ( error == FODC0003 /* Function stability not defined. */ )
    return XQC_INTERNAL_ERROR;

  /////////////////////////////////////////////////////////////////////////////

  switch ( error.category() ) {

    case XQUERY_SERIALIZATION:
      return XQC_SERIALIZATION_ERROR;

    case ZORBA_API:
      if ( error == ZAPI0002_XQUERY_COMPILATION_FAILED )
        return XQC_STATIC_ERROR;
      return XQC_INVALID_ARGUMENT;

    case ZORBA_SERIALIZATION:
      return XQC_INTERNAL_ERROR;

    case ZORBA_DDF:
    case ZORBA_STORE:
      return XQC_INVALID_ARGUMENT;

    case ZORBA_OS:
      return XQC_DYNAMIC_ERROR;

    default:                            // suppresses warning
      break;
  }

  switch ( error.kind() ) {
    case XQUERY_DYNAMIC: return XQC_DYNAMIC_ERROR;
    case XQUERY_STATIC : return XQC_STATIC_ERROR;
    case XQUERY_TYPE   : return XQC_TYPE_ERROR;
    default            : break;         // suppresses warning
  }

  ////////// Zorba errors /////////////////////////////////////////////////////

  if ( error == ZXQP0001_DYNAMIC_RUNTIME_ERROR
    || error == ZXQP0002_ASSERT_FAILED
    || error == ZXQP0003_INTERNAL_ERROR
    || error == ZXQP0004_NOT_IMPLEMENTED
    || error == ZXQP0005_NOT_ENABLED
    || error == ZXQP0007_FUNCTION_SIGNATURE_NOT_EQUAL
    || error == ZXQP0008_FUNCTION_IMPL_NOT_FOUND
    || error == ZXQP0009_FUNCTION_LOCALNAME_MISMATCH
    || error == ZXQP0013_FXCHARHEAP_EXCEPTION
    || error == ZXQP0020_INVALID_URI
    || error == ZXQP0021_USER_ERROR
    || error == ZXQP0025_ITEM_CREATION_FAILED
    || error == ZXQP0028_TARGET_NAMESPACE_NOT_PROVIDED
    || error == ZXQP0029_URI_ACCESS_DENIED
    || error == ZXQP0030_DEADLOCK
    || error == ZXQP0036_BREAKITERATOR_CREATION_FAILED
    || error == ZXQP0037_INAPPROPRIATE_MODULE_VERSION
  )
    return XQC_INTERNAL_ERROR;

  if ( error == ZXQP0017_FILE_ACCESS_DISABLED
    || error == ZXQP0024_XML_DOES_NOT_MATCH_SCHEMA
  )
    return XQC_DYNAMIC_ERROR;

  if ( error == ZXQP0031_MALFORMED_XQUERYX_INPUT
    || error == ZXQP0032_ERROR_TRANSFORMING_XQUERYX_TO_XQUERY
#ifndef ZORBA_NO_FULL_TEXT
    || error == ZXQP8401_THESAURUS_VERSION_MISMATCH
    || error == ZXQP8402_THESAURUS_ENDIANNESS_MISMATCH
    || error == ZXQP8403_THESAURUS_DATA_ERROR
#endif /* ZORBA_NO_FULL_TEXT */
  )
    return XQC_INVALID_ARGUMENT;

  return static_cast<XQC_Error>( -1 );
} // Error::convert_xquery_error()

XQC_Error Error::handle_and_convert_queryexception( XQC_ErrorHandler *handler,
                                                    XQueryException const &xe ) {
  XQC_Error const xqc_error = Error::convert_xquery_error( xe.diagnostic() );
  if ( handler ) {
    diagnostic::QName const &qname = xe.diagnostic().qname();
    handler->error(
      handler,
      xqc_error,
      qname.ns(),
      qname.localname(),
      xe.what(),
      NULL // TODO: no support for passing argument to fn:error()
    );
  }
  return xqc_error;
}

} // namespace zorbac
/* vim:set et sw=2 ts=2: */

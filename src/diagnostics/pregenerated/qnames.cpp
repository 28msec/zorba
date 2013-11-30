/**
 * Copyright 2006-2013 The FLWOR Foundation.
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
 
 /*
  * THIS FILE IS GENERATED.
  * PLEASE DO NOT EDIT.
  */


#include <zorba/diagnostic.h>
#include "zorbamisc/ns_consts.h"

namespace zorba {

extern diagnostic::kind get_standard_error_kind( char const* );

namespace internal {

char const XQueryErrorQName::NAMESPACE[] = XQUERY_ERR_NS;
char const XQueryErrorQName::PREFIX[] = "err";


char const JSONiqErrorQName::NAMESPACE[] = JSONIQ_ERR_NS;
char const JSONiqErrorQName::PREFIX[] = "jerr";

zorba::diagnostic::kind JSONiqErrorQName::kind() const {
  return get_standard_error_kind( localname() );
}

char const JSoundErrorQName::NAMESPACE[] = JSOUND_SCHEMA_NS;
char const JSoundErrorQName::PREFIX[] = "jsd";

zorba::diagnostic::kind JSoundErrorQName::kind() const {
  return zorba::diagnostic::UNKNOWN_KIND;
}

char const ZorbaErrorQName::NAMESPACE[] = ZORBA_ERR_NS;
char const ZorbaErrorQName::PREFIX[] = "zerr";

zorba::diagnostic::kind ZorbaErrorQName::kind() const {
  return zorba::diagnostic::UNKNOWN_KIND;
}

char const ZorbaWarningQName::NAMESPACE[] = ZORBA_WARN_NS;
char const ZorbaWarningQName::PREFIX[] = "zwarn";

zorba::diagnostic::kind ZorbaWarningQName::kind() const {
  return get_standard_error_kind( localname() );
}

char const ZorbaCSVErrorQName::NAMESPACE[] = "http://zorba.io/modules/json-csv";
char const ZorbaCSVErrorQName::PREFIX[] = "csv";

zorba::diagnostic::kind ZorbaCSVErrorQName::kind() const {
  return zorba::diagnostic::UNKNOWN_KIND;
}

char const ZorbaDateTimeErrorQName::NAMESPACE[] = "http://zorba.io/modules/datetime";
char const ZorbaDateTimeErrorQName::PREFIX[] = "dt";

zorba::diagnostic::kind ZorbaDateTimeErrorQName::kind() const {
  return zorba::diagnostic::UNKNOWN_KIND;
}

char const ZorbaURIErrorQName::NAMESPACE[] = "http://zorba.io/modules/uri";
char const ZorbaURIErrorQName::PREFIX[] = "zuri";

zorba::diagnostic::kind ZorbaURIErrorQName::kind() const {
  return zorba::diagnostic::UNKNOWN_KIND;
}

} // namespace internal
} // namespace zorba
/*
 * Local variables:
 * mode: c++
 * End:
 */ 

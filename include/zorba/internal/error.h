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

#ifndef ZORBA_INTERNAL_ERROR_H
#define ZORBA_INTERNAL_ERROR_H

#include <zorba/error.h>

namespace zorba {
namespace internal {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %SystemError is-an Error for built-in errors.
 *
 * @tparam QNameType The QName type.
 */
template<class QNameType>
class ZORBA_DLL_PUBLIC SystemError : public Error {
public:

  /**
   * Constructs a %SystemError.
   *
   * @param localname The local-name of the error.
   */
  SystemError( char const *localname ) : qname_( localname ) {
  }

  // inherited
  zorba::err::QName const& qname() const { return qname_; }
  zorba::err::type type() const { return qname_.error_type(); }

protected:
  // inherited
  Error const* clone() const { return this; }
  void destroy() const { /* do nothing */ }

private:
  QNameType qname_;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace internal
} // namespace zorba
#endif /* ZORBA_INTERNAL_ERROR_H */
/* vim:set et sw=2 ts=2: */

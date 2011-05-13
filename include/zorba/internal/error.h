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

#include <map>

#include <zorba/error.h>

#include "ztd.h"

namespace zorba {
namespace internal {

///////////////////////////////////////////////////////////////////////////////

class ZORBA_DLL_PUBLIC SystemErrorBase : public Error {
public:
  /**
   * Given an error's local-name, finds its corresponding %Error object.
   *
   * @param localname The local-name.
   * @return Returns the corresponding %Error object or \c NULL if not found.
   */
  static Error const* find( char const *localname ) {
    map_type const &m = get_map();
    map_type::const_iterator const i = m.find( localname );
    return i != m.end() ? i->second : 0;
  }

private:
  typedef std::map<char const*,Error const*,ztd::less<char const*> > map_type;
  static map_type& get_map();

  SystemErrorBase( char const *localname ) {
    get_map()[ localname ] = this;
  }

  // Only a SystemError can derive from SystemErrorBase.
  template<class QNameType> friend class SystemError;
};

/**
 * \internal
 * A %SystemError is-an Error for built-in errors.
 *
 * @tparam QNameType The QName type.
 */
template<class QNameType>
class ZORBA_DLL_PUBLIC SystemError : public SystemErrorBase {
public:

  /**
   * Constructs a %SystemError.
   *
   * @param localname The local-name of the error.
   */
  SystemError( char const *localname ) :
    SystemErrorBase( localname ), qname_( localname )
  {
  }

  // inherited
  zorba::err::category category() const { return qname_.error_category(); }
  zorba::err::kind kind() const { return qname_.error_kind(); }
  zorba::err::QName const& qname() const { return qname_; }

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

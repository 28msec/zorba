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

#ifndef ZORBA_INTERNAL_QNAME_H
#define ZORBA_INTERNAL_QNAME_H

// standard
#include <cstring>

// Zorba
#include <zorba/config.h>
#include <zorba/diagnostic.h>

// local
#include "ztd.h"

namespace zorba {

namespace internal {
  template<typename StringType>
  class ZORBA_DLL_PUBLIC VariableQName;
}
namespace serialization {
  class Archiver;
  template<typename StringType>
  void operator&( serialization::Archiver&,
                  internal::VariableQName<StringType>& );
}

namespace internal {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %FixedQName is-an diagnostic::QName that has a fixed namespace and prefix,
 * but a variable local-name.
 *
 * @tparam QNameTraits A class that contains static \c NAMESPACE and \c PREFIX
 * members.
 * @tparam LocalnameType The type to use to store the local-name.  Note that
 * this can be either a string type or <code>char const*</code>.  If the
 * latter, then it must be guaranteed that the pointed-to C strings will exist
 * for the entire lifetime of this object.
 */
template<class QNameTraits,typename LocalnameType>
class ZORBA_DLL_PUBLIC FixedQName : public zorba::diagnostic::QName {
public:

  /**
   * Constructs a %FixedQName.
   *
   * @param localname The QName's local-name.
   */
  FixedQName( char const *localname ) :
    localname_( strip_prefix( localname ) )
  {
  }

  // inherited
  char const* ns() const { return ztd::c_str( QNameTraits::NAMESPACE ); }
  char const* prefix() const { return ztd::c_str( QNameTraits::PREFIX ); }
  char const* localname() const { return ztd::c_str( localname_ ); }

private:
  LocalnameType localname_;

  static char const* strip_prefix( char const *localname ) {
    char const *const colon = strchr( localname, ':' );
    return colon ? colon + 1 : localname;
  }

  template<typename StringType> static
  typename std::enable_if<ZORBA_HAS_C_STR(StringType),char const*>::type
  strip_prefix( StringType const &localname ) {
    return strip_prefix( localname.c_str() );
  }
};

/**
 * A %VariableQName is-an diagnostic::QName that has a variable namespace,
 * prefix, and local-name.
 *
 * @tparam StringType The type to use to store the namespace, prefix, and
 * local-name.  Note that this can be either a string type or <code>char
 * const*</code>.  If the latter, then it must be guaranteed that the
 * pointed-to C strings will exist for the entire lifetime of this object.
 */
template<typename StringType>
class ZORBA_DLL_PUBLIC VariableQName : public zorba::diagnostic::QName {
public:

  /**
   * Constructs a %VariableQName.
   */
  VariableQName( char const *ns, char const *prefix, char const *localname ) :
    ns_( ns ), prefix_( prefix ), localname_( localname )
  {
  }

  // inherited
  char const* ns() const { return ztd::c_str( ns_ ); }
  char const* prefix() const { return ztd::c_str( prefix_ ); }
  char const* localname() const { return ztd::c_str( localname_ ); }

private:
  StringType ns_;
  StringType prefix_;
  StringType localname_;

  // for plan serialization
public:
  VariableQName( serialization::Archiver& ) { }
private:
  friend void serialization::operator&<typename StringType>( serialization::Archiver&,
                                          VariableQName& );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace internal
} // namespace zorba

#include <zorba/internal/qnames.h>

#endif /* ZORBA_INTERNAL_QNAME_H */
/* vim:set et sw=2 ts=2: */

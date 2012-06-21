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

#include <zorba/config.h>
#include <zorba/diagnostic.h>

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
  FixedQName( char const *localname ) : localname_( localname ) {
  }

  // inherited
  char const* ns() const { return ztd::c_str( QNameTraits::NAMESPACE ); }
  char const* prefix() const { return ztd::c_str( QNameTraits::PREFIX ); }
  char const* localname() const { return ztd::c_str( localname_ ); }

private:
  LocalnameType localname_;
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
  friend void serialization::operator&<>( serialization::Archiver&,
                                          VariableQName& );
};

///////////////////////////////////////////////////////////////////////////////

/**
 * A %ZorbaErrQName is-a FixedQName for Zorba errors.
 */
class ZORBA_DLL_PUBLIC ZorbaErrQName :
  public FixedQName<ZorbaErrQName,char const*>
{
  typedef FixedQName<ZorbaErrQName,char const*> base_type;
public:
  static char const NAMESPACE[];
  static char const PREFIX[];

  /**
   * Constructs a %ZorbaErrQName.
   *
   * @param localname The local-name of the error.
   */
  ZorbaErrQName( char const *localname ) : base_type( localname ) { }

  /**
   * Gets the category of error this QName represents.
   *
   * @return Returns said kind.
   */
  zorba::diagnostic::category category() const;

  /**
   * Gets the kind of error this QName represents.
   *
   * @return Returns said kind.
   */
  zorba::diagnostic::kind kind() const;
};

///////////////////////////////////////////////////////////////////////////////

/**
 * An %XQueryErrQName is-a FixedQName for standard XQuery errors.
 */
class ZORBA_DLL_PUBLIC XQueryErrQName :
  public FixedQName<XQueryErrQName,char const*>
{
  typedef FixedQName<XQueryErrQName,char const*> base_type;
public:
  static char const NAMESPACE[];
  static char const PREFIX[];

  /**
   * Constructs an %XQueryErrQName.
   *
   * @param localname The local-name of the error.
   */
  XQueryErrQName( char const *localname ) : base_type( localname ) { }

  /**
   * Gets the category of error this QName represents.
   *
   * @return Returns said kind.
   */
  zorba::diagnostic::category category() const;

  /**
   * Gets the kind of error this QName represents.
   *
   * @return Returns said kind.
   */
  zorba::diagnostic::kind kind() const;
};

///////////////////////////////////////////////////////////////////////////////

#ifdef ZORBA_WITH_JSON

/**
 * An %JSONiqErrQName is-a FixedQName for standard JSONiq errors.
 */
class ZORBA_DLL_PUBLIC JSONiqErrQName :
  public FixedQName<JSONiqErrQName,char const*>
{
  typedef FixedQName<JSONiqErrQName,char const*> base_type;
public:
  static char const NAMESPACE[];
  static char const PREFIX[];

  /**
   * Constructs an %JSONiqErrQName.
   *
   * @param localname The local-name of the error.
   */
  JSONiqErrQName( char const *localname ) : base_type( localname ) { }

  /**
   * Gets the category of error this QName represents.
   *
   * @return Returns UNKNOWN_CATEGORY as there currently
   *         are no categories for JSONiq errors
   */
  zorba::diagnostic::category category() const;

  /**
   * Gets the kind of error this QName represents.
   *
   * @return Returns said kind.
   */
  zorba::diagnostic::kind kind() const;
};

#endif

///////////////////////////////////////////////////////////////////////////////

/**
 * An %ZorbaWarningQName is-a FixedQName for Zorba warnings.
 */
class ZORBA_DLL_PUBLIC ZorbaWarningQName :
  public FixedQName<ZorbaWarningQName,char const*>
{
  typedef FixedQName<ZorbaWarningQName,char const*> base_type;
public:
  static char const NAMESPACE[];
  static char const PREFIX[];

  /**
   * Constructs a %ZorbaWarningQName.
   *
   * @param localname The local-name of the warning.
   */
  ZorbaWarningQName( char const *localname ) : base_type( localname ) { }

  /**
   * Gets the category of warning this QName represents.
   *
   * @return Returns said kind.
   */
  zorba::diagnostic::category category() const;

  /**
   * Gets the kind of warning this QName represents.
   *
   * @return Returns said kind.
   */
  zorba::diagnostic::kind kind() const;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace internal
} // namespace zorba
#endif /* ZORBA_INTERNAL_QNAME_H */
/* vim:set et sw=2 ts=2: */

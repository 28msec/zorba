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

#ifndef ZORBA_ERR_API_H
#define ZORBA_ERR_API_H

#include <cstring>
#include <iostream>

#include <zorba/config.h>

namespace zorba {
namespace err {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %QName is the abstract base class for a QName.
 */
class ZORBA_DLL_PUBLIC QName {
public:
  virtual ~QName();

  /**
   * Gets this QName's namespace URI.
   *
   * @return Returns said URI.
   */
  virtual char const* ns() const = 0;

  /**
   * Gets this QName's prefix.
   *
   * @return Returns said prefix.
   */
  virtual char const* prefix() const = 0;

  /**
   * Gets this QName's local name.
   *
   * @return Returns said local name.
   */
  virtual char const* localname() const = 0;
};

/**
 * Emits a QName to an ostream.
 *
 * @param o The ostream to emit to.
 * @param qn The QName to emit.
 * @return Returns \a o.
 */
ZORBA_DLL_PUBLIC
std::ostream& operator<<( std::ostream &o, QName const &qn );

/**
 * Compares two QNames for equality.
 *
 * @param q1 The first QName.
 * @param q2 The second QName.
 * @return Returns \c true only if the QNames' namespaces and local names are
 * equal.
 */
ZORBA_DLL_PUBLIC
bool operator==( QName const &q1, QName const &q2 );

/**
 * Compares two QNames for equality.
 *
 * @param q1 The first QName.
 * @param q2 The second QName.  It can be in Clark notation,
 * <code>{</code><em>namespace</em><code>}</code><em>local-name</em>, in which
 * case the namespaces and local-names are compared; or as
 * <em>prefix</em><code>:</code><em>local-name</em> in which case the prefixes
 * and local-names are compared.
 * @return Returns \c true only if the QNames are equal.
 */
ZORBA_DLL_PUBLIC
bool operator==( QName const &q1, char const *q2 );

/**
 * Compares two QNames for equality.
 *
 * @param q1 The first QName.  It can be in Clark notation,
 * <code>{</code><em>namespace</em><code>}</code><em>local-name</em>, in which
 * case the namespaces and local-names are compared; or as
 * <em>prefix</em><code>:</code><em>local-name</em> in which case the prefixes
 * and local-names are compared.
 * @param q2 The second QName.
 * @return Returns \c true only if the QNames are equal.
 */
inline bool operator==( char const *q1, QName const &q2 ) {
  return q2 == q1;
}

/**
 * Compares two QNames for equality.
 *
 * @tparam StringType The string type of \a q2.
 * @param q1 The first QName.
 * @param q2 The second QName.  It can be in Clark notation,
 * <code>{</code><em>namespace</em><code>}</code><em>local-name</em>, in which
 * case the namespaces and local-names are compared; or as
 * <em>prefix</em><code>:</code><em>local-name</em> in which case the prefixes
 * and local-names are compared.
 * @return Returns \c true only if the QNames are equal.
 */
template<class StringType> inline
bool operator==( QName const &q1, StringType const &q2 ) {
  return q1 == q2.c_str();
}

/**
 * Compares two QNames for equality.
 *
 * @tparam StringType The string type of \a q1.
 * @param q1 The first QName.  It can be in Clark notation,
 * <code>{</code><em>namespace</em><code>}</code><em>local-name</em>, in which
 * case the namespaces and local-names are compared; or as
 * <em>prefix</em><code>:</code><em>local-name</em> in which case the prefixes
 * and local-names are compared.
 * @param q2 The second QName.
 * @return Returns \c true only if the QNames are equal.
 */
template<class StringType> inline
bool operator==( StringType const &q1, QName const &q2 ) {
  return q1.c_str() == q2;
}

/**
 * Compares two QNames for inequality.
 *
 * @param q1 The first QName.
 * @param q2 The second QName.
 * @return Returns \c true only if either the QNames' namespaces or local names
 * are not equal.
 */
inline bool operator!=( QName const &q1, QName const &q2 ) {
  return !(q1 == q2);
}

/**
 * Compares two QNames for inequality.
 *
 * @param q1 The first QName.
 * @param q2 The second QName.  It can be in Clark notation,
 * <code>{</code><em>namespace</em><code>}</code><em>local-name</em>, in which
 * case the namespaces and local-names are compared; or as
 * <em>prefix</em><code>:</code><em>local-name</em> in which case the prefixes
 * and local-names are compared.
 * @return Returns \c true only if either the QNames' namespaces or local names
 * are not equal.
 */
inline bool operator!=( QName const &q1, char const *q2 ) {
  return !(q1 == q2);
}

/**
 * Compares two QNames for inequality.
 *
 * @param q1 The first QName.  It can be in Clark notation,
 * <code>{</code><em>namespace</em><code>}</code><em>local-name</em>, in which
 * case the namespaces and local-names are compared; or as
 * <em>prefix</em><code>:</code><em>local-name</em> in which case the prefixes
 * and local-names are compared.
 * @param q2 The second QName.
 * @return Returns \c true only if either the QNames' namespaces or local names
 * are not equal.
 */
inline bool operator!=( char const *q1, QName const &q2 ) {
  return !(q1 == q2);
}

/**
 * Compares two QNames for inequality.
 *
 * @tparam StringType The string type of \a q2.
 * @param q1 The first QName.
 * @param q2 The second QName.  It can be in Clark notation,
 * <code>{</code><em>namespace</em><code>}</code><em>local-name</em>, in which
 * case the namespaces and local-names are compared; or as
 * <em>prefix</em><code>:</code><em>local-name</em> in which case the prefixes
 * and local-names are compared.
 * @return Returns \c true only if the QNames are not equal.
 */
template<class StringType> inline
bool operator!=( QName const &q1, StringType const &q2 ) {
  return q1 != q2.c_str();
}

/**
 * Compares two QNames for inequality.
 *
 * @tparam StringType The string type of \a q1.
 * @param q1 The first QName.  It can be in Clark notation,
 * <code>{</code><em>namespace</em><code>}</code><em>local-name</em>, in which
 * case the namespaces and local-names are compared; or as
 * <em>prefix</em><code>:</code><em>local-name</em> in which case the prefixes
 * and local-names are compared.
 * @param q2 The second QName.
 * @return Returns \c true only if the QNames are not equal.
 */
template<class StringType> inline
bool operator!=( StringType const &q1, QName const &q2 ) {
  return q1.c_str() != q2;
}

///////////////////////////////////////////////////////////////////////////////

/**
 * An err::type is the type of error.
 */
enum type {
  UNKNOWN,                              // must have integer value of 0

  XQUERY_DYNAMIC,
  XQUERY_SERIALIZATION,
  XQUERY_STATIC,
  XQUERY_TYPE,
  XQUERY_USER_DEFINED,                  // for fn:error()

  ZORBA_XQP,                            // Zorba XQuery Processor
  ZORBA_API,                            // Zorba API
  ZORBA_DDF,                            // Data Definition Facility
  ZORBA_SERIALIZATION,
  ZORBA_STORE
};

/**
 * Emits the given err::type to the given ostream.
 *
 * @param o The ostream to emit to.
 * @param t The type to emit.
 * @return Returns \a o.
 */
ZORBA_DLL_PUBLIC
std::ostream& operator<<( std::ostream &o, type t );

///////////////////////////////////////////////////////////////////////////////

/**
 * Creates an error location.
 * Example:
 * \code
 * throw XQUERY_EXCEPTION( XPST0001, ERROR_LOC( file, line, col ) );
 * \endcode
 * \hideinitializer
 */
#define ERROR_LOC ::zorba::internal::err::make_location

/**
 * Creates a set of error parameters.
 * Example:
 * \code
 * throw XQUERY_EXCEPTION( XPST0001, ERROR_PARAMS( param1, param2, ... ) );
 * \endcode
 * \hideinitializer
 */
#define ERROR_PARAMS ::zorba::internal::err::make_parameters

///////////////////////////////////////////////////////////////////////////////

} // namespace err
} // namespace zorba

#include <zorba/internal/err.h>
#include <zorba/internal/qname.h>

#endif /* ZORBA_ERR_API_H */
/* vim:set et sw=2 ts=2: */

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

#ifndef ZORBA_DIAGNOSTIC_API_H
#define ZORBA_DIAGNOSTIC_API_H

#include <cstring>
#include <iostream>

#include <zorba/config.h>

namespace zorba {
namespace diagnostic {

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
 * An diagnostic::category is the category of error.
 */
enum category {
  UNKNOWN_CATEGORY,                     // must have integer value of 0

  XQUERY_CORE,
  XQUERY_FULL_TEXT,
  XQUERY_SCRIPTING,
  XQUERY_SERIALIZATION,
  XQUERY_UPDATE,
  XQUERY_USER_DEFINED,                  // for fn:error()

  ZORBA_XQP,                            // Zorba XQuery Processor
  ZORBA_API,                            // Zorba API
  ZORBA_DDF,                            // Data Definition Facility
  ZORBA_DEBUGGER,                       // Zorba Debugger
  ZORBA_OS,                             // Operating System
  ZORBA_SERIALIZATION,
  ZORBA_STORE
};

/**
 * Emits the given diagnostic::category to the given ostream.
 *
 * @param o The ostream to emit to.
 * @param c The category to emit.
 * @return Returns \a o.
 */
ZORBA_DLL_PUBLIC
std::ostream& operator<<( std::ostream &o, category c );

/**
 * An diagnostic::kind is the kind of error.
 * See: http://www.w3.org/TR/xquery-30/#id-kinds-of-errors
 */
enum kind {
  UNKNOWN_KIND,                         // must have integer value of 0

  /**
   * A static error is an error that must be detected during the static
   * analysis phase. A syntax error is an example of a static error.
   */
  XQUERY_STATIC,

  /**
   * A dynamic error is an error that must be detected during the dynamic
   * evaluation phase and may be detected during the static analysis phase.
   * Numeric overflow is an example of a dynamic error.
   */
  XQUERY_DYNAMIC,

  /**
   * A type error may be raised during the static analysis phase or the dynamic
   * evaluation phase.
   * 
   * During the static analysis phase, a type error occurs when the static type
   * of an expression does not match the expected type of the context in which
   * the expression occurs.
   *
   * During the dynamic evaluation phase, a type error occurs when the dynamic
   * type of a value does not match the expected type of the context in which
   * the value occurs.
   */
  XQUERY_TYPE
};

/**
 * Emits the given diagnostic::kind to the given ostream.
 *
 * @param o The ostream to emit to.
 * @param k The kind to emit.
 * @return Returns \a o.
 */
ZORBA_DLL_PUBLIC
std::ostream& operator<<( std::ostream &o, kind k );

///////////////////////////////////////////////////////////////////////////////

} // namespace diagnostic
} // namespace zorba

#include <zorba/internal/qname.h>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %Diagnostic is the base class for all Zorba diagnostics (errors and
 * warnings).
 */
class ZORBA_DLL_PUBLIC Diagnostic {
public:
  /**
   * Gets the QName for this diagnostic.
   *
   * @return Returns said QName.
   */
  virtual diagnostic::QName const& qname() const = 0;

  /**
   * Gets the category of this diagnostic.
   *
   * @return Returns said category.
   */
  virtual diagnostic::category category() const;

  /**
   * Gets the kind of this diagnostic.
   *
   * @return Returns said kind.
   */
  virtual diagnostic::kind kind() const;

  /**
   * Gets the message of this diagnostic.
   *
   * @return Returns said message.
   */
  virtual char const* message() const;

protected:
  virtual ~Diagnostic();

  virtual Diagnostic const* clone() const = 0;

  /**
   * Destroys a %Diagnostic.  This is the only way a %Diagnostic should be
   * destroyed.
   */
  virtual void destroy() const;

  // Only ZorbaException may call clone() and destroy().
  friend class ZorbaException;
};

/**
 * Compares two diagnostics for equality.
 *
 * @param d1 The first diagnostic.
 * @param d2 The second diagnostic.
 * @return Returns \c true only if the diagnostics' QNames are equal.
 */
inline bool operator==( Diagnostic const &d1, Diagnostic const &d2 ) {
  return d1.qname() == d2.qname();
}

/**
 * Compares two diagnostics for inequality.
 *
 * @param d1 The first diagnostic.
 * @param d2 The second diagnostic.
 * @return Returns \c true only if the diagnostics' QNames are not equal.
 */
inline bool operator!=( Diagnostic const &d1, Diagnostic const &d2 ) {
  return !(d1 == d2);
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#include <zorba/internal/diagnostic.h>

#endif /* ZORBA_DIAGNOSTIC_API_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */

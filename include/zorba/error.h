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

#ifndef ZORBA_ERROR_API_H
#define ZORBA_ERROR_API_H

#include <zorba/internal/qname.h>

namespace zorba {

class Error;
namespace serialization{
  class Archiver;
  void operator&(zorba::serialization::Archiver &ar, const Error *&obj);
}

///////////////////////////////////////////////////////////////////////////////

/**
 * An %Error is the base class for all Zorba errors.
 */
class ZORBA_DLL_PUBLIC Error {
public:
  virtual ~Error();

  /**
   * Gets the QName for this error.
   *
   * @return Returns said QName.
   */
  virtual err::QName const& qname() const = 0;

  /**
   * Gets the type of this error.
   *
   * @return Returns said type.
   */
  virtual err::type type() const = 0;

  /**
   * Gets the error message of this error.
   *
   * @return Returns said message.
   */
  virtual char const* message() const;

protected:
  virtual Error const* clone() const = 0;
  virtual void destroy() const;

  friend class ZorbaException;
};

/**
 * Compares two errors for equality.
 *
 * @param q1 The first error.
 * @param q2 The second error.
 * @return Returns \c true only if the errors' QNames are equal.
 */
inline bool operator==( Error const &e1, Error const &e2 ) {
  return e1.qname() == e2.qname();
}

/**
 * Compares two errors for inequality.
 *
 * @param q1 The first error.
 * @param q2 The second error.
 * @return Returns \c true only if the errors' QNames are not equal.
 */
inline bool operator!=( Error const &e1, Error const &e2 ) {
  return !(e1 == e2);
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#include <zorba/internal/error.h>
#include <zorba/internal/qname.h>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * An %XQueryError is an error for all XQuery-specific errors.
 */
typedef internal::SystemError<internal::XQueryErrQName> XQueryError;

/**
 * A %ZorbaError is an error for all Zorba-specific errors.
 */
typedef internal::SystemError<internal::ZorbaErrQName> ZorbaError;

///////////////////////////////////////////////////////////////////////////////

/**
 * A %UserError is-an Error for user-defined errors via \c fn:error().
 */
class ZORBA_DLL_PUBLIC UserError : public Error {
public:
  /**
   * Destroys a %UserError.
   */
  ~UserError();

  // inherited
  err::QName const& qname() const;
  err::type type() const;

protected:
  // inherited
  Error const* clone() const;

private:
  typedef internal::VariableQName<std::string> QName;
  QName qname_;

  /**
   * Constructs a %UserError.
   *
   * @param ns The error's namespace URI.
   * @param prefix The error's prefix.
   * @param localname The error's local-name.
   */
  UserError( char const *ns, char const *prefix, char const *localname );

  friend class UserException;
  friend UserError make_user_error( char const*, char const*, char const* );

  //for plan serialization
  UserError(zorba::serialization::Archiver &ar);
  friend void zorba::serialization::operator&(zorba::serialization::Archiver &ar, const Error *&obj);
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_ERROR_API_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */

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

#ifndef ZORBA_USER_EXCEPTION_API_H
#define ZORBA_USER_EXCEPTION_API_H

#include <vector>

#include <zorba/api_shared_types.h>
#include <zorba/error.h>
#include <zorba/xquery_exception.h>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

class UserException;

namespace internal {

typedef std::vector<Item> error_object_type;

/**
 * \internal
 * Makes a UserException.
 * This function should not be called directly.
 * Instead, the \c USER_EXCEPTION macro should be used.
 *
 * @param throw_file The C++ source-code file name whence the exception was
 * thrown.           
 * @param throw_line The C++ source-code line number whence the exception was
 * thrown.
 * @param ns The error's namespace.
 * @param prefix The error's prefix.
 * @param localname The error's local-name.
 * @param description The error description.
 * @param loc The XQuery source-code location.
 * @param error_object The error object, if any.
 * @return Returns a new UserException.
 */
UserException
make_user_exception( char const *throw_file,
                     ZorbaException::line_type throw_line,
                     char const *ns, char const *prefix, char const *localname,
                     char const *description, err::location const &loc,
                     error_object_type *error_object = 0 );

} // namespace internal

///////////////////////////////////////////////////////////////////////////////

/**
 * A %UserException is-an XQueryException for errors raised via
 * <code>fn:error()</code>.
 */
class ZORBA_DLL_PUBLIC UserException : public XQueryException {
public:
  typedef internal::error_object_type error_object_type;

  /**
   * Destroys this %UserException.
   */
  ~UserException() throw();

  /**
   * Gets the error object associated with this exception.
   *
   * @return Returns said error object.
   */
  error_object_type const& getErrorObject() const throw() {
    return error_object_;
  }

  // inherited
  std::auto_ptr<ZorbaException> clone() const;
  void polymorphic_throw() const;

private:
  error_object_type error_object_;

  /**
   * Constructs a %UserException.
   *
   * @param ns The namespace of the error.
   * @param prefix The prefix of the error.
   * @param locaname The local-name of the error.
   * @param throw_file The source-code file name whence the exception was
   * thrown.
   * @param throw_line The source-code line number whence the exception was
   * thrown.
   * @param description The error description.
   * @param error_object The error object.
   */
  UserException( char const *ns, char const *prefix, char const *localname,
                 char const *throw_file, line_type throw_line,
                 char const *description, error_object_type *error_object );

  friend UserException internal::make_user_exception(
    char const*, line_type, char const*, char const*, char const*, char const*,
    internal::err::location const&, error_object_type*
  );
};

/**
 * Creates a UserException.
 * \hideinitializer
 */
#define USER_EXCEPTION(...) \
  zorba::internal::make_user_exception( __FILE__, __LINE__, __VA_ARGS__ )

/**
 * Creates a default UserException.
 * \hideinitializer
 */
#define DEFAULT_USER_EXCEPTION() \
  zorba::internal::make_user_exception( __FILE__, __LINE__ )

///////////////////////////////////////////////////////////////////////////////

namespace internal {

/**
 * \internal
 * Makes a UserException.
 * This provides for the:
 * \code
 * fn:error()
 * \endcode
 * XQuery function.
 * This function should not be called directly.
 * Instead, the \c USER_EXCEPTION macro should be used.
 *
 * @param throw_file The C++ source-code file name whence the exception was
 * thrown.           
 * @param throw_line The C++ source-code line number whence the exception was
 * thrown.
 */
ZORBA_DLL_PUBLIC UserException
make_user_exception( char const *throw_file,
                     ZorbaException::line_type throw_line );

/**
 * \internal
 * Makes a UserException.
 * This provides for the:
 * \code
 * fn:error($error as xs:QName)
 * \endcode
 * XQuery function.
 * This function should not be called directly.
 * Instead, the \c USER_EXCEPTION macro should be used.
 *
 * @param throw_file The C++ source-code file name whence the exception was
 * thrown.           
 * @param throw_line The C++ source-code line number whence the exception was
 * thrown.
 * @param error The error code expressed as a QName.
 */
ZORBA_DLL_PUBLIC UserException
make_user_exception( char const *throw_file,
                     ZorbaException::line_type throw_line, Item const &error );

/**
 * \internal
 * Makes a UserException.
 * This provides for the:
 * \code
 * fn:error($error as xs:QName,
 *          $description as xs:string)
 * \endcode
 * XQuery function.
 * This function should not be called directly.
 * Instead, the \c USER_EXCEPTION macro should be used.
 *
 * @param throw_file The C++ source-code file name whence the exception was
 * thrown.           
 * @param throw_line The C++ source-code line number whence the exception was
 * thrown.
 * @param error The error code expressed as a QName.
 * @param description The error description
 */
ZORBA_DLL_PUBLIC UserException
make_user_exception( char const *throw_file,
                     ZorbaException::line_type throw_line, Item const &error,
                     String const &description );

/**
 * \internal
 * Makes a UserException.
 * This provides for the:
 * \code
 * fn:error($error as xs:QName,
 *          $description as xs:string,
 *          $error-object as item()*)
 * \endcode
 * XQuery function.
 * This function should not be called directly.
 * Instead, the \c USER_EXCEPTION macro should be used.
 *
 * @param throw_file The C++ source-code file name whence the exception was
 * thrown.           
 * @param throw_line The C++ source-code line number whence the exception was
 * thrown.
 * @param error The error code expressed as a QName.
 * @param description The error description
 * @param error_object The error object.
 */
ZORBA_DLL_PUBLIC UserException
make_user_exception( char const *throw_file,
                     ZorbaException::line_type throw_line,
                     Item const &error, String const &description,
                     ItemSequence_t const &error_object );

ZORBA_DLL_PUBLIC UserException
make_user_exception( char const *throw_file,
                     ZorbaException::line_type throw_line,
                     Error const &error, err::parameters const &params,
                     err::location const &loc,
                     error_object_type *error_object = 0 );

inline UserException
make_user_exception( char const *throw_file,
                     ZorbaException::line_type throw_line,
                     Error const &error, err::parameters const &params,
                     error_object_type *error_object = 0 ) {
  return make_user_exception(
    throw_file, throw_line, error, params, err::location::empty, error_object
  );
}

inline UserException
make_user_exception( char const *throw_file,
                     ZorbaException::line_type throw_line,
                     Error const &error, error_object_type *error_object = 0 ) {
  return make_user_exception(
    throw_file, throw_line, error, err::parameters::empty,
    err::location::empty, error_object
  );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace internal
} // namespace zorba
#endif /* ZORBA_USER_EXCEPTION_API_H */
/* vim:set et sw=2 ts=2: */

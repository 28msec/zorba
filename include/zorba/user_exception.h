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

namespace serialization {
  class Archiver;
}

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
 * @param raise_file The C++ source-code file name whence the exception was
 * raised.           
 * @param raise_line The C++ source-code line number whence the exception was
 * raised.
 * @param ns The error's namespace.
 * @param prefix The error's prefix.
 * @param localname The error's local-name.
 * @param description The error description.
 * @param loc The XQuery source-code location.
 * @param error_object The error object, if any.
 * @return Returns a new UserException.
 */
ZORBA_DLL_PUBLIC UserException // MAKE_USER_EXCEPTION_CC_LT_4CC_EL_EOT_X
make_user_exception( char const *raise_file,
                     ZorbaException::line_type raise_line,
                     char const *ns, char const *prefix, char const *localname,
                     char const *description, diagnostic::location const &loc,
                     error_object_type *error_object = 0 );

/**
 * \internal
 * Makes a UserException.
 * This function should not be called directly.
 * Instead, the \c USER_EXCEPTION macro should be used.
 *
 * @param raise_file The C++ source-code file name whence the exception was
 * raised.           
 * @param raise_line The C++ source-code line number whence the exception was
 * raised.
 * @param error The error.
 * @param description The error description.
 * @param loc The XQuery source-code location.
 * @param error_object The error object, if any.
 * @return Returns a new UserException.
 */
ZORBA_DLL_PUBLIC UserException // MAKE_USER_EXCEPTION_CC_LT_E_CC_EL_EOT_X
make_user_exception( char const *raise_file,
                     ZorbaException::line_type raise_line,
                     Error const &error, char const *description,
                     diagnostic::location const &loc,
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
   * Copy-constructs a %UserException.
   *
   * @param from The %UserException to copy from.
   */
  UserException( UserException const &from );

  /**
   * Destroys this %UserException.
   */
  ~UserException() throw();

  /**
   * Assigns this %UserException from another.
   *
   * @param from The %UserException to assign from.
   * @return Returns \c *this.
   */
  UserException& operator=( UserException const &from );

  /**
   * Gets the error object associated with this exception.
   *
   * @return Returns said error object.
   */
  error_object_type const& error_object() const throw() {
    return error_object_;
  }

  // inherited
  void polymorphic_throw() const;

protected:
  // inherited
  std::unique_ptr<ZorbaException> clone() const;

private:
  error_object_type error_object_;

  /**
   * Constructs a %UserException.
   *
   * @param ns The namespace of the error.
   * @param prefix The prefix of the error.
   * @param locaname The local-name of the error.
   * @param raise_file The source-code file name whence the exception was
   * raised.
   * @param raise_line The source-code line number whence the exception was
   * raised.
   * @param description The error description.
   * @param error_object The error object.
   */
  UserException( char const *ns, char const *prefix, char const *localname,
                 char const *raise_file, line_type raise_line,
                 char const *description, error_object_type *error_object );

  /**
   * Constructs a %UserException.
   *
   * @param error The error.
   * @param raise_file The source-code file name whence the exception was
   * raised.
   * @param raise_line The source-code line number whence the exception was
   * raised.
   * @param description The error description.
   * @param error_object The error object.
   */
  UserException( Error const &error,
                 char const *raise_file, line_type raise_line,
                 char const *description, error_object_type *error_object );

  friend UserException internal::make_user_exception(
    char const*, line_type, char const*, char const*, char const*, char const*,
    internal::diagnostic::location const&, error_object_type*
  );

  friend UserException internal::make_user_exception(
    char const*, line_type, Error const&, char const*,
    internal::diagnostic::location const&, error_object_type*
  );

  // for plan serialization
  UserException( serialization::Archiver& );
  friend void serialization::operator&( serialization::Archiver&,
                                        ZorbaException*& );
};

/**
 * Creates a UserException.
 * \hideinitializer
 */
#define USER_EXCEPTION(...) \
  ::zorba::internal::make_user_exception( __FILE__, __LINE__, __VA_ARGS__ )

/**
 * Creates a default UserException.
 * \hideinitializer
 */
#define DEFAULT_USER_EXCEPTION() \
  ::zorba::internal::make_user_exception( __FILE__, __LINE__ )

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
 * Instead, the \c DEFAULT_USER_EXCEPTION macro should be used.
 *
 * @param raise_file The C++ source-code file name whence the exception was
 * raised.           
 * @param raise_line The C++ source-code line number whence the exception was
 * raised.
 */
ZORBA_DLL_PUBLIC UserException // MAKE_USER_EXCEPTION_CC_LT_X
make_user_exception( char const *raise_file,
                     ZorbaException::line_type raise_line );

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
 * @param raise_file The C++ source-code file name whence the exception was
 * raised.           
 * @param raise_line The C++ source-code line number whence the exception was
 * raised.
 * @param error The error code expressed as a QName.
 */
ZORBA_DLL_PUBLIC UserException // MAKE_USER_EXCEPTION_CC_LT_I_X
make_user_exception( char const *raise_file,
                     ZorbaException::line_type raise_line,
                     Item const &error );

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
 * @param raise_file The C++ source-code file name whence the exception was
 * raised.           
 * @param raise_line The C++ source-code line number whence the exception was
 * raised.
 * @param error The error code expressed as a QName.
 */
ZORBA_DLL_PUBLIC UserException // MAKE_USER_EXCEPTION_CC_LT_E_X
make_user_exception( char const *raise_file,
                     ZorbaException::line_type raise_line,
                     Error const &error );

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
 * @param raise_file The C++ source-code file name whence the exception was
 * raised.           
 * @param raise_line The C++ source-code line number whence the exception was
 * raised.
 * @param error The error code expressed as a QName.
 * @param description The error description.
 */
ZORBA_DLL_PUBLIC UserException // MAKE_USER_EXCEPTION_CC_LT_I_S_X
make_user_exception( char const *raise_file,
                     ZorbaException::line_type raise_line,
                     Item const &error, String const &description );

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
 * @param raise_file The C++ source-code file name whence the exception was
 * raised.           
 * @param raise_line The C++ source-code line number whence the exception was
 * raised.
 * @param error The error code expressed as a QName.
 * @param description The error description.
 * @param error_object The error object.
 */
ZORBA_DLL_PUBLIC UserException // MAKE_USER_EXCEPTION_CC_LT_I_S_IS_X
make_user_exception( char const *raise_file,
                     ZorbaException::line_type raise_line,
                     Item const &error, String const &description,
                     ItemSequence_t const &error_object );

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
 * @param raise_file The C++ source-code file name whence the exception was
 * raised.           
 * @param raise_line The C++ source-code line number whence the exception was
 * raised.
 * @param error The error code expressed as a QName.
 * @param description The error description.
 * @param error_object The error object.
 */
ZORBA_DLL_PUBLIC UserException // MAKE_USER_EXCEPTION_CC_LT_E_S_IS_X
make_user_exception( char const *raise_file,
                     ZorbaException::line_type raise_line,
                     Error const &error, String const &description,
                     ItemSequence_t const &error_object );

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
 * @param raise_file The C++ source-code file name whence the exception was
 * raised.           
 * @param raise_line The C++ source-code line number whence the exception was
 * raised.
 * @param error The error code expressed as a QName.
 * @param description The error description.
 * @param error_object The error object.
 */
ZORBA_DLL_PUBLIC UserException // MAKE_USER_EXCEPTION_CC_LT_E_S_EOT_X
make_user_exception( char const *raise_file,
                     ZorbaException::line_type raise_line,
                     Error const &error, String const &description,
                     error_object_type *error_object = 0 );

///////////////////////////////////////////////////////////////////////////////

} // namespace internal
} // namespace zorba
#endif /* ZORBA_USER_EXCEPTION_API_H */
/* vim:set et sw=2 ts=2: */

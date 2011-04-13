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

#ifndef ZORBA_XQUERY_EXCEPTION_API_H
#define ZORBA_XQUERY_EXCEPTION_API_H

#include <zorba/xquery_stack_trace.h>
#include <zorba/zorba_exception.h>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

namespace internal {

/**
 * \internal
 * Makes an XQueryException.
 *
 * @param throw_file The C++ source-code file name whence the exception was
 * thrown.
 * @param throw_line The C++ source-code line number whence the exception was
 * thrown.
 * @param error The error.
 * @param params The error message parameters.
 * @param loc The error XQuery source-code location.
 * @return Returns a new XQueryException.
 */
ZORBA_DLL_PUBLIC XQueryException
make_xquery_exception( char const *throw_file,
                       ZorbaException::line_type throw_line,
                       Error const &error, err::parameters const &params,
                       err::location const &loc = err::location::empty );

/**
 * \internal
 * Dynamically allocates an XQueryException.
 *
 * @param throw_file The C++ source-code file name whence the exception was
 * thrown.
 * @param throw_line The C++ source-code line number whence the exception was
 * thrown.
 * @param error The error.
 * @param params The error message parameters.
 * @param loc The error XQuery source-code location.
 * @return Returns a new XQueryException.
 */
ZORBA_DLL_PUBLIC XQueryException*
new_xquery_exception( char const *throw_file,
                      ZorbaException::line_type throw_line,
                      Error const &error, err::parameters const &params,
                      err::location const &loc = err::location::empty );

} // namespace internal

///////////////////////////////////////////////////////////////////////////////

/**
 * An %XQueryException is-a ZorbaException for errors with the user's XQuery.
 * An %XQueryException therefore also contains the XQuery source URI, line, and
 * column numbers.
 */
class ZORBA_DLL_PUBLIC XQueryException : public ZorbaException {
public:
  typedef internal::err::location::column_type column_type;

  /**
   * Copy-constructs a %XQueryException.
   *
   * @param from The %XQueryException to copy from.
   */
  XQueryException( XQueryException const &from );

  /**
   * Destroys this %XQueryException.
   */
  ~XQueryException() throw();

  /**
   * Assigns this %XQueryException from another.
   *
   * @param from The %XQueryException to assign from.
   * @return Returns \c *this.
   */
  XQueryException& operator=( XQueryException const &from );

  /**
   * Sets the XQuery source-code URI name, line, and column numbers.
   *
   * @param URI The source-code URI name.
   * @param line The source-code URI line number.
   * @param col The source-code URI column number.
   */
  void set_source( char const *uri, line_type line, column_type column = 0 );

  /**
   * Checks whether the XQuery source location has been set.
   *
   * @return Returns \c true only if the source location has been set.
   */
  bool has_source() const throw() {
    return source_loc_;
  }

  /**
   * Gets the XQuery source URI containing the error.
   *
   * @return Returns said URI or the empty string if unset.
   */
  char const* source_uri() const throw() {
    return source_loc_.file();
  }

  /**
   * Gets the XQuery source-code line number containing the error.
   *
   * @return Returns said line number or 0 if unset.
   */
  line_type source_line() const throw() {
    return source_loc_.line();
  }

  /**
   * Gets the XQuery source-code column number containing the error.
   *
   * @return Returns said column number or 0 if unset.
   */
  column_type source_column() const throw() {
    return source_loc_.column();
  }

  /**
   * Gets the XQuery stack trace, if any.
   *
   * @return Returns said stack trace.
   */
  XQueryStackTrace& query_trace() throw() {
    return query_trace_;
  }

  /**
   * Gets the XQuery stack trace, if any.
   *
   * @return Returns said stack trace.
   */
  XQueryStackTrace const& query_trace() const throw() {
    return query_trace_;
  }

  // inherited
  std::auto_ptr<ZorbaException> clone() const;
  void polymorphic_throw() const;
  std::ostream& print( std::ostream &o ) const;

private:
  /**
   * Constructs an %XQueryException.
   *
   * @param error The error.
   * @param throw_file The C++ source-code file name whence the exception was
   * thrown.
   * @param throw_line The C++ source-code line number whence the exception was
   * thrown.
   * @param message The error message.
   */
  XQueryException( Error const &error, char const *throw_file,
                   line_type throw_line, char const *message );

  internal::err::location source_loc_;
  XQueryStackTrace query_trace_;

  friend XQueryException internal::make_xquery_exception(
    char const*,
    ZorbaException::line_type,
    Error const&,
    internal::err::parameters const&,
    internal::err::location const&
  );

  friend XQueryException* internal::new_xquery_exception(
    char const*,
    ZorbaException::line_type,
    Error const&,
    internal::err::parameters const&,
    internal::err::location const&
  );

  friend class UserException;
};

#define MAKE_EXCEPTION_VAR(MAKE_FN,...) \
  ::zorba::MAKE_FN( __FILE__, __LINE__, __VA_ARGS__ )

/**
 * Creates an XQueryException using the given Error variable.
 * \hideinitializer
 */
#define XQUERY_EXCEPTION_VAR(...) \
  MAKE_EXCEPTION_VAR( internal::make_xquery_exception, __VA_ARGS__ )

/**
 * Creates an XQueryException using the local name of an error.
 * \hideinitializer
 */
#define XQUERY_EXCEPTION(...) \
  XQUERY_EXCEPTION_VAR( ::zorba::err:: __VA_ARGS__ )

///////////////////////////////////////////////////////////////////////////////

namespace internal {

/**
 * \internal
 * Makes an XQueryException.
 *
 * @param throw_file The C++ source-code file name whence the exception was
 * thrown.
 * @param throw_line The C++ source-code line number whence the exception was
 * thrown.
 * @param error The error.
 * @param loc The error XQuery source-code location.
 * @return Returns a new XQueryException.
 */
inline XQueryException
make_xquery_exception(
    char const *throw_file,
    ZorbaException::line_type throw_line,
    Error const &error,
    err::location const &loc = err::location::empty ) {
  return make_xquery_exception(
    throw_file, throw_line, error, err::parameters::empty, loc
  );
}

} // namespace internal

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_XQUERY_EXCEPTION_API_H */
/* vim:set et sw=2 ts=2: */

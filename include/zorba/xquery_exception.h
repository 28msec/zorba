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

namespace serialization {
  class Archiver;
  void operator&( Archiver&, ZorbaException*& );
}

///////////////////////////////////////////////////////////////////////////////

/**
 * An %XQueryException is-a ZorbaException for errors with the user's XQuery.
 * An %XQueryException therefore also contains the XQuery source URI, line, and
 * column numbers.
 */
class ZORBA_DLL_PUBLIC XQueryException : public ZorbaException {
public:
  typedef internal::diagnostic::location::column_type column_type;

  /**
   * Copy-constructs an %XQueryException.
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
   * @param uri The source-code URI name.
   * @param line The source-code URI line number.
   * @param column The source-code URI column number.
   * @param line_end The source-code URI end line number.
   * @param column_end The source-code URI end column number.
   */
  void set_source(
      char const *uri,
      line_type line,
      column_type column = 0,
      line_type line_end = 0,
      column_type column_end = 0 );

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
   * Gets the XQuery source-code end line number containing the error.
   *
   * @return Returns said line number or 0 if unset.
   */
  line_type source_line_end() const throw() {
    return source_loc_.line_end();
  }

  /**
   * Gets the XQuery source-code end column number containing the error.
   *
   * @return Returns said column number or 0 if unset.
   */
  column_type source_column_end() const throw() {
    return source_loc_.column_end();
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
  void polymorphic_throw() const;

protected:
  // inherited
  std::auto_ptr<ZorbaException> clone() const;
  std::ostream& print( std::ostream &o ) const;

private:
  /**
   * Constructs an %XQueryException.
   *
   * @param diagnostic The diagnostic.
   * @param raise_file The C++ source-code file name whence the exception was
   * raised.
   * @param raise_line The C++ source-code line number whence the exception was
   * raised.
   * @param message The diagnostic message.
   */
  XQueryException( Diagnostic const &diagnostic, char const *raise_file,
                   line_type raise_line, char const *message );

  internal::diagnostic::location source_loc_;
  XQueryStackTrace query_trace_;

  friend XQueryException make_xquery_exception(
    char const*, ZorbaException::line_type, Diagnostic const&,
    internal::diagnostic::parameters const&,
    internal::diagnostic::location const&
  );

  friend XQueryException* new_xquery_exception(
    char const*, ZorbaException::line_type, Diagnostic const&,
    internal::diagnostic::parameters const&,
    internal::diagnostic::location const&
  );

  friend void set_source( ZorbaException&, char const*, line_type, column_type,
                          line_type, column_type, bool );

  friend class UserException;

protected:
  // for plan serialization
  XQueryException( serialization::Archiver &ar );
  friend void serialization::operator&( serialization::Archiver&,
                                        ZorbaException*& );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_XQUERY_EXCEPTION_API_H */
/* vim:set et sw=2 ts=2: */

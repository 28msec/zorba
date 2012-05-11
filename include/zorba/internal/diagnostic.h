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

#ifndef ZORBA_INTERNAL_DIAGNOSTIC_H
#define ZORBA_INTERNAL_DIAGNOSTIC_H

#include <string>
#include <vector>

#include <zorba/diagnostic.h>

#include "ztd.h"

namespace zorba {

namespace internal {
  namespace diagnostic {
    class location;
  }
}
namespace serialization {
  class Archiver;
  void operator&( serialization::Archiver&, internal::diagnostic::location& );
}

namespace internal {
namespace diagnostic {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %location hold the file location of an error.
 */
class ZORBA_DLL_PUBLIC location {
public:
  /**
   * The line-number type.
   */
  typedef unsigned line_type;

  /**
   * The column-number type.
   */
  typedef unsigned short column_type;

  /**
   * A empty instance for convenience.
   */
  static location const empty;

  /**
   * Constructs a default (empty) %location.
   */
  location() : line_( 0 ), column_( 0 ), line_end_( 0 ), column_end_( 0 ) {
  }

  /**
   * Constructs a %location.
   *
   * @param file The name of the file where the error occurred.
   * @param line The line number of the file where the expression that
   *  raises the error begins.
   * @param column The column number, if any, of the file where the expression
   *  that raises the error begins.
   * @param line_end The end line number, if any, of the file where the expression
   *  causing the error ends.
   * @param column_end The end column number, if any, of the file where 
   *  the xpression causing the error ends.
   */
  location(
      char const *file,
      line_type line,
      column_type column = 0,
      line_type line_end = 0,
      column_type column_end = 0) :
    file_( file ), line_( line ), column_( column ),
    line_end_( line_end ), column_end_( column_end )
  {
  }

  /**
   * Constructs a %location.
   *
   * @tparam StringType The string type for \a file.
   * @param file The name of the file where the error occurred.
   * @param line The line number of the file where the error occurred.
   * @param column The column number, if any, of the file where the error occurred.
   * @param line_end The end line number, if any, of the file where the expression
   *  causing the error ends.
   * @param column_end The end column number, if any, of the file where 
   *  the xpression causing the error ends.
   */
  template<class StringType>
  location(
      StringType const &file,
      line_type line,
      column_type column = 0,
      line_type line_end = 0,
      column_type column_end = 0) :
    file_( file.c_str() ), line_( line ), column_( column ),
    line_end_( line_end ), column_end_( column_end )
  {
  }

  /**
   * Gets the file name, if any.
   *
   * @return Returns the file name or the empty string if unset.
   */
  char const* file() const {
    return file_.c_str();
  }

  /**
   * Gets the line number, if any.
   *
   * @return Returns the line number or 0 if unset.
   */
  line_type line() const {
    return line_;
  }

  /**
   * Gets the column number, if any.
   *
   * @return Returns the column number or 0 if unset.
   */
  column_type column() const {
    return column_;
  }

  /**
   * Gets the ending line number, if any.
   *
   * @return Returns the line number or 0 if unset.
   */
  line_type line_end() const {
    return line_end_;
  }

  /**
   * Gets the ending column number, if any.
   *
   * @return Returns the column number or 0 if unset.
   */
  column_type column_end() const {
    return column_end_;
  }

  /**
   * Conversion to \c bool for testing whether this %location has been set.
   *
   * @return Returns \c true only if this %location has been set.
   */
  operator bool() const {
    return !!line_;
  }

  /**
   * Checks whether this %location has not been set.
   *
   * @return Returns \c true only if this %location has not been set.
   */
  bool operator!() const {
    return !line_;
  }

  /**
   * Sets the %location information.
   *
   * @param file The name of the file where the error occurred.
   * @param line The line number of the file where the error occurred.
   * @param column The column number, if any, of the file where the error
   * occurred.
   * @param line_end The end line of the file where the error occured.
   * @param column_end The column number, if any, where the error ends.
   * occurred.
   */
  void set(
      char const *file,
      line_type line,
      column_type column = 0,
      line_type line_end = 0,
      column_type column_end = 0) {
    file_ = file;
    line_ = line;
    column_ = column;
    line_end_ = line_end;
    column_end_ = column_end;
  }

private:
  std::string file_;
  line_type line_;
  column_type column_;
  line_type line_end_;
  column_type column_end_;

  // for plan serialization
  friend void serialization::operator&( serialization::Archiver&, location& );
};

///////////////////////////////////////////////////////////////////////////////

/**
 * \internal
 * A %parameters holds the parameters for an error message.
 */
class ZORBA_DLL_PUBLIC parameters {
  typedef std::vector<std::string> params_type;
public:
  typedef params_type::value_type value_type;
  typedef params_type::size_type size_type;

  /**
   * A empty instance for convenience.
   */
  static parameters const empty;

  /**
   * Constructs a %parameters object.
   */
  parameters();

  /**
   * Adds the string representation of the given object as the next parameter.
   *
   * @tparam T The object type.
   * @param t The object.
   * @return Returns \c *this.
   */
  template<typename T>
  parameters& operator,( T const &t ) {
    params_.push_back( ztd::to_string( t ) );
    return *this;
  }

  /**
   * Gets the i'th parameter value.
   * Parameter numbers start at 1.
   *
   * @param i The parameter to get.
   * @return Returns said parameter value.
   */
  value_type const& operator[]( size_type i ) const {
    return params_[ i - 1 ];
  }

  /**
   * Substitutes substrings of the given string.  There are two forms:
   *
   * - <code>$</code><em>i</em>
   * - <code>${</code><em>chars i chars</em><code>}</code>
   *
   * where <em>i</em> is an integer in the range <code>[1,9]</code>
   * and <em>chars</em> are any characters except <code>[1-9}]</code>.
   *
   * The second form elides the addition characacters if the value of the
   * <em>ith</em> parameter is empty.  For example, <code>${"1"}</code> will
   * substitute the value of the 1st parameter quoted if non-empty; if empty,
   * the entire substitution set of characters (everything from the
   * <code>$</code> to the <code>}</code>) will be elided.
   *
   * @param s The string to perform the substitutions on.
   */
  void substitute( value_type *s ) const;

private:
  params_type params_;

  value_type lookup_param( size_type i ) const;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace diagnostic
} // namespace internal
} // namespace zorba
#endif /* ZORBA_INTERNAL_DIAGNOSTIC_H */
/* vim:set et sw=2 ts=2: */

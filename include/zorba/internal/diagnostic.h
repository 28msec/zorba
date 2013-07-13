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
 * \internal
 * A %location holds the file location of an error.
 */
class ZORBA_DLL_PUBLIC location {
  typedef ztd::explicit_bool explicit_bool;
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
   * @param file The name of the file where the expression causing the error
   * occurred.
   * @param line The line number of the file where the expression causing the
   * error begins.
   * @param column The column number, if any, of the file where the expression
   * causing the error begins.
   * @param line_end The end line number, if any, of the file where the
   * expression causing the error ends.
   * @param column_end The end column number, if any, of the file where the
   * expression causing the error ends.
   */
  location( char const *file, line_type line, column_type column = 0,
            line_type line_end = 0, column_type column_end = 0 ) :
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
   * @param column The column number, if any, of the file where the error
   * occurred.
   * @param line_end The end line number, if any, of the file where the
   * expression causing the error ends.
   * @param column_end The end column number, if any, of the file where the
   * xpression causing the error ends.
   */
  template<class StringType>
  location( StringType const &file, line_type line, column_type column = 0,
            line_type line_end = 0, column_type column_end = 0 ) :
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
  operator explicit_bool::type() const {
    return explicit_bool::value_of( line_ );
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
  void set( char const *file, line_type line, column_type column = 0,
            line_type line_end = 0, column_type column_end = 0 ) {
    file_ = file;
    set( line, column, line_end, column_end );
  }

  /**
   * Sets the %location information.
   *
   * @param line The line number of the file where the error occurred.
   * @param column The column number, if any, of the file where the error
   * occurred.
   * @param line_end The end line of the file where the error occured.
   * @param column_end The column number, if any, where the error ends.
   * occurred.
   */
  void set( line_type line, column_type column = 0, line_type line_end = 0,
            column_type column_end = 0 ) {
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

  friend bool operator==( location const&, location const& );
  friend bool operator!=( location const&, location const& );

  // for plan serialization
  friend void serialization::operator&( serialization::Archiver&, location& );
};

/**
 * \internal
 * Compares two locations for equality.
 *
 * @param i The first location.
 * @param j The second location.
 * @return Returns \c true only if the two locations are equal.
 */
bool operator==( location const &i, location const &j );

/**
 * \internal
 * Compares two locations for inequality.
 *
 * @param i The first location.
 * @param j The second location.
 * @return Returns \c true only if the two locations are not equal.
 */
bool operator!=( location const &i, location const &j );

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
    add_param( ztd::to_string( t ) );
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
   * Substitutes substrings of the given string.  Substitutions are in three
   * forms:
   *
   * - <code>$</code><em>i</em>
   * - <code>${</code>[<em>chars</em>]<em>i</em>[<em>chars</em>]<code>}</code>
   * - <code>$</code><em>i</em><code>?</code><em>then</em>[<code>:</code><em>else</em>]
   *
   * where \e i is a digit in the range <code>[1,9]</code> and refers to the
   * value of the \e ith parameter, \e chars may be any characters except
   * <code>[1-9}]</code>, and \e then and \e else are of one of the two forms:
   *
   *  - <em>j</em>
   *  - <code>{</code>[<em>chars j chars k chars ...</em>]<code>}</code>
   *
   * where \e j is likewise a digit in the range <code>[1,9]</code> and refers
   * to the value of the \e jth parameter.
   *
   * The first substitution form replaces <code>$</code><em>i</em> with the
   * value of the \e ith parameter.
   *
   * The second form replaces everything from the \c $ to the \c } with the
   * contents of the \c {} where \e i is replaced with the value of the \e ith
   * parameter.  However, if the value is empty, then everything from the \c $
   * to the \c } is instead erased.
   *
   * For example, <code>${"1": }</code> will substitute the value of the 1st
   * parameter quoted followed by a \c : and a space if non-empty; if empty,
   * then everything from the \c $ to the \c } will instead be erased.
   *
   * The third form tests the value of the \c ith parameter: if non-empty, then
   * the \e then portion is substituted; if empty, then the \e else portion is.
   * Both the \e then and \e else portions can be either a digit in the range
   * [1,9] or \e chars enclosed by \c {}.  The \c {} here can contain multiple
   * parameter indicies.  If at least one is non-empty, then the substitution
   * for the portion will be done; if all are empty, then everything for the
   * portion will be erased.
   * 
   * 
   * The \c \\ character can be used to escape the meaning of the
   * <code>$</code>, <code>[1-9]</code>, <code>?</code>, <code>:</code>, and
   * <code>}</code> characters and instead treat them as ordinary characters.
   *
   * Substitution is performed by making at most 9 passes over the string, one
   * pass per parameter starting at 1.  Substitutions may themselves have
   * further substitutions, but, due to the way that substitution is performed,
   * should only refer to parameters having higher digits.  (Digits less than
   * or equal to the current one will not be substituted.)
   *
   * @param s The string to perform the substitutions on.
   */
  void substitute( value_type *s ) const;

private:
  params_type params_;

  void add_param( value_type const& );
  value_type lookup_param( size_type i ) const;
  bool then_else( bool, value_type const&, value_type::size_type*,
                  value_type* ) const;
  size_type to_index( value_type::value_type ) const;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace diagnostic
} // namespace internal
} // namespace zorba
#endif /* ZORBA_INTERNAL_DIAGNOSTIC_H */
/* vim:set et sw=2 ts=2: */

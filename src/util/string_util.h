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

#pragma once
#ifndef ZORBA_STRING_UTIL_H
#define ZORBA_STRING_UTIL_H

#include <zorba/config.h>

// standard
#include <cctype>
#include <cstring>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>
#ifdef WIN32
# include <windows.h>
#endif /* WIN32 */

// Zorba
#include <zorba/internal/cxx_util.h>
#include <zorba/internal/unique_ptr.h>
#include <zorba/internal/ztd.h>
#include "ascii_util.h"
#include "stl_util.h"
#include "zorbatypes/zstring.h"

#ifdef WIN32
// Windows annoyingly defines these as macros.
#undef max
#undef min
#endif /* WIN32 */

namespace zorba {
namespace ztd {

using internal::ztd::c_str;

////////// String appending ///////////////////////////////////////////////////

/**
 * A %string_appender is used to optimize repeatedly appending characters to a
 * string in a loop by gathering \em N characters and appending them in chunks
 * so as to call the string's \c append() function less.
 */
template<class StringType,int BufCapacity>
class string_appender {
public:
  typedef StringType value_type;
  typedef typename value_type::value_type char_type;
  typedef typename value_type::size_type size_type;

  /**
   * Constructs an appender.
   *
   * @param s A pointer to the string to append to.
   */
  string_appender( value_type *s ) : buf_size_( 0 ),  s_( s ) { }

  /**
   * Destroys the appender and appends any unappended characters to the string.
   */
  ~string_appender() {
    flush();
  }

  /**
   * Appends a character.
   *
   * @param c The character to append.
   * @return Returns \c *this.
   */
  string_appender& append( char_type c ) {
    buf_[ buf_size_++ ] = c;
    if ( buf_size_ == BufCapacity )
      flush();
    return *this;
  }

  /**
   * Appends any unappended characters to the string.
   */
  void flush() {
    s_->append( buf_, buf_size_ );
    buf_size_ = 0;
  }

  /**
   * Gets the string that is being appended to.
   *
   * @return Returns said string.
   */
  value_type& str() const {
    return *s_;
  }

  /**
   * Appends a character.
   *
   * @param c The character to append.
   * @return Returns \c *this.
   */
  string_appender& operator+=( char_type c ) {
    return append( c );
  }

private:
  char_type buf_[ BufCapacity ];
  size_type buf_size_;
  value_type *s_;
};

////////// String building ////////////////////////////////////////////////////

/**
 * A %string_builder is used to build (concatenate) strings on-the-fly and pass
 * the resultant string to some function.  See the BUILD_STRING macro for usage.
 * Note that you can use either "<<" or "," to taste.
 *
 * See http://stackoverflow.com/q/5666678 as to why a class like this is
 * needed rather than just using an ostringstream directly.
 */
class string_builder {
public:

  /**
   * Clears then sets the string being built to the string representation of
   * the given object.
   *
   * @tparam T The object type.
   * @param t The object.
   * @return Returns \c *this.
   */
  template<typename T>
  string_builder& operator=( T const &t ) {
    oss_.str( "" );
    oss_ << t;
    return *this;
  }

  /**
   * Appends the string representation of the given object to the string being
   * built.
   *
   * @tparam T The object type.
   * @param t The object.
   * @return Returns \c *this.
   */
  template<typename T>
  string_builder& operator<<( T const &t ) {
    oss_ << t;
    return *this;
  }

  /**
   * Appends the string representation of the given object to the string being
   * built.
   *
   * @tparam T The object type.
   * @param t The object.
   * @return Returns \c *this.
   */
  template<typename T>
  string_builder& operator,( T const &t ) {
    oss_ << t;
    return *this;
  }

  /**
   * Explicit conversion to std::string.
   *
   * @return Returns a string comprising all the objects' string
   * representations concatenated together.
   */
  std::string str() const {
    return oss_.str();
  }

  /**
   * Implicit conversion to std::string.
   *
   * @return Returns a string comprising all the objects' string
   * representations concatenated together.
   */
  operator std::string() const {
    return str();
  }

private:
  std::ostringstream oss_;
};

/**
 * Emits a string_builder's string to the given ostream.
 *
 * @param o The ostream to emit to.
 * @param sb The string_builder to emit the string of.
 * @return Returns \a o.
 */
inline std::ostream& operator<<( std::ostream &o, string_builder const &sb ) {
  return o << sb.str();
}

/**
 * A convenience macro for using string_builder to de-uglify using it.
 * Using this macro, you can go from:
 * \code
 * f( string_builder() = "The answer is: ", answer )
 * \endcode
 * to the more function-like syntax of:
 * \code
 * f( BUILD_STRING( "The answer is: ", answer ) )
 * \endcode
 * \hideinitializer
 */
#define BUILD_STRING(...) (::zorba::ztd::string_builder() << __VA_ARGS__)

////////// String equality /////////////////////////////////////////////////////

/**
 * Equals that works even when either argument is the \c nullptr.
 *
 * @param s1 The first NULL-terminated C string or the \c nullptr.
 * @param s2 The second NULL-terminated C string or the \c nullptr.
 * @return Returns \c true only if \a s1 \c == \a s2.
 */
inline bool equals( char const *s1, char const *s2 ) {
  return s1 ? s2 && std::strcmp( s1, s2 ) == 0 : !s2;
}

/**
 * Faster C string equals.
 *
 * @param s1 The first string.
 * @param s2 The second NULL-terminated C string.
 * @param s2_n The number of characters to compare of \a s2.
 * @return Returns \c true only if \a s1 \c == \a s2.
 */
template<class StringType> inline
typename std::enable_if<ZORBA_IS_STRING(StringType),bool>::type
equals( StringType const &s1, char const *s2,
        typename StringType::size_type s2_n ) {
  typedef typename StringType::traits_type traits_type;
  return s1.size() == s2_n && traits_type::compare( s1.data(), s2, s2_n ) == 0;
}

/**
 * Faster C string equals.
 *
 * @param s1 The first NULL-terminated string.
 * @param s1_n The number of characters to compare of \a s1.
 * @param s2 The second string.
 * @return Returns \c true only if \a s1 \c == \a s2.
 */
template<class StringType> inline
typename std::enable_if<ZORBA_IS_STRING(StringType),bool>::type
equals( char const *s1, typename StringType::size_type s1_n,
        StringType const &s2 ) {
  typedef typename StringType::traits_type traits_type;
  return s1_n == s2.size() && traits_type::compare( s1, s2.data(), s1_n ) == 0;
}

/**
 * A macro for calling equals() with a second argument of a string literal.
 */
#define ZSTREQ(STRING,LITERAL) \
  ::zorba::ztd::equals( STRING, LITERAL, sizeof( LITERAL ) - 1 )

////////// String splitting ////////////////////////////////////////////////////

/**
 * Splits a string at the given delimiter.
 *
 * @tparam OutputStringType1 The first output string type.
 * @tparam OutputStringType2 The second output string type.
 * @param in The string to split.
 * @param delim The delimiter.
 * @param out1 If not \c nullptr, a pointer to the output string to receive the
 * substring to the left of \a delim.
 * @param out2 If not \c nullptr, a pointer to the output string to receive the
 * substring to the right of \a delim.
 * @return Returns \c true only if the string was split (the delimiter was
 * present in \a in).
 */
template<class OutputStringType1,class OutputStringType2>
typename std::enable_if<ZORBA_IS_STRING(OutputStringType1)
                     && ZORBA_IS_STRING(OutputStringType2),
                        bool>::type
split( char const *in, char delim, OutputStringType1 *out1,
       OutputStringType2 *out2 ) {
  if ( char const *const pos = std::strchr( in, delim ) ) {
    if ( out1 )
      *out1 = OutputStringType1( in, pos - in );
    if ( out2 )
      *out2 = OutputStringType2( pos + 1 );
    return true;
  }
  return false;
}

// Allows out1 to be nullptr.
template<class OutputStringType2> inline
typename std::enable_if<ZORBA_IS_STRING(OutputStringType2),bool>::type
split( char const *in, char delim, void*, OutputStringType2 *out2 ) {
  return split( in, delim, static_cast<OutputStringType2*>( nullptr ), out2 );
}

// Allows out2 to be nullptr.
template<class OutputStringType1> inline
typename std::enable_if<ZORBA_IS_STRING(OutputStringType1),bool>::type
split( char const *in, char delim, OutputStringType1 *out1, void* ) {
  return split( in, delim, out1, static_cast<OutputStringType1*>( nullptr ) );
}

/**
 * Splits a string at the given delimiter.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType1 The first output string type.
 * @tparam OutputStringType2 The second output string type.
 * @param in The string to split.
 * @param delim The delimiter.
 * @param out1 If not \c nullptr, a pointer to the output string to receive the
 * substring to the left of \a delim.
 * @param out2 If not \c nullptr, a pointer to the output string to receive the
 * substring to the right of \a delim.
 * @return Returns \c true only if the string was split (the delimiter was
 * present in \a in).
 */
template<class InputStringType,class OutputStringType1,class OutputStringType2>
inline
typename std::enable_if<ZORBA_IS_STRING(InputStringType)
                     && ZORBA_IS_STRING(OutputStringType1)
                     && ZORBA_IS_STRING(OutputStringType2),
                        bool>::type
split( InputStringType const &in, char delim,
                   OutputStringType1 *out1, OutputStringType2 *out2 ) {
  return split( in.c_str(), delim, out1, out2 );
}

// Allows out1 to be nullptr.
template<class InputStringType,class OutputStringType2> inline
typename std::enable_if<ZORBA_IS_STRING(InputStringType)
                     && ZORBA_IS_STRING(OutputStringType2),
                        bool>::type
split( InputStringType const &in, char delim, void*, OutputStringType2 *out2 ) {
  return split( in, delim, static_cast<OutputStringType2*>( nullptr ), out2 );
}

// Allows out2 to be nullptr.
template<class InputStringType,class OutputStringType1> inline
typename std::enable_if<ZORBA_IS_STRING(InputStringType)
                     && ZORBA_IS_STRING(OutputStringType1),
                        bool>::type
split( InputStringType const &in, char delim, OutputStringType1 *out1, void* ) {
  return split( in, delim, out1, static_cast<OutputStringType1*>( nullptr ) );
}

/**
 * Splits a string at the given delimiter.
 *
 * @tparam OutputStringType1 The first output string type.
 * @tparam OutputStringType2 The second output string type.
 * @param in The string to split.
 * @param delim The delimiter.
 * @param out1 If not \c nullptr, a pointer to the output string to receive the
 * substring to the left of \a delim.
 * @param out2 If not \c nullptr, a pointer to the output string to receive the
 * substring to the right of \a delim.
 * @return Returns \c true only if the string was split (the delimiter was
 * present in \a in).
 */
template<class OutputStringType1,class OutputStringType2>
typename std::enable_if<ZORBA_IS_STRING(OutputStringType1)
                     && ZORBA_IS_STRING(OutputStringType2),
                        bool>::type
split( char const *in, char const *delim, OutputStringType1 *out1,
       OutputStringType2 *out2 ) {
  if ( *delim )
    if ( char const *const pos = std::strstr( in, delim ) ) {
      if ( out1 )
        *out1 = OutputStringType1( in, pos - in );
      if ( out2 )
        *out2 = OutputStringType2( pos + std::strlen( delim ) );
      return true;
    }
  return false;
}

// Allows out1 to be nullptr.
template<class OutputStringType2> inline
typename std::enable_if<ZORBA_IS_STRING(OutputStringType2),bool>::type
split( char const *in, char const *delim, void*, OutputStringType2 *out2 ) {
  return split( in, delim, static_cast<OutputStringType2*>( nullptr ), out2 );
}

// Allows out2 to be nullptr.
template<class OutputStringType1> inline
typename std::enable_if<ZORBA_IS_STRING(OutputStringType1),bool>::type
split( char const *in, char const *delim, OutputStringType1 *out1, void* ) {
  return split( in, delim, out1, static_cast<OutputStringType1*>( nullptr ) );
}

/**
 * Splits a string at the given delimiter.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType1 The first output string type.
 * @tparam OutputStringType2 The second output string type.
 * @param in The string to split.
 * @param delim The delimiter.
 * @param out1 If not \c nullptr, a pointer to the output string to receive the
 * substring to the left of \a delim.
 * @param out2 If not \c nullptr, a pointer to the output string to receive the
 * substring to the right of \a delim.
 * @return Returns \c true only if the string was split (the delimiter was
 * present in \a in).
 */
template<class InputStringType,class OutputStringType1,class OutputStringType2>
inline
typename std::enable_if<ZORBA_IS_STRING(InputStringType)
                     && ZORBA_IS_STRING(OutputStringType1)
                     && ZORBA_IS_STRING(OutputStringType2),
                        bool>::type
split( InputStringType const &in, char const *delim, OutputStringType1 *out1,
       OutputStringType2 *out2 ) {
  return split( in.c_str(), delim, out1, out2 );
}

// Allows out1 to be nullptr.
template<class InputStringType,class OutputStringType2> inline
typename std::enable_if<ZORBA_IS_STRING(InputStringType)
                     && ZORBA_IS_STRING(OutputStringType2),
                        bool>::type
split( InputStringType const &in, char const *delim, void*,
            OutputStringType2 *out2 ) {
  return split( in, delim, static_cast<OutputStringType2*>( nullptr ), out2 );
}

// Allows out2 to be nullptr.
template<class InputStringType,class OutputStringType1> inline
typename std::enable_if<ZORBA_IS_STRING(InputStringType)
                     && ZORBA_IS_STRING(OutputStringType1),
                        bool>::type
split( InputStringType const &in, char const *delim, OutputStringType1 *out1,
       void* ) {
  return split( in, delim, out1, static_cast<OutputStringType1*>( nullptr ) );
}

/**
 * Splits a string at the given delimiter.
 *
 * @tparam InputStringType The input string type.
 * @tparam DelimtStringType The delimiter string type.
 * @tparam OutputStringType1 The first output string type.
 * @tparam OutputStringType2 The second output string type.
 * @param in The string to split.
 * @param delim The delimiter.
 * @param out1 If not \c nullptr, a pointer to the output string to receive the
 * substring to the left of \a delim.
 * @param out2 If not \c nullptr, a pointer to the output string to receive the
 * substring to the right of \a delim.
 * @return Returns \c true only if the string was split (the delimiter was
 * present in \a in).
 */
template<
  class InputStringType,
  class DelimStringType,
  class OutputStringType1,
  class OutputStringType2
>
typename std::enable_if<ZORBA_IS_STRING(InputStringType)
                     && ZORBA_IS_STRING(DelimStringType)
                     && ZORBA_IS_STRING(OutputStringType1)
                     && ZORBA_IS_STRING(OutputStringType2),
                        bool>::type
split( InputStringType const &in, DelimStringType const &delim,
       OutputStringType1 *out1, OutputStringType2 *out2 ) {
  typename InputStringType::size_type const pos = in.find( delim );
  if ( pos != InputStringType::npos ) {
    if ( out1 )
      *out1 = OutputStringType1( in.data(), pos );
    if ( out2 )
      *out2 = OutputStringType2( in.data() + pos + delim.size() );
    return true;
  }
  return false;
}

// Allows out1 to be nullptr.
template<class InputStringType,class DelimStringType,class OutputStringType2>
inline
typename std::enable_if<ZORBA_IS_STRING(InputStringType)
                     && ZORBA_IS_STRING(DelimStringType)
                     && ZORBA_IS_STRING(OutputStringType2),
                        bool>::type
split( InputStringType const &in, DelimStringType const &delim, void*,
       OutputStringType2 *out2 ) {
  return split( in, delim, static_cast<OutputStringType2*>( nullptr ), out2 );
}

// Allows out2 to be nullptr.
template<class InputStringType,class DelimStringType,class OutputStringType1>
inline
typename std::enable_if<ZORBA_IS_STRING(InputStringType)
                     && ZORBA_IS_STRING(DelimStringType)
                     && ZORBA_IS_STRING(OutputStringType1),
                        bool>::type
split( InputStringType const &in, DelimStringType const &delim,
       OutputStringType1 *out1, void* ) {
  return split( in, delim, out1, static_cast<OutputStringType1*>( nullptr ) );
}

////////// String number parsing ///////////////////////////////////////////////

/**
 * Parses the given string for a \c double.
 *
 * @param buf The null-terminated C string to parse.  Leading and trailing
 * whitespace is ignored.  After any leading whitespace, there may be a \c + or
 * \c - sign, followed by a sequence of decimal digits optionally containing a
 * single single \c . (decimal-point), optionally followed by an exponent
 * consisting of an \c e or \c E followed by an optional \c + or \c - sign
 * followed by a sequence of decimal digits.
 * @param last If not \c null, this is set to point to the character after the
 * last numeric character parsed; if \c null, characters past the last numeric
 * character may only be whitespace.
 * @return Returns the \c double value.
 * @throws invalid_argument if \a buf contains characters other than as
 * described or contains no digits at all.
 * @throws range_error if the number overflows/underflows.
 */
double atod( char const *buf, char const **last = nullptr );

/**
 * Parses the given string for a \c float.
 *
 * @param buf The null-terminated C string to parse.  Leading and trailing
 * whitespace is ignored.  After any leading whitespace, there may be a \c + or
 * \c - sign, followed by a sequence of decimal digits optionally containing a
 * single single \c . (decimal-point), optionally followed by an exponent
 * consisting of an \c e or \c E followed by an optional \c + or \c - sign
 * followed by a sequence of decimal digits.
 * @param last If not \c null, this is set to point to the character after the
 * last numeric character parsed; if \c null, characters past the last numeric
 * character may only be whitespace.
 * @return Returns the \c float value.
 * @throws invalid_argument if \a buf contains characters other than as
 * described or contains no digits at all.
 * @throws range_error if the number overflows/underflows.
 */
float atof( char const *buf, char const **last = nullptr );

/**
 * Parses the given string for a <code>long long</code>.
 *
 * @param buf The null-terminated C string to parse.  Leading and trailing
 * whitespace is ignored.  After any leading whitespace, there may be a \c + or
 * \c - sign, followed by a sequence of decimal digits.
 * @param last If not \c null, this is set to point to the character after the
 * last numeric character parsed; if \c null, characters past the last numeric
 * character may only be whitespace.
 * @return Returns the <code>long long</code> value.
 * @throws invalid_argument if \a buf contains characters other than as
 * described or contains no digits at all.
 * @throws range_error if the number overflows/underflows.
 */
long long atoll( char const *buf, char const **last = nullptr );

/**
 * Parses the given string for a <code>long long</code>.
 *
 * @param buf The C string to parse; it need not be null-terminated.  Leading
 * and trailing whitespace is ignored.  After any leading whitespace, there may
 * be a \c + or \c - sign, followed by a sequence of decimal digits.
 * @param end A pointer to one past the last character to parse.
 * @param last If not \c null, this is set to point to the character after the
 * last numeric character parsed; if \c null, characters past the last numeric
 * character may only be whitespace.
 * @return Returns the <code>long long</code> value.
 * @throws invalid_argument if \a buf contains characters other than as
 * described or contains no digits at all.
 * @throws range_error if the number overflows.
 */
long long atoll( char const *buf, char const *end, char const **last );

/**
 * Parses the given string for an <code>unsigned long long</code>.
 *
 * @param buf The null-terminated C string to parse.  Leading and trailing
 * whitespace is ignored.  After any leading whitespace, there may be a \c +
 * sign, followed by a sequence of decimal digits.
 * @param last If not \c null, this is set to point to the character after the
 * last numeric character parsed; if \c null, characters past the last numeric
 * character may only be whitespace.
 * @return Returns the <code>unsigned long long</code> value.
 * @throws invalid_argument if \a buf contains characters other than as
 * described or contains no digits at all.
 * @throws range_error if the number overflows.
 */
unsigned long long atoull( char const *buf, char const **last = nullptr );

/**
 * Parses the given string for an <code>unsigned long long</code>.
 *
 * @param buf The C string to parse; it need not be null-terminated.  Leading
 * and trailing whitespace is ignored.  After any leading whitespace, there may
 * be a \c + sign, followed by a sequence of decimal digits.
 * @param end A pointer to one past the last character to parse.
 * @param last If not \c null, this is set to point to the character after the
 * last numeric character parsed; if \c null, characters past the last numeric
 * character may only be whitespace.
 * @return Returns the <code>unsigned long long</code> value.
 * @throws invalid_argument if \a buf contains characters other than as
 * described or contains no digits at all.
 * @throws range_error if the number overflows.
 */
unsigned long long atoull( char const *buf, char const *end,
                           char const **last );

/**
 * Parses the given string for a C++ signed integral type.
 *
 * @tparam IntegralType The C++ signed integral type to parse for.
 * @param buf The null-terminated C string to parse.  Leading and trailing
 * whitespace is ignored.  After any leading whitespace, there may be a \c + or
 * \c - sign, followed by a sequence of decimal digits.
 * @param last If not \c null, this is set to point to the character after the
 * last numeric character parsed; if \c null, characters past the last numeric
 * character may only be whitespace.
 * @return Returns the \c IntegralType value.
 * @throws invalid_argument if \a buf contains characters other than as
 * described or contains no digits at all.
 * @throws range_error if the number is either too small or too big.
 */
template<typename IntegralType> inline
//
// Note that the is_integral shouldn't be needed since is_signed means "is a
// signed integral type", but Microsoft's implementation is broken and returns
// true for floating point types as well.
//
typename std::enable_if<ZORBA_TR1_NS::is_integral<IntegralType>::value
                     && ZORBA_TR1_NS::is_signed<IntegralType>::value,
                        IntegralType>::type
aton( char const *buf, char const **last = nullptr ) {
  long long const result = atoll( buf, last );
  if ( result < std::numeric_limits<IntegralType>::min() ||
       result > std::numeric_limits<IntegralType>::max() )
    throw std::range_error(
      BUILD_STRING( '"', result, "\": number too big/small" )
    );
  return static_cast<IntegralType>( result );
}

/**
 * Parses the given string for a C++ signed integral type.
 *
 * @tparam IntegralType The C++ signed integral type to parse for.
 * @param buf The null-terminated C string to parse.  Leading and trailing
 * whitespace is ignored.  After any leading whitespace, there may be a \c + or
 * \c - sign, followed by a sequence of decimal digits.
 * @param low The lower acceptable bound.
 * @param high the higher acceptable bound.
 * @param last If not \c null, this is set to point to the character after the
 * last numeric character parsed; if \c null, characters past the last numeric
 * character may only be whitespace.
 * @return Returns the \c IntegralType value.
 * @throws invalid_argument if \a buf contains characters other than as
 * described or contains no digits at all.
 * @throws range_error if the number is either too small or too big.
 */
template<typename IntegralType> inline
//
// Note that the is_integral shouldn't be needed since is_signed means "is a
// signed integral type", but Microsoft's implementation is broken and returns
// true for floating point types as well.
//
typename std::enable_if<ZORBA_TR1_NS::is_integral<IntegralType>::value
                     && ZORBA_TR1_NS::is_signed<IntegralType>::value,
                        IntegralType>::type
aton( char const *buf, IntegralType low, IntegralType high,
      char const **last = nullptr ) {
  long long const result = atoll( buf, last );
  if ( result < low || result > high )
    throw std::range_error(
      BUILD_STRING(
        '"', result, "\": number not in range ", low, '-', high
      )
    );
  return static_cast<IntegralType>( result );
}

/**
 * Parses the given string for a C++ signed integral type.
 *
 * @tparam IntegralType The C++ signed integral type to parse for.
 * @param buf The C string to parse; it need not be null-terminated.  Leading
 * and trailing whitespace is ignored.  After any leading whitespace, there may
 * be a \c + or \c - sign, followed by a sequence of decimal digits.
 * @param end A pointer to one past the last character to parse.
 * @param last If not \c null, this is set to point to the character after the
 * last numeric character parsed; if \c null, characters past the last numeric
 * character may only be whitespace.
 * @return Returns the \c IntegralType value.
 * @throws invalid_argument if \a buf contains characters other than as
 * described or contains no digits at all.
 * @throws range_error if the number is either too small or too big.
 */
template<typename IntegralType> inline
//
// Note that the is_integral shouldn't be needed since is_signed means "is a
// signed integral type", but Microsoft's implementation is broken and returns
// true for floating point types as well.
//
typename std::enable_if<ZORBA_TR1_NS::is_integral<IntegralType>::value
                     && ZORBA_TR1_NS::is_signed<IntegralType>::value,
                        IntegralType>::type
aton( char const *buf, char const *end, char const **last = nullptr ) {
  long long const result = atoll( buf, end, last );
  if ( result < std::numeric_limits<IntegralType>::min() ||
       result > std::numeric_limits<IntegralType>::max() )
    throw std::range_error(
      BUILD_STRING( '"', result, "\": number too big/small" )
    );
  return static_cast<IntegralType>( result );
}

/**
 * Parses the given string for a C++ signed integral type.
 *
 * @tparam IntegralType The C++ signed integral type to parse for.
 * @param buf The null-terminated C string to parse.  Leading and trailing
 * whitespace is ignored.  After any leading whitespace, there may be a \c + or
 * \c - sign, followed by a sequence of decimal digits.
 * @param end A pointer to one past the last character to parse.
 * @param low The lower acceptable bound.
 * @param high the higher acceptable bound.
 * @param last If not \c null, this is set to point to the character after the
 * last numeric character parsed; if \c null, characters past the last numeric
 * character may only be whitespace.
 * @return Returns the \c IntegralType value.
 * @throws invalid_argument if \a buf contains characters other than as
 * described or contains no digits at all.
 * @throws range_error if the number is either too small or too big.
 */
template<typename IntegralType> inline
//
// Note that the is_integral shouldn't be needed since is_signed means "is a
// signed integral type", but Microsoft's implementation is broken and returns
// true for floating point types as well.
//
typename std::enable_if<ZORBA_TR1_NS::is_integral<IntegralType>::value
                     && ZORBA_TR1_NS::is_signed<IntegralType>::value,
                        IntegralType>::type
aton( char const *buf, char const *end, IntegralType low, IntegralType high,
      char const **last = nullptr ) {
  long long const result = atoll( buf, end, last );
  if ( result < low || result > high )
    throw std::range_error(
      BUILD_STRING(
        '"', result, "\": number not in range ", low, '-', high
      )
    );
  return static_cast<IntegralType>( result );
}

/**
 * Parses the given string for a C++ unsigned integral types.
 *
 * @tparam IntegralType The C++ unsigned integral type to parse for.
 * @param buf The null-terminated C string to parse.  Leading and trailing
 * whitespace is ignored.  After any leading whitespace, there may be a \c +
 * sign, followed by a sequence of decimal digits.
 * @param last If not \c null, this is set to point to the character after the
 * last numeric character parsed; if \c null, characters past the last numeric
 * character may only be whitespace.
 * @return Returns the \c IntegralType value.
 * @throws invalid_argument if \a buf contains characters other than as
 * described or contains no digits at all.
 * @throws range_error if the number is either too small or too big.
 */
template<typename IntegralType> inline
typename std::enable_if<ZORBA_TR1_NS::is_unsigned<IntegralType>::value,
                        IntegralType>::type
aton( char const *buf, char const **last = nullptr ) {
  unsigned long long const result = atoull( buf, last );
  if ( result > std::numeric_limits<IntegralType>::max() )
    throw std::range_error( BUILD_STRING( '"', result, "\": number too big" ) );
  return static_cast<IntegralType>( result );
}

/**
 * Parses the given string for a C++ unsigned integral types.
 *
 * @tparam IntegralType The C++ unsigned integral type to parse for.
 * @param buf The null-terminated C string to parse.  Leading and trailing
 * whitespace is ignored.  After any leading whitespace, there may be a \c +
 * sign, followed by a sequence of decimal digits.
 * @param low The lower acceptable bound.
 * @param high the higher acceptable bound.
 * @param last If not \c null, this is set to point to the character after the
 * last numeric character parsed; if \c null, characters past the last numeric
 * character may only be whitespace.
 * @return Returns the \c IntegralType value.
 * @throws invalid_argument if \a buf contains characters other than as
 * described or contains no digits at all.
 * @throws range_error if the number is either too small or too big.
 */
template<typename IntegralType> inline
typename std::enable_if<ZORBA_TR1_NS::is_unsigned<IntegralType>::value,
                        IntegralType>::type
aton( char const *buf, IntegralType low, IntegralType high,
      char const **last = nullptr ) {
  unsigned long long const result = atoull( buf, last );
  if ( result < low || result > high )
    throw std::range_error(
      BUILD_STRING(
        '"', result, "\": number not in range ", low, '-', high
      )
    );
  return static_cast<IntegralType>( result );
}

/**
 * Parses the given string for a C++ unsigned integral types.
 *
 * @tparam IntegralType The C++ unsigned integral type to parse for.
 * @param buf The C string to parse; it need not be null-terminated.  Leading
 * and trailing whitespace is ignored.  After any leading whitespace, there may
 * be a \c + sign, followed by a sequence of decimal digits.
 * @param end A pointer to one past the last character to parse.
 * @param last If not \c null, this is set to point to the character after the
 * last numeric character parsed; if \c null, characters past the last numeric
 * character may only be whitespace.
 * @return Returns the \c IntegralType value.
 * @throws invalid_argument if \a buf contains characters other than as
 * described or contains no digits at all.
 * @throws range_error if the number is either too small or too big.
 */
template<typename IntegralType> inline
typename std::enable_if<ZORBA_TR1_NS::is_unsigned<IntegralType>::value,
                        IntegralType>::type
aton( char const *buf, char const *end, char const **last = nullptr ) {
  unsigned long long const result = atoull( buf, end, last );
  if ( result > std::numeric_limits<IntegralType>::max() )
    throw std::range_error( BUILD_STRING( '"', result, "\": number too big" ) );
  return static_cast<IntegralType>( result );
}

/**
 * Parses the given string for a C++ unsigned integral types.
 *
 * @tparam IntegralType The C++ unsigned integral type to parse for.
 * @param buf The C string to parse; it need not be null-terminated.  Leading
 * and trailing whitespace is ignored.  After any leading whitespace, there may
 * be a \c + sign, followed by a sequence of decimal digits.
 * @param end A pointer to one past the last character to parse.
 * @param low The lower acceptable bound.
 * @param high the higher acceptable bound.
 * @param last If not \c null, this is set to point to the character after the
 * last numeric character parsed; if \c null, characters past the last numeric
 * character may only be whitespace.
 * @return Returns the \c IntegralType value.
 * @throws invalid_argument if \a buf contains characters other than as
 * described or contains no digits at all.
 * @throws range_error if the number is either too small or too big.
 */
template<typename IntegralType> inline
typename std::enable_if<ZORBA_TR1_NS::is_unsigned<IntegralType>::value,
                        IntegralType>::type
aton( char const *buf, char const *end, IntegralType low, IntegralType high,
      char const **last = nullptr ) {
  unsigned long long const result = atoull( buf, end, last );
  if ( result < low || result > high )
    throw std::range_error(
      BUILD_STRING(
        '"', result, "\": number not in range ", low, '-', high
      )
    );
  return static_cast<IntegralType>( result );
}

/**
 * Parses the given string for a C++ \c double type.
 *
 * @param buf The null-terminated C string to parse.  Leading and trailing
 * whitespace is ignored.  After any leading whitespace, there may be a \c + or
 * \c - sign, followed by a sequence of decimal digits optionally containing a
 * single single \c . (decimal-point), optionally followed by an exponent
 * consisting of an \c e or \c E followed by an optional \c + or \c - sign
 * followed by a sequence of decimal digits.
 * @param last If not \c null, this is set to point to the character after the
 * last numeric character parsed; if \c null, characters past the last numeric
 * character may only be whitespace.
 * @return Returns the \c double value.
 * @throws invalid_argument if \a buf contains characters other than as
 * described or contains no digits at all.
 * @throws range_error if the number overflows/underflows.
 */
template<typename NumericType> inline
typename std::enable_if<ZORBA_TR1_NS::is_same<NumericType,double>::value,
                        NumericType>::type
aton( char const *buf, char const **last = nullptr ) {
  return atod( buf, last );
}

/**
 * Parses the given string for a C++ \c float type.
 *
 * @param buf The null-terminated C string to parse.  Leading and trailing
 * whitespace is ignored.  After any leading whitespace, there may be a \c + or
 * \c - sign, followed by a sequence of decimal digits optionally containing a
 * single single \c . (decimal-point), optionally followed by an exponent
 * consisting of an \c e or \c E followed by an optional \c + or \c - sign
 * followed by a sequence of decimal digits.
 * @param last If not \c null, this is set to point to the character after the
 * last numeric character parsed; if \c null, characters past the last numeric
 * character may only be whitespace.
 * @return Returns the \c float value.
 * @throws invalid_argument if \a buf contains characters other than as
 * described or contains no digits at all.
 * @throws range_error if the number overflows/underflows.
 */
template<typename NumericType> inline
typename std::enable_if<ZORBA_TR1_NS::is_same<NumericType,float>::value,
                        NumericType>::type
aton( char const *buf, char const **last = nullptr ) {
  return atof( buf, last );
}

////////// To-string conversion ////////////////////////////////////////////////

using internal::ztd::has_c_str;
using internal::ztd::has_str;
using internal::ztd::has_toString;
using internal::ztd::to_string;

/**
 * Converts an object to its string representation.
 *
 * @tparam T The object type that:
 *  - is not a pointer
 *  - is not integral
 *  - has an <code>ostream& operator&lt;&lt;(ostream&,T const&)</code> defined
 * @tparam OutputStringType The output string type.
 * @param t The object.
 * @param out The output string.
 */
template<typename T,class OutputStringType> inline
typename std::enable_if<!ZORBA_TR1_NS::is_pointer<T>::value
                     && !ZORBA_TR1_NS::is_integral<T>::value
                     && has_insertion_operator<T>::value
                     && ZORBA_IS_STRING(OutputStringType),
                        void>::type
to_string( T const &t, OutputStringType *out ) {
  std::ostringstream o;
  o << t;
  *out = o.str();
}

/**
 * Specialization of \c to_string() for C++ integral types.
 *
 * @tparam T The class type that is integral.
 * @tparam OutputStringType The output string type.
 * @param t The object.
 * @param out The output string.
 */
template<typename T,class OutputStringType> inline
typename std::enable_if<ZORBA_TR1_NS::is_integral<T>::value
                     && ZORBA_IS_STRING(OutputStringType),
                        void>::type
to_string( T t, OutputStringType *out ) {
  ascii::itoa_buf_type buf;
  *out = ascii::itoa( t, buf );
}

/**
 * Specialization of \c to_string() for class types that have a \c c_str()
 * member function.
 *
 * @tparam T The class type that:
 *  - has no <code>ostream& operator&lt;&lt;(ostream&,T const&)</code> defined
 *  - has <code>char const* T::c_str() const</code> defined
 * @tparam OutputStringType The output string type.
 * @param t The object.
 * @param out The output string.
 */
template<class T,class OutputStringType> inline
typename std::enable_if<!has_insertion_operator<T>::value
                     && ZORBA_HAS_C_STR(T)
                     && ZORBA_IS_STRING(OutputStringType),
                        void>::type
to_string( T const &t, OutputStringType *out ) {
  *out = t.c_str();
}

/**
 * Specialization of \c to_string() for class types that have a \c str()
 * member function.
 *
 * @tparam T The class type that:
 *  - has no <code>ostream& operator&lt;&lt;(ostream&,T const&)</code> defined
 *  - has no <code>char const* T::c_str() const</code> defined
 *  - has no <code>std::string T::toString() const</code> defined
 *  - has <code>std::string T::str() const</code> defined
 * @tparam OutputStringType The output string type.
 * @param t The object.
 * @param out The output string.
 */
template<class T,class OutputStringType> inline
typename std::enable_if<!has_insertion_operator<T>::value
                     && !ZORBA_HAS_C_STR(T)
                     && has_str<T,std::string (T::*)() const>::value
                     && !has_toString<T,std::string (T::*)() const>::value
                     && ZORBA_IS_STRING(OutputStringType),
                        void>::type
to_string( T const &t, OutputStringType *out ) {
  *out = t.str();
}

/**
 * Specialization of \c to_string() for class types that have a \c toString()
 * member function.
 *
 * @tparam T The class type that:
 *  - has no <code>ostream& operator&lt;&lt;(ostream&,T const&)</code> defined
 *  - has no <code>char const* T::c_str() const</code> defined
 *  - has no <code>std::string T::str() const</code> defined
 *  - has <code>std::string T::toString() const</code> defined
 * @tparam OutputStringType The output string type.
 * @param t The object.
 * @param out The output string.
 */
template<class T,class OutputStringType> inline
typename std::enable_if<!has_insertion_operator<T>::value
                     && !ZORBA_HAS_C_STR(T)
                     && !has_str<T,std::string (T::*)() const>::value
                     && has_toString<T,std::string (T::*)() const>::value
                     && ZORBA_IS_STRING(OutputStringType),
                        void>::type
to_string( T const &t, OutputStringType *out ) {
  *out = t.toString();
}

/**
 * Specialization of \c to_string() for pointer types.
 *
 * @tparam T The pointer type.
 * @tparam OutputStringType The output string type.
 * @param p The pointer.
 * @param out The output string.  If \a p is not \c nullptr, sets \c *out to
 * the result of \c to_string(*p); otherwise \c "<null>".
 */
template<typename T,class OutputStringType> inline
typename std::enable_if<ZORBA_TR1_NS::is_pointer<T>::value
                     && ZORBA_IS_STRING(OutputStringType),
                        void>::type
to_string( T p, OutputStringType *out ) {
  typedef typename ZORBA_TR1_NS::remove_pointer<T>::type const* T_const_ptr;
  if ( p )
    to_string( *static_cast<T_const_ptr>( p ), out );
  else
    *out = "<null>";
}

/**
 * Specialization of \c to_string() for C strings.
 *
 * @tparam OutputStringType The output string type.
 * @param s The C string.
 * @param out The output string.
 */
template<class OutputStringType> inline
typename std::enable_if<ZORBA_IS_STRING(OutputStringType),void>::type
to_string( char const *s, OutputStringType *out ) {
  *out = s ? s : "<null>";
}

////////// Miscellaneous ///////////////////////////////////////////////////////

/**
 * Converts an integer to an alphabetic string: 1 = A, 2 = B, ..., 26 = Z, 27 =
 * AA, 28 = AB, ....  Note that 0 remains 0.
 *
 * @param n The integer to convert.
 * @param capital If \c true, capital letters are used; if \c false, lower case
 * letters are used.
 * @return Returns \a n as an alphabetic string or "0" if \a n is zero.
 */
zstring alpha( unsigned long long n, bool capital );

/**
 * Converts a signed integer to English, e.g, 42 becomes "forty two".
 *
 * @param n The integer to convert.
 * @param ordinal If \c true, ordinal words ("forty second") are returned.
 * @return Returns \a n in English.
 */
zstring english( int64_t n, bool ordinal = false );

/**
 * Returns the English ordinal suffix for an integer, e.g., "st" for 1, "nd"
 * for 2, etc.
 *
 * @param n The integer to return the ordinal suffix for.
 * @return Returns said suffix.
 */
char const* ordinal( long long n );

///////////////////////////////////////////////////////////////////////////////

} // namespace ztd

////////// Windows /////////////////////////////////////////////////////////////

#ifdef WIN32
namespace win32 {

/**
 * Converts a wide-character (UTF-16) string to a multi-byte (UTF-8) string.
 *
 * @param ws The wide-character string to convert.
 * @param s The string buffer to convert \a ws into.
 * @param s_len The size of \a s (in bytes).
 * @return Returns \c true only if the conversion succeeded.
 */
inline bool wtoa( LPCWSTR ws, char *s, int s_len ) {
  return !!::WideCharToMultiByte( CP_UTF8, 0, ws, -1, s, s_len, NULL, NULL );
}

/**
 * Converts a wide character (UTF-16) string to a multi-byte (UTF-8) string.
 *
 * @param ws The wide string to convert.
 * @return Returns the equivalent multi-byte string.
 */
inline std::unique_ptr<char[]> wtoa( LPCWSTR ws ) {
  int const s_len =
    ::WideCharToMultiByte( CP_UTF8, 0, ws, -1, NULL, 0, NULL, NULL );
  std::unique_ptr<char[]> s( new char[ s_len ] );
  wtoa( ws, s.get(), s_len );
  return s;
}

/**
 * Converts a multi-byte (UTF-8) string to a wide-character (UTF-16) string.
 *
 * @param s The string to convert.
 * @param ws The wide-character string buffer to convert \a s into.
 * @param ws_len The size of \a ws (in characters).
 * @return Returns \c true only if the conversion succeeded.
 */
inline bool atow( char const *s, LPWSTR ws, int ws_len ) {
  if ( ::MultiByteToWideChar( CP_UTF8, 0, s, -1, ws, ws_len ) )
    return true;
  return !!::MultiByteToWideChar( CP_ACP, 0, s, -1, ws, ws_len );
}

} // namespace win32
#endif /* WIN32 */

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_STRING_UTIL_H */
/* vim:set et sw=2 ts=2: */

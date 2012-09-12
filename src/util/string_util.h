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

#include <cstring>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>

#include <zorba/internal/ztd.h>
#include "cxx_util.h"
#include "stl_util.h"

#ifdef WIN32
// Windows annoyingly defines these as macros.
#undef max
#undef min
#endif /* WIN32 */

namespace zorba {
namespace ztd {

using internal::ztd::c_str;

////////// String building /////////////////////////////////////////////////////

/**
 * A %string_builder is used to build (concatenate) strings on-the-fly and pass
 * the resultant string to some function.  See the BUILD_STRING macro for usage.
 * Note that you can use either "<<" or "," to taste.
 *
 * See http://stackoverflow.com/questions/5666678/ as to why a class like this
 * is needed rather than just using an ostringstream directly.
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
bool equals( StringType const &s1, char const *s2,
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
bool equals( char const *s1, typename StringType::size_type s1_n,
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
bool split( char const *in, char delim, OutputStringType1 *out1,
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
bool split( char const *in, char delim, void*, OutputStringType2 *out2 ) {
  return split( in, delim, static_cast<OutputStringType2*>( nullptr ), out2 );
}

// Allows out2 to be nullptr.
template<class OutputStringType1> inline
bool split( char const *in, char delim, OutputStringType1 *out1, void* ) {
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
inline bool split( InputStringType const &in, char delim,
                   OutputStringType1 *out1, OutputStringType2 *out2 ) {
  return split( in.c_str(), delim, out1, out2 );
}

// Allows out1 to be nullptr.
template<class InputStringType,class OutputStringType2> inline
bool split( InputStringType const &in, char delim, void*,
            OutputStringType2 *out2 ) {
  return split( in, delim, static_cast<OutputStringType2*>( nullptr ), out2 );
}

// Allows out2 to be nullptr.
template<class InputStringType,class OutputStringType1> inline
bool split( InputStringType const &in, char delim, OutputStringType1 *out1,
            void* ) {
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
bool split( char const *in, char const *delim, OutputStringType1 *out1,
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
bool split( char const *in, char const *delim, void*,
            OutputStringType2 *out2 ) {
  return split( in, delim, static_cast<OutputStringType2*>( nullptr ), out2 );
}

// Allows out2 to be nullptr.
template<class OutputStringType1> inline
bool split( char const *in, char const *delim, OutputStringType1 *out1,
            void* ) {
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
inline bool split( InputStringType const &in, char const *delim,
                   OutputStringType1 *out1, OutputStringType2 *out2 ) {
  return split( in.c_str(), delim, out1, out2 );
}

// Allows out1 to be nullptr.
template<class InputStringType,class OutputStringType2> inline
bool split( InputStringType const &in, char const *delim, void*,
            OutputStringType2 *out2 ) {
  return split( in, delim, static_cast<OutputStringType2*>( nullptr ), out2 );
}

// Allows out2 to be nullptr.
template<class InputStringType,class OutputStringType1> inline
bool split( InputStringType const &in, char const *delim,
            OutputStringType1 *out1, void* ) {
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
bool split( InputStringType const &in, DelimStringType const &delim,
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
template<
  class InputStringType,
  class DelimStringType,
  class OutputStringType2
>
inline bool split( InputStringType const &in, DelimStringType const &delim,
                   void*, OutputStringType2 *out2 ) {
  return split( in, delim, static_cast<OutputStringType2*>( nullptr ), out2 );
}

// Allows out2 to be nullptr.
template<
  class InputStringType,
  class DelimStringType,
  class OutputStringType1
>
inline bool split( InputStringType const &in, DelimStringType const &delim,
                   OutputStringType1 *out1, void* ) {
  return split( in, delim, out1, static_cast<OutputStringType1*>( nullptr ) );
}

////////// String number parsing ///////////////////////////////////////////////

/**
 * Parses the given string for a \c double.
 *
 * @param s The null-terminated C string to parse.  Leading and trailing
 * whitespace is ignored.
 * @return Returns the \c double value.
 * @throws invalid_argument if \a s contains characters other than digits or
 * leading/trailing whitespace, or contains no digits at all.
 * @throws range_error if the number overflows/underflows.
 */
double atod( char const *s );

/**
 * Parses the given string for a \c float.
 *
 * @param s The null-terminated C string to parse.  Leading and trailing
 * whitespace is ignored.
 * @return Returns the \c float value.
 * @throws invalid_argument if \a s contains characters other than digits or
 * leading/trailing whitespace, or contains no digits at all.
 * @throws range_error if the number overflows/underflows.
 */
float atof( char const *s );

/**
 * Parses the given string for a <code>long lomg</code>.
 *
 * @param s The null-terminated C string to parse.  Leading and trailing
 * whitespace is ignored.
 * @return Returns the <code>long long</code> value.
 * @throws invalid_argument if \a s contains characters other than digits or
 * leading/trailing whitespace, or contains no digits at all.
 * @throws range_error if the number overflows/underflows.
 */
long long atoll( char const *s );

/**
 * Parses the given string for an <code>unsigned long lomg</code>.
 *
 * @param s The null-terminated C string to parse.  Leading and trailing
 * whitespace is ignored.
 * @return Returns the <code>unsigned long long</code> value.
 * @throws invalid_argument if \a s contains characters other than digits or
 * leading/trailing whitespace, or contains no digits at all.
 * @throws range_error if the number overflows/underflows.
 */
unsigned long long atoull( char const *s );

/**
 * Parses the given string for a C++ signed integral type.
 *
 * @tparam IntegralType The C++ signed integral type to parse for.
 * @param s The null-terminated C string to parse.  Leading and trailing
 * whitespace is ignored.
 * @return Returns the \c IntegralType value.
 * @throws invalid_argument if \a s contains characters other than digits or
 * leading/trailing whitespace, or contains no digits at all.
 * @throws range_error if the number overflows/underflows.
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
aton( char const *s ) {
  long long const result = atoll( s );
  if ( result < std::numeric_limits<IntegralType>::min() ||
       result > std::numeric_limits<IntegralType>::max() )
    throw std::range_error(
      BUILD_STRING( '"', result, "\": number too big/small" )
    );
  return static_cast<IntegralType>( result );
}

/**
 * Parses the given string for a C++ unsigned integral types.
 *
 * @tparam IntegralType The C++ unsigned integral type to parse for.
 * @param s The null-terminated C string to parse.  Leading and trailing
 * whitespace is ignored.
 * @return Returns the \c IntegralType value.
 * @throws invalid_argument if \a s contains characters other than digits or
 * leading/trailing whitespace, or contains no digits at all.
 * @throws range_error if the number overflows/underflows.
 */
template<typename IntegralType> inline
typename std::enable_if<ZORBA_TR1_NS::is_unsigned<IntegralType>::value,
                        IntegralType>::type
aton( char const *s ) {
  unsigned long long const result = atoull( s );
  if ( result > std::numeric_limits<IntegralType>::max() )
    throw std::range_error( BUILD_STRING( '"', result, "\": number too big" ) );
  return static_cast<IntegralType>( result );
}

/**
 * Parses the given string for a C++ \c double type.
 *
 * @param s The null-terminated C string to parse.  Leading and trailing
 * whitespace is ignored.
 * @return Returns the \c double value.
 * @throws invalid_argument if \a s contains characters other than those for a
 * valid \c double value or leading/trailing whitespace, or contains no digits
 * at all.
 * @throws range_error if the number overflows/underflows.
 */
template<typename NumericType> inline
typename std::enable_if<ZORBA_TR1_NS::is_same<NumericType,double>::value,
                        NumericType>::type
aton( char const *s ) {
  return atod( s );
}

/**
 * Parses the given string for a C++ \c float type.
 *
 * @param s The null-terminated C string to parse.  Leading and trailing
 * whitespace is ignored.
 * @return Returns the \c float value.
 * @throws invalid_argument if \a s contains characters other than those for a
 * valid \c float value or leading/trailing whitespace, or contains no digits
 * at all.
 * @throws range_error if the number overflows/underflows.
 */
template<typename NumericType> inline
typename std::enable_if<ZORBA_TR1_NS::is_same<NumericType,float>::value,
                        NumericType>::type
aton( char const *s ) {
  return atof( s );
}

////////// To-string conversion ////////////////////////////////////////////////

using internal::ztd::has_c_str;
using internal::ztd::has_str;
using internal::ztd::has_toString;
using internal::ztd::to_string;

/**
 * A type that can hold the largest possible C string equivalent of the largest
 * possible integral value.
 */
typedef char itoa_buf_type[48];

/**
 * Converts a <code>long long</code> to a C string.
 *
 * @param n The <code>long long</code> to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
char* itoa( long long n, char *buf );

/**
 * Converts a \c char to a C string.
 *
 * @param n The \c char to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
inline char* itoa( char n, char *buf ) {
  return itoa( static_cast<long long>( n ), buf );
}

/**
 * Converts a <code>signed char</code> to a C string.
 *
 * @param n The <code>signed char</code> to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
inline char* itoa( signed char n, char *buf ) {
  return itoa( static_cast<long long>( n ), buf );
}

/**
 * Converts a \c short to a C string.
 *
 * @param n The \c short to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
inline char* itoa( short n, char *buf ) {
  return itoa( static_cast<long long>( n ), buf );
}

/**
 * Converts an \c int to a C string.
 *
 * @param n The \c int to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
inline char* itoa( int n, char *buf ) {
  return itoa( static_cast<long long>( n ), buf );
}

/**
 * Converts a \c long to a C string.
 *
 * @param n The \c long to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
inline char* itoa( long n, char *buf ) {
  return itoa( static_cast<long long>( n ), buf );
}

/**
 * Converts an <code>unsigned long long</code> to a C string.
 *
 * @param n The <code>unsigned long long</code> to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
char* itoa( unsigned long long n, char *buf );

/**
 * Converts an <code>unsigned char</code> to a C string.
 *
 * @param n The <code>unsigned char</code> to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
inline char* itoa( unsigned char n, char *buf ) {
  return itoa( static_cast<unsigned long long>( n ), buf );
}

/**
 * Converts an <code>unsigned short</code> to a C string.
 *
 * @param n The <code>unsigned short</code> to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
inline char* itoa( unsigned short n, char *buf ) {
  return itoa( static_cast<unsigned long long>( n ), buf );
}

/**
 * Converts an <code>unsigned int</code> to a C string.
 *
 * @param n The <code>unsigned int</code> to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
inline char* itoa( unsigned int n, char *buf ) {
  return itoa( static_cast<unsigned long long>( n ), buf );
}

/**
 * Converts an <code>unsigned long</code> to a C string.
 *
 * @param n The <code>unsigned long</code> to convert.
 * @param buf The buffer for the result.  The caller must ensure it's of
 * sufficient size.
 * @return Returns \a buf for convenience.
 */
inline char* itoa( unsigned long n, char *buf ) {
  return itoa( static_cast<unsigned long long>( n ), buf );
}

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
                     && has_insertion_operator<T>::value,
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
typename std::enable_if<ZORBA_TR1_NS::is_integral<T>::value,void>::type
to_string( T t, OutputStringType *out ) {
  itoa_buf_type buf;
  *out = itoa( t, buf );
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
                     && has_c_str<T,char const* (T::*)() const>::value,
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
                     && !has_c_str<T,char const* (T::*)() const>::value
                     && has_str<T,std::string (T::*)() const>::value
                     && !has_toString<T,std::string (T::*)() const>::value,
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
                     && !has_c_str<T,char const* (T::*)() const>::value
                     && !has_str<T,std::string (T::*)() const>::value
                     && has_toString<T,std::string (T::*)() const>::value,
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
typename std::enable_if<ZORBA_TR1_NS::is_pointer<T>::value,void>::type
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
void to_string( char const *s, OutputStringType *out ) {
  *out = s ? s : "<null>";
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ztd
} // namespace zorba
#endif  /* ZORBA_STRING_UTIL_H */
/* vim:set et sw=2 ts=2: */

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
#include <sstream>
#include <string>

#include <zorba/internal/ztd.h>
#include "stl_util.h"

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
 * Equals that works even when either argument is the \c NULL pointer.
 *
 * @param s1 The first NULL-terminated C string or the \c NULL pointer.
 * @param s2 The second NULL-terminated C string or the \c NULL pointer.
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
 * @param out1 If not \c NULL, a pointer to the output string to receive the
 * substring to the left of \a delim.
 * @param out2 If not \c NULL, a pointer to the output string to receive the
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

// Allows out1 to be NULL.
template<class OutputStringType2> inline
bool split( char const *in, char delim, void*, OutputStringType2 *out2 ) {
  return split( in, delim, static_cast<OutputStringType2*>(0), out2 );
}

// Allows out2 to be NULL.
template<class OutputStringType1> inline
bool split( char const *in, char delim, OutputStringType1 *out1, void* ) {
  return split( in, delim, out1, static_cast<OutputStringType1*>(0) );
}

/**
 * Splits a string at the given delimiter.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType1 The first output string type.
 * @tparam OutputStringType2 The second output string type.
 * @param in The string to split.
 * @param delim The delimiter.
 * @param out1 If not \c NULL, a pointer to the output string to receive the
 * substring to the left of \a delim.
 * @param out2 If not \c NULL, a pointer to the output string to receive the
 * substring to the right of \a delim.
 * @return Returns \c true only if the string was split (the delimiter was
 * present in \a in).
 */
template<class InputStringType,class OutputStringType1,class OutputStringType2>
inline bool split( InputStringType const &in, char delim,
                   OutputStringType1 *out1, OutputStringType2 *out2 ) {
  return split( in.c_str(), delim, out1, out2 );
}

// Allows out1 to be NULL.
template<class InputStringType,class OutputStringType2> inline
bool split( InputStringType const &in, char delim, void*,
            OutputStringType2 *out2 ) {
  return split( in, delim, static_cast<OutputStringType2*>(0), out2 );
}

// Allows out2 to be NULL.
template<class InputStringType,class OutputStringType1> inline
bool split( InputStringType const &in, char delim, OutputStringType1 *out1,
            void* ) {
  return split( in, delim, out1, static_cast<OutputStringType1*>(0) );
}

/**
 * Splits a string at the given delimiter.
 *
 * @tparam OutputStringType1 The first output string type.
 * @tparam OutputStringType2 The second output string type.
 * @param in The string to split.
 * @param delim The delimiter.
 * @param out1 If not \c NULL, a pointer to the output string to receive the
 * substring to the left of \a delim.
 * @param out2 If not \c NULL, a pointer to the output string to receive the
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

// Allows out1 to be NULL.
template<class OutputStringType2> inline
bool split( char const *in, char const *delim, void*,
            OutputStringType2 *out2 ) {
  return split( in, delim, static_cast<OutputStringType2*>(0), out2 );
}

// Allows out2 to be NULL.
template<class OutputStringType1> inline
bool split( char const *in, char const *delim, OutputStringType1 *out1,
            void* ) {
  return split( in, delim, out1, static_cast<OutputStringType1*>(0) );
}

/**
 * Splits a string at the given delimiter.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType1 The first output string type.
 * @tparam OutputStringType2 The second output string type.
 * @param in The string to split.
 * @param delim The delimiter.
 * @param out1 If not \c NULL, a pointer to the output string to receive the
 * substring to the left of \a delim.
 * @param out2 If not \c NULL, a pointer to the output string to receive the
 * substring to the right of \a delim.
 * @return Returns \c true only if the string was split (the delimiter was
 * present in \a in).
 */
template<class InputStringType,class OutputStringType1,class OutputStringType2>
inline bool split( InputStringType const &in, char const *delim,
                   OutputStringType1 *out1, OutputStringType2 *out2 ) {
  return split( in.c_str(), delim, out1, out2 );
}

// Allows out1 to be NULL.
template<class InputStringType,class OutputStringType2> inline
bool split( InputStringType const &in, char const *delim, void*,
            OutputStringType2 *out2 ) {
  return split( in, delim, static_cast<OutputStringType2*>(0), out2 );
}

// Allows out2 to be NULL.
template<class InputStringType,class OutputStringType1> inline
bool split( InputStringType const &in, char const *delim,
            OutputStringType1 *out1, void* ) {
  return split( in, delim, out1, static_cast<OutputStringType1*>(0) );
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
 * @param out1 If not \c NULL, a pointer to the output string to receive the
 * substring to the left of \a delim.
 * @param out2 If not \c NULL, a pointer to the output string to receive the
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

// Allows out1 to be NULL.
template<
  class InputStringType,
  class DelimStringType,
  class OutputStringType2
>
inline bool split( InputStringType const &in, DelimStringType const &delim,
                   void*, OutputStringType2 *out2 ) {
  return split( in, delim, static_cast<OutputStringType2*>(0), out2 );
}

// Allows out2 to be NULL.
template<
  class InputStringType,
  class DelimStringType,
  class OutputStringType1
>
inline bool split( InputStringType const &in, DelimStringType const &delim,
                   OutputStringType1 *out1, void* ) {
  return split( in, delim, out1, static_cast<OutputStringType1*>(0) );
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
 *  - has an <code>ostream& operator&lt;&lt;(ostream&,T const&)</code> defined
 * @tparam OutputStringType The output string type.
 * @param t The object.
 * @param out The output string.
 */
template<typename T,class OutputStringType> inline
typename enable_if<!ZORBA_TR1_NS::is_pointer<T>::value
                && has_insertion_operator<T>::value,
                   void>::type
to_string( T const &t, OutputStringType *out ) {
  std::ostringstream o;
  o << t;
  *out = o.str();
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
typename enable_if<!has_insertion_operator<T>::value
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
 *  - has <code>std::string T::str() const</code> defined
 * @tparam OutputStringType The output string type.
 * @param t The object.
 * @param out The output string.
 */
template<class T,class OutputStringType> inline
typename enable_if<!has_insertion_operator<T>::value
                && !has_c_str<T,char const* (T::*)() const>::value
                && has_str<T,std::string (T::*)() const>::value,
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
 *  - has <code>std::string T::toString() const</code> defined
 * @tparam OutputStringType The output string type.
 * @param t The object.
 * @param out The output string.
 */
template<class T,class OutputStringType> inline
typename enable_if<!has_insertion_operator<T>::value
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
 * @param out The output string.  If \a p is not \c NULL, sets \c *out to the
 * result of \c to_string(*p); otherwise \c "<null>".
 */
template<typename T,class OutputStringType> inline
typename enable_if<ZORBA_TR1_NS::is_pointer<T>::value,void>::type
to_string( T p, OutputStringType *out ) {
  if ( p )
    to_string( *p, out );
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
  *out = s;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ztd
} // namespace zorba
#endif  /* ZORBA_STRING_UTIL_H */
/* vim:set et sw=2 ts=2: */

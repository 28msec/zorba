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

#ifndef ZORBA_INTERNAL_ZTD_H
#define ZORBA_INTERNAL_ZTD_H

#include <cstring>
#include <functional>
#include <sstream>
#include <string>

#include <zorba/config.h>

#ifdef ZORBA_TR1_IN_TR1_SUBDIRECTORY
# include <tr1/type_traits>
#else
# include <type_traits>
#endif

///////////////////////////////////////////////////////////////////////////////

namespace zorba {
namespace internal {
namespace ztd {

////////// tr1 ////////////////////////////////////////////////////////////////

/**
 * \internal
 * Define our own version of \c enable_if since g++ 4.2.1 (the version that
 * comes with Xcode 3.x) doesn't have \c enable_if.
 */
template<bool,typename T = void>
struct enable_if {
};

/**
 * \internal
 * Specialization of \c enable_if for the \c true case.
 */
template<typename T>
struct enable_if<true,T> {
  typedef T type;
};

/**
 * \internal
 * Declares a class that can be used to determine whether a given type \c T has
 * a particular member function with a certain signature.
 * For example:
 * \code
 * ZORBA_DECL_HAS_MEM_FN( c_str, char const* (T::*)() const);
 *
 * template<typename T> inline
 * typename enable_if<has_c_str<T>::value,std::string>::type
 * to_string( T const &t ) {
 *   // case where T has c_str()
 * }
 *
 * template<typename T> inline
 * typename enable_if<!has_c_str<T>::value,std::string>::type
 * to_string( T const &t ) {
 *   // case where T does not have c_str()
 * }
 * \endcode
 * Note: the identifier in the member function signature used to represent the
 * class type must be called \c T.
 * \hideinitializer
 */
#define ZORBA_DECL_HAS_MEM_FN(FN_NAME,...)                                    \
  template<typename U>                                                        \
  class has_##FN_NAME {                                                       \
    typedef char yes[1];                                                      \
    typedef char no[2];                                                       \
    template<typename SignatureType,SignatureType> struct type_check;         \
    template<class T> static yes& test(type_check<__VA_ARGS__,&T::FN_NAME>*); \
    template<class T> static no& test(...);                                   \
  public:                                                                     \
    static bool const value = sizeof( test<U>(0) ) == sizeof( yes );          \
    static void suppress_all_member_functions_are_private_warning();          \
  }

////////// c_str() /////////////////////////////////////////////////////////////

/**
 * \internal
 * Gets the \c char* to the given string.
 * 
 * @tparam OutputStringType The string's type.
 * @param s The string to get the \c char* of.
 * @return Returns said \c char*.
 */
template<class StringType> inline
typename StringType::const_pointer c_str( StringType const &s ) {
  return s.c_str();
}

/**
 * \internal
 * Specialization of global c_str() for \c char* argument.
 *
 * @param s The C string to get the \c char* of.
 * @return Returns said \c char*.
 */
inline char const* c_str( char const *s ) {
  return s;
}

////////// less<char const*> ///////////////////////////////////////////////////

// This declaration exists only to declare that less is a template class.
template<typename T> struct less {
};

/**
 * \internal
 * Specialize the binary_function "less" so that C-style strings (char const*)
 * will work properly with STL containers.
 *
 * See also: Bjarne Stroustrup. "The C++ Programming Language, 3rd ed."
 * Addison-Wesley, Reading, MA, 1997.  p. 468.
 */
template<> struct less<char const*> :
  std::binary_function<char const*,char const*,bool>
{
  less() { }
  // This default constructor doesn't need to be defined, but g++ complains if
  // it isn't and you try to define a "const less" object.

  result_type
  operator()( first_argument_type a, second_argument_type b ) const {
    return std::strcmp( a, b ) < 0;
  }
};

////////// To-string conversion ////////////////////////////////////////////////

ZORBA_DECL_HAS_MEM_FN( c_str, char const* (T::*)() const );
ZORBA_DECL_HAS_MEM_FN( str, std::string (T::*)() const );
ZORBA_DECL_HAS_MEM_FN( toString, std::string (T::*)() const );

/**
 * \internal
 * Converts an object to its string representation.
 *
 * @tparam OutputStringType The output string type.
 * @tparam T The object type.
 * @param t The object.
 * @Param out The output string.
 */
template<typename T,class OutputStringType> inline
typename enable_if<!ZORBA_TR1_NS::is_pointer<T>::value
                && !has_c_str<T>::value
                && !has_str<T>::value
                && !has_toString<T>::value,
                   void>::type
to_string( T const &t, OutputStringType *out ) {
  std::ostringstream o;
  o << t;
  *out = o.str();
}

/**
 * \internal
 * Specialization of \c to_string() for class types that have a \c c_str()
 * member function.
 *
 * @tparam T The class type.
 * @tparam OutputStringType The output string type.
 * @param t The object.
 * @Param out The output string.
 */
template<class T,class OutputStringType> inline
typename enable_if<has_c_str<T>::value,void>::type
to_string( T const &t, OutputStringType *out ) {
  *out = t.c_str();
}

/**
 * \internal
 * Specialization of \c to_string() for class types that have a \c str()
 * member function.
 *
 * @tparam T The class type.
 * @tparam OutputStringType The output string type.
 * @param t The object.
 * @Param out The output string.
 */
template<class T,class OutputStringType> inline
typename enable_if<has_str<T>::value && !has_c_str<T>::value,void>::type
to_string( T const &t, OutputStringType *out ) {
  *out = t.str();
}

/**
 * \internal
 * Specialization of \c to_string() for class types that have a \c toString()
 * member function.
 *
 * @tparam T The class type.
 * @tparam OutputStringType The output string type.
 * @param t The object.
 * @Param out The output string.
 */
template<class T,class OutputStringType> inline
typename enable_if<has_toString<T>::value,void>::type
to_string( T const &t, OutputStringType *out ) {
  *out = t.toString();
}

/**
 * \internal
 * Specialization of \c to_string() for pointer types.
 *
 * @tparam T The pointer type.
 * @tparam OutputStringType The output string type.
 * @param t The pointer.
 * @Param out The output string.
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
 * \internal
 * Specialization of \c to_string() for C strings.
 *
 * @tparam OutputStringType The output string type.
 * @param s The C string.
 * @Param out The output string.
 */
template<class OutputStringType> inline
void to_string( char const *s, OutputStringType *out ) {
  *out = s;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ztd
} // namespace internal
} // namespace zorba
#endif /* ZORBA_INTERNAL_ZTD_H */
/* vim:set et sw=2 ts=2: */

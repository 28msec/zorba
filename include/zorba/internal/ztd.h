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

#include "type_traits.h"

///////////////////////////////////////////////////////////////////////////////

namespace zorba {
namespace internal {
namespace ztd {

////////// tr1 ////////////////////////////////////////////////////////////////

/**
 * \internal
 * Base class for SFINAE (Substitution Failure Is Not An Error) types.
 */
class sfinae_base {
protected:
  typedef char no;
  typedef char yes[2];
public:
  void suppress_all_member_functions_are_private_warning();
};

/**
 * \internal
 * Declares a class that can be used to determine whether a given type \c T has
 * a particular member function with a certain signature.
 * For example:
 * \code
 * ZORBA_DECL_HAS_MEM_FN( c_str );
 *
 * template<typename T> inline
 * typename enable_if<has_c_str<T,char const* (T::*)() const>::value,
 *                    std::string>::type
 * to_string( T const &t ) {
 *   // case where T has c_str()
 * }
 *
 * template<typename T> inline
 * typename enable_if<!has_c_str<T,char const* (T::*)() const>::value,
 *                     std::string>::type
 * to_string( T const &t ) {
 *   // case where T does not have c_str()
 * }
 * \endcode
 * \hideinitializer
 */
#define ZORBA_DECL_HAS_MEM_FN(FN_NAME)                                \
  template<typename T,typename S>                                     \
  class has_##FN_NAME : public sfinae_base {                          \
    template<typename SignatureType,SignatureType> struct type_check; \
    template<class U> static yes& test(type_check<S,&U::FN_NAME>*);   \
    template<class U> static no& test(...);                           \
  public:                                                             \
    static bool const value = sizeof( test<T>(0) ) == sizeof( yes );  \
  }

/**
 * \internal
 * This namespace is used only to bundle the implementation details for
 * implementing \c has_insertion_operator<T>.
 * This implementation is based on http://stackoverflow.com/questions/4434569/
 */
namespace has_insertion_operator_impl {
  typedef char no;
  typedef char yes[2];

  /**
   * This dummy class is used to make the matching of the dummy operator<<()
   * \e worse than the global \c operator<<(), if any.
   */
  struct any_t {
    template<typename T> any_t( T const& );
  };

  /**
   * This dummy operator is matched only when there is \e no global
   * operator<<() otherwise declared for type \c T.
   *
   * @return Returns a \c no that selects defined(no).
   */
  no operator<<( std::ostream const&, any_t const& );

  /**
   * This function is matched only when there \e is a global \c operator<<()
   * declared for type \c T because \c operator<<()'s return type is
   * \c std::ostream&.
   *
   * @return Returns a yes& whose \c sizeof() equals \c sizeof(yes).
   */
  yes& defined( std::ostream& );

  /**
   * This function is matched only when the dummy \c operator<<() is matched.
   *
   * @return Returns a no whose \c sizeof() equals \c sizeof(no).
   */
  no defined( no );

  /**
   * The implementation class that can be used to determine whether a given
   * type \c T has a global <code>std::ostream& operator<<(std::ostream&,T
   * const&)</code> defined for it.  However, do not use this class directly.
   *
   * @tparam T The type to check.
   */
  template<typename T>
  class has_insertion_operator {
    static std::ostream &s;
    static T const &t;
  public:
    /**
     * This is \c true only when the type \c T has a global \c operator<<()
     * declared for it.
     * \hideinitializer
     */
    static bool const value = sizeof( defined( s << t ) ) == sizeof( yes );
  };
} // namespace has_insertion_operator_impl

/**
 * \internal
 * A class that can be used to determine whether a given type \c T has a global
 * <code>std::ostream& operator<<(std::ostream&,T const&)</code> defined for
 * it.
 * For example:
 * \code
 * template<typename T> inline
 * typename enable_if<has_insertion_operator<T>::value,std::string>::value
 * to_string( T const &t ) {
 *   // case where T has operator<<(ostream&,T const&)
 * }
 * \endcode
 *
 * @tparam T The type to check.
 */
template<typename T>
struct has_insertion_operator :
  has_insertion_operator_impl::has_insertion_operator<T>
{
};

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

ZORBA_DECL_HAS_MEM_FN( c_str );
ZORBA_DECL_HAS_MEM_FN( str );
ZORBA_DECL_HAS_MEM_FN( toString );

/**
 * \internal
 * Converts an object to its string representation.
 *
 * @tparam T The object type that:
 *  - is not a pointer
 *  - has an <code>ostream& operator&lt;&lt;(ostream&,T const&)</code> defined
 * @param t The object.
 * @return Returns a string representation of the object.
 */
template<typename T> inline
typename std::enable_if<!ZORBA_TR1_NS::is_pointer<T>::value
                     && has_insertion_operator<T>::value,
                        std::string>::type
to_string( T const &t ) {
  std::ostringstream o;
  o << t;
  return o.str();
}

/**
 * \internal
 * Specialization of \c to_string() for class types that have a \c c_str()
 * member function, i.e., string types.
 *
 * @tparam T The class type that:
 *  - has no <code>ostream& operator&lt;&lt;(ostream&,T const&)</code> defined
 *  - has <code>char const* T::c_str() const</code> defined
 * @param t The object.
 * @return Returns a string representation of the object.
 */
template<class T> inline
typename std::enable_if<!has_insertion_operator<T>::value
                     && has_c_str<T,char const* (T::*)() const>::value,
                        std::string>::type
to_string( T const &t ) {
  return t.c_str();
}

/**
 * \internal
 * Specialization of \c to_string() for class types that have a \c str()
 * member function.
 *
 * @tparam T The class type that:
 *  - has no <code>ostream& operator&lt;&lt;(ostream&,T const&)</code> defined
 *  - has no <code>char const* T::c_str() const</code> defined
 *  - has <code>std::string T::str() const</code> defined
 * @param t The object.
 * @return Returns a string representation of the object.
 */
template<class T> inline
typename std::enable_if<!has_insertion_operator<T>::value
                     && !has_c_str<T,char const* (T::*)() const>::value
                     && has_str<T,std::string (T::*)() const>::value,
                std::string>::type
to_string( T const &t ) {
  return t.str();
}

/**
 * \internal
 * Specialization of \c to_string() for class types that have a \c toString()
 * member function.
 *
 * @tparam T The class type that:
 *  - has no <code>ostream& operator&lt;&lt;(ostream&,T const&)</code> defined
 *  - has <code>std::string T::toString() const</code> defined
 * @param t The object.
 * @return Returns a string representation of the object.
 */
template<class T> inline
typename std::enable_if<!has_insertion_operator<T>::value
                     && has_toString<T,std::string (T::*)() const>::value,
                        std::string>::type
to_string( T const &t ) {
  return t.toString();
}

/**
 * \internal
 * Specialization of \c to_string() for pointer types.
 *
 * @tparam T The pointer type.
 * @param p The pointer.
 * @return If \a p is not \c NULL, returns the result of \c to_string(*p);
 * otherwise returns \c "<null>".
 */
template<typename T> inline
typename std::enable_if<ZORBA_TR1_NS::is_pointer<T>::value,std::string>::type
to_string( T p ) {
  return p ? to_string( *p ) : "<null>";
}

/**
 * \internal
 * Specialization of \c to_string() for C strings.
 *
 * @param s The C string.
 * @return Returns a string representation of the object.
 */
inline std::string to_string( char const *s ) {
  return s ? s : "<null>";
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ztd
} // namespace internal
} // namespace zorba
#endif /* ZORBA_INTERNAL_ZTD_H */
/* vim:set et sw=2 ts=2: */

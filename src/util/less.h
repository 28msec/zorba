#ifndef less_H
#define less_H

// standard
#include <cstring>
#include <functional>

namespace std {

/**
 * Specialize the binary_function "less" so that C-style strings (char const*)
 * will work properly with STL containers.
 *
 * See also: Bjarne Stroustrup. "The C++ Programming Language, 3rd ed."
 * Addison-Wesley, Reading, MA, 1997.  p. 468.
 */
template<> struct less<char const*> :
    std::binary_function<char const*, char const*, bool>
{
  less() { }
  // This default constructor doesn't need to be defined, but g++ complains
  // if it isn't and you try to define a "const less" object.

  result_type
  operator()( first_argument_type a, second_argument_type b ) const {
      return std::strcmp( a, b ) < 0;
  }
};

} // namespace std

#endif  /* less_H */
/* vim:set et sw=2 ts=2: */

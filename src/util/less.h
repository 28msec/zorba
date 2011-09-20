/*
** Copyright (C) 1998, Paul J. Lucas
** All rights reserved.
** 
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
** 
**  o  Redistributions of source code must retain the above copyright notice,
**     this list of conditions and the following disclaimer.
**
**  o  Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in the
**     documentation and/or other materials provided with the distribution.
**
**  o  The name of the author may not be used to endorse or promote products
**     derived from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
** ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
** LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
** CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
** SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
** INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
** CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
** ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
** POSSIBILITY OF SUCH DAMAGE.
*/
#pragma once
#ifndef pjl_less_H
#define pjl_less_H

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
  // This default constructor doesn't need to be defined, but g++ complains if
  // it isn't and you try to define a "const less" object.

  result_type
  operator()( first_argument_type a, second_argument_type b ) const {
    return std::strcmp( a, b ) < 0;
  }
};

} // namespace std

#endif  /* pjl_less_H */
/* vim:set et sw=2 ts=2: */

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
#ifndef ZORBA_OMANIP_H
#define ZORBA_OMANIP_H

// standard
#include <iostream>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * An omanip1 is a class for assisting in the creation of ostream manipulators
 * by storing a pointer to a function and its argument to be called later via
 * operator<<().
 *
 * See also: "Standard C++ IOStreams and Locales," Angelika Langer and Klaus
 * Kreft, Addison-Wesley, pp. 179-191.
 */
template<typename Arg1Type> class omanip1 {
public:

  /**
   * The signature of functions this omanip1 can handle.
   */
  typedef std::ostream& (*func_type)( std::ostream&, Arg1Type );

  /**
   * Constructs an omanip1.
   *
   * @param f     The function to call when this omanip1 is inserted into an
   *              ostream.
   * @param arg1  The argument to be passed to the function.
   */
  omanip1( func_type f, Arg1Type arg1 ) :
    f_( f ), arg1_( arg1 )
  {
  }

  /**
   * Inserts the given omanip1 into the given ostream.  This has the effect of
   * calling the function and argument bound to the omanip1 at the time of its
   * construction.
   *
   * @param o The ostream to insert into.
   * @param m The omanip1 to insert.
   */
  friend std::ostream& operator<<( std::ostream &o, omanip1 const &m ) {
    return (*m.f_)( o, m.arg1_ );
  }

private:
  func_type const f_;
  Arg1Type const arg1_;
};

/**
 * Defines an ostream manipulator "thunk" function that calls an existing
 * non-manipulator function having the same name.
 *
 * @param FN_NAME   The name of the existing function.
 * @param ARG1_TYPE The type of the non-ostream argument.
 */
#define DEF_OMANIP1(FN_NAME,ARG1_TYPE)          \
  inline omanip1<ARG1_TYPE>                     \
  FN_NAME( ARG1_TYPE arg1 ) {                   \
    return omanip1<ARG1_TYPE>( FN_NAME, arg1 ); \
  }

///////////////////////////////////////////////////////////////////////////////

/**
 * An omanip2 is a class for assisting in the creation of ostream manipulators
 * by storing a pointer to a function and its arguments to be called later via
 * operator<<().
 *
 * See also: "Standard C++ IOStreams and Locales," Angelika Langer and Klaus
 * Kreft, Addison-Wesley, pp. 179-191.
 */
template<typename Arg1Type, typename Arg2Type> class omanip2 {
public:

  /**
   * The signature of functions this omanip2 can handle.
   */
  typedef std::ostream& (*func_type)( std::ostream&, Arg1Type, Arg2Type );

  /**
   * Constructs an omanip2.
   *
   * @param f     The function to call when this omanip2 is inserted into an
   *              ostream.
   * @param arg1  The first argument to be passed to the function.
   * @param arg2  The second argument to be passed to the function.
   */
  omanip2( func_type f, Arg1Type arg1, Arg2Type arg2 ) :
    f_( f ), arg1_( arg1 ), arg2_( arg2 )
  {
  }

  /**
   * Inserts the given omanip2 into the given ostream.  This has the effect of
   * calling the function and argument bound to the omanip2 at the time of its
   * construction.
   *
   * @param o The ostream to insert into.
   * @param m The omanip2 to insert.
   */
  friend std::ostream& operator<<( std::ostream &o, omanip2 const &m ) {
    return (*m.f_)( o, m.arg1_, m.arg2_ );
  }

private:
  func_type const f_;
  Arg1Type const arg1_;
  Arg2Type const arg2_;
};

/**
 * Defines an ostream manipulator "thunk" function that calls an existing
 * non-manipulator function having the same name.
 *
 * @param FN_NAME   The name of the existing function.
 * @param ARG1_TYPE The type of the first non-ostream argument.
 * @param ARG2_TYPE The type of the second non-ostream argument.
 */
#define DEF_OMANIP2(FN_NAME,ARG1_TYPE,ARG2_TYPE)                \
  inline omanip2<ARG1_TYPE,ARG2_TYPE>                           \
  FN_NAME( ARG1_TYPE arg1, ARG2_TYPE arg2 ) {                   \
    return omanip2<ARG1_TYPE,ARG2_TYPE>( FN_NAME, arg1, arg2 ); \
  }

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#endif  /* ZORBA_OMANIP_H */
/* vim:set et sw=2 ts=2: */

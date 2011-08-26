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

#ifndef ZORBA_ZORBA_EXCEPTION_API_H
#define ZORBA_ZORBA_EXCEPTION_API_H

#include <iostream>
#include <exception>
#include <string>

#include <zorba/config.h>
#include <zorba/internal/unique_ptr.h>
#include <zorba/error.h>

namespace zorba {

class ZorbaException;

namespace serialization {
  class Archiver;
  void operator&( Archiver&, ZorbaException*& );
}

//////////////////////////////////////////////////////////////////////////////

/**
 * A %ZorbaException is the base class for all Zorba exceptions.
 */
class ZORBA_DLL_PUBLIC ZorbaException : public std::exception {
public:
  typedef internal::diagnostic::location::line_type line_type;

  /**
   * Copy-constructs a %ZorbaException.
   *
   * @param from The %ZorbaException to copy from.
   */
  ZorbaException( ZorbaException const &from );

  /**
   * Destroys this %ZorbaException.
   */
  ~ZorbaException() throw();

  /**
   * Assigns this %ZorbaException from another.
   *
   * @param from The %ZorbaException to assign from.
   * @return Returns \c *this.
   */
  ZorbaException& operator=( ZorbaException const &from );

  /**
   * Gets the diagnostic carried by this exception.
   *
   * @return Returns said diagnostic.
   */
  Diagnostic const& diagnostic() const throw() {
    return *diagnostic_;
  }

  /**
   * Throws itself polymorphically; see
   * http://www.parashift.com/c++-faq-lite/exceptions.html#faq-17.16
   */
  virtual void polymorphic_throw() const;

  /**
   * Sets the diagnostic.
   *
   * @param diagnostic The diagnostic.
   */
  void set_diagnostic( Diagnostic const &diagnostic ) throw() {
    diagnostic_ = &diagnostic;
  }

  /**
   * Gets the C++ source-code file name whence this exception was raised.
   *
   * @return Returns said file name.
   */
  char const* raise_file() const throw() {
    return raise_file_.c_str();
  }

  /**
   * Gets the C++ source-code line number whence this exception was raised.
   *
   * @return Returns said line number.
   */
  line_type raise_line() const throw() {
    return raise_line_;
  }

  // inherited
  char const* what() const throw();

protected:
  /**
   * Constructs a %ZorbaException.
   *
   * @param diagnostic The diagnostic.
   * @param raise_file The C++ source-code file name whence the exception was
   * raised.
   * @param raise_line The C++ source-code line number whence the exception was
   * raised.
   * @param message The diagnostic message.
   */
  ZorbaException( Diagnostic const &diagnostic, char const *raise_file,
                  line_type raise_line, char const *message );

  /**
   * Clones this exception object.
   *
   * @return Returns a clone of this exception.
   */
  virtual std::unique_ptr<ZorbaException> clone() const;

  /**
   * Prints the exception to the given ostream.
   *
   * @param o The ostream to print to.
   * @return Returns \a o.
   */
  virtual std::ostream& print( std::ostream &o ) const;

  friend std::ostream& operator<<( std::ostream&, ZorbaException const& );

private:
  Diagnostic const *diagnostic_;
  std::string raise_file_;
  line_type raise_line_;
  std::string message_;

  friend std::unique_ptr<ZorbaException> clone( ZorbaException const& );

  friend ZorbaException make_zorba_exception(
    char const*, line_type, Diagnostic const&,
    internal::diagnostic::parameters const&
  );

  friend ZorbaException* new_zorba_exception(
    char const*, line_type, Diagnostic const&,
    internal::diagnostic::parameters const&
  );

protected:
  // for plan serialization
  ZorbaException( serialization::Archiver& );
  friend void serialization::operator&( serialization::Archiver&,
                                        ZorbaException*& );
};

/**
 * Emits the given ZorbaException to the given ostream.
 *
 * @param o The ostream to emit to.
 * @param e The ZorbaException to emit.
 * @return Returns \a o.
 */
inline std::ostream& operator<<( std::ostream &o, ZorbaException const &e ) {
  return e.print( o );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_ZORBA_EXCEPTION_API_H */
/* vim:set et sw=2 ts=2: */

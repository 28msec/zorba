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

#ifndef ZORBA_USER_EXCEPTION_API_H
#define ZORBA_USER_EXCEPTION_API_H

#include <zorba/item.h>
#include <zorba/error.h>
#include <zorba/xquery_exception.h>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %UserException is-a XQueryException for errors raised via
 * <code>fn:error()</code>.
 */
class ZORBA_DLL_PUBLIC UserException : public XQueryException {
public:
  typedef std::vector<Item> error_object_type;

  /**
   * Constructs a %UserException.
   *
   * @param ns The namespace of the error.
   * @param prefix The prefix of the error.
   * @param locaname The local-name of the error.
   * @param throw_file The source-code file name whence the exception was
   * thrown.
   * @param throw_line The source-code line number whence the exception was
   * thrown.
   * @param description The error description.
   * @param error_object TODO
   */
  UserException( char const *ns, char const *prefix, char const *localname,
                 char const *throw_file, line_type throw_line,
                 char const *description, error_object_type *error_object );

  /**
   * Destroys this %UserException.
   */
  ~UserException() throw();

  /**
   * Gets the error object associated with this exception.
   *
   * @return Returns said error object.
   */
  error_object_type const& getErrorObject() const throw() {
    return error_object_;
  }

  // inherited
  std::auto_ptr<ZorbaException> clone() const;
  void polymorphic_throw() const;

private:
  error_object_type error_object_;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_USER_EXCEPTION_API_H */
/* vim:set et sw=2 ts=2: */

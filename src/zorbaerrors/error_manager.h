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
#ifndef ZORBA_ERROR_MANAGER_H
#define ZORBA_ERROR_MANAGER_H

#include <memory>
#include <vector>

#include <zorba/config.h>

// TODO: this #include is temporary
#include <zorba/error_list.h>

#include "util/error_util.h"

#include "dict.h"
#include "err.h"
#include "xquery_exception.h"
#include "zorba_exception.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * An %ErrorManager is used to collect errors (and warnings) that can not be
 * issued immediately and must be deferred until some later time.
 */
class ZORBA_DLL_PUBLIC ErrorManager {
public:
  typedef std::vector<ZorbaException const*> errors_type;

  ErrorManager();
  ~ErrorManager();

  /**
   * Adds an exception to the list of exceptions.
   *
   * @param exception The exception to add.  The %ErrorManager takes ownership
   * of the exception.
   */
  void add_error( ZorbaException const *exception ) {
    errors_.push_back( exception );
  }

  /**
   * Adds an exception to the list of exceptions.
   *
   * @param exception The exception to add.  The %ErrorManager takes ownership
   * of the exception.
   */
  void add_error( std::auto_ptr<ZorbaException> exception ) {
    add_error( exception.release() );
  }

  /**
   * Adds an exception to the list of exceptions.
   *
   * @param exception The exception to add.  The exception is cloned.
   */
  void add_error( ZorbaException const &exception ) {
    add_error( exception.clone() );
  }

  /**
   * Checks whether there are any errors.
   *
   * @return Returns \c true only if there is at least one error.
   */
  bool has_errors() const {
    return !errors_.empty();
  }

  /**
   * Gets the list of exceptions.
   *
   * @return Returns said exceptions.
   */
  errors_type const& errors() const {
    return errors_;
  }

private:
  errors_type errors_;
};

////////// TEMPORARY TRANSITION MACROS: THESE WILL BE REMOVED /////////////////

#define ZORBA_ERROR_DESC_OSS(LOCALNAME,MSG) \
  do { \
    std::ostringstream oss; \
    oss << MSG; \
    throw XQUERY_EXCEPTION( LOCALNAME, ERROR_PARAMS( oss.str() ) ); \
  } while (0)

#define ZORBA_ERROR_LOC_DESC(LOCALNAME,LOC,MSG) \
  throw XQUERY_EXCEPTION( LOCALNAME, ERROR_PARAMS(MSG), ERROR_LOC(LOC) )

#define ZORBA_ERROR_VAR_LOC_OSS(ERROR_VAR,LOC,MSG)                      \
  do {                                                                  \
    std::ostringstream oss;                                             \
    oss << MSG;                                                         \
    throw XQUERY_EXCEPTION_VAR(ERROR_VAR, ERROR_PARAMS(oss.str()), ERROR_LOC(LOC)); \
  } while (0)

#define ZORBA_ERROR_LOC_DESC_OSS(LOCALNAME,LOC,MSG) \
  do { \
    std::ostringstream oss; \
    oss << MSG; \
    ZORBA_ERROR_LOC_DESC( LOCALNAME, LOC, oss.str() ); \
  } while (0)

} // namespace zorba

#endif /* ZORBA_ERROR_MANAGER_H */
/* vim:set et sw=2 ts=2: */

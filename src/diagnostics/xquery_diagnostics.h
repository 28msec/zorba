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
#ifndef ZORBA_XQUERY_DIAGNOSTICS_H
#define ZORBA_XQUERY_DIAGNOSTICS_H

#include <vector>

#include <zorba/config.h>
#include <zorba/internal/unique_ptr.h>

// TODO: this #include is temporary
#include <zorba/diagnostic_list.h>

#include "util/error_util.h"

#include "diagnostic.h"
#include "dict.h"
#include "xquery_exception.h"
#include "xquery_warning.h"
#include "zorba_exception.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * An %XQueryDiagnostics is used to collect errors and warnings that can not be
 * issued immediately and must be deferred until some later time.
 */
class ZORBA_DLL_PUBLIC XQueryDiagnostics {
public:
  typedef std::vector<ZorbaException const*> errors_type;
  typedef std::vector<XQueryWarning const*> warnings_type;

  XQueryDiagnostics();
  ~XQueryDiagnostics();

  ////////// Errors ///////////////////////////////////////////////////////////

  /**
   * Adds an exception to the list of exceptions.
   *
   * @param exception The exception to add.  The %XQueryDiagnostics takes
   * ownership of the exception.
   */
  void add_error( ZorbaException const *exception ) {
    errors_.push_back( exception );
  }

  /**
   * Adds an exception to the list of exceptions.
   *
   * @param exception The exception to add.  The %XQueryDiagnostics takes
   * ownership of the exception.
   */
  void add_error( std::unique_ptr<ZorbaException> exception ) {
    add_error( exception.release() );
  }

  /**
   * Adds an exception to the list of exceptions.
   *
   * @param exception The exception to add.  The exception is cloned.
   */
  void add_error( ZorbaException const &exception ) {
    add_error( clone( exception ) );
  }

  /**
   * Gets the list of exceptions.
   *
   * @return Returns said exceptions.
   */
  errors_type const& errors() const {
    return errors_;
  }

  ////////// Warnings /////////////////////////////////////////////////////////

  /**
   * Adds a warning to the list of warnings.
   *
   * @param exception The exception to add.  The %XQueryDiagnostics takes
   * ownership of the exception.
   */
  void add_warning( XQueryWarning const *warning ) {
    warnings_.push_back( warning );
  }

  /**
   * Gets the list of warnings.
   *
   * @return Returns said warnings.
   */
  warnings_type const& warnings() const {
    return warnings_;
  }

  /**
   * Clears the list of warnings. This function should be called after the
   * warnings have been given to the diagnostics handler so that they are not
   * reported multiple times.
   */
  void clear_warnings();

private:
  errors_type errors_;
  warnings_type warnings_;
};

////////// TEMPORARY TRANSITION MACROS: THESE WILL BE REMOVED /////////////////

#define ZORBA_ERROR_DESC_OSS(LOCALNAME,MSG) \
  do { \
    std::ostringstream oss; \
    oss << MSG; \
    throw XQUERY_EXCEPTION( LOCALNAME, ERROR_PARAMS( oss.str() ) ); \
  } while (0)

#define ZORBA_ERROR_VAR_LOC_OSS(ERROR_VAR,LOC,MSG)                      \
  do {                                                                  \
    std::ostringstream oss;                                             \
    oss << MSG;                                                         \
    throw XQUERY_EXCEPTION_VAR( ERROR_VAR, ERROR_PARAMS(oss.str()), ERROR_LOC(LOC) ); \
  } while (0)

} // namespace zorba

#endif /* ZORBA_XQUERY_DIAGNOSTICS_H */
/* vim:set et sw=2 ts=2: */

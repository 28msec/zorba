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

#ifndef ZORBA_DIAGNOSTIC_HANDLER_API_H
#define ZORBA_DIAGNOSTIC_HANDLER_API_H

#include <zorba/config.h>

#include <zorba/xquery_warning.h>

namespace zorba {

/**
 * When registered with an XQuery object, a %DiagnosticHandler handles all
 * exceptions and warnings that otherwise would have been thrown or reported.
 */
class ZORBA_DLL_PUBLIC DiagnosticHandler {
public:
  virtual ~DiagnosticHandler();

  /**
   * This function is called for all exceptions.
   *
   * @param exception The exception.
   */
  virtual void error( ZorbaException const &exception );

  /**
   * This function is called for all warnings.
   *
   * @param warning The warning.
   */
  virtual void warning( XQueryWarning const &warning );
};

} // namespace zorba

#endif /* ZORBA_DIAGNOSTIC_HANDLER_API_H */
/* vim:set et sw=2 ts=2: */
